0407A962: 4856                     pea     (a6)
0407A964: 2c4f                     movea.l sp,a6
0407A966: 2f2e002c                 move.l  $2C(a6),-(sp)
0407A96A: 2f2e0028                 move.l  $28(a6),-(sp)
0407A96E: 2f2e0024                 move.l  $24(a6),-(sp)
0407A972: 2f2e0020                 move.l  $20(a6),-(sp)
0407A976: 2f2e001c                 move.l  $1C(a6),-(sp)
0407A97A: 2f2e0018                 move.l  $18(a6),-(sp)
0407A97E: 2f2e0014                 move.l  $14(a6),-(sp)
0407A982: 2f2e0010                 move.l  $10(a6),-(sp)
0407A986: 2f2e000c                 move.l  $C(a6),-(sp)
0407A98A: 2f2e0008                 move.l  8(a6),-(sp)
0407A98E: 48780008                 pea     (8).w
0407A992: 4878003c                 pea     ($3C).w
0407A996: 61ffffff6c8c             bsr.l   _alert
0407A99C: defc002c                 adda.w  #$2C,sp ; ','
0407A9A0: 2ebc040ab2de             move.l  #$40AB2DE,(sp)
0407A9A6: 61fffff909b0             bsr.l   _printf
0407A9AC: 4e5e                     unlk    a6
0407A9AE: 4e75                     rts
