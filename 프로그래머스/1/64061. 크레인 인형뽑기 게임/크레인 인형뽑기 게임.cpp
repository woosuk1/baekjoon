#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    
    int n = board.size();    
    
    vector<vector<int>> convert_board(n);
    vector<int> basket;

    // 각 가로열에 걸맞게 convert 해줌
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(board[j][i] == 0)
                continue;
            convert_board[i].push_back(board[j][i]);
        }
    }
    // moves value는 1~n까지니까 -1해서 확인해주기
    
    // 각 열의 사이즈에 따라서 convert_board 삭제해주기
    // basket의 사이즈가 0이 아닐 때, 
    // size()-1의 값과 일치하면 basket.size() -1 의 값 삭제 후 answer++
    for(int i=0; i<moves.size(); i++){
        int temp = moves[i] - 1;
        bool flag = false;
        
        // 인형이 없을 경우
        if(convert_board[temp].size() == 0){
            continue;
        }
        
        // basket 사이즈가 있을때만 검증
        if(basket.size()){
            if(convert_board[temp][0] == basket[basket.size() -1]){
                basket.erase(basket.end()-1);
                answer+=2;
                flag = true;
            }
        }
        
        // 지워지지 않았을 때 basket에 push 해주기
        if(!flag)
            basket.push_back(convert_board[temp][0]);
        // 공통으로 지워야 하니까...
        convert_board[temp].erase(convert_board[temp].begin());
    }
    
    
    return answer;
}