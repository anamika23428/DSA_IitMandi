#include<bits/stdc++.h>
using namespace std;
int comp=0;
void merge(vector<int>& arr, int low,int mid,int high){
    int n = arr.size();
    vector<int> temp;
    int i = low, j = mid + 1;
    while(i<=mid && j<=high){
        comp++;
        if(arr[i]>arr[j]){
            temp.push_back(arr[j]);
            j++;
        }  
        else{
            temp.push_back(arr[i]);
            i++;
        }
    }
    while(i<=mid){
        temp.push_back(arr[i]);
        i++;
        }
        while(j<=high){
            temp.push_back(arr[j]);
            j++;
        }
    for (int k = 0; k < temp.size(); k++) {
            arr[low + k] = temp[k];  
        }

}
void mergesort(vector<int>& arr,int low, int high){
    if(low>=high){return ;}
    int mid=(low+high)/2;
    mergesort(arr,low,mid);
    mergesort(arr,mid+1,high);
    merge(arr,low,mid,high);
}
int main(){
vector<int> vec= {5, 3, 8, 1, 4, 2};
mergesort(vec,0,5);
for(int i:vec){
cout<<i<<" ";
}
cout<<endl;
cout<<"Comparisons: "<<comp<<endl;
}