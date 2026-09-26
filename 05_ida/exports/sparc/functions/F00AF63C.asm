F00AF63C: 9de3bf98                 save    %sp, -0x68, %sp
F00AF640: f40e0000                 ldub    [%i0], %i2
F00AF644: 10800009                 ba      loc_F00AF668
F00AF648: c64e4000                 ldsb    [%i1], %g3
F00AF64C: 80a6a000                 cmp     %i2, 0
F00AF650: 12800004                 bne     loc_F00AF660
F00AF654: b0062001                 inc     %i0
F00AF658: 1080000b                 ba      locret_F00AF684
F00AF65C: b0102000                 mov     0, %i0
F00AF660: f40e0000                 ldub    [%i0], %i2
F00AF664: c64e4000                 ldsb    [%i1], %g3
F00AF668: c44e0000                 ldsb    [%i0], %g2
F00AF66C: 80a08003                 cmp     %g2, %g3
F00AF670: 02bffff7                 be      loc_F00AF64C
F00AF674: b2066001                 inc     %i1
F00AF678: c44e0000                 ldsb    [%i0], %g2
F00AF67C: f04e7fff                 ldsb    [%i1-1], %i0
F00AF680: b0208018                 sub     %g2, %i0, %i0
F00AF684: 81c7e008                 ret
F00AF688: 81e80000                 restore
