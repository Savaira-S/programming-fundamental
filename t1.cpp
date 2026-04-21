#include <iostream>
using namespace std;

void add(int num1, int num2);

int main(){
    int  num1,num2;
    cout<<"enter number 1: ";
    cin>>num1;
    cout<<"enter the number 2: ";
    cin>>num2;
    add(num1,num2);

    return 0;
}
void add(int num1,int num2){
    cout<<"sum "<<num1 + num2;

}
