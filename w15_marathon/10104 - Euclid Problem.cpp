#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <cmath>

using namespace std;

long long int x, y;
void gcd(long long int a, long long int b){
    long long int aux;
    if(b == 0){
        x = 1;
        y = 0;
        
    }else {
    gcd(b, a % b);
    aux = y;
    y = x - a/b*y;
    x = aux;
    }
}


int main() {
    long long int a,b,aux;
    int i,j;
    bool found;
    while(cin >> a >> b){
        if(a==0){
            aux=b;
            b=a;
            a=aux;
        }
        gcd(a,b);
        cout<< x << " " << y << " " << (x*a)+(y*b) << endl;
    }

}