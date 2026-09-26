0400725A: 4e56ffb0                 link    a6,#-$50
0400725E: 2f0b                     move.l  a3,-(sp)
04007260: 2f0a                     move.l  a2,-(sp)
04007262: 266e0008                 movea.l arg_0(a6),a3
04007266: 302b0030                 move.w  $30(a3),d0
0400726A: 723f                     moveq   #$3F,d1 ; '?'
0400726C: c081                     and.l   d1,d0
0400726E: 41f9040b5f04             lea     (_posix_proc_hash).l,a0
04007274: 45f00c00                 lea     (a0,d0.l*4),a2
04007278: 4a92                     tst.l   (a2)
0400727A: 6724                     beq.s   loc_40072A0
0400727C: 2252                     movea.l (a2),a1
0400727E: 306b0030                 movea.w $30(a3),a0
04007282: b1d1                     cmpa.l  (a1),a0
04007284: 6612                     bne.s   loc_4007298
04007286: 24a9001a                 move.l  $1A(a1),(a2)
0400728A: 4878001e                 pea     ($1E).w
0400728E: 2f09                     move.l  a1,-(sp)
04007290: 61ff00043032             bsr.l   _kfree
04007296: 6028                     bra.s   loc_40072C0
04007298: 45e9001a                 lea     $1A(a1),a2
0400729C: 4a92                     tst.l   (a2)
0400729E: 66dc                     bne.s   loc_400727C
040072A0: 366b0030                 movea.w $30(a3),a3
040072A4: 2f0b                     move.l  a3,-(sp)
040072A6: 4879040a5fc1             pea     (aDeletePosixPro).l; "delete_posix_proc(): no posix proc stru"...
040072AC: 45eeffb0                 lea     var_50(a6),a2
040072B0: 2f0a                     move.l  a2,-(sp)
040072B2: 61ff00004168             bsr.l   _sprintf
040072B8: 2f0a                     move.l  a2,-(sp)
040072BA: 61ff000049aa             bsr.l   _panic
040072C0: 246effa8                 movea.l var_58(a6),a2
040072C4: 266effac                 movea.l var_54(a6),a3
040072C8: 4e5e                     unlk    a6
040072CA: 4e75                     rts
