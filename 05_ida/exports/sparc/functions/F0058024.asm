F0058024: 9de3bf98                 save    %sp, -0x68, %sp
F0058028: 173c04ef                 sethi   %hi(_ipc_marequest_table), %o3
F005802C: 91362004                 srl     %i0, 4, %o0
F0058030: 93366008                 srl     %i1, 8, %o1
F0058034: 90020009                 add     %o0, %o1, %o0
F0058038: 940e60ff                 and     %i1, 0xFF, %o2
F005803C: 133c04ef                 sethi   %hi(_ipc_marequest_mask), %o1
F0058040: d2026350                 ld      [%o1+%lo(_ipc_marequest_mask)], %o1
F0058044: 9002000a                 add     %o0, %o2, %o0
F0058048: 900a0009                 and     %o0, %o1, %o0
F005804C: d202e360                 ld      [%o3+%lo(_ipc_marequest_table)], %o1
F0058050: 912a2003                 sll     %o0, 3, %o0
F0058054: a0024008                 add     %o1, %o0, %l0
F0058058: d0040000                 ld      [%l0], %o0
F005805C: 80a22000                 cmp     %o0, 0
F0058060: 12bffffe                 bne     loc_F0058058
F0058064: 01000000                 nop
F0058068: 4000fb90                 call    _simple_lock_try
F005806C: 90100010                 mov     %l0, %o0
F0058070: 80a22000                 cmp     %o0, 0
F0058074: 02bffff9                 be      loc_F0058058
F0058078: 01000000                 nop
F005807C: e2042004                 ld      [%l0+4], %l1
F0058080: 80a46000                 cmp     %l1, 0
F0058084: 0280000f                 be      loc_F00580C0
F0058088: 92042004                 add     %l0, 4, %o1
F005808C: d0044000                 ld      [%l1], %o0
F0058090: 80a20018                 cmp     %o0, %i0
F0058094: 32800007                 bne,a   loc_F00580B0
F0058098: 9204600c                 add     %l1, 0xC, %o1
F005809C: d0046004                 ld      [%l1+4], %o0
F00580A0: 80a20019                 cmp     %o0, %i1
F00580A4: 02800008                 be      loc_F00580C4
F00580A8: 173c04ef                 sethi   -0xFEC4400, %o3
F00580AC: 9204600c                 add     %l1, 0xC, %o1
F00580B0: e204600c                 ld      [%l1+0xC], %l1
F00580B4: 80a46000                 cmp     %l1, 0
F00580B8: 32bffff6                 bne,a   loc_F0058090
F00580BC: d0044000                 ld      [%l1], %o0
F00580C0: 173c04ef                 sethi   -0xFEC4400, %o3
F00580C4: d004600c                 ld      [%l1+0xC], %o0
F00580C8: 940ea0ff                 and     %i2, 0xFF, %o2
F00580CC: d0224000                 st      %o0, [%o1]
F00580D0: c0240000                 clr     [%l0]
F00580D4: f4246004                 st      %i2, [%l1+4]
F00580D8: 91362004                 srl     %i0, 4, %o0
F00580DC: 9336a008                 srl     %i2, 8, %o1
F00580E0: 90020009                 add     %o0, %o1, %o0
F00580E4: 133c04ef                 sethi   %hi(_ipc_marequest_mask), %o1
F00580E8: d2026350                 ld      [%o1+%lo(_ipc_marequest_mask)], %o1
F00580EC: 9002000a                 add     %o0, %o2, %o0
F00580F0: 900a0009                 and     %o0, %o1, %o0
F00580F4: d202e360                 ld      [%o3+0x360], %o1
F00580F8: 912a2003                 sll     %o0, 3, %o0
F00580FC: a0024008                 add     %o1, %o0, %l0
F0058100: d0040000                 ld      [%l0], %o0
F0058104: 80a22000                 cmp     %o0, 0
F0058108: 12bffffe                 bne     loc_F0058100
F005810C: 01000000                 nop
F0058110: 4000fb66                 call    _simple_lock_try
F0058114: 90100010                 mov     %l0, %o0
F0058118: 80a22000                 cmp     %o0, 0
F005811C: 02bffff9                 be      loc_F0058100
F0058120: 01000000                 nop
F0058124: d0042004                 ld      [%l0+4], %o0
F0058128: d024600c                 st      %o0, [%l1+0xC]
F005812C: e2242004                 st      %l1, [%l0+4]
F0058130: c0240000                 clr     [%l0]
F0058134: 81c7e008                 ret
F0058138: 81e80000                 restore
