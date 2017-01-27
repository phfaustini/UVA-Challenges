#include <string>
#include <iostream>
#include <algorithm>
#include <sstream>


using namespace std;

int main() {
    int numtest,count;
    long long int a,b,sum;
    
    bool palindrome;
    cin >> numtest;
    while(numtest--){
        count=1;
        palindrome=false;
        string val, reval;
        cin >> val;
        reval = val;
        reverse(reval.begin(),reval.end());
        a = atol(val.c_str());
        b = atol(reval.c_str());
        sum = a+b;
        ostringstream ss;
        ss << sum;
        val = ss.str();
        while(!palindrome){
            reval = val;
            reverse(reval.begin(),reval.end());
            if(val!=reval){
                count++;
                
                a = atol(val.c_str());
                b = atol(reval.c_str());
                sum = a+b;
                ostringstream ss;
                ss << sum;
                val = ss.str();
            }
            else
                palindrome=true;

        }
        cout << count << " "<< val << endl;
    }
    return 0;
}