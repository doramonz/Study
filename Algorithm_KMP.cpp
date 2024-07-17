#include <iostream>
#include <vector>

using namespace std;

vector<int> getPatter(vector<char> &arr) {
  int index = 0;
  vector<int> result(arr.size(), 0);

  if (arr.size() > 0) result[0] = 0;

  for (int i = 1; i < arr.size(); i++) {
    if (arr[i] == arr[index]) {
      index++;
    } else {
      index = 0;
      if (arr[i] == arr[index]) index++;
    }
    result[i] = index;
  }

  return result;
}

int kmp(vector<char> &text, vector<char> &find) {
  vector<int> pattern = getPatter(find);

  int index = 0;

  while (index + find.size() < text.size()) {
    for (int i = 0; i < find.size(); i++) {
      if (text[index] != find[i]) {
        if (i > 0) {
          if (pattern[i] == 0)
            index++;
          else
            index += pattern[i-1];
        }else{
            index++;
        }
        break;
      }
      if (i == find.size() - 1) {
        return 1;
      }
      index++;
    }
  }
  return -1;
}

int main(void) {
  vector<char> text = {'a', 'b', 'a', 't', 'c', 'a', 'c',
                       'd', 'a', 'b', 'a', 'b', 'c'};
  vector<char> find = {'a', 'b', 'a', 'b'};
  cout << kmp(text, find);
}