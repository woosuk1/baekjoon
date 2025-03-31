#include <string>
#include <vector>
#include <algorithm>

using namespace std;


int solution(int m, int n, vector<string> board) {
    int answer = 0;
    
    while(true){
        vector<vector<int>> arr(board.size(), vector<int>(board[0].size()));
        vector<string> cpy_board(board.size(), string(board[0].size(), '0'));
        
        int cnt = 0;
        // 2*2 블록이 있는지 스캐닝 한후에 좌표 저장
        for(int i=0; i<board.size()-1; i++){
            for(int j=0; j<board[i].size()-1; j++){
                if(board[i][j] != '0' && board[i][j] == board[i+1][j] && board[i+1][j] == board[i][j+1] && board[i][j+1] == board[i+1][j+1]){
                    arr[i][j] = 1;
                    arr[i+1][j] = 1;
                    arr[i][j+1] = 1;
                    arr[i+1][j+1] = 1;
                    cnt++;
                }                                        
            }
        }    
        // 스캐닝 종료 시 
        // cnt == 0 일 시 종료
        if(!cnt)
            break;
        // 1. 저장한 좌표 삭제
        for(int i=0; i<board.size(); i++){
            for(int j=0; j<board[i].size(); j++){
                if(arr[i][j])
                    board[i][j] = '0';
            }
        }    
        // 2. 위에 있던 좌표들 아래로 밀착(열 끝에서부터 시작해서 0이 아닌 값들만 push(정갈하게 쌓이죠?))
        for(int i=0; i<n; i++){
            int index = m-1;
            for(int j=m-1; j>=0; j--){
                if(board[j][i] != '0'){
                    cpy_board[index][i] = board[j][i];
                    index--;
                }
            }
        }
        
        copy(cpy_board.begin(), cpy_board.end(), board.begin());
    }    
        
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(board[i][j] == '0')
                answer++;
        }
    }
    
    return answer;
}