F009BC2C: 9de3bf98                 save    %sp, -0x68, %sp
F009BC30: d0068000                 ld      [%i2], %o0
F009BC34: 80a22043                 cmp     %o0, 0x43 ! 'C'
F009BC38: 38800004                 bgu,a   loc_F009BC48
F009BC3C: d0062028                 ld      [%i0+0x28], %o0
F009BC40: 10800012                 ba      locret_F009BC88
F009BC44: b0102004                 mov     4, %i0
F009BC48: d0022284                 ld      [%o0+0x284], %o0
F009BC4C: 80a22000                 cmp     %o0, 0
F009BC50: 32800007                 bne,a   loc_F009BC6C
F009BC54: d2062028                 ld      [%i0+0x28], %o1
F009BC58: 7ffff396                 call    _fpu_ctxalloc
F009BC5C: 01000000                 nop
F009BC60: d2062028                 ld      [%i0+0x28], %o1
F009BC64: d0226284                 st      %o0, [%o1+0x284]
F009BC68: d2062028                 ld      [%i0+0x28], %o1
F009BC6C: 90100019                 mov     %i1, %o0! __dst
F009BC70: d2026284                 ld      [%o1+0x284], %o1! __src
F009BC74: 7ffdad8b                 call    _memcpy
F009BC78: 94102110                 mov     0x110, %o2
F009BC7C: 90102044                 mov     0x44, %o0 ! 'D'
F009BC80: d0268000                 st      %o0, [%i2]
F009BC84: b0102000                 mov     0, %i0
F009BC88: 81c7e008                 ret
F009BC8C: 81e80000                 restore
