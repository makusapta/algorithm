#include<stdio.h>

// void mergeArr(int A[], int B[]);

void merge(int high,int low, int mid, int arr[]){
printf("Merge function \n");
    int i, j, k, store[10];

    i =low;
    j = mid;
    k = low;

    while(i<= mid -1 && j<=high){
        if(arr[j]>arr[i]){
            store[k] = arr[i];
            k++; i++;
        }
        else{
            store[k] = arr[j];
            k++; j++;
        }
    }

    while(i>= mid - 1 && j<=high){
        store[k] = arr[j];
        k++; j++;
    }

    while(j>= high && i<=mid -1){
        store[k] = arr[i];
        k++; i++;
    }

    for(int i=low; i<high + 1; i++){
        arr[i] = store[i];
    }
}

void mergeSort(int arr[], int low, int high){
    printf("MergeSort function \n");
    int mid;
    if(low<high){
        mid = (low + high)/2;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid+1, high);
        merge(high, low, mid, arr);
    }
}

void print(int arrSize, int arr[]){
    for(int i=0; i<arrSize; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main()
{
    int arr[7] = {51, 65, 77, 11, 22, 33, 55};
    int arrSize = sizeof(arr)/sizeof(arr[0]);
    int high = arrSize - 1;    //high
    int low = 0;              //low
    int mid = (low + high)/2;

    print(arrSize, arr);
    //merge(high, low, mid, arr);

    mergeSort(arr, low, high);

    print(arrSize, arr);


    // int A[7] = {11, 12, 13, 14, 15, 16, 17};
    // int B[5] = {1, 2, 3, 4, 5};

    // mergeArr(A, B);

    return 0;
}


 //Merging two sorted array in one sorted array,
// void mergeArr(int A[], int B[]){
//     int sizeA = 7;
//     int sizeB = 5;
//     int i=0; 
//     int j=0; 
//     int k=0; 
//     int store[100];
//     while(i<sizeA && j<sizeB){
//         if(A[i]>B[j]){
//             store[k] = B[j];
//             k++;
//             j++;
//         }
//         else{
//             store[k] = A[i];
//             k++; 
//             i++;
//         }
//     }
//     while(i>=sizeA && j<sizeB){
//         store[k] = B[j];
//          k++; j++;
//      }
//      while(j>=sizeB && i<sizeA){
//         store[k] = A[i];
//          k++; i++;
//      }

//      for(int i=0; i<sizeA + sizeB; i++){
//         printf("%d ",store[i] );
//      }

// }