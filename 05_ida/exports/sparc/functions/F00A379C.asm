F00A379C: 9de3bf98                 save    %sp, -0x68, %sp
F00A37A0: 113c0464                 sethi   %hi(aData_2), %o0! "__DATA"
F00A37A4: 7fff1acf                 call    _getsegbyname
F00A37A8: 90122378                 bset    %lo(aData_2), %o0! "__DATA"
F00A37AC: a2920000                 orcc    %o0, %g0, %l1
F00A37B0: 02800013                 be      locret_F00A37FC
F00A37B4: 01000000                 nop
F00A37B8: 7fff1ae4                 call    _firstsect
F00A37BC: 01000000                 nop
F00A37C0: 1080000c                 ba      loc_F00A37F0
F00A37C4: a0100008                 mov     %o0, %l0
F00A37C8: 808a2001                 btst    1, %o0
F00A37CC: 02800006                 be      loc_F00A37E4
F00A37D0: 90100011                 mov     %l1, %o0
F00A37D4: d0042020                 ld      [%l0+0x20], %o0! void *
F00A37D8: 7fffc5a0                 call    _bzero
F00A37DC: d2042024                 ld      [%l0+0x24], %o1
F00A37E0: 90100011                 mov     %l1, %o0
F00A37E4: 7fff1ae4                 call    _nextsect
F00A37E8: 92100010                 mov     %l0, %o1
F00A37EC: a0100008                 mov     %o0, %l0
F00A37F0: 80a42000                 cmp     %l0, 0
F00A37F4: 32bffff5                 bne,a   loc_F00A37C8
F00A37F8: d0042038                 ld      [%l0+0x38], %o0
F00A37FC: 81c7e008                 ret
F00A3800: 81e80000                 restore
