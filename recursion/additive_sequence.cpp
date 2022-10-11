// given a string, check that if it is additive sequence or not
// 47111829 (4 7 11 18 29) yes
// 413173047 (4 13 17 30 47) yes

#include <iostream>
#include <string> 
using namespace std;

string addStrings(string a, string b) {
    string result = "";

    int carry = 0;
    int i = a.length() - 1;
    int j = b.length() - 1;

    while (i >= 0 && j >= 0) {
        int sum = 0;
        sum += a[i] - '0';
        sum += b[j] - '0';
        sum += carry;
        carry = sum / 10;
        result = to_string(sum % 10) + result;
        i--; j--;
    }

    while(i >= 0) {
        int sum = 0;
        sum += a[i] - '0';
        sum += carry;
        carry = sum / 10;
        result = to_string(sum % 10) + result;
        i--;
    }

    while(j >= 0) {
        int sum = 0;
        sum += b[j] - '0';
        sum += carry;
        carry = sum / 10;
        result = to_string(sum % 10) + result;
        j--;
    }

    if(carry > 0) {
        result = to_string(carry) + result;
    }
    return result;
}

bool check(string a, string b, string c) {
    // check if the strings are valid or not 
    if((a.length() > 1 && a[0] == '0') || (b.length() > 1 && b[0] == '0')) {
        return false;
    }
    // add a and b, and check if == c
    string res = addStrings(a, b);
    if(res == c) {
        cout << "MATCH: a: " << a << ", b: " << b << ", res: " << res << " == " << c << endl;
        return true;
    }

    // if the res (sum) length is greater or equal to remaining string (c), and they are not matched (acc to above condition),
    // or if result is not a substring of c,
    // then no additive sequence possible in this pattern further, 
    if(res.length() >= c.length() || res != c.substr(0, res.length())) {
        cout << "No Possibility: Returning.\n";
        return false;
    } else {
        // otherwise, do check for remaining string (c)
        cout << "recursive: check(" << b << ", " << res << ", " << c.substr(res.length()) << ")" << endl;
        return check(b, res, c.substr(res.length()));
    }
}

string isAdditiveSequence(string str) {
    // addition result cannot be smaller than any of the operands, so logically we need to go till length/2
    for(int i = 1; i < str.length() / 2; ++i) {
        for(int j = 1; j < (str.length() - i) / 2; ++j) {
            cout << "check(" << str.substr(0,i) << ", " << str.substr(i,j) << ", " << str.substr(i + j) << ")" << endl;
            bool isAdditive = check(str.substr(0,i), str.substr(i,j), str.substr(i+j));
            if(isAdditive) {
                return "YES";
            }
        }
    }
    return "NO";
}

int main()
{
    string str = "235813";
    str = "213242751";
    // str = "1011235";
    cout << isAdditiveSequence(str) << endl;
    return 0;
}