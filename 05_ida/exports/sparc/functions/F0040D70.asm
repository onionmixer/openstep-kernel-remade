F0040D70: 9de3bf98                 save    %sp, -0x68, %sp
F0040D74: 4000b0f1                 call    _mfs_fsync
F0040D78: 90100018                 mov     %i0, %o0
F0040D7C: d0062030                 ld      [%i0+0x30], %o0
F0040D80: d0122060                 lduh    [%o0+0x60], %o0
F0040D84: 808a2010                 btst    0x10, %o0
F0040D88: 02800004                 be      locret_F0040D98
F0040D8C: 01000000                 nop
F0040D90: 40000011                 call    sub_F0040DD4
F0040D94: 90100018                 mov     %i0, %o0
F0040D98: 81c7e008                 ret
F0040D9C: 81e80000                 restore
