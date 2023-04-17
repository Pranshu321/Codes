#include <bits/stdc++.h>
using namespace std;

// This is a recursive function to fill count for 'mngr'
// using mngrEmpMap. This function uses memoization to
// avoid re- computations of subproblems.
int populateResultUtil(
    string mngr,
    unordered_map<string, vector<string>> mngrEmpMap,
    map<string, int> &result)
{
    int count = 0;

    // means employee is not a manager of any other employee
    if (mngrEmpMap.find(mngr) == mngrEmpMap.end())
    {
        result.insert({mngr, 0});
        return 0;
    }

    // this employee count has already been done by this
    // method, so avoid re-computation
    else if (result.find(mngr) != result.end())
    {
        count = result[mngr];
    }
    else
    {
        vector<string> directReportEmpList = mngrEmpMap[mngr];
        count = directReportEmpList.size();
        for (int i = 0; i < directReportEmpList.size();
             i++)
        {
            count += populateResultUtil(
                directReportEmpList[i], mngrEmpMap, result);
        }
        result.insert({mngr, count});
    }
    return count;
}

// This function populates 'result' for given input
// 'dataset'
void populateResult(unordered_map<string, string> dataset)
{

    // A hashmap to store result. It stores count of
    // employees under every employee, the count may by 0
    // also
    map<string, int> result;

    // To store reverse of original map, each key will have
    // 0 to multiple values
    unordered_map<string, vector<string>> mngrEmpMap;

    // To fill mngrEmpMap, iterate through the given map
    for (auto d : dataset)
    {
        string emp = d.first;
        string mngr = d.second;
        if (emp != mngr) // excluding emp-emp entry
        {
            // If 'emp' is the first employee under 'mngr'
            if (mngrEmpMap.find(mngr) == mngrEmpMap.end())
            {
                vector<string> directReportList;
                directReportList.push_back(emp);
                // add a new entry for the mngr with empty
                // directReportList
                mngrEmpMap[mngr] = directReportList;
            }
            else
            {
                // Get the previous list of direct reports
                // under current 'mngr' and add the current
                // 'emp' to the list
                mngrEmpMap[mngr].push_back(emp);
            }
        }
    }

    // Now use manager-Emp map built above to populate
    // result with use of populateResultUtil()

    // note- we are iterating over original emp-manager map
    // and will use mngr-emp map in helper to get the count
    for (auto d : dataset)
    {
        populateResultUtil(d.first, mngrEmpMap, result);
    }

    map<string, int>::iterator itr;
    auto end = result.end();
    end--; // end to second last;

    cout << "result = {";
    for (itr = result.begin(); itr != end; itr++)
    {
        cout << itr->first << "=" << itr->second << ", ";
    }
    cout << itr->first << "=" << itr->second;
    cout << "}";
}

int main()
{
    unordered_map<string, string> dataset;
    dataset["A"] = "C";
    dataset["B"] = "C";
    dataset["C"] = "F";
    dataset["D"] = "E";
    dataset["E"] = "F";
    dataset["F"] = "F";

    populateResult(dataset);

    return 0;
}

// This code is contributed by Snigdha Patil
