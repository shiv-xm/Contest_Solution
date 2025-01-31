#include <string>
using namespace std;

class Solution {
public:
    bool hasMatch(string s, string p) {
        size_t starPos = p.find('*');
        string prefix = p.substr(0, starPos);
        string suffix = p.substr(starPos + 1);

        for (size_t i = 0; i <= s.size(); i++) {
          
            if (s.substr(i, prefix.size()) == prefix) {
               
                if (s.substr(i + prefix.size()).rfind(suffix, 0) == 0) {
                    return true;
                }
            }
        }
        return false;
    }
};
int main(){
    return 0;
}