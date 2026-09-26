F00B14BC: 9de3bf78                 save    %sp, -0x88, %sp
F00B14C0: 9007bfd8                 add     %fp, var_28, %o0
F00B14C4: 7ffff713                 call    _prom_getidprom
F00B14C8: 92102020                 mov     0x20, %o1 ! ' '
F00B14CC: f00fbfd9                 ldub    [%fp+var_27], %i0
F00B14D0: d007bfe4                 ld      [%fp+var_1C], %o0
F00B14D4: b12e2018                 sll     %i0, 24, %i0
F00B14D8: 91322008                 srl     %o0, 8, %o0
F00B14DC: 81c7e008                 ret
F00B14E0: 91ee0008                 restore %i0, %o0, %o0
