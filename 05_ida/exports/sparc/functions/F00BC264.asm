F00BC264: 9de3bf98                 save    %sp, -0x68, %sp
F00BC268: 113c04fd                 sethi   %hi(_kmId), %o0
F00BC26C: d0022240                 ld      [%o0+%lo(_kmId)], %o0! id
F00BC270: 80a22000                 cmp     %o0, 0
F00BC274: 02800005                 be      locret_F00BC288
F00BC278: 94100018                 mov     %i0, %o2
F00BC27C: 133c0504                 sethi   %hi(paDrawgraphicpan), %o1! SEL
F00BC280: 4000d57c                 call    _objc_msgSend
F00BC284: d2026230                 ld      [%o1+%lo(paDrawgraphicpan)], %o1
F00BC288: 81c7e008                 ret
F00BC28C: 81e80000                 restore
