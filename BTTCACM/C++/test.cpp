/*
 * @Description: ***
 * @Author: Lilin
 * @Date: 2020-04-25 12:01:51
 * @LastEditTime: 2020-04-25 12:02:40
 */
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
int a[100005];
long long int ans;
void merge(int s1,int e1,int s2,int e2){
    int p1,p2,p;
    int* temp = new int[e2-s1+5];
    p=0;p1=s1;p2=s2;
    while(p1<=e1&&p2<=e2){
        if(a[p1]<=a[p2]){
            temp[p++]=a[p1++];
            continue;
        }else{
            temp[p++]=a[p2++];
            ans+=e1-p1+1; 
            continue;
        }
    }
    while(p1<=e1) temp[p++]=a[p1++];
    while(p2<=e2) temp[p++]=a[p2++];
    int i;
    for(i=s1;i<=e2;i++) a[i]=temp[i-s1];
    delete temp;
}
 
void merge_sort(int s,int e){
    int m;
    if(s<e){
        m=(s+e)/2;
        merge_sort(s,m);
        merge_sort(m+1,e);
        merge(s,m,m+1,e);
    }
}
 
int main(){
    int n;
    int num;
    while(cin>>n){
        ans=0;
        long long int step=0;
        for(int i=0;i<n;i++){
            cin>>num;
            if(i%2){
                if(num%2)step++;
            }else a[i/2]=num;
        }
        merge_sort(0,n/2-1);
        step+=ans;
        cout<<step<<endl;
    }
} 
