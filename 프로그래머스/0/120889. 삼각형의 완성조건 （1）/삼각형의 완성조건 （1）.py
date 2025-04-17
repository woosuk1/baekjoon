def solution(sides):
    answer = 2
    
    mx = max(sides)
    temp = 0
    
    for i in sides:
        temp += i
    
    
    if(mx < temp- mx): answer = 1
    
    return answer