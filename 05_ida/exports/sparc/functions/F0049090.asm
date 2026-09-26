F0049090: 9de3bf98                 save    %sp, -0x68, %sp
F0049094: e006202c                 ld      [%i0+0x2C], %l0
F0049098: d00620c8                 ld      [%i0+0xC8], %o0! int
F004909C: 7ffef55b                 call    _div
F00490A0: 92100010                 mov     %l0, %o1
F00490A4: 9a102000                 mov     0, %o5
F00490A8: 94102000                 mov     0, %o2
F00490AC: 80a34010                 cmp     %o5, %l0
F00490B0: d80620b8                 ld      [%i0+0xB8], %o4
F00490B4: 1680001b                 bge     loc_F0049120
F00490B8: 82100008                 mov     %o0, %g1
F00490BC: d006206c                 ld      [%i0+0x6C], %o0
F00490C0: 9e100010                 mov     %l0, %o7
F00490C4: c6062070                 ld      [%i0+0x70], %g3
F00490C8: 84380008                 xnor    %g0, %o0, %g2
F00490CC: 913a8003                 sra     %o2, %g3, %o0
F00490D0: 912a2002                 sll     %o0, 2, %o0
F00490D4: 90020018                 add     %o0, %i0, %o0
F00490D8: 920a8002                 and     %o2, %g2, %o1
F00490DC: d00222d8                 ld      [%o0+0x2D8], %o0
F00490E0: 932a6004                 sll     %o1, 4, %o1
F00490E4: d6020009                 ld      [%o0+%o1], %o3
F00490E8: 80a2c00c                 cmp     %o3, %o4
F00490EC: 3680000a                 bge,a   loc_F0049114
F00490F0: 9402a001                 inc     %o2
F00490F4: 90020009                 add     %o0, %o1, %o0
F00490F8: d0022008                 ld      [%o0+8], %o0
F00490FC: 80a20001                 cmp     %o0, %g1
F0049100: 26800005                 bl,a    loc_F0049114
F0049104: 9402a001                 inc     %o2
F0049108: 9a10000a                 mov     %o2, %o5
F004910C: 9810000b                 mov     %o3, %o4
F0049110: 9402a001                 inc     %o2
F0049114: 80a2800f                 cmp     %o2, %o7
F0049118: 06bfffee                 bl      loc_F00490D0
F004911C: 913a8003                 sra     %o2, %g3, %o0
F0049120: d00620b8                 ld      [%i0+0xB8], %o0
F0049124: 7ffef4f7                 call    _umul
F0049128: 9210000d                 mov     %o5, %o1
F004912C: 81c7e008                 ret
F0049130: 91e80008                 restore %g0, %o0, %o0
