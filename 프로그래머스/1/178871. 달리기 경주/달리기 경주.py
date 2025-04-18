def solution(players, callings):
    answer = []
    
    players_position = {player : idx for idx, player in enumerate(players)}
    
    for i in callings:
        idx = players_position[i]
        
        players[idx], players[idx-1] = players[idx-1], players[idx]
        
        players_position[players[idx]] = idx
        players_position[players[idx-1]] = idx-1
    
    return players