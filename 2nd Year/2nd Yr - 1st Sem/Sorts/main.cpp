#include <iostream>
using namespace std;

void ibubble(int arr[],int len);
void rbubble(int arr[],int len);

void imerge(int arr[], int n);
void imerge(int arr[], int l, int m, int r);
void rmergeSort(int arr[],int l,int r);
void rmerge(int arr[],int l,int mid,int r);

int main(){
    int arr[] = {32,48,2,5,645};
    int len = sizeof(arr)/sizeof(arr[0]);

    //ibubble(arr,len);
    //rbubble(arr,len);
    rmergeSort(arr,0,4);
    for(int i = 0;i <len;i++){
        cout<<arr[i]<<endl;
    }

    return 0;
}


void ibubble(int arr[],int len){
    int temp = 0;
    for(int i = 0; i < len - 1; i++){
        for(int j =i + 1; j<= len-1; j++){
            if (arr[i] > arr[j]){
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    for(int i = 0; i <len; i++){
        cout<< arr[i]<<endl;
    }
}
void rbubble(int arr[],int len){
    if (len==1) return;

    for (int i = 0; i < len-1;i++){
        if (arr[i] > arr[i+1]){
            swap(arr[i], arr[i+1]);
        }
    }
    rbubble(arr,len-1);
}

void imerge(int arr[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    int a[n1];  //left subarray
    int b[n2];  //right subarray

    for (int i = 0; i < n1; i++) a[i] = arr[l + i];  //copy left
    for (int i = 0; i < n2; i++) b[i] = arr[m + 1 + i]; //copy right

    int i = 0, j = 0, k = l;

    while (i < n1 && j < n2) {   //merge back to arr
        if (a[i] < b[j]) arr[k++] = a[i++];
        else arr[k++] = b[j++];
    }

    while (i < n1) arr[k++] = a[i++];  //copy remaining left
    while (j < n2) arr[k++] = b[j++];  //copy remaining right
}

void imergesort(int arr[], int n) {
    //size of subarrays to merge: 1, 2, 4, 8, ...
    for (int curr_size = 1; curr_size <= n - 1; curr_size *= 2) {
        //pick starting index of left subarray
        for (int left_start = 0; left_start < n - 1; left_start += 2 * curr_size) {
            int mid = min(left_start + curr_size - 1, n - 1);  //end of left
            int right_end = min(left_start + 2 * curr_size - 1, n - 1); //end of right

            imerge(arr, left_start, mid, right_end);  //merge two subarrays
        }
    }
}

void rmerge(int arr[],int l,int mid,int r){
    int n1= mid-l+1; //size of left & right subarray
    int n2= r-mid;  //sizes when divided to two

    int a[n1]; //temp left & right array
    int b[n2]; //temp arrays

    for(int i=0;i<n1;i++) //fillnig left & right temp arrays
        a[i] = arr[l+i];

    for(int i=0;i<n2;i++) //fillnig the temp arrays
        b[i] = arr[mid+1+i];

    int i=0; //index for left array
    int j=0; //index for right array
    int k=l; //index for merge array

    while(i<n1 && j<n2){ //merge while both arrays have elements
        if(a[i]<b[j]){ //take smaller element
            arr[k]=a[i];
            k++; i++;
        }
        else{
            arr[k]=b[j];
            k++; j++;
        }
    }
    while(i<n1){  //copy remaining left array elements
        arr[k]=a[i];
            k++; i++;
    }
    while(j<n2){  //copy remaining right array elements
        arr[k]=b[j];
        k++; j++;
    }
}
void rmergeSort(int arr[],int l,int r){
    if (l<r){ //base case: array has more than 1 element
        int mid = (l+r)/2; //find middle

        rmergeSort(arr,l,mid); //sort left half
        rmergeSort(arr,mid+1,r); //sort right half

        rmerge(arr,l,mid,r); //merge the two halves

    }
}
