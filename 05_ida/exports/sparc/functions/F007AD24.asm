F007AD24: 9de3bf98                 save    %sp, -0x68, %sp
F007AD28: 40007007                 call    _curipl
F007AD2C: f0060000                 ld      [%i0], %i0
F007AD30: 80a22000                 cmp     %o0, 0
F007AD34: 1280000c                 bne     loc_F007AD64
F007AD38: 01000000                 nop
F007AD3C: 7fffb15d                 call    _task_self
F007AD40: 01000000                 nop
F007AD44: d2062008                 ld      [%i0+8], %o1
F007AD48: 80a20009                 cmp     %o0, %o1
F007AD4C: 12800006                 bne     loc_F007AD64
F007AD50: 01000000                 nop
F007AD54: 9fc64000                 call    %i1
F007AD58: 9010001a                 mov     %i2, %o0
F007AD5C: 10800031                 ba      locret_F007AE20
F007AD60: b0102000                 mov     0, %i0
F007AD64: 40006f89                 call    _splusclock
F007AD68: 01000000                 nop
F007AD6C: a0100008                 mov     %o0, %l0
F007AD70: d0060000                 ld      [%i0], %o0
F007AD74: 80a22000                 cmp     %o0, 0
F007AD78: 12bffffe                 bne     loc_F007AD70
F007AD7C: 01000000                 nop
F007AD80: 4000704a                 call    _simple_lock_try
F007AD84: 90100018                 mov     %i0, %o0
F007AD88: 80a22000                 cmp     %o0, 0
F007AD8C: 02bffff9                 be      loc_F007AD70
F007AD90: 9406203c                 add     %i0, 0x3C, %o2 ! '<'
F007AD94: d006203c                 ld      [%i0+0x3C], %o0
F007AD98: 80a28008                 cmp     %o2, %o0
F007AD9C: 12800007                 bne     loc_F007ADB8
F007ADA0: 92100008                 mov     %o0, %o1
F007ADA4: c0260000                 clr     [%i0]
F007ADA8: 40006fdf                 call    _splx
F007ADAC: 90100010                 mov     %l0, %o0
F007ADB0: 1080001c                 ba      locret_F007AE20
F007ADB4: b0102006                 mov     6, %i0
F007ADB8: d0026008                 ld      [%o1+8], %o0
F007ADBC: 80a28008                 cmp     %o2, %o0
F007ADC0: 32800003                 bne,a   loc_F007ADCC
F007ADC4: d422200c                 st      %o2, [%o0+0xC]
F007ADC8: d0262040                 st      %o0, [%i0+0x40]
F007ADCC: d026203c                 st      %o0, [%i0+0x3C]
F007ADD0: f2224000                 st      %i1, [%o1]
F007ADD4: f4226004                 st      %i2, [%o1+4]
F007ADD8: d4062038                 ld      [%i0+0x38], %o2
F007ADDC: 90062034                 add     %i0, 0x34, %o0 ! '4'
F007ADE0: 80a2000a                 cmp     %o0, %o2
F007ADE4: 32800003                 bne,a   loc_F007ADF0
F007ADE8: d222a008                 st      %o1, [%o2+8]
F007ADEC: d2262034                 st      %o1, [%i0+0x34]
F007ADF0: d422600c                 st      %o2, [%o1+0xC]
F007ADF4: 90062034                 add     %i0, 0x34, %o0 ! '4'
F007ADF8: d0226008                 st      %o0, [%o1+8]
F007ADFC: d2262038                 st      %o1, [%i0+0x38]
F007AE00: c0260000                 clr     [%i0]
F007AE04: 40006fc8                 call    _splx
F007AE08: 90100010                 mov     %l0, %o0
F007AE0C: 113c01eb                 sethi   %hi(sub_F007AE28), %o0
F007AE10: d206200c                 ld      [%i0+0xC], %o1
F007AE14: 7fffef1a                 call    _calloutDispatchUnique
F007AE18: 90122228                 bset    %lo(sub_F007AE28), %o0
F007AE1C: b0102000                 mov     0, %i0
F007AE20: 81c7e008                 ret
F007AE24: 81e80000                 restore
