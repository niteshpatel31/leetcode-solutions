#include <fmt/format.h>
#include <queue>
#include <unordered_map>

int main(){
  std::priority_queue<std::pair<int, int>> pq;
  std::unordered_map<int, int> mp;
  std::vector<int> num = {1,2,1,3,4,5,1,2,3,4,5,1,1,1,1,2,2,2,3,3,3}, ans;
  ans.reserve(3);
  mp.reserve(num.size());
  for(auto e : num)
      mp[e]++;
  num.erase(num.begin(), num.end());
  for(auto &it : mp)
    pq.push({it.second,it.first});
  for(int i =0 ; i< 3 ;i++){
    ans.emplace_back(pq.top().second);
    pq.pop();
  }
  for(auto v : ans)
    fmt::println("{}", v);
  return 0;
}
