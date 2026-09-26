F005D880: 9de3bf98                 save    %sp, -0x68, %sp
F005D884: 80a6e005                 cmp     %i3, 5
F005D888: 0280005a                 be      loc_F005D9F0
F005D88C: e0068000                 ld      [%i2], %l0
F005D890: 80a6e006                 cmp     %i3, 6
F005D894: 128000c9                 bne     loc_F005DBB8
F005D898: 113c043d                 sethi   -0xFEF0C00, %o0
F005D89C: 80a72000                 cmp     %i4, 0
F005D8A0: 02800033                 be      loc_F005D96C
F005D8A4: 110007c0                 sethi   0x1F0000, %o0
F005D8A8: 900c0008                 and     %l0, %o0, %o0
F005D8AC: 13000040                 sethi   0x10000, %o1
F005D8B0: 80a20009                 cmp     %o0, %o1
F005D8B4: 128000c5                 bne     loc_F005DBC8
F005D8B8: 90100018                 mov     %i0, %o0
F005D8BC: 94100019                 mov     %i1, %o2
F005D8C0: f806a004                 ld      [%i2+4], %i4
F005D8C4: 9610001a                 mov     %i2, %o3
F005D8C8: 7ffff977                 call    _ipc_right_check
F005D8CC: 9210001c                 mov     %i4, %o1
F005D8D0: 80a22000                 cmp     %o0, 0
F005D8D4: 12800032                 bne     loc_F005D99C
F005D8D8: 11001000                 sethi   0x400000, %o0
F005D8DC: d006a008                 ld      [%i2+8], %o0
F005D8E0: 80a22000                 cmp     %o0, 0
F005D8E4: 02800008                 be      loc_F005D904
F005D8E8: 90100018                 mov     %i0, %o0
F005D8EC: 9210001c                 mov     %i4, %o1
F005D8F0: 94100019                 mov     %i1, %o2
F005D8F4: 7ffff91e                 call    _ipc_right_dncancel
F005D8F8: 9610001a                 mov     %i2, %o3
F005D8FC: 10800003                 ba      loc_F005D908
F005D900: b6100008                 mov     %o0, %i3
F005D904: b6102000                 mov     0, %i3
F005D908: c0270000                 clr     [%i4]
F005D90C: 11000800                 sethi   0x200000, %o0
F005D910: 808c0008                 btst    %o0, %l0
F005D914: 02800004                 be      loc_F005D924
F005D918: 90100018                 mov     %i0, %o0
F005D91C: 7fffe995                 call    _ipc_marequest_cancel
F005D920: 92100019                 mov     %i1, %o1
F005D924: 90100018                 mov     %i0, %o0
F005D928: 9210001c                 mov     %i4, %o1
F005D92C: 94100019                 mov     %i1, %o2
F005D930: 7fffdb20                 call    _ipc_hash_delete
F005D934: 9610001a                 mov     %i2, %o3
F005D938: c026a004                 clr     [%i2+4]
F005D93C: 90100018                 mov     %i0, %o0
F005D940: 92100019                 mov     %i1, %o1
F005D944: 7fffd94d                 call    _ipc_entry_dealloc
F005D948: 9410001a                 mov     %i2, %o2
F005D94C: c0262008                 clr     [%i0+8]
F005D950: 80a6e000                 cmp     %i3, 0
F005D954: 02800004                 be      loc_F005D964
F005D958: 9010001b                 mov     %i3, %o0
F005D95C: 7fffeda4                 call    _ipc_notify_port_deleted
F005D960: 92100019                 mov     %i1, %o1
F005D964: 10800097                 ba      loc_F005DBC0
F005D968: f8274000                 st      %i4, [%i5]
F005D96C: 110000c0                 sethi   0x30000, %o0
F005D970: 808c0008                 btst    %o0, %l0
F005D974: 02800095                 be      loc_F005DBC8
F005D978: 90100018                 mov     %i0, %o0
F005D97C: 94100019                 mov     %i1, %o2
F005D980: f206a004                 ld      [%i2+4], %i1
F005D984: 9610001a                 mov     %i2, %o3
F005D988: 7ffff947                 call    _ipc_right_check
F005D98C: 92100019                 mov     %i1, %o1
F005D990: 80a22000                 cmp     %o0, 0
F005D994: 02800006                 be      loc_F005D9AC
F005D998: 11001000                 sethi   0x400000, %o0
F005D99C: 808c0008                 btst    %o0, %l0
F005D9A0: 0280008a                 be      loc_F005DBC8
F005D9A4: 01000000                 nop
F005D9A8: 3080008b                 ba,a    loc_F005DBD4
F005D9AC: c0262008                 clr     [%i0+8]
F005D9B0: 11000040                 sethi   0x10000, %o0
F005D9B4: 808c0008                 btst    %o0, %l0
F005D9B8: 32800006                 bne,a   loc_F005D9D0
F005D9BC: d006601c                 ld      [%i1+0x1C], %o0
F005D9C0: d0066018                 ld      [%i1+0x18], %o0
F005D9C4: 90022001                 inc     %o0
F005D9C8: d0266018                 st      %o0, [%i1+0x18]
F005D9CC: d006601c                 ld      [%i1+0x1C], %o0
F005D9D0: 90022001                 inc     %o0
F005D9D4: d026601c                 st      %o0, [%i1+0x1C]
F005D9D8: d0066004                 ld      [%i1+4], %o0
F005D9DC: 90022001                 inc     %o0
F005D9E0: d0266004                 st      %o0, [%i1+4]
F005D9E4: c0264000                 clr     [%i1]
F005D9E8: 10800076                 ba      loc_F005DBC0
F005D9EC: f2274000                 st      %i1, [%i5]
F005D9F0: 80a72000                 cmp     %i4, 0
F005D9F4: 02800047                 be      loc_F005DB10
F005D9F8: a2102000                 mov     0, %l1
F005D9FC: 11000080                 sethi   0x20000, %o0
F005DA00: 808c0008                 btst    %o0, %l0
F005DA04: 02800071                 be      loc_F005DBC8
F005DA08: a4102000                 mov     0, %l2
F005DA0C: f606a004                 ld      [%i2+4], %i3
F005DA10: d006c000                 ld      [%i3], %o0
F005DA14: 80a22000                 cmp     %o0, 0
F005DA18: 12bffffe                 bne     loc_F005DA10
F005DA1C: 01000000                 nop
F005DA20: 4000e522                 call    _simple_lock_try
F005DA24: 9010001b                 mov     %i3, %o0
F005DA28: 80a22000                 cmp     %o0, 0
F005DA2C: 02bffff9                 be      loc_F005DA10
F005DA30: 01000000                 nop
F005DA34: d006a008                 ld      [%i2+8], %o0
F005DA38: 80a22000                 cmp     %o0, 0
F005DA3C: 02800008                 be      loc_F005DA5C
F005DA40: 90100018                 mov     %i0, %o0
F005DA44: 9210001b                 mov     %i3, %o1
F005DA48: 94100019                 mov     %i1, %o2
F005DA4C: 7ffff8c8                 call    _ipc_right_dncancel
F005DA50: 9610001a                 mov     %i2, %o3
F005DA54: 10800003                 ba      loc_F005DA60
F005DA58: b8100008                 mov     %o0, %i4
F005DA5C: b8102000                 mov     0, %i4
F005DA60: 11000800                 sethi   0x200000, %o0
F005DA64: 808c0008                 btst    %o0, %l0
F005DA68: 02800004                 be      loc_F005DA78
F005DA6C: 90100018                 mov     %i0, %o0
F005DA70: 7fffe940                 call    _ipc_marequest_cancel
F005DA74: 92100019                 mov     %i1, %o1
F005DA78: c026a004                 clr     [%i2+4]
F005DA7C: 90100018                 mov     %i0, %o0
F005DA80: 92100019                 mov     %i1, %o1
F005DA84: 7fffd8fd                 call    _ipc_entry_dealloc
F005DA88: 9410001a                 mov     %i2, %o2
F005DA8C: c0262008                 clr     [%i0+8]
F005DA90: 11000040                 sethi   0x10000, %o0
F005DA94: 808c0008                 btst    %o0, %l0
F005DA98: 0280000d                 be      loc_F005DACC
F005DA9C: 01000000                 nop
F005DAA0: d006e01c                 ld      [%i3+0x1C], %o0
F005DAA4: 90023fff                 inc     -1, %o0
F005DAA8: 80a22000                 cmp     %o0, 0
F005DAAC: 12800008                 bne     loc_F005DACC
F005DAB0: d026e01c                 st      %o0, [%i3+0x1C]
F005DAB4: e206e024                 ld      [%i3+0x24], %l1
F005DAB8: 80a46000                 cmp     %l1, 0
F005DABC: 02800004                 be      loc_F005DACC
F005DAC0: 01000000                 nop
F005DAC4: c026e024                 clr     [%i3+0x24]
F005DAC8: e406e018                 ld      [%i3+0x18], %l2
F005DACC: 7ffff397                 call    _ipc_port_clear_receiver
F005DAD0: 9010001b                 mov     %i3, %o0
F005DAD4: c026e010                 clr     [%i3+0x10]
F005DAD8: c026e00c                 clr     [%i3+0xC]
F005DADC: c026c000                 clr     [%i3]
F005DAE0: 80a46000                 cmp     %l1, 0
F005DAE4: 02800004                 be      loc_F005DAF4
F005DAE8: 90100011                 mov     %l1, %o0
F005DAEC: 7fffedc6                 call    _ipc_notify_no_senders
F005DAF0: 92100012                 mov     %l2, %o1
F005DAF4: 80a72000                 cmp     %i4, 0
F005DAF8: 0280002e                 be      loc_F005DBB0
F005DAFC: 9010001c                 mov     %i4, %o0
F005DB00: 7fffed3b                 call    _ipc_notify_port_deleted
F005DB04: 92100019                 mov     %i1, %o1
F005DB08: 1080002e                 ba      loc_F005DBC0
F005DB0C: f6274000                 st      %i3, [%i5]
F005DB10: 11000080                 sethi   0x20000, %o0
F005DB14: 808c0008                 btst    %o0, %l0
F005DB18: 0280002c                 be      loc_F005DBC8
F005DB1C: 01000000                 nop
F005DB20: f606a004                 ld      [%i2+4], %i3
F005DB24: d006c000                 ld      [%i3], %o0
F005DB28: 80a22000                 cmp     %o0, 0
F005DB2C: 12bffffe                 bne     loc_F005DB24
F005DB30: 01000000                 nop
F005DB34: 4000e4dd                 call    _simple_lock_try
F005DB38: 9010001b                 mov     %i3, %o0
F005DB3C: 80a22000                 cmp     %o0, 0
F005DB40: 02bffff9                 be      loc_F005DB24
F005DB44: 11000040                 sethi   0x10000, %o0
F005DB48: 808c0008                 btst    %o0, %l0
F005DB4C: 12800009                 bne     loc_F005DB70
F005DB50: 90100018                 mov     %i0, %o0
F005DB54: d206e01c                 ld      [%i3+0x1C], %o1
F005DB58: 1100004090122001         set     0x10001, %o0
F005DB60: a0140008                 bset    %o0, %l0
F005DB64: 92026001                 inc     %o1
F005DB68: d226e01c                 st      %o1, [%i3+0x1C]
F005DB6C: 90100018                 mov     %i0, %o0
F005DB70: 9210001b                 mov     %i3, %o1
F005DB74: 94100019                 mov     %i1, %o2
F005DB78: 7fffda79                 call    _ipc_hash_insert
F005DB7C: 9610001a                 mov     %i2, %o3
F005DB80: 11000080                 sethi   0x20000, %o0
F005DB84: 902c0008                 andn    %l0, %o0, %o0
F005DB88: d0268000                 st      %o0, [%i2]
F005DB8C: c0262008                 clr     [%i0+8]
F005DB90: 7ffff366                 call    _ipc_port_clear_receiver
F005DB94: 9010001b                 mov     %i3, %o0
F005DB98: c026e010                 clr     [%i3+0x10]
F005DB9C: c026e00c                 clr     [%i3+0xC]
F005DBA0: d006e004                 ld      [%i3+4], %o0! char *
F005DBA4: 90022001                 inc     %o0
F005DBA8: d026e004                 st      %o0, [%i3+4]
F005DBAC: c026c000                 clr     [%i3]
F005DBB0: 10800004                 ba      loc_F005DBC0
F005DBB4: f6274000                 st      %i3, [%i5]
F005DBB8: 7ffedd6e                 call    _panic
F005DBBC: 90122398                 bset    0x398, %o0
F005DBC0: 10800007                 ba      locret_F005DBDC
F005DBC4: b0102000                 mov     0, %i0
F005DBC8: c0262008                 clr     [%i0+8]
F005DBCC: 10800004                 ba      locret_F005DBDC
F005DBD0: b0102011                 mov     0x11, %i0
F005DBD4: c0262008                 clr     [%i0+8]
F005DBD8: b010200f                 mov     0xF, %i0
F005DBDC: 81c7e008                 ret
F005DBE0: 81e80000                 restore
