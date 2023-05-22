#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <map>
#include <iomanip>

int main(){
   int N;
   std::cin >> N;
   std::vector<double> inputs;
   std::map<double, int> inputs_2;

   int size = N;
   double input;
   while(N--){
       std::cin >> input;
       inputs.push_back(input);
       inputs_2[input]++;
   }

   std::cout << std::fixed << std::setprecision(0);
   double sum = std::accumulate(inputs.begin(), inputs.end(), 0);
   double avg = sum / size;
   if(avg > -1 && 0 > avg)
       std::cout << 0 << "\n";
   else
       std::cout << avg << "\n";

   std::sort(inputs.begin(), inputs.end());
   std::cout << inputs[size/2] << "\n";

   int max_cnt = 0;
   for(std::pair<double,int> p : inputs_2){
       if(p.second > max_cnt)
           max_cnt = p.second;
   }

   std::vector<double> max_nums;
   for(std::pair<int,int> p : inputs_2){
       if(p.second == max_cnt) {
           max_nums.push_back(p.first);
       }
   }

   std::sort(max_nums.begin(), max_nums.end());
   if(max_nums.size() > 1)
       std::cout << max_nums[1] << "\n";
   else if(max_nums.size() == 1)
       std::cout << max_nums[0] << "\n";

   std::cout << *(inputs.end()-1) - *inputs.begin();
}