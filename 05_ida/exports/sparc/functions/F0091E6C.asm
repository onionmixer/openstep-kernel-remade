F0091E6C: 9de3bf98                 save    %sp, -0x68, %sp
F0091E70: 1300003f                 sethi   0xFC00, %o1
F0091E74: d0060000                 ld      [%i0], %o0
F0091E78: 92126300                 bset    0x300, %o1
F0091E7C: 900a0009                 and     %o0, %o1, %o0
F0091E80: 91322008                 srl     %o0, 8, %o0
F0091E84: d0264000                 st      %o0, [%i1]
F0091E88: 90102020                 mov     0x20, %o0 ! ' '
F0091E8C: d0266004                 st      %o0, [%i1+4]
F0091E90: d006200c                 ld      [%i0+0xC], %o0
F0091E94: d0266008                 st      %o0, [%i1+8]
F0091E98: c026600c                 clr     [%i1+0xC]
F0091E9C: c0266010                 clr     [%i1+0x10]
F0091EA0: d0062014                 ld      [%i0+0x14], %o0
F0091EA4: 90022064                 inc     0x64, %o0 ! 'd'
F0091EA8: d0266014                 st      %o0, [%i1+0x14]
F0091EAC: 113c0448                 sethi   %hi(dword_F01123A0), %o0
F0091EB0: d00223a0                 ld      [%o0+%lo(dword_F01123A0)], %o0
F0091EB4: d0266018                 st      %o0, [%i1+0x18]
F0091EB8: d2062014                 ld      [%i0+0x14], %o1
F0091EBC: 90027574                 add     %o1, -0xA8C, %o0
F0091EC0: 80a22026                 cmp     %o0, 0x26 ! '&'
F0091EC4: 18800008                 bgu     loc_F0091EE4
F0091EC8: 113c043e                 sethi   %hi(_exception_raise_misses), %o0
F0091ECC: 901220d4                 bset    %lo(_exception_raise_misses), %o0
F0091ED0: 932a6002                 sll     %o1, 2, %o1
F0091ED4: d4024008                 ld      [%o1+%o0], %o2
F0091ED8: 80a2a000                 cmp     %o2, 0
F0091EDC: 12800006                 bne     loc_F0091EF4
F0091EE0: 90100018                 mov     %i0, %o0
F0091EE4: 90103ed1                 mov     -0x12F, %o0
F0091EE8: d026601c                 st      %o0, [%i1+0x1C]
F0091EEC: 10800005                 ba      locret_F0091F00
F0091EF0: b0102000                 mov     0, %i0
F0091EF4: 9fc28000                 call    %o2
F0091EF8: 92100019                 mov     %i1, %o1
F0091EFC: b0102001                 mov     1, %i0
F0091F00: 81c7e008                 ret
F0091F04: 81e80000                 restore
