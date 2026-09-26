F00304F4: 9de3bf78                 save    %sp, -0x88, %sp
F00304F8: a2100018                 mov     %i0, %l1
F00304FC: d2044000                 ld      [%l1], %o1! __src
F0030500: a007bfd8                 add     %fp, var_28, %l0
F0030504: f007a040                 ld      [%fp+arg_40], %i0
F0030508: 7fff5c08                 call    _strcpy
F003050C: 90100010                 mov     %l0, %o0
F0030510: d04fbfd8                 ldsb    [%fp+var_28], %o0
F0030514: 80a22000                 cmp     %o0, 0
F0030518: 02800008                 be      loc_F0030538
F003051C: 90100019                 mov     %i1, %o0
F0030520: a0042001                 inc     %l0
F0030524: d04c0000                 ldsb    [%l0], %o0
F0030528: 80a22000                 cmp     %o0, 0
F003052C: 32bffffe                 bne,a   loc_F0030524
F0030530: a0042001                 inc     %l0
F0030534: 90100019                 mov     %i1, %o0! void *
F0030538: d4146008                 lduh    [%l1+8], %o2
F003053C: 9207bfe8                 add     %fp, var_18, %o1! void *
F0030540: 9402a030                 inc     0x30, %o2 ! '0'! size_t
F0030544: d42c0000                 stb     %o2, [%l0]
F0030548: c02c2001                 clrb    [%l0+1]
F003054C: 40019171                 call    _bcopy
F0030550: 94102010                 mov     0x10, %o2
F0030554: d007bfd8                 ld      [%fp+var_28], %o0
F0030558: d0260000                 st      %o0, [%i0]
F003055C: d007bfdc                 ld      [%fp+var_24], %o0
F0030560: d0262004                 st      %o0, [%i0+4]
F0030564: d007bfe0                 ld      [%fp+var_20], %o0
F0030568: d0262008                 st      %o0, [%i0+8]
F003056C: d007bfe4                 ld      [%fp+var_1C], %o0
F0030570: d026200c                 st      %o0, [%i0+0xC]
F0030574: d007bfe8                 ld      [%fp+var_18], %o0
F0030578: d0262010                 st      %o0, [%i0+0x10]
F003057C: d007bfec                 ld      [%fp+var_14], %o0
F0030580: d0262014                 st      %o0, [%i0+0x14]
F0030584: d007bff0                 ld      [%fp+var_10], %o0
F0030588: d0262018                 st      %o0, [%i0+0x18]
F003058C: d007bff4                 ld      [%fp+var_C], %o0
F0030590: d026201c                 st      %o0, [%i0+0x1C]
F0030594: 81c7e00c                 jmp     %i7+0xC
F0030598: 81e80000                 restore
