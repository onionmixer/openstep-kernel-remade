04080388: 4e56ffe0                 link    a6,#-$20
0408038C: 2f0a                     move.l  a2,-(sp)
0408038E: 45eeffe0                 lea     var_20(a6),a2
04080392: 2f0a                     move.l  a2,-(sp)
04080394: 61ff0001144c             bsr.l   _nvram_check
0408039A: 3039040b508a             move.w  (dword_40B5088+2).l,d0
040803A0: 0240003f                 andi.w  #$3F,d0 ; '?'
040803A4: efee0186ffe0             bfins   d0,var_20(a6){6:6}
040803AA: 3039040b508e             move.w  (dword_40B508C+2).l,d0
040803B0: 0240003f                 andi.w  #$3F,d0 ; '?'
040803B4: efee0186ffe2             bfins   d0,var_1E(a6){6:6}
040803BA: 2239040b5084             move.l  (dword_40B5084).l,d1
040803C0: 102effe3                 move.b  var_1D(a6),d0
040803C4: efc01741                 bfins   d1,d0{29:1}
040803C8: 1d40ffe3                 move.b  d0,var_1D(a6)
040803CC: 2239040b5080             move.l  (dword_40B5080).l,d1
040803D2: efc01701                 bfins   d1,d0{28:1}
040803D6: 1d40ffe3                 move.b  d0,var_1D(a6)
040803DA: 2f0a                     move.l  a2,-(sp)
040803DC: 61ff0001146c             bsr.l   _nvram_set
040803E2: 246effdc                 movea.l var_24(a6),a2
040803E6: 4e5e                     unlk    a6
040803E8: 4e75                     rts
