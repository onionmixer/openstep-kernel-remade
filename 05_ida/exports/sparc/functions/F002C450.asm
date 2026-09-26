F002C450: 9de3bf98                 save    %sp, -0x68, %sp
F002C454: 90102000                 mov     0, %o0
F002C458: 7fffc568                 call    _m_getclr
F002C45C: 92102004                 mov     4, %o1
F002C460: a0920000                 orcc    %o0, %g0, %l0
F002C464: 22800026                 be,a    locret_F002C4FC
F002C468: b0102037                 mov     0x37, %i0 ! '7'
F002C46C: a206203c                 add     %i0, 0x3C, %l1 ! '<'
F002C470: 90100011                 mov     %l1, %o0
F002C474: 7fffd013                 call    _sbreserve
F002C478: 92102800                 mov     0x800, %o1
F002C47C: 80a22000                 cmp     %o0, 0
F002C480: 0280001c                 be      loc_F002C4F0
F002C484: 90062024                 add     %i0, 0x24, %o0 ! '$'
F002C488: 7fffd00e                 call    _sbreserve
F002C48C: 92102824                 mov     0x824, %o1
F002C490: 80a22000                 cmp     %o0, 0
F002C494: 02800015                 be      loc_F002C4E8
F002C498: 153c04d8                 sethi   %hi(_rawcb), %o2
F002C49C: d6042004                 ld      [%l0+4], %o3
F002C4A0: 9204000b                 add     %l0, %o3, %o1
F002C4A4: f0226008                 st      %i0, [%o1+8]
F002C4A8: d2262008                 st      %o1, [%i0+8]
F002C4AC: c0226030                 clr     [%o1+0x30]
F002C4B0: d006200c                 ld      [%i0+0xC], %o0
F002C4B4: d0022004                 ld      [%o0+4], %o0
F002C4B8: d0020000                 ld      [%o0], %o0
F002C4BC: d032602c                 sth     %o0, [%o1+0x2C]
F002C4C0: f232602e                 sth     %i1, [%o1+0x2E]
F002C4C4: d002a3f0                 ld      [%o2+%lo(_rawcb)], %o0
F002C4C8: d024000b                 st      %o0, [%l0+%o3]
F002C4CC: 9012a3f0                 or      %o2, %lo(_rawcb), %o0
F002C4D0: d0226004                 st      %o0, [%o1+4]
F002C4D4: d002a3f0                 ld      [%o2+%lo(_rawcb)], %o0
F002C4D8: b0102000                 mov     0, %i0
F002C4DC: d2222004                 st      %o1, [%o0+4]
F002C4E0: 10800007                 ba      locret_F002C4FC
F002C4E4: d222a3f0                 st      %o1, [%o2+0x3F0]
F002C4E8: 7fffd008                 call    _sbrelease
F002C4EC: 90100011                 mov     %l1, %o0
F002C4F0: 7fffc571                 call    _m_free
F002C4F4: 90100010                 mov     %l0, %o0
F002C4F8: b0102037                 mov     0x37, %i0 ! '7'
F002C4FC: 81c7e008                 ret
F002C500: 81e80000                 restore
