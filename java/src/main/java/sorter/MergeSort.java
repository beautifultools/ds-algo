package sorter;

import java.util.Collections;
import java.util.LinkedList;
import java.util.List;
import java.util.PriorityQueue;

public class MergeSort {

	static void mergeSort(int[] Array, int left, int right){

		if(right > left){
			int middle = (left + right)/2;
			mergeSort(Array, left, middle);
			mergeSort(Array, middle+1, right);
			merge(Array, left, middle, right);
		}
	}

	static void merge(int[] Array, int left, int middle, int right){
		int[] leftTmpArray = new int[middle - left + 2];
		int[] rightTmpArray = new int[right-middle + 1];

		for(int i = 0; i < leftTmpArray.length-1; i++){
			leftTmpArray[i] = Array[left+i];
		}

		for(int i = 0; i < rightTmpArray.length-1; i++){
			rightTmpArray[i] = Array[middle+1+i];
		}

		leftTmpArray[leftTmpArray.length - 1] = Integer.MAX_VALUE;
		rightTmpArray[rightTmpArray.length - 1] = Integer.MAX_VALUE;

		int i = 0, j = 0;
		for(int k = left; k<=right; k++ ){
			if(leftTmpArray[i] < rightTmpArray[j]){
				Array[k] = leftTmpArray[i++];
			} else {
				Array[k] = rightTmpArray[j++];
			}
		}
	}

//	static void mergeSort(int[] Array, int left, int right){
//		if(right>left){
//			int middle = (left + right)/2;
//			mergeSort(Array, left, middle);
//			mergeSort(Array, middle+1, right);
//			merge(Array, left, middle, right);
//		}
//	}
//
//	static void merge(int[] A, int left, int middle, int right){
//		int [] leftTmpArray = new int[middle - left+2];
//		int [] rightTmpArray = new int[right - middle+1];
//
//		for(int i=0; i<=middle-left; i++)
//			leftTmpArray[i] = A[left+i];
//
//		for(int i=0; i<right-middle; i++)
//			rightTmpArray[i] = A[middle+1+i];
//
//		leftTmpArray[middle-left+1] = Integer.MAX_VALUE;
//		leftTmpArray[right-middle] = Integer.MAX_VALUE;
//		int i = 0, j = 0;
//		for(int k = left; k<=right; k++){
//			if(leftTmpArray[i] < rightTmpArray[j]){
//				A[k] = leftTmpArray[i];
//				i++;
//			} else {
//				A[k] = rightTmpArray[j];
//				j++;
//			}
//		}
//	}

	void printArray(int arr[]){
		int n = arr.length;
		for (int i = 0; i <n; ++i)
			System.out.print(arr[i] + " ");
		System.out.println();
	}
}
