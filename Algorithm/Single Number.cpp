#include <iostream>
#include <stack>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
 public:
  int singleNumber(vector<int> &nums) {
    // stack
    // stack<int> numberStack;
    unordered_map<int, int> numberHash;
    for (auto it = nums.begin(); it != nums.end(); ++it) {
      // cout << *it;
      if (numberHash.find(*it) == numberHash.end()) {
        ++numberHash[*it];
      } else {
        numberHash[*it] = 0;
      }

    }
    for (auto it = nums.begin(); it != nums.end(); ++it) {
      // cout << *it;
      if (numberHash[*it] == 1) {
        return *it;
      }

    }
    return 0;
  }
};

int main(int argc, char const *argv[]) {
  int input;
  Solution mySolution;
  vector<int> myInput;
  while (cin >> input) {
    cout << input << "  ";
    myInput.push_back(input);
  }
  cout << endl;
  cout << mySolution.singleNumber(myInput);


  return 0;
}