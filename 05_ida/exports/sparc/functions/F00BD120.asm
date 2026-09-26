F00BD120: 9de3bf90                 save    %sp, -0x70, %sp
F00BD124: 7fffff6a                 call    sub_F00BCECC
F00BD128: 9010001a                 mov     %i2, %o0
F00BD12C: a0100008                 mov     %o0, %l0
F00BD130: 80a42100                 cmp     %l0, 0x100
F00BD134: 02800035                 be      locret_F00BD208
F00BD138: 01000000                 nop
F00BD13C: d0062124                 ld      [%i0+0x124], %o0
F00BD140: 80a22000                 cmp     %o0, 0
F00BD144: 16800026                 bge     loc_F00BD1DC
F00BD148: 113c04d4                 sethi   -0xFECB000, %o0
F00BD14C: b4062170                 add     %i0, 0x170, %i2
F00BD150: d0068000                 ld      [%i2], %o0
F00BD154: 80a22000                 cmp     %o0, 0
F00BD158: 12bffffe                 bne     loc_F00BD150
F00BD15C: 01000000                 nop
F00BD160: 7fff6752                 call    _simple_lock_try
F00BD164: 9010001a                 mov     %i2, %o0
F00BD168: 80a22000                 cmp     %o0, 0
F00BD16C: 02bffff9                 be      loc_F00BD150
F00BD170: 01000000                 nop
F00BD174: d4062168                 ld      [%i0+0x168], %o2
F00BD178: 9002a001                 add     %o2, 1, %o0
F00BD17C: 80a22010                 cmp     %o0, 0x10
F00BD180: 12800003                 bne     loc_F00BD18C
F00BD184: 92100008                 mov     %o0, %o1
F00BD188: 92102000                 mov     0, %o1
F00BD18C: d006216c                 ld      [%i0+0x16C], %o0
F00BD190: 80a24008                 cmp     %o1, %o0
F00BD194: 12800004                 bne     loc_F00BD1A4
F00BD198: 912aa002                 sll     %o2, 2, %o0
F00BD19C: c0262170                 clr     [%i0+0x170]
F00BD1A0: 3080001a                 ba,a    locret_F00BD208
F00BD1A4: 90020018                 add     %o0, %i0, %o0
F00BD1A8: e0222128                 st      %l0, [%o0+0x128]
F00BD1AC: d0062168                 ld      [%i0+0x168], %o0
F00BD1B0: 90022001                 inc     %o0
F00BD1B4: 80a22010                 cmp     %o0, 0x10
F00BD1B8: 22800002                 be,a    loc_F00BD1C0
F00BD1BC: 90102000                 mov     0, %o0
F00BD1C0: d0262168                 st      %o0, [%i0+0x168]
F00BD1C4: 90062128                 add     %i0, 0x128, %o0
F00BD1C8: 92102000                 mov     0, %o1
F00BD1CC: 7ffecf8c                 call    _thread_wakeup_prim
F00BD1D0: 94102000                 mov     0, %o2
F00BD1D4: c0262170                 clr     [%i0+0x170]
F00BD1D8: 3080000c                 ba,a    locret_F00BD208
F00BD1DC: d2022290                 ld      [%o0+0x290], %o1
F00BD1E0: d64a6047                 ldsb    [%o1+0x47], %o3
F00BD1E4: 952ae001                 sll     %o3, 1, %o2
F00BD1E8: 9402800b                 add     %o2, %o3, %o2
F00BD1EC: 952aa004                 sll     %o2, 4, %o2
F00BD1F0: 173c042e9612e0cc         set     _linesw, %o3
F00BD1F8: 9402800b                 add     %o2, %o3, %o2
F00BD1FC: d402a014                 ld      [%o2+0x14], %o2
F00BD200: 9fc28000                 call    %o2
F00BD204: 90100010                 mov     %l0, %o0
F00BD208: 81c7e008                 ret
F00BD20C: 81e80000                 restore
