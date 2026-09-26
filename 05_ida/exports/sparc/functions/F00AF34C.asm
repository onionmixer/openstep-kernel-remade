F00AF34C: 9de3bf98                 save    %sp, -0x68, %sp
F00AF350: 113c0470                 sethi   %hi(_obp_romvec_version), %o0
F00AF354: d0022278                 ld      [%o0+%lo(_obp_romvec_version)], %o0
F00AF358: 80a22000                 cmp     %o0, 0
F00AF35C: 02800007                 be      locret_F00AF378
F00AF360: 113c000c                 sethi   %hi(_romp), %o0
F00AF364: d2022030                 ld      [%o0+%lo(_romp)], %o1
F00AF368: d40260a8                 ld      [%o1+0xA8], %o2
F00AF36C: 90100018                 mov     %i0, %o0
F00AF370: 9fc28000                 call    %o2
F00AF374: 92100019                 mov     %i1, %o1
F00AF378: 81c7e008                 ret
F00AF37C: 81e80000                 restore
