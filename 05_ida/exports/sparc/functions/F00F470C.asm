F00F470C: 9de3bf68                 save    %sp, -0x98, %sp
F00F4710: 113c03e9                 sethi   %hi(dword_F00FA4B0), %o0
F00F4714: d00220b0                 ld      [%o0+%lo(dword_F00FA4B0)], %o0
F00F4718: 94102030                 mov     0x30, %o2 ! '0'
F00F471C: d027bfe0                 st      %o0, [%fp+var_20]
F00F4720: d2064000                 ld      [%i1], %o1
F00F4724: 113c03e9                 sethi   %hi(dword_F00FA4B4), %o0
F00F4728: d00220b4                 ld      [%o0+%lo(dword_F00FA4B4)], %o0
F00F472C: d227bfe4                 st      %o1, [%fp+var_1C]
F00F4730: d027bfe8                 st      %o0, [%fp+var_18]
F00F4734: 113c03e9                 sethi   %hi(dword_F00FA4B8), %o0
F00F4738: f427bfec                 st      %i2, [%fp+var_14]
F00F473C: f627bff4                 st      %i3, [%fp+var_C]
F00F4740: d427bfcc                 st      %o2, [%fp+var_34]
F00F4744: f027bfd8                 st      %i0, [%fp+var_28]
F00F4748: d00220b8                 ld      [%o0+%lo(dword_F00FA4B8)], %o0
F00F474C: b407bfc8                 add     %fp, var_38, %i2
F00F4750: d027bff0                 st      %o0, [%fp+var_10]
F00F4754: 90102001                 mov     1, %o0
F00F4758: d02fbfcb                 stb     %o0, [%fp+var_35]
F00F475C: 90102100                 mov     0x100, %o0
F00F4760: 7ffdc786                 call    _mig_get_reply_port
F00F4764: d027bfd0                 st      %o0, [%fp+var_30]
F00F4768: d027bfd4                 st      %o0, [%fp+var_2C]
F00F476C: 901027e5                 mov     0x7E5, %o0
F00F4770: d027bfdc                 st      %o0, [%fp+var_24]
F00F4774: 9010001a                 mov     %i2, %o0! reply_port
F00F4778: 92102000                 mov     0, %o1
F00F477C: 94102028                 mov     0x28, %o2 ! '('
F00F4780: 96102000                 mov     0, %o3
F00F4784: 7ffdc616                 call    _msg_rpc
F00F4788: 98102000                 mov     0, %o4
F00F478C: b0920000                 orcc    %o0, %g0, %i0
F00F4790: 02800006                 be      loc_F00F47A8
F00F4794: 80a63f36                 cmp     %i0, -0xCA
F00F4798: 1280002b                 bne     locret_F00F4844
F00F479C: 01000000                 nop
F00F47A0: 7ffdc783                 call    _mig_dealloc_reply_port
F00F47A4: 9e03e09c                 inc     0x9C, %o7
F00F47A8: d407bfcc                 ld      [%fp+var_34], %o2
F00F47AC: d007bfdc                 ld      [%fp+var_24], %o0
F00F47B0: 80a22849                 cmp     %o0, 0x849
F00F47B4: 02800004                 be      loc_F00F47C4
F00F47B8: d20fbfcb                 ldub    [%fp+var_35], %o1
F00F47BC: 10800022                 ba      locret_F00F4844
F00F47C0: b0103ed3                 mov     -0x12D, %i0
F00F47C4: 80a2a028                 cmp     %o2, 0x28 ! '('
F00F47C8: 12800005                 bne     loc_F00F47DC
F00F47CC: 80a2a020                 cmp     %o2, 0x20 ! ' '
F00F47D0: 80a26001                 cmp     %o1, 1
F00F47D4: 0280000a                 be      loc_F00F47FC
F00F47D8: 80a2a020                 cmp     %o2, 0x20 ! ' '
F00F47DC: 1280001a                 bne     locret_F00F4844
F00F47E0: b0103ed4                 mov     -0x12C, %i0
F00F47E4: 80a26001                 cmp     %o1, 1
F00F47E8: 12800017                 bne     locret_F00F4844
F00F47EC: d007bfe4                 ld      [%fp+var_1C], %o0
F00F47F0: 80a22000                 cmp     %o0, 0
F00F47F4: 02800014                 be      locret_F00F4844
F00F47F8: 01000000                 nop
F00F47FC: d006a018                 ld      [%i2+0x18], %o0
F00F4800: 133c03e9                 sethi   %hi(dword_F00FA4BC), %o1
F00F4804: d20260bc                 ld      [%o1+%lo(dword_F00FA4BC)], %o1
F00F4808: 80a20009                 cmp     %o0, %o1
F00F480C: 1280000e                 bne     locret_F00F4844
F00F4810: b0103ed4                 mov     -0x12C, %i0
F00F4814: f006a01c                 ld      [%i2+0x1C], %i0
F00F4818: 80a62000                 cmp     %i0, 0
F00F481C: 1280000a                 bne     locret_F00F4844
F00F4820: 133c03e9                 sethi   %hi(dword_F00FA4C0), %o1
F00F4824: d006a020                 ld      [%i2+0x20], %o0
F00F4828: d20260c0                 ld      [%o1+%lo(dword_F00FA4C0)], %o1
F00F482C: 80a20009                 cmp     %o0, %o1
F00F4830: 12800005                 bne     locret_F00F4844
F00F4834: b0103ed4                 mov     -0x12C, %i0
F00F4838: d006a024                 ld      [%i2+0x24], %o0
F00F483C: d0264000                 st      %o0, [%i1]
F00F4840: f006a01c                 ld      [%i2+0x1C], %i0
F00F4844: 81c7e008                 ret
F00F4848: 81e80000                 restore
