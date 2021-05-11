package heap;

import java.util.stream.IntStream;

/*
* 완전 이진 트리에서 각 단계의 첫번째 노드의 인덱스틑 2^n이다. 그리고 n번째 단계는 2^n개의 노드가 있다.
* 임의의 점 2^n + c(c는 0 < c < 2^n-1)에서 다음 단계 왼쪽 자식으로 가려면
* (2^n - c) + 2*c =(현재 단계에서 다음단계 첫번째 노드까지 가야 하는 수) + (다음 단계에서 자신의 왼쪽 자식으로 이동하기 위한 수) = 2^n + c 만큼 이동해야 하고, 이는 자기 자신의 인덱스와 같다.
* 그래서 n을 인덱스로 가지는 임의점 a의 왼쪽 자식의 인덱스는 2*n이 된다.
* 이 성질을 이용해서 HeapifyTopToBottom, HeapifyBottomToTop
* */

public class HeapByArray {

	int[] arr;
	int sizeOfTree;

	public HeapByArray(int size){
		arr = new int[size + 1];
		this.sizeOfTree = 0;
		System.out.println("Empty Heap has bean created");
	}

	public int sizeOfArray() { return arr.length; }

	public int sizeOfTree() {
		System.out.println("Size Of Tree : " + sizeOfTree);
		return sizeOfTree;
	}

	public boolean isHeapEmpty(){
		if(sizeOfTree<=0) return true;
		return false;
	}

	public void deleteHeap(){
		arr = null;
	}

	public void peek(){
		if (sizeOfTree == 0)
			System.out.println("Heap is empty");
		else
			System.out.println("Head of the Heap is " + arr[1]);
	}

	public void insertInHeap(int value){
		arr[++sizeOfTree] = value;
		HeapifyBottomToTop(sizeOfTree);
		levelOrder();
	}

	public int extractHeadOfHeap(){
		if(sizeOfTree == 0){
			System.out.println("Heap is empty");
			return -1;
		} else {
			System.out.println("Head of the Heap is " + arr[1]);
			int head = arr[1];
			arr[1] = arr[--sizeOfTree];
			HeapifyTopToBottom(arr[1]);
			return head;
		}
	}

	public void HeapifyBottomToTop(int index){
		int parent = index/2;

		if(index<=1) return;

		if(arr[index] < arr[parent]){
			int tmp = arr[index];
			arr[index]= arr[parent];
			arr[parent] = tmp;
		}

		HeapifyBottomToTop(parent);
	}

	public void HeapifyTopToBottom(int index){
		int left = index*2;
		int right = index*2 + 1;

		int smallestChild = 0;

		if(sizeOfTree<left){
			return;
		} else if(sizeOfTree == left){
			if(arr[index] > arr[left]){
				int tmp = arr[index];
				arr[index] = arr[left];
				arr[left] =tmp;
			}
		} else {
			smallestChild = arr[left] < arr[right]?left:right;

			if(arr[index] > arr[smallestChild]){
				int tmp = arr[index];
				arr[index] = arr[smallestChild];
				arr[smallestChild] = tmp;
			}
			HeapifyTopToBottom(smallestChild);
		}
	}

	public void levelOrder() {
		System.out.println("Heap Level Order Start");
		IntStream.range(1, sizeOfTree+1).map(i->arr[i]).forEach(System.out::println);
		System.out.println("Heap Level Order End");
	}
}
