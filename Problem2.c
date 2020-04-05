#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    for(int l = 1;l<=t;l++)
    {
        string s;
        cin >> s;
        string ans = "";
        int i, j, open = 0, prev = 0;
        for(i=0;i<s.size();i++)
        {
            int x = s[i] - '0';
            if(x > prev)
            {
                for(j=1;j<=(x-prev);j++)
                    ans+='(', open++;
                ans+=s[i];
                prev = x;
            }
            else if(x < prev)
            {
                for(j=1;j<=prev-x;j++)
                    ans+=')', open--;
                ans+=s[i];
                prev = x;
            }
            else
                ans+=s[i];
        }
        while(open > 0)
        {
            ans+=')';
            open--;
        }
        cout << "Case #"<<l<<": " << ans << '\n';
    }
}
