F0030F48: 9de3bf98                 save    %sp, -0x68, %sp
F0030F4C: c2060000                 ld      [%i0], %g1
F0030F50: 9e102000                 mov     0, %o7
F0030F54: f2064000                 ld      [%i1], %i1
F0030F58: 88102003                 mov     3, %g4
F0030F5C: 80a04018                 cmp     %g1, %i0
F0030F60: 02800041                 be      locret_F0031064
F0030F64: f606c000                 ld      [%i3], %i3
F0030F68: 852f2010                 sll     %i4, 16, %g2
F0030F6C: 9130a010                 srl     %g2, 16, %o0
F0030F70: 852ea010                 sll     %i2, 16, %g2
F0030F74: b930a010                 srl     %g2, 16, %i4
F0030F78: 153c0000                 sethi   -0x10000000, %o2
F0030F7C: 13380000                 sethi   -0x20000000, %o1
F0030F80: ba0f6001                 and     %i5, 1, %i5
F0030F84: c4106018                 lduh    [%g1+0x18], %g2
F0030F88: 80a08008                 cmp     %g2, %o0
F0030F8C: 32800033                 bne,a   loc_F0031058
F0030F90: c2004000                 ld      [%g1], %g1
F0030F94: c4006014                 ld      [%g1+0x14], %g2
F0030F98: 80a0a000                 cmp     %g2, 0
F0030F9C: 02800009                 be      loc_F0030FC0
F0030FA0: 86102000                 mov     0, %g3
F0030FA4: 80a6e000                 cmp     %i3, 0
F0030FA8: 02800009                 be      loc_F0030FCC
F0030FAC: 80a0801b                 cmp     %g2, %i3
F0030FB0: 3280002a                 bne,a   loc_F0031058
F0030FB4: c2004000                 ld      [%g1], %g1
F0030FB8: 10800007                 ba      loc_F0030FD4
F0030FBC: f400600c                 ld      [%g1+0xC], %i2
F0030FC0: 80a6e000                 cmp     %i3, 0
F0030FC4: 22800004                 be,a    loc_F0030FD4
F0030FC8: f400600c                 ld      [%g1+0xC], %i2
F0030FCC: 86102001                 mov     1, %g3
F0030FD0: f400600c                 ld      [%g1+0xC], %i2
F0030FD4: 80a6a000                 cmp     %i2, 0
F0030FD8: 02800011                 be      loc_F003101C
F0030FDC: 80a66000                 cmp     %i1, 0
F0030FE0: 22800012                 be,a    loc_F0031028
F0030FE4: 8600e001                 inc     %g3
F0030FE8: c4106010                 lduh    [%g1+0x10], %g2
F0030FEC: 80a0801c                 cmp     %g2, %i4
F0030FF0: 3280001a                 bne,a   loc_F0031058
F0030FF4: c2004000                 ld      [%g1], %g1
F0030FF8: 840e800a                 and     %i2, %o2, %g2
F0030FFC: 80a08009                 cmp     %g2, %o1
F0031000: 22800016                 be,a    loc_F0031058
F0031004: c2004000                 ld      [%g1], %g1
F0031008: 80a68019                 cmp     %i2, %i1
F003100C: 32800013                 bne,a   loc_F0031058
F0031010: c2004000                 ld      [%g1], %g1
F0031014: 10800006                 ba      loc_F003102C
F0031018: 80a0e000                 cmp     %g3, 0
F003101C: 02800004                 be      loc_F003102C
F0031020: 80a0e000                 cmp     %g3, 0
F0031024: 8600e001                 inc     %g3
F0031028: 80a0e000                 cmp     %g3, 0
F003102C: 02800004                 be      loc_F003103C
F0031030: 80a76000                 cmp     %i5, 0
F0031034: 22800009                 be,a    loc_F0031058
F0031038: c2004000                 ld      [%g1], %g1
F003103C: 80a0c004                 cmp     %g3, %g4
F0031040: 36800006                 bge,a   loc_F0031058
F0031044: c2004000                 ld      [%g1], %g1
F0031048: 8890c000                 orcc    %g3, %g0, %g4
F003104C: 02800006                 be      locret_F0031064
F0031050: 9e100001                 mov     %g1, %o7
F0031054: c2004000                 ld      [%g1], %g1
F0031058: 80a04018                 cmp     %g1, %i0
F003105C: 32bfffcb                 bne,a   loc_F0030F88
F0031060: c4106018                 lduh    [%g1+0x18], %g2
F0031064: 81c7e008                 ret
F0031068: 91e8000f                 restore %g0, %o7, %o0
