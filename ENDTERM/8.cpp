#include<bits/stdc++.h>
using namespace std;

class Solution{
	public:
	bool isPrime(int n) {
	    if(n <= 1) return false;
	    if(n <= 3) return true;
	    if(n % 2 == 0 || n % 3 == 0) return false;
	    
	    for(int i = 5; i * i <= n; i += 6) {
	        if(n % i == 0 || n % ( i + 2) == 0) return false;
	    }
	    return true;
	}
	
	vector<int> findTwo(int n) {
	    for(int i = 2; i <= n / 2; i++) {
	        if(isPrime(i) && isPrime(n - i)) {
	            return vector<int> {i, n - i};
	        }
	    }
	    return {-1,-1};
	}
	vector<int> Express(int N){
	    int n = N;
	    if(N < 8) {
	        return vector<int> {-1};
	    }
	    if(N % 2 == 0) {
	        auto ans = findTwo(n - 4);
	        ans.push_back(2);
	        ans.push_back(2);
	        sort(ans.begin(), ans.end());
	        return ans;
	    } else {
	        auto ans = findTwo(n - 5);
	        ans.push_back(2);
	        ans.push_back(3);
	        sort(ans.begin(), ans.end());
	        return ans;
	    }
	    return vector<int> {-1};
	}
};

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int N;
		cin >> N;
		Solution ob;
		vector<int>ans = ob.Express(N);
		for(auto i: ans)
			cout << i <<" ";
		cout << "\n";
	}  
	return 0;
}
