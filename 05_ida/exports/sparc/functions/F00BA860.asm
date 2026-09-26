F00BA860: 9de3bf98                 save    %sp, -0x68, %sp
F00BA864: 2d3c04fc                 sethi   %hi(_zsaline), %l6
F00BA868: 113c04fdaa1221d0         set     _zssoftCAR, %l5
F00BA870: a215a160                 or      %l6, %lo(_zsaline), %l1
F00BA874: 80a44015                 cmp     %l1, %l5
F00BA878: 1a80001a                 bcc     loc_F00BA8E0
F00BA87C: a6102000                 mov     0, %l3
F00BA880: a8046470                 add     %l1, 0x470, %l4
F00BA884: a004600c                 add     %l1, 0xC, %l0
F00BA888: d0540000                 ldsh    [%l0], %o0
F00BA88C: 80a22000                 cmp     %o0, 0
F00BA890: 22800011                 be,a    loc_F00BA8D4
F00BA894: a204611c                 inc     0x11C, %l1
F00BA898: 7fff70e0                 call    _spl3
F00BA89C: c0340000                 clrh    [%l0]
F00BA8A0: a4100008                 mov     %o0, %l2
F00BA8A4: 4000001d                 call    _zsa_process
F00BA8A8: 90100011                 mov     %l1, %o0
F00BA8AC: 80a22000                 cmp     %o0, 0
F00BA8B0: 02800006                 be      loc_F00BA8C8
F00BA8B4: 01000000                 nop
F00BA8B8: d0140000                 lduh    [%l0], %o0
F00BA8BC: a604e001                 inc     %l3
F00BA8C0: 90022001                 inc     %o0
F00BA8C4: d0340000                 sth     %o0, [%l0]
F00BA8C8: 7fff7117                 call    _splx
F00BA8CC: 90100012                 mov     %l2, %o0
F00BA8D0: a204611c                 inc     0x11C, %l1
F00BA8D4: 80a44014                 cmp     %l1, %l4
F00BA8D8: 0abfffec                 bcs     loc_F00BA888
F00BA8DC: a004211c                 inc     0x11C, %l0
F00BA8E0: 912ce010                 sll     %l3, 16, %o0
F00BA8E4: 80a22000                 cmp     %o0, 0
F00BA8E8: 32bfffe3                 bne,a   loc_F00BA874
F00BA8EC: a215a160                 or      %l6, 0x160, %l1
F00BA8F0: 80a62000                 cmp     %i0, 0
F00BA8F4: 12800007                 bne     locret_F00BA910
F00BA8F8: 113c02ea                 sethi   %hi(_zspoll), %o0
F00BA8FC: 133c047e                 sethi   %hi(_zsticks), %o1
F00BA900: d40262ec                 ld      [%o1+%lo(_zsticks)], %o2
F00BA904: 90122060                 bset    %lo(_zspoll), %o0! int
F00BA908: 7ffd3dc8                 call    _timeout
F00BA90C: 92102000                 mov     0, %o1
F00BA910: 81c7e008                 ret
F00BA914: 81e80000                 restore
