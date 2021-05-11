package sorter;

import java.util.*;
public class SortMain {

	public static void main(String[] args){

		int bridge_length = (int)(Math.random()*10000 + 1);
		int weight = (int)(Math.random()*10000 + 1);
		int[] truck_weights = new int[(int)(Math.random()*10000 + 1)];
		for (int i = 0; i < truck_weights.length; i++) {
			truck_weights[i] = (int)(Math.random()*weight + 1);
		}

		bridge_length = 6637;
		weight = 3212;
//		truck_weights = new int[]{1568, 39, 357, 2526, 941};
		truck_weights = new int[]{1568, 39, 357, 2526, 941};

		Solution solution = new Solution();
		int answer1 = solution.solution(bridge_length, weight, truck_weights);
//		System.out.println("answer1 : " + answer1);

		Solution2 solution2 = new Solution2();
		int answer2 = solution2.solution(bridge_length, weight, truck_weights);
		System.out.println("answer1 : " + answer1 + " / answer2 : " + answer2);
//		System.out.println("bridge_length : " + bridge_length + " / weight : " + weight);
//		for (int truck_weight : truck_weights) {
//			System.out.print(truck_weight + ", ");
//		}
	}

	static class Solution2 {
		private Queue<Integer> bridge = new LinkedList<>();
		private int totalWeightInBridge = 0;
		public int solution(int bridge_length, int weight, int[] truck_weights) {
			int answer = 0;

			for(int truck : truck_weights){
				while(true){
					if(bridge.isEmpty()){
						bridge.add(truck);
						totalWeightInBridge += truck;
						answer++;
						break;
					} else if(bridge.size() == bridge_length){
						totalWeightInBridge -= bridge.poll();
					} else {
						if(totalWeightInBridge + truck > weight){
							bridge.add(0);
							answer++;
						} else {
							bridge.add(truck);
							totalWeightInBridge += truck;
							answer++;
							break;
						}
					}
				}
			}
			System.out.println("######## SOLUTION 2");
			System.out.println("bridge" + bridge.stream().filter(i->i>0).count());
			System.out.println("totalWeightInBridge" + totalWeightInBridge);

			return answer + bridge_length;
		}
	}

	static class Solution {
		private Queue<TruckInBridge> bridge = new LinkedList<>();

		private int requiredSeconds = 0;
		private int emptyDistanceBetweenCar = 0;
		private int totalWeightInBridge = 0;

		private int weight = 0;
		private int bridge_length = 0;

		public int solution(int bridge_length, int weight, int[] truck_weights) {
			setBridgeLengthAndWeight(bridge_length, weight);
			calculateRequiredSecondsOfAllTrucks(truck_weights);
			System.out.println("######## SOLUTION 1");
			System.out.println("bridge" + bridge.size() + "/ empty : " + emptyDistanceBetweenCar);
			System.out.println("totalWeightInBridge" + totalWeightInBridge);
			return requiredSeconds;
		}

		private void setBridgeLengthAndWeight(int bridge_length, int weight){
			this.bridge_length = bridge_length;
			this.weight = weight;
		}

		private void calculateRequiredSecondsOfAllTrucks(int[] truck_weights) {
			addAllTrucksToTheBridge(truck_weights);
			waitUntilLastTruckGoThroughTheBridge();
		}

		private void addAllTrucksToTheBridge(int[] truck_weights) {
			for(int i = 0; i < truck_weights.length; i++){
				addTruckToBridgeByWaitingInCaseOfBridgeFull(truck_weights[i]);
			}
		}

		private void addTruckToBridgeByWaitingInCaseOfBridgeFull(int truck_weight) {
			if(isCannotEnter(truck_weight)){
				addTruckAfterExtractingTruckInBridge(truck_weight);
			} else {
				moveCarsInBridgeOneDistanceAndAddNewTruck(truck_weight);
			}
		}

