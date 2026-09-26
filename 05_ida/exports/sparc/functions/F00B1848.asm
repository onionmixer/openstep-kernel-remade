F00B1848: 9de3bf98                 save    %sp, -0x68, %sp
F00B184C: 113c0471                 sethi   %hi(_devdesc_found), %o0
F00B1850: c02223a8                 clr     [%o0+%lo(_devdesc_found)]
F00B1854: 113c04fb                 sethi   %hi(_top_devinfo), %o0
F00B1858: d0022088                 ld      [%o0+%lo(_top_devinfo)], %o0
F00B185C: 92100018                 mov     %i0, %o1
F00B1860: 7fffffe0                 call    _find_devinfo
F00B1864: 94100019                 mov     %i1, %o2
F00B1868: 81c7e008                 ret
F00B186C: 91e80008                 restore %g0, %o0, %o0
