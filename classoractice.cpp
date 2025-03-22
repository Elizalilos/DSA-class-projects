#include <iostream>
#include <string>

using namespace std;

// overloaded function , structure , namespace


int Subtract (int q , int v);
int Subtract(int q , int v , int c);
float Subtract(float q , float v); 

// using namespaces 

namespace VALUES{
    const float PI = 3.14f;
    float gravityOnEarth = 9.18f;
    float Weight(float mass){
        float weight = mass * gravityOnEarth;
        return weight;
    }

}

template <typename T>
T Subtraction(T a , T b){
    T difference = a - b;
    return difference;
}

struct Animal{
    string name;
    int age;
    int numOfChildren;
}  Dog; // 2 ways to initialize objects from struct



int main(){
    float mass;
    cout << Subtract(4 , 5) <<endl;
    cout << Subtract( 5, 7, 9) << endl;
    cout << Subtraction(  16.0 , 15.0) <<endl;
    cout  <<"Enter your mass to find out your weight" <<endl;
    cin >> mass;
    cout <<"Your weight is " <<VALUES::Weight(mass) <<endl;
    Animal Lion;
    Lion.name = "Simba";
    Lion.age = 5;
    Lion.numOfChildren = 1;
    Dog.name = "Jack";
    Dog.age = 4;
    Dog.numOfChildren = 5;
    cout <<"Lion : " << Lion.name << ' ' << Lion.age <<" years old" << ' ' << Lion.numOfChildren <<" Chilren." <<endl;
    cout <<"Dog : " << Dog.name << ' ' << Dog.age <<" years old"<< ' ' <<Dog.numOfChildren <<" children." <<endl;
    return 0;
}

// overloading subtract

int Subtract (int q , int v){
    return q-v;
}

int Subtract(int q , int v , int c){
    return q-v-c;
}

float Subtract(float q , float v){
    return q-v;
}