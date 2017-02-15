#include <iostream>
#include <string>
#include <vector>

using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unsigned long n = s.length();
        int maxLength = 0, indS = 0, indE = 0;
        vector<bool> ind(128, 0);
        for (; indE < n; indE++) {
            if (ind[s[indE]] != 0) { // repetition detected
                maxLength = max(indE - indS, maxLength);
                while (s[indS] != s[indE]) {
                    ind[s[indS]] = 0;
                    indS++;
                }
                indS++;
            } else { // continue forwarding the point ahead
                ind[s[indE]] = 1;
            }
        }
        return max(indE - indS, maxLength);
    }
};

int main () {
    Solution instance;
    string s = "a";
    while (1) {
        cin >> s;
        cout << instance.lengthOfLongestSubstring(s);
    }
    return 0;
}