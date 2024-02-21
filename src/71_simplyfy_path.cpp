#include<iostream>
#include<stack>
using namespace std;
class Solution {
public:
    string simplifyPath(string path) {

        stack<string>  st;

        string res;

        for(int i = 0; i < path.size(); i++)
        {
            if(path[i] == '/')
            {
                continue;
            }
            string temp;

            while(i < path.size() && path[i] != '/')
            {
                temp += path[i];
                i++;
            }

            if(temp == ".")
            {
                continue;
            }
            else if(temp == "..")
            {
                if(!st.empty())
                {
                    st.pop();
                }
            }
            else
            {
                st.push(temp);
            }
        }
        while(!st.empty())
        {
            res = "/"+ st.top() + res;
            st.pop();
        }
        if(res.size() == 0)
        {
            return "/";
        }         
        return res;
    }
};
int main()
{
    Solution sol;
    string path = "/home//foo/";
    cout << sol.simplifyPath(path) << endl;

    return 0;
}