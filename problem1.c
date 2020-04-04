#include<bits/stdc++.h>
using namespace std;
int main()
{

    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
            int m,rc=0,c=0,d=0;
            cin>>n;

            int a[m][m];



            for(int j=0;j<n;j++)
            {
               set<int> l;
                    for(int k=0;k<n;k++)
                    {
                        cin>>a[j][k];
                       l.insert(a[j][k]);
                        if(j==k)
                            d+=a[j][k];

                    }
                    if(l.size()!=n)
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
