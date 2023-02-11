/******************************************************************************
                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.
*******************************************************************************/

#include <iostream>

using namespace std;

class Stack{
    int *num_Array;
    int size;
    public:
    Stack(int size=0){
        this->size = size;
        num_Array = new int[size];
    }
    
    ~Stack(){ delete [] num_Array;}
    
    Stack& operator << (int num){
        num_Array[size] = num;
        size++;
        return *this;
    }
    
    bool operator !(){
        if(size == 0)
        return true;
        else
        return false;
    }
    
    int operator >> (int& num){
        num = num_Array[size-1]; //위에 <<연산자함수에서 마지막에 size가 1증가
        size--;                  //그래서 마지막에 -1해줌.
        return num;
    }
};

int main()
{
    Stack stack;
    stack << 3 << 5 << 10;
    while(true) {
        if(!stack) 
        break;
        int x;
        stack >> x;
        cout << x << ' ';
    }
    cout << endl;
    return 0;
}