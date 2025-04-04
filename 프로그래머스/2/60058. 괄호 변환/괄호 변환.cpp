#include <string>
#include <vector>
#include <stack>

using namespace std;

bool is_correct(string a){
    stack<char> stk;
    
    for(int i=0; i<a.size(); i++){
        if(stk.empty() && a[i] == ')')
            return false;   
        if(a[i]== '(')
            stk.push(a[i]);
        else if(stk.top() == '(' && a[i] == ')')
            stk.pop();
    }
    
    return true;
}

string change(string a){
    string change_a = "";
    
    
    for(int i=1; i<a.size() - 1; i++){
        if(a[i] == '('){
            change_a += ")";
        }
        else{
            change_a += "(";
        }
    }
    
    return change_a;
}

string get_balance(string p) {
    string u = "";
    string v = "";
    stack<char> s; // 균형잡힌 괄호 문자열 확인용 스택

    if (p == "") {
        return p;
    }

    // 받은 문자열이 올바른 괄호 문자열이면 바로 반환해준다.
    if (is_correct(p)) {
        return p;
    }

    // 문자열 u(= 균형잡힌 괄호 문자열)와 v로 나누기
    for (int i = 0; i < p.length(); i++) { 
        u.push_back(p[i]);

        if (i == 0) { // 첫 실행에는 괄호를 스택에 저장
            s.push(p[i]);
        }
        else if (s.top() == ')' && p[i] == '(') {
            s.pop();
        }
        else if (s.top() == '(' && p[i] == ')') {
            s.pop();
        }
        else {
            s.push(p[i]);
        }

        // 위의 과정을 모두 거쳤을 때 스택이 공백이면 균형잡힌 괄호 문자열이다.
        if (s.empty()) {
            for (int j = i + 1; j < p.length(); j++) {
                v.push_back(p[j]);
            }

            if (is_correct(u)) {
                return u + get_balance(v); // 올바른 괄호 문자열이면 u를 그대로 두고 v를 실행한다.
            }
            else {
                return "(" + get_balance(v) + ")" + change(u);
            }
        }
    }
}

string solution(string p) {
    return get_balance(p);
}