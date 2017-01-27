#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>

using namespace std;

int main() {
    string a,vec,res;
    int i,max;
    bool found;
    while(getline(cin,a)){
        sort(a.begin(), a.end());
        res="";
        vec="";
        max=0;
        //cout << a << endl;
        for(i=0;i<a.size();i++){
            size_t n = count(a.begin(), a.end(), a[i]);
            size_t t = count(vec.begin(), vec.end(), a[i]);
            if(t==0 && ( ( a[i] >= 'a' && a[i] <= 'z' ) || ( a[i] >= 'A' && a[i] <= 'Z' ) ) ){
                //cout<< n << " - " << a[i] << endl;
                if(n==max )
                {
                    res+=a[i];
                } else if(n>max){
                    res=a[i];
                    max=n;
                }
                vec+=a[i];
            }
        }
        sort(res.begin(), res.end());
        cout<< res << " " << max  << endl;
    }

}