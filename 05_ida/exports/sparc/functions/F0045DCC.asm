F0045DCC: 9de3bf98                 save    %sp, -0x68, %sp
F0045DD0: 1080001a                 ba      loc_F0045E38
F0045DD4: a0100018                 mov     %i0, %l0
F0045DD8: d0042014                 ld      [%l0+0x14], %o0
F0045DDC: 9402001a                 add     %o0, %i2, %o2! size_t
F0045DE0: 80a2a000                 cmp     %o2, 0
F0045DE4: 04800008                 ble     loc_F0045E04
F0045DE8: d4242014                 st      %o2, [%l0+0x14]
F0045DEC: d004200c                 ld      [%l0+0xC], %o0! void *
F0045DF0: 40013b48                 call    _bcopy
F0045DF4: 92100019                 mov     %i1, %o1
F0045DF8: d0042014                 ld      [%l0+0x14], %o0
F0045DFC: b2064008                 add     %i1, %o0, %i1
F0045E00: b4268008                 sub     %i2, %o0, %i2
F0045E04: d0042010                 ld      [%l0+0x10], %o0
F0045E08: 80a22000                 cmp     %o0, 0
F0045E0C: 02800018                 be      locret_F0045E6C
F0045E10: b0102000                 mov     0, %i0
F0045E14: d2020000                 ld      [%o0], %o1
F0045E18: 80a26000                 cmp     %o1, 0
F0045E1C: 02800014                 be      locret_F0045E6C
F0045E20: d2242010                 st      %o1, [%l0+0x10]
F0045E24: d0026004                 ld      [%o1+4], %o0
F0045E28: 90024008                 add     %o1, %o0, %o0
F0045E2C: d024200c                 st      %o0, [%l0+0xC]
F0045E30: d0526008                 ldsh    [%o1+8], %o0
F0045E34: d0242014                 st      %o0, [%l0+0x14]
F0045E38: d0042014                 ld      [%l0+0x14], %o0
F0045E3C: 9022001a                 sub     %o0, %i2, %o0
F0045E40: 80a22000                 cmp     %o0, 0
F0045E44: 06bfffe5                 bl      loc_F0045DD8
F0045E48: d0242014                 st      %o0, [%l0+0x14]
F0045E4C: 92100019                 mov     %i1, %o1! void *
F0045E50: d004200c                 ld      [%l0+0xC], %o0! void *
F0045E54: 40013b2f                 call    _bcopy
F0045E58: 9410001a                 mov     %i2, %o2
F0045E5C: d004200c                 ld      [%l0+0xC], %o0
F0045E60: b0102001                 mov     1, %i0
F0045E64: 9002001a                 add     %o0, %i2, %o0
F0045E68: d024200c                 st      %o0, [%l0+0xC]
F0045E6C: 81c7e008                 ret
F0045E70: 81e80000                 restore
