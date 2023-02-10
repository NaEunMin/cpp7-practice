/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

using namespace std;

class Circle{
    int radius;
    public:
    Circle(int radius=0){
        this->radius = radius;
    }
    void show() {
        cout << "radius = " << radius << " 인 원" << endl;
    }
 /*  
    Circle& operator ++(){
        radius++;
        return *this;
    }
    
    Circle operator ++(int x){
        Circle tmp = *this;
        radius++;
        return tmp;
    }*/
    friend Circle& operator ++(Circle &c);
    friend Circle operator ++(Circle &c, int x);
    
};

Circle& operator ++ (Circle &c){
    c.radius++;
    return c;
}

Circle operator ++(Circle &c, int x){
   Circle tmp = c;
   c.radius++;
   return tmp;
}
int main()
{
    Circle a(5), b(4);
    ++a;
    b = a++;
    a.show();
    b.show();

    return 0;
}
