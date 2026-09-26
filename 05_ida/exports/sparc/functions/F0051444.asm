F0051444: 9de3bf98                 save    %sp, -0x68, %sp
F0051448: 80a6a001                 cmp     %i2, 1
F005144C: 3280000a                 bne,a   loc_F0051474
F0051450: f0062030                 ld      [%i0+0x30], %i0
F0051454: d0060000                 ld      [%i0], %o0
F0051458: d0020000                 ld      [%o0], %o0
F005145C: 80a22000                 cmp     %o0, 0
F0051460: 22800005                 be,a    loc_F0051474
F0051464: f0062030                 ld      [%i0+0x30], %i0
F0051468: 4000eb56                 call    _vnode_uncache
F005146C: 90100018                 mov     %i0, %o0
F0051470: f0062030                 ld      [%i0+0x30], %i0
F0051474: d0162064                 lduh    [%i0+0x64], %o0
F0051478: 1300003c                 sethi   0xF000, %o1
F005147C: 900a0009                 and     %o0, %o1, %o0
F0051480: 13000020                 sethi   0x8000, %o1
F0051484: 80a20009                 cmp     %o0, %o1
F0051488: 32800019                 bne,a   loc_F00514EC
F005148C: a0102000                 mov     0, %l0
F0051490: d0162044                 lduh    [%i0+0x44], %o0
F0051494: 808a2001                 btst    1, %o0
F0051498: 0280000c                 be      loc_F00514C8
F005149C: a0102001                 mov     1, %l0
F00514A0: 90122010                 bset    0x10, %o0
F00514A4: d0362044                 sth     %o0, [%i0+0x44]
F00514A8: 90100018                 mov     %i0, %o0! unsigned int
F00514AC: 7fff0473                 call    _sleep
F00514B0: 9210200a                 mov     0xA, %o1
F00514B4: d0162044                 lduh    [%i0+0x44], %o0
F00514B8: 808a2001                 btst    1, %o0
F00514BC: 12bffffa                 bne     loc_F00514A4
F00514C0: 90122010                 bset    0x10, %o0
F00514C4: d0162044                 lduh    [%i0+0x44], %o0
F00514C8: 808ee002                 btst    2, %i3
F00514CC: 90122001                 bset    1, %o0
F00514D0: 02800007                 be      loc_F00514EC
F00514D4: d0362044                 sth     %o0, [%i0+0x44]
F00514D8: 80a6a001                 cmp     %i2, 1
F00514DC: 12800005                 bne     loc_F00514F0
F00514E0: 90100018                 mov     %i0, %o0
F00514E4: d0062070                 ld      [%i0+0x70], %o0
F00514E8: d0266008                 st      %o0, [%i1+8]
F00514EC: 90100018                 mov     %i0, %o0
F00514F0: 92100019                 mov     %i1, %o1
F00514F4: 9410001a                 mov     %i2, %o2
F00514F8: 40000032                 call    sub_F00515C0
F00514FC: 9610001b                 mov     %i3, %o3
F0051500: d2162044                 lduh    [%i0+0x44], %o1
F0051504: 808a6046                 btst    0x46, %o1 ! 'F'
F0051508: 0280001d                 be      loc_F005157C
F005150C: b4100008                 mov     %o0, %i2
F0051510: 90126008                 or      %o1, 8, %o0
F0051514: d0362044                 sth     %o0, [%i0+0x44]
F0051518: 333c04d4                 sethi   %hi(_iuniqtime), %i1
F005151C: 4000742d                 call    _microtime
F0051520: 90166148                 or      %i1, %lo(_iuniqtime), %o0
F0051524: d0162044                 lduh    [%i0+0x44], %o0
F0051528: 808a2004                 btst    4, %o0
F005152C: 02800003                 be      loc_F0051538
F0051530: d0066148                 ld      [%i1+%lo(_iuniqtime)], %o0
F0051534: d0262074                 st      %o0, [%i0+0x74]
F0051538: d0162044                 lduh    [%i0+0x44], %o0
F005153C: 808a2002                 btst    2, %o0
F0051540: 02800003                 be      loc_F005154C
F0051544: d0066148                 ld      [%i1+0x148], %o0
F0051548: d026207c                 st      %o0, [%i0+0x7C]
F005154C: d0162044                 lduh    [%i0+0x44], %o0
F0051550: 808a2040                 btst    0x40, %o0 ! '@'
F0051554: 22800006                 be,a    loc_F005156C
F0051558: d2162044                 lduh    [%i0+0x44], %o1
F005155C: c026204c                 clr     [%i0+0x4C]
F0051560: d0066148                 ld      [%i1+0x148], %o0
F0051564: d0262084                 st      %o0, [%i0+0x84]
F0051568: d2162044                 lduh    [%i0+0x44], %o1
F005156C: 1100003f901223b9         set     0xFFB9, %o0
F0051574: 920a4008                 and     %o1, %o0, %o1
F0051578: d2362044                 sth     %o1, [%i0+0x44]
F005157C: 80a42000                 cmp     %l0, 0
F0051580: 0280000e                 be      locret_F00515B8
F0051584: 1100003f                 sethi   0xFC00, %o0
F0051588: d2162044                 lduh    [%i0+0x44], %o1
F005158C: 901223fe                 bset    0x3FE, %o0
F0051590: 920a4008                 and     %o1, %o0, %o1
F0051594: 808a6010                 btst    0x10, %o1
F0051598: 02800008                 be      locret_F00515B8
F005159C: d2362044                 sth     %o1, [%i0+0x44]
F00515A0: 1100003f901223ef         set     0xFFEF, %o0
F00515A8: 900a4008                 and     %o1, %o0, %o0
F00515AC: d0362044                 sth     %o0, [%i0+0x44]
F00515B0: 7fff060e                 call    _wakeup
F00515B4: 90100018                 mov     %i0, %o0
F00515B8: 81c7e008                 ret
F00515BC: 91e8001a                 restore %g0, %i2, %o0
