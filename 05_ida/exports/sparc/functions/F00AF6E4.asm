F00AF6E4: 9de3bf98                 save    %sp, -0x68, %sp
F00AF6E8: 113c0470                 sethi   %hi(_obp_romvec_version), %o0
F00AF6EC: d0022278                 ld      [%o0+%lo(_obp_romvec_version)], %o0
F00AF6F0: 80a22000                 cmp     %o0, 0
F00AF6F4: 0280000f                 be      loc_F00AF730
F00AF6F8: 133c04c5                 sethi   %hi(unk_F013168C), %o1
F00AF6FC: d04a628c                 ldsb    [%o1+%lo(unk_F013168C)], %o0
F00AF700: 80a22000                 cmp     %o0, 0
F00AF704: 1280000c                 bne     locret_F00AF734
F00AF708: b012628c                 or      %o1, %lo(unk_F013168C), %i0
F00AF70C: 7fffff5b                 call    _prom_nextnode
F00AF710: 90102000                 mov     0, %o0
F00AF714: 133c0470921262f8         set     aStdoutPath, %o1! "stdout-path"
F00AF71C: 7ffffe3a                 call    _prom_getprop
F00AF720: 94100018                 mov     %i0, %o2
F00AF724: 80a23fff                 cmp     %o0, -1
F00AF728: 12800003                 bne     locret_F00AF734
F00AF72C: 01000000                 nop
F00AF730: b0102000                 mov     0, %i0
F00AF734: 81c7e008                 ret
F00AF738: 81e80000                 restore
