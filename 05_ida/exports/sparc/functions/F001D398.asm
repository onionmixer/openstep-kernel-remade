F001D398: 9de3bf98                 save    %sp, -0x68, %sp
F001D39C: 053c04d4                 sethi   %hi(_domains), %g2
F001D3A0: c600a2b8                 ld      [%g2+%lo(_domains)], %g3
F001D3A4: 80a0e000                 cmp     %g3, 0
F001D3A8: 2280001c                 be,a    locret_F001D418
F001D3AC: b0102000                 mov     0, %i0
F001D3B0: c400c000                 ld      [%g3], %g2
F001D3B4: 80a08018                 cmp     %g2, %i0
F001D3B8: 22800008                 be,a    loc_F001D3D8
F001D3BC: f000e014                 ld      [%g3+0x14], %i0
F001D3C0: c600e01c                 ld      [%g3+0x1C], %g3
F001D3C4: 80a0e000                 cmp     %g3, 0
F001D3C8: 32bffffb                 bne,a   loc_F001D3B4
F001D3CC: c400c000                 ld      [%g3], %g2
F001D3D0: 10800012                 ba      locret_F001D418
F001D3D4: b0102000                 mov     0, %i0
F001D3D8: c400e018                 ld      [%g3+0x18], %g2
F001D3DC: 80a60002                 cmp     %i0, %g2
F001D3E0: 3a80000e                 bcc,a   locret_F001D418
F001D3E4: b0102000                 mov     0, %i0
F001D3E8: c6560000                 ldsh    [%i0], %g3
F001D3EC: 80a0e000                 cmp     %g3, 0
F001D3F0: 22800006                 be,a    loc_F001D408
F001D3F4: b0062030                 inc     0x30, %i0 ! '0'
F001D3F8: 80a0c019                 cmp     %g3, %i1
F001D3FC: 02800007                 be      locret_F001D418
F001D400: 01000000                 nop
F001D404: b0062030                 inc     0x30, %i0 ! '0'
F001D408: 80a60002                 cmp     %i0, %g2
F001D40C: 2abffff8                 bcs,a   loc_F001D3EC
F001D410: c6560000                 ldsh    [%i0], %g3
F001D414: b0102000                 mov     0, %i0
F001D418: 81c7e008                 ret
F001D41C: 81e80000                 restore
