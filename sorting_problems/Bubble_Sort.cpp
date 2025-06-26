#include <iostream>

void bubbleSort(int arr[], int n){
    for (int i = 0; i < n - 1; i++){
        bool isSwap = false;
        for (int j = 0; j < n - 1 - i; j++){
            if (arr[j] > arr[j + 1]){
                std::swap(arr[j], arr[j + 1]);
                isSwap = true;
            }
        }
        if(!isSwap) return;
    }
}

//Ques: Push zeros to end while maintaining the relative order ot other elements
void sort_to_zerors(int arr[],int n){
    for(int i = 0;i<n-1;i++){
        for(int j = 0;j<n-1-i;j++){
            if(arr[j] == 0){
                std::swap(arr[j],arr[j+1]);
            }
        }
    }
}

int main(){
    int arr[] = {12, 23, 34, 13, 16, 19, 17, 15, 14, 15, 24, 21, 32};
    int n = sizeof(arr) / sizeof(arr[0]);

    //Bubble sort 
    bubbleSort(arr, n);
    for (int i = 0; i < n; i++){
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
    
    int arr1[] = {5,0,2,0,0,3,4,0,1};
    int size = sizeof(arr1)/sizeof(arr1[0]);
    
    //Pushing zeros to the end
    sort_to_zerors(arr1,size);
    for (int i = 0; i < size; i++){
        std::cout << arr1[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
