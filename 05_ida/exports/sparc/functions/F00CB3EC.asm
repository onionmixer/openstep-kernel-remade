F00CB3EC: 9de3bf88                 save    %sp, -0x78, %sp
F00CB3F0: f027bff0                 st      %i0, [%fp+var_10]
F00CB3F4: 9007bff0                 add     %fp, var_10, %o0! objc_super *
F00CB3F8: 133c0508                 sethi   %hi(stru_F014209C.super_class), %o1
F00CB3FC: d60260a0                 ld      [%o1+%lo(stru_F014209C.super_class)], %o3
F00CB400: 9410001a                 mov     %i2, %o2
F00CB404: 133c0504                 sethi   %hi(paInitfromdevice), %o1
F00CB408: d20262fc                 ld      [%o1+%lo(paInitfromdevice)], %o1! SEL
F00CB40C: 4000995c                 call    _objc_msgSendSuper
F00CB410: d627bff4                 st      %o3, [%fp+var_C]
F00CB414: 80a22000                 cmp     %o0, 0
F00CB418: 22800048                 be,a    locret_F00CB538
F00CB41C: b0102000                 mov     0, %i0
F00CB420: 113c0506                 sethi   %hi(paStartiothread), %o0! id
F00CB424: d202206c                 ld      [%o0+%lo(paStartiothread)], %o1! SEL
F00CB428: 40009912                 call    _objc_msgSend
F00CB42C: 90100018                 mov     %i0, %o0
F00CB430: 80a22000                 cmp     %o0, 0
F00CB434: 1280003d                 bne     loc_F00CB528
F00CB438: 113c0503                 sethi   -0xFEBF400, %o0
F00CB43C: 113c0506                 sethi   %hi(paDrivercmd), %o0
F00CB440: d00222ec                 ld      [%o0+%lo(paDrivercmd)], %o0! id
F00CB444: 133c0503                 sethi   %hi(paAlloc), %o1! SEL
F00CB448: 4000990a                 call    _objc_msgSend
F00CB44C: d20263f0                 ld      [%o1+%lo(paAlloc)], %o1
F00CB450: a2100008                 mov     %o0, %l1
F00CB454: 113c0506                 sethi   %hi(paInitport), %o0! id
F00CB458: e0022068                 ld      [%o0+%lo(paInitport)], %l0
F00CB45C: 133c0504                 sethi   %hi(paInterruptport_0), %o1
F00CB460: d2026308                 ld      [%o1+%lo(paInterruptport_0)], %o1! SEL
F00CB464: 40009903                 call    _objc_msgSend
F00CB468: 90100018                 mov     %i0, %o0
F00CB46C: 94100008                 mov     %o0, %o2
F00CB470: 90100011                 mov     %l1, %o0! id
F00CB474: 400098ff                 call    _objc_msgSend
F00CB478: 92100010                 mov     %l0, %o1
F00CB47C: d026212c                 st      %o0, [%i0+0x12C]
F00CB480: 113c0506                 sethi   %hi(paNxlock), %o0
F00CB484: d00222a0                 ld      [%o0+%lo(paNxlock)], %o0! id
F00CB488: 133c0504                 sethi   %hi(paNew), %o1! SEL
F00CB48C: 400098f9                 call    _objc_msgSend
F00CB490: d2026238                 ld      [%o1+%lo(paNew)], %o1
F00CB494: d0262138                 st      %o0, [%i0+0x138]
F00CB498: 90062144                 add     %i0, 0x144, %o0
F00CB49C: d0262148                 st      %o0, [%i0+0x148]
F00CB4A0: d0262144                 st      %o0, [%i0+0x144]
F00CB4A4: a207bfe8                 add     %fp, var_18, %l1
F00CB4A8: 90100011                 mov     %l1, %o0! char *
F00CB4AC: 133c03ec921260a8         set     aSD, %o1! "%s%d"
F00CB4B4: 193c04cc                 sethi   %hi(dword_F01330C4), %o4
F00CB4B8: 153c04bb                 sethi   %hi(unk_F012ECB8), %o2
F00CB4BC: e00320c4                 ld      [%o4+%lo(dword_F01330C4)], %l0
F00CB4C0: 9412a0b8                 bset    %lo(unk_F012ECB8), %o2
F00CB4C4: 96042001                 add     %l0, 1, %o3
F00CB4C8: d62320c4                 st      %o3, [%o4+%lo(dword_F01330C4)]
F00CB4CC: 7ffd24a7                 call    _sprintf
F00CB4D0: 96100010                 mov     %l0, %o3
F00CB4D4: 90100018                 mov     %i0, %o0! id
F00CB4D8: 133c0504                 sethi   %hi(paSetname), %o1
F00CB4DC: d202624c                 ld      [%o1+%lo(paSetname)], %o1! SEL
F00CB4E0: 400098e4                 call    _objc_msgSend
F00CB4E4: 94100011                 mov     %l1, %o2
F00CB4E8: 90100018                 mov     %i0, %o0! id
F00CB4EC: 133c0504                 sethi   %hi(paSetdevicekind), %o1
F00CB4F0: 153c04bb                 sethi   %hi(aEthernet), %o2! "Ethernet"
F00CB4F4: d2026250                 ld      [%o1+%lo(paSetdevicekind)], %o1! SEL
F00CB4F8: 400098de                 call    _objc_msgSend
F00CB4FC: 9412a0c0                 bset    %lo(aEthernet), %o2! "Ethernet"
F00CB500: 90100018                 mov     %i0, %o0! id
F00CB504: 133c0504                 sethi   %hi(paSetunit), %o1
F00CB508: d2026248                 ld      [%o1+%lo(paSetunit)], %o1! SEL
F00CB50C: 400098d9                 call    _objc_msgSend
F00CB510: 94100010                 mov     %l0, %o2
F00CB514: 113c0504                 sethi   %hi(paRegisterdevice), %o0! id
F00CB518: d202225c                 ld      [%o0+%lo(paRegisterdevice)], %o1! SEL
F00CB51C: 400098d5                 call    _objc_msgSend
F00CB520: 90100018                 mov     %i0, %o0! id
F00CB524: 30800005                 ba,a    locret_F00CB538
F00CB528: d20223fc                 ld      [%o0+0x3FC], %o1! SEL
F00CB52C: 400098d1                 call    _objc_msgSend
F00CB530: 90100018                 mov     %i0, %o0
F00CB534: b0102000                 mov     0, %i0
F00CB538: 81c7e008                 ret
F00CB53C: 81e80000                 restore
