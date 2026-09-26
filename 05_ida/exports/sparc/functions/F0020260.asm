F0020260: 9de3bf98                 save    %sp, -0x68, %sp
F0020264: f6062010                 ld      [%i0+0x10], %i3
F0020268: b410001b                 mov     %i3, %i2
F002026C: 80a66000                 cmp     %i1, 0
F0020270: 22800003                 be,a    loc_F002027C
F0020274: c606a014                 ld      [%i2+0x14], %g3
F0020278: c606a01c                 ld      [%i2+0x1C], %g3
F002027C: 80a0c018                 cmp     %g3, %i0
F0020280: 02800006                 be      loc_F0020298
F0020284: 80a0c01b                 cmp     %g3, %i3
F0020288: 0280000d                 be      loc_F00202BC
F002028C: b4100003                 mov     %g3, %i2
F0020290: 10bffff8                 ba      loc_F0020270
F0020294: 80a66000                 cmp     %i1, 0
F0020298: 80a66000                 cmp     %i1, 0
F002029C: 3280000a                 bne,a   loc_F00202C4
F00202A0: c400e01c                 ld      [%g3+0x1C], %g2
F00202A4: c400e014                 ld      [%g3+0x14], %g2
F00202A8: c426a014                 st      %g2, [%i2+0x14]
F00202AC: c416e018                 lduh    [%i3+0x18], %g2
F00202B0: 8400bfff                 inc     -1, %g2
F00202B4: 10800008                 ba      loc_F00202D4
F00202B8: c436e018                 sth     %g2, [%i3+0x18]
F00202BC: 1080000a                 ba      locret_F00202E4
F00202C0: b0102000                 mov     0, %i0
F00202C4: c426a01c                 st      %g2, [%i2+0x1C]
F00202C8: c416e020                 lduh    [%i3+0x20], %g2
F00202CC: 8400bfff                 inc     -1, %g2
F00202D0: c436e020                 sth     %g2, [%i3+0x20]
F00202D4: c020e01c                 clr     [%g3+0x1C]
F00202D8: c020e014                 clr     [%g3+0x14]
F00202DC: c020e010                 clr     [%g3+0x10]
F00202E0: b0102001                 mov     1, %i0
F00202E4: 81c7e008                 ret
F00202E8: 81e80000                 restore
