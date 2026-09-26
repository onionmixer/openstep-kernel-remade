F0062770: 9de3bf98                 save    %sp, -0x68, %sp
F0062774: d0064000                 ld      [%i1], %o0
F0062778: 80a22000                 cmp     %o0, 0
F006277C: 12bffffe                 bne     loc_F0062774
F0062780: 01000000                 nop
F0062784: 4000d1c9                 call    _simple_lock_try
F0062788: 90100019                 mov     %i1, %o0
F006278C: 80a22000                 cmp     %o0, 0
F0062790: 02bffff9                 be      loc_F0062774
F0062794: 01000000                 nop
F0062798: d0066030                 ld      [%i1+0x30], %o0
F006279C: c0264000                 clr     [%i1]
F00627A0: 80a60008                 cmp     %i0, %o0
F00627A4: 12800009                 bne     locret_F00627C8
F00627A8: f2066010                 ld      [%i1+0x10], %i1
F00627AC: d2070000                 ld      [%i4], %o1
F00627B0: 80a2401a                 cmp     %o1, %i2
F00627B4: 1a800003                 bcc     loc_F00627C0
F00627B8: 912a6002                 sll     %o1, 2, %o0
F00627BC: f226c008                 st      %i1, [%i3+%o0]
F00627C0: 90026001                 add     %o1, 1, %o0
F00627C4: d0270000                 st      %o0, [%i4]
F00627C8: 81c7e008                 ret
F00627CC: 81e80000                 restore
