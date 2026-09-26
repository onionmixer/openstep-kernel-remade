F00A32FC: 9de3bf98                 save    %sp, -0x68, %sp
F00A3300: 113c0485                 sethi   %hi(aRootdevEn), %o0! "rootdev=en"
F00A3304: 40000150                 call    _getargs
F00A3308: 90122052                 bset    %lo(aRootdevEn), %o0! "rootdev=en"
F00A330C: 113c046c                 sethi   %hi(_boothowto), %o0
F00A3310: d0022104                 ld      [%o0+%lo(_boothowto)], %o0
F00A3314: 808a2008                 btst    8, %o0
F00A3318: 02800006                 be      locret_F00A3330
F00A331C: 113c0464                 sethi   %hi(aHaltedByHFlag), %o0! "halted by -h flag\n"
F00A3320: 40003116                 call    _prom_printf
F00A3324: 90122348                 bset    %lo(aHaltedByHFlag), %o0! "halted by -h flag\n"
F00A3328: 40002ee7                 call    _prom_enter_mon
F00A332C: 01000000                 nop
F00A3330: 81c7e008                 ret
F00A3334: 81e80000                 restore
