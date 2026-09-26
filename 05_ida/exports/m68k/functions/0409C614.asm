0409C614: 302eff1c                 move.w  -$E4(a6),d0
0409C618: 08000005                 btst    #5,d0
0409C61C: 67ff00000022             beq.l   loc_409C640
0409C622: 08000004                 btst    #4,d0
0409C626: 67ff00000012             beq.l   loc_409C63A
0409C62C: 0240007f                 andi.w  #$7F,d0
0409C630: 0c400038                 cmpi.w  #$38,d0 ; '8'
0409C634: 66ff0000000a             bne.l   loc_409C640
0409C63A: 50eeffb8                 st      -$48(a6)
0409C63E: 4e75                     rts
0409C640: 422effb8                 clr.b   -$48(a6)
0409C644: 4e75                     rts
