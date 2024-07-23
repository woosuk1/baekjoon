class Solution {
    public int solution(String num_str) {
        int answer = 0;
        int save;
        
        for(int i =0; i< num_str.length(); i++){
            save = Integer.parseInt(String.valueOf(num_str.charAt(i)));
            answer += save;
        }
        
        return answer;
    }
}