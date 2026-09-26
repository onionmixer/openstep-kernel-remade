F00A4648: 9de3bf98                 save    %sp, -0x68, %sp
F00A464C: 82100018                 mov     %i0, %g1
F00A4650: 90100019                 mov     %i1, %o0
F00A4654: 9210001a                 mov     %i2, %o1
F00A4658: 88102000                 mov     0, %g4
F00A465C: 80a06000                 cmp     %g1, 0
F00A4660: 02800018                 be      loc_F00A46C0
F00A4664: 9e102000                 mov     0, %o7
F00A4668: c4184000                 ldd     [%g1], %g2
F00A466C: f8186008                 ldd     [%g1+8], %i4
F00A4670: 8680c01d                 addcc   %g3, %i5, %g3
F00A4674: 8440801c                 addc    %g2, %i4, %g2
F00A4678: 8680ffff                 inccc   -1, %g3
F00A467C: 8440bfff                 addc    %g2, -1, %g2
F00A4680: b728a014                 sll     %g2, 20, %i3
F00A4684: b530e00c                 srl     %g3, 12, %i2
F00A4688: b216c01a                 or      %i3, %i2, %i1
F00A468C: b130a00c                 srl     %g2, 12, %i0
F00A4690: b0100019                 mov     %i1, %i0
F00A4694: 80a10018                 cmp     %g4, %i0
F00A4698: 26800002                 bl,a    loc_F00A46A0
F00A469C: 88100018                 mov     %i0, %g4
F00A46A0: b32f2014                 sll     %i4, 20, %i1
F00A46A4: b137600c                 srl     %i5, 12, %i0
F00A46A8: 86164018                 or      %i1, %i0, %g3
F00A46AC: 8537200c                 srl     %i4, 12, %g2
F00A46B0: c2006010                 ld      [%g1+0x10], %g1
F00A46B4: 80a06000                 cmp     %g1, 0
F00A46B8: 12bfffec                 bne     loc_F00A4668
F00A46BC: 9e03c003                 add     %o7, %g3, %o7
F00A46C0: c8220000                 st      %g4, [%o0]
F00A46C4: de224000                 st      %o7, [%o1]
F00A46C8: 81c7e008                 ret
F00A46CC: 81e80000                 restore
