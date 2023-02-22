/**
 *author:Abu Jafar Shiddik
 *created:21-02-2023(18:51:00)
 **/
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    priority_queue<int> pq;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        pq.push(x);
    }
    int k;
    cin >> k;

    for (int i = 0; i < k; i++)
    {
        cout<<pq.top()<<" ";
        pq.pop();
    }
    return 0;
}