04085920: 4856                     pea     (a6)
04085922: 2c4f                     movea.l sp,a6
04085924: 4ab9040b2264             tst.l   (dword_40B2264).l
0408592A: 6614                     bne.s   loc_4085940
0408592C: 4879040abc74             pea     (aSounddspAudioD).l; "SoundDSP: audio driver not loaded!\n"
04085932: 61fffff85a24             bsr.l   _printf
04085938: 7201                     moveq   #1,d1
0408593A: 23c1040b2264             move.l  d1,(dword_40B2264).l
04085940: 7005                     moveq   #5,d0
04085942: 4e5e                     unlk    a6
04085944: 4e75                     rts
