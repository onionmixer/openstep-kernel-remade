F009BB1C: 9de3bf98                 save    %sp, -0x68, %sp
F009BB20: 80a6a043                 cmp     %i2, 0x43 ! 'C'
F009BB24: 38800004                 bgu,a   loc_F009BB34
F009BB28: d0062028                 ld      [%i0+0x28], %o0
F009BB2C: 10800010                 ba      locret_F009BB6C
F009BB30: b0102004                 mov     4, %i0
F009BB34: d0022284                 ld      [%o0+0x284], %o0
F009BB38: 80a22000                 cmp     %o0, 0
F009BB3C: 32800007                 bne,a   loc_F009BB58
F009BB40: d0062028                 ld      [%i0+0x28], %o0
F009BB44: 7ffff3db                 call    _fpu_ctxalloc
F009BB48: 01000000                 nop
F009BB4C: d2062028                 ld      [%i0+0x28], %o1
F009BB50: d0226284                 st      %o0, [%o1+0x284]
F009BB54: d0062028                 ld      [%i0+0x28], %o0
F009BB58: 92100019                 mov     %i1, %o1! __src
F009BB5C: d0022284                 ld      [%o0+0x284], %o0! __dst
F009BB60: 7ffdadd0                 call    _memcpy
F009BB64: 94102110                 mov     0x110, %o2
F009BB68: b0102000                 mov     0, %i0
F009BB6C: 81c7e008                 ret
F009BB70: 81e80000                 restore
