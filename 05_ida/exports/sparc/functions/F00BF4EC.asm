F00BF4EC: 9de3bf78                 save    %sp, -0x88, %sp
F00BF4F0: 113c0504                 sethi   %hi(paOwner_0), %o0! id
F00BF4F4: d2022298                 ld      [%o0+%lo(paOwner_0)], %o1! SEL
F00BF4F8: e007a05c                 ld      [%fp+arg_5C], %l0
F00BF4FC: e207a060                 ld      [%fp+arg_60], %l1
F00BF500: e407a064                 ld      [%fp+arg_64], %l2
F00BF504: 4000c8db                 call    _objc_msgSend
F00BF508: 90100018                 mov     %i0, %o0! id
F00BF50C: d6062148                 ld      [%i0+0x148], %o3
F00BF510: 9410001a                 mov     %i2, %o2
F00BF514: e023a05c                 st      %l0, [%sp+0x88+var_2C]
F00BF518: e223a060                 st      %l1, [%sp+0x88+var_28]
F00BF51C: e423a064                 st      %l2, [%sp+0x88+var_24]
F00BF520: d84e214e                 ldsb    [%i0+0x14E], %o4
F00BF524: 133c0504                 sethi   %hi(paKeyboardeventF_0), %o1
F00BF528: d202629c                 ld      [%o1+%lo(paKeyboardeventF_0)], %o1! SEL
F00BF52C: d823a068                 st      %o4, [%sp+0x88+var_20]
F00BF530: d81e2158                 ldd     [%i0+0x158], %o4
F00BF534: 9616c00b                 bset    %i3, %o3
F00BF538: d823a06c                 st      %o4, [%sp+0x88+var_1C]
F00BF53C: da23a070                 st      %o5, [%sp+0x88+var_18]
F00BF540: 9810001c                 mov     %i4, %o4
F00BF544: 4000c8cb                 call    _objc_msgSend
F00BF548: 9a10001d                 mov     %i5, %o5
F00BF54C: 90100018                 mov     %i0, %o0! id
F00BF550: 9410001a                 mov     %i2, %o2
F00BF554: 133c0504                 sethi   %hi(paSetrepeatForco), %o1
F00BF558: d20262a0                 ld      [%o1+%lo(paSetrepeatForco)], %o1! SEL
F00BF55C: 4000c8c5                 call    _objc_msgSend
F00BF560: 9610001c                 mov     %i4, %o3
F00BF564: 81c7e008                 ret
F00BF568: 91e80008                 restore %g0, %o0, %o0
