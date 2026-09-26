F009BA98: 9de3bf98                 save    %sp, -0x68, %sp
F009BA9C: 80a6a012                 cmp     %i2, 0x12
F009BAA0: 38800004                 bgu,a   loc_F009BAB0
F009BAA4: d006200c                 ld      [%i0+0xC], %o0
F009BAA8: 1080001b                 ba      locret_F009BB14
F009BAAC: b0102004                 mov     4, %i0
F009BAB0: d002204c                 ld      [%o0+0x4C], %o0
F009BAB4: f4062028                 ld      [%i0+0x28], %i2
F009BAB8: 80a22000                 cmp     %o0, 0
F009BABC: 12800012                 bne     loc_F009BB04
F009BAC0: 9006a234                 add     %i2, 0x234, %o0! __dst
F009BAC4: 92100019                 mov     %i1, %o1! __src
F009BAC8: e006a234                 ld      [%i2+0x234], %l0
F009BACC: 7ffdadf5                 call    _memcpy
F009BAD0: 9410204c                 mov     0x4C, %o2 ! 'L'
F009BAD4: 13003c00                 sethi   0xF00000, %o1
F009BAD8: 922c0009                 andn    %l0, %o1, %o1
F009BADC: d0064000                 ld      [%i1], %o0
F009BAE0: 15003c00                 sethi   0xF00000, %o2
F009BAE4: 900a000a                 and     %o0, %o2, %o0
F009BAE8: 92124008                 bset    %o0, %o1
F009BAEC: d226a234                 st      %o1, [%i2+0x234]
F009BAF0: d0066004                 ld      [%i1+4], %o0
F009BAF4: b0102000                 mov     0, %i0
F009BAF8: 90022004                 inc     4, %o0
F009BAFC: 10800006                 ba      locret_F009BB14
F009BB00: d026a23c                 st      %o0, [%i2+0x23C]
F009BB04: d2066004                 ld      [%i1+4], %o1
F009BB08: 7fff67c7                 call    _thread_start
F009BB0C: 90100018                 mov     %i0, %o0
F009BB10: b0102000                 mov     0, %i0
F009BB14: 81c7e008                 ret
F009BB18: 81e80000                 restore
