F0048780: 9de3bf98                 save    %sp, -0x68, %sp
F0048784: 90100018                 mov     %i0, %o0
F0048788: d2022040                 ld      [%o0+0x40], %o1
F004878C: d412602c                 lduh    [%o1+0x2C], %o2
F0048790: 9532a008                 srl     %o2, 8, %o2
F0048794: 932aa001                 sll     %o2, 1, %o1
F0048798: 9202400a                 add     %o1, %o2, %o1
F004879C: 932a6003                 sll     %o1, 3, %o1
F00487A0: 153c04719412a3ac         set     _bdevsw, %o2
F00487A8: 9202400a                 add     %o1, %o2, %o1
F00487AC: d2026008                 ld      [%o1+8], %o1
F00487B0: 9fc24000                 call    %o1
F00487B4: b0102000                 mov     0, %i0
F00487B8: 81c7e008                 ret
F00487BC: 81e80000                 restore
