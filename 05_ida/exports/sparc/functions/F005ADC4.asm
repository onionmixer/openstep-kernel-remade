F005ADC4: 9de3bf98                 save    %sp, -0x68, %sp
F005ADC8: 80a60019                 cmp     %i0, %i1
F005ADCC: 0280004b                 be      loc_F005AEF8
F005ADD0: a0100019                 mov     %i1, %l0
F005ADD4: d0060000                 ld      [%i0], %o0
F005ADD8: 80a22000                 cmp     %o0, 0
F005ADDC: 12bffffe                 bne     loc_F005ADD4
F005ADE0: 01000000                 nop
F005ADE4: 4000f031                 call    _simple_lock_try
F005ADE8: 90100018                 mov     %i0, %o0
F005ADEC: 80a22000                 cmp     %o0, 0
F005ADF0: 02bffff9                 be      loc_F005ADD4
F005ADF4: 01000000                 nop
F005ADF8: 4000f02c                 call    _simple_lock_try
F005ADFC: 90100019                 mov     %i1, %o0
F005AE00: 80a22000                 cmp     %o0, 0
F005AE04: 0280000f                 be      loc_F005AE40
F005AE08: 01000000                 nop
F005AE0C: d0066008                 ld      [%i1+8], %o0
F005AE10: 80a22000                 cmp     %o0, 0
F005AE14: 36800046                 bge,a   loc_F005AF2C
F005AE18: d0066004                 ld      [%i1+4], %o0
F005AE1C: d0066010                 ld      [%i1+0x10], %o0
F005AE20: 80a22000                 cmp     %o0, 0
F005AE24: 32800042                 bne,a   loc_F005AF2C
F005AE28: d0066004                 ld      [%i1+4], %o0
F005AE2C: d006600c                 ld      [%i1+0xC], %o0
F005AE30: 80a22000                 cmp     %o0, 0
F005AE34: 2280003e                 be,a    loc_F005AF2C
F005AE38: d0066004                 ld      [%i1+4], %o0
F005AE3C: c0264000                 clr     [%i1]
F005AE40: c0260000                 clr     [%i0]
F005AE44: 113c04efa2122308         set     _ipc_port_multiple_lock_data, %l1
F005AE4C: d0044000                 ld      [%l1], %o0
F005AE50: 80a22000                 cmp     %o0, 0
F005AE54: 12bffffe                 bne     loc_F005AE4C
F005AE58: 01000000                 nop
F005AE5C: 4000f013                 call    _simple_lock_try
F005AE60: 90100011                 mov     %l1, %o0
F005AE64: 80a22000                 cmp     %o0, 0
F005AE68: 02bffff9                 be      loc_F005AE4C
F005AE6C: 01000000                 nop
F005AE70: d0040000                 ld      [%l0], %o0
F005AE74: 80a22000                 cmp     %o0, 0
F005AE78: 12bffffe                 bne     loc_F005AE70
F005AE7C: 01000000                 nop
F005AE80: 4000f00a                 call    _simple_lock_try
F005AE84: 90100010                 mov     %l0, %o0
F005AE88: 80a22000                 cmp     %o0, 0
F005AE8C: 02bffff9                 be      loc_F005AE70
F005AE90: 01000000                 nop
F005AE94: d0042008                 ld      [%l0+8], %o0
F005AE98: 80a22000                 cmp     %o0, 0
F005AE9C: 1680000c                 bge     loc_F005AECC
F005AEA0: 80a60010                 cmp     %i0, %l0
F005AEA4: d0042010                 ld      [%l0+0x10], %o0
F005AEA8: 80a22000                 cmp     %o0, 0
F005AEAC: 12800008                 bne     loc_F005AECC
F005AEB0: 80a60010                 cmp     %i0, %l0
F005AEB4: d004200c                 ld      [%l0+0xC], %o0
F005AEB8: 80a22000                 cmp     %o0, 0
F005AEBC: 02800004                 be      loc_F005AECC
F005AEC0: 80a60010                 cmp     %i0, %l0
F005AEC4: 10bfffeb                 ba      loc_F005AE70
F005AEC8: a0100008                 mov     %o0, %l0
F005AECC: 1280000d                 bne     loc_F005AF00
F005AED0: 113c04ef                 sethi   %hi(_ipc_port_multiple_lock_data), %o0
F005AED4: c0222308                 clr     [%o0+%lo(_ipc_port_multiple_lock_data)]
F005AED8: 80a66000                 cmp     %i1, 0
F005AEDC: 22800021                 be,a    locret_F005AF60
F005AEE0: b0102001                 mov     1, %i0
F005AEE4: d006600c                 ld      [%i1+0xC], %o0
F005AEE8: c0264000                 clr     [%i1]
F005AEEC: b2920000                 orcc    %o0, %g0, %i1
F005AEF0: 32bffffe                 bne,a   loc_F005AEE8
F005AEF4: d006600c                 ld      [%i1+0xC], %o0
F005AEF8: 1080001a                 ba      locret_F005AF60
F005AEFC: b0102001                 mov     1, %i0
F005AF00: d0060000                 ld      [%i0], %o0
F005AF04: 80a22000                 cmp     %o0, 0
F005AF08: 12bffffe                 bne     loc_F005AF00
F005AF0C: 01000000                 nop
F005AF10: 4000efe6                 call    _simple_lock_try
F005AF14: 90100018                 mov     %i0, %o0
F005AF18: 80a22000                 cmp     %o0, 0
F005AF1C: 02bffff9                 be      loc_F005AF00
F005AF20: 113c04ef                 sethi   %hi(_ipc_port_multiple_lock_data), %o0
F005AF24: c0222308                 clr     [%o0+%lo(_ipc_port_multiple_lock_data)]
F005AF28: d0066004                 ld      [%i1+4], %o0
F005AF2C: 90022001                 inc     %o0
F005AF30: d0266004                 st      %o0, [%i1+4]
F005AF34: 80a60010                 cmp     %i0, %l0
F005AF38: 02800008                 be      loc_F005AF58
F005AF3C: f226200c                 st      %i1, [%i0+0xC]
F005AF40: d006200c                 ld      [%i0+0xC], %o0
F005AF44: c0260000                 clr     [%i0]
F005AF48: b0100008                 mov     %o0, %i0
F005AF4C: 80a60010                 cmp     %i0, %l0
F005AF50: 32bffffd                 bne,a   loc_F005AF44
F005AF54: d006200c                 ld      [%i0+0xC], %o0
F005AF58: c0240000                 clr     [%l0]
F005AF5C: b0102000                 mov     0, %i0
F005AF60: 81c7e008                 ret
F005AF64: 81e80000                 restore
