F0080234: 9de3bf98                 save    %sp, -0x68, %sp
F0080238: 1300003f                 sethi   0xFC00, %o1
F008023C: d0060000                 ld      [%i0], %o0
F0080240: 92126300                 bset    0x300, %o1
F0080244: 900a0009                 and     %o0, %o1, %o0
F0080248: 91322008                 srl     %o0, 8, %o0
F008024C: d0264000                 st      %o0, [%i1]
F0080250: 90102020                 mov     0x20, %o0 ! ' '
F0080254: d0266004                 st      %o0, [%i1+4]
F0080258: d006200c                 ld      [%i0+0xC], %o0
F008025C: d0266008                 st      %o0, [%i1+8]
F0080260: c026600c                 clr     [%i1+0xC]
F0080264: c0266010                 clr     [%i1+0x10]
F0080268: d0062014                 ld      [%i0+0x14], %o0
F008026C: 90022064                 inc     0x64, %o0 ! 'd'
F0080270: d0266014                 st      %o0, [%i1+0x14]
F0080274: 113c0445                 sethi   %hi(dword_F011166C), %o0
F0080278: d002226c                 ld      [%o0+%lo(dword_F011166C)], %o0
F008027C: d0266018                 st      %o0, [%i1+0x18]
F0080280: d2062014                 ld      [%i0+0x14], %o1
F0080284: 90027830                 add     %o1, -0x7D0, %o0
F0080288: 80a22067                 cmp     %o0, 0x67 ! 'g'
F008028C: 18800008                 bgu     loc_F00802AC
F0080290: 113c043d                 sethi   %hi(aDroppedMsgAcce_0+4), %o0! "ped msg-accepted-compat (0x%08x, 0x%x)"...
F0080294: 9012218c                 bset    %lo(aDroppedMsgAcce_0+4), %o0! "ped msg-accepted-compat (0x%08x, 0x%x)"...
F0080298: 932a6002                 sll     %o1, 2, %o1
F008029C: d4024008                 ld      [%o1+%o0], %o2
F00802A0: 80a2a000                 cmp     %o2, 0
F00802A4: 12800006                 bne     loc_F00802BC
F00802A8: 90100018                 mov     %i0, %o0
F00802AC: 90103ed1                 mov     -0x12F, %o0
F00802B0: d026601c                 st      %o0, [%i1+0x1C]
F00802B4: 10800005                 ba      locret_F00802C8
F00802B8: b0102000                 mov     0, %i0
F00802BC: 9fc28000                 call    %o2
F00802C0: 92100019                 mov     %i1, %o1
F00802C4: b0102001                 mov     1, %i0
F00802C8: 81c7e008                 ret
F00802CC: 81e80000                 restore
