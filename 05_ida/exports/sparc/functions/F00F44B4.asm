F00F44B4: 9de3bf68                 save    %sp, -0x98, %sp
F00F44B8: 92102028                 mov     0x28, %o1 ! '('
F00F44BC: f227bfe4                 st      %i1, [%fp+var_1C]
F00F44C0: f427bfec                 st      %i2, [%fp+var_14]
F00F44C4: 90102001                 mov     1, %o0
F00F44C8: d02fbfcb                 stb     %o0, [%fp+var_35]
F00F44CC: d227bfcc                 st      %o1, [%fp+var_34]
F00F44D0: 90102100                 mov     0x100, %o0
F00F44D4: d027bfd0                 st      %o0, [%fp+var_30]
F00F44D8: f027bfd8                 st      %i0, [%fp+var_28]
F00F44DC: 113c03e9                 sethi   %hi(dword_F00FA498), %o0
F00F44E0: d2022098                 ld      [%o0+%lo(dword_F00FA498)], %o1
F00F44E4: b207bfc8                 add     %fp, var_38, %i1
F00F44E8: 113c03e9                 sethi   %hi(dword_F00FA49C), %o0
F00F44EC: d002209c                 ld      [%o0+%lo(dword_F00FA49C)], %o0
F00F44F0: d227bfe0                 st      %o1, [%fp+var_20]
F00F44F4: 7ffdc821                 call    _mig_get_reply_port
F00F44F8: d027bfe8                 st      %o0, [%fp+var_18]
F00F44FC: d027bfd4                 st      %o0, [%fp+var_2C]
F00F4500: 901027ea                 mov     0x7EA, %o0
F00F4504: d027bfdc                 st      %o0, [%fp+var_24]
F00F4508: 90100019                 mov     %i1, %o0! reply_port
F00F450C: 92102000                 mov     0, %o1
F00F4510: 94102030                 mov     0x30, %o2 ! '0'
F00F4514: 96102000                 mov     0, %o3
F00F4518: 7ffdc6b1                 call    _msg_rpc
F00F451C: 98102000                 mov     0, %o4
F00F4520: b0920000                 orcc    %o0, %g0, %i0
F00F4524: 02800006                 be      loc_F00F453C
F00F4528: 80a63f36                 cmp     %i0, -0xCA
F00F452C: 12800033                 bne     locret_F00F45F8
F00F4530: 01000000                 nop
F00F4534: 7ffdc81e                 call    _mig_dealloc_reply_port
F00F4538: 9e03e0bc                 inc     0xBC, %o7
F00F453C: d207bfcc                 ld      [%fp+var_34], %o1
F00F4540: d007bfdc                 ld      [%fp+var_24], %o0
F00F4544: 80a2284e                 cmp     %o0, 0x84E
F00F4548: 02800004                 be      loc_F00F4558
F00F454C: d40fbfcb                 ldub    [%fp+var_35], %o2
F00F4550: 1080002a                 ba      locret_F00F45F8
F00F4554: b0103ed3                 mov     -0x12D, %i0
F00F4558: 80a26030                 cmp     %o1, 0x30 ! '0'
F00F455C: 12800005                 bne     loc_F00F4570
F00F4560: 80a26020                 cmp     %o1, 0x20 ! ' '
F00F4564: 80a2a000                 cmp     %o2, 0
F00F4568: 0280000a                 be      loc_F00F4590
F00F456C: 80a26020                 cmp     %o1, 0x20 ! ' '
F00F4570: 12800022                 bne     locret_F00F45F8
F00F4574: b0103ed4                 mov     -0x12C, %i0
F00F4578: 80a2a001                 cmp     %o2, 1
F00F457C: 1280001f                 bne     locret_F00F45F8
F00F4580: d007bfe4                 ld      [%fp+var_1C], %o0
F00F4584: 80a22000                 cmp     %o0, 0
F00F4588: 0280001c                 be      locret_F00F45F8
F00F458C: 01000000                 nop
F00F4590: d0066018                 ld      [%i1+0x18], %o0
F00F4594: 133c03e9                 sethi   %hi(dword_F00FA4A0), %o1
F00F4598: d20260a0                 ld      [%o1+%lo(dword_F00FA4A0)], %o1
F00F459C: 80a20009                 cmp     %o0, %o1
F00F45A0: 12800016                 bne     locret_F00F45F8
F00F45A4: b0103ed4                 mov     -0x12C, %i0
F00F45A8: f006601c                 ld      [%i1+0x1C], %i0
F00F45AC: 80a62000                 cmp     %i0, 0
F00F45B0: 12800012                 bne     locret_F00F45F8
F00F45B4: 01000000                 nop
F00F45B8: d0066020                 ld      [%i1+0x20], %o0
F00F45BC: 900a200c                 and     %o0, 0xC, %o0
F00F45C0: 80a22004                 cmp     %o0, 4
F00F45C4: 1280000d                 bne     locret_F00F45F8
F00F45C8: b0103ed4                 mov     -0x12C, %i0
F00F45CC: d2066024                 ld      [%i1+0x24], %o1
F00F45D0: 1100024090122008         set     0x90008, %o0
F00F45D8: 80a24008                 cmp     %o1, %o0
F00F45DC: 12800007                 bne     locret_F00F45F8
F00F45E0: 01000000                 nop
F00F45E4: d006602c                 ld      [%i1+0x2C], %o0
F00F45E8: d026c000                 st      %o0, [%i3]
F00F45EC: d0066028                 ld      [%i1+0x28], %o0
F00F45F0: d0270000                 st      %o0, [%i4]
F00F45F4: f006601c                 ld      [%i1+0x1C], %i0
F00F45F8: 81c7e008                 ret
F00F45FC: 81e80000                 restore
