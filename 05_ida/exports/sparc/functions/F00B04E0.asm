F00B04E0: 9de3bf98                 save    %sp, -0x68, %sp
F00B04E4: 113c0470                 sethi   %hi(_obp_romvec_version), %o0
F00B04E8: d0022278                 ld      [%o0+%lo(_obp_romvec_version)], %o0
F00B04EC: 80a23fff                 cmp     %o0, -1
F00B04F0: 0280000b                 be      loc_F00B051C
F00B04F4: 80a62000                 cmp     %i0, 0
F00B04F8: 02800009                 be      loc_F00B051C
F00B04FC: 80a63fff                 cmp     %i0, -1
F00B0500: 2280000e                 be,a    locret_F00B0538
F00B0504: b0102000                 mov     0, %i0
F00B0508: 7ffffbee                 call    _prom_rootnode
F00B050C: 01000000                 nop
F00B0510: 80a60008                 cmp     %i0, %o0
F00B0514: 12800004                 bne     loc_F00B0524
F00B0518: 01000000                 nop
F00B051C: 10800007                 ba      locret_F00B0538
F00B0520: b0102000                 mov     0, %i0
F00B0524: 7ffffbe7                 call    _prom_rootnode
F00B0528: 01000000                 nop
F00B052C: 7fffffcc                 call    sub_F00B045C
F00B0530: 92100018                 mov     %i0, %o1
F00B0534: b0100008                 mov     %o0, %i0
F00B0538: 81c7e008                 ret
F00B053C: 81e80000                 restore
