0409BCC4: 2d6eff34ff8c             move.l  -$CC(a6),-$74(a6)
0409BCCA: 2d6eff38ff90             move.l  -$C8(a6),-$70(a6)
0409BCD0: 2d6eff3cff94             move.l  -$C4(a6),-$6C(a6)
0409BCD6: 08ee0006ff90             bset    #6,-$70(a6)
0409BCDC: f22ed040ff8c             fmovem.x -$74(a6),fp1
0409BCE2: 61ff0000746a             bsr.l   sto_cos
0409BCE8: 60ff00000f6e             bra.l   src_nan
