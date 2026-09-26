040379C4: 4856                     pea     (a6)
040379C6: 2c4f                     movea.l sp,a6
040379C8: 2f0a                     move.l  a2,-(sp)
040379CA: 246e0008                 movea.l 8(a6),a2
040379CE: 082a00000043             btst    #0,$43(a2)
040379D4: 670e                     beq.s   loc_40379E4
040379D6: 4879040a80e4             pea     (aIrele).l; "irele"
040379DC: 61fffffd4288             bsr.l   _panic
040379E2: 584f                     addq.w  #4,sp
040379E4: 322a0042                 move.w  $42(a2),d1
040379E8: 3001                     move.w  d1,d0
040379EA: 02400046                 andi.w  #$46,d0 ; 'F'
040379EE: 6750                     beq.s   loc_4037A40
040379F0: 00410008                 ori.w   #8,d1
040379F4: 35410042                 move.w  d1,$42(a2)
040379F8: 4879040b67b8             pea     (_iuniqtime).l
040379FE: 61ff00016f8c             bsr.l   _microtime
04037A04: 584f                     addq.w  #4,sp
04037A06: 082a00020043             btst    #2,$43(a2)
04037A0C: 6708                     beq.s   loc_4037A16
04037A0E: 2579040b67b80072         move.l  (_iuniqtime).l,$72(a2)
04037A16: 082a00010043             btst    #1,$43(a2)
04037A1C: 6708                     beq.s   loc_4037A26
04037A1E: 2579040b67b8007a         move.l  (_iuniqtime).l,$7A(a2)
04037A26: 082a00060043             btst    #6,$43(a2)
04037A2C: 670c                     beq.s   loc_4037A3A
04037A2E: 42aa004a                 clr.l   $4A(a2)
04037A32: 2579040b67b80082         move.l  (_iuniqtime).l,$82(a2)
04037A3A: 026affb90042             andi.w  #$FFB9,$42(a2)
04037A40: 486a000c                 pea     $C(a2)
04037A44: 61fffffe3680             bsr.l   _vn_rele
04037A4A: 246efffc                 movea.l -4(a6),a2
04037A4E: 4e5e                     unlk    a6
04037A50: 4e75                     rts
