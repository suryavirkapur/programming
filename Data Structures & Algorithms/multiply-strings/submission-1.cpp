#include "dsa/dsa.hpp"
using namespace std;

class Solution {
   public:
    string multiply(string num1, string num2) {
        if (num1 == "0"  ||  num2 == "0") {
            return "0";
        }

        int s1 = num1.size();
        int s2 = num2.size();

        vector<int> res(s1+s2,0);

        for (int i =  s1 - 1; i >= 0; i--) {
              for (int j =  s2 - 1; j >= 0; j--) {
                

                int digit1 = num1[i] - '0';
                int digit2 = num2[j] - '0';

                int product = digit1 * digit2;

                int sum = res[i + j + 1] + product;

                res[i + j + 1] = sum % 10;
                res[ i + j] += sum / 10;


            }
        }
        string ans;
        for (int num : res) {
            if (!(ans.empty() && num == 0)) {
                ans.push_back(num + '0');
            }
        }

        return ans;
    }
};

int main() { return 0; }
