F0010B5C: 9de3bf98                 save    %sp, -0x68, %sp
F0010B60: 113c04d0                 sethi   %hi(_file_list), %o0
F0010B64: e0022058                 ld      [%o0+%lo(_file_list)], %l0
F0010B68: 90122058                 bset    %lo(_file_list), %o0
F0010B6C: 80a40008                 cmp     %l0, %o0
F0010B70: 02800010                 be      locret_F0010BB0
F0010B74: a4100008                 mov     %o0, %l2
F0010B78: d054200e                 ldsh    [%l0+0xE], %o0
F0010B7C: 80a22000                 cmp     %o0, 0
F0010B80: 04800008                 ble     loc_F0010BA0
F0010B84: e2040000                 ld      [%l0], %l1
F0010B88: 7fffea56                 call    _closef
F0010B8C: 90100010                 mov     %l0, %o0
F0010B90: d054200e                 ldsh    [%l0+0xE], %o0
F0010B94: 80a22000                 cmp     %o0, 0
F0010B98: 14bffffc                 bg      loc_F0010B88
F0010B9C: 01000000                 nop
F0010BA0: a0100011                 mov     %l1, %l0
F0010BA4: 80a40012                 cmp     %l0, %l2
F0010BA8: 32bffff5                 bne,a   loc_F0010B7C
F0010BAC: d054200e                 ldsh    [%l0+0xE], %o0
F0010BB0: 81c7e008                 ret
F0010BB4: 81e80000                 restore
