040295CE: 4e56fff8                 link    a6,#-8
040295D2: 2f0a                     move.l  a2,-(sp)
040295D4: 2f02                     move.l  d2,-(sp)
040295D6: 487800ff                 pea     ($FF).w
040295DA: 61ff00020c24             bsr.l   _kalloc
040295E0: 2400                     move.l  d0,d2
040295E2: 2442                     movea.l d2,a2
040295E4: 41f9040aee58             lea     (aNfs_0).l,a0; ".nfs"
040295EA: 584f                     addq.w  #4,sp
040295EC: 203c040aee5c             move.l  #$40AEE5C,d0
040295F2: b088                     cmp.l   a0,d0
040295F4: 6306                     bls.s   loc_40295FC
040295F6: 14d8                     move.b  (a0)+,(a2)+
040295F8: b088                     cmp.l   a0,d0
040295FA: 62fa                     bhi.s   loc_40295F6
040295FC: 4ab9040b352c             tst.l   (dword_40B352C).l
04029602: 6616                     bne.s   loc_402961A
04029604: 486efff8                 pea     var_8(a6)
04029608: 61fffffe0d56             bsr.l   _getthetime
0402960E: 4280                     clr.l   d0
04029610: 302efffa                 move.w  var_6(a6),d0
04029614: 23c0040b352c             move.l  d0,(dword_40B352C).l
0402961A: 2239040b352c             move.l  (dword_40B352C).l,d1
04029620: 52b9040b352c             addq.l  #1,(dword_40B352C).l
04029626: 4a81                     tst.l   d1
04029628: 6712                     beq.s   loc_402963C
0402962A: 41f9040a6c60             lea     (a0123456789abcd_0).l,a0; "0123456789ABCDEF"
04029630: 700f                     moveq   #$F,d0
04029632: c081                     and.l   d1,d0
04029634: 14f00800                 move.b  (a0,d0.l),(a2)+
04029638: e881                     asr.l   #4,d1
0402963A: 66f4                     bne.s   loc_4029630
0402963C: 4212                     clr.b   (a2)
0402963E: 2002                     move.l  d2,d0
04029640: 242efff0                 move.l  var_10(a6),d2
04029644: 246efff4                 movea.l var_C(a6),a2
04029648: 4e5e                     unlk    a6
0402964A: 4e75                     rts
