F00B73E8: 9de3bf98                 save    %sp, -0x68, %sp
F00B73EC: 90100018                 mov     %i0, %o0! void *
F00B73F0: 7fff769a                 call    _bzero
F00B73F4: 92102070                 mov     0x70, %o1 ! 'p'
F00B73F8: d0064000                 ld      [%i1], %o0
F00B73FC: d0262004                 st      %o0, [%i0+4]
F00B7400: d0066004                 ld      [%i1+4], %o0
F00B7404: d0262008                 st      %o0, [%i0+8]
F00B7408: 113c02e3901223f8         set     _scsi_pollintr, %o0
F00B7410: d0262010                 st      %o0, [%i0+0x10]
F00B7414: 90102009                 mov     9, %o0
F00B7418: d0262014                 st      %o0, [%i0+0x14]
F00B741C: 90062060                 add     %i0, 0x60, %o0 ! '`'
F00B7420: d026201c                 st      %o0, [%i0+0x1C]
F00B7424: 90062064                 add     %i0, 0x64, %o0 ! 'd'
F00B7428: d0262020                 st      %o0, [%i0+0x20]
F00B742C: 90103fff                 mov     -1, %o0
F00B7430: d02e202b                 stb     %o0, [%i0+0x2B]
F00B7434: 90102100                 mov     0x100, %o0
F00B7438: d036205c                 sth     %o0, [%i0+0x5C]
F00B743C: 90102001                 mov     1, %o0
F00B7440: d02e206a                 stb     %o0, [%i0+0x6A]
F00B7444: c02e206b                 clrb    [%i0+0x6B]
F00B7448: d02e206c                 stb     %o0, [%i0+0x6C]
F00B744C: f42e206d                 stb     %i2, [%i0+0x6D]
F00B7450: 81c7e008                 ret
F00B7454: 81e80000                 restore
