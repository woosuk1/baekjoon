#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cctype>
#include <cmath>
using namespace std;

int is_prime(long long a){
    if(a<2) return 0;
    for(int i=2; i<=(int)sqrt(a); i++){
        if(a % i == 0){
            return 0;
        }
    }
    return 1;
}

int solution(int n, int k) {
    int answer = 0;
    
    string temp = "";
    int save = n;
    while(true){
        if(n==1){
            temp += to_string(n);
            break;
        }else if(n==0){
            break;
        }
        
        temp += to_string(n % k);
        n /= k;
    }
    
    reverse(temp.begin(), temp.end());
    
    vector<string> temptemp;
    string maxString = "";
    //0을 만나면 0 다음 인덱스부터 
    // size()는 종료
    int index = 0;
    string temptemptemp = "";
    while(temp.size() >= index){
        if(temp[index] == '0' || index == temp.size()){
            if(temptemptemp.size() !=0)
                temptemp.push_back(temptemptemp);
            index++;
            if(temptemptemp > maxString){
                maxString = temptemptemp;
            }
            temptemptemp = "";
            continue;
            
        }        

        temptemptemp += temp[index];
        index++;
    }
    for(int i=0; i<temptemp.size(); i++){
        if(is_prime(stol(temptemp[i])))
            answer++;
        // if(!arr[stol(temptemp[i])])
        //         answer++;
    }
    
    return answer;
}