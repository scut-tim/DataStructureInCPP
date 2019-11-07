typedef int Rank;
#define DEFAULT_CAPACITY 3


template <typename T> class Vector{

protected:    
    Rank _size; int _capacity; T* _elem;//规模 容量 数据区？
    void copyFrom(T const* A, Rank lo, Rank hi){//左闭右开
        _elem = new T[_capacity = 2*(hi - lo)];_size = 0;
        while(lo<hi)
            _elem[_size++] = A[lo++];
    }
    void expand(){
        if( _size < _capacity) return;
        if( _capacity < DEFAULT_CAPACITY)_capacity = DEFAULT_CAPACITY;
        T* oldElem = _elem; _elem = new T[_capacity <<= 1];
        for(int i = 0;i<_size;i++){
            _elem[i] = oldElem[i];
        }
        delete [] oldElem;
    }
    void shrink(){
        if( _capacity < DEFAULT_CAPACITY<<1)return;
        if( _size << 2 > _capacity)return;
        T* oldElem = _elem; _elem = new T[_capacity >>= 1];
        for(int i = 0;i<_size;i++){
            _elem[i] = oldElem[i];
        }
        delete [] oldElem;
    }
    bool bunbble( Rank lo, Rank hi);//扫描交换
    void bunbbleSort( Rank lo, Rank hi);
    Rank max( Rank lo, Rank hi);
    void selectionSort( Rank lo, Rank hi );
    void merge( Rank lo, Rank mi, Rank hi );
    void mergeSort( Rank lo, Rank hi);
    Rank partition( Rank lo, Rank hi);
    void quickSort( Rank lo, Rank hi);
    void heapSort( Rank lo, Rank hi);
public:
    Vector(int c = DEFAULT_CAPACITY, int s = 0, T v = 0){
        _elem = new T[_capacity = c];
        for( _size = 0; _size < s; _elem[_size++] = v);
    }
    Vector(T const* A, Rank n){ copyFrom(A , 0, n);}
    Vector(T const* A, Rank lo, Rank hi){ copyFrom(A, lo, hi);}
    Vector(Vector<T> const& V){ copyFrom(V._elem, 0, V._size);}
    Vector(Vector<T> const& V, Rank lo, Rank hi){ copyFrom(V._elem, lo, hi); }

    ~Vector(){ delete [] _elem;}

    Rank size() const{ return _size;}
    bool empty() const{ return !_size;}
    int disordered() const;
    Rank find( T const& e) const{ return find( T const& e, 0, _size);}//find 无序 search 有序
    Rank find( T const& e, Rank lo, Rank hi) const;
    Rank search( T const& e) const
    { return (0>=_size)? -1 :search( T const& e, 0, _size);}
    Rank search ( T const& e, Rank lo, Rank hi) const{
        return (rand() % 2)? binSearch(e, lo, hi) : fibSearch(e, lo, hi);
    }
    Rank binSearch( T const& e, Rank lo, Rank hi)const;
    Rank fibSearch( T const& e, Rank lo, Rank hi)const;

    T& operator[] ( Rank r ){ return _elem[r] };
    Vector<T> & operator= ( Vector<T> const& V){
        if( _elem )delete [] _elem;
        copyFrom( V._elem, 0, V.size());
        return *this;
    };
    T remove ( Rank r);
    int remove ( Rank lo, Rank hi);
    Rank insert ( Rank r, T const& e);
    Rank insert ( const& T e){ return insert(_size, e);}
    void sort( Rank lo, Rank hi);
    void sort(){ sort(0,_size);}
    void unsort( Rank lo, Rank hi);
    void unsort(){ unsort(0,_size);}

    int deduplicate();
    int uniquify();

    void traverse( void (*vist) (T&));




};




