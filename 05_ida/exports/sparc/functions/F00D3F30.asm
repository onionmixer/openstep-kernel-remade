F00D3F30: 9de3bf90                 save    %sp, -0x70, %sp
F00D3F34: f2062188                 ld      [%i0+0x188], %i1
F00D3F38: b2067fff                 inc     -1, %i1
F00D3F3C: 80a67fff                 cmp     %i1, -1
F00D3F40: 02800029                 be      loc_F00D3FE4
F00D3F44: c6062180                 ld      [%i0+0x180], %g3
F00D3F48: 852e6002                 sll     %i1, 2, %g2
F00D3F4C: 84008019                 add     %g2, %i1, %g2
F00D3F50: 8528a002                 sll     %g2, 2, %g2
F00D3F54: b0008003                 add     %g2, %g3, %i0
F00D3F58: c4060000                 ld      [%i0], %g2
F00D3F5C: 80a0a000                 cmp     %g2, 0
F00D3F60: 2280001e                 be,a    loc_F00D3FD8
F00D3F64: b2067fff                 inc     -1, %i1
F00D3F68: c416200c                 lduh    [%i0+0xC], %g2
F00D3F6C: c6568000                 ldsh    [%i2], %g3
F00D3F70: 8528a010                 sll     %g2, 16, %g2
F00D3F74: 8538a010                 sra     %g2, 16, %g2
F00D3F78: 80a0c002                 cmp     %g3, %g2
F00D3F7C: 26800017                 bl,a    loc_F00D3FD8
F00D3F80: b2067fff                 inc     -1, %i1
F00D3F84: c416200e                 lduh    [%i0+0xE], %g2
F00D3F88: 8528a010                 sll     %g2, 16, %g2
F00D3F8C: 8538a010                 sra     %g2, 16, %g2
F00D3F90: 80a0c002                 cmp     %g3, %g2
F00D3F94: 36800011                 bge,a   loc_F00D3FD8
F00D3F98: b2067fff                 inc     -1, %i1
F00D3F9C: c4162010                 lduh    [%i0+0x10], %g2
F00D3FA0: c656a002                 ldsh    [%i2+2], %g3
F00D3FA4: 8528a010                 sll     %g2, 16, %g2
F00D3FA8: 8538a010                 sra     %g2, 16, %g2
F00D3FAC: 80a0c002                 cmp     %g3, %g2
F00D3FB0: 2680000a                 bl,a    loc_F00D3FD8
F00D3FB4: b2067fff                 inc     -1, %i1
F00D3FB8: c4162012                 lduh    [%i0+0x12], %g2
F00D3FBC: 8528a010                 sll     %g2, 16, %g2
F00D3FC0: 8538a010                 sra     %g2, 16, %g2
F00D3FC4: 80a0c002                 cmp     %g3, %g2
F00D3FC8: 36800004                 bge,a   loc_F00D3FD8
F00D3FCC: b2067fff                 inc     -1, %i1
F00D3FD0: 10800006                 ba      locret_F00D3FE8
F00D3FD4: b0100019                 mov     %i1, %i0
F00D3FD8: 80a67fff                 cmp     %i1, -1
F00D3FDC: 12bfffdf                 bne     loc_F00D3F58
F00D3FE0: b0063fec                 inc     -0x14, %i0
F00D3FE4: b0103fff                 mov     -1, %i0
F00D3FE8: 81c7e008                 ret
F00D3FEC: 81e80000                 restore
