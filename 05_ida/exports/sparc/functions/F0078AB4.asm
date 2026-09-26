F0078AB4: 9de3bf98                 save    %sp, -0x68, %sp
F0078AB8: b6100018                 mov     %i0, %i3
F0078ABC: 053c04f2                 sethi   %hi(unk_F013CBB4), %g2
F0078AC0: c606e014                 ld      [%i3+0x14], %g3
F0078AC4: 80a0e000                 cmp     %g3, 0
F0078AC8: 1280001a                 bne     locret_F0078B30
F0078ACC: b410a3b4                 or      %g2, %lo(unk_F013CBB4), %i2
F0078AD0: 053c04f2                 sethi   %hi(_zone_free_space_count), %g2
F0078AD4: c400a3d0                 ld      [%g2+%lo(_zone_free_space_count)], %g2
F0078AD8: b2102001                 mov     1, %i1
F0078ADC: 80a64002                 cmp     %i1, %g2
F0078AE0: 16800014                 bge     locret_F0078B30
F0078AE4: b8100002                 mov     %g2, %i4
F0078AE8: f0068000                 ld      [%i2], %i0
F0078AEC: c406e01c                 ld      [%i3+0x1C], %g2
F0078AF0: c6060000                 ld      [%i0], %g3
F0078AF4: 8400bfff                 inc     -1, %g2
F0078AF8: 84008003                 add     %g2, %g3, %g2
F0078AFC: 86200003                 neg     %g3
F0078B00: f0062004                 ld      [%i0+4], %i0
F0078B04: 84088003                 and     %g2, %g3, %g2
F0078B08: 80a08018                 cmp     %g2, %i0
F0078B0C: 18800006                 bgu     loc_F0078B24
F0078B10: b2066001                 inc     %i1
F0078B14: c426e01c                 st      %g2, [%i3+0x1C]
F0078B18: c4068000                 ld      [%i2], %g2
F0078B1C: 10800005                 ba      locret_F0078B30
F0078B20: c426e03c                 st      %g2, [%i3+0x3C]
F0078B24: 80a6401c                 cmp     %i1, %i4
F0078B28: 06bffff0                 bl      loc_F0078AE8
F0078B2C: b406a004                 inc     4, %i2
F0078B30: 81c7e008                 ret
F0078B34: 81e80000                 restore
