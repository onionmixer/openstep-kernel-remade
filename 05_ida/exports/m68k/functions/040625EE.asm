040625EE: 4856                     pea     (a6)
040625F0: 2c4f                     movea.l sp,a6
040625F2: 202e0008                 move.l  8(a6),d0
040625F6: 671a                     beq.s   loc_4062612
040625F8: 2f2e0018                 move.l  $18(a6),-(sp)
040625FC: 2f2e0014                 move.l  $14(a6),-(sp)
04062600: 2f2e0010                 move.l  $10(a6),-(sp)
04062604: 2f2e000c                 move.l  $C(a6),-(sp)
04062608: 2f00                     move.l  d0,-(sp)
0406260A: 61ffffffcedc             bsr.l   _vm_map_machine_attribute
04062610: 6002                     bra.s   loc_4062614
04062612: 7004                     moveq   #4,d0
04062614: 4e5e                     unlk    a6
04062616: 4e75                     rts
