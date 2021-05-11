package sorter;

public class InsertionSort {

	static void insertionSort(int[] A){
		for(int i = 1; i<A.length; i++){
			int tmp = A[i], j=i;
			while(j>0 && A[j] < tmp){
				A[j] = A[j-1];
				j--;
			}
			A[j] = tmp;
		}

	}

	void printArray(int arr[]){
		int n = arr.length;
		for (int i = 0; i <n; ++i)
			System.out.print(arr[i] + " ");
		System.out.println();
	}
}
