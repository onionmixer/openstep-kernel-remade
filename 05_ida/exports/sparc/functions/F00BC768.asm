F00BC768: 9de3bf90                 save    %sp, -0x70, %sp
F00BC76C: d0062114                 ld      [%i0+0x114], %o0
F00BC770: 80a22001                 cmp     %o0, 1
F00BC774: 02800005                 be      loc_F00BC788
F00BC778: 80a22003                 cmp     %o0, 3
F00BC77C: 22800004                 be,a    loc_F00BC78C
F00BC780: d0062110                 ld      [%i0+0x110], %o0
F00BC784: 30800006                 ba,a    locret_F00BC79C
F00BC788: d006210c                 ld      [%i0+0x10C], %o0
F00BC78C: 932ea018                 sll     %i2, 24, %o1
F00BC790: d4022014                 ld      [%o0+0x14], %o2
F00BC794: 9fc28000                 call    %o2
F00BC798: 933a6018                 sra     %o1, 24, %o1
F00BC79C: 81c7e008                 ret
F00BC7A0: 91e82000                 restore %g0, 0, %o0
