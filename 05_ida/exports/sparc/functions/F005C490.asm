F005C490: 9de3bf98                 save    %sp, -0x68, %sp
F005C494: e4068000                 ld      [%i2], %l2
F005C498: 110007c0                 sethi   0x1F0000, %o0
F005C49C: 920c8008                 and     %l2, %o0, %o1
F005C4A0: 110000c0                 sethi   0x30000, %o0
F005C4A4: 80a24008                 cmp     %o1, %o0
F005C4A8: 0280008e                 be      loc_F005C6E0
F005C4AC: a0102000                 mov     0, %l0
F005C4B0: 18800006                 bgu     loc_F005C4C8
F005C4B4: 11000040                 sethi   0x10000, %o0
F005C4B8: 80a24008                 cmp     %o1, %o0
F005C4BC: 0280003a                 be      loc_F005C5A4
F005C4C0: a2102000                 mov     0, %l1
F005C4C4: 308000ae                 ba,a    loc_F005C77C
F005C4C8: 11000100                 sethi   0x40000, %o0
F005C4CC: 80a24008                 cmp     %o1, %o0
F005C4D0: 02800014                 be      loc_F005C520
F005C4D4: 11000400                 sethi   0x100000, %o0
F005C4D8: 80a24008                 cmp     %o1, %o0
F005C4DC: 128000a8                 bne     loc_F005C77C
F005C4E0: 01000000                 nop
F005C4E4: 1100003f901223ff         set     0xFFFF, %o0
F005C4EC: 900c8008                 and     %l2, %o0, %o0
F005C4F0: 80a22001                 cmp     %o0, 1
F005C4F4: 12800007                 bne     loc_F005C510
F005C4F8: 9004bfff                 add     %l2, -1, %o0
F005C4FC: 90100018                 mov     %i0, %o0
F005C500: 92100019                 mov     %i1, %o1
F005C504: 7fffde5d                 call    _ipc_entry_dealloc
F005C508: 9410001a                 mov     %i2, %o2
F005C50C: 30800002                 ba,a    loc_F005C514
F005C510: d0268000                 st      %o0, [%i2]
F005C514: c0262008                 clr     [%i0+8]
F005C518: 108000a0                 ba      locret_F005C798
F005C51C: b0102000                 mov     0, %i0
F005C520: 90100018                 mov     %i0, %o0
F005C524: 94100019                 mov     %i1, %o2
F005C528: e206a004                 ld      [%i2+4], %l1
F005C52C: 9610001a                 mov     %i2, %o3
F005C530: 7ffffe5d                 call    _ipc_right_check
F005C534: 92100011                 mov     %l1, %o1
F005C538: 80a22000                 cmp     %o0, 0
F005C53C: 12800025                 bne     loc_F005C5D0
F005C540: 11001000                 sethi   0x400000, %o0
F005C544: d006a008                 ld      [%i2+8], %o0
F005C548: 80a22000                 cmp     %o0, 0
F005C54C: 02800008                 be      loc_F005C56C
F005C550: 92100011                 mov     %l1, %o1
F005C554: 90100018                 mov     %i0, %o0
F005C558: 94100019                 mov     %i1, %o2
F005C55C: 7ffffe04                 call    _ipc_right_dncancel
F005C560: 9610001a                 mov     %i2, %o3
F005C564: 10800003                 ba      loc_F005C570
F005C568: a0100008                 mov     %o0, %l0
F005C56C: a0102000                 mov     0, %l0
F005C570: c0244000                 clr     [%l1]
F005C574: c026a004                 clr     [%i2+4]
F005C578: 90100018                 mov     %i0, %o0
F005C57C: 92100019                 mov     %i1, %o1
F005C580: 7fffde3e                 call    _ipc_entry_dealloc
F005C584: 9410001a                 mov     %i2, %o2
F005C588: c0262008                 clr     [%i0+8]
F005C58C: 7ffff34a                 call    _ipc_notify_send_once
F005C590: 90100011                 mov     %l1, %o0
F005C594: 80a42000                 cmp     %l0, 0
F005C598: 0280007c                 be      loc_F005C788
F005C59C: 90100010                 mov     %l0, %o0
F005C5A0: 3080004c                 ba,a    loc_F005C6D0
F005C5A4: a6102000                 mov     0, %l3
F005C5A8: a8102000                 mov     0, %l4
F005C5AC: 90100018                 mov     %i0, %o0
F005C5B0: 94100019                 mov     %i1, %o2
F005C5B4: e006a004                 ld      [%i2+4], %l0
F005C5B8: 9610001a                 mov     %i2, %o3
F005C5BC: 7ffffe3a                 call    _ipc_right_check
F005C5C0: 92100010                 mov     %l0, %o1
F005C5C4: 80a22000                 cmp     %o0, 0
F005C5C8: 02800007                 be      loc_F005C5E4
F005C5CC: 11001000                 sethi   0x400000, %o0
F005C5D0: 808c8008                 btst    %o0, %l2
F005C5D4: 1280006f                 bne     loc_F005C790
F005C5D8: 01000000                 nop
F005C5DC: 10bfffc2                 ba      loc_F005C4E4
F005C5E0: e4068000                 ld      [%i2], %l2
F005C5E4: 1100003f901223ff         set     0xFFFF, %o0
F005C5EC: 900c8008                 and     %l2, %o0, %o0
F005C5F0: 80a22001                 cmp     %o0, 1
F005C5F4: 1280002c                 bne     loc_F005C6A4
F005C5F8: 9004bfff                 add     %l2, -1, %o0
F005C5FC: d004201c                 ld      [%l0+0x1C], %o0
F005C600: 90023fff                 inc     -1, %o0
F005C604: 80a22000                 cmp     %o0, 0
F005C608: 12800008                 bne     loc_F005C628
F005C60C: d024201c                 st      %o0, [%l0+0x1C]
F005C610: e6042024                 ld      [%l0+0x24], %l3
F005C614: 80a4e000                 cmp     %l3, 0
F005C618: 22800005                 be,a    loc_F005C62C
F005C61C: d006a008                 ld      [%i2+8], %o0
F005C620: c0242024                 clr     [%l0+0x24]
F005C624: e8042018                 ld      [%l0+0x18], %l4
F005C628: d006a008                 ld      [%i2+8], %o0
F005C62C: 80a22000                 cmp     %o0, 0
F005C630: 02800008                 be      loc_F005C650
F005C634: 90100018                 mov     %i0, %o0
F005C638: 92100010                 mov     %l0, %o1
F005C63C: 94100019                 mov     %i1, %o2
F005C640: 7ffffdcb                 call    _ipc_right_dncancel
F005C644: 9610001a                 mov     %i2, %o3
F005C648: 10800003                 ba      loc_F005C654
F005C64C: a2100008                 mov     %o0, %l1
F005C650: a2102000                 mov     0, %l1
F005C654: 90100018                 mov     %i0, %o0
F005C658: 92100010                 mov     %l0, %o1
F005C65C: 94100019                 mov     %i1, %o2
F005C660: 7fffdfd4                 call    _ipc_hash_delete
F005C664: 9610001a                 mov     %i2, %o3
F005C668: 11000800                 sethi   0x200000, %o0
F005C66C: 808c8008                 btst    %o0, %l2
F005C670: 02800004                 be      loc_F005C680
F005C674: 90100018                 mov     %i0, %o0
F005C678: 7fffee3e                 call    _ipc_marequest_cancel
F005C67C: 92100019                 mov     %i1, %o1
F005C680: d0042004                 ld      [%l0+4], %o0
F005C684: 90023fff                 inc     -1, %o0
F005C688: d0242004                 st      %o0, [%l0+4]
F005C68C: c026a004                 clr     [%i2+4]
F005C690: 90100018                 mov     %i0, %o0
F005C694: 92100019                 mov     %i1, %o1
F005C698: 7fffddf8                 call    _ipc_entry_dealloc
F005C69C: 9410001a                 mov     %i2, %o2
F005C6A0: 30800002                 ba,a    loc_F005C6A8
F005C6A4: d0268000                 st      %o0, [%i2]
F005C6A8: c0240000                 clr     [%l0]
F005C6AC: c0262008                 clr     [%i0+8]
F005C6B0: 80a4e000                 cmp     %l3, 0
F005C6B4: 02800004                 be      loc_F005C6C4
F005C6B8: 90100013                 mov     %l3, %o0
F005C6BC: 7ffff2d2                 call    _ipc_notify_no_senders
F005C6C0: 92100014                 mov     %l4, %o1
F005C6C4: 80a46000                 cmp     %l1, 0
F005C6C8: 02800030                 be      loc_F005C788
F005C6CC: 90100011                 mov     %l1, %o0
F005C6D0: 7ffff247                 call    _ipc_notify_port_deleted
F005C6D4: 92100019                 mov     %i1, %o1
F005C6D8: 10800030                 ba      locret_F005C798
F005C6DC: b0102000                 mov     0, %i0
F005C6E0: a2102000                 mov     0, %l1
F005C6E4: f206a004                 ld      [%i2+4], %i1
F005C6E8: d0064000                 ld      [%i1], %o0
F005C6EC: 80a22000                 cmp     %o0, 0
F005C6F0: 12bffffe                 bne     loc_F005C6E8
F005C6F4: 01000000                 nop
F005C6F8: 4000e9ec                 call    _simple_lock_try
F005C6FC: 90100019                 mov     %i1, %o0
F005C700: 80a22000                 cmp     %o0, 0
F005C704: 02bffff9                 be      loc_F005C6E8
F005C708: 1100003f                 sethi   0xFC00, %o0
F005C70C: 901223ff                 bset    0x3FF, %o0
F005C710: 900c8008                 and     %l2, %o0, %o0
F005C714: 80a22001                 cmp     %o0, 1
F005C718: 1280000f                 bne     loc_F005C754
F005C71C: 9004bfff                 add     %l2, -1, %o0
F005C720: d006601c                 ld      [%i1+0x1C], %o0
F005C724: 90023fff                 inc     -1, %o0
F005C728: 80a22000                 cmp     %o0, 0
F005C72C: 12800008                 bne     loc_F005C74C
F005C730: d026601c                 st      %o0, [%i1+0x1C]
F005C734: e0066024                 ld      [%i1+0x24], %l0
F005C738: 80a42000                 cmp     %l0, 0
F005C73C: 22800005                 be,a    loc_F005C750
F005C740: 113fff80                 sethi   -0x20000, %o0
F005C744: c0266024                 clr     [%i1+0x24]
F005C748: e2066018                 ld      [%i1+0x18], %l1
F005C74C: 113fff80                 sethi   -0x20000, %o0
F005C750: 900c8008                 and     %l2, %o0, %o0
F005C754: d0268000                 st      %o0, [%i2]
F005C758: c0264000                 clr     [%i1]
F005C75C: c0262008                 clr     [%i0+8]
F005C760: 80a42000                 cmp     %l0, 0
F005C764: 02800009                 be      loc_F005C788
F005C768: 90100010                 mov     %l0, %o0
F005C76C: 7ffff2a6                 call    _ipc_notify_no_senders
F005C770: 92100011                 mov     %l1, %o1
F005C774: 10800009                 ba      locret_F005C798
F005C778: b0102000                 mov     0, %i0
F005C77C: c0262008                 clr     [%i0+8]
F005C780: 10800006                 ba      locret_F005C798
F005C784: b0102011                 mov     0x11, %i0
F005C788: 10800004                 ba      locret_F005C798
F005C78C: b0102000                 mov     0, %i0
F005C790: c0262008                 clr     [%i0+8]
F005C794: b010200f                 mov     0xF, %i0
F005C798: 81c7e008                 ret
F005C79C: 81e80000                 restore
