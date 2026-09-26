F00790FC: 9de3bf98                 save    %sp, -0x68, %sp
F0079100: 80a62000                 cmp     %i0, 0
F0079104: 32800006                 bne,a   loc_F007911C
F0079108: d006202c                 ld      [%i0+0x2C], %o0
F007910C: 113c0443                 sethi   %hi(aZallocNullZone_0), %o0! "zalloc: null zone"
F0079110: 7ffe7018                 call    _panic
F0079114: 90122078                 bset    %lo(aZallocNullZone_0), %o0! "zalloc: null zone"
F0079118: d006202c                 ld      [%i0+0x2C], %o0
F007911C: 80a22000                 cmp     %o0, 0
F0079120: 16800006                 bge     loc_F0079138
F0079124: 01000000                 nop
F0079128: 7fffbf27                 call    _lock_write
F007912C: 90062030                 add     %i0, 0x30, %o0 ! '0'
F0079130: 10800010                 ba      loc_F0079170
F0079134: e0062010                 ld      [%i0+0x10], %l0
F0079138: 40007694                 call    _splusclock
F007913C: 01000000                 nop
F0079140: a0100008                 mov     %o0, %l0
F0079144: d0060000                 ld      [%i0], %o0
F0079148: 80a22000                 cmp     %o0, 0
F007914C: 12bffffe                 bne     loc_F0079144
F0079150: 01000000                 nop
F0079154: 40007755                 call    _simple_lock_try
F0079158: 90100018                 mov     %i0, %o0
F007915C: 80a22000                 cmp     %o0, 0
F0079160: 02bffff9                 be      loc_F0079144
F0079164: 01000000                 nop
F0079168: e0262004                 st      %l0, [%i0+4]
F007916C: e0062010                 ld      [%i0+0x10], %l0
F0079170: 80a42000                 cmp     %l0, 0
F0079174: 2280000c                 be,a    loc_F00791A4
F0079178: d006202c                 ld      [%i0+0x2C], %o0
F007917C: d0062008                 ld      [%i0+8], %o0
F0079180: d206200c                 ld      [%i0+0xC], %o1
F0079184: 90022001                 inc     %o0
F0079188: d0262008                 st      %o0, [%i0+8]
F007918C: d0040000                 ld      [%l0], %o0
F0079190: 80a24010                 cmp     %o1, %l0
F0079194: 12800003                 bne     loc_F00791A0
F0079198: d0262010                 st      %o0, [%i0+0x10]
F007919C: c026200c                 clr     [%i0+0xC]
F00791A0: d006202c                 ld      [%i0+0x2C], %o0
F00791A4: 80a22000                 cmp     %o0, 0
F00791A8: 36800005                 bge,a   loc_F00791BC
F00791AC: d0062004                 ld      [%i0+4], %o0
F00791B0: 7fffbfa1                 call    _lock_done
F00791B4: 90062030                 add     %i0, 0x30, %o0 ! '0'
F00791B8: 30800004                 ba,a    locret_F00791C8
F00791BC: c0260000                 clr     [%i0]
F00791C0: 400076d9                 call    _splx
F00791C4: 01000000                 nop
F00791C8: 81c7e008                 ret
F00791CC: 91e80010                 restore %g0, %l0, %o0
