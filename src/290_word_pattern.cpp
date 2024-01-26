#include<iostream>
#include <map>
using namespace std;
class Solution {
public:
    bool wordPattern(string pattern, string s) {
        map<char, string> map_p;
        map<string, char> map_s;
        int j = 0;
        for(int i = 0; i < pattern.size(); i++)
        {
            string temp = "";
            while(j < s.size() && s[j] != ' ')
            {
                temp += s[j++];
            }
            j++;
            if(temp.empty())
            {
                return false;
            }
            if((map_p.find(pattern[i]) != map_p.end() || map_s.find(temp) != map_s.end()) && 
               (map_p[pattern[i]] != temp || map_s[temp] != pattern[i]))
            {
                return false;
            }
            map_p[pattern[i]] = temp;
            map_s[temp] = pattern[i];
        }
        if(j < s.size()+1)
        {
            return false;
        }
        return true;
    }
};
int main()
{
    string pattern = "abba";
    string s = "dog cat cat dog";
    Solution sol;

    cout << sol.wordPattern(pattern, s)<<endl;

    return 0;
}