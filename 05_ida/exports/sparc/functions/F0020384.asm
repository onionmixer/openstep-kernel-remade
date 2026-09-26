F0020384: 9de3bf98                 save    %sp, -0x68, %sp
F0020388: 4001da0c                 call    _spltty
F002038C: 01000000                 nop
F0020390: d4062010                 ld      [%i0+0x10], %o2
F0020394: 80a2a000                 cmp     %o2, 0
F0020398: 0280000b                 be      loc_F00203C4
F002039C: a0100008                 mov     %o0, %l0
F00203A0: d2162014                 lduh    [%i0+0x14], %o1
F00203A4: 9010000a                 mov     %o2, %o0
F00203A8: 7fffd75b                 call    _selwakeup
F00203AC: 920a6010                 and     %o1, 0x10, %o1
F00203B0: 7fffd749                 call    _selthreadclear
F00203B4: 90062010                 add     %i0, 0x10, %o0
F00203B8: d0162014                 lduh    [%i0+0x14], %o0
F00203BC: 900a3fef                 and     %o0, -0x11, %o0
F00203C0: d0362014                 sth     %o0, [%i0+0x14]
F00203C4: 4001da58                 call    _splx
F00203C8: 90100010                 mov     %l0, %o0
F00203CC: d0162014                 lduh    [%i0+0x14], %o0
F00203D0: 808a2004                 btst    4, %o0
F00203D4: 0280000c                 be      locret_F0020404
F00203D8: 900a3ffb                 and     %o0, -5, %o0
F00203DC: 133c042f                 sethi   %hi(_nfs_wakeup_one_nfsd), %o1
F00203E0: d2026080                 ld      [%o1+%lo(_nfs_wakeup_one_nfsd)], %o1
F00203E4: 80a26001                 cmp     %o1, 1
F00203E8: 12800005                 bne     loc_F00203FC
F00203EC: d0362014                 sth     %o0, [%i0+0x14]
F00203F0: 7fffca8a                 call    _wakeup_one
F00203F4: 90100018                 mov     %i0, %o0
F00203F8: 30800003                 ba,a    locret_F0020404
F00203FC: 7fffca7b                 call    _wakeup
F0020400: 90100018                 mov     %i0, %o0
F0020404: 81c7e008                 ret
F0020408: 81e80000                 restore
