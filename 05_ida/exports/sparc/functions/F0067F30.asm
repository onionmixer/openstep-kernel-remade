F0067F30: 9de3bf98                 save    %sp, -0x68, %sp
F0067F34: a6102000                 mov     0, %l3
F0067F38: 113c043eb01222a8         set     _k_zone_elemsize, %i0
F0067F40: 293c0447                 sethi   -0xFEEE400, %l4
F0067F44: 2f3c043e                 sethi   -0xFEF0800, %l7
F0067F48: 113c04f0ac122070         set     _k_zone, %l6
F0067F50: 2b3c04f0                 sethi   -0xFEC4000, %l5
F0067F54: 113c04bda4122170         set     unk_F012F570, %l2
F0067F5C: 113c04d1                 sethi   %hi(_kernel_map), %o0
F0067F60: d2022340                 ld      [%o0+%lo(_kernel_map)], %o1
F0067F64: a2102000                 mov     0, %l1
F0067F68: 113c04f0                 sethi   %hi(_kalloc_map), %o0
F0067F6C: d2222038                 st      %o1, [%o0+%lo(_kalloc_map)]
F0067F70: e0044018                 ld      [%l1+%i0], %l0
F0067F74: d005213c                 ld      [%l4+0x13C], %o0
F0067F78: 80a40008                 cmp     %l0, %o0
F0067F7C: 1a800012                 bcc     locret_F0067FC4
F0067F80: 90100012                 mov     %l2, %o0! char *
F0067F84: 9215e2e8                 or      %l7, 0x2E8, %o1! char *
F0067F88: 7ffeb1f8                 call    _sprintf
F0067F8C: 94100010                 mov     %l0, %o2
F0067F90: 90100010                 mov     %l0, %o0
F0067F94: 13000400                 sethi   0x100000, %o1
F0067F98: d405213c                 ld      [%l4+0x13C], %o2
F0067F9C: 98100012                 mov     %l2, %o4
F0067FA0: a404a010                 inc     0x10, %l2
F0067FA4: a604e001                 inc     %l3
F0067FA8: 40003fe4                 call    _zinit
F0067FAC: 96102000                 mov     0, %o3
F0067FB0: d0244016                 st      %o0, [%l1+%l6]
F0067FB4: e02560b0                 st      %l0, [%l5+0xB0]
F0067FB8: 80a4e00f                 cmp     %l3, 0xF
F0067FBC: 04bfffed                 ble     loc_F0067F70
F0067FC0: a2046004                 inc     4, %l1
F0067FC4: 81c7e008                 ret
F0067FC8: 81e80000                 restore
