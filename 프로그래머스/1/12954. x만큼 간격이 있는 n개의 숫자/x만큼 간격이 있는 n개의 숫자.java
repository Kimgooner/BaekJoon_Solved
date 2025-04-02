class Solution {
    public long[] solution(int x, int n) {
        long[] answer = new long[n];
        
        int idx = 0;
        long s = x;
        while(idx != n){
            answer[idx] = s;
            
            s += x;
            idx++;
        }
        
        
        return answer;
    }
}