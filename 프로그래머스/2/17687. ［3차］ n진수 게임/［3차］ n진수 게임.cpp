#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

string solution(int n, int t, int m, int p) {
    string answer = "";
    
    // 주어지는 진법에 맞춰서.... 구현하라
    
    // 진법에 맞춰서 숫자리스트(m*t개)를 string으로 덧붙인다.
    // 튜브의 순서대로 i*m개 해서 구하면 됨
    string realTemp = "01";
    
    int real = 2;
    
    while(realTemp.size() <= m*t){
        int i = real;
        string temp = "";
        while(i/n >= 0){
            if(i%n < 10){
                temp += to_string(i % n);
            }else{
                if(i%n == 10){
                    temp += 'A';
                }else if(i%n == 11){
                    temp += 'B';
                }else if(i%n == 12){
                    temp += 'C';
                }else if(i%n == 13){
                    temp += 'D';
                }else if(i%n == 14){
                    temp += 'E';
                }else if(i%n == 15){
                    temp += 'F';
                }
            }           
            if(i/n == 1){
                temp += '1';
                break;
            }else if(i/n == 0){
                break;
            }
            i /= n;

        }
        reverse(temp.begin(), temp.end());
        realTemp += temp;
        real++;
    }
    
    int j = p-1;
    
    if(p == 1){
        answer += '0';
        j = m;
        t--;
    }
    
    while(t--){
        answer += realTemp[j];
        j+=m;
    }
    
    return answer;
}