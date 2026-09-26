F00AE3E8: 9de3bf98                 save    %sp, -0x68, %sp
F00AE3EC: f4068000                 ld      [%i2], %i2
F00AE3F0: 131ffc00                 sethi   0x7FF00000, %o1
F00AE3F4: c026601c                 clr     [%i1+0x1C]
F00AE3F8: c0266020                 clr     [%i1+0x20]
F00AE3FC: 9136a01f                 srl     %i2, 31, %o0
F00AE400: d0264000                 st      %o0, [%i1]
F00AE404: f6266010                 st      %i3, [%i1+0x10]
F00AE408: c0266014                 clr     [%i1+0x14]
F00AE40C: 113ffc00                 sethi   -0x100000, %o0
F00AE410: a02e8008                 andn    %i2, %o0, %l0
F00AE414: 908e8009                 andcc   %i2, %o1, %o0
F00AE418: 12800011                 bne     loc_F00AE45C
F00AE41C: c0266018                 clr     [%i1+0x18]
F00AE420: 80a42000                 cmp     %l0, 0
F00AE424: 12800007                 bne     loc_F00AE440
F00AE428: 90102001                 mov     1, %o0
F00AE42C: 80a6e000                 cmp     %i3, 0
F00AE430: 32800005                 bne,a   loc_F00AE444
F00AE434: d0266004                 st      %o0, [%i1+4]
F00AE438: 10800031                 ba      locret_F00AE4FC
F00AE43C: c0266004                 clr     [%i1+4]
F00AE440: d0266004                 st      %o0, [%i1+4]
F00AE444: 90103bfe                 mov     -0x402, %o0
F00AE448: d0266008                 st      %o0, [%i1+8]
F00AE44C: e026600c                 st      %l0, [%i1+0xC]
F00AE450: 400000e2                 call    _fpu_normalize
F00AE454: 90100019                 mov     %i1, %o0
F00AE458: 30800029                 ba,a    locret_F00AE4FC
F00AE45C: 80a20009                 cmp     %o0, %o1
F00AE460: 32800018                 bne,a   loc_F00AE4C0
F00AE464: 9136a014                 srl     %i2, 20, %o0
F00AE468: 8094001b                 orcc    %l0, %i3, %g0
F00AE46C: 12800005                 bne     loc_F00AE480
F00AE470: 11000200                 sethi   0x80000, %o0
F00AE474: 90102002                 mov     2, %o0
F00AE478: 10800021                 ba      locret_F00AE4FC
F00AE47C: d0266004                 st      %o0, [%i1+4]
F00AE480: 808c0008                 btst    %o0, %l0
F00AE484: 22800005                 be,a    loc_F00AE498
F00AE488: 90102005                 mov     5, %o0
F00AE48C: 90102004                 mov     4, %o0
F00AE490: 10800006                 ba      loc_F00AE4A8
F00AE494: d0266004                 st      %o0, [%i1+4]
F00AE498: d0266004                 st      %o0, [%i1+4]
F00AE49C: 90100018                 mov     %i0, %o0
F00AE4A0: 40000189                 call    _fpu_set_exception
F00AE4A4: 92102004                 mov     4, %o1
F00AE4A8: 91342004                 srl     %l0, 4, %o0
F00AE4AC: 13000060                 sethi   0x18000, %o1
F00AE4B0: 90120009                 bset    %o1, %o0
F00AE4B4: d026600c                 st      %o0, [%i1+0xC]
F00AE4B8: 1080000c                 ba      loc_F00AE4E8
F00AE4BC: 912c201c                 sll     %l0, 28, %o0
F00AE4C0: 900a27ff                 and     %o0, 0x7FF, %o0
F00AE4C4: 90023c01                 inc     -0x3FF, %o0
F00AE4C8: d0266008                 st      %o0, [%i1+8]
F00AE4CC: 90102001                 mov     1, %o0
F00AE4D0: d0266004                 st      %o0, [%i1+4]
F00AE4D4: 91342004                 srl     %l0, 4, %o0
F00AE4D8: 13000040                 sethi   0x10000, %o1
F00AE4DC: 90120009                 bset    %o1, %o0
F00AE4E0: d026600c                 st      %o0, [%i1+0xC]
F00AE4E4: 912ea01c                 sll     %i2, 28, %o0
F00AE4E8: 9336e004                 srl     %i3, 4, %o1
F00AE4EC: 90120009                 bset    %o1, %o0
F00AE4F0: d0266010                 st      %o0, [%i1+0x10]
F00AE4F4: 912ee01c                 sll     %i3, 28, %o0
F00AE4F8: d0266014                 st      %o0, [%i1+0x14]
F00AE4FC: 81c7e008                 ret
F00AE500: 81e80000                 restore
