F001A2D8: 9de3bf98                 save    %sp, -0x68, %sp
F001A2DC: d206203c                 ld      [%i0+0x3C], %o1
F001A2E0: 11000100                 sethi   0x40000, %o0
F001A2E4: 808a4008                 btst    %o0, %o1
F001A2E8: 02800004                 be      loc_F001A2F8
F001A2EC: 113c042e                 sethi   %hi(asc_F010B8B0), %o0! "\b \b"
F001A2F0: 10800004                 ba      loc_F001A300
F001A2F4: a01220b0                 or      %o0, %lo(asc_F010B8B0), %l0! "\b \b"
F001A2F8: 113c042ea01220b8         set     asc_F010B8B8, %l0! "\b"
F001A300: b2867fff                 inccc   -1, %i1
F001A304: 0c800007                 bneg    locret_F001A320
F001A308: 90100010                 mov     %l0, %o0
F001A30C: 40000088                 call    _ttyoutstr
F001A310: 92100018                 mov     %i0, %o1
F001A314: b2867fff                 inccc   -1, %i1
F001A318: 1cbffffd                 bpos    loc_F001A30C
F001A31C: 90100010                 mov     %l0, %o0
F001A320: 81c7e008                 ret
F001A324: 81e80000                 restore
