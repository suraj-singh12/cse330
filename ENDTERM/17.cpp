// Sphenic Number


#include<bits/stdc++.h>
using namespace std;


class Solution{
	public:
	bool isPrime(int n) {
	    if(n <= 1) return false;
	    if(n <= 3) return true;
	    if(n % 2 == 0 || n % 3== 0) return false;
	    for(int i = 5; i * i <= n; i+=6) {
	        if(n % i == 0 || n % (i + 2) == 0) return false;
	    }
	    return true;
	}
	int isSphenicNo(int n){
	    int cnt = 0;
	    int product = 1;
	    for(int i = 2; i <= n; ++i) {
	        if(n % i == 0) {
	            if(isPrime(i)) {
	                product *= i;
	                cnt++;
	            }
	        }
	    }
	    return (cnt == 3 && product == n);
	}
};

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int N;
		cin >> N;
		Solution ob;
		int ans = ob.isSphenicNo(N);
		cout << ans <<"\n";
	}  
	return 0;
}
