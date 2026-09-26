F002C5A0: 9de3bf98                 save    %sp, -0x68, %sp
F002C5A4: d016204c                 lduh    [%i0+0x4C], %o0
F002C5A8: d2062008                 ld      [%i0+8], %o1
F002C5AC: 900a3ffd                 and     %o0, -3, %o0
F002C5B0: d036204c                 sth     %o0, [%i0+0x4C]
F002C5B4: d0126006                 lduh    [%o1+6], %o0
F002C5B8: 808a2001                 btst    1, %o0
F002C5BC: 02800004                 be      locret_F002C5CC
F002C5C0: 01000000                 nop
F002C5C4: 7fffffd0                 call    _raw_detach
F002C5C8: 90100018                 mov     %i0, %o0
F002C5CC: 81c7e008                 ret
F002C5D0: 81e80000                 restore
