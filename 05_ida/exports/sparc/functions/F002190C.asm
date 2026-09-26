F002190C: 9de3bf70                 save    %sp, -0x90, %sp! int
F0021910: 233c04cf                 sethi   %hi(dword_F0133DDC), %l1
F0021914: d00461dc                 ld      [%l1+%lo(dword_F0133DDC)], %o0
F0021918: e0022024                 ld      [%o0+0x24], %l0
F002191C: d0042014                 ld      [%l0+0x14], %o0! int
F0021920: 80a22000                 cmp     %o0, 0
F0021924: 02800007                 be      loc_F0021940
F0021928: 9207bfd4                 add     %fp, var_2C, %o1! int
F002192C: 4001d9cb                 call    _copyin
F0021930: 94102004                 mov     4, %o2
F0021934: d20461dc                 ld      [%l1+%lo(dword_F0133DDC)], %o1
F0021938: 10800003                 ba      loc_F0021944
F002193C: d02a6038                 stb     %o0, [%o1+0x38]
F0021940: c027bfe4                 clr     [%fp+var_20+4]
F0021944: 113c04cf                 sethi   %hi(dword_F0133DDC), %o0
F0021948: d00221dc                 ld      [%o0+%lo(dword_F0133DDC)], %o0
F002194C: d04a2038                 ldsb    [%o0+0x38], %o0
F0021950: 80a22000                 cmp     %o0, 0
F0021954: 12800014                 bne     locret_F00219A4
F0021958: d207bfd4                 ld      [%fp+var_2C], %o1
F002195C: d0042010                 ld      [%l0+0x10], %o0
F0021960: d03fbfe0                 std     %o0, [%fp+var_20]
F0021964: 9007bfd8                 add     %fp, var_28, %o0
F0021968: d027bfe8                 st      %o0, [%fp+var_18]
F002196C: 90102001                 mov     1, %o0
F0021970: d027bfec                 st      %o0, [%fp+var_14]
F0021974: d0042004                 ld      [%l0+4], %o0
F0021978: d027bfd8                 st      %o0, [%fp+var_28]
F002197C: d0042008                 ld      [%l0+8], %o0
F0021980: d027bfdc                 st      %o0, [%fp+var_24]
F0021984: c027bff0                 clr     [%fp+var_10]
F0021988: c027bff4                 clr     [%fp+var_C]
F002198C: d0040000                 ld      [%l0], %o0
F0021990: d404200c                 ld      [%l0+0xC], %o2
F0021994: 98102000                 mov     0, %o4
F0021998: d6042014                 ld      [%l0+0x14], %o3
F002199C: 40000052                 call    _recvit
F00219A0: 9207bfe0                 add     %fp, var_20, %o1
F00219A4: 81c7e008                 ret
F00219A8: 81e80000                 restore
