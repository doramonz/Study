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

void heapify_loop(int* arr, int size, int index) {
    int largest = index;  // 현재 노드를 가장 큰 값으로 설정
    int left, right;

    while (true) {
        left = 2 * largest + 1;  // 왼쪽 자식 노드
        right = 2 * largest + 2; // 오른쪽 자식 노드
        int temp_largest = largest;

        // 왼쪽 자식이 존재하고, 더 크면 largest 업데이트
        if (left < size && arr[left] > arr[temp_largest]) {
            temp_largest = left;
        }

        // 오른쪽 자식이 존재하고, 더 크면 largest 업데이트
        if (right < size && arr[right] > arr[temp_largest]) {
            temp_largest = right;
        }

        // 더 이상 교환할 필요가 없으면 종료
        if (temp_largest == largest) {
            break;
        }

        // 부모와 가장 큰 자식 노드 교환
        swap(arr[largest], arr[temp_largest]);

        // 가장 큰 자식 노드를 기준으로 다시 반복
        largest = temp_largest;
    }
}

void heap_sort(int* arr, int size) {
  for (int i = size / 2 - 1; i >= 0; i--) {
    heapify_loop(arr, size, i);
  }
  for(int i = size-1;i>=0;i--){
    swap(arr[0],arr[i]);
    heapify_loop(arr,i,0);
  }
}

int main(void) {
  int arr[] = {5, 3, 7, 1, 5, 6, 5};
  heap_sort(arr, 7);
  for (int i = 0; i < 7; i++) {
    cout << arr[i] << " ";
  }
}

