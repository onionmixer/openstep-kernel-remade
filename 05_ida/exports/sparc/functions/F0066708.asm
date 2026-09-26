F0066708: 9de3bf98                 save    %sp, -0x68, %sp
F006670C: 4000c11f                 call    _splusclock
F0066710: a0066020                 add     %i1, 0x20, %l0 ! ' '
F0066714: a2100008                 mov     %o0, %l1
F0066718: d0040000                 ld      [%l0], %o0
F006671C: 80a22000                 cmp     %o0, 0
F0066720: 12bffffe                 bne     loc_F0066718
F0066724: 01000000                 nop
F0066728: 4000c1e0                 call    _simple_lock_try
F006672C: 90100010                 mov     %l0, %o0
F0066730: 80a22000                 cmp     %o0, 0
F0066734: 02bffff9                 be      loc_F0066718
F0066738: 01000000                 nop
F006673C: d006614c                 ld      [%i1+0x14C], %o0
F0066740: 80a22000                 cmp     %o0, 0
F0066744: 22800005                 be,a    loc_F0066758
F0066748: d406604c                 ld      [%i1+0x4C], %o2
F006674C: 40000cc2                 call    _reset_timeout
F0066750: 90066118                 add     %i1, 0x118, %o0
F0066754: d406604c                 ld      [%i1+0x4C], %o2
F0066758: 900aa00f                 and     %o2, 0xF, %o0
F006675C: 92023fff                 add     %o0, -1, %o1
F0066760: 80a2600e                 cmp     %o1, 0xE! switch 15 cases
F0066764: 18800030                 bgu     def_F0066778! jumptable F0066778 default case, cases 1,3,5,7,9,11,13
F0066768: 113c0199                 sethi   %hi(jpt_F0066778), %o0
F006676C: 90122380                 bset    %lo(jpt_F0066778), %o0
F0066770: 932a6002                 sll     %o1, 2, %o1
F0066774: d0024008                 ld      [%o1+%o0], %o0
F0066778: 81c20000                 jmp     %o0! switch jump
F006677C: 01000000                 nop
F00667BC: 900abffe                 and     %o2, -2, %o0! jumptable F0066778 cases 0,8,10
F00667C0: 90122004                 bset    4, %o0
F00667C4: d026604c                 st      %o0, [%i1+0x4C]
F00667C8: d2066190                 ld      [%i1+0x190], %o1
F00667CC: c0266044                 clr     [%i1+0x44]
F00667D0: d0026114                 ld      [%o1+0x114], %o0
F00667D4: 80a22000                 cmp     %o0, 0
F00667D8: 14800008                 bg      loc_F00667F8
F00667DC: 90100019                 mov     %i1, %o0
F00667E0: 113c04d0                 sethi   %hi(_active_threads), %o0
F00667E4: d0022260                 ld      [%o0+%lo(_active_threads)], %o0
F00667E8: d0022190                 ld      [%o0+0x190], %o0
F00667EC: 80a24008                 cmp     %o1, %o0
F00667F0: 02800005                 be      loc_F0066804
F00667F4: 90100019                 mov     %i1, %o0
F00667F8: 40002d2a                 call    _thread_setrun
F00667FC: 92102001                 mov     1, %o1
F0066800: 30800009                 ba,a    def_F0066778! jumptable F0066778 default case, cases 1,3,5,7,9,11,13
F0066804: c0266020                 clr     [%i1+0x20]
F0066808: 90100018                 mov     %i0, %o0
F006680C: 40002be6                 call    _thread_run
F0066810: 92100019                 mov     %i1, %o1
F0066814: 3080000c                 ba,a    loc_F0066844
F0066818: 900abffe                 and     %o2, -2, %o0! jumptable F0066778 cases 2,4,6,12,14
F006681C: d026604c                 st      %o0, [%i1+0x4C]
F0066820: c0266044                 clr     [%i1+0x44]
F0066824: c0266020                 clr     [%i1+0x20]! jumptable F0066778 default case, cases 1,3,5,7,9,11,13
F0066828: 80a62000                 cmp     %i0, 0
F006682C: 02800006                 be      loc_F0066844
F0066830: 01000000                 nop
F0066834: 4000c12b                 call    _spl0
F0066838: 01000000                 nop
F006683C: 4000b8aa                 call    _call_continuation
F0066840: 90100018                 mov     %i0, %o0
F0066844: 4000c138                 call    _splx
F0066848: 90100011                 mov     %l1, %o0
F006684C: 81c7e008                 ret
F0066850: 81e80000                 restore
