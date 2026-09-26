F00B92F4: 9de3bf98                 save    %sp, -0x68, %sp
F00B92F8: 94964000                 orcc    %i1, %g0, %o2
F00B92FC: 02800008                 be      loc_F00B931C
F00B9300: 80a6a000                 cmp     %i2, 0
F00B9304: 02800006                 be      loc_F00B931C
F00B9308: 113c04f6                 sethi   %hi(_iopbmap), %o0
F00B930C: d0022300                 ld      [%o0+%lo(_iopbmap)], %o0
F00B9310: 9206a003                 add     %i2, 3, %o1
F00B9314: 7fffaf00                 call    _rmfree
F00B9318: 920a7ffc                 and     %o1, -4, %o1
F00B931C: 7ffffd48                 call    _scsi_resfree
F00B9320: 90100018                 mov     %i0, %o0
F00B9324: 81c7e008                 ret
F00B9328: 81e80000                 restore
