0409677C: 23fc00000001040c9778     move.l  #1,(_client_running).l
04096786: 2079040c96d4             movea.l (_client_pcb).l,a0
0409678C: 4e7b8800                 movec   a0,usp
04096790: 4cf9ffff040c96d8         movem.l (dword_40C96D8).l,d0-d7/a0-a7
04096798: 4e73                     rte
