#include <algorithm>
#include <cassert>
#include <iostream>
#include <string>

#define NO_ARGS argc == 1
#define FIRST_ARG 1

using namespace std;

bool isUnique(string str) {
  sort(str.begin(), str.end());
  // Skip the last letter as there is no subsequent letter to check it with
  for (long unsigned letterPos = 0; letterPos < str.length() - 1; ++letterPos) {
    // As sorted, all identical letters are contiguous
    if (str[letterPos] == str[letterPos + 1]) {
      return false;
    }
  }
  return true;
}

void testIsUnique(string testCase) {
  cout << boolalpha;
  cout << testCase << " " << isUnique(testCase) << endl;
}

int main(int argc, char **argv) {
  if (NO_ARGS) {
    testIsUnique("test");     // expect false, t appears twice
    testIsUnique("abdefghi"); // expect true
  } else {
    for (int argIndex = FIRST_ARG; argIndex < argc; argIndex++) {
      testIsUnique(argv[argIndex]);
    }
  }
}
