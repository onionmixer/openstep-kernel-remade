F00EF0C8: 9de3bf98                 save    %sp, -0x68, %sp
F00EF0CC: 80a6401a                 cmp     %i1, %i2
F00EF0D0: 12800004                 bne     loc_F00EF0E0
F00EF0D4: 80a66000                 cmp     %i1, 0
F00EF0D8: 10800017                 ba      locret_F00EF134
F00EF0DC: b0102001                 mov     1, %i0
F00EF0E0: 12800004                 bne     loc_F00EF0F0
F00EF0E4: 80a6a000                 cmp     %i2, 0
F00EF0E8: 10800005                 ba      loc_F00EF0FC
F00EF0EC: 9010001a                 mov     %i2, %o0
F00EF0F0: 32800008                 bne,a   loc_F00EF110
F00EF0F4: d24e4000                 ldsb    [%i1], %o1! __s2
F00EF0F8: 90100019                 mov     %i1, %o0! __s
F00EF0FC: 7ffc60cf                 call    _strlen
F00EF100: 01000000                 nop
F00EF104: 80a00008                 cmp     %g0, %o0
F00EF108: 1080000b                 ba      locret_F00EF134
F00EF10C: b0603fff                 subc    %g0, -1, %i0
F00EF110: d04e8000                 ldsb    [%i2], %o0
F00EF114: 80a24008                 cmp     %o1, %o0
F00EF118: 12800007                 bne     locret_F00EF134
F00EF11C: b0102000                 mov     0, %i0
F00EF120: 90100019                 mov     %i1, %o0! __s1
F00EF124: 7ffc6422                 call    _strcmp
F00EF128: 9210001a                 mov     %i2, %o1
F00EF12C: 80a00008                 cmp     %g0, %o0
F00EF130: b0603fff                 subc    %g0, -1, %i0
F00EF134: 81c7e008                 ret
F00EF138: 81e80000                 restore
