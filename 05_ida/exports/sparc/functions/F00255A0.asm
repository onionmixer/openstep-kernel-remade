F00255A0: 9de3bf98                 save    %sp, -0x68, %sp
F00255A4: 86100018                 mov     %i0, %g3
F00255A8: c400c000                 ld      [%g3], %g2
F00255AC: 8088a004                 btst    4, %g2
F00255B0: 02800006                 be      locret_F00255C8
F00255B4: b0102000                 mov     0, %i0
F00255B8: f050e01c                 ldsh    [%g3+0x1C], %i0
F00255BC: 80a62000                 cmp     %i0, 0
F00255C0: 22800002                 be,a    locret_F00255C8
F00255C4: b0102005                 mov     5, %i0
F00255C8: 81c7e008                 ret
F00255CC: 81e80000                 restore
