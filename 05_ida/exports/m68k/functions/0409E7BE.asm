0409E7BE: 0409e804                 subi.b  #4,a1
0409E7C2: 0409e7ce                 subi.b  #$CE,a1
0409E7C6: 0409e83c                 subi.b  #$3C,a1 ; '<'
0409E7CA: 0409e83c                 subi.b  #$3C,a1 ; '<'
0409E7CE: 06a8000001000004         addi.l  #$100,4(a0)
0409E7D6: 64ff00000010             bcc.l   loc_409E7E8
0409E7DC: e4e80004                 roxr    4(a0)
0409E7E0: e4e80006                 roxr    6(a0)
0409E7E4: 52680000                 addq.w  #1,0(a0)
0409E7E8: 4a80                     tst.l   d0
0409E7EA: 66ff0000000a             bne.l   loc_409E7F6
0409E7F0: 0268fe000006             andi.w  #$FE00,6(a0)
0409E7F6: 02a8ffffff000004         andi.l  #$FFFFFF00,4(a0)
0409E7FE: 42a80008                 clr.l   8(a0)
0409E802: 4e75                     rts
