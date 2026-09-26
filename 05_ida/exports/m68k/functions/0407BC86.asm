0407BC86: 4856                     pea     (a6)
0407BC88: 2c4f                     movea.l sp,a6
0407BC8A: 226e0008                 movea.l 8(a6),a1
0407BC8E: 102e0013                 move.b  $13(a6),d0
0407BC92: 2051                     movea.l (a1),a0
0407BC94: 20680010                 movea.l $10(a0),a0
0407BC98: 20680008                 movea.l 8(a0),a0
0407BC9C: 136e000f0221             move.b  $F(a6),$221(a1)
0407BCA2: 13400220                 move.b  d0,$220(a1)
0407BCA6: 137c0001021f             move.b  #1,$21F(a1)
0407BCAC: 117c001a0003             move.b  #$1A,3(a0)
0407BCB2: 4e5e                     unlk    a6
0407BCB4: 4e75                     rts
