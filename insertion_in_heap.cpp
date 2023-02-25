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
                largest = l;
            if (r < nodes.size() && nodes[largest] < nodes[r])
                largest = r;
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
        down_hepify(idx);
    }
    // max value
    int get_max()
    {
        if (nodes.empty())
        {
            cout << "Heap is null \n";
            return -1;
        }
        return nodes[0];
    }
    // extract max
    int extract_max()
    {
        if (nodes.empty())
        {
            cout << "Heap is null \n";
            return -1;
        }
        int ret = nodes[0];
        Delete(0);
        return ret;
    }
    // print heap
    void print_heap()
    {
        for (int i = 0; i < nodes.size(); i++)
            cout << nodes[i] << " ";
        cout << "\n";
    }
    // build heap  from array
    // jodi array value gula agey jana thake
    void build_heap_from_array(vector<int> a)
    {
        nodes = a;
        int n = a.size();
        int last_non_leaf = n / 2 - 1;
        for (int i = last_non_leaf; i >= 0; i--)
        {
            down_hepify(i);
        }
    }
    // size of heap
    int size()
    {
        return nodes.size();
    }
};
// heap sort implementation
vector<int> heap_sort(vector<int> a)
{
    MaxHeap h;
    h.build_heap_from_array(a);
    vector<int> ans;
    for (int i = 0; i < a.size(); i++)
    {
        ans.push_back(h.extract_max());
    }
    reverse(ans.begin(), ans.end());
    return ans;
}
// priority queue implement using heap

class Priority_Queue
{
public:
    MaxHeap mh;
    Priority_Queue()
    {
    }
    // push in pq
    void push(int x)
    {
        mh.inseart(x);
    }
    // pop
    void pop()
    {
        mh.Delete(0);
    }
    // top
    int top()
    {
        return mh.get_max();
    }
    // size
    int size()
    {
        return mh.size();
    }
};
// // min heap implement using max heap
// class Min_heap
// {
// public:
//     MaxHeap mh;
//     void insert(int x)
//     {
//         mh.nodes.push_back(-1 * x);
//         mh.up_heapify(mh.nodes.size() - 1);
//     }
//     void print_min_heap(){
//         mh.print_heap();
//     }
// };
// heap
//   int main()
//  {
//      // MaxHeap h;
//      // h.inseart(5);
//      // h.inseart(15);
//      // h.inseart(7);
//      // h.inseart(18);
//      // h.inseart(4);
//      // h.print_heap();
//      // h.Delete(2);
//      // h.print_heap();
//      // cout << "max = " << h.get_max() << "\n";
//      // h.print_heap();
//      // cout << "extract max = " << h.extract_max() << "\n";
//      // cout << "extract max = " << h.extract_max() << "\n";

//     // vector<int> a = {1, 2, 3, 4, 10, 9, 8, 7};
//     // vector<int> ans = heap_sort(a);
//     // for (int i = 0; i < ans.size(); i++)
//     // {
//     //     cout << ans[i] << " ";
//     // }

//     return 0;
// }

// main for priority queue
//  int main()
//  {
//      Priority_Queue pq;
//      pq.push(10);
//      pq.push(1);
//      pq.push(12);
//      pq.push(9);
//      pq.push(7);
//      while (pq.size() != 0)
//      {
//          cout << pq.top() << " ";
//          pq.pop();
//      }
//      cout << "\n";
//      cout << pq.size();
//  }

// int main()
// {
//     Min_heap mh;
//     mh.insert(4);
//     mh.insert(14);
//     mh.insert(44);
//     mh.insert(3);
//     mh.print_min_heap();
//     return 0;
// }