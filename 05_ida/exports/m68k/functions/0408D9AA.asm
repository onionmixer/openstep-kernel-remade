0408D9AA: 4856                     pea     (a6)
0408D9AC: 2c4f                     movea.l sp,a6
0408D9AE: 206e0008                 movea.l 8(a6),a0
0408D9B2: 40c0                     move    sr,d0
0408D9B4: 46fc2300                 move    #$2300,sr
0408D9B8: 48c0                     ext.l   d0
0408D9BA: 20b9040b244a             move.l  (dword_40B244A).l,(a0)
0408D9C0: 23c8040b244a             move.l  a0,(dword_40B244A).l
0408D9C6: 52b9040b2452             addq.l  #1,(dword_40B2452).l
0408D9CC: 40c1                     move    sr,d1
0408D9CE: 46c0                     move    d0,sr
0408D9D0: 4e5e                     unlk    a6
0408D9D2: 4e75                     rts
