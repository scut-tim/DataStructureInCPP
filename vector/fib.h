

class Fib{
    

    private:
        int f;
        int g;
    public:
        
        Fib(int n){
            f = 1; g = 0;
            while(g<n){ next(); }
        }

        int get(){
            return g;
        }

        int next(){
            g += f; f = g - f;
            return g;
        }

        int pre(){
            f = g - f; g -= f;
            return g;
        }
};