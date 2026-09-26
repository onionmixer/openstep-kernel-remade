F007E080: 9de3bf98                 save    %sp, -0x68, %sp
F007E084: 1300003f                 sethi   0xFC00, %o1
F007E088: d0060000                 ld      [%i0], %o0
F007E08C: 92126300                 bset    0x300, %o1
F007E090: 900a0009                 and     %o0, %o1, %o0
F007E094: 91322008                 srl     %o0, 8, %o0
F007E098: d0264000                 st      %o0, [%i1]
F007E09C: 90102020                 mov     0x20, %o0 ! ' '
F007E0A0: d0266004                 st      %o0, [%i1+4]
F007E0A4: d006200c                 ld      [%i0+0xC], %o0
F007E0A8: d0266008                 st      %o0, [%i1+8]
F007E0AC: c026600c                 clr     [%i1+0xC]
F007E0B0: c0266010                 clr     [%i1+0x10]
F007E0B4: d0062014                 ld      [%i0+0x14], %o0
F007E0B8: 90022064                 inc     0x64, %o0 ! 'd'
F007E0BC: d0266014                 st      %o0, [%i1+0x14]
F007E0C0: 113c0444                 sethi   %hi(dword_F01112E8), %o0
F007E0C4: d00222e8                 ld      [%o0+%lo(dword_F01112E8)], %o0
F007E0C8: d0266018                 st      %o0, [%i1+0x18]
F007E0CC: d2062014                 ld      [%i0+0x14], %o1
F007E0D0: 90027380                 add     %o1, -0xC80, %o0
F007E0D4: 80a22012                 cmp     %o0, 0x12
F007E0D8: 18800008                 bgu     loc_F007E0F8
F007E0DC: 113c0438                 sethi   %hi(aXdrArrayBadSiz+0xC), %o0! "ad size FAILED\n"
F007E0E0: 9012209c                 bset    %lo(aXdrArrayBadSiz+0xC), %o0! "ad size FAILED\n"
F007E0E4: 932a6002                 sll     %o1, 2, %o1
F007E0E8: d4024008                 ld      [%o1+%o0], %o2
F007E0EC: 80a2a000                 cmp     %o2, 0
F007E0F0: 12800006                 bne     loc_F007E108
F007E0F4: 90100018                 mov     %i0, %o0
F007E0F8: 90103ed1                 mov     -0x12F, %o0
F007E0FC: d026601c                 st      %o0, [%i1+0x1C]
F007E100: 10800005                 ba      locret_F007E114
F007E104: b0102000                 mov     0, %i0
F007E108: 9fc28000                 call    %o2
F007E10C: 92100019                 mov     %i1, %o1
F007E110: b0102001                 mov     1, %i0
F007E114: 81c7e008                 ret
F007E118: 81e80000                 restore
