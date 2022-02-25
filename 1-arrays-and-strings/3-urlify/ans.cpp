/*
URLify: Write a method to replace all spaces in a string with '%20'. You may
assume that the string has sufficient space at the end to hold the additional
characters, and that you are given the "true" length of the string.
*/

#include <algorithm>
#include <iostream>
#include <string>

#define NO_ARGS (argc == 1)
#define FIRST_ARG 1

using namespace std;

string URLify(string url, long length) {
  string new_url = "";
  for (auto c : url) {
    if (c == ' ') {
      new_url += "%20";
    }
    else {
      new_url += c;
    }
  }
  return new_url;
}

void testURLify(string url) {
  long url_length = url.length();
  url.resize(url_length + (count(url.begin(), url.end(), ' ') * 3));
  cout << url << " : " << URLify(url, url_length) << endl;
}

int main(int argc, char **argv) {
  if (NO_ARGS) {
    testURLify("This is a test string");
    testURLify("");
    testURLify("nospaces");
  }
  for (int i = FIRST_ARG; i < argc; ++i) {
    testURLify(argv[i]);
  }
}
