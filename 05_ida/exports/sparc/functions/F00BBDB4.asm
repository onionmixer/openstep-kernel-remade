F00BBDB4: 9de3bf98                 save    %sp, -0x68, %sp
F00BBDB8: d2062040                 ld      [%i0+0x40], %o1
F00BBDBC: 808a6121                 btst    0x121, %o1
F00BBDC0: 1280001f                 bne     loc_F00BBE3C
F00BBDC4: 113c042d                 sethi   -0xFEF4C00, %o0
F00BBDC8: d0062018                 ld      [%i0+0x18], %o0
F00BBDCC: 80a22000                 cmp     %o0, 0
F00BBDD0: 0280001a                 be      loc_F00BBE38
F00BBDD4: 90126020                 or      %o1, 0x20, %o0
F00BBDD8: d0262040                 st      %o0, [%i0+0x40]
F00BBDDC: 113c042d                 sethi   %hi(_ttlowat), %o0
F00BBDE0: d20e204a                 ldub    [%i0+0x4A], %o1
F00BBDE4: 90122360                 bset    %lo(_ttlowat), %o0
F00BBDE8: 920a601f                 and     %o1, 0x1F, %o1
F00BBDEC: 932a6001                 sll     %o1, 1, %o1
F00BBDF0: d2524008                 ldsh    [%o1+%o0], %o1
F00BBDF4: d0062018                 ld      [%i0+0x18], %o0
F00BBDF8: 80a20009                 cmp     %o0, %o1
F00BBDFC: 04800007                 ble     loc_F00BBE18
F00BBE00: 90102004                 mov     4, %o0
F00BBE04: 133c02ef921262b8         set     sub_F00BBEB8, %o1
F00BBE0C: 7fff783b                 call    _callout_dispatch
F00BBE10: 94100018                 mov     %i0, %o2
F00BBE14: 30800027                 ba,a    locret_F00BBEB0
F00BBE18: 113c02ef901222b8         set     sub_F00BBEB8, %o0
F00BBE20: 92100018                 mov     %i0, %o1
F00BBE24: 94102000                 mov     0, %o2
F00BBE28: 961023e8                 mov     0x3E8, %o3
F00BBE2C: 7ffec8be                 call    _ns_timeout
F00BBE30: 98102004                 mov     4, %o4
F00BBE34: 3080001f                 ba,a    locret_F00BBEB0
F00BBE38: 113c042d                 sethi   -0xFEF4C00, %o0
F00BBE3C: d20e204a                 ldub    [%i0+0x4A], %o1
F00BBE40: 90122360                 bset    0x360, %o0
F00BBE44: 920a601f                 and     %o1, 0x1F, %o1
F00BBE48: 932a6001                 sll     %o1, 1, %o1
F00BBE4C: d2524008                 ldsh    [%o1+%o0], %o1
F00BBE50: d0062018                 ld      [%i0+0x18], %o0
F00BBE54: 80a20009                 cmp     %o0, %o1
F00BBE58: 14800016                 bg      locret_F00BBEB0
F00BBE5C: 01000000                 nop
F00BBE60: d0062040                 ld      [%i0+0x40], %o0
F00BBE64: 808a2040                 btst    0x40, %o0 ! '@'
F00BBE68: 02800005                 be      loc_F00BBE7C
F00BBE6C: 900a3fbf                 and     %o0, -0x41, %o0
F00BBE70: d0262040                 st      %o0, [%i0+0x40]
F00BBE74: 7ffd5bdd                 call    _wakeup
F00BBE78: 90062018                 add     %i0, 0x18, %o0
F00BBE7C: d006202c                 ld      [%i0+0x2C], %o0
F00BBE80: 80a22000                 cmp     %o0, 0
F00BBE84: 0280000b                 be      locret_F00BBEB0
F00BBE88: 13000004                 sethi   0x1000, %o1
F00BBE8C: d4062040                 ld      [%i0+0x40], %o2
F00BBE90: 7ffd68a1                 call    _selwakeup
F00BBE94: 920a8009                 and     %o2, %o1, %o1
F00BBE98: 7ffd688f                 call    _selthreadclear
F00BBE9C: 9006202c                 add     %i0, 0x2C, %o0 ! ','
F00BBEA0: d2062040                 ld      [%i0+0x40], %o1
F00BBEA4: 11000004                 sethi   0x1000, %o0
F00BBEA8: 902a4008                 andn    %o1, %o0, %o0
F00BBEAC: d0262040                 st      %o0, [%i0+0x40]
F00BBEB0: 81c7e008                 ret
F00BBEB4: 91e82000                 restore %g0, 0, %o0
