// Circular Prime Number

#include<bits/stdc++.h>
using namespace std;
class Solution{

	public:

	bool isPrime(int n) {
	    if(n <= 1) return false;
	    if(n <= 3) return true;
	    if(n % 2 == 0 || n % 3 == 0) return false;
	    for(int i = 5; i * i <= n; i += 6) {
	        if(n % i == 0 || n % (i + 2) == 0) return false;
	    }
	    return true;
	}
	
	int isCircularPrime(int n) {
	    if(n <= 1) return false;
	    int digitCount = ceil(log10(n));
	    int p = digitCount - 1;
	    
	    while(digitCount--) {
	        if(!isPrime(n)) return false;
	        n = ( (n % 10) * pow(10, p) ) + n / 10;        // rotated
	    }
	    return true;
	}
};


int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		Solution ob;
		int ans = ob.isCircularPrime(n);
		cout << ans <<"\n";
	}  
	return 0;
}
