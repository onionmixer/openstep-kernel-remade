F0023C64: 9de3bf98                 save    %sp, -0x68, %sp
F0023C68: e2062008                 ld      [%i0+8], %l1
F0023C6C: 4000014e                 call    _vfs_lock
F0023C70: 90100018                 mov     %i0, %o0
F0023C74: a0920000                 orcc    %o0, %g0, %l0
F0023C78: 1280001b                 bne     locret_F0023CE4
F0023C7C: 01000000                 nop
F0023C80: 40000806                 call    _dnlc_purge
F0023C84: 01000000                 nop
F0023C88: d0062004                 ld      [%i0+4], %o0
F0023C8C: d2022010                 ld      [%o0+0x10], %o1
F0023C90: 9fc24000                 call    %o1
F0023C94: 90100018                 mov     %i0, %o0
F0023C98: d0062004                 ld      [%i0+4], %o0
F0023C9C: d2022004                 ld      [%o0+4], %o1
F0023CA0: 9fc24000                 call    %o1
F0023CA4: 90100018                 mov     %i0, %o0
F0023CA8: a0920000                 orcc    %o0, %g0, %l0
F0023CAC: 02800005                 be      loc_F0023CC0
F0023CB0: 80a46000                 cmp     %l1, 0
F0023CB4: 40000146                 call    _vfs_unlock
F0023CB8: 90100018                 mov     %i0, %o0
F0023CBC: 3080000a                 ba,a    locret_F0023CE4
F0023CC0: 02800007                 be      loc_F0023CDC
F0023CC4: 90100018                 mov     %i0, %o0
F0023CC8: 400013a7                 call    _vn_rele
F0023CCC: 90100011                 mov     %l1, %o0
F0023CD0: 400000fc                 call    _vfs_remove
F0023CD4: 90100018                 mov     %i0, %o0
F0023CD8: 90100018                 mov     %i0, %o0
F0023CDC: 40011131                 call    _kfree
F0023CE0: 9210212c                 mov     0x12C, %o1
F0023CE4: 81c7e008                 ret
F0023CE8: 91e80010                 restore %g0, %l0, %o0
