F00AF5E0: 9de3be98                 save    %sp, -0x168, %sp
F00AF5E4: 90100018                 mov     %i0, %o0
F00AF5E8: 133c0470                 sethi   %hi(aName), %o1! "name"
F00AF5EC: 7ffffe7c                 call    _prom_getproplen
F00AF5F0: 921262e8                 bset    %lo(aName), %o1! "name"
F00AF5F4: 90023fff                 inc     -1, %o0
F00AF5F8: 80a220fe                 cmp     %o0, 0xFE
F00AF5FC: 08800004                 bleu    loc_F00AF60C
F00AF600: 90100018                 mov     %i0, %o0
F00AF604: 1080000c                 ba      locret_F00AF634
F00AF608: b0102000                 mov     0, %i0
F00AF60C: 133c0470921262f0         set     aName_0, %o1! "name"
F00AF614: a007bef8                 add     %fp, var_108, %l0
F00AF618: 7ffffe7b                 call    _prom_getprop
F00AF61C: 94100010                 mov     %l0, %o2
F00AF620: 90100019                 mov     %i1, %o0
F00AF624: 40000006                 call    _prom_strcmp
F00AF628: 92100010                 mov     %l0, %o1
F00AF62C: 80a00008                 cmp     %g0, %o0
F00AF630: b0603fff                 subc    %g0, -1, %i0
F00AF634: 81c7e008                 ret
F00AF638: 81e80000                 restore
