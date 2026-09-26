F00BE93C: 9de3bf98                 save    %sp, -0x68, %sp
F00BE940: d2062018                 ld      [%i0+0x18], %o1
F00BE944: 80a26000                 cmp     %o1, 0
F00BE948: 26800002                 bl,a    loc_F00BE950
F00BE94C: 92026007                 inc     7, %o1
F00BE950: 933a6003                 sra     %o1, 3, %o1! int
F00BE954: d0062020                 ld      [%i0+0x20], %o0! int
F00BE958: d2262014                 st      %o1, [%i0+0x14]
F00BE95C: 7ffd1f2b                 call    _div
F00BE960: 9210200c                 mov     0xC, %o1
F00BE964: d026201c                 st      %o0, [%i0+0x1C]
F00BE968: 81c7e008                 ret
F00BE96C: 81e80000                 restore
