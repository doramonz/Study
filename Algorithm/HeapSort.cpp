#include <iostream>

using namespace std;

void heapify(int* arr, int size, int index) {
  int largest = index;
  int left = index * 2 + 1;
  int right = index * 2 + 2;

  if (left < size && arr[left] > arr[largest]) largest = left;
  if (right < size && arr[right] > arr[largest]) largest = right;
  if (largest != index) {
    swap(arr[index], arr[largest]);
    heapify(arr, size, largest);
  }
}

void heap_sort(int* arr, int size) {
  for (int i = size / 2 - 1; i >= 0; i--) {
    heapify(arr, size, i);
  }
  for(int i = size-1;i>=0;i--){
    swap(arr[0],arr[i]);
    heapify(arr,i,0);
  }
}

int main(void) {
  int arr[] = {5, 3, 7, 1, 5, 6, 5};
  heap_sort(arr, 7);
  for (int i = 0; i < 7; i++) {
    cout << arr[i] << " ";
  }
}