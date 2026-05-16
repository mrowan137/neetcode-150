// problem: https://neetcode.io/problems/string-encode-and-decode/question
// approach: encoding as length, marker, string
// complexity: O(N) time, O(1) space, N := total chars
#include <string>
#include <vector>

class Solution {
 public:
  std::string encode (const std::vector<std::string>& strs) {
    std::string ret = "";
    for (const std::string& s : strs) ret += (std::to_string(s.size()) + '#' + s);
    return ret;
  }

  std::vector<std::string> decode (const std::string& s) {
    std::vector<std::string> ret;
    int i = 0, j = 0;
    while (i < static_cast<int>(s.size())) {
      j = i;  // invariant: i points to start of digits
      while (j < static_cast<int>(s.size()) && s[j] != '#') ++j;  // point j to end of digits
      if (j == static_cast<int>(s.size())) break;  // no more strings to process
      int length = std::stoi(s.substr(i, j - i));
      ret.push_back(s.substr(j + 1, length));  // add string to results
      i = j + 1 + length;  // maintain invariant: i points to start of digits
    }
    return ret;
  }
};
