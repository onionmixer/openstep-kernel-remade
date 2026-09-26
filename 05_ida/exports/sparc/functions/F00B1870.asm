F00B1870: 9de3bf98                 save    %sp, -0x68, %sp
F00B1874: 293c04d4                 sethi   %hi(_cons_tp), %l4
F00B1878: 7ffda61c                 call    _ttynty
F00B187C: d0052290                 ld      [%l4+%lo(_cons_tp)], %o0
F00B1880: 273c04cf                 sethi   %hi(_active_u), %l3
F00B1884: d204e1d8                 ld      [%l3+%lo(_active_u)], %o1
F00B1888: e2024000                 ld      [%o1], %l1
F00B188C: d2052290                 ld      [%l4+%lo(_cons_tp)], %o1
F00B1890: a4100008                 mov     %o0, %l2
F00B1894: d0546030                 ldsh    [%l1+0x30], %o0
F00B1898: 7ffd74a2                 call    _get_posix_proc
F00B189C: ea126038                 lduh    [%o1+0x38], %l5
F00B18A0: 13000010                 sethi   0x4000, %o1
F00B18A4: d4046014                 ld      [%l1+0x14], %o2
F00B18A8: 808a8009                 btst    %o1, %o2
F00B18AC: 02800029                 be      loc_F00B1950
F00B18B0: a0100008                 mov     %o0, %l0
F00B18B4: d0042010                 ld      [%l0+0x10], %o0
F00B18B8: d2022008                 ld      [%o0+8], %o1
F00B18BC: d0026004                 ld      [%o1+4], %o0
F00B18C0: 80a20011                 cmp     %o0, %l1
F00B18C4: 12800048                 bne     loc_F00B19E4
F00B18C8: 952d6010                 sll     %l5, 16, %o2
F00B18CC: d0026008                 ld      [%o1+8], %o0
F00B18D0: 80a22000                 cmp     %o0, 0
F00B18D4: 12800044                 bne     loc_F00B19E4
F00B18D8: 01000000                 nop
F00B18DC: d004a008                 ld      [%l2+8], %o0
F00B18E0: 80a22000                 cmp     %o0, 0
F00B18E4: 12800041                 bne     loc_F00B19E8
F00B18E8: 913aa010                 sra     %o2, 16, %o0
F00B18EC: d0042018                 ld      [%l0+0x18], %o0
F00B18F0: 15100000                 sethi   0x40000000, %o2
F00B18F4: 808a000a                 btst    %o2, %o0
F00B18F8: 3280003b                 bne,a   loc_F00B19E4
F00B18FC: 952d6010                 sll     %l5, 16, %o2
F00B1900: d004e1d8                 ld      [%l3+0x1D8], %o0
F00B1904: d2052290                 ld      [%l4+0x290], %o1
F00B1908: d2222164                 st      %o1, [%o0+0x164]
F00B190C: d004e1d8                 ld      [%l3+0x1D8], %o0
F00B1910: f0322168                 sth     %i0, [%o0+0x168]
F00B1914: d0042010                 ld      [%l0+0x10], %o0
F00B1918: d0022008                 ld      [%o0+8], %o0
F00B191C: d024a008                 st      %o0, [%l2+8]
F00B1920: d0042010                 ld      [%l0+0x10], %o0
F00B1924: d0022008                 ld      [%o0+8], %o0
F00B1928: d2222008                 st      %o1, [%o0+8]
F00B192C: d0042010                 ld      [%l0+0x10], %o0
F00B1930: d024a00c                 st      %o0, [%l2+0xC]
F00B1934: d0042010                 ld      [%l0+0x10], %o0
F00B1938: d002200c                 ld      [%o0+0xC], %o0
F00B193C: d0326044                 sth     %o0, [%o1+0x44]
F00B1940: d0046028                 ld      [%l1+0x28], %o0
F00B1944: 9012000a                 bset    %o2, %o0
F00B1948: 10800026                 ba      loc_F00B19E0
F00B194C: d0246028                 st      %o0, [%l1+0x28]
F00B1950: d2046028                 ld      [%l1+0x28], %o1
F00B1954: 11100000                 sethi   0x40000000, %o0
F00B1958: 808a4008                 btst    %o0, %o1
F00B195C: 12800022                 bne     loc_F00B19E4
F00B1960: 952d6010                 sll     %l5, 16, %o2
F00B1964: d004e1d8                 ld      [%l3+0x1D8], %o0
F00B1968: d2052290                 ld      [%l4+0x290], %o1
F00B196C: d2222164                 st      %o1, [%o0+0x164]
F00B1970: d004e1d8                 ld      [%l3+0x1D8], %o0
F00B1974: f0322168                 sth     %i0, [%o0+0x168]
F00B1978: d0042010                 ld      [%l0+0x10], %o0
F00B197C: d0022008                 ld      [%o0+8], %o0
F00B1980: d024a008                 st      %o0, [%l2+8]
F00B1984: d0042010                 ld      [%l0+0x10], %o0
F00B1988: d0022008                 ld      [%o0+8], %o0
F00B198C: d2222008                 st      %o1, [%o0+8]
F00B1990: d2526044                 ldsh    [%o1+0x44], %o1
F00B1994: 80a26000                 cmp     %o1, 0
F00B1998: 3280000d                 bne,a   loc_F00B19CC
F00B199C: d054602e                 ldsh    [%l1+0x2E], %o0
F00B19A0: 90100011                 mov     %l1, %o0
F00B19A4: d2522030                 ldsh    [%o0+0x30], %o1
F00B19A8: 7ffd7343                 call    _enterpgrp
F00B19AC: 94102000                 mov     0, %o2
F00B19B0: d0042010                 ld      [%l0+0x10], %o0
F00B19B4: d2052290                 ld      [%l4+0x290], %o1
F00B19B8: d024a00c                 st      %o0, [%l2+0xC]
F00B19BC: d0042010                 ld      [%l0+0x10], %o0
F00B19C0: d002200c                 ld      [%o0+0xC], %o0
F00B19C4: 10800007                 ba      loc_F00B19E0
F00B19C8: d0326044                 sth     %o0, [%o1+0x44]
F00B19CC: 80a24008                 cmp     %o1, %o0
F00B19D0: 02800004                 be      loc_F00B19E0
F00B19D4: 90100011                 mov     %l1, %o0
F00B19D8: 7ffd7337                 call    _enterpgrp
F00B19DC: 94102000                 mov     0, %o2
F00B19E0: 952d6010                 sll     %l5, 16, %o2
F00B19E4: 913aa010                 sra     %o2, 16, %o0
F00B19E8: 9532a018                 srl     %o2, 24, %o2
F00B19EC: 932aa001                 sll     %o2, 1, %o1
F00B19F0: 9202400a                 add     %o1, %o2, %o1
F00B19F4: 932a6002                 sll     %o1, 2, %o1
F00B19F8: 9222400a                 sub     %o1, %o2, %o1
F00B19FC: 932a6002                 sll     %o1, 2, %o1
F00B1A00: 153c04729412a1f0         set     _cdevsw, %o2
F00B1A08: d402400a                 ld      [%o1+%o2], %o2
F00B1A0C: 9fc28000                 call    %o2
F00B1A10: 92100019                 mov     %i1, %o1
F00B1A14: 81c7e008                 ret
F00B1A18: 91e80008                 restore %g0, %o0, %o0
