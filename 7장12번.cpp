/******************************************************************************
                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.
*******************************************************************************/

#include <iostream>

using namespace std;

class SortedArray{
    int size;
    int *p;
    void sort();
    public:
    SortedArray(){
        size=0, p=NULL;
    }
    
    SortedArray(SortedArray& src){
        this->size = src.size;
        this->p = new int [size];
        for(int i=0; i<size; i++){
            this->p[i] = src.p[i];
        }
        sort();
    }
    
    SortedArray(int p[], int size){
        this->size = size;
        this->p = new int [size];
        for(int i=0; i<size; i++){
            this->p[i] = p[i];
        }
        sort();
    }
    
    ~SortedArray(){delete [] p;}
    
    SortedArray operator + (SortedArray& op2){
        SortedArray tmp;
        tmp.size = size + op2.size;
        tmp.p = new int [tmp.size];
        
        for(int i=0; i<size; i++){
            tmp.p[i] = p[i];
        }
        
        for(int i=3; i<tmp.size; i++){ 
            tmp.p[i] = op2.p[i-3];
        }
        
        sort();
        
        return tmp;
    }
    
    SortedArray& operator = (const SortedArray& op2){
    delete [] p;
    this->size = op2.size;
    this-> p = new int[this->size];
    for(int i=0; i<this->size; i++){
        this->p[i] = op2.p[i];
    }
    sort();
    
    return *this;
}
    
    void show(){
        cout << "배열 출력 : ";
        for(int i=0; i<size; i++){
            cout << p[i] << ' ';
        }
        cout << endl;
    }
};

void SortedArray::sort(){
    int tmp;
    for(int i=0; i<size-1; i++){
    if(p[i] > p[i+1]){
    tmp = p[i];
    p[i] = p[i+1];
    p[i+1] = tmp;
    }
    }
}

int main()
{
    int n[] = {2, 20, 6};
    int m[] = {10, 7, 8, 30};
    SortedArray a(n,3), b(m,4), c;
    
    c = a + b;
    
    a.show();
    b.show();
    c.show();
    
    return 0;
}