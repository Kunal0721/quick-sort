#include <iostream>
using namespace std;

void swap(int *a, int *b){
	int t = *a;
	*a =*b;
	*b=t;
}

void printarray(int array[], int n){
	for(int i = 0; i<n; i++){
		cout<<array[i]<<" "<<endl;
	}
}

int partition(int array[], int low , int high){
	int pivot =array[high];
	int i = low-1;
	for(int j = low; j<high; j++){
		if(array[j]<=pivot){
			i++;
			swap(&array[i], &array[j]);
		}
			
	}
	swap(&array[i+1], &array[high]);
	return (i+1);
}

void quicksort(int array[], int low,  int high){
	if(low<high){
		int pi = partition(array, low , high);
		quicksort(array, low, pi-1);
		quicksort(array, pi+1, high);
	}
}

int main() {
	int ar[] = {5,2,8,69,89,0,1};
	int s = sizeof(ar)/sizeof(ar[0]);
	cout<<"Before sorting "<<endl;
	printarray(ar,s);
	quicksort(ar,0,s-1);
	cout<<"After sorting "<<endl;

	printarray(ar,s);
	return 0;
}
