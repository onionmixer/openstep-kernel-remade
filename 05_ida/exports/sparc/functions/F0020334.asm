F0020334: 9de3bf98                 save    %sp, -0x68, %sp
F0020338: 7fffd742                 call    _selthreadcache
F002033C: 90062010                 add     %i0, 0x10, %o0
F0020340: 80a22000                 cmp     %o0, 0
F0020344: 02800005                 be      locret_F0020358
F0020348: 01000000                 nop
F002034C: d0162014                 lduh    [%i0+0x14], %o0
F0020350: 90122010                 bset    0x10, %o0
F0020354: d0362014                 sth     %o0, [%i0+0x14]
F0020358: 81c7e008                 ret
F002035C: 81e80000                 restore
