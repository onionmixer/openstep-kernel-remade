0404D56E: 4856                     pea     (a6)
0404D570: 2c4f                     movea.l sp,a6
0404D572: 206e0008                 movea.l 8(a6),a0
0404D576: 2f10                     move.l  (a0),-(sp)
0404D578: 61ff00000038             bsr.l   _vmp_put
0404D57E: 4e5e                     unlk    a6
0404D580: 4e75                     rts
