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
    // up heapify O(logn) beaceuse complete binary trees level h(logn)
    void up_heapify(int idx)
    {
        while (idx > 0 && nodes[idx] > nodes[(idx - 1) / 2])
        {
            swap(nodes[idx], nodes[(idx - 1) / 2]);
            idx = (idx - 1) / 2;
        }
    }
    // insert O(n)
    void inseart(int x)
    {
        nodes.push_back(x);
        up_heapify(nodes.size() - 1);
    }
    // downify
    void down_hepify(int idx)
    {
        while (1)
        {
            int largest = idx;
            int l = idx * 2 + 1;
            int r = idx * 2 + 2;
            if (l < nodes.size() && nodes[largest] < nodes[l])
                l = largest;
            if (r < nodes.size() && nodes[largest] < nodes[r])
                r = largest;
            if (largest == idx)
                break;
            swap(nodes[idx], nodes[largest]);
            idx = largest;
        }
    }
    // delete index
    void Delete(int idx)
    {
        if (idx >= nodes.size())
            return;
        swap(nodes[idx], nodes[nodes.size() - 1]);
        nodes.pop_back();
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
    cout << "\n";
    h.Delete(2);
    for (auto it : h.nodes)
        cout << it << " ";
    cout << "\n";
    return 0;
}