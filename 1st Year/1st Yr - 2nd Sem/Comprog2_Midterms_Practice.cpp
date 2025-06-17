#include <iostream>
using namespace std;
int iMin(int arr[], int i);
int iMax(int arr[], int i);
int rMin(int arr[], int i);
int rMax(int arr[], int i);
void Sort(int arr[],int Size);
void ifib(int n);
int rfib(int n);
int main(){
    int ar[]={5,6,7,34,21,3,54,1},i = sizeof(ar)/sizeof(ar[0]);
    int imi=iMin(ar,i),ima=iMax(ar,i);
    cout<<"Lowest ite val: "<<imi<<endl;
    cout<<"Highest ite val: "<<ima<<endl;

    int ar2[]={34,545,65554,32,12,23,34,3234,32},j = sizeof(ar2)/sizeof(ar2[0]);
    int rmi=iMin(ar2,j),rma=rMax(ar2,j);
    cout<<"Lowest ite val: "<<rmi<<endl;
    cout<<"Highest ite val: "<<rma<<endl;

    cout<<"Before: ";
    for(int k = 0;k<i-1;k++){
        cout<<ar[k]<<" ";
    }
    Sort(ar,i);
    cout<<"\nAfter: ";
    for(int k = 0;k<i-1;k++){
        cout<<ar[k]<<" ";
    }

    int n;
    cout<<"\nEnter number to fibonacci sequence: ";cin>>n;
    ifib(n);
    int fib = rfib(n);
    cout<<fib<<endl;

    return 0;
}

int iMin(int arr[], int i){
    int Min=arr[0],j;
    for(j = 1; j< i; j++){
        if(Min<= arr[j])
        Min = arr[j];
    }return Min;
}
int iMax(int arr[], int i){
int Max=arr[0],j;
    for(j = 1; j< i; j++){
        if(Max>= arr[j])
        Max = arr[j];
    }return Max;
}

int rMin(int arr[], int i){
    if(i==0)
        return 0;
    if(arr[i-1] <= rMin(arr,i-1)){
        return arr[i-1];
    }else
        return rMin(arr,i-1);
}
int rMax(int arr[], int i){
    if(i==1)
        return arr[i-1];
    if(arr[i-1] <= rMax(arr,i-1)){
        return arr[i-1];
    }else
        return rMax(arr,i-1);
}
void Sort(int arr[],int Size){
    int i,t,j;
    for(i=0;i<Size-1;i++){
        for(j=i+1;j<=Size-1;j++){
            if(arr[i]<arr[j]){
                t= arr[i];
                arr[i]= arr[j];
                arr[j] = t;
            }
        }
    }
}
void ifib(int n){
    int i, first =1,second = 1,tsec=0;
    for(i =1;i<n;i++){

        tsec=first+second;
        first = second;
        second = tsec;
    }cout<< first<<endl;
}
int rfib(int n){
    if(n==0)
        return 0;
    if(n==1) return 1;
    else return rfib(n-1)+rfib(n-2);
}


