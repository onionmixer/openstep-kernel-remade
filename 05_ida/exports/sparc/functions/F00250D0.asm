F00250D0: 9de3bf98                 save    %sp, -0x68, %sp
F00250D4: d0060000                 ld      [%i0], %o0
F00250D8: 808a2002                 btst    2, %o0
F00250DC: 02800004                 be      loc_F00250EC
F00250E0: 113c042f                 sethi   %hi(aDupBiodone), %o0! "dup biodone"
F00250E4: 7fffc023                 call    _panic
F00250E8: 901223a0                 bset    %lo(aDupBiodone), %o0! "dup biodone"
F00250EC: d0060000                 ld      [%i0], %o0
F00250F0: 92122002                 or      %o0, 2, %o1
F00250F4: 11000800                 sethi   0x200000, %o0
F00250F8: 808a4008                 btst    %o0, %o1
F00250FC: 02800008                 be      loc_F002511C
F0025100: d2260000                 st      %o1, [%i0]
F0025104: 902a4008                 andn    %o1, %o0, %o0
F0025108: d0260000                 st      %o0, [%i0]
F002510C: d2062030                 ld      [%i0+0x30], %o1
F0025110: 9fc24000                 call    %o1
F0025114: 90100018                 mov     %i0, %o0
F0025118: 3080000a                 ba,a    locret_F0025140
F002511C: 808a6100                 btst    0x100, %o1
F0025120: 02800005                 be      loc_F0025134
F0025124: 900a7fbf                 and     %o1, -0x41, %o0
F0025128: 7ffffdd0                 call    _brelse
F002512C: 90100018                 mov     %i0, %o0
F0025130: 30800004                 ba,a    locret_F0025140
F0025134: d0260000                 st      %o0, [%i0]
F0025138: 7fffb72c                 call    _wakeup
F002513C: 90100018                 mov     %i0, %o0
F0025140: 81c7e008                 ret
F0025144: 81e80000                 restore
