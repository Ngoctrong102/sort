#include<iostream>
#include<stdlib.h>
#include<time.h>
using namespace std;

void bubbleSort(int* arr, int size){
    for (int i=0;i<size;i++){
        for (int j=size-1;j>i;j--){
            if (arr[j]<arr[j-1]) swap(arr[j],arr[j-1]);
        }
        cout << arr[i] << endl;
    }
}

// void quickSort(int* arr, int size){
//     if (size < 2) return;
//     int center = arr[size/2];
//     int left = 0;
//     int right = size-1;
//     while (left < right){
//         while (arr[left] <= center) left++;
//         while (arr[right] >= center) right--;
//         if (left > right) break;
//         swap(arr[left],arr[right]);
//     }
//     quickSort(arr,right+1);
//     quickSort(arr+left,size-left);  
// }

int partition(int* arr, int left, int right){
    int temp = arr[right];
    int i = left-1;
    for (int j=left;j<right;j++){
        if (arr[j] < temp){
            i++;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[right],arr[i+1]);
    return i+1;
}

void quickSort(int* arr, int left, int right){
    if (left < right){
        int pi = partition(arr,left,right);
        quickSort(arr,left,pi-1);
        quickSort(arr,pi,right);
    }
}

int main(){
    int size;
    cin >> size;
    int* array = new int[size];
    srand(time(NULL));
    for (int i=0;i<size;i++) {
        array[i] = rand()%(100*size);
        // cout << array[i] << "  ";
    }
    cout << endl;
    // bubbleSort(array,size);
    quickSort(array,0,size-1);
    for (int i=0;i<size-1;i++){
        if (array[i] > array[i+1]){
            cout << array[i];
            cout << "Sai r :\"<";
            return 0;
        }
    }
    cout << "Dung het roi :\">";
    return 0;
}