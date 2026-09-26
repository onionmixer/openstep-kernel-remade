F007B65C: 9de3bf98                 save    %sp, -0x68, %sp
F007B660: d2062004                 ld      [%i0+4], %o1
F007B664: 80a26030                 cmp     %o1, 0x30 ! '0'
F007B668: 12800005                 bne     loc_F007B67C
F007B66C: d00e2003                 ldub    [%i0+3], %o0
F007B670: 80a22000                 cmp     %o0, 0
F007B674: 22800005                 be,a    loc_F007B688
F007B678: d0062018                 ld      [%i0+0x18], %o0
F007B67C: 90103ed0                 mov     -0x130, %o0
F007B680: 10800026                 ba      locret_F007B718
F007B684: d026601c                 st      %o0, [%i1+0x1C]
F007B688: 133c03d3                 sethi   %hi(dword_F00F4DB0), %o1
F007B68C: d20261b0                 ld      [%o1+%lo(dword_F00F4DB0)], %o1
F007B690: 80a20009                 cmp     %o0, %o1
F007B694: 12800019                 bne     loc_F007B6F8
F007B698: 90103ed0                 mov     -0x130, %o0
F007B69C: d0062020                 ld      [%i0+0x20], %o0
F007B6A0: 133c03d3                 sethi   %hi(dword_F00F4DB4), %o1
F007B6A4: d20261b4                 ld      [%o1+%lo(dword_F00F4DB4)], %o1
F007B6A8: 80a20009                 cmp     %o0, %o1
F007B6AC: 12800013                 bne     loc_F007B6F8
F007B6B0: 90103ed0                 mov     -0x130, %o0
F007B6B4: d0062028                 ld      [%i0+0x28], %o0
F007B6B8: 133c03d3                 sethi   %hi(dword_F00F4DB8), %o1
F007B6BC: d20261b8                 ld      [%o1+%lo(dword_F00F4DB8)], %o1
F007B6C0: 80a20009                 cmp     %o0, %o1
F007B6C4: 1280000d                 bne     loc_F007B6F8
F007B6C8: 90103ed0                 mov     -0x130, %o0
F007B6CC: d806a018                 ld      [%i2+0x18], %o4
F007B6D0: 80a32000                 cmp     %o4, 0
F007B6D4: 32800005                 bne,a   loc_F007B6E8
F007B6D8: d0068000                 ld      [%i2], %o0
F007B6DC: 90103ed1                 mov     -0x12F, %o0
F007B6E0: 1080000e                 ba      locret_F007B718
F007B6E4: d026601c                 st      %o0, [%i1+0x1C]
F007B6E8: d206201c                 ld      [%i0+0x1C], %o1
F007B6EC: d4062024                 ld      [%i0+0x24], %o2
F007B6F0: 9fc30000                 call    %o4
F007B6F4: d606202c                 ld      [%i0+0x2C], %o3
F007B6F8: d026601c                 st      %o0, [%i1+0x1C]
F007B6FC: d006601c                 ld      [%i1+0x1C], %o0
F007B700: 80a22000                 cmp     %o0, 0
F007B704: 12800005                 bne     locret_F007B718
F007B708: 92102020                 mov     0x20, %o1 ! ' '
F007B70C: 90102001                 mov     1, %o0
F007B710: d02e6003                 stb     %o0, [%i1+3]
F007B714: d2266004                 st      %o1, [%i1+4]
F007B718: 81c7e008                 ret
F007B71C: 81e80000                 restore
