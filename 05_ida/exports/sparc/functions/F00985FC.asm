F00985FC: 9de3bf78                 save    %sp, -0x88, %sp
F0098600: 9007bfd8                 add     %fp, var_28, %o0
F0098604: 40005ac3                 call    _prom_getidprom
F0098608: 92102020                 mov     0x20, %o1 ! ' '
F009860C: d00fbfd8                 ldub    [%fp+var_28], %o0
F0098610: 80a22001                 cmp     %o0, 1
F0098614: 1280000a                 bne     loc_F009863C
F0098618: 113c04d1                 sethi   -0xFECBC00, %o0
F009861C: d00fbfd9                 ldub    [%fp+var_27], %o0
F0098620: d207bfe4                 ld      [%fp+var_1C], %o1
F0098624: 912a2018                 sll     %o0, 24, %o0
F0098628: 93326008                 srl     %o1, 8, %o1
F009862C: 90120009                 bset    %o1, %o0
F0098630: 133c04d1                 sethi   %hi(_hostid), %o1
F0098634: 10800003                 ba      locret_F0098640
F0098638: d0226228                 st      %o0, [%o1+%lo(_hostid)]
F009863C: c0222228                 clr     [%o0+0x228]
F0098640: 81c7e008                 ret
F0098644: 81e80000                 restore
