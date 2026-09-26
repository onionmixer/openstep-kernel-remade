F00B8B90: 9de3bf98                 save    %sp, -0x68, %sp
F00B8B94: 1100003f                 sethi   0xFC00, %o0
F00B8B98: d216205c                 lduh    [%i0+0x5C], %o1
F00B8B9C: 901223f8                 bset    0x3F8, %o0
F00B8BA0: 920a4008                 and     %o1, %o0, %o1
F00B8BA4: d236205c                 sth     %o1, [%i0+0x5C]
F00B8BA8: 113ffc00                 sethi   -0x100000, %o0
F00B8BAC: d2066020                 ld      [%i1+0x20], %o1
F00B8BB0: 96122000                 or      %o0, 0, %o3
F00B8BB4: 80a2400b                 cmp     %o1, %o3
F00B8BB8: 0a800015                 bcs     loc_F00B8C0C
F00B8BBC: 113c0464                 sethi   %hi(_dvmasize), %o0
F00B8BC0: d0022324                 ld      [%o0+%lo(_dvmasize)], %o0
F00B8BC4: 912a200c                 sll     %o0, 12, %o0
F00B8BC8: 9402000b                 add     %o0, %o3, %o2
F00B8BCC: 80a2400a                 cmp     %o1, %o2
F00B8BD0: 1a800010                 bcc     loc_F00B8C10
F00B8BD4: 80a6a001                 cmp     %i2, 1
F00B8BD8: d0066014                 ld      [%i1+0x14], %o0
F00B8BDC: 90024008                 add     %o1, %o0, %o0
F00B8BE0: 80a2000b                 cmp     %o0, %o3
F00B8BE4: 0a80000a                 bcs     loc_F00B8C0C
F00B8BE8: 90023fff                 inc     -1, %o0
F00B8BEC: 80a2000a                 cmp     %o0, %o2
F00B8BF0: 1a800007                 bcc     loc_F00B8C0C
F00B8BF4: 9222400b                 sub     %o1, %o3, %o1
F00B8BF8: d016205c                 lduh    [%i0+0x5C], %o0
F00B8BFC: d226203c                 st      %o1, [%i0+0x3C]
F00B8C00: 90122004                 bset    4, %o0
F00B8C04: 1080003a                 ba      loc_F00B8CEC
F00B8C08: d036205c                 sth     %o0, [%i0+0x5C]
F00B8C0C: 80a6a001                 cmp     %i2, 1
F00B8C10: 1280000b                 bne     loc_F00B8C3C
F00B8C14: 113c04fc                 sethi   -0xFEC1000, %o0
F00B8C18: 113c04f6                 sethi   %hi(_dvmamap), %o0
F00B8C1C: d00222f8                 ld      [%o0+%lo(_dvmamap)], %o0
F00B8C20: 92100019                 mov     %i1, %o1
F00B8C24: 94102040                 mov     0x40, %o2 ! '@'
F00B8C28: 96102000                 mov     0, %o3
F00B8C2C: 7fff8526                 call    _mb_mapalloc
F00B8C30: 98102000                 mov     0, %o4
F00B8C34: 1080002e                 ba      loc_F00B8CEC
F00B8C38: d026203c                 st      %o0, [%i0+0x3C]
F00B8C3C: 7fff7832                 call    _splr
F00B8C40: d00220c0                 ld      [%o0+0xC0], %o0
F00B8C44: 153c04c5                 sethi   %hi(dword_F01317E4), %o2
F00B8C48: d202a3e4                 ld      [%o2+%lo(dword_F01317E4)], %o1
F00B8C4C: a0100008                 mov     %o0, %l0
F00B8C50: 80a26000                 cmp     %o1, 0
F00B8C54: 12800006                 bne     loc_F00B8C6C
F00B8C58: 9412a3e4                 bset    %lo(dword_F01317E4), %o2
F00B8C5C: d002bff0                 ld      [%o2-0x10], %o0
F00B8C60: 80a22000                 cmp     %o0, 0
F00B8C64: 12800017                 bne     loc_F00B8CC0
F00B8C68: 9002bff0                 add     %o2, -0x10, %o0
F00B8C6C: 113c04f6                 sethi   %hi(_dvmamap), %o0
F00B8C70: 80a6a000                 cmp     %i2, 0
F00B8C74: 02800005                 be      loc_F00B8C88
F00B8C78: d20222f8                 ld      [%o0+%lo(_dvmamap)], %o1
F00B8C7C: 113c02e3                 sethi   %hi(sub_F00B8D20), %o0
F00B8C80: 10800003                 ba      loc_F00B8C8C
F00B8C84: 96122120                 or      %o0, %lo(sub_F00B8D20), %o3
F00B8C88: 96102000                 mov     0, %o3
F00B8C8C: 90100009                 mov     %o1, %o0
F00B8C90: 92100019                 mov     %i1, %o1
F00B8C94: 94102041                 mov     0x41, %o2 ! 'A'
F00B8C98: 7fff850b                 call    _mb_mapalloc
F00B8C9C: 98102000                 mov     0, %o4
F00B8CA0: 80a22000                 cmp     %o0, 0
F00B8CA4: 12800010                 bne     loc_F00B8CE4
F00B8CA8: d026203c                 st      %o0, [%i0+0x3C]
F00B8CAC: 80a6a000                 cmp     %i2, 0
F00B8CB0: 02800009                 be      loc_F00B8CD4
F00B8CB4: 113c04c5                 sethi   %hi(dword_F01317D4), %o0
F00B8CB8: 10800005                 ba      loc_F00B8CCC
F00B8CBC: 901223d4                 bset    %lo(dword_F01317D4), %o0
F00B8CC0: 80a6a000                 cmp     %i2, 0
F00B8CC4: 02800004                 be      loc_F00B8CD4
F00B8CC8: 01000000                 nop
F00B8CCC: 40000054                 call    sub_F00B8E1C
F00B8CD0: 9210001a                 mov     %i2, %o1
F00B8CD4: 7fff7814                 call    _splx
F00B8CD8: 90100010                 mov     %l0, %o0
F00B8CDC: 1080000f                 ba      locret_F00B8D18
F00B8CE0: b0102000                 mov     0, %i0
F00B8CE4: 7fff7810                 call    _splx
F00B8CE8: 90100010                 mov     %l0, %o0
F00B8CEC: d0066014                 ld      [%i1+0x14], %o0
F00B8CF0: d0262040                 st      %o0, [%i0+0x40]
F00B8CF4: d0064000                 ld      [%i1], %o0
F00B8CF8: 808a2001                 btst    1, %o0
F00B8CFC: 12800005                 bne     loc_F00B8D10
F00B8D00: d016205c                 lduh    [%i0+0x5C], %o0
F00B8D04: 90122002                 bset    2, %o0
F00B8D08: d036205c                 sth     %o0, [%i0+0x5C]
F00B8D0C: d016205c                 lduh    [%i0+0x5C], %o0
F00B8D10: 90122001                 bset    1, %o0
F00B8D14: d036205c                 sth     %o0, [%i0+0x5C]
F00B8D18: 81c7e008                 ret
F00B8D1C: 81e80000                 restore
