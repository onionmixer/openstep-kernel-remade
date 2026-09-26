F008D8F8: 9de3bf90                 save    %sp, -0x70, %sp
F008D8FC: c4062008                 ld      [%i0+8], %g2
F008D900: 80a0a000                 cmp     %g2, 0
F008D904: 34800003                 bg,a    locret_F008D910
F008D908: b0102001                 mov     1, %i0
F008D90C: b0102000                 mov     0, %i0
F008D910: 81c7e008                 ret
F008D914: 81e80000                 restore
