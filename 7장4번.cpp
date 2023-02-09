/******************************************************************************
                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.
*******************************************************************************/


#include <iostream>
#include <string>

using namespace std;

class Book {
	string title;
	int price, pages;
public : 
	Book(string title="", int price=0, int pages=0) {
		this->title = title; this->price = price; this->pages = pages;
	}
	void show() {
		cout << title << ' ' << price << "원 " << pages << " 페이지" << endl;
	}
	string getTitle() { return title; }
	
	friend bool operator < (string title, Book op1);
};

bool operator < (string title, Book op1){
    if(title<op1.title)
    return true;
    else 
    return false;
}
int main() {

	Book a("청춘", 20000, 300);
	string b;
	cout << "책 이름을 입력하세요>>";
	getline(cin, b);
	if (b < a)
	cout << a.getTitle() << "이 " << b << "보다 뒤에 있구나!" << endl;

	return 0;
}