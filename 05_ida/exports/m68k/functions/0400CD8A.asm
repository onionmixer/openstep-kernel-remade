0400CD8A: 4856                     pea     (a6)
0400CD8C: 2c4f                     movea.l sp,a6
0400CD8E: 2f0a                     move.l  a2,-(sp)
0400CD90: 246e0008                 movea.l 8(a6),a2
0400CD94: 2f0a                     move.l  a2,-(sp)
0400CD96: 61ff00003304             bsr.l   _ttynty
0400CD9C: 2040                     movea.l d0,a0
0400CD9E: 2579040ae49e004c         move.l  (_ttydefaults).l,$4C(a2)
0400CDA6: 2579040ae4a20050         move.l  (dword_40AE4A2).l,$50(a2)
0400CDAE: 2579040ae4a60054         move.l  (dword_40AE4A6).l,$54(a2)
0400CDB6: 3579040ae4aa0058         move.w  (word_40AE4AA).l,$58(a2)
0400CDBE: 117c005c0014             move.b  #$5C,$14(a0) ; '\'
0400CDC4: 117c00010015             move.b  #1,$15(a0)
0400CDCA: 42280016                 clr.b   $16(a0)
0400CDCE: 2f08                     move.l  a0,-(sp)
0400CDD0: 61fffffffdec             bsr.l   _ttysetspec
0400CDD6: 246efffc                 movea.l -4(a6),a2
0400CDDA: 4e5e                     unlk    a6
0400CDDC: 4e75                     rts
