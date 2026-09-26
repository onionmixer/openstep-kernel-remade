F006F358: 9de3bf98                 save    %sp, -0x68, %sp
F006F35C: a0960000                 orcc    %i0, %g0, %l0
F006F360: 0280003c                 be      loc_F006F450
F006F364: 80a66001                 cmp     %i1, 1
F006F368: 1280001d                 bne     loc_F006F3DC
F006F36C: 80a66002                 cmp     %i1, 2
F006F370: d0070000                 ld      [%i4], %o0
F006F374: 80a22004                 cmp     %o0, 4
F006F378: 0880001f                 bleu    loc_F006F3F4
F006F37C: b0042158                 add     %l0, 0x158, %i0
F006F380: d0060000                 ld      [%i0], %o0
F006F384: 80a22000                 cmp     %o0, 0
F006F388: 12bffffe                 bne     loc_F006F380
F006F38C: 01000000                 nop
F006F390: 40009ec6                 call    _simple_lock_try
F006F394: 90100018                 mov     %i0, %o0
F006F398: 80a22000                 cmp     %o0, 0
F006F39C: 02bffff9                 be      loc_F006F380
F006F3A0: 01000000                 nop
F006F3A4: d0042124                 ld      [%l0+0x124], %o0
F006F3A8: d026c000                 st      %o0, [%i3]
F006F3AC: d0042134                 ld      [%l0+0x134], %o0
F006F3B0: d026e004                 st      %o0, [%i3+4]
F006F3B4: d0042140                 ld      [%l0+0x140], %o0
F006F3B8: d026e008                 st      %o0, [%i3+8]
F006F3BC: d0042170                 ld      [%l0+0x170], %o0
F006F3C0: d026e010                 st      %o0, [%i3+0x10]
F006F3C4: d0042174                 ld      [%l0+0x174], %o0
F006F3C8: b0102000                 mov     0, %i0
F006F3CC: d026e00c                 st      %o0, [%i3+0xC]
F006F3D0: c0242158                 clr     [%l0+0x158]
F006F3D4: 1080001a                 ba      loc_F006F43C
F006F3D8: 90102005                 mov     5, %o0
F006F3DC: 3280001d                 bne,a   loc_F006F450
F006F3E0: c0268000                 clr     [%i2]
F006F3E4: d0070000                 ld      [%i4], %o0
F006F3E8: 80a22001                 cmp     %o0, 1
F006F3EC: 18800004                 bgu     loc_F006F3FC
F006F3F0: b0042158                 add     %l0, 0x158, %i0
F006F3F4: 10800018                 ba      locret_F006F454
F006F3F8: b0102005                 mov     5, %i0
F006F3FC: d0060000                 ld      [%i0], %o0
F006F400: 80a22000                 cmp     %o0, 0
F006F404: 12bffffe                 bne     loc_F006F3FC
F006F408: 01000000                 nop
F006F40C: 40009ea7                 call    _simple_lock_try
F006F410: 90100018                 mov     %i0, %o0
F006F414: 80a22000                 cmp     %o0, 0
F006F418: 02bffff9                 be      loc_F006F3FC
F006F41C: 01000000                 nop
F006F420: d0042168                 ld      [%l0+0x168], %o0
F006F424: d026c000                 st      %o0, [%i3]
F006F428: d0042164                 ld      [%l0+0x164], %o0
F006F42C: b0102000                 mov     0, %i0
F006F430: d026e004                 st      %o0, [%i3+4]
F006F434: c0242158                 clr     [%l0+0x158]
F006F438: 90102002                 mov     2, %o0
F006F43C: d0270000                 st      %o0, [%i4]
F006F440: 113c04d490122170         set     _realhost, %o0
F006F448: 10800003                 ba      locret_F006F454
F006F44C: d0268000                 st      %o0, [%i2]
F006F450: b0102004                 mov     4, %i0
F006F454: 81c7e008                 ret
F006F458: 81e80000                 restore
