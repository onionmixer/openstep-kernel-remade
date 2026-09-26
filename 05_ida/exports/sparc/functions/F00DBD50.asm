F00DBD50: 9de3bf90                 save    %sp, -0x70, %sp
F00DBD54: d0062068                 ld      [%i0+0x68], %o0
F00DBD58: 80a22001                 cmp     %o0, 1
F00DBD5C: 22800015                 be,a    locret_F00DBDB0
F00DBD60: b010225a                 mov     0x25A, %i0
F00DBD64: 14800007                 bg      loc_F00DBD80
F00DBD68: 80a22002                 cmp     %o0, 2
F00DBD6C: 80a22000                 cmp     %o0, 0
F00DBD70: 22800010                 be,a    locret_F00DBDB0
F00DBD74: b0102258                 mov     0x258, %i0
F00DBD78: 1080000a                 ba      loc_F00DBDA0
F00DBD7C: 113c03f1                 sethi   -0xFF03C00, %o0
F00DBD80: 02800006                 be      loc_F00DBD98
F00DBD84: 80a22003                 cmp     %o0, 3
F00DBD88: 2280000a                 be,a    locret_F00DBDB0
F00DBD8C: b0102259                 mov     0x259, %i0
F00DBD90: 10800004                 ba      loc_F00DBDA0
F00DBD94: 113c03f1                 sethi   -0xFF03C00, %o0
F00DBD98: 10800006                 ba      locret_F00DBDB0
F00DBD9C: b010225b                 mov     0x25B, %i0
F00DBDA0: d2062068                 ld      [%i0+0x68], %o1
F00DBDA4: 7fffa8d4                 call    _IOLog
F00DBDA8: 90122120                 bset    0x120, %o0
F00DBDAC: b0103fff                 mov     -1, %i0
F00DBDB0: 81c7e008                 ret
F00DBDB4: 81e80000                 restore
