#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>

using namespace std;

int main() {
    string ans,read;
    int i,max;
    bool found;
    while(getline(cin,read)){
        ans="";
        //cout << a << endl;
        for(i=0;i<read.size();i++){
            if( ( read[i] >= 'A' && read[i] <= 'C' )){
               ans+="2";
            } else if( ( read[i] >= 'D' && read[i] <= 'F' )){
               ans+="3";
            } else if( ( read[i] >= 'G' && read[i] <= 'I' )){
               ans+="4";
            } else if( ( read[i] >= 'J' && read[i] <= 'L' )){
               ans+="5";
            } else if( ( read[i] >= 'M' && read[i] <= 'O' )){
               ans+="6";
            } else if( ( read[i] >= 'P' && read[i] <= 'S' )){
               ans+="7";
            } else if( ( read[i] >= 'T' && read[i] <= 'V' )){
               ans+="8";
            } else if( ( read[i] >= 'W' && read[i] <= 'Z' )){
               ans+="9";
            } else
                ans+=read[i];

        }
        cout<< ans << endl;
    }

}