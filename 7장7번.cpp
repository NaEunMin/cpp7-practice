/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

using namespace std;

class Matrix{
    int Num_array[4];
    public:
    Matrix(int num1=0, int num2=0, int num3=0, int num4=0){
        Num_array[0]=num1;
        Num_array[1]=num2;
        Num_array[2]=num3;
        Num_array[3]=num4;
    }
    void show(){
        cout << "Matrix = { ";
        for(int i=0; i<4; i++){
            cout << Num_array[i] << ' ';
        }
        cout << '}';
    }
    /* 클래스 멤버함수 구현 ******************
    int* operator >> (int x[4]){
        for(int i=0; i<4; i++){
            x[i] = Num_array[i];
        }
        return x;
    }
    
    Matrix& operator << (int x[4]){
        for(int i=0; i<4; i++){
            Num_array[i] = x[i];
        }
        return *this;
    }*/
    
    friend void operator >> (Matrix op, int x[4]);
    friend void operator << (Matrix &op, int x[4]);

};

void operator >> (Matrix op, int x[4]){
    for(int i=0; i<4; i++){
        x[i] = op.Num_array[i];
    }
}

void operator << (Matrix &op, int x[4]){
    for(int i=0; i<4; i++){
        op.Num_array[i] = x[i];
    }
}

int main()
{
    Matrix a(4,3,2,1), b;
    int x[4], y[4] = {1,2,3,4};
    a >> x;
    b << y;
    
    for(int i=0; i<4; i++){
        cout << x[i] << ' ' ;
    }
    
    cout << endl;
    b.show();

    return 0;
}
