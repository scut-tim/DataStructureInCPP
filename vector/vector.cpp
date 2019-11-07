#include"vector.h"
#include<cmath>
#include"fib.h"





template <typename T>
void Vector<T>::unsort( Rank lo, Rank hi){
    T* v = _elem + lo;
    for(int i = _size;i>0;i--){
        int temp = v[i - 1];
        int randomIndex = rand() % i;
        v[i - 1] = v[randomIndex];
        v[randomIndex] = temp;
    }
}

template <typename T>
Rank Vector<T>::find( T const& e, Rank lo, Rank hi) const{

    while((lo<hi--)&&(_elem[hi] != e);
    return hi;
}

template <typename T>
Rank Vector<T>::insert( Rank r, T const& e){
    expand();
    for(int i = _size;i>r;i--) _elem[i] = _elem[i-1];
    _elem[r] = e; _size++;
    return r;
}

template <typename T>
int Vector<T>::remove( Rank lo, Rank hi){
    if(lo == hi)return 0;

    while( hi < _size )_elem[lo++] = _elem[hi++];
    _size = lo;
    return hi - lo;
}

template<typename T>
T Vector<T>::remove( Rank r){

    T e = _elem[r];
    Vector<T>::remove( r, r+1);
    return e;

}

template<typename T>
int Vector<T>::deduplicate(){
    int oldSize = _size;
    int i = 1;
    while(i<_size)
        ( find(_elem[i],0,i) < 0 )?
            i++ : remove(i);
    return oldSize - _size;
}


template<typename T>
void Vector<T>::traverse( void (*vist) (T&)){
    for(int i = 0;i<_size;i++)vist(_elem[i]);
}


template<typename T>
int Vector<T>::disordered() const{
    
    int n = 0;
    for(int i = 1;i<_size;i++)
        if(_elem[i-1]>_elem[i])n++;

    return n;
}

template<typename T>
int Vector<T>::uniquify(){
    int i = 0; int j = 0;
    while(++j<_size){
        if(_elem[i] != _elem[j])
            _elem[++i] = _elem[j];
    }
    _size = i;
    shrink();
    return j - i;
}


template<typename T>
Rank Vector<T>::binSearch( T const& e, Rank lo, Rank hi)const{
    
    while(lo < hi){
        Rank mi = (lo + hi)>>1;
        if     (e < _elem[mi])  hi = mid;
        else if(e > elem[mi])   lo = mid + 1;
        else                    return mi;    
    }
    return -1;


    
}


template<typename T>
Rank Vector<T>::fibSearch( T const& e, Rank lo, Rank hi)const{
    Fib fib(hi - lo);
    while(lo < hi){
        while(fib.get()>hi - lo)fib.pre();
        int mi = lo + fib.get() - 1;
        if(_elem[mi] > e)hi = mi;
        else if(_elem[mi] < e)lo = mi + 1;
        else return mi;
    }
    
    
}

