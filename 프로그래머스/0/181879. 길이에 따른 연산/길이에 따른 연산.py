def solution(num_list):
    answer = 1
    
    if(len(num_list) > 10):
        answer = 0
        for i in num_list:
            answer += i
    else:
        for i in num_list:
            answer *= i
    
    return answer