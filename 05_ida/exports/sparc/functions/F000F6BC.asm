F000F6BC: 9de3bf58                 save    %sp, -0xA8, %sp! int
F000F6C0: 233c04cf                 sethi   %hi(dword_F0133DDC), %l1
F000F6C4: d00461dc                 ld      [%l1+%lo(dword_F0133DDC)], %o0
F000F6C8: 400000a9                 call    _suser
F000F6CC: e0022024                 ld      [%o0+0x24], %l0
F000F6D0: 80a22000                 cmp     %o0, 0
F000F6D4: 02800045                 be      locret_F000F7E8
F000F6D8: a41461dc                 or      %l1, %lo(dword_F0133DDC), %l2
F000F6DC: d0040000                 ld      [%l0], %o0
F000F6E0: 80a22010                 cmp     %o0, 0x10
F000F6E4: 08800005                 bleu    loc_F000F6F8
F000F6E8: d20461dc                 ld      [%l1+%lo(dword_F0133DDC)], %o1
F000F6EC: 90102016                 mov     0x16, %o0
F000F6F0: 1080003e                 ba      locret_F000F7E8
F000F6F4: d02a6038                 stb     %o0, [%o1+0x38]
F000F6F8: d004bffc                 ld      [%l2-4], %o0
F000F6FC: 400000ea                 call    _crdup
F000F700: d002201c                 ld      [%o0+0x1C], %o0
F000F704: a6100008                 mov     %o0, %l3
F000F708: a407bfb8                 add     %fp, var_48, %l2
F000F70C: d4040000                 ld      [%l0], %o2! int
F000F710: 92100012                 mov     %l2, %o1! int
F000F714: d0042004                 ld      [%l0+4], %o0! int
F000F718: 40022250                 call    _copyin
F000F71C: 952aa002                 sll     %o2, 2, %o2
F000F720: d20461dc                 ld      [%l1+0x1DC], %o1
F000F724: d02a6038                 stb     %o0, [%o1+0x38]
F000F728: d00461dc                 ld      [%l1+0x1DC], %o0
F000F72C: d04a2038                 ldsb    [%o0+0x38], %o0
F000F730: 80a22000                 cmp     %o0, 0
F000F734: 02800005                 be      loc_F000F748
F000F738: 92100012                 mov     %l2, %o1
F000F73C: 400000b7                 call    _crfree
F000F740: 90100013                 mov     %l3, %o0
F000F744: 30800029                 ba,a    locret_F000F7E8
F000F748: d0040000                 ld      [%l0], %o0
F000F74C: 912a2002                 sll     %o0, 2, %o0
F000F750: 90024008                 add     %o1, %o0, %o0
F000F754: 80a24008                 cmp     %o1, %o0
F000F758: 1a80000c                 bcc     loc_F000F788
F000F75C: 9404e00a                 add     %l3, 0xA, %o2
F000F760: 96100009                 mov     %o1, %o3
F000F764: d0024000                 ld      [%o1], %o0
F000F768: d0328000                 sth     %o0, [%o2]
F000F76C: 92026004                 inc     4, %o1
F000F770: d0040000                 ld      [%l0], %o0
F000F774: 912a2002                 sll     %o0, 2, %o0
F000F778: 9002c008                 add     %o3, %o0, %o0
F000F77C: 80a24008                 cmp     %o1, %o0
F000F780: 0abffff9                 bcs     loc_F000F764
F000F784: 9402a002                 inc     2, %o2
F000F788: 233c04cf                 sethi   %hi(_active_u), %l1
F000F78C: d20461d8                 ld      [%l1+%lo(_active_u)], %o1
F000F790: d002601c                 ld      [%o1+0x1C], %o0
F000F794: 400000a1                 call    _crfree
F000F798: e622601c                 st      %l3, [%o1+0x1C]
F000F79C: d2040000                 ld      [%l0], %o1
F000F7A0: d00461d8                 ld      [%l1+%lo(_active_u)], %o0
F000F7A4: 932a6001                 sll     %o1, 1, %o1
F000F7A8: d002201c                 ld      [%o0+0x1C], %o0
F000F7AC: 9202600a                 inc     0xA, %o1
F000F7B0: 94020009                 add     %o0, %o1, %o2
F000F7B4: 9002202a                 inc     0x2A, %o0 ! '*'
F000F7B8: 80a28008                 cmp     %o2, %o0
F000F7BC: 1a80000b                 bcc     locret_F000F7E8
F000F7C0: 96103fff                 mov     -1, %o3
F000F7C4: 92100011                 mov     %l1, %o1
F000F7C8: d6328000                 sth     %o3, [%o2]
F000F7CC: d00261d8                 ld      [%o1+0x1D8], %o0
F000F7D0: d002201c                 ld      [%o0+0x1C], %o0
F000F7D4: 9402a002                 inc     2, %o2
F000F7D8: 9002202a                 inc     0x2A, %o0 ! '*'
F000F7DC: 80a28008                 cmp     %o2, %o0
F000F7E0: 2abffffb                 bcs,a   loc_F000F7CC
F000F7E4: d6328000                 sth     %o3, [%o2]
F000F7E8: 81c7e008                 ret
F000F7EC: 81e80000                 restore
