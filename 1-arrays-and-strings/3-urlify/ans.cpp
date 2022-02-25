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
  char new_url[url.length() + 1];
  url.copy(new_url, url.length(), 0);
  int offset = 0;
  for (int i = 1; i <= length; ++i) {
    if (url[length - i] == ' ') {
      /* Find nicer way of doing this */
      new_url[url.length() - i - offset] = '0';
      offset++;
      new_url[url.length() - i - offset] = '2';
      offset++;
      new_url[url.length() - i - offset] = '%';
      offset++;
    } else {
      new_url[url.length() - i - offset] = url[length - i];
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