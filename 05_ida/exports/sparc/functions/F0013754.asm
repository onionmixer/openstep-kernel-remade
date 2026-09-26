F0013754: 9de3bf70                 save    %sp, -0x90, %sp
F0013758: 233c04cf                 sethi   %hi(dword_F0133DDC), %l1
F001375C: 113c042d90122018         set     aNextstep, %o0! "NEXTSTEP"
F0013764: d20461dc                 ld      [%l1+%lo(dword_F0133DDC)], %o1
F0013768: 94102020                 mov     0x20, %o2 ! ' '
F001376C: e6026024                 ld      [%o1+0x24], %l3
F0013770: a407bfd4                 add     %fp, var_2C, %l2
F0013774: d204c000                 ld      [%l3], %o1
F0013778: 400211ee                 call    _copyoutstr
F001377C: 96100012                 mov     %l2, %o3
F0013780: d20461dc                 ld      [%l1+%lo(dword_F0133DDC)], %o1
F0013784: d02a6038                 stb     %o0, [%o1+0x38]
F0013788: d00461dc                 ld      [%l1+%lo(dword_F0133DDC)], %o0
F001378C: d04a2038                 ldsb    [%o0+0x38], %o0
F0013790: 80a22000                 cmp     %o0, 0
F0013794: 1280003a                 bne     locret_F001387C
F0013798: 113c04d1                 sethi   %hi(_hostname), %o0
F001379C: 90122230                 bset    %lo(_hostname), %o0
F00137A0: 94102020                 mov     0x20, %o2 ! ' '
F00137A4: d204c000                 ld      [%l3], %o1
F00137A8: 96100012                 mov     %l2, %o3
F00137AC: 400211e1                 call    _copyoutstr
F00137B0: 92026020                 inc     0x20, %o1 ! ' '
F00137B4: d20461dc                 ld      [%l1+0x1DC], %o1
F00137B8: d02a6038                 stb     %o0, [%o1+0x38]
F00137BC: d00461dc                 ld      [%l1+0x1DC], %o0
F00137C0: d04a2038                 ldsb    [%o0+0x38], %o0
F00137C4: 80a22000                 cmp     %o0, 0
F00137C8: 1280002d                 bne     locret_F001387C
F00137CC: a007bfd8                 add     %fp, var_28, %l0
F00137D0: 90100010                 mov     %l0, %o0! char *
F00137D4: 133c042d92126028         set     aD_0, %o1! "%d"
F00137DC: 400003e3                 call    _sprintf
F00137E0: 94102000                 mov     0, %o2
F00137E4: 90100010                 mov     %l0, %o0
F00137E8: 94102020                 mov     0x20, %o2 ! ' '
F00137EC: d204c000                 ld      [%l3], %o1
F00137F0: 96100012                 mov     %l2, %o3
F00137F4: 400211cf                 call    _copyoutstr
F00137F8: 92026040                 inc     0x40, %o1 ! '@'
F00137FC: d20461dc                 ld      [%l1+0x1DC], %o1
F0013800: d02a6038                 stb     %o0, [%o1+0x38]
F0013804: d00461dc                 ld      [%l1+0x1DC], %o0
F0013808: d04a2038                 ldsb    [%o0+0x38], %o0
F001380C: 80a22000                 cmp     %o0, 0
F0013810: 1280001b                 bne     locret_F001387C
F0013814: 90100010                 mov     %l0, %o0! char *
F0013818: 133c042d92126030         set     aD_1, %o1! "%d"
F0013820: 400003d2                 call    _sprintf
F0013824: 94102004                 mov     4, %o2
F0013828: 90100010                 mov     %l0, %o0
F001382C: 94102020                 mov     0x20, %o2 ! ' '
F0013830: d204c000                 ld      [%l3], %o1
F0013834: 96100012                 mov     %l2, %o3
F0013838: 400211be                 call    _copyoutstr
F001383C: 92026060                 inc     0x60, %o1 ! '`'
F0013840: d20461dc                 ld      [%l1+0x1DC], %o1
F0013844: d02a6038                 stb     %o0, [%o1+0x38]
F0013848: d00461dc                 ld      [%l1+0x1DC], %o0
F001384C: d04a2038                 ldsb    [%o0+0x38], %o0
F0013850: 80a22000                 cmp     %o0, 0
F0013854: 1280000a                 bne     locret_F001387C
F0013858: 113c042d                 sethi   %hi(aUnknown), %o0! "Unknown"
F001385C: 90122038                 bset    %lo(aUnknown), %o0! "Unknown"
F0013860: 94102020                 mov     0x20, %o2 ! ' '
F0013864: d204c000                 ld      [%l3], %o1
F0013868: 96100012                 mov     %l2, %o3
F001386C: 400211b1                 call    _copyoutstr
F0013870: 92026080                 inc     0x80, %o1
F0013874: d20461dc                 ld      [%l1+0x1DC], %o1
F0013878: d02a6038                 stb     %o0, [%o1+0x38]
F001387C: 81c7e008                 ret
F0013880: 81e80000                 restore
