F0054604: 9de3bf98                 save    %sp, -0x68, %sp
F0054608: 173c04ef                 sethi   %hi(_ipc_hash_global_table), %o3
F005460C: 91362004                 srl     %i0, 4, %o0
F0054610: 95366006                 srl     %i1, 6, %o2
F0054614: 133c04ef                 sethi   %hi(_ipc_hash_global_mask), %o1
F0054618: d20262e0                 ld      [%o1+%lo(_ipc_hash_global_mask)], %o1
F005461C: 9002000a                 add     %o0, %o2, %o0
F0054620: 900a0009                 and     %o0, %o1, %o0
F0054624: d202e2f0                 ld      [%o3+%lo(_ipc_hash_global_table)], %o1
F0054628: 912a2003                 sll     %o0, 3, %o0
F005462C: a0024008                 add     %o1, %o0, %l0
F0054630: d0040000                 ld      [%l0], %o0
F0054634: 80a22000                 cmp     %o0, 0
F0054638: 12bffffe                 bne     loc_F0054630
F005463C: 01000000                 nop
F0054640: 40010a1a                 call    _simple_lock_try
F0054644: 90100010                 mov     %l0, %o0
F0054648: 80a22000                 cmp     %o0, 0
F005464C: 02bffff9                 be      loc_F0054630
F0054650: 01000000                 nop
F0054654: d2042004                 ld      [%l0+4], %o1
F0054658: 80a26000                 cmp     %o1, 0
F005465C: 02800020                 be      loc_F00546DC
F0054660: 01000000                 nop
F0054664: d0026004                 ld      [%o1+4], %o0
F0054668: 80a20019                 cmp     %o0, %i1
F005466C: 12800018                 bne     loc_F00546CC
F0054670: 9402600c                 add     %o1, 0xC, %o2
F0054674: d0026014                 ld      [%o1+0x14], %o0
F0054678: 80a20018                 cmp     %o0, %i0
F005467C: 32800015                 bne,a   loc_F00546D0
F0054680: d202600c                 ld      [%o1+0xC], %o1
F0054684: 10800007                 ba      loc_F00546A0
F0054688: d0026010                 ld      [%o1+0x10], %o0
F005468C: d0228000                 st      %o0, [%o2]
F0054690: d0042004                 ld      [%l0+4], %o0
F0054694: d022600c                 st      %o0, [%o1+0xC]
F0054698: d2242004                 st      %o1, [%l0+4]
F005469C: d0026010                 ld      [%o1+0x10], %o0
F00546A0: d0268000                 st      %o0, [%i2]
F00546A4: 1080000e                 ba      loc_F00546DC
F00546A8: d226c000                 st      %o1, [%i3]
F00546AC: 80a20019                 cmp     %o0, %i1
F00546B0: 32800007                 bne,a   loc_F00546CC
F00546B4: 9402600c                 add     %o1, 0xC, %o2
F00546B8: d0026014                 ld      [%o1+0x14], %o0
F00546BC: 80a20018                 cmp     %o0, %i0
F00546C0: 22bffff3                 be,a    loc_F005468C
F00546C4: d002600c                 ld      [%o1+0xC], %o0
F00546C8: 9402600c                 add     %o1, 0xC, %o2
F00546CC: d202600c                 ld      [%o1+0xC], %o1
F00546D0: 80a26000                 cmp     %o1, 0
F00546D4: 32bffff6                 bne,a   loc_F00546AC
F00546D8: d0026004                 ld      [%o1+4], %o0
F00546DC: c0240000                 clr     [%l0]
F00546E0: 80a00009                 cmp     %g0, %o1
F00546E4: b0402000                 addc    %g0, 0, %i0
F00546E8: 81c7e008                 ret
F00546EC: 81e80000                 restore
