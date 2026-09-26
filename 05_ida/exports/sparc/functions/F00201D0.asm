F00201D0: 9de3bf98                 save    %sp, -0x68, %sp
F00201D4: b6100018                 mov     %i0, %i3
F00201D8: 80a6a000                 cmp     %i2, 0
F00201DC: 12800011                 bne     loc_F0020220
F00201E0: f6266010                 st      %i3, [%i1+0x10]
F00201E4: c416e018                 lduh    [%i3+0x18], %g2
F00201E8: c606e014                 ld      [%i3+0x14], %g3
F00201EC: 8400a001                 inc     %g2
F00201F0: 80a0c01b                 cmp     %g3, %i3
F00201F4: 02800007                 be      loc_F0020210
F00201F8: c436e018                 sth     %g2, [%i3+0x18]
F00201FC: f606e014                 ld      [%i3+0x14], %i3
F0020200: c406e014                 ld      [%i3+0x14], %g2
F0020204: 80a08018                 cmp     %g2, %i0
F0020208: 32bffffe                 bne,a   loc_F0020200
F002020C: f606e014                 ld      [%i3+0x14], %i3
F0020210: c406e014                 ld      [%i3+0x14], %g2
F0020214: c4266014                 st      %g2, [%i1+0x14]
F0020218: 10800010                 ba      locret_F0020258
F002021C: f226e014                 st      %i1, [%i3+0x14]
F0020220: c416e020                 lduh    [%i3+0x20], %g2
F0020224: c606e01c                 ld      [%i3+0x1C], %g3
F0020228: 8400a001                 inc     %g2
F002022C: 80a0c01b                 cmp     %g3, %i3
F0020230: 02800007                 be      loc_F002024C
F0020234: c436e020                 sth     %g2, [%i3+0x20]
F0020238: f606e01c                 ld      [%i3+0x1C], %i3
F002023C: c406e01c                 ld      [%i3+0x1C], %g2
F0020240: 80a08018                 cmp     %g2, %i0
F0020244: 32bffffe                 bne,a   loc_F002023C
F0020248: f606e01c                 ld      [%i3+0x1C], %i3
F002024C: c406e01c                 ld      [%i3+0x1C], %g2
F0020250: c426601c                 st      %g2, [%i1+0x1C]
F0020254: f226e01c                 st      %i1, [%i3+0x1C]
F0020258: 81c7e008                 ret
F002025C: 81e80000                 restore
