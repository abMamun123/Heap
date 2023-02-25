/**
 *author:Abu Jafar Shiddik
 *created:24-02-2023(18:48:26)
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
    // print_heap
    void print_heap()
    {
        for (int i = 0; i < nodes.size(); i++)
        {
            cout << nodes[i] << " ";
        }
        cout << "\n";
    }
    // up_hepify
    void up_hepify(int idx)
    {
        while (idx > 0 && (nodes[idx] > nodes[(idx - 1) / 2]))
        {
            swap(nodes[idx], nodes[(idx - 1) / 2]);
            idx = (idx - 1) / 2;
        }
    }
    // insert in heap
    void insertaion(int x)
    {
        nodes.push_back(x);
        up_hepify(nodes.size() - 1);
    }
    // down heapify
    void down_heapify(int idx)
    {
        while (1)
        {
            int largest = idx;
            int l = idx + 1, r = idx + 2;
            if (l < nodes.size() && nodes[l] > nodes[largest])
                largest = l;
            if (r < nodes.size() && nodes[r] > nodes[largest])
                largest = r;
            if (largest == idx)
                break;
            swap(nodes[largest], nodes[idx]);
            idx = largest;
        }
    }
    // delete in heap
    void deletion(int idx)
    {
        if (idx >= nodes.size())
            return;
        swap(nodes[idx], nodes[nodes.size() - 1]);
        nodes.pop_back();
        down_heapify(idx);
    }
    // get max
    int get_max()
    {
        if (nodes.empty())
            return -1;
        return nodes[0];
    }
};
class MinHeap
{
public:
    MaxHeap mx;
    void insert(int x)
    {
        mx.insertaion(-x);
    }
    void Delete(int idx)
    {
        mx.deletion(idx);
    }
    int getMin()
    {
        int x = mx.get_max();
        return x * (-1);
    }
};

int main()
{
    MinHeap h;
    h.insert(4);
    h.insert(7);
    h.insert(9);
    h.insert(1);
    h.insert(10);
    h.insert(20);
    h.insert(30);
    cout << h.getMin() << "\n";
    return 0;
}