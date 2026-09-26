F002BA64: 9de3bf98                 save    %sp, -0x68, %sp
F002BA68: 9010001a                 mov     %i2, %o0
F002BA6C: 9210001b                 mov     %i3, %o1
F002BA70: 94100018                 mov     %i0, %o2
F002BA74: 96100019                 mov     %i1, %o3
F002BA78: 7fffca32                 call    _mclgetx
F002BA7C: 98102000                 mov     0, %o4
F002BA80: 80a00008                 cmp     %g0, %o0
F002BA84: b0602000                 subc    %g0, 0, %i0
F002BA88: b00a0018                 and     %o0, %i0, %i0
F002BA8C: 81c7e008                 ret
F002BA90: 81e80000                 restore
