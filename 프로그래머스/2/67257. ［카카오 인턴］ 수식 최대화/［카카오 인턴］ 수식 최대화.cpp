#include <string> 
#include <vector>
#include <algorithm>
#include <list>

using namespace std;

long long solution(string expression) {
    long long answer = 0;
    //string 배열로 받아야겠다.
    string temp1 = "";
    vector<string> save;
    vector<string> copy_save;
    long long temp2;
    for (int i = 0; i < expression.size(); i++) {
        if (expression[i] == '+' || expression[i] == '-' || expression[i] == '*') {
            save.push_back(temp1);
            temp1 = "";
            if (expression[i] == '+')
                save.push_back("+");
            else if (expression[i] == '-')
                save.push_back("-");
            else if (expression[i] == '*')
                save.push_back("*");

        }
        else {
            temp1 += expression[i];
        }
    }

    save.push_back(temp1);
    

    copy_save = save;

    //6가지를 다 해본다.

    // 1.+ / - -> *
    for (int i = 0; i < save.size(); i++) {
        if (save[i] == "+") {
            long long temp = stoll(save[i - 1]) + stoll(save[i + 1]);
            save[i - 1] = to_string(temp);
            save.erase(save.begin() + i + 1);
            save.erase(save.begin() + i);
            i -= 1;
        }
    }
    for (int i = 0; i < save.size(); i++) {
        if (save[i] == "-") {
            long long temp = stoll(save[i - 1]) - stoll(save[i + 1]);
            save[i - 1] = to_string(temp);
            save.erase(save.begin() + i + 1);
            save.erase(save.begin() + i);
            i -= 1;
        }
    }

    for (int i = 0; i < save.size(); i++) {
        if (save[i] == "*") {
            long long temp = stoll(save[i - 1]) * stoll(save[i + 1]);
            save[i - 1] = to_string(temp);
            save.erase(save.begin() + i + 1);
            save.erase(save.begin() + i);
            i -= 1;
        }
    }

    temp2 = stoll(save[0]);

    if (temp2 < 0)
        temp2 = -temp2;

    answer = max(temp2, answer);

    save = copy_save;

    // 2.+ / * -> -
    for (int i = 0; i < save.size(); i++) {
        if (save[i] == "+") {
            long long temp = stoll(save[i - 1]) + stoll(save[i + 1]);
            save[i - 1] = to_string(temp);
            save.erase(save.begin() + i + 1);
            save.erase(save.begin() + i);
            i -= 1;
        }
    }
    for (int i = 0; i < save.size(); i++) {
        if (save[i] == "*") {
            long long temp = stoll(save[i - 1]) * stoll(save[i + 1]);
            save[i - 1] = to_string(temp);
            save.erase(save.begin() + i + 1);
            save.erase(save.begin() + i);
            i -= 1;
        }
    }

    for (int i = 0; i < save.size(); i++) {
        if (save[i] == "-") {
            long long temp = stoll(save[i - 1]) - stoll(save[i + 1]);
            save[i - 1] = to_string(temp);
            save.erase(save.begin() + i + 1);
            save.erase(save.begin() + i);
            i -= 1;
        }
    }

    temp2 = stoll(save[0]);

    if (temp2 < 0)
        temp2 = -temp2;

    answer = max(temp2, answer);

    save = copy_save;

    // 3.* / * -> + -> -

    for (int i = 0; i < save.size(); i++) {
        if (save[i] == "*") {
            long long temp = stoll(save[i - 1]) * stoll(save[i + 1]);
            save[i - 1] = to_string(temp);
            save.erase(save.begin() + i + 1);
            save.erase(save.begin() + i);
            i -= 1;
        }
    }
    for (int i = 0; i < save.size(); i++) {
        if (save[i] == "+") {
            long long temp = stoll(save[i - 1]) + stoll(save[i + 1]);
            save[i - 1] = to_string(temp);
            save.erase(save.begin() + i + 1);
            save.erase(save.begin() + i);
            i -= 1;
        }
    }

    for (int i = 0; i < save.size(); i++) {
        if (save[i] == "-") {
            long long temp = stoll(save[i - 1]) - stoll(save[i + 1]);
            save[i - 1] = to_string(temp);
            save.erase(save.begin() + i + 1);
            save.erase(save.begin() + i);
            i -= 1;
        }
    }

    temp2 = stoll(save[0]);

    if (temp2 < 0)
        temp2 = -temp2;

    answer = max(temp2, answer);

    save = copy_save;

    // 4.* / * -> - -> +
    for (int i = 0; i < save.size(); i++) {
        if (save[i] == "*") {
            long long temp = stoll(save[i - 1]) * stoll(save[i + 1]);
            save[i - 1] = to_string(temp);
            save.erase(save.begin() + i + 1);
            save.erase(save.begin() + i);
            i -= 1;
        }
    }
    for (int i = 0; i < save.size(); i++) {
        if (save[i] == "-") {
            long long temp = stoll(save[i - 1]) - stoll(save[i + 1]);
            save[i - 1] = to_string(temp);
            save.erase(save.begin() + i + 1);
            save.erase(save.begin() + i);
            i -= 1;
        }
    }

    for (int i = 0; i < save.size(); i++) {
        if (save[i] == "+") {
            long long temp = stoll(save[i - 1]) + stoll(save[i + 1]);
            save[i - 1] = to_string(temp);
            save.erase(save.begin() + i + 1);
            save.erase(save.begin() + i);
            i -= 1;
        }
    }

    temp2 = stoll(save[0]);

    if (temp2 < 0)
        temp2 = -temp2;

    answer = max(temp2, answer);

    save = copy_save;

    // 5.- / * -> +
    for (int i = 0; i < save.size(); i++) {
        if (save[i] == "-") {
            long long temp = stoll(save[i - 1]) - stoll(save[i + 1]);
            save[i - 1] = to_string(temp);
            save.erase(save.begin() + i + 1);
            save.erase(save.begin() + i);
            i -= 1;
        }
    }
    for (int i = 0; i < save.size(); i++) {
        if (save[i] == "*") {
            long long temp = stoll(save[i - 1]) * stoll(save[i + 1]);
            save[i - 1] = to_string(temp);
            save.erase(save.begin() + i + 1);
            save.erase(save.begin() + i);
            i -= 1;
        }
    }

    for (int i = 0; i < save.size(); i++) {
        if (save[i] == "+") {
            long long temp = stoll(save[i - 1]) + stoll(save[i + 1]);
            save[i - 1] = to_string(temp);
            save.erase(save.begin() + i + 1);
            save.erase(save.begin() + i);
            i -= 1;
        }
    }

    temp2 = stoll(save[0]);

    if (temp2 < 0)
        temp2 = -temp2;

    answer = max(temp2, answer);

    save = copy_save;

    // 6.- / + -> *
    for (int i = 0; i < save.size(); i++) {
        if (save[i] == "-") {
            long long temp = stoll(save[i - 1]) - stoll(save[i + 1]);
            save[i - 1] = to_string(temp);
            save.erase(save.begin() + i + 1);
            save.erase(save.begin() + i);
            i -= 1;
        }
    }
    for (int i = 0; i < save.size(); i++) {
        if (save[i] == "+") {
            long long temp = stoll(save[i - 1]) + stoll(save[i + 1]);
            save[i - 1] = to_string(temp);
            save.erase(save.begin() + i + 1);
            save.erase(save.begin() + i);
            i -= 1;
        }
    }

    for (int i = 0; i < save.size(); i++) {
        if (save[i] == "*") {
            long long temp = stoll(save[i - 1]) * stoll(save[i + 1]);
            save[i - 1] = to_string(temp);
            save.erase(save.begin() + i + 1);
            save.erase(save.begin() + i);
            i -= 1;
        }
    }

    temp2 = stoll(save[0]);

    if (temp2 < 0)
        temp2 = -temp2;


    answer = max(temp2, answer);

    return answer;
}