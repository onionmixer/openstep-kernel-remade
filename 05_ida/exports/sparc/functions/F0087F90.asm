F0087F90: 9de3bf98                 save    %sp, -0x68, %sp
F0087F94: 113c04d0                 sethi   %hi(_active_threads), %o0
F0087F98: d0022260                 ld      [%o0+%lo(_active_threads)], %o0
F0087F9C: a8102001                 mov     1, %l4
F0087FA0: 40003b50                 call    _spl0
F0087FA4: e8222078                 st      %l4, [%o0+0x78]
F0087FA8: 233c0447                 sethi   %hi(_vm_page_free_min), %l1
F0087FAC: d0046144                 ld      [%l1+%lo(_vm_page_free_min)], %o0
F0087FB0: 80a22000                 cmp     %o0, 0
F0087FB4: 12800019                 bne     loc_F0088018
F0087FB8: 133c0447                 sethi   -0xFEEE400, %o1! int
F0087FBC: 113c04f3                 sethi   %hi(_vm_page_free_count), %o0
F0087FC0: d0022000                 ld      [%o0+%lo(_vm_page_free_count)], %o0! int
F0087FC4: 7ffdf991                 call    _div
F0087FC8: 92102032                 mov     0x32, %o1 ! '2'
F0087FCC: 80a22002                 cmp     %o0, 2
F0087FD0: 14800004                 bg      loc_F0087FE0
F0087FD4: d0246144                 st      %o0, [%l1+%lo(_vm_page_free_min)]
F0087FD8: 90102003                 mov     3, %o0
F0087FDC: d0246144                 st      %o0, [%l1+%lo(_vm_page_free_min)]
F0087FE0: 133c0447                 sethi   %hi(_page_size), %o1
F0087FE4: e002613c                 ld      [%o1+%lo(_page_size)], %l0
F0087FE8: d0046144                 ld      [%l1+0x144], %o0
F0087FEC: 7ffdf945                 call    _umul
F0087FF0: 92100010                 mov     %l0, %o1
F0087FF4: 133c0447                 sethi   %hi(_vm_page_free_min_sanity), %o1
F0087FF8: d20260d8                 ld      [%o1+%lo(_vm_page_free_min_sanity)], %o1
F0087FFC: 80a20009                 cmp     %o0, %o1
F0088000: 08800005                 bleu    loc_F0088014
F0088004: 90100009                 mov     %o1, %o0
F0088008: 7ffdf97e                 call    _udiv
F008800C: 92100010                 mov     %l0, %o1
F0088010: d0246144                 st      %o0, [%l1+0x144]
F0088014: 133c0447                 sethi   -0xFEEE400, %o1
F0088018: d002614c                 ld      [%o1+0x14C], %o0
F008801C: 80a22000                 cmp     %o0, 0
F0088020: 12800004                 bne     loc_F0088030
F0088024: 153c0447                 sethi   -0xFEEE400, %o2
F0088028: 90102003                 mov     3, %o0
F008802C: d022614c                 st      %o0, [%o1+0x14C]
F0088030: d002a0d4                 ld      [%o2+0xD4], %o0
F0088034: 80a22000                 cmp     %o0, 0
F0088038: 3280000c                 bne,a   loc_F0088068
F008803C: 213c0447                 sethi   -0xFEEE400, %l0
F0088040: d002614c                 ld      [%o1+0x14C], %o0
F0088044: 9332201f                 srl     %o0, 31, %o1
F0088048: 90020009                 add     %o0, %o1, %o0
F008804C: 913a2001                 sra     %o0, 1, %o0
F0088050: 80a2200a                 cmp     %o0, 0xA
F0088054: 04800004                 ble     loc_F0088064
F0088058: d022a0d4                 st      %o0, [%o2+0xD4]
F008805C: 9010200a                 mov     0xA, %o0
F0088060: d022a0d4                 st      %o0, [%o2+0xD4]
F0088064: 213c0447                 sethi   -0xFEEE400, %l0
F0088068: d0042140                 ld      [%l0+0x140], %o0
F008806C: 80a22000                 cmp     %o0, 0
F0088070: 12800006                 bne     loc_F0088088
F0088074: 233c0447                 sethi   -0xFEEE400, %l1
F0088078: 113c0447                 sethi   %hi(_vm_page_free_min), %o0
F008807C: d0022144                 ld      [%o0+%lo(_vm_page_free_min)], %o0
F0088080: 912a2002                 sll     %o0, 2, %o0
F0088084: d0242140                 st      %o0, [%l0+0x140]
F0088088: d0046148                 ld      [%l1+0x148], %o0
F008808C: 80a22000                 cmp     %o0, 0
F0088090: 12800008                 bne     loc_F00880B0
F0088094: d2042140                 ld      [%l0+0x140], %o1! int
F0088098: 113c04f3                 sethi   %hi(_vm_page_free_count), %o0
F008809C: d0022000                 ld      [%o0+%lo(_vm_page_free_count)], %o0! int
F00880A0: 7ffdf95a                 call    _div
F00880A4: 92102003                 mov     3, %o1
F00880A8: d0246148                 st      %o0, [%l1+0x148]
F00880AC: d2042140                 ld      [%l0+0x140], %o1
F00880B0: 113c0447                 sethi   %hi(_vm_page_free_min), %o0
F00880B4: d0022144                 ld      [%o0+%lo(_vm_page_free_min)], %o0
F00880B8: 80a24008                 cmp     %o1, %o0
F00880BC: 34800005                 bg,a    loc_F00880D0
F00880C0: d0046148                 ld      [%l1+0x148], %o0
F00880C4: 90022001                 inc     %o0
F00880C8: d0242140                 st      %o0, [%l0+0x140]
F00880CC: d0046148                 ld      [%l1+0x148], %o0
F00880D0: d2042140                 ld      [%l0+0x140], %o1
F00880D4: 80a20009                 cmp     %o0, %o1
F00880D8: 14800005                 bg      loc_F00880EC
F00880DC: 113c04f3                 sethi   -0xFEC3400, %o0
F00880E0: 90026001                 add     %o1, 1, %o0
F00880E4: d0246148                 st      %o0, [%l1+0x148]
F00880E8: 113c04f3                 sethi   -0xFEC3400, %o0
F00880EC: a0122020                 or      %o0, 0x20, %l0
F00880F0: d0040000                 ld      [%l0], %o0
F00880F4: 80a22000                 cmp     %o0, 0
F00880F8: 12bffffe                 bne     loc_F00880F0
F00880FC: 01000000                 nop
F0088100: 40003b6a                 call    _simple_lock_try
F0088104: 90100010                 mov     %l0, %o0
F0088108: 80a22000                 cmp     %o0, 0
F008810C: 02bffff9                 be      loc_F00880F0
F0088110: 273c04f3                 sethi   -0xFEC3400, %l3
F0088114: 233c04f3                 sethi   -0xFEC3400, %l1
F0088118: 253c04f3                 sethi   -0xFEC3400, %l2
F008811C: 2f3c0447                 sethi   -0xFEEE400, %l7
F0088120: 2d3c04f0                 sethi   -0xFEC4000, %l6
F0088124: 2b3c0447                 sethi   -0xFEEE400, %l5
F0088128: 80a52000                 cmp     %l4, 0
F008812C: 0280000f                 be      loc_F0088168
F0088130: d204a000                 ld      [%l2], %o1
F0088134: d005e144                 ld      [%l7+0x144], %o0
F0088138: 80a24008                 cmp     %o1, %o0
F008813C: 04800010                 ble     loc_F008817C
F0088140: 113c0447                 sethi   %hi(_vm_page_free_target), %o0
F0088144: d0022140                 ld      [%o0+%lo(_vm_page_free_target)], %o0
F0088148: 80a24008                 cmp     %o1, %o0
F008814C: 16800008                 bge     loc_F008816C
F0088150: 9014e018                 or      %l3, 0x18, %o0
F0088154: d205a220                 ld      [%l6+0x220], %o1
F0088158: d0056148                 ld      [%l5+0x148], %o0
F008815C: 80a24008                 cmp     %o1, %o0
F0088160: 04800007                 ble     loc_F008817C
F0088164: 01000000                 nop
F0088168: 9014e018                 or      %l3, 0x18, %o0
F008816C: 92146020                 or      %l1, 0x20, %o1
F0088170: 7fffa413                 call    _thread_sleep
F0088174: 94102000                 mov     0, %o2
F0088178: 30800002                 ba,a    loc_F0088180
F008817C: c0246020                 clr     [%l1+0x20]
F0088180: 7ffffe68                 call    _vm_pageout_scan
F0088184: a0146020                 or      %l1, 0x20, %l0
F0088188: a8100008                 mov     %o0, %l4
F008818C: d0040000                 ld      [%l0], %o0
F0088190: 80a22000                 cmp     %o0, 0
F0088194: 12bffffe                 bne     loc_F008818C
F0088198: 01000000                 nop
F008819C: 40003b43                 call    _simple_lock_try
F00881A0: 90100010                 mov     %l0, %o0
F00881A4: 80a22000                 cmp     %o0, 0
F00881A8: 02bffff9                 be      loc_F008818C
F00881AC: 9014a000                 or      %l2, 0, %o0
F00881B0: 92102000                 mov     0, %o1
F00881B4: 7fffa392                 call    _thread_wakeup_prim
F00881B8: 94102000                 mov     0, %o2
F00881BC: 10bfffdc                 ba      loc_F008812C
F00881C0: 80a52000                 cmp     %l4, 0
