// 574 - Sum It Up

#include <bits/stdc++.h>
using namespace std;


vector<vector<int> > listingSubsets(int n){
  int subsets = 1 << n;
  vector<vector<int > > subs;
  for (int i = 0; i < subsets; i++){
    int aux = i;
    int add = 0;
    vector<int> subsub;
    while (aux != 0){
      if (aux & 1)
        subsub.push_back(add);
      add++;
      aux >>= 1;
    }
    subs.push_back(subsub);
  }
  sort(subs.begin(), subs.end());
  return subs;
}

int main(){
  int t, n;
  cin >> t >> n;

  while (t != 0 && n != 0){
    vector<vector<int> > subsets = listingSubsets(n);
    vector<int> nums(n);
    vector<int> nums2;
    for (int i = 0; i < n; i++){
      cin >> nums[i];
    }
    int sum = 0;
    cout << "Sums of " << t << ":" << endl;
    int flag = 1;
    set<vector<int>, greater<vector<int> > > set;
    for (int i = 0; i < subsets.size(); i++){
      nums2.clear();
      sum = 0;
      for (int j = 0; j < subsets[i].size(); j++){
        sum += nums[subsets[i][j]];
        nums2.push_back(nums[subsets[i][j]]);
      }
      if (sum == t){
        flag = 0;
        sort(nums2.begin(), nums2.end(), greater<int>() );
        set.insert(nums2);
    }
  }

  if (flag)
    cout <<  "NONE" << endl;
  else{
    for (auto vec : set){
      for (int i = 0; i < vec.size(); i++){
        cout << vec[i];
        if (i != vec.size()-1)
          cout << "+";
      }
      cout << endl;
    }
  }
  cin >> t >> n;
}
}
