#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

void Merge(int *A, int *L, int leftCount, int *R, int rightCount){
    int i, j, k;
    i = 0; j = 0; k = 0;
    while(i<leftCount && j < rightCount){
        if(L[i]<R[j]){
            A[k++] = L[i++];
        }else{
            A[k++] = R[j++];
        }
    }
    while (i < leftCount){
        A[k++] = L[i++];
    }
    while (j < rightCount){
        A[k++] = R[j++];
    }
}

void Merge_Sort(int *A,int n){
    int mid, i,*l,*r;
    if (n < 2){
        return;
    }
    mid = n/2;
    l = new int[mid];
    r = new int[n-mid];
    for (i = 0; i < mid; i++){
        l[i] = A[i];
    }
    for (i = mid; i < n;i++){
        r[i-mid] = A[i];
    }

    Merge_Sort(l,mid);
    Merge_Sort(r,n-mid);
    Merge(A,l,mid,r,n-mid);
    delete [] r;
    delete [] l;
}


int main(){
    int A[] = {3,44,5,69,87,1,0,66,5,89,99,151,25,15,13,11,66,88,99};
    int NumberOfElements;
    NumberOfElements = sizeof(A)/sizeof(A[0]);
    Merge_Sort(A,NumberOfElements);
    for (int i = 0; i < NumberOfElements; i++){
        cout << A[i] << ' ';
    }
    cout << endl;
    return 0;
}