#include<iostream>
using namespace std;


//studying <<csapp>>
int main(){
    unsigned char* charPointer;
    int a = 0x87654321;
    //cout<<&a;
    charPointer = (unsigned char*)&a;
    //cout<<charPointer;
    for(int i = 0;i<sizeof(int);i++){
        printf("%.2x ",charPointer[i]);
    }
;

    //cout<<sizeof(char);
}