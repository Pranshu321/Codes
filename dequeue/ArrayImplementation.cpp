#include <bits/stdc++.h>

using namespace std;

// #define int long long

struct dequeue
{
    int *arr;
    int size;
    int capacity;
    dequeue(int c)
    {
        capacity = c;
        size = 0;
        arr = new int[capacity];
    }

    bool isFull()
    {
        return size == capacity;
    }
    bool isEmpty()
    {
        return size == 0;
    }
    void insertRear(int x)
    {
        if (isFull())
        {
            return;
        }
        arr[size++] = x;
    }
    void deleteRear()
    {
        if (isEmpty())
        {
            return;
        }
        size--;
    }
    int getFront()
    {
        if (isEmpty())
        {
            return -1;
        }
        return arr[0];
    }

    int getRear()
    {
        if (isFull())
        {
            return -1;
        }
        return arr[size - 1];
    }

    void insertFront(int x)
    {
        if (isFull())
        {
            return;
        }
        for (int i = size - 1; i >= 0; i--)
        {
            arr[i + 1] = arr[i];
        }
        arr[0] = x;
        size++;
    }

    void DeleteFront()
    {
        if (isEmpty())
        {
            return;
        }
        for (int i = 0; i < size - 1; i++)
        {
            arr[i] = arr[i + 1];
        }
        size--;
    }

    void Print()
    {
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int32_t main()

{
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);
    dequeue d(10);
    d.insertRear(1);
    d.insertRear(2);
    d.insertRear(3);
    d.insertRear(4);
    d.deleteRear();
    d.Print();

    return 0;
}