		private void addTruckAfterExtractingTruckInBridge(int truck_weight) {
			while(isCannotEnter(truck_weight)){
				extractFrontTruckOutOfBridge(truck_weight);
			}

			addRequiredSeconds(-1); // extract and add occurs at the same time.
			moveCarsInBridgeOneDistanceAndAddNewTruck(truck_weight);
		}

		private boolean isCannotEnter(int truckWeight){
			return totalWeightInBridge + truckWeight > weight;
		}

		private void extractFrontTruckOutOfBridge(int truck_weight){
			if (!isFrontTruckAtTheEndOfBridge()) {
				moveTrucksToTheEndOfBridge();
			}

			extractFrontTruckAtTheEndOfBridge(truck_weight);
		}

		private boolean isFrontTruckAtTheEndOfBridge() {
			return bridge.size() + emptyDistanceBetweenCar == bridge_length;
		}

		private void moveTrucksToTheEndOfBridge() {
			removeFrontDummyTruck();
			int frontTruckRemainDistance = bridge_length - bridge.size() - emptyDistanceBetweenCar;
			if(frontTruckRemainDistance > 0){
				addDummyTrucksToBridge(frontTruckRemainDistance);
				addRequiredSeconds(frontTruckRemainDistance);
			}
		}

		private void addDummyTrucksToBridge(int frontTruckRemainDistance) {
			TruckInBridge dummyTruck = makeDummyTruck(frontTruckRemainDistance);
			bridge.add(dummyTruck);
			emptyDistanceBetweenCar += frontTruckRemainDistance;
		}

		private TruckInBridge makeDummyTruck(int frontTruckRemainDistance) {
			TruckInBridge dummyTruck = new TruckInBridge(0);
			dummyTruck.length = frontTruckRemainDistance;
			return dummyTruck;
		}

		private void addRequiredSeconds(int seconds) {
			requiredSeconds += seconds;
		}

		private void moveCarsInBridgeOneDistanceAndAddNewTruck(int truck_weight) {
			removeFrontDummyTruck();
			letFrontTruckOutIfNeed();
			addTruckToBridge(truck_weight);
			addRequiredSeconds(1);
		}

		private void removeFrontDummyTruck() {
			while(isDummyTruckInFront()){
				TruckInBridge frontDummyTruck = this.bridge.remove();
				emptyDistanceBetweenCar -= frontDummyTruck.length;
			}
		}

		private boolean isDummyTruckInFront() {
			return this.bridge.size() > 0 && this.bridge.peek().weight == 0;
		}

		private void letFrontTruckOutIfNeed(){
			boolean frontTruckIsAtTheEndOfTheBridge = this.bridge.size() > 0 && (this.bridge.size() + emptyDistanceBetweenCar >= bridge_length);
			if(frontTruckIsAtTheEndOfTheBridge){
				TruckInBridge frontTruckInBridge = this.bridge.remove();
				totalWeightInBridge -= frontTruckInBridge.weight;
			}
		}

		private void extractFrontTruckAtTheEndOfBridge(int truck_weight) {
			if(isCannotEnter(truck_weight)){
				TruckInBridge dummyTruck = makeDummyTruck(1);
				bridge.add(dummyTruck);
				emptyDistanceBetweenCar += 1;
			}

			TruckInBridge frontTruckInBridge = this.bridge.remove();
			totalWeightInBridge -= frontTruckInBridge.weight;
			addRequiredSeconds(1);
		}

		private void addTruckToBridge(int currentTruckWeight) {
			TruckInBridge truck = new TruckInBridge(currentTruckWeight);
			bridge.add(truck);
			totalWeightInBridge += currentTruckWeight;
		}

		private void waitUntilLastTruckGoThroughTheBridge() {
			addRequiredSeconds(bridge_length);
		}

		class TruckInBridge{
			public int length;
			public int weight;
			TruckInBridge(int weight){
				this.length = 1;
				this.weight = weight;
			}
		}
	}
}
