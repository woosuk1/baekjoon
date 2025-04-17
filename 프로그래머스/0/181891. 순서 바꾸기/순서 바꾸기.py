def solution(num_list, n):
    answer = []
    
    temp = []
    for i in range(n):
        temp.append(num_list[i])
    
    for i in range(n, len(num_list)):
        answer.append(num_list[i])
        
    answer += temp
        
    
    return answer