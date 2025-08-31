#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    static void reverseString(string& str) {
        string::iterator start = str.begin();
        string::iterator end = str.end() - 1;

        while (start < end) {
            swapCharacters(start, end);
            ++start;
            --end;
        }
    }

    // static void reverseStringPointer(string& str) {
    //     char* start = &str[0];
    //     char* end = &str[str.size() - 1];
    //
    //     while (start < end) {
    //         swapCharacters(start, end);
    //         ++start;
    //         --end;
    //     }
    // }

private:
    static void swapCharacters(auto& a, auto& b) {
        char const temp = *a;
        *a = *b;
        *b = temp;
    }
};

int main() {
    string str = "MetaInterview";
    Solution::reverseString(str);
    cout << str << endl;

    // string anotherStr = "AnotherInterview";
    // Solution::reverseStringPointer(anotherStr);
    // cout << anotherStr << endl;
    return 0;
}
