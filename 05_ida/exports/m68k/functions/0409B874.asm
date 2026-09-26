0409B874: 082800070000             btst    #7,0(a0)
0409B87A: 66ff00000010             bne.l   loc_409B88C
0409B880: 61ff000004d0             bsr.l   ld_pzero
0409B886: 60ff00001320             bra.l   t_inx2
0409B88C: 61ff000004d6             bsr.l   ld_mzero
0409B892: 60ff00001314             bra.l   t_inx2
