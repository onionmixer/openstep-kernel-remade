0404ABCC: 4856                     pea     (a6)
0404ABCE: 2c4f                     movea.l sp,a6
0404ABD0: 2f0a                     move.l  a2,-(sp)
0404ABD2: 246e0008                 movea.l 8(a6),a2
0404ABD6: 2052                     movea.l (a2),a0
0404ABD8: b1f9040b5648             cmpa.l  (_active_threads).l,a0
0404ABDE: 665c                     bne.s   loc_404AC3C
0404ABE0: 302a0006                 move.w  6(a2),d0
0404ABE4: 5240                     addq.w  #1,d0
0404ABE6: 02400fff                 andi.w  #$FFF,d0
0404ABEA: efea010c0006             bfins   d0,6(a2){4:12}
0404ABF0: 600000b4                 bra.w   loc_404ACA6
0404ABF4: 2039040af7e0             move.l  (_lock_wait_time).l,d0
0404ABFA: 6f18                     ble.s   loc_404AC14
0404ABFC: 5380                     subq.l  #1,d0
0404ABFE: 4a80                     tst.l   d0
0404AC00: 6f12                     ble.s   loc_404AC14
0404AC02: 122a0006                 move.b  6(a2),d1
0404AC06: 02010040                 andi.b  #$40,d1 ; '@'
0404AC0A: 4a01                     tst.b   d1
0404AC0C: 6706                     beq.s   loc_404AC14
0404AC0E: 5380                     subq.l  #1,d0
0404AC10: 4a80                     tst.l   d0
0404AC12: 6ef6                     bgt.s   loc_404AC0A
0404AC14: 122a0006                 move.b  6(a2),d1
0404AC18: 1001                     move.b  d1,d0
0404AC1A: 02000050                 andi.b  #$50,d0 ; 'P'
0404AC1E: 0c000050                 cmpi.b  #$50,d0 ; 'P'
0404AC22: 6618                     bne.s   loc_404AC3C
0404AC24: 00010020                 ori.b   #$20,d1 ; ' '
0404AC28: 15410006                 move.b  d1,6(a2)
0404AC2C: 42a7                     clr.l   -(sp)
0404AC2E: 42a7                     clr.l   -(sp)
0404AC30: 2f0a                     move.l  a2,-(sp)
0404AC32: 61ff00005e72             bsr.l   _thread_sleep
0404AC38: 504f                     addq.w  #8,sp
0404AC3A: 584f                     addq.w  #4,sp
0404AC3C: 082a00060006             btst    #6,6(a2)
0404AC42: 66b0                     bne.s   loc_404ABF4
0404AC44: 002a00400006             ori.b   #$40,6(a2) ; '@'
0404AC4A: 604e                     bra.s   loc_404AC9A
0404AC4C: 2039040af7e0             move.l  (_lock_wait_time).l,d0
0404AC52: 6f18                     ble.s   loc_404AC6C
0404AC54: 5380                     subq.l  #1,d0
0404AC56: 4a80                     tst.l   d0
0404AC58: 6f12                     ble.s   loc_404AC6C
0404AC5A: 222a0004                 move.l  4(a2),d1
0404AC5E: 02418000                 andi.w  #$8000,d1
0404AC62: 4a81                     tst.l   d1
0404AC64: 6706                     beq.s   loc_404AC6C
0404AC66: 5380                     subq.l  #1,d0
0404AC68: 4a80                     tst.l   d0
0404AC6A: 6ef6                     bgt.s   loc_404AC62
0404AC6C: 122a0006                 move.b  6(a2),d1
0404AC70: 08010004                 btst    #4,d1
0404AC74: 6724                     beq.s   loc_404AC9A
0404AC76: 202a0004                 move.l  4(a2),d0
0404AC7A: 02408000                 andi.w  #$8000,d0
0404AC7E: 4a80                     tst.l   d0
0404AC80: 6724                     beq.s   loc_404ACA6
0404AC82: 00010020                 ori.b   #$20,d1 ; ' '
0404AC86: 15410006                 move.b  d1,6(a2)
0404AC8A: 42a7                     clr.l   -(sp)
0404AC8C: 42a7                     clr.l   -(sp)
0404AC8E: 2f0a                     move.l  a2,-(sp)
0404AC90: 61ff00005e14             bsr.l   _thread_sleep
0404AC96: 504f                     addq.w  #8,sp
0404AC98: 584f                     addq.w  #4,sp
0404AC9A: 202a0004                 move.l  4(a2),d0
0404AC9E: 02408000                 andi.w  #$8000,d0
0404ACA2: 4a80                     tst.l   d0
0404ACA4: 66a6                     bne.s   loc_404AC4C
0404ACA6: 246efffc                 movea.l -4(a6),a2
0404ACAA: 4e5e                     unlk    a6
0404ACAC: 4e75                     rts
