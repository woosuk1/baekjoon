def solution(data, ext, val_ext, sort_by):
    answer = []
    
    idx = 0
    if(ext == "date"):
        idx = 1
    elif(ext == "maximum"):
        idx = 2
    elif(ext == "remain"):
        idx = 3
    
    sort_idx = 0
    if(sort_by == "date"):
        sort_idx = 1
    elif(sort_by == "maximum"):
        sort_idx = 2
    elif(sort_by == "remain"):
        sort_idx = 3
    
    for i in data:
        if(i[idx] <val_ext):
            answer.append(i)
    
    print(answer)
    
    answer.sort(key=lambda x:x[sort_idx])
            
    return answer