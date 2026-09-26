F0024418: 9de3bf98                 save    %sp, -0x68, %sp
F002441C: b2067f80                 inc     -0x80, %i1
F0024420: 932e6003                 sll     %i1, 3, %o1
F0024424: 113c042f901223d8         set     _vfssw, %o0
F002442C: d4062004                 ld      [%i0+4], %o2
F0024430: 92024008                 add     %o1, %o0, %o1
F0024434: d0026004                 ld      [%o1+4], %o0
F0024438: 80a28008                 cmp     %o2, %o0
F002443C: 02800005                 be      locret_F0024450
F0024440: 113c04bd                 sethi   %hi(unk_F012F404), %o0
F0024444: 90122004                 bset    %lo(unk_F012F404), %o0
F0024448: 40000028                 call    _vfs_putnum
F002444C: 92100019                 mov     %i1, %o1
F0024450: 81c7e008                 ret
F0024454: 81e80000                 restore
