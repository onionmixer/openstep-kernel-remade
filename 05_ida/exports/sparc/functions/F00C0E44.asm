F00C0E44: 9de3bf98                 save    %sp, -0x68, %sp
F00C0E48: f027a044                 st      %i0, [%fp+arg_44]
F00C0E4C: 4000002a                 call    sub_F00C0EF4
F00C0E50: 9007a044                 add     %fp, arg_44, %o0
F00C0E54: 92920000                 orcc    %o0, %g0, %o1
F00C0E58: 02800013                 be      locret_F00C0EA4
F00C0E5C: b0100019                 mov     %i1, %i0
F00C0E60: d0026018                 ld      [%o1+0x18], %o0
F00C0E64: 80a22000                 cmp     %o0, 0
F00C0E68: 22800007                 be,a    loc_F00C0E84
F00C0E6C: d207a044                 ld      [%fp+arg_44], %o1
F00C0E70: d0026014                 ld      [%o1+0x14], %o0
F00C0E74: 80a22000                 cmp     %o0, 0
F00C0E78: 12800007                 bne     loc_F00C0E94
F00C0E7C: 113c0483                 sethi   -0xFEDF400, %o0
F00C0E80: d207a044                 ld      [%fp+arg_44], %o1
F00C0E84: 912e6018                 sll     %i1, 24, %o0
F00C0E88: 40000009                 call    _cninput
F00C0E8C: 913a2018                 sra     %o0, 24, %o0
F00C0E90: 30800005                 ba,a    locret_F00C0EA4
F00C0E94: 90122258                 bset    0x258, %o0
F00C0E98: d407a044                 ld      [%fp+arg_44], %o2
F00C0E9C: 40001496                 call    _IOLog
F00C0EA0: 920e20ff                 and     %i0, 0xFF, %o1
F00C0EA4: 81c7e008                 ret
F00C0EA8: 81e80000                 restore
