#include<bits/stdc++.h>
using namespace std;

vector<int> printLIS(vector<int>& arr){
  int res = INT_MIN;
  int n = arr.size();
  vector<int>lis(n, 1);
  for(int i=0; i<n; ++i){
    for(int j=0; j<i; ++j){
      if(arr[j] < arr[i]) lis[i] = max(lis[i], lis[j]+1);
    }
    res = max(res, lis[i]);
  }
  vector<int>ans;
  for(int i=n-1; i>=0; --i){
    if(lis[i] == res){
      ans.push_back(arr[i]);
      res--;
    }
  }
  reverse(ans.begin(), ans.end());
  return ans;
}


int main(){
  vector<int>arr = {1,3,5,4,7};
  vector<int> lis = printLIS(arr);
  for (int num : lis) {
    cout << num << " ";
  }
  cout << endl;
  return 0;
  
}