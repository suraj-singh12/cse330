// Next Prime Palindrome

#include<bits/stdc++.h>
using namespace std;

class Solution {
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
	    
	    bool isPal(int n) {
	        int copy = n;
	        int reverse = 0;
	        while(n) {
	            reverse = reverse * 10 + n % 10;
	            n /= 10;
	        }
	        return (copy == reverse);
	    }
		int PrimePalindrome(int N){
		    int c = N;
		    while(c>=N)
		    {
		        if(isPal(c) && isPrime(c)) return c;
		        c++;
		    }
		}

};

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int N;
		cin >> N;
		Solution obj;
		int ans = obj.PrimePalindrome(N);
		cout << ans << "\n";
	}
	return 0;
}
