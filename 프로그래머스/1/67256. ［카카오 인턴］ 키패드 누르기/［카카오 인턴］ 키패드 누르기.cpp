#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(vector<int> numbers, string hand) {
    string answer = "";
    
    pair<int, int> cur_left = {0,3};
    pair<int, int> cur_right = {2,3};

    for(int i=0; i<numbers.size(); i++){
        if(numbers[i] == 1 || numbers[i] == 4 || numbers[i] == 7){
            if(numbers[i] == 1){
                cur_left = {0,0};
            }
            else if(numbers[i] == 4){
                cur_left = {0,1};
            }
            else if(numbers[i] == 7 ){
                cur_left = {0,2};
            }
            answer += "L";
        }
        else if(numbers[i] == 3 || numbers[i] == 6 || numbers[i] == 9){
            if(numbers[i] == 3){
                cur_right = {2,0};
            }
            else if(numbers[i] == 6){
                cur_right = {2,1};
            }
            else if(numbers[i] == 9){
                cur_right = {2,2};
            }
            answer += "R";
        }
        else{
            pair<int, int> new_index;
            if(numbers[i] == 2){
                new_index = {1,0};
            } else if(numbers[i] == 5){
                new_index = {1,1};
            } else if(numbers[i] == 8){
                new_index = {1,2};
            } else if(numbers[i] == 0){
                new_index = {1,3};
            }
            
            int tempLeft = 0, tempRight = 0;
            
            tempLeft += (abs(new_index.first - cur_left.first) + abs(new_index.second - cur_left.second));
            
            tempRight += (abs(new_index.first - cur_right.first) + abs(new_index.second - cur_right.second));
            
            // 거리가 같을 때
            if(tempLeft == tempRight){
                if(hand == "left"){
                    cur_left = new_index;
                    answer += "L";
                }
                else{
                    cur_right = new_index;
                    answer += "R";
                }
            }
            else if(tempLeft > tempRight){
                cur_right = new_index;
                answer += "R";
            }else{
                cur_left = new_index;
                answer += "L";
            }
        }
    }
    
    return answer;
}