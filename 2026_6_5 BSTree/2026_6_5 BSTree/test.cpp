#include "BinaryTree.h"
#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <set>
using namespace std;
//int main()
//{
//	key_value::TestBSTree3();
//	return 0;
//}


int main()
{
    vector<string> v1 = { "i", "love", "leetcode", "i", "love", "coding" };
    map<string, int> m;
    for (auto e : v1)
    {
        m[e]++;
    }

    map<int, set<string>, greater<int>> sortMap;
    for (auto& kv : m)
    {
        sortMap[kv.second].insert(kv.first);
    }
    vector<string> ret;
    for (auto& kv : sortMap)
    {
        for (auto& word : kv.second)
        {
            cout << word << ":" << kv.first << endl;
            ret.push_back(word);
        }
    }

    
}