#include <iostream>
#include <vector>

int main(){
    std::string s;
    std::cin>>s;

    std::vector<std::string> substrings;

    int idx, len;

    for(int i = 0; i < s.length(); ++i){
        idx = i;
        len = 0;

        for (int j = i; j < s.length() - i; ++j) {
            if(s[j] == s[j+1])
                len += 1;
        }

        std::cout<<s.substr(idx, len)<<" ";

    }

//    int max = 0;
//
//    for(int i: index)
//        if(i > max)
//            max = i;
//
//    std::cout<<max;

    return 0;
}