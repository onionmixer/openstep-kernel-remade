F00AF304: 9de3bf98                 save    %sp, -0x68, %sp
F00AF308: 113c0470                 sethi   %hi(_obp_romvec_version), %o0
F00AF30C: d0022278                 ld      [%o0+%lo(_obp_romvec_version)], %o0
F00AF310: 80a22000                 cmp     %o0, 0
F00AF314: 0280000b                 be      loc_F00AF340
F00AF318: 92100019                 mov     %i1, %o1
F00AF31C: 153c000c                 sethi   %hi(_romp), %o2
F00AF320: d602a030                 ld      [%o2+%lo(_romp)], %o3
F00AF324: 90100018                 mov     %i0, %o0
F00AF328: d802e0a4                 ld      [%o3+0xA4], %o4
F00AF32C: 9410001a                 mov     %i2, %o2
F00AF330: 9fc30000                 call    %o4
F00AF334: 9610001b                 mov     %i3, %o3
F00AF338: 10800003                 ba      locret_F00AF344
F00AF33C: b0100008                 mov     %o0, %i0
F00AF340: b0102000                 mov     0, %i0
F00AF344: 81c7e008                 ret
F00AF348: 81e80000                 restore
