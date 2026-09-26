F00B0274: 9de3bf98                 save    %sp, -0x68, %sp
F00B0278: 7ffffbea                 call    _prom_stdinpath
F00B027C: 01000000                 nop
F00B0280: 7ffffd19                 call    _prom_stdoutpath
F00B0284: b0100008                 mov     %o0, %i0
F00B0288: 80a62000                 cmp     %i0, 0
F00B028C: 0280000a                 be      loc_F00B02B4
F00B0290: 92100008                 mov     %o0, %o1! __s2
F00B0294: 80a26000                 cmp     %o1, 0
F00B0298: 02800008                 be      loc_F00B02B8
F00B029C: 113c0470                 sethi   -0xFEE4000, %o0! __s1
F00B02A0: 7ffd5fc3                 call    _strcmp
F00B02A4: 90100018                 mov     %i0, %o0
F00B02A8: 80a00008                 cmp     %g0, %o0
F00B02AC: 10800016                 ba      locret_F00B0304
F00B02B0: b0603fff                 subc    %g0, -1, %i0
F00B02B4: 113c0470                 sethi   -0xFEE4000, %o0
F00B02B8: d0022278                 ld      [%o0+0x278], %o0
F00B02BC: 80a22000                 cmp     %o0, 0
F00B02C0: 02800004                 be      loc_F00B02D0
F00B02C4: 80a22002                 cmp     %o0, 2
F00B02C8: 1280000f                 bne     locret_F00B0304
F00B02CC: b0102000                 mov     0, %i0
F00B02D0: 113c000c                 sethi   %hi(_romp), %o0
F00B02D4: d2022030                 ld      [%o0+%lo(_romp)], %o1
F00B02D8: d002604c                 ld      [%o1+0x4C], %o0
F00B02DC: d40a0000                 ldub    [%o0], %o2
F00B02E0: 80a2a000                 cmp     %o2, 0
F00B02E4: 02800008                 be      locret_F00B0304
F00B02E8: b0102000                 mov     0, %i0
F00B02EC: d0026048                 ld      [%o1+0x48], %o0
F00B02F0: d00a0000                 ldub    [%o0], %o0
F00B02F4: 80a2000a                 cmp     %o0, %o2
F00B02F8: 12800003                 bne     locret_F00B0304
F00B02FC: 01000000                 nop
F00B0300: b0102001                 mov     1, %i0
F00B0304: 81c7e008                 ret
F00B0308: 81e80000                 restore
