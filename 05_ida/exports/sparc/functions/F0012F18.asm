F0012F18: 9de3bf80                 save    %sp, -0x80, %sp
F0012F1C: 7ffff294                 call    _suser
F0012F20: 01000000                 nop
F0012F24: 80a22000                 cmp     %o0, 0
F0012F28: 02800017                 be      locret_F0012F84
F0012F2C: 01000000                 nop
F0012F30: 40000017                 call    _getthetime
F0012F34: 9007bff0                 add     %fp, var_10, %o0
F0012F38: d4060000                 ld      [%i0], %o2
F0012F3C: d607bff0                 ld      [%fp+var_10], %o3
F0012F40: 133c04d4                 sethi   %hi(_boottime), %o1
F0012F44: d0026168                 ld      [%o1+%lo(_boottime)], %o0
F0012F48: 9422800b                 sub     %o2, %o3, %o2
F0012F4C: 9002000a                 add     %o0, %o2, %o0
F0012F50: d0226168                 st      %o0, [%o1+%lo(_boottime)]
F0012F54: 92126168                 bset    %lo(_boottime), %o1
F0012F58: c0226004                 clr     [%o1+4]
F0012F5C: d4060000                 ld      [%i0], %o2
F0012F60: d427bfe8                 st      %o2, [%fp+var_18]
F0012F64: d2062004                 ld      [%i0+4], %o1
F0012F68: 113c04d4                 sethi   %hi(dword_F0135174), %o0
F0012F6C: d0022174                 ld      [%o0+%lo(dword_F0135174)], %o0
F0012F70: d227bfec                 st      %o1, [%fp+var_14]
F0012F74: d427bfe0                 st      %o2, [%fp+var_20]
F0012F78: d227bfe4                 st      %o1, [%fp+var_1C]
F0012F7C: 40015af1                 call    _host_set_time
F0012F80: 9207bfe0                 add     %fp, var_20, %o1
F0012F84: 81c7e008                 ret
F0012F88: 81e80000                 restore
