#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(vector<string> survey, vector<int> choices) {
    string answer = "";
    
    // 1. 길이가 4인 2개의 쌍을 가진 배열을 만들어주기
    // 사전순으로 1. R,T | 2. C,F | 3. J,M | 4. A,N
    vector<pair<int,int>> arr(4);
    
    // 2. if(rt, tr) = arr[0], if(fc,cf), if(mj,jm), if(an,na) 중 하나이며 배열 인덱스 지정
    // if(rt) else (tr) 일때로 분기를 나눠준다. 
    // 1,2,3 일 시 left value++ | 4일시 continue | 5,6,7일 시 right value++
    for(int i=0; i<survey.size(); i++){
        if(survey[i] == "RT" || survey[i] == "TR"){
            // arr[0]
            if(survey[i] == "RT"){
                // left value 지정 가능
                if(choices[i] <= 3){
                    if(choices[i] == 1){
                        arr[0].first+=3;                        
                    }else if(choices[i] == 2){
                        arr[0].first+=2;
                    }else if(choices[i] == 3){
                        arr[0].first+=1;
                    }
                }
                // right value 지정 가능
                else if(choices[i] >= 5){
                    if(choices[i] == 5){
                        arr[0].second+=1;                        
                    }else if(choices[i] == 6){
                        arr[0].second+=2;
                    }else if(choices[i] == 7){
                        arr[0].second+=3;
                    }
                }
            }else if(survey[i] == "TR"){
                                // left value 지정 가능
                if(choices[i] <= 3){
                    if(choices[i] == 1){
                        arr[0].second+=3;                        
                    }else if(choices[i] == 2){
                        arr[0].second+=2;
                    }else if(choices[i] == 3){
                        arr[0].second+=1;
                    }
                }
                // right value 지정 가능
                else if(choices[i] >= 5){
                    if(choices[i] == 5){
                        arr[0].first+=1;                        
                    }else if(choices[i] == 6){
                        arr[0].first+=2;
                    }else if(choices[i] == 7){
                        arr[0].first+=3;
                    }
                }
            }
        }else if(survey[i] == "CF" || survey[i] == "FC"){
                        // arr[1]
            if(survey[i] == "CF"){
                // left value 지정 가능
                if(choices[i] <= 3){
                    if(choices[i] == 1){
                        arr[1].first+=3;                        
                    }else if(choices[i] == 2){
                        arr[1].first+=2;
                    }else if(choices[i] == 3){
                        arr[1].first+=1;
                    }
                }
                // right value 지정 가능
                else if(choices[i] >= 5){
                    if(choices[i] == 5){
                        arr[1].second+=1;                        
                    }else if(choices[i] == 6){
                        arr[1].second+=2;
                    }else if(choices[i] == 7){
                        arr[1].second+=3;
                    }
                }
            }else if(survey[i] == "FC"){
                                // left value 지정 가능
                if(choices[i] <= 3){
                    if(choices[i] == 1){
                        arr[1].second+=3;                        
                    }else if(choices[i] == 2){
                        arr[1].second+=2;
                    }else if(choices[i] == 3){
                        arr[1].second+=1;
                    }
                }
                // right value 지정 가능
                else if(choices[i] >= 5){
                    if(choices[i] == 5){
                        arr[1].first+=1;                        
                    }else if(choices[i] == 6){
                        arr[1].first+=2;
                    }else if(choices[i] == 7){
                        arr[1].first+=3;
                    }
                }
            }
        }else if(survey[i] == "MJ" || survey[i] == "JM"){
            // arr[2]
            if(survey[i] == "JM"){
                // left value 지정 가능
                if(choices[i] <= 3){
                    if(choices[i] == 1){
                        arr[2].first+=3;                        
                    }else if(choices[i] == 2){
                        arr[2].first+=2;
                    }else if(choices[i] == 3){
                        arr[2].first+=1;
                    }
                }
                // right value 지정 가능
                else if(choices[i] >= 5){
                    if(choices[i] == 5){
                        arr[2].second+=1;                        
                    }else if(choices[i] == 6){
                        arr[2].second+=2;
                    }else if(choices[i] == 7){
                        arr[2].second+=3;
                    }
                }
            }else if(survey[i] == "MJ"){
                                // left value 지정 가능
                if(choices[i] <= 3){
                    if(choices[i] == 1){
                        arr[2].second+=3;                        
                    }else if(choices[i] == 2){
                        arr[2].second+=2;
                    }else if(choices[i] == 3){
                        arr[2].second+=1;
                    }
                }
                // right value 지정 가능
                else if(choices[i] >= 5){
                    if(choices[i] == 5){
                        arr[2].first+=1;                        
                    }else if(choices[i] == 6){
                        arr[2].first+=2;
                    }else if(choices[i] == 7){
                        arr[2].first+=3;
                    }
                }
            }
        }else if(survey[i] == "AN" || survey[i] == "NA"){
            // arr[3]
            if(survey[i] == "AN"){
                // left value 지정 가능
                if(choices[i] <= 3){
                    if(choices[i] == 1){
                        arr[3].first+=3;                        
                    }else if(choices[i] == 2){
                        arr[3].first+=2;
                    }else if(choices[i] == 3){
                        arr[3].first+=1;
                    }
                }
                // right value 지정 가능
                else if(choices[i] >= 5){
                    if(choices[i] == 5){
                        arr[3].second+=1;                        
                    }else if(choices[i] == 6){
                        arr[3].second+=2;
                    }else if(choices[i] == 7){
                        arr[3].second+=3;
                    }
                }
            }else if(survey[i] == "NA"){
                                // left value 지정 가능
                if(choices[i] <= 3){
                    if(choices[i] == 1){
                        arr[3].second+=3;                        
                    }else if(choices[i] == 2){
                        arr[3].second+=2;
                    }else if(choices[i] == 3){
                        arr[3].second+=1;
                    }
                }
                // right value 지정 가능
                else if(choices[i] >= 5){
                    if(choices[i] == 5){
                        arr[3].first+=1;                        
                    }else if(choices[i] == 6){
                        arr[3].first+=2;
                    }else if(choices[i] == 7){
                        arr[3].first+=3;
                    }
                }
            }
        }
    }
    
    // 3. 4가지 지표를 돌면서 더 큰 경우를 answer+= ' '해준다
    for(int i=0; i<4; i++){
        if(arr[i].first >= arr[i].second){
            if(i == 0){
                answer += "R";
            }else if(i==1){
                answer += "C";
            }else if(i==2){
                answer += "J";
            }else if(i==3){
                answer += "A";
            }
        }else{
            if(i == 0){
                answer += "T";
            }else if(i==1){
                answer += "F";
            }else if(i==2){
                answer += "M";
            }else if(i==3){
                answer += "N";
            }   
        }
    }
    
    return answer;
}