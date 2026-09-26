F00527B4: 9de3bf88                 save    %sp, -0x78, %sp
F00527B8: d206201c                 ld      [%i0+0x1C], %o1
F00527BC: d4026070                 ld      [%o1+0x70], %o2
F00527C0: 90100018                 mov     %i0, %o0
F00527C4: 9fc28000                 call    %o2
F00527C8: 9207bff4                 add     %fp, var_C, %o1
F00527CC: 80a22000                 cmp     %o0, 0
F00527D0: 22800002                 be,a    loc_F00527D8
F00527D4: f007bff4                 ld      [%fp+var_C], %i0
F00527D8: 113c04cf                 sethi   %hi(_active_u), %o0
F00527DC: d00221d8                 ld      [%o0+%lo(_active_u)], %o0
F00527E0: d0020000                 ld      [%o0], %o0
F00527E4: d0022014                 ld      [%o0+0x14], %o0
F00527E8: 15000010                 sethi   0x4000, %o2
F00527EC: 808a000a                 btst    %o2, %o0
F00527F0: 02800008                 be      loc_F0052810
F00527F4: f0062030                 ld      [%i0+0x30], %i0
F00527F8: d0162064                 lduh    [%i0+0x64], %o0
F00527FC: 1300003c                 sethi   0xF000, %o1
F0052800: 900a0009                 and     %o0, %o1, %o0
F0052804: 80a2000a                 cmp     %o0, %o2
F0052808: 2280005b                 be,a    locret_F0052974
F005280C: b0102001                 mov     1, %i0
F0052810: d0162064                 lduh    [%i0+0x64], %o0
F0052814: 1300003c                 sethi   0xF000, %o1
F0052818: 900a0009                 and     %o0, %o1, %o0
F005281C: 13000010                 sethi   0x4000, %o1
F0052820: 80a20009                 cmp     %o0, %o1
F0052824: 12800009                 bne     loc_F0052848
F0052828: 9210001a                 mov     %i2, %o1
F005282C: 7ffef450                 call    _suser
F0052830: 01000000                 nop
F0052834: 80a22000                 cmp     %o0, 0
F0052838: 12800004                 bne     loc_F0052848
F005283C: 9210001a                 mov     %i2, %o1
F0052840: 1080004d                 ba      locret_F0052974
F0052844: b0102001                 mov     1, %i0
F0052848: 94102001                 mov     1, %o2
F005284C: 96102000                 mov     0, %o3
F0052850: 98100018                 mov     %i0, %o4
F0052854: d0066030                 ld      [%i1+0x30], %o0
F0052858: 9a102000                 mov     0, %o5
F005285C: 7fffe32e                 call    _direnter
F0052860: c023a05c                 clr     [%sp+0x78+var_1C]
F0052864: d2162044                 lduh    [%i0+0x44], %o1
F0052868: 808a6046                 btst    0x46, %o1 ! 'F'
F005286C: 0280001d                 be      loc_F00528E0
F0052870: a0100008                 mov     %o0, %l0
F0052874: 90126008                 or      %o1, 8, %o0
F0052878: d0362044                 sth     %o0, [%i0+0x44]
F005287C: 353c04d4                 sethi   %hi(_iuniqtime), %i2
F0052880: 40006f54                 call    _microtime
F0052884: 9016a148                 or      %i2, %lo(_iuniqtime), %o0
F0052888: d0162044                 lduh    [%i0+0x44], %o0
F005288C: 808a2004                 btst    4, %o0
F0052890: 02800003                 be      loc_F005289C
F0052894: d006a148                 ld      [%i2+%lo(_iuniqtime)], %o0
F0052898: d0262074                 st      %o0, [%i0+0x74]
F005289C: d0162044                 lduh    [%i0+0x44], %o0
F00528A0: 808a2002                 btst    2, %o0
F00528A4: 02800003                 be      loc_F00528B0
F00528A8: d006a148                 ld      [%i2+0x148], %o0
F00528AC: d026207c                 st      %o0, [%i0+0x7C]
F00528B0: d0162044                 lduh    [%i0+0x44], %o0
F00528B4: 808a2040                 btst    0x40, %o0 ! '@'
F00528B8: 22800006                 be,a    loc_F00528D0
F00528BC: d2162044                 lduh    [%i0+0x44], %o1
F00528C0: c026204c                 clr     [%i0+0x4C]
F00528C4: d006a148                 ld      [%i2+0x148], %o0
F00528C8: d0262084                 st      %o0, [%i0+0x84]
F00528CC: d2162044                 lduh    [%i0+0x44], %o1
F00528D0: 1100003f901223b9         set     0xFFB9, %o0
F00528D8: 920a4008                 and     %o1, %o0, %o1
F00528DC: d2362044                 sth     %o1, [%i0+0x44]
F00528E0: d2066030                 ld      [%i1+0x30], %o1
F00528E4: d0126044                 lduh    [%o1+0x44], %o0
F00528E8: 808a2046                 btst    0x46, %o0 ! 'F'
F00528EC: 02800021                 be      loc_F0052970
F00528F0: 90122008                 bset    8, %o0
F00528F4: d0326044                 sth     %o0, [%o1+0x44]
F00528F8: 353c04d4                 sethi   %hi(_iuniqtime), %i2
F00528FC: 40006f35                 call    _microtime
F0052900: 9016a148                 or      %i2, %lo(_iuniqtime), %o0
F0052904: d2066030                 ld      [%i1+0x30], %o1
F0052908: d0126044                 lduh    [%o1+0x44], %o0
F005290C: 808a2004                 btst    4, %o0
F0052910: 02800004                 be      loc_F0052920
F0052914: d006a148                 ld      [%i2+%lo(_iuniqtime)], %o0
F0052918: d0226074                 st      %o0, [%o1+0x74]
F005291C: d2066030                 ld      [%i1+0x30], %o1
F0052920: d0126044                 lduh    [%o1+0x44], %o0
F0052924: 808a2002                 btst    2, %o0
F0052928: 02800003                 be      loc_F0052934
F005292C: d006a148                 ld      [%i2+0x148], %o0
F0052930: d022607c                 st      %o0, [%o1+0x7C]
F0052934: d2066030                 ld      [%i1+0x30], %o1
F0052938: d0126044                 lduh    [%o1+0x44], %o0
F005293C: 808a2040                 btst    0x40, %o0 ! '@'
F0052940: 22800007                 be,a    loc_F005295C
F0052944: d0066030                 ld      [%i1+0x30], %o0
F0052948: c022604c                 clr     [%o1+0x4C]
F005294C: d2066030                 ld      [%i1+0x30], %o1
F0052950: d006a148                 ld      [%i2+0x148], %o0
F0052954: d0226084                 st      %o0, [%o1+0x84]
F0052958: d0066030                 ld      [%i1+0x30], %o0
F005295C: 1300003f                 sethi   0xFC00, %o1
F0052960: d4122044                 lduh    [%o0+0x44], %o2
F0052964: 921263b9                 bset    0x3B9, %o1
F0052968: 940a8009                 and     %o2, %o1, %o2
F005296C: d4322044                 sth     %o2, [%o0+0x44]
F0052970: b0100010                 mov     %l0, %i0
F0052974: 81c7e008                 ret
F0052978: 81e80000                 restore
