F00D90B4: 9de3bf90                 save    %sp, -0x70, %sp
F00D90B8: a2102000                 mov     0, %l1
F00D90BC: 80a4401c                 cmp     %l1, %i4
F00D90C0: 1a80000d                 bcc     locret_F00D90F4
F00D90C4: 253c0505                 sethi   -0xFEBEC00, %l2
F00D90C8: a0102000                 mov     0, %l0
F00D90CC: 90100018                 mov     %i0, %o0! id
F00D90D0: d204a0f8                 ld      [%l2+0xF8], %o1! SEL
F00D90D4: a2046001                 inc     %l1
F00D90D8: d404001a                 ld      [%l0+%i2], %o2
F00D90DC: 400061e5                 call    _objc_msgSend
F00D90E0: 9610001d                 mov     %i5, %o3
F00D90E4: d024001b                 st      %o0, [%l0+%i3]
F00D90E8: 80a4401c                 cmp     %l1, %i4
F00D90EC: 0abffff8                 bcs     loc_F00D90CC
F00D90F0: a0042004                 inc     4, %l0
F00D90F4: 81c7e008                 ret
F00D90F8: 81e80000                 restore
