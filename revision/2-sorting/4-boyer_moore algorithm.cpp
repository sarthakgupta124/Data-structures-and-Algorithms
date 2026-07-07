// boyer moore algorithm for finding the majority element which is the element that appears more than n/2 times in an array
#include <bits/stdc++.h>
using namespace std;
int majorityElement(vector<int> &nums){
    int count = 0;
    int candidate = 0;
    for (int num : nums){
        if (count == 0){
            candidate = num;
        }
        if (num == candidate){
            count++;
        }
        else{
            count--;
        }
    }

    return candidate;
}
int main(){
}