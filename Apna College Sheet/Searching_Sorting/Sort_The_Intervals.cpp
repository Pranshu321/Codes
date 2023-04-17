// C++ Code to insert a new interval in set of sorted
// intervals and merge overlapping intervals that are
// formed as a result of insertion.
#include <bits/stdc++.h>

using namespace std;

// Define the structure of interval
struct Interval
{
    int s, e;
};

// A subroutine to check if intervals overlap or not.
bool mycomp(Interval a, Interval b) { return a.s < b.s; }

// merge overlapping intervals
void insertNewInterval(vector<Interval> &Intervals, Interval newInterval)
{
    vector<Interval> ans;
    int n = Intervals.size();
    Intervals.push_back(newInterval); // Insert the new interval into Intervals
    sort(Intervals.begin(), Intervals.end(), mycomp);

    int index = 0;
    // Traverse all input Intervals
    for (int i = 1; i <= n; i++)
    {
        // If this is not first Interval and overlaps
        // with the previous one
        if (Intervals[index].e >= Intervals[i].s)
        {
            // Merge previous and current Intervals
            Intervals[index].e = max(Intervals[index].e, Intervals[i].e);
        }
        else
        {
            index++;
            Intervals[index] = Intervals[i];
        }
    }

    for (int i = 0; i <= index; i++)
        cout << Intervals[i].s << ", " << Intervals[i].e << "\n";
}

// Driver code
int main()
{
    vector<Interval> Intervals;
    Interval newInterval;

    newInterval.s = 1;
    newInterval.e = 2;
    Intervals.push_back(newInterval);
    newInterval.s = 3;
    newInterval.e = 5;
    Intervals.push_back(newInterval);
    newInterval.s = 6;
    newInterval.e = 7;
    Intervals.push_back(newInterval);
    newInterval.s = 8;
    newInterval.e = 10;
    Intervals.push_back(newInterval);
    newInterval.s = 12;
    newInterval.e = 16;
    Intervals.push_back(newInterval);
    newInterval.s = 4;
    newInterval.e = 9;

    insertNewInterval(Intervals, newInterval);

    return 0;
}
