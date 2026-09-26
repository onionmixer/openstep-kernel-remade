F004D32C: 9de3bf98                 save    %sp, -0x68, %sp
F004D330: a0100018                 mov     %i0, %l0
F004D334: d0042018                 ld      [%l0+0x18], %o0
F004D338: 80a22000                 cmp     %o0, 0
F004D33C: 12800004                 bne     loc_F004D34C
F004D340: 90023fff                 inc     -1, %o0
F004D344: 1080000a                 ba      loc_F004D36C
F004D348: b0102000                 mov     0, %i0
F004D34C: d0242018                 st      %o0, [%l0+0x18]
F004D350: 40006b48                 call    _kalloc
F004D354: 90102018                 mov     0x18, %o0
F004D358: c022200c                 clr     [%o0+0xC]
F004D35C: c0222004                 clr     [%o0+4]
F004D360: c0220000                 clr     [%o0]
F004D364: c0222008                 clr     [%o0+8]
F004D368: b0100008                 mov     %o0, %i0
F004D36C: f4262004                 st      %i2, [%i0+4]
F004D370: f4260000                 st      %i2, [%i0]
F004D374: 92042010                 add     %l0, 0x10, %o1
F004D378: 80a24019                 cmp     %o1, %i1
F004D37C: 1280000c                 bne     loc_F004D3AC
F004D380: c026a00c                 clr     [%i2+0xC]
F004D384: d0042010                 ld      [%l0+0x10], %o0
F004D388: 80a64008                 cmp     %i1, %o0
F004D38C: 32800003                 bne,a   loc_F004D398
F004D390: f0222014                 st      %i0, [%o0+0x14]
F004D394: f0242014                 st      %i0, [%l0+0x14]
F004D398: d0262010                 st      %o0, [%i0+0x10]
F004D39C: 90042010                 add     %l0, 0x10, %o0
F004D3A0: d0262014                 st      %o0, [%i0+0x14]
F004D3A4: 10800015                 ba      locret_F004D3F8
F004D3A8: f0242010                 st      %i0, [%l0+0x10]
F004D3AC: d0066010                 ld      [%i1+0x10], %o0
F004D3B0: 80a24008                 cmp     %o1, %o0
F004D3B4: 3280000c                 bne,a   loc_F004D3E4
F004D3B8: f2262014                 st      %i1, [%i0+0x14]
F004D3BC: d0042014                 ld      [%l0+0x14], %o0
F004D3C0: 80a24008                 cmp     %o1, %o0
F004D3C4: 32800003                 bne,a   loc_F004D3D0
F004D3C8: f0222010                 st      %i0, [%o0+0x10]
F004D3CC: f0242010                 st      %i0, [%l0+0x10]
F004D3D0: d0262014                 st      %o0, [%i0+0x14]
F004D3D4: 90042010                 add     %l0, 0x10, %o0
F004D3D8: d0262010                 st      %o0, [%i0+0x10]
F004D3DC: 10800007                 ba      locret_F004D3F8
F004D3E0: f0242014                 st      %i0, [%l0+0x14]
F004D3E4: d0066010                 ld      [%i1+0x10], %o0
F004D3E8: d0262010                 st      %o0, [%i0+0x10]
F004D3EC: f0266010                 st      %i0, [%i1+0x10]
F004D3F0: d0062010                 ld      [%i0+0x10], %o0
F004D3F4: f0222014                 st      %i0, [%o0+0x14]
F004D3F8: 81c7e008                 ret
F004D3FC: 81e80000                 restore
