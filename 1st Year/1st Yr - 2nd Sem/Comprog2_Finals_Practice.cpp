#include <iostream>
using namespace std;


class methods{
public:
    bool iSorted(int arr[],int s){
        for (int i = 0; i<s-1; i++){
            if(arr[i]<arr[i+1]){
                return false;
                }
        }return true;
    }
    int iOccur(int arr[],int n,int s){
        int num=0;
        for (int i=0;i<s;i++){
            if(n == arr[i])num+=1;
        }
        return num;
    }
    int rOccur(int arr[],int n,int i){
        if(i<0)
            return 0;
        if(arr[i]==n){
            return 1 + rOccur(arr,n,i-1);
        }
        else
            return rOccur(arr,n,i-1);
    }
    int iSmall(int arr[],int s){
        int sm=arr[0];
        for(int i=0;i<s-1;i++){
            if(arr[i]<arr[i+1])
                sm = arr[i];
            else sm = arr[i+1];
        }
        return sm;
    }
    int rSmall(int arr[],int s){
        if (s == 1)
            return arr[0];
        int sm = rSmall(arr, s - 1);
        if (arr[s- 1] < sm)
            return arr[s- 1];
        else
            return sm;
    }

    bool iPal(int arr[],int s){
        for(int i=0;i<s/2;i++){
            if(arr[i]!=arr[s-1-i])
                return false;
        }return true;
    }
    bool rPal(int arr[],int i,int s){
        if(i >= s)
            return true;
        if(arr[s-1]!=arr[i])
            return false;
        else
            return rPal(arr,i+1,s-1);
    }

};

int main(){
    methods m;
    int arr[]={76,57,54,54,32},arrp[]={5,4,3,2,2,3,4,5};
    int s = sizeof(arr)/sizeof(arr[0]),s2=sizeof(arrp)/sizeof(arrp[0]);
    if(m.iSorted(arr,s))
        cout <<"1. Sorted in descending order"<< endl;
    else
        cout<<"1.  Sorted not in descending order"<<endl;

    int n = 54;
    int ocr = m.rOccur(arr,n,s);
    cout<<"2. Number of occurence/s of "<<n<<" is: "<<ocr<<endl;

    int sm=m.iSmall(arr,s);
    cout<<"3. The smallest element in the array is: "<<sm<<endl;
    int smr=m.rSmall(arr,s);
    cout<<"4. The smallest element in the array is: "<<smr<<endl;

    if(m.iPal(arrp,s2))
        cout<<"5. Array is palindrome"<<endl;
    else
        cout<<"5. Array is not palindrome"<<endl;

    if(m.rPal(arrp,0,s2))
        cout<<"6. Array is palindrome"<<endl;
    else
        cout<<"6. Array is not palindrome"<<endl;

    return 0;
}
