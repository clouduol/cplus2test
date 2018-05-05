#include <iostream>
using namespace std;

void nextChar(char*&);
void nextChar2(char**);
int main() {
	char* str="This is a test";
	cout<<*str<<endl;
	nextChar(str);
	cout<<*str<<endl;
	nextChar2(&str);
	cout<<*str<<endl;
}

void nextChar(char* &str) {
	str++;
}

void nextChar2(char** str) {
	(*str)++;
}
