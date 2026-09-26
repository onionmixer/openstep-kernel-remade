F00A46D0: 9de3bf98                 save    %sp, -0x68, %sp
F00A46D4: 94100018                 mov     %i0, %o2
F00A46D8: 80a2a004                 cmp     %o2, 4
F00A46DC: 12800004                 bne     loc_F00A46EC
F00A46E0: 80a2a003                 cmp     %o2, 3
F00A46E4: 1080000c                 ba      locret_F00A4714
F00A46E8: b0102000                 mov     0, %i0
F00A46EC: 12800007                 bne     loc_F00A4708
F00A46F0: 113c0465                 sethi   -0xFEE6C00, %o0
F00A46F4: 113c0465                 sethi   %hi(aNoticeUsingOld), %o0! "NOTICE: using old boot memory list inte"...
F00A46F8: 40002c20                 call    _prom_printf
F00A46FC: 90122320                 bset    %lo(aNoticeUsingOld), %o0! "NOTICE: using old boot memory list inte"...
F00A4700: 10800005                 ba      locret_F00A4714
F00A4704: b0102001                 mov     1, %i0
F00A4708: 90122350                 bset    0x350, %o0! char *
F00A470C: 7ffdc299                 call    _panic
F00A4710: 92102004                 mov     4, %o1
F00A4714: 81c7e008                 ret
F00A4718: 81e80000                 restore
