F0036668: 9de3bf98                 save    %sp, -0x68, %sp
F003666C: d0166026                 lduh    [%i1+0x26], %o0
F0036670: 98823fff                 addcc   %o0, -1, %o4
F0036674: 0c800020                 bneg    loc_F00366F4
F0036678: 113c0432                 sethi   -0xFEF3800, %o0
F003667C: d056a008                 ldsh    [%i2+8], %o0
F0036680: 80a2000c                 cmp     %o0, %o4
F0036684: 24800015                 ble,a   loc_F00366D8
F0036688: f4068000                 ld      [%i2], %i2
F003668C: d0062008                 ld      [%i0+8], %o0
F0036690: d206a004                 ld      [%i2+4], %o1
F0036694: d4022020                 ld      [%o0+0x20], %o2
F0036698: 92068009                 add     %i2, %o1, %o1
F003669C: d60a400c                 ldub    [%o1+%o4], %o3
F00366A0: d62aa069                 stb     %o3, [%o2+0x69]
F00366A4: d00aa068                 ldub    [%o2+0x68], %o0
F00366A8: 9202400c                 add     %o1, %o4, %o1! void *
F00366AC: 90122001                 bset    1, %o0
F00366B0: d02aa068                 stb     %o0, [%o2+0x68]
F00366B4: d456a008                 ldsh    [%i2+8], %o2
F00366B8: 90026001                 add     %o1, 1, %o0! void *
F00366BC: 9422800c                 sub     %o2, %o4, %o2! size_t
F00366C0: 40017914                 call    _bcopy
F00366C4: 9402bfff                 inc     -1, %o2
F00366C8: d016a008                 lduh    [%i2+8], %o0
F00366CC: 90023fff                 inc     -1, %o0
F00366D0: 1080000b                 ba      locret_F00366FC
F00366D4: d036a008                 sth     %o0, [%i2+8]
F00366D8: 80a6a000                 cmp     %i2, 0
F00366DC: 02800005                 be      loc_F00366F0
F00366E0: 98230008                 sub     %o4, %o0, %o4
F00366E4: 80a32000                 cmp     %o4, 0
F00366E8: 36bfffe6                 bge,a   loc_F0036680
F00366EC: d056a008                 ldsh    [%i2+8], %o0
F00366F0: 113c0432                 sethi   -0xFEF3800, %o0! char *
F00366F4: 7fff7a9f                 call    _panic
F00366F8: 901220b0                 bset    0xB0, %o0
F00366FC: 81c7e008                 ret
F0036700: 81e80000                 restore
