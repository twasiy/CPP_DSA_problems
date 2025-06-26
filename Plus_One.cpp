#include<iostream>
#include<vector>
#include<algorithm>

//This is the most optimal solution for this problem
std::vector<int> plusOne(std::vector<int>& digits) {
    int n = digits.size();
    for (int i = n - 1; i >= 0; --i) {
        if (digits[i] < 9) {
            digits[i] += 1;
            return digits; // no carry, done
        }
        digits[i] = 0; // set to 0 and carry to next
    }
    // All digits were 9 → need extra 1 at front
    digits.insert(digits.begin(), 1);
    return digits;
}

//This is for when you want to do any work with the digits .
std::vector<int> plusone(std::vector<int>& digit){
    long long int num = 0;
    for (int dig : digit) {
        num = num * 10 + dig;
    }
    std::vector<int> res;
    num++;
    // Handle 0 explicitly
    if (num == 0) {
        res.push_back(0);
        return res;
    }
    // Extract digits from the back
    while (num > 0) {
        res.push_back(num % 10); // get last digit
        num /= 10; // remove last digit
    }
    std::reverse(res.begin(),res.end());
    return res;
}

int main() {
    //main solution
    std::vector<int> digits{7,2,8,5,0,9,1,2,9,5,3,6,6,7,3,2,8,4,3,7,9,5,7,7,4,7,4,9,4,7,0,1,1,1,7,4,0,0,6};
    auto result = plusOne(digits);
    for (int num : result) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    //second one
    std::vector<int> digit{7,2,8,5,0,9,1,2,9};
    auto vector = plusone(digit);
    for(auto vec:vector){
        std::cout << vec << " ";
    }
    std::cout << std::endl;
    
    return 0;
}



