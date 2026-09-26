F004E198: 9de3bf98                 save    %sp, -0x68, %sp
F004E19C: d0162044                 lduh    [%i0+0x44], %o0
F004E1A0: 808a2001                 btst    1, %o0
F004E1A4: 32800006                 bne,a   loc_F004E1BC
F004E1A8: d2162044                 lduh    [%i0+0x44], %o1
F004E1AC: 113c043b                 sethi   %hi(aIput), %o0! "iput"
F004E1B0: 7fff1bf0                 call    _panic
F004E1B4: 90122088                 bset    %lo(aIput), %o0! "iput"
F004E1B8: d2162044                 lduh    [%i0+0x44], %o1
F004E1BC: 1100003f901223fe         set     0xFFFE, %o0
F004E1C4: 920a4008                 and     %o1, %o0, %o1
F004E1C8: 808a6010                 btst    0x10, %o1
F004E1CC: 02800008                 be      loc_F004E1EC
F004E1D0: d2362044                 sth     %o1, [%i0+0x44]
F004E1D4: 1100003f901223ef         set     0xFFEF, %o0
F004E1DC: 900a4008                 and     %o1, %o0, %o0
F004E1E0: d0362044                 sth     %o0, [%i0+0x44]
F004E1E4: 7fff1301                 call    _wakeup
F004E1E8: 90100018                 mov     %i0, %o0
F004E1EC: d0162044                 lduh    [%i0+0x44], %o0
F004E1F0: 808a2046                 btst    0x46, %o0 ! 'F'
F004E1F4: 0280001c                 be      loc_F004E264
F004E1F8: 90122008                 bset    8, %o0
F004E1FC: d0362044                 sth     %o0, [%i0+0x44]
F004E200: 213c04d4                 sethi   %hi(_iuniqtime), %l0
F004E204: 400080f3                 call    _microtime
F004E208: 90142148                 or      %l0, %lo(_iuniqtime), %o0
F004E20C: d0162044                 lduh    [%i0+0x44], %o0
F004E210: 808a2004                 btst    4, %o0
F004E214: 02800003                 be      loc_F004E220
F004E218: d0042148                 ld      [%l0+%lo(_iuniqtime)], %o0
F004E21C: d0262074                 st      %o0, [%i0+0x74]
F004E220: d0162044                 lduh    [%i0+0x44], %o0
F004E224: 808a2002                 btst    2, %o0
F004E228: 02800003                 be      loc_F004E234
F004E22C: d0042148                 ld      [%l0+0x148], %o0
F004E230: d026207c                 st      %o0, [%i0+0x7C]
F004E234: d0162044                 lduh    [%i0+0x44], %o0
F004E238: 808a2040                 btst    0x40, %o0 ! '@'
F004E23C: 22800006                 be,a    loc_F004E254
F004E240: d2162044                 lduh    [%i0+0x44], %o1
F004E244: c026204c                 clr     [%i0+0x4C]
F004E248: d0042148                 ld      [%l0+0x148], %o0
F004E24C: d0262084                 st      %o0, [%i0+0x84]
F004E250: d2162044                 lduh    [%i0+0x44], %o1
F004E254: 1100003f901223b9         set     0xFFB9, %o0
F004E25C: 920a4008                 and     %o1, %o0, %o1
F004E260: d2362044                 sth     %o1, [%i0+0x44]
F004E264: 7fff6a40                 call    _vn_rele
F004E268: 9006200c                 add     %i0, 0xC, %o0
F004E26C: 81c7e008                 ret
F004E270: 81e80000                 restore
