F0094654: 9de3bf98                 save    %sp, -0x68, %sp
F0094658: c0260000                 clr     [%i0]
F009465C: 073c04f0                 sethi   %hi(dword_F013C048), %g3
F0094660: c400e048                 ld      [%g3+%lo(dword_F013C048)], %g2
F0094664: b4102000                 mov     0, %i2
F0094668: 80a68002                 cmp     %i2, %g2
F009466C: 16800019                 bge     locret_F00946D0
F0094670: b8102001                 mov     1, %i4
F0094674: b6100003                 mov     %g3, %i3
F0094678: 053c04d1b210a360         set     _machine_slot, %i1
F0094680: c4064000                 ld      [%i1], %g2
F0094684: 80a0a000                 cmp     %g2, 0
F0094688: 0280000e                 be      loc_F00946C0
F009468C: c406e048                 ld      [%i3+0x48], %g2
F0094690: c4060000                 ld      [%i0], %g2
F0094694: 872f001a                 sll     %i4, %i2, %g3
F0094698: 84108003                 bset    %g3, %g2
F009469C: c6062004                 ld      [%i0+4], %g3
F00946A0: 80a0e000                 cmp     %g3, 0
F00946A4: 12800006                 bne     loc_F00946BC
F00946A8: c4260000                 st      %g2, [%i0]
F00946AC: c4066004                 ld      [%i1+4], %g2
F00946B0: c4262004                 st      %g2, [%i0+4]
F00946B4: c4066008                 ld      [%i1+8], %g2
F00946B8: c4262008                 st      %g2, [%i0+8]
F00946BC: c406e048                 ld      [%i3+0x48], %g2
F00946C0: b406a001                 inc     %i2
F00946C4: 80a68002                 cmp     %i2, %g2
F00946C8: 06bfffee                 bl      loc_F0094680
F00946CC: b2066020                 inc     0x20, %i1 ! ' '
F00946D0: 81c7e008                 ret
F00946D4: 81e80000                 restore
