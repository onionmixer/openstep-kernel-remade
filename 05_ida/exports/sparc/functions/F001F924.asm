F001F924: 9de3bf98                 save    %sp, -0x68, %sp
F001F928: b2066001                 inc     %i1
F001F92C: 808e6001                 btst    1, %i1
F001F930: 02800004                 be      loc_F001F940
F001F934: e006200c                 ld      [%i0+0xC], %l0
F001F938: 40000010                 call    _sorflush
F001F93C: 90100018                 mov     %i0, %o0
F001F940: 808e6002                 btst    2, %i1
F001F944: 12800004                 bne     loc_F001F954
F001F948: 90100018                 mov     %i0, %o0
F001F94C: 10800009                 ba      locret_F001F970
F001F950: b0102000                 mov     0, %i0
F001F954: da04201c                 ld      [%l0+0x1C], %o5
F001F958: 92102007                 mov     7, %o1
F001F95C: 94102000                 mov     0, %o2
F001F960: 96102000                 mov     0, %o3
F001F964: 9fc34000                 call    %o5
F001F968: 98102000                 mov     0, %o4
F001F96C: b0100008                 mov     %o0, %i0
F001F970: 81c7e008                 ret
F001F974: 81e80000                 restore
