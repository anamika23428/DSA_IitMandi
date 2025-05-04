#include <iostream>
using namespace std;
#include <bits/stdc++.h>

int partition(vector<int>& arr, int low,int high){
    int p=arr[high];
    int i=low-1;
    for(int j=low;j<=high-1;j++){
        if(arr[j]<=p){
            i+=1;
            swap(arr[i],arr[j]);
        }
    }
    i++;
    swap(arr[i],arr[high]);
    return i;
}

void quick_sort(vector<int> & arr , int l,int r ){
    if(l<r){
        int p=partition(arr,l,r);
        quick_sort(arr,l,p-1);
        quick_sort(arr,p+1,r);
    }
}
int main(){
    vector<int> arr={2,4,5,11,0,6,7};
    int n=arr.size();
    quick_sort(arr,0,n-1);
    for(int i:arr){
        cout<<i<<" ";
    }
}