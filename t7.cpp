#include<iostream>
#include<cmath>
using namespace std;
float  radian( float angle){
    float pi=3.147895;
    float rad= angle * (pi/180);
    return rad;
}
void heigth( float distance, float ang){
    cout<<"The heigth is : "<<distance * tan(ang);
}
int main(){
    float distance,angle,ang;
    cout<<"Enter distance: "<<endl;
    cin>>distance;
    cout<<"Enter angle: "<<endl;
    cin>>angle;
    ang= radian(angle);
    heigth(distance,ang);
}