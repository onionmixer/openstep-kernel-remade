0409C646: 42aeffac                 clr.l   -$54(a6)
0409C64A: 08a800070000             bclr    #7,0(a0)
0409C650: 56e80002                 sne     2(a0)
0409C654: 0c2e002c000b             cmpi.b  #$2C,$B(a6) ; ','
0409C65A: 66ff00000010             bne.l   loc_409C66C
0409C660: 61ff00000090             bsr.l   sub_409C6F2
0409C666: 60ff00000022             bra.l   loc_409C68A
0409C66C: 082e0005ff1c             btst    #5,-$E4(a6)
0409C672: 66ff00000010             bne.l   loc_409C684
0409C678: 61ff00000056             bsr.l   sub_409C6D0
0409C67E: 60ff0000000a             bra.l   loc_409C68A
0409C684: 61ff0000002a             bsr.l   sub_409C6B0
0409C68A: 0c683fff0000             cmpi.w  #$3FFF,0(a0)
0409C690: 6eff0000000a             bgt.l   loc_409C69C
0409C696: 08ee0004ffac             bset    #4,-$54(a6)
0409C69C: ece800080002             bfclr   2(a0){0:8}
0409C6A2: 67ff0000000a             beq.l   locret_409C6AE
0409C6A8: 08e800070000             bset    #7,0(a0)
0409C6AE: 4e75                     rts
