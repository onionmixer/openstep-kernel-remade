F003FAE0: 9de3bf98                 save    %sp, -0x68, %sp
F003FAE4: e0062030                 ld      [%i0+0x30], %l0
F003FAE8: 7ffff6cf                 call    _rlock
F003FAEC: 90100010                 mov     %l0, %o0
F003FAF0: 400004b9                 call    sub_F0040DD4
F003FAF4: 90100018                 mov     %i0, %o0
F003FAF8: 7ffff6e9                 call    _runlock
F003FAFC: 90100010                 mov     %l0, %o0
F003FB00: f0542062                 ldsh    [%l0+0x62], %i0
F003FB04: 81c7e008                 ret
F003FB08: 81e80000                 restore
