def solution(arr1, arr2):
    answer = 0
    
    if(len(arr1) > len(arr2)):
        answer = 1
    elif(len(arr2) > len(arr1)):
        answer = -1
    else:
        one = 0
        two = 0
        for i in range(0, len(arr1)):
            one += arr1[i]
            two += arr2[i]
        
        if(one == two):
            answer = 0
        elif(one> two):
            answer = 1
        else:
            answer = -1
    
    
    
    return answer