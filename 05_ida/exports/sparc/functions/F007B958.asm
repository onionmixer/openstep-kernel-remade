F007B958: 9de3bf98                 save    %sp, -0x68, %sp
F007B95C: d2062004                 ld      [%i0+4], %o1
F007B960: 80a26030                 cmp     %o1, 0x30 ! '0'
F007B964: 12800005                 bne     loc_F007B978
F007B968: d00e2003                 ldub    [%i0+3], %o0
F007B96C: 80a22000                 cmp     %o0, 0
F007B970: 22800005                 be,a    loc_F007B984
F007B974: d0062018                 ld      [%i0+0x18], %o0
F007B978: 90103ed0                 mov     -0x130, %o0
F007B97C: 10800026                 ba      locret_F007BA14
F007B980: d026601c                 st      %o0, [%i1+0x1C]
F007B984: 133c03d3                 sethi   %hi(dword_F00F4DD0), %o1
F007B988: d20261d0                 ld      [%o1+%lo(dword_F00F4DD0)], %o1
F007B98C: 80a20009                 cmp     %o0, %o1
F007B990: 12800019                 bne     loc_F007B9F4
F007B994: 90103ed0                 mov     -0x130, %o0
F007B998: d0062020                 ld      [%i0+0x20], %o0
F007B99C: 133c03d3                 sethi   %hi(dword_F00F4DD4), %o1
F007B9A0: d20261d4                 ld      [%o1+%lo(dword_F00F4DD4)], %o1
F007B9A4: 80a20009                 cmp     %o0, %o1
F007B9A8: 12800013                 bne     loc_F007B9F4
F007B9AC: 90103ed0                 mov     -0x130, %o0
F007B9B0: d0062028                 ld      [%i0+0x28], %o0
F007B9B4: 133c03d3                 sethi   %hi(dword_F00F4DD8), %o1
F007B9B8: d20261d8                 ld      [%o1+%lo(dword_F00F4DD8)], %o1
F007B9BC: 80a20009                 cmp     %o0, %o1
F007B9C0: 1280000d                 bne     loc_F007B9F4
F007B9C4: 90103ed0                 mov     -0x130, %o0
F007B9C8: d806a030                 ld      [%i2+0x30], %o4
F007B9CC: 80a32000                 cmp     %o4, 0
F007B9D0: 32800005                 bne,a   loc_F007B9E4
F007B9D4: d0068000                 ld      [%i2], %o0
F007B9D8: 90103ed1                 mov     -0x12F, %o0
F007B9DC: 1080000e                 ba      locret_F007BA14
F007B9E0: d026601c                 st      %o0, [%i1+0x1C]
F007B9E4: d206201c                 ld      [%i0+0x1C], %o1
F007B9E8: d4062024                 ld      [%i0+0x24], %o2
F007B9EC: 9fc30000                 call    %o4
F007B9F0: d606202c                 ld      [%i0+0x2C], %o3
F007B9F4: d026601c                 st      %o0, [%i1+0x1C]
F007B9F8: d006601c                 ld      [%i1+0x1C], %o0
F007B9FC: 80a22000                 cmp     %o0, 0
F007BA00: 12800005                 bne     locret_F007BA14
F007BA04: 92102020                 mov     0x20, %o1 ! ' '
F007BA08: 90102001                 mov     1, %o0
F007BA0C: d02e6003                 stb     %o0, [%i1+3]
F007BA10: d2266004                 st      %o1, [%i1+4]
F007BA14: 81c7e008                 ret
F007BA18: 81e80000                 restore
