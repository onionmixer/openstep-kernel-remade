F00AED50: 9de3bf98                 save    %sp, -0x68, %sp
F00AED54: 113c0470                 sethi   %hi(_obp_romvec_version), %o0
F00AED58: d0022278                 ld      [%o0+%lo(_obp_romvec_version)], %o0
F00AED5C: 80a22000                 cmp     %o0, 0
F00AED60: 02800009                 be      loc_F00AED84
F00AED64: 113c000c                 sethi   %hi(_romp), %o0
F00AED68: d2022030                 ld      [%o0+%lo(_romp)], %o1
F00AED6C: d402609c                 ld      [%o1+0x9C], %o2
F00AED70: 90100018                 mov     %i0, %o0
F00AED74: 9fc28000                 call    %o2
F00AED78: 92100019                 mov     %i1, %o1
F00AED7C: 10800003                 ba      locret_F00AED88
F00AED80: b0100008                 mov     %o0, %i0
F00AED84: b0102000                 mov     0, %i0
F00AED88: 81c7e008                 ret
F00AED8C: 81e80000                 restore
