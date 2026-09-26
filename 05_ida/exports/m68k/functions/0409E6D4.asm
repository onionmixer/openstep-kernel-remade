0409E6D4: 0409e720                 subi.b  #$20,a1 ; ' '
0409E6D8: 0409e718                 subi.b  #$18,a1
0409E6DC: 0409e6fe                 subi.b  #$FE,a1
0409E6E0: 0409e6e4                 subi.b  #$E4,a1
0409E6E4: 4841                     swap    d1
0409E6E6: 4a280002                 tst.b   2(a0)
0409E6EA: 6bff000001a6             bmi.l   loc_409E892
0409E6F0: 70ff                     moveq   #$FFFFFFFF,d0
0409E6F2: 43f90409e7be             lea     (sub_409E7BE).l,a1
0409E6F8: 22711400                 movea.l (a1,d1.w*4),a1
0409E6FC: 4ed1                     jmp     (a1)
0409E892: 43f90409e882             lea     (loc_409E882).l,a1
0409E898: 22711400                 movea.l (a1,d1.w*4),a1
0409E89C: 4ed1                     jmp     (a1)
