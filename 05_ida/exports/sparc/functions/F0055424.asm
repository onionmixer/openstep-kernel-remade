F0055424: 9de3bf98                 save    %sp, -0x68, %sp
F0055428: 90066014                 add     %i1, 0x14, %o0! void *
F005542C: 92100018                 mov     %i0, %o1! void *
F0055430: 4000fdb8                 call    _bcopy
F0055434: 9410001a                 mov     %i2, %o2
F0055438: d2066008                 ld      [%i1+8], %o1
F005543C: 80a26000                 cmp     %o1, 0
F0055440: 04800005                 ble     loc_F0055454
F0055444: 01000000                 nop
F0055448: 40004b56                 call    _kfree
F005544C: 90100019                 mov     %i1, %o0
F0055450: 30800003                 ba,a    locret_F005545C
F0055454: 7fffff6b                 call    _ipc_kmsg_free
F0055458: 90100019                 mov     %i1, %o0
F005545C: 81c7e008                 ret
F0055460: 81e80000                 restore
