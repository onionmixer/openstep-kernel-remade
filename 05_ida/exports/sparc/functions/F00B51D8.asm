F00B51D8: 9de3bf98                 save    %sp, -0x68, %sp
F00B51DC: b4100018                 mov     %i0, %i2
F00B51E0: c456a0b2                 ldsh    [%i2+0xB2], %g2
F00B51E4: 8528a002                 sll     %g2, 2, %g2
F00B51E8: 8400801a                 add     %g2, %i2, %g2
F00B51EC: f600a0b8                 ld      [%g2+0xB8], %i3
F00B51F0: c406e02c                 ld      [%i3+0x2C], %g2
F00B51F4: c606e020                 ld      [%i3+0x20], %g3
F00B51F8: f00ee063                 ldub    [%i3+0x63], %i0
F00B51FC: 84208003                 sub     %g2, %g3, %g2
F00B5200: 80a08018                 cmp     %g2, %i0
F00B5204: 08800006                 bleu    loc_F00B521C
F00B5208: f206a09c                 ld      [%i2+0x9C], %i1
F00B520C: 84102008                 mov     8, %g2
F00B5210: c42ee028                 stb     %g2, [%i3+0x28]
F00B5214: 10800018                 ba      locret_F00B5274
F00B5218: b0102006                 mov     6, %i0
F00B521C: 86102001                 mov     1, %g3
F00B5220: c62e600c                 stb     %g3, [%i1+0xC]
F00B5224: c40ea033                 ldub    [%i2+0x33], %g2
F00B5228: 8088a040                 btst    0x40, %g2 ! '@'
F00B522C: 02800005                 be      loc_F00B5240
F00B5230: c62e4000                 stb     %g3, [%i1]
F00B5234: c02e6004                 clrb    [%i1+4]
F00B5238: 10800003                 ba      loc_F00B5244
F00B523C: c02e6038                 clrb    [%i1+0x38]
F00B5240: c02e6004                 clrb    [%i1+4]
F00B5244: c606e02c                 ld      [%i3+0x2C], %g3
F00B5248: 8400e001                 add     %g3, 1, %g2
F00B524C: c426e02c                 st      %g2, [%i3+0x2C]
F00B5250: c408c000                 ldub    [%g3], %g2
F00B5254: c42e6008                 stb     %g2, [%i1+8]
F00B5258: 84102010                 mov     0x10, %g2
F00B525C: c42e600c                 stb     %g2, [%i1+0xC]
F00B5260: c40ea041                 ldub    [%i2+0x41], %g2
F00B5264: b0103fff                 mov     -1, %i0
F00B5268: c42ea042                 stb     %g2, [%i2+0x42]
F00B526C: 84102002                 mov     2, %g2
F00B5270: c42ea041                 stb     %g2, [%i2+0x41]
F00B5274: 81c7e008                 ret
F00B5278: 81e80000                 restore
