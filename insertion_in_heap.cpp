/**
 *author:Abu Jafar Shiddik
 *created:20-02-2023(11:38:29)
 **/
#include <bits/stdc++.h>
using namespace std;
class MaxHeap
{
public:
    vector<int> nodes;
    MaxHeap()
    {
    }
    void up_heapify(int idx)
    {
        while (idx > 0 && nodes[idx] > nodes[(idx - 1) / 2])
        {
            swap(nodes[idx], nodes[(idx - 1) / 2]);
            idx = (idx - 1) / 2;
        }
    }
    void inseart(int x)
    {
        nodes.push_back(x);
        up_heapify(nodes.size() - 1);
    }
};
int main()
{
    MaxHeap h;
    h.inseart(5);
    h.inseart(15);
    h.inseart(7);
    h.inseart(18);
    h.inseart(4);

    for (auto it : h.nodes)
        cout << it << " ";
    cout<<"\n";
    return 0;
}