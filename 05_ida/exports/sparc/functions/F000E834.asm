F000E834: 9de3bf98                 save    %sp, -0x68, %sp
F000E838: 400000ba                 call    _get_posix_proc
F000E83C: d0562030                 ldsh    [%i0+0x30], %o0
F000E840: a0100008                 mov     %o0, %l0
F000E844: d0042010                 ld      [%l0+0x10], %o0
F000E848: d2022004                 ld      [%o0+4], %o1
F000E84C: 80a26000                 cmp     %o1, 0
F000E850: 0280000f                 be      loc_F000E88C
F000E854: 94022004                 add     %o0, 4, %o2
F000E858: d0028000                 ld      [%o2], %o0
F000E85C: 80a20018                 cmp     %o0, %i0
F000E860: 12800005                 bne     loc_F000E874
F000E864: 01000000                 nop
F000E868: d004200c                 ld      [%l0+0xC], %o0
F000E86C: 1080000b                 ba      loc_F000E898
F000E870: d0228000                 st      %o0, [%o2]
F000E874: 400000ab                 call    _get_posix_proc
F000E878: d0522030                 ldsh    [%o0+0x30], %o0
F000E87C: d202200c                 ld      [%o0+0xC], %o1
F000E880: 80a26000                 cmp     %o1, 0
F000E884: 12bffff5                 bne     loc_F000E858
F000E888: 9402200c                 add     %o0, 0xC, %o2
F000E88C: 113c042c                 sethi   %hi(aLeavepgrpCanTF), %o0! "leavepgrp(): can't find p in pgrp"
F000E890: 40001a38                 call    _panic
F000E894: 90122108                 bset    %lo(aLeavepgrpCanTF), %o0! "leavepgrp(): can't find p in pgrp"
F000E898: d2042010                 ld      [%l0+0x10], %o1
F000E89C: d0026004                 ld      [%o1+4], %o0
F000E8A0: 80a22000                 cmp     %o0, 0
F000E8A4: 32800005                 bne,a   loc_F000E8B8
F000E8A8: c0242010                 clr     [%l0+0x10]
F000E8AC: 40000006                 call    _pgdelete
F000E8B0: 90100009                 mov     %o1, %o0
F000E8B4: c0242010                 clr     [%l0+0x10]
F000E8B8: c036202e                 clrh    [%i0+0x2E]
F000E8BC: 81c7e008                 ret
F000E8C0: 81e80000                 restore
