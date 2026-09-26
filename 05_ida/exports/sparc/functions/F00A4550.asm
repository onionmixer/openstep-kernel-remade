F00A4550: 9de3bf98                 save    %sp, -0x68, %sp
F00A4554: 88100019                 mov     %i1, %g4
F00A4558: f6010000                 ld      [%g4], %i3
F00A455C: 80a6a000                 cmp     %i2, 0
F00A4560: 0280001f                 be      loc_F00A45DC
F00A4564: ba10001b                 mov     %i3, %i5
F00A4568: 82960000                 orcc    %i0, %g0, %g1
F00A456C: 02800034                 be      loc_F00A463C
F00A4570: b806e014                 add     %i3, 0x14, %i4
F00A4574: f4004000                 ld      [%g1], %i2
F00A4578: 8610001a                 mov     %i2, %g3
F00A457C: 84102000                 mov     0, %g2
F00A4580: c43ec000                 std     %g2, [%i3]
F00A4584: c4006004                 ld      [%g1+4], %g2
F00A4588: 80a7401b                 cmp     %i5, %i3
F00A458C: b2100002                 mov     %g2, %i1
F00A4590: b0102000                 mov     0, %i0
F00A4594: f03f3ff4                 std     %i0, [%i4-0xC]
F00A4598: 12800006                 bne     loc_F00A45B0
F00A459C: c0273ffc                 clr     [%i4-4]
F00A45A0: c0270000                 clr     [%i4]
F00A45A4: b8072018                 inc     0x18, %i4
F00A45A8: 10800007                 ba      loc_F00A45C4
F00A45AC: b606e018                 inc     0x18, %i3
F00A45B0: fa270000                 st      %i5, [%i4]
F00A45B4: f6276010                 st      %i3, [%i5+0x10]
F00A45B8: b8072018                 inc     0x18, %i4
F00A45BC: b606e018                 inc     0x18, %i3
F00A45C0: ba076018                 inc     0x18, %i5
F00A45C4: c2006008                 ld      [%g1+8], %g1
F00A45C8: 80a06000                 cmp     %g1, 0
F00A45CC: 32bfffeb                 bne,a   loc_F00A4578
F00A45D0: f4004000                 ld      [%g1], %i2
F00A45D4: 1080001b                 ba      locret_F00A4640
F00A45D8: f6210000                 st      %i3, [%g4]
F00A45DC: 80a62000                 cmp     %i0, 0
F00A45E0: 22800018                 be,a    locret_F00A4640
F00A45E4: f6210000                 st      %i3, [%g4]
F00A45E8: b206e014                 add     %i3, 0x14, %i1
F00A45EC: c41e0000                 ldd     [%i0], %g2
F00A45F0: c43ec000                 std     %g2, [%i3]
F00A45F4: c41e2008                 ldd     [%i0+8], %g2
F00A45F8: 80a7401b                 cmp     %i5, %i3
F00A45FC: c43e7ff4                 std     %g2, [%i1-0xC]
F00A4600: 12800006                 bne     loc_F00A4618
F00A4604: c0267ffc                 clr     [%i1-4]
F00A4608: c0264000                 clr     [%i1]
F00A460C: b2066018                 inc     0x18, %i1
F00A4610: 10800007                 ba      loc_F00A462C
F00A4614: b606e018                 inc     0x18, %i3
F00A4618: fa264000                 st      %i5, [%i1]
F00A461C: f6276010                 st      %i3, [%i5+0x10]
F00A4620: b2066018                 inc     0x18, %i1
F00A4624: b606e018                 inc     0x18, %i3
F00A4628: ba076018                 inc     0x18, %i5
F00A462C: f0062010                 ld      [%i0+0x10], %i0
F00A4630: 80a62000                 cmp     %i0, 0
F00A4634: 32bfffef                 bne,a   loc_F00A45F0
F00A4638: c41e0000                 ldd     [%i0], %g2
F00A463C: f6210000                 st      %i3, [%g4]
F00A4640: 81c7e008                 ret
F00A4644: 81e80000                 restore
