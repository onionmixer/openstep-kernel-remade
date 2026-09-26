F003EE44: 9de3bf98                 save    %sp, -0x68, %sp
F003EE48: 80a6a001                 cmp     %i2, 1
F003EE4C: 34800026                 bg,a    locret_F003EEE4
F003EE50: b0102000                 mov     0, %i0
F003EE54: f4062030                 ld      [%i0+0x30], %i2
F003EE58: d006a07c                 ld      [%i2+0x7C], %o0
F003EE5C: 80a22000                 cmp     %o0, 0
F003EE60: 12800006                 bne     loc_F003EE78
F003EE64: 01000000                 nop
F003EE68: d056a062                 ldsh    [%i2+0x62], %o0
F003EE6C: 80a22000                 cmp     %o0, 0
F003EE70: 02800009                 be      loc_F003EE94
F003EE74: 808e6002                 btst    2, %i1
F003EE78: 400007be                 call    _sync_vp
F003EE7C: 90100018                 mov     %i0, %o0
F003EE80: 90100018                 mov     %i0, %o0
F003EE84: 7fffe9f6                 call    _nfs_purge_caches
F003EE88: 92100019                 mov     %i1, %o1
F003EE8C: 10800013                 ba      loc_F003EED8
F003EE90: 808e6002                 btst    2, %i1
F003EE94: 02800011                 be      loc_F003EED8
F003EE98: 808e6002                 btst    2, %i1
F003EE9C: 113c0435                 sethi   %hi(_nfs_cto), %o0
F003EEA0: d00221c8                 ld      [%o0+%lo(_nfs_cto)], %o0
F003EEA4: 80a22000                 cmp     %o0, 0
F003EEA8: 12800009                 bne     loc_F003EECC
F003EEAC: 01000000                 nop
F003EEB0: d0062024                 ld      [%i0+0x24], %o0
F003EEB4: d0022128                 ld      [%o0+0x128], %o0
F003EEB8: d2022014                 ld      [%o0+0x14], %o1
F003EEBC: 11010000                 sethi   0x4000000, %o0
F003EEC0: 808a4008                 btst    %o0, %o1
F003EEC4: 12800005                 bne     loc_F003EED8
F003EEC8: 808e6002                 btst    2, %i1
F003EECC: 400007a9                 call    _sync_vp
F003EED0: 90100018                 mov     %i0, %o0
F003EED4: 808e6002                 btst    2, %i1
F003EED8: 02800003                 be      locret_F003EEE4
F003EEDC: b0102000                 mov     0, %i0
F003EEE0: f056a062                 ldsh    [%i2+0x62], %i0
F003EEE4: 81c7e008                 ret
F003EEE8: 81e80000                 restore
