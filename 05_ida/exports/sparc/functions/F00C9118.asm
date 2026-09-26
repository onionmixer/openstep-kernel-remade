F00C9118: 9de3bf88                 save    %sp, -0x78, %sp
F00C911C: 113c0504                 sethi   %hi(paCount_0), %o0! id
F00C9120: d20220b8                 ld      [%o0+%lo(paCount_0)], %o1! SEL
F00C9124: b0102000                 mov     0, %i0
F00C9128: 4000a1d2                 call    _objc_msgSend
F00C912C: 9010001a                 mov     %i2, %o0
F00C9130: a4920000                 orcc    %o0, %g0, %l2
F00C9134: 2480001e                 ble,a   locret_F00C91AC
F00C9138: e426c000                 st      %l2, [%i3]
F00C913C: 7ffff37d                 call    _IOMalloc
F00C9140: 912ca003                 sll     %l2, 3, %o0
F00C9144: a2102000                 mov     0, %l1
F00C9148: 80a44012                 cmp     %l1, %l2
F00C914C: 16800017                 bge     loc_F00C91A8
F00C9150: b0100008                 mov     %o0, %i0
F00C9154: 2b3c0504                 sethi   -0xFEBF000, %l5
F00C9158: 293c0504                 sethi   -0xFEBF000, %l4
F00C915C: a607bfe8                 add     %fp, var_18, %l3
F00C9160: a0100018                 mov     %i0, %l0
F00C9164: 9010001a                 mov     %i2, %o0! id
F00C9168: d20560c8                 ld      [%l5+0xC8], %o1! SEL
F00C916C: 4000a1c1                 call    _objc_msgSend
F00C9170: 94100011                 mov     %l1, %o2
F00C9174: d2052058                 ld      [%l4+0x58], %o1! SEL
F00C9178: e623a040                 st      %l3, [%sp+0x78+var_38]
F00C917C: 4000a1bd                 call    _objc_msgSend
F00C9180: 01000000                 nop
F00C9184: 00000008                 illtrap
F00C9188: d007bfe8                 ld      [%fp+var_18], %o0
F00C918C: a2046001                 inc     %l1
F00C9190: d0240000                 st      %o0, [%l0]
F00C9194: d007bfec                 ld      [%fp+var_14], %o0
F00C9198: 80a44012                 cmp     %l1, %l2
F00C919C: d0242004                 st      %o0, [%l0+4]
F00C91A0: 06bffff1                 bl      loc_F00C9164
F00C91A4: a0042008                 inc     8, %l0
F00C91A8: e426c000                 st      %l2, [%i3]
F00C91AC: 81c7e008                 ret
F00C91B0: 81e80000                 restore
