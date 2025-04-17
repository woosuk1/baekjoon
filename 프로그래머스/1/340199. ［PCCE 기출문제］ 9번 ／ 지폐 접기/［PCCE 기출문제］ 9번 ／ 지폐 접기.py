def solution(wallet, bill):
    answer = 0
    
    min_bill = min(bill)
    min_wallet = min(wallet)
    
    while min(bill) > min(wallet) or max(bill) > max(wallet):
        if(bill[0] > bill[1]):
            bill[0] //= 2
        else:
            bill[1] //= 2
        answer+=1
    
    return answer