F0045F00: 9de3bf98                 save    %sp, -0x68, %sp
F0045F04: 1080001a                 ba      loc_F0045F6C
F0045F08: a0100018                 mov     %i0, %l0
F0045F0C: d0042014                 ld      [%l0+0x14], %o0! void *
F0045F10: 9402001a                 add     %o0, %i2, %o2! size_t
F0045F14: 80a2a000                 cmp     %o2, 0
F0045F18: 04800008                 ble     loc_F0045F38
F0045F1C: d4242014                 st      %o2, [%l0+0x14]
F0045F20: d204200c                 ld      [%l0+0xC], %o1! void *
F0045F24: 40013afb                 call    _bcopy
F0045F28: 90100019                 mov     %i1, %o0
F0045F2C: d0042014                 ld      [%l0+0x14], %o0
F0045F30: b2064008                 add     %i1, %o0, %i1
F0045F34: b4268008                 sub     %i2, %o0, %i2
F0045F38: d0042010                 ld      [%l0+0x10], %o0
F0045F3C: 80a22000                 cmp     %o0, 0
F0045F40: 02800018                 be      locret_F0045FA0
F0045F44: b0102000                 mov     0, %i0
F0045F48: d2020000                 ld      [%o0], %o1
F0045F4C: 80a26000                 cmp     %o1, 0
F0045F50: 02800014                 be      locret_F0045FA0
F0045F54: d2242010                 st      %o1, [%l0+0x10]
F0045F58: d0026004                 ld      [%o1+4], %o0
F0045F5C: 90024008                 add     %o1, %o0, %o0
F0045F60: d024200c                 st      %o0, [%l0+0xC]
F0045F64: d0526008                 ldsh    [%o1+8], %o0
F0045F68: d0242014                 st      %o0, [%l0+0x14]
F0045F6C: d0042014                 ld      [%l0+0x14], %o0
F0045F70: 9022001a                 sub     %o0, %i2, %o0
F0045F74: 80a22000                 cmp     %o0, 0
F0045F78: 06bfffe5                 bl      loc_F0045F0C
F0045F7C: d0242014                 st      %o0, [%l0+0x14]
F0045F80: 90100019                 mov     %i1, %o0! void *
F0045F84: d204200c                 ld      [%l0+0xC], %o1! void *
F0045F88: 40013ae2                 call    _bcopy
F0045F8C: 9410001a                 mov     %i2, %o2
F0045F90: d004200c                 ld      [%l0+0xC], %o0
F0045F94: b0102001                 mov     1, %i0
F0045F98: 9002001a                 add     %o0, %i2, %o0
F0045F9C: d024200c                 st      %o0, [%l0+0xC]
F0045FA0: 81c7e008                 ret
F0045FA4: 81e80000                 restore
