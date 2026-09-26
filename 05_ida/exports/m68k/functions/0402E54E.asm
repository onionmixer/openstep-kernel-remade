0402E54E: 4856                     pea     (a6)
0402E550: 2c4f                     movea.l sp,a6
0402E552: 48e73e30                 movem.l d2-d6/a2-a3,-(sp)
0402E556: 2c2e0008                 move.l  8(a6),d6
0402E55A: 48780008                 pea     (8).w
0402E55E: 48780001                 pea     (1).w
0402E562: 61fffffe3a00             bsr.l   _m_get
0402E568: 2440                     movea.l d0,a2
0402E56A: 504f                     addq.w  #8,sp
0402E56C: 4a8a                     tst.l   a2
0402E56E: 6612                     bne.s   loc_402E582
0402E570: 4879040a7390             pea     (aBindresvportCo).l; "bindresvport: couldn't alloc mbuf"
0402E576: 61fffffdcde0             bsr.l   _printf
0402E57C: 7037                     moveq   #$37,d0 ; '7'
0402E57E: 60000088                 bra.w   loc_402E608
0402E582: 264a                     movea.l a2,a3
0402E584: d7ea0004                 adda.l  4(a2),a3
0402E588: 36bc0002                 move.w  #2,(a3)
0402E58C: 42ab0004                 clr.l   4(a3)
0402E590: 357c00100008             move.w  #$10,8(a2)
0402E596: 2079040b57d0             movea.l (_active_u).l,a0
0402E59C: 2f28001a                 move.l  $1A(a0),-(sp)
0402E5A0: 61fffffd9732             bsr.l   _crdup
0402E5A6: 2800                     move.l  d0,d4
0402E5A8: 2079040b57d0             movea.l (_active_u).l,a0
0402E5AE: 2a28001a                 move.l  $1A(a0),d5
0402E5B2: 2144001a                 move.l  d4,$1A(a0)
0402E5B6: 2079040b57d0             movea.l (_active_u).l,a0
0402E5BC: 2068001a                 movea.l $1A(a0),a0
0402E5C0: 42680002                 clr.w   2(a0)
0402E5C4: 7630                     moveq   #$30,d3 ; '0'
0402E5C6: 343c03ff                 move.w  #$3FF,d2
0402E5CA: 584f                     addq.w  #4,sp
0402E5CC: 0c4201ff                 cmpi.w  #$1FF,d2
0402E5D0: 631a                     bls.s   loc_402E5EC
0402E5D2: 37420002                 move.w  d2,2(a3)
0402E5D6: 2f0a                     move.l  a2,-(sp)
0402E5D8: 2f06                     move.l  d6,-(sp)
0402E5DA: 61fffffe43c2             bsr.l   _sobind
0402E5E0: 2600                     move.l  d0,d3
0402E5E2: 504f                     addq.w  #8,sp
0402E5E4: 5342                     subq.w  #1,d2
0402E5E6: 7230                     moveq   #$30,d1 ; '0'
0402E5E8: b283                     cmp.l   d3,d1
0402E5EA: 67e0                     beq.s   loc_402E5CC
0402E5EC: 2f0a                     move.l  a2,-(sp)
0402E5EE: 61fffffe3bb6             bsr.l   _m_freem
0402E5F4: 2079040b57d0             movea.l (_active_u).l,a0
0402E5FA: 2145001a                 move.l  d5,$1A(a0)
0402E5FE: 2f04                     move.l  d4,-(sp)
0402E600: 61fffffd9644             bsr.l   _crfree
0402E606: 2003                     move.l  d3,d0
0402E608: 4cee0c7cffe4             movem.l -$1C(a6),d2-d6/a2-a3
0402E60E: 4e5e                     unlk    a6
0402E610: 4e75                     rts
