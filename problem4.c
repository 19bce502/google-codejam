#include<bits/stdc++.h>
using namespace std;
int main()
{

    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
            int n,rc=0,c=0,d=0;
            cin>>n;

            int a[n][n];



            for(int j=0;j<n;j++)
            {
               set<int> s;
                    for(int k=0;k<n;k++)
                    {
                        cin>>a[j][k];
                       s.insert(a[j][k]);
                        if(j==k)
                            d+=a[j][k];

                    }
                    if(s.size()!=n)
                        rc++;

            }
            for(int j=0;j<n;j++)
            {
                set <int>s1;
                for(int k=0;k<n;k++)
                {
                    s1.insert(a[k][j]);
                }
                if(s1.size()!=n)
                    c++;
            }

            cout<<"Case #"<<i+1<<": "<<d<<" "<<rc<<" "<<c<<endl;

    }
}
