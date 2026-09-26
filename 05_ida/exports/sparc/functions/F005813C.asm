F005813C: 9de3bf98                 save    %sp, -0x68, %sp
F0058140: e2060000                 ld      [%i0], %l1
F0058144: a6102000                 mov     0, %l3
F0058148: a0046008                 add     %l1, 8, %l0
F005814C: d0040000                 ld      [%l0], %o0
F0058150: 80a22000                 cmp     %o0, 0
F0058154: 12bffffe                 bne     loc_F005814C
F0058158: 01000000                 nop
F005815C: 4000fb53                 call    _simple_lock_try
F0058160: 90100010                 mov     %l0, %o0
F0058164: 80a22000                 cmp     %o0, 0
F0058168: 02bffff9                 be      loc_F005814C
F005816C: 01000000                 nop
F0058170: e4062004                 ld      [%i0+4], %l2
F0058174: 80a4a000                 cmp     %l2, 0
F0058178: 0280003c                 be      loc_F0058268
F005817C: e8062008                 ld      [%i0+8], %l4
F0058180: 173c04ef                 sethi   %hi(_ipc_marequest_table), %o3
F0058184: 91346004                 srl     %l1, 4, %o0
F0058188: 9334a008                 srl     %l2, 8, %o1
F005818C: 90020009                 add     %o0, %o1, %o0
F0058190: 940ca0ff                 and     %l2, 0xFF, %o2
F0058194: 133c04ef                 sethi   %hi(_ipc_marequest_mask), %o1
F0058198: d2026350                 ld      [%o1+%lo(_ipc_marequest_mask)], %o1
F005819C: 9002000a                 add     %o0, %o2, %o0
F00581A0: 900a0009                 and     %o0, %o1, %o0
F00581A4: d202e360                 ld      [%o3+%lo(_ipc_marequest_table)], %o1
F00581A8: 912a2003                 sll     %o0, 3, %o0
F00581AC: a0024008                 add     %o1, %o0, %l0
F00581B0: d0040000                 ld      [%l0], %o0
F00581B4: 80a22000                 cmp     %o0, 0
F00581B8: 12bffffe                 bne     loc_F00581B0
F00581BC: 01000000                 nop
F00581C0: 4000fb3a                 call    _simple_lock_try
F00581C4: 90100010                 mov     %l0, %o0
F00581C8: 80a22000                 cmp     %o0, 0
F00581CC: 02bffff9                 be      loc_F00581B0
F00581D0: 01000000                 nop
F00581D4: d2042004                 ld      [%l0+4], %o1
F00581D8: 80a26000                 cmp     %o1, 0
F00581DC: 0280000f                 be      loc_F0058218
F00581E0: 94042004                 add     %l0, 4, %o2
F00581E4: d0024000                 ld      [%o1], %o0
F00581E8: 80a20011                 cmp     %o0, %l1
F00581EC: 32800007                 bne,a   loc_F0058208
F00581F0: 9402600c                 add     %o1, 0xC, %o2
F00581F4: d0026004                 ld      [%o1+4], %o0
F00581F8: 80a20012                 cmp     %o0, %l2
F00581FC: 22800008                 be,a    loc_F005821C
F0058200: d002600c                 ld      [%o1+0xC], %o0
F0058204: 9402600c                 add     %o1, 0xC, %o2
F0058208: d202600c                 ld      [%o1+0xC], %o1
F005820C: 80a26000                 cmp     %o1, 0
F0058210: 32bffff6                 bne,a   loc_F00581E8
F0058214: d0024000                 ld      [%o1], %o0
F0058218: d002600c                 ld      [%o1+0xC], %o0
F005821C: d0228000                 st      %o0, [%o2]
F0058220: c0240000                 clr     [%l0]
F0058224: d004600c                 ld      [%l1+0xC], %o0
F0058228: 80a22000                 cmp     %o0, 0
F005822C: 0280000e                 be      loc_F0058264
F0058230: 90100011                 mov     %l1, %o0
F0058234: 7fffee02                 call    _ipc_entry_lookup
F0058238: 92100012                 mov     %l2, %o1
F005823C: 80a52000                 cmp     %l4, 0
F0058240: d4020000                 ld      [%o0], %o2
F0058244: 13000800                 sethi   0x200000, %o1
F0058248: 922a8009                 andn    %o2, %o1, %o1
F005824C: 12800007                 bne     loc_F0058268
F0058250: d2220000                 st      %o1, [%o0]
F0058254: 40000b7a                 call    _ipc_port_copy_send
F0058258: d0046044                 ld      [%l1+0x44], %o0
F005825C: 10800003                 ba      loc_F0058268
F0058260: a6100008                 mov     %o0, %l3
F0058264: a4102000                 mov     0, %l2
F0058268: c0246008                 clr     [%l1+8]
F005826C: 400016f7                 call    _ipc_space_release
F0058270: 90100011                 mov     %l1, %o0
F0058274: 113c04ef                 sethi   %hi(_ipc_marequest_zone), %o0
F0058278: d0022368                 ld      [%o0+%lo(_ipc_marequest_zone)], %o0
F005827C: 400083d5                 call    _zfree
F0058280: 92100018                 mov     %i0, %o1
F0058284: 80a52000                 cmp     %l4, 0
F0058288: 1280000a                 bne     loc_F00582B0
F005828C: 90100014                 mov     %l4, %o0
F0058290: 80a4e000                 cmp     %l3, 0
F0058294: 02800009                 be      locret_F00582B8
F0058298: 80a4ffff                 cmp     %l3, -1
F005829C: 02800007                 be      locret_F00582B8
F00582A0: 90100013                 mov     %l3, %o0
F00582A4: 40000484                 call    _ipc_notify_msg_accepted_compat
F00582A8: 92100012                 mov     %l2, %o1
F00582AC: 30800003                 ba,a    locret_F00582B8
F00582B0: 4000037b                 call    _ipc_notify_msg_accepted
F00582B4: 92100012                 mov     %l2, %o1
F00582B8: 81c7e008                 ret
F00582BC: 81e80000                 restore
