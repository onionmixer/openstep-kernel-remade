F00BA468: 9de3bf98                 save    %sp, -0x68, %sp
F00BA46C: d0062034                 ld      [%i0+0x34], %o0
F00BA470: 7fff71bf                 call    _splzs
F00BA474: e0022018                 ld      [%o0+0x18], %l0
F00BA478: d2062040                 ld      [%i0+0x40], %o1
F00BA47C: 808a6020                 btst    0x20, %o1 ! ' '
F00BA480: 0280000b                 be      loc_F00BA4AC
F00BA484: 94100008                 mov     %o0, %o2
F00BA488: 808a6100                 btst    0x100, %o1
F00BA48C: 32800004                 bne,a   loc_F00BA49C
F00BA490: d014211a                 lduh    [%l0+0x11A], %o0
F00BA494: 10800005                 ba      loc_F00BA4A8
F00BA498: c034211a                 clrh    [%l0+0x11A]
F00BA49C: d2142118                 lduh    [%l0+0x118], %o1
F00BA4A0: 90220009                 sub     %o0, %o1, %o0
F00BA4A4: d034211a                 sth     %o0, [%l0+0x11A]
F00BA4A8: c0342118                 clrh    [%l0+0x118]
F00BA4AC: 7fff721e                 call    _splx
F00BA4B0: 9010000a                 mov     %o2, %o0
F00BA4B4: 81c7e008                 ret
F00BA4B8: 81e80000                 restore
