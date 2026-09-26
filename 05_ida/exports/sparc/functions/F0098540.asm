F0098540: 9de3bf98                 save    %sp, -0x68, %sp
F0098544: 133c044aa2126238         set     _mach_info, %l1
F009854C: 113c044b90122038         set     _sysname, %o0
F0098554: d0246004                 st      %o0, [%l1+4]
F0098558: 90102071                 mov     0x71, %o0 ! 'q'
F009855C: d0226238                 st      %o0, [%o1+0x238]
F0098560: 173c044a9412e254         set     _mmc_info, %o2
F0098568: 133c044b90126100         set     _mcname, %o0
F0098570: d022a004                 st      %o0, [%o2+4]
F0098574: c02a6100                 clrb    [%o1+0x100]
F0098578: 90103fff                 mov     -1, %o0
F009857C: d022e254                 st      %o0, [%o3+0x254]
F0098580: 94102000                 mov     0, %o2
F0098584: 113c044b92122060         set     _modname, %o1
F009858C: 113c044a90122264         set     _mod_info, %o0
F0098594: d2222004                 st      %o1, [%o0+4]
F0098598: 92026028                 inc     0x28, %o1 ! '('
F009859C: 9402a001                 inc     %o2
F00985A0: 80a2a003                 cmp     %o2, 3
F00985A4: 08bffffc                 bleu    loc_F0098594
F00985A8: 90022074                 inc     0x74, %o0 ! 't'
F00985AC: 40005bb3                 call    _prom_nextnode
F00985B0: 90102000                 mov     0, %o0
F00985B4: a0100008                 mov     %o0, %l0
F00985B8: 113c044b94122038         set     _sysname, %o2
F00985C0: 92102027                 mov     0x27, %o1 ! '''
F00985C4: c02a8000                 clrb    [%o2]
F00985C8: 9402a001                 inc     %o2
F00985CC: 90924000                 orcc    %o1, %g0, %o0
F00985D0: 14bffffd                 bg      loc_F00985C4
F00985D4: 92027fff                 inc     -1, %o1
F00985D8: 90100010                 mov     %l0, %o0
F00985DC: 133c044b                 sethi   %hi(_psname), %o1! "name"
F00985E0: d4046004                 ld      [%l1+4], %o2
F00985E4: 40005a88                 call    _prom_getprop
F00985E8: 92126148                 bset    %lo(_psname), %o1! "name"
F00985EC: 40000017                 call    _fill_node
F00985F0: 90100010                 mov     %l0, %o0
F00985F4: 81c7e008                 ret
F00985F8: 81e80000                 restore
