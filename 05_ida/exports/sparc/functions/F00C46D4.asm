F00C46D4: 9de3bf98                 save    %sp, -0x68, %sp
F00C46D8: 113c04cc                 sethi   %hi(dword_F0133034), %o0
F00C46DC: e0022034                 ld      [%o0+%lo(dword_F0133034)], %l0
F00C46E0: 90122034                 bset    %lo(dword_F0133034), %o0
F00C46E4: 80a40008                 cmp     %l0, %o0
F00C46E8: 22800018                 be,a    locret_F00C4748
F00C46EC: b0103d40                 mov     -0x2C0, %i0
F00C46F0: 253c0504                 sethi   -0xFEBF000, %l2
F00C46F4: a2100008                 mov     %o0, %l1
F00C46F8: d0040000                 ld      [%l0], %o0! id
F00C46FC: 4000b45d                 call    _objc_msgSend
F00C4700: d204a008                 ld      [%l2+8], %o1
F00C4704: 92100008                 mov     %o0, %o1! __s2
F00C4708: 90100018                 mov     %i0, %o0! __s1
F00C470C: 7ffd0f77                 call    _strncmp
F00C4710: 94102050                 mov     0x50, %o2 ! 'P'
F00C4714: 80a22000                 cmp     %o0, 0
F00C4718: 32800008                 bne,a   loc_F00C4738
F00C471C: e0042008                 ld      [%l0+8], %l0
F00C4720: d0040000                 ld      [%l0], %o0
F00C4724: d0264000                 st      %o0, [%i1]
F00C4728: d0042004                 ld      [%l0+4], %o0
F00C472C: b0102000                 mov     0, %i0
F00C4730: 10800006                 ba      locret_F00C4748
F00C4734: d0268000                 st      %o0, [%i2]
F00C4738: 80a40011                 cmp     %l0, %l1
F00C473C: 32bffff0                 bne,a   loc_F00C46FC
F00C4740: d0040000                 ld      [%l0], %o0
F00C4744: b0103d40                 mov     -0x2C0, %i0
F00C4748: 81c7e008                 ret
F00C474C: 81e80000                 restore
