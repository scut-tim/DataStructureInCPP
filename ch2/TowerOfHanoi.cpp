#include<iostream>

using namespace std;




void printMvInfo(char source,char aux,char target,int n ){
    
    if( n == 1){
        cout<<"mv "<<n<<" from "<<source<<" to "<<target<<endl;
        return;
    }
    //要完成汉諾塔的任务，为了移动放在最后的一块，必须先达到下面的分布情况，n--n-1。。。1--0
    printMvInfo(source,target,aux,n-1);
    
    cout<<"mv "<<n<<" from "<<source<<" to "<<target<<endl;//将n移动到目标后，继续调用该函数，即下面所述！

    printMvInfo(aux,source,target,n-1);
    

}


int main(){

    printMvInfo('a','b','c',3);

}