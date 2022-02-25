/*
Check Permutation: Given two strings, write a method to decide if one is a
permutation of the other.
*/

#include <cassert>
#include <iostream>
#include <map>
#include <string>

#define NO_ARGS (argc == 1)

using namespace std;

bool checkPermutation(string str1, string str2) {
  map<char, int> letters{};
  for (auto c : str1) {
    letters[c] += 1;
  }

  for (auto c : str2) {
    if (letters[c] == 0) {
      return false;
    }
    letters[c] -= 1;
  }

  for (auto letter_count : letters) {
    if (get<int>(letter_count) > 0) {
      return false;
    }
  }

  return true;
}

void testCheckPermutation(string str1, string str2) {
  cout << boolalpha;
  cout << str1 << " " << str2 << " " << checkPermutation(str1, str2) << endl;
}

int main(int argc, char **argv) {
  if (NO_ARGS) {
    testCheckPermutation("not", "permutation");
    testCheckPermutation("test", "test");
    testCheckPermutation("hello", "loleh");
    testCheckPermutation("hello", "helloo");
  } else {
    assert(argc % 2 == 1);
    for (int i = 1; i < argc; i += 2) {
      testCheckPermutation(argv[i], argv[i + 1]);
    }
  }
}