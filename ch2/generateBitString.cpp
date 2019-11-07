#include<iostream>
#include<vector>
#include<cstdio>
#include<cstdlib>
using namespace std;

vector<int> values;

vector<vector<int>> generate(int n,vector<vector<int>>& vv,vector<int> v){

    if( n == 0){
        vv.push_back(v);
        return vv;
    }

    else
    {
        
        v.push_back(0);
        generate(n-1,vv,v);
        
        v.pop_back();
        v.push_back(1);
        generate(n-1,vv,v);
    
        return vv;
    }

    

}


void generateAny(int n,int k){
    if(n == 0){
        for(int i : values)cout<<hex<<i<<" ";
        cout<<endl;
        return;
    }
    
    
    for(int i = 0;i<k;i++){
        values.push_back(i);
        generateAny(n-1,k);
        values.pop_back();
    }

}


int main(){
    // vector<vector<int>> vv;
    // vector<int> v;
    // generate(3,vv,v);

    // for(vector<int> v: vv){
    //     for(int i : v){
    //         cout<<i<<" ";
    //     }cout<<endl;
    // }


    generateAny(1,16);

}

