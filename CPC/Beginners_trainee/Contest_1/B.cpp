// REPETITIONS

#include <iostream>
#include <vector>

int main(){
    std::string s;
    std::cin>>s;

    std::vector<int> substrings;

    int len = 0;

    for (int idx = 0; idx < s.length(); ++idx) {
        len = 1;

        while (std::toupper(s[idx]) == std::toupper(s[idx + 1])) {
            len += 1;
            idx += 1;
        }

        substrings.push_back(len);
    }

    int max = 0;
    for (int i : substrings) {
        if (i > max)
            max = i;
    }

    std::cout<<max;

    return 0;
}