/* 1.1 Is Unique
Implement an algorithm to determine if a string has all unique characters. What
if you cannot use additional data structures?
*/

#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

bool isUnique(string str) {
  unordered_set<char> cs{};
  for (auto c : str) {
    if (cs.find(c) != cs.end()) {
      return false;
    }
    cs.insert(c);
  }
  return true;
}

int main() {
  cout << boolalpha;

  string str1 = "abcdefg";
  cout << str1 << " " << isUnique(str1) << endl;

  string str2 = "test";
  cout << str2 << " " << isUnique(str2) << endl;

  return 0;
}