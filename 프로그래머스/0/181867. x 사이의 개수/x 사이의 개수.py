def solution(myString):
    answer = []

    myString = myString.split("x")
    
    for i in myString:
        print(i)
        answer.append(len(i))
    
    return answer