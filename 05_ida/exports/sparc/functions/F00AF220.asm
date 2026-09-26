F00AF220: 9de3bf98                 save    %sp, -0x68, %sp
F00AF224: 113c0470                 sethi   %hi(_obp_romvec_version), %o0
F00AF228: d0022278                 ld      [%o0+%lo(_obp_romvec_version)], %o0
F00AF22C: 80a22000                 cmp     %o0, 0
F00AF230: 0280000f                 be      loc_F00AF26C
F00AF234: 133c04c5                 sethi   %hi(unk_F0131588), %o1
F00AF238: d04a6188                 ldsb    [%o1+%lo(unk_F0131588)], %o0
F00AF23C: 80a22000                 cmp     %o0, 0
F00AF240: 1280000c                 bne     locret_F00AF270
F00AF244: b0126188                 or      %o1, %lo(unk_F0131588), %i0
F00AF248: 4000008c                 call    _prom_nextnode
F00AF24C: 90102000                 mov     0, %o0
F00AF250: 133c047092126298         set     aStdinPath, %o1! "stdin-path"
F00AF258: 7fffff6b                 call    _prom_getprop
F00AF25C: 94100018                 mov     %i0, %o2
F00AF260: 80a23fff                 cmp     %o0, -1
F00AF264: 12800003                 bne     locret_F00AF270
F00AF268: 01000000                 nop
F00AF26C: b0102000                 mov     0, %i0
F00AF270: 81c7e008                 ret
F00AF274: 81e80000                 restore
