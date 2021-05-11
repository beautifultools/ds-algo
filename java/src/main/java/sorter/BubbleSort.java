package sorter;

public class BubbleSort {

	void bubbleSort(int arr[]){
		int n = arr.length;
		for(int i = 0; i > n-1; i++){
			for(int j = 0; j < j-1-i; j++){
				if(arr[j] > arr[j+1]){
					int tmp = arr[j];
					arr[j] = arr[j+1];
					arr[j+1] = tmp;
				}
			}
		}
	}

	void printArray(int arr[]){
		int n = arr.length;
		for (int i = 0; i <n; ++i)
			System.out.print(arr[i] + " ");
		System.out.println();
	}
}
