F006A414: 9de3bf98                 save    %sp, -0x68, %sp
F006A418: 113c043f                 sethi   %hi(aUser), %o0! "__USER"
F006A41C: 7fffffb1                 call    _getsegbyname
F006A420: 901220c0                 bset    %lo(aUser), %o0! "__USER"
F006A424: b0100008                 mov     %o0, %i0
F006A428: 113c0000                 sethi   %hi(dword_F0000000), %o0
F006A42C: 7fffffe6                 call    sub_F006A3C4
F006A430: 90122000                 bset    %lo(dword_F0000000), %o0
F006A434: 80a62000                 cmp     %i0, 0
F006A438: 12800016                 bne     locret_F006A490
F006A43C: a0100008                 mov     %o0, %l0
F006A440: 80a42000                 cmp     %l0, 0
F006A444: 12800004                 bne     loc_F006A454
F006A448: 113c04f0                 sethi   -0xFEC4000, %o0
F006A44C: 10800011                 ba      locret_F006A490
F006A450: b0102000                 mov     0, %i0
F006A454: 133c043f92126040         set     unk_F010FC40, %o1
F006A45C: d22220f0                 st      %o1, [%o0+0xF0]
F006A460: d004200c                 ld      [%l0+0xC], %o0! __dst
F006A464: b0100009                 mov     %o1, %i0
F006A468: 4000000c                 call    sub_F006A498
F006A46C: d0262018                 st      %o0, [%i0+0x18]
F006A470: d026201c                 st      %o0, [%i0+0x1C]
F006A474: d2042008                 ld      [%l0+8], %o1! __src
F006A478: 7ffe742c                 call    _strcpy
F006A47C: 90062038                 add     %i0, 0x38, %o0 ! '8'
F006A480: d0062018                 ld      [%i0+0x18], %o0
F006A484: d206201c                 ld      [%i0+0x1C], %o1
F006A488: d0262058                 st      %o0, [%i0+0x58]
F006A48C: d226205c                 st      %o1, [%i0+0x5C]
F006A490: 81c7e008                 ret
F006A494: 81e80000                 restore
