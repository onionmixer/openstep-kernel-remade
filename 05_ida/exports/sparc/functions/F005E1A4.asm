F005E1A4: 9de3bf98                 save    %sp, -0x68, %sp
F005E1A8: c2066010                 ld      [%i1+0x10], %g1
F005E1AC: 80a60001                 cmp     %i0, %g1
F005E1B0: 02800041                 be      loc_F005E2B4
F005E1B4: de07a05c                 ld      [%fp+arg_5C], %o7
F005E1B8: 80a60001                 cmp     %i0, %g1
F005E1BC: 3a80001f                 bcc,a   loc_F005E238
F005E1C0: c806601c                 ld      [%i1+0x1C], %g4
F005E1C4: c8066018                 ld      [%i1+0x18], %g4
F005E1C8: 80a12000                 cmp     %g4, 0
F005E1CC: 2280003b                 be,a    loc_F005E2B8
F005E1D0: f2268000                 st      %i1, [%i2]
F005E1D4: c2012010                 ld      [%g4+0x10], %g1
F005E1D8: 80a60001                 cmp     %i0, %g1
F005E1DC: 3a80000b                 bcc,a   loc_F005E208
F005E1E0: f2274000                 st      %i1, [%i5]
F005E1E4: c4012018                 ld      [%g4+0x18], %g2
F005E1E8: 80a0a000                 cmp     %g2, 0
F005E1EC: 02800006                 be      loc_F005E204
F005E1F0: 86100019                 mov     %i1, %g3
F005E1F4: b2100004                 mov     %g4, %i1
F005E1F8: c406601c                 ld      [%i1+0x1C], %g2
F005E1FC: c420e018                 st      %g2, [%g3+0x18]
F005E200: c626601c                 st      %g3, [%i1+0x1C]
F005E204: f2274000                 st      %i1, [%i5]
F005E208: ba066018                 add     %i1, 0x18, %i5
F005E20C: 80a60001                 cmp     %i0, %g1
F005E210: 08800025                 bleu    loc_F005E2A4
F005E214: f2066018                 ld      [%i1+0x18], %i1
F005E218: c401201c                 ld      [%g4+0x1C], %g2
F005E21C: 80a0a000                 cmp     %g2, 0
F005E220: 22800022                 be,a    loc_F005E2A8
F005E224: c2066010                 ld      [%i1+0x10], %g1
F005E228: f226c000                 st      %i1, [%i3]
F005E22C: b606601c                 add     %i1, 0x1C, %i3
F005E230: 1080001d                 ba      loc_F005E2A4
F005E234: f206601c                 ld      [%i1+0x1C], %i1
F005E238: 80a12000                 cmp     %g4, 0
F005E23C: 2280001f                 be,a    loc_F005E2B8
F005E240: f2268000                 st      %i1, [%i2]
F005E244: c2012010                 ld      [%g4+0x10], %g1
F005E248: 80a60001                 cmp     %i0, %g1
F005E24C: 2880000b                 bleu,a  loc_F005E278
F005E250: f226c000                 st      %i1, [%i3]
F005E254: c401201c                 ld      [%g4+0x1C], %g2
F005E258: 80a0a000                 cmp     %g2, 0
F005E25C: 02800006                 be      loc_F005E274
F005E260: 86100019                 mov     %i1, %g3
F005E264: b2100004                 mov     %g4, %i1
F005E268: c4066018                 ld      [%i1+0x18], %g2
F005E26C: c420e01c                 st      %g2, [%g3+0x1C]
F005E270: c6266018                 st      %g3, [%i1+0x18]
F005E274: f226c000                 st      %i1, [%i3]
F005E278: b606601c                 add     %i1, 0x1C, %i3
F005E27C: 80a60001                 cmp     %i0, %g1
F005E280: 1a800009                 bcc     loc_F005E2A4
F005E284: f206601c                 ld      [%i1+0x1C], %i1
F005E288: c4012018                 ld      [%g4+0x18], %g2
F005E28C: 80a0a000                 cmp     %g2, 0
F005E290: 22800006                 be,a    loc_F005E2A8
F005E294: c2066010                 ld      [%i1+0x10], %g1
F005E298: f2274000                 st      %i1, [%i5]
F005E29C: ba066018                 add     %i1, 0x18, %i5
F005E2A0: f2066018                 ld      [%i1+0x18], %i1
F005E2A4: c2066010                 ld      [%i1+0x10], %g1
F005E2A8: 80a60001                 cmp     %i0, %g1
F005E2AC: 12bfffc3                 bne     loc_F005E1B8
F005E2B0: 01000000                 nop
F005E2B4: f2268000                 st      %i1, [%i2]
F005E2B8: f6270000                 st      %i3, [%i4]
F005E2BC: fa23c000                 st      %i5, [%o7]
F005E2C0: 81c7e008                 ret
F005E2C4: 81e80000                 restore
