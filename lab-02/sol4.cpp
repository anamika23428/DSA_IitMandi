//insertion sort
using namespace std;
#include <iostream>
#include <bits/stdc++.h>
int main(){
vector<int> arr={0,2,3,2,1,6,7,9};
int comparisions=0;
int swap=0;
for(int i=0;i<arr.size();i++){
    int j=i;
    while(j>0 && arr[j-1]>arr[j]){
        int temp=arr[j];
        arr[j]=arr[j-1];
        arr[j-1]=temp;
        swap++;
        j--;
        comparisions++;
    }
    if(j>0){comparisions++;}

}
for(int i: arr){
    cout<<i<<" ";
}
cout<<endl;
cout<<"swap="<<swap<<endl;
cout<<"comp= "<<comparisions<<endl;
}