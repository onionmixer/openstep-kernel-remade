F001A560: 9de3bf98                 save    %sp, -0x68, %sp
F001A564: b2100018                 mov     %i0, %i1
F001A568: f4064000                 ld      [%i1], %i2
F001A56C: c406a03c                 ld      [%i2+0x3C], %g2
F001A570: 8088a022                 btst    0x22, %g2 ! '"'
F001A574: 0280000a                 be      locret_F001A59C
F001A578: b0102001                 mov     1, %i0
F001A57C: c60e6015                 ldub    [%i1+0x15], %g3
F001A580: c4068000                 ld      [%i2], %g2
F001A584: 80a08003                 cmp     %g2, %g3
F001A588: 16800005                 bge     locret_F001A59C
F001A58C: 01000000                 nop
F001A590: c40e6016                 ldub    [%i1+0x16], %g2
F001A594: 80a00002                 cmp     %g0, %g2
F001A598: b0402000                 addc    %g0, 0, %i0
F001A59C: 81c7e008                 ret
F001A5A0: 81e80000                 restore
