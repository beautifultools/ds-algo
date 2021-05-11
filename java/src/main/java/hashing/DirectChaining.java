package hashing;

import java.util.LinkedList;

public class DirectChaining {

	LinkedList<String>[] hashTable;

	DirectChaining(){ hashTable = new LinkedList[13]; }

	public int simpleASCIIHashFunction(String x, int M){
		char ch[];
		ch = x.toCharArray();
		int sum = 0;
		for(int i = 0; i < ch.length; i++){
			sum += ch[i];
		}

		return sum % M;
	}

	public void insertKeyInHashTable(String value){
		int newIndex = simpleASCIIHashFunction(value, hashTable.length);
		if(hashTable[newIndex] == null){
			System.out.println("Index : " + newIndex + " is empty. create new linked list");
			hashTable[newIndex] = new LinkedList<String>();
			hashTable[newIndex].add(value);
			System.out.println("linked list is created");
			System.out.println("-----------------------------------------");
		} else {
			System.out.println("Index : " + newIndex + " is having sufficient space. ");
			LinkedList<String> targetList = hashTable[newIndex];
			if(targetList.contains(value)) {
				System.out.println("Already Exist : " + value + " is in the list ");
				System.out.println("-----------------------------------------");
			}
			targetList.add(value);
			System.out.println("Index : " + newIndex + " is having sufficient space. ");
			System.out.println("-----------------------------------------");
		}
	}

	public boolean searchKeyInHashTable(String stringToBeSearched){
		int newIndex = simpleASCIIHashFunction(stringToBeSearched, hashTable.length);
		if(hashTable[newIndex] != null && hashTable[newIndex].contains(stringToBeSearched)){
			System.out.println(stringToBeSearched + " is found at location : " + newIndex);
			return true;
		}
		System.out.println(stringToBeSearched + " is not found in Hashtable");
		return false;
	}

	public void deleteKeyInHashTable(String stringToBeDeleted){
		int newIndex = simpleASCIIHashFunction(stringToBeDeleted, hashTable.length);
		if(hashTable[newIndex] != null && hashTable[newIndex].contains(stringToBeDeleted)){
			hashTable[newIndex].remove(stringToBeDeleted);
			System.out.println(stringToBeDeleted + " is deleted at location : " + newIndex);
		}
		System.out.println(stringToBeDeleted + " is not found in Hashtable");
	}

	public void displayHashTable() {
		if(hashTable == null ){
			System.out.println("\n HashTable does not exist");
			return;
		}

		System.out.println("\n ------------- Hash Table --------------");
		for (int i = 0; i < hashTable.length; i++){
			System.out.println("Index " + i + ", key: " + hashTable[i]);
		}
	}

	public void deleteHashTable(){
		hashTable = null;
		System.out.println("hash table is deleted.");
	}

}
