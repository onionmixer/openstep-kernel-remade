F00768A8: 9de3bf98                 save    %sp, -0x68, %sp
F00768AC: 88100018                 mov     %i0, %g4
F00768B0: 053c04c3                 sethi   %hi(dword_F0130F34), %g2
F00768B4: f600a334                 ld      [%g2+%lo(dword_F0130F34)], %i3
F00768B8: 8610a334                 or      %g2, %lo(dword_F0130F34), %g3
F00768BC: 80a6c003                 cmp     %i3, %g3
F00768C0: 02800028                 be      locret_F0076960
F00768C4: b0102000                 mov     0, %i0
F00768C8: 053c04c18210a120         set     unk_F0130520, %g1
F00768D0: 90006a00                 add     %g1, 0xA00, %o0
F00768D4: 053c04c3ba10a324         set     dword_F0130F24, %i5
F00768DC: 9e100003                 mov     %g3, %o7
F00768E0: c406e008                 ld      [%i3+8], %g2
F00768E4: 80a08004                 cmp     %g2, %g4
F00768E8: 3280001b                 bne,a   loc_F0076954
F00768EC: f606c000                 ld      [%i3], %i3
F00768F0: c406e00c                 ld      [%i3+0xC], %g2
F00768F4: 80a08019                 cmp     %g2, %i1
F00768F8: 32800017                 bne,a   loc_F0076954
F00768FC: f606c000                 ld      [%i3], %i3
F0076900: f806c000                 ld      [%i3], %i4
F0076904: c406e004                 ld      [%i3+4], %g2
F0076908: c4272004                 st      %g2, [%i4+4]
F007690C: c606e004                 ld      [%i3+4], %g3
F0076910: c406c000                 ld      [%i3], %g2
F0076914: 80a6c001                 cmp     %i3, %g1
F0076918: c420c000                 st      %g2, [%g3]
F007691C: 0a80000a                 bcs     loc_F0076944
F0076920: c026e020                 clr     [%i3+0x20]
F0076924: 80a6c008                 cmp     %i3, %o0
F0076928: 1a800008                 bcc     loc_F0076948
F007692C: 80a6a000                 cmp     %i2, 0
F0076930: fa26c000                 st      %i5, [%i3]
F0076934: c4076004                 ld      [%i5+4], %g2
F0076938: c426e004                 st      %g2, [%i3+4]
F007693C: f6208000                 st      %i3, [%g2]
F0076940: f6276004                 st      %i3, [%i5+4]
F0076944: 80a6a000                 cmp     %i2, 0
F0076948: 02800006                 be      locret_F0076960
F007694C: b0102001                 mov     1, %i0
F0076950: b610001c                 mov     %i4, %i3
F0076954: 80a6c00f                 cmp     %i3, %o7
F0076958: 32bfffe3                 bne,a   loc_F00768E4
F007695C: c406e008                 ld      [%i3+8], %g2
F0076960: 81c7e008                 ret
F0076964: 81e80000                 restore
