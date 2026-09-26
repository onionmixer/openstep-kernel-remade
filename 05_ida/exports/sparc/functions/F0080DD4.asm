F0080DD4: 9de3bf98                 save    %sp, -0x68, %sp
F0080DD8: 1300003f                 sethi   0xFC00, %o1
F0080DDC: d0060000                 ld      [%i0], %o0
F0080DE0: 92126300                 bset    0x300, %o1
F0080DE4: 900a0009                 and     %o0, %o1, %o0
F0080DE8: 91322008                 srl     %o0, 8, %o0
F0080DEC: d0264000                 st      %o0, [%i1]
F0080DF0: 90102020                 mov     0x20, %o0 ! ' '
F0080DF4: d0266004                 st      %o0, [%i1+4]
F0080DF8: d006200c                 ld      [%i0+0xC], %o0
F0080DFC: d0266008                 st      %o0, [%i1+8]
F0080E00: c026600c                 clr     [%i1+0xC]
F0080E04: c0266010                 clr     [%i1+0x10]
F0080E08: d0062014                 ld      [%i0+0x14], %o0
F0080E0C: 90022064                 inc     0x64, %o0 ! 'd'
F0080E10: d0266014                 st      %o0, [%i1+0x14]
F0080E14: 113c0445                 sethi   %hi(dword_F0111790), %o0
F0080E18: d0022390                 ld      [%o0+%lo(dword_F0111790)], %o0
F0080E1C: d0266018                 st      %o0, [%i1+0x18]
F0080E20: d2062014                 ld      [%i0+0x14], %o1
F0080E24: 90027448                 add     %o1, -0xBB8, %o0
F0080E28: 80a22015                 cmp     %o0, 0x15
F0080E2C: 18800008                 bgu     loc_F0080E4C
F0080E30: 113c043a                 sethi   %hi(aFreeBlockBadSi+0x10), %o0! "size"
F0080E34: 90122058                 bset    %lo(aFreeBlockBadSi+0x10), %o0! "size"
F0080E38: 932a6002                 sll     %o1, 2, %o1
F0080E3C: d4024008                 ld      [%o1+%o0], %o2
F0080E40: 80a2a000                 cmp     %o2, 0
F0080E44: 12800006                 bne     loc_F0080E5C
F0080E48: 90100018                 mov     %i0, %o0
F0080E4C: 90103ed1                 mov     -0x12F, %o0
F0080E50: d026601c                 st      %o0, [%i1+0x1C]
F0080E54: 10800005                 ba      locret_F0080E68
F0080E58: b0102000                 mov     0, %i0
F0080E5C: 9fc28000                 call    %o2
F0080E60: 92100019                 mov     %i1, %o1
F0080E64: b0102001                 mov     1, %i0
F0080E68: 81c7e008                 ret
F0080E6C: 81e80000                 restore
