040404B8: 4856                     pea     (a6)
040404BA: 2c4f                     movea.l sp,a6
040404BC: 226e0008                 movea.l 8(a6),a1
040404C0: 202e000c                 move.l  $C(a6),d0
040404C4: 5b80                     subq.l  #5,d0
040404C6: 7210                     moveq   #$10,d1
040404C8: b280                     cmp.l   d0,d1
040404CA: 65000082                 bcs.w   loc_404054E
040404CE: 207c040404da             movea.l #$40404DA,a0
040404D4: 20700c00                 movea.l (a0,d0.l*4),a0
040404D8: 4ed0                     jmp     (a0)
040404DA: 0404051e                 subi.b  #$1E,d4
040404DE: 0404052c                 subi.b  #$2C,d4 ; ','
040404E2: 0404054e                 subi.b  #$4E,d4 ; 'N'
040404E6: 0404054e                 subi.b  #$4E,d4 ; 'N'
040404EA: 0404054e                 subi.b  #$4E,d4 ; 'N'
040404EE: 0404054e                 subi.b  #$4E,d4 ; 'N'
040404F2: 0404054e                 subi.b  #$4E,d4 ; 'N'
040404F6: 0404054e                 subi.b  #$4E,d4 ; 'N'
040404FA: 0404054e                 subi.b  #$4E,d4 ; 'N'
040404FE: 0404054e                 subi.b  #$4E,d4 ; 'N'
04040502: 0404054e                 subi.b  #$4E,d4 ; 'N'
04040506: 0404051e                 subi.b  #$1E,d4
0404050A: 0404055a                 subi.b  #$5A,d4 ; 'Z'
0404050E: 0404055a                 subi.b  #$5A,d4 ; 'Z'
04040512: 0404052c                 subi.b  #$2C,d4 ; ','
04040516: 0404053a                 subi.b  #$3A,d4 ; ':'
0404051A: 04040546                 subi.b  #$46,d4 ; 'F'
0404051E: 42a90014                 clr.l   $14(a1)
04040522: 42a9000c                 clr.l   $C(a1)
04040526: 42a90008                 clr.l   8(a1)
0404052A: 602e                     bra.s   loc_404055A
0404052C: 4aa90004                 tst.l   4(a1)
04040530: 6c04                     bge.s   loc_4040536
04040532: 52a90018                 addq.l  #1,$18(a1)
04040536: 5291                     addq.l  #1,(a1)
04040538: 6020                     bra.s   loc_404055A
0404053A: 5291                     addq.l  #1,(a1)
0404053C: 52a90014                 addq.l  #1,$14(a1)
04040540: 52a90018                 addq.l  #1,$18(a1)
04040544: 6014                     bra.s   loc_404055A
04040546: 5291                     addq.l  #1,(a1)
04040548: 52a9001c                 addq.l  #1,$1C(a1)
0404054C: 600c                     bra.s   loc_404055A
0404054E: 4879040a853d             pea     (aIpcObjectCopyi_0).l; "ipc_object_copyin_from_kernel: strange "...
04040554: 61fffffcb710             bsr.l   _panic
0404055A: 4e5e                     unlk    a6
0404055C: 4e75                     rts
