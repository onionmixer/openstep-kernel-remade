F00767D8: 9de3bf98                 save    %sp, -0x68, %sp
F00767DC: 9e100018                 mov     %i0, %o7
F00767E0: 053c04c3                 sethi   %hi(dword_F0130F2C), %g2
F00767E4: f600a32c                 ld      [%g2+%lo(dword_F0130F2C)], %i3
F00767E8: 8610a32c                 or      %g2, %lo(dword_F0130F2C), %g3
F00767EC: 80a6c003                 cmp     %i3, %g3
F00767F0: 0280002c                 be      locret_F00768A0
F00767F4: b0102000                 mov     0, %i0
F00767F8: 033c04c3                 sethi   -0xFECF400, %g1
F00767FC: 053c04c18810a120         set     unk_F0130520, %g4
F0076804: 92012a00                 add     %g4, 0xA00, %o1
F0076808: 053c04c3ba10a324         set     dword_F0130F24, %i5
F0076810: 90100003                 mov     %g3, %o0
F0076814: c406e008                 ld      [%i3+8], %g2
F0076818: 80a0800f                 cmp     %g2, %o7
F007681C: 3280001e                 bne,a   loc_F0076894
F0076820: f606c000                 ld      [%i3], %i3
F0076824: c406e00c                 ld      [%i3+0xC], %g2
F0076828: 80a08019                 cmp     %g2, %i1
F007682C: 3280001a                 bne,a   loc_F0076894
F0076830: f606c000                 ld      [%i3], %i3
F0076834: f806c000                 ld      [%i3], %i4
F0076838: c606e004                 ld      [%i3+4], %g3
F007683C: 80a6c004                 cmp     %i3, %g4
F0076840: c400633c                 ld      [%g1+0x33C], %g2
F0076844: c6272004                 st      %g3, [%i4+4]
F0076848: f006e004                 ld      [%i3+4], %i0
F007684C: 8400bfff                 inc     -1, %g2
F0076850: c606c000                 ld      [%i3], %g3
F0076854: c420633c                 st      %g2, [%g1+0x33C]
F0076858: c6260000                 st      %g3, [%i0]
F007685C: 0a80000a                 bcs     loc_F0076884
F0076860: c026e020                 clr     [%i3+0x20]
F0076864: 80a6c009                 cmp     %i3, %o1
F0076868: 1a800008                 bcc     loc_F0076888
F007686C: 80a6a000                 cmp     %i2, 0
F0076870: fa26c000                 st      %i5, [%i3]
F0076874: c4076004                 ld      [%i5+4], %g2
F0076878: c426e004                 st      %g2, [%i3+4]
F007687C: f6208000                 st      %i3, [%g2]
F0076880: f6276004                 st      %i3, [%i5+4]
F0076884: 80a6a000                 cmp     %i2, 0
F0076888: 02800006                 be      locret_F00768A0
F007688C: b0102001                 mov     1, %i0
F0076890: b610001c                 mov     %i4, %i3
F0076894: 80a6c008                 cmp     %i3, %o0
F0076898: 32bfffe0                 bne,a   loc_F0076818
F007689C: c406e008                 ld      [%i3+8], %g2
F00768A0: 81c7e008                 ret
F00768A4: 81e80000                 restore
