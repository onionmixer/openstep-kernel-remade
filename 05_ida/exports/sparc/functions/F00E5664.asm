F00E5664: 9de3bf98                 save    %sp, -0x68, %sp
F00E5668: 80a6200f                 cmp     %i0, 0xF
F00E566C: 073c04bb                 sethi   %hi(_sparcfbs), %g3
F00E5670: 852e2004                 sll     %i0, 4, %g2
F00E5674: 84008018                 add     %g2, %i0, %g2
F00E5678: 8528a002                 sll     %g2, 2, %g2
F00E567C: c600e364                 ld      [%g3+%lo(_sparcfbs)], %g3
F00E5680: 8400a008                 inc     8, %g2
F00E5684: 18800006                 bgu     loc_F00E569C
F00E5688: b000c002                 add     %g3, %g2, %i0
F00E568C: c400c002                 ld      [%g3+%g2], %g2
F00E5690: 80a0a000                 cmp     %g2, 0
F00E5694: 12800004                 bne     loc_F00E56A4
F00E5698: 01000000                 nop
F00E569C: 10800010                 ba      locret_F00E56DC
F00E56A0: b0103d40                 mov     -0x2C0, %i0
F00E56A4: c6062014                 ld      [%i0+0x14], %g3
F00E56A8: c406201c                 ld      [%i0+0x1C], %g2
F00E56AC: 8600c002                 add     %g3, %g2, %g3
F00E56B0: 852e6018                 sll     %i1, 24, %g2
F00E56B4: f0062014                 ld      [%i0+0x14], %i0
F00E56B8: 80a60003                 cmp     %i0, %g3
F00E56BC: 1a800007                 bcc     loc_F00E56D8
F00E56C0: 84108019                 bset    %i1, %g2
F00E56C4: c4260000                 st      %g2, [%i0]
F00E56C8: b0062004                 inc     4, %i0
F00E56CC: 80a60003                 cmp     %i0, %g3
F00E56D0: 2abffffe                 bcs,a   loc_F00E56C8
F00E56D4: c4260000                 st      %g2, [%i0]
F00E56D8: b0102000                 mov     0, %i0
F00E56DC: 81c7e008                 ret
F00E56E0: 81e80000                 restore
