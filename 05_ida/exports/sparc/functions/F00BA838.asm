F00BA838: 9de3bf98                 save    %sp, -0x68, %sp
F00BA83C: 40000037                 call    _zsa_process
F00BA840: d0062018                 ld      [%i0+0x18], %o0
F00BA844: 80a22000                 cmp     %o0, 0
F00BA848: 02800004                 be      locret_F00BA858
F00BA84C: 01000000                 nop
F00BA850: 40000004                 call    _zspoll
F00BA854: 90102001                 mov     1, %o0
F00BA858: 81c7e008                 ret
F00BA85C: 91e82000                 restore %g0, 0, %o0
