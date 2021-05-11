package sorter;

public class QuickSort {

	static void quickSort(int[] arr, int startIndex, int endIndex){
		int pivot = partition(arr, startIndex, endIndex);
		quickSort(arr, startIndex, pivot-1);
		quickSort(arr,pivot+1, endIndex);
	}

	static int partition(int[] arr, int startIndex, int endIndex){
		int pivotIndex = endIndex;
		int pivotValue = arr[pivotIndex];
		int i = startIndex;
		for(int j = startIndex; j <= endIndex; j++){
			if(arr[j] <= pivotValue){
				int tmp = arr[j];
				arr[j] = arr[i];
				arr[i] = tmp;
				i++;
			}
		}
		return pivotIndex;
	}

	void printArray(int arr[]){
		int n = arr.length;
		for (int i = 0; i <n; ++i)
			System.out.print(arr[i] + " ");
		System.out.println();
	}
}
