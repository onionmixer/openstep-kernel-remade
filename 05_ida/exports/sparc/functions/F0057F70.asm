F0057F70: 9de3bf98                 save    %sp, -0x68, %sp
F0057F74: 173c04ef                 sethi   %hi(_ipc_marequest_table), %o3
F0057F78: 91362004                 srl     %i0, 4, %o0
F0057F7C: 93366008                 srl     %i1, 8, %o1
F0057F80: 90020009                 add     %o0, %o1, %o0
F0057F84: 940e60ff                 and     %i1, 0xFF, %o2
F0057F88: 133c04ef                 sethi   %hi(_ipc_marequest_mask), %o1
F0057F8C: d2026350                 ld      [%o1+%lo(_ipc_marequest_mask)], %o1
F0057F90: 9002000a                 add     %o0, %o2, %o0
F0057F94: 900a0009                 and     %o0, %o1, %o0
F0057F98: d202e360                 ld      [%o3+%lo(_ipc_marequest_table)], %o1
F0057F9C: 912a2003                 sll     %o0, 3, %o0
F0057FA0: a0024008                 add     %o1, %o0, %l0
F0057FA4: d0040000                 ld      [%l0], %o0
F0057FA8: 80a22000                 cmp     %o0, 0
F0057FAC: 12bffffe                 bne     loc_F0057FA4
F0057FB0: 01000000                 nop
F0057FB4: 4000fbbd                 call    _simple_lock_try
F0057FB8: 90100010                 mov     %l0, %o0
F0057FBC: 80a22000                 cmp     %o0, 0
F0057FC0: 02bffff9                 be      loc_F0057FA4
F0057FC4: 01000000                 nop
F0057FC8: d2042004                 ld      [%l0+4], %o1
F0057FCC: 80a26000                 cmp     %o1, 0
F0057FD0: 0280000f                 be      loc_F005800C
F0057FD4: 94042004                 add     %l0, 4, %o2
F0057FD8: d0024000                 ld      [%o1], %o0
F0057FDC: 80a20018                 cmp     %o0, %i0
F0057FE0: 32800007                 bne,a   loc_F0057FFC
F0057FE4: 9402600c                 add     %o1, 0xC, %o2
F0057FE8: d0026004                 ld      [%o1+4], %o0
F0057FEC: 80a20019                 cmp     %o0, %i1
F0057FF0: 22800008                 be,a    loc_F0058010
F0057FF4: d002600c                 ld      [%o1+0xC], %o0
F0057FF8: 9402600c                 add     %o1, 0xC, %o2
F0057FFC: d202600c                 ld      [%o1+0xC], %o1
F0058000: 80a26000                 cmp     %o1, 0
F0058004: 32bffff6                 bne,a   loc_F0057FDC
F0058008: d0024000                 ld      [%o1], %o0
F005800C: d002600c                 ld      [%o1+0xC], %o0
F0058010: d0228000                 st      %o0, [%o2]
F0058014: c0240000                 clr     [%l0]
F0058018: c0226004                 clr     [%o1+4]
F005801C: 81c7e008                 ret
F0058020: 81e80000                 restore
