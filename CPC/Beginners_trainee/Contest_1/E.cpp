// Filter

#include <iostream>

using namespace std;

int main(){
    int n, x; cin>>n;

    int* nums = new int[n];

    for (int i = 0; i < n; ++i) {
        cin>>x;

        nums[i] = x;
    }

    for (int i = 0; i < n; ++i) {
        if (nums[i] % 2 == 0) {
            cout<<nums[i]<<" ";
        }
    }

    delete [] nums;
    nums = nullptr;

    return 0;
}