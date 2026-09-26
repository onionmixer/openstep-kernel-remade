F00106A4: 9de3bf98                 save    %sp, -0x68, %sp
F00106A8: 40023046                 call    _pmap_create
F00106AC: 90102000                 mov     0, %o0
F00106B0: 92102000                 mov     0, %o1
F00106B4: 94102000                 mov     0, %o2
F00106B8: 4001ce7e                 call    _vm_map_create
F00106BC: 96102001                 mov     1, %o3
F00106C0: a6100008                 mov     %o0, %l3
F00106C4: 113c04d3a01223b8         set     _all_psets_lock, %l0
F00106CC: d0040000                 ld      [%l0], %o0
F00106D0: 80a22000                 cmp     %o0, 0
F00106D4: 12bffffe                 bne     loc_F00106CC
F00106D8: 01000000                 nop
F00106DC: 400219f3                 call    _simple_lock_try
F00106E0: 90100010                 mov     %l0, %o0
F00106E4: 80a22000                 cmp     %o0, 0
F00106E8: 02bffff9                 be      loc_F00106CC
F00106EC: 133c04d3                 sethi   %hi(_all_psets), %o1
F00106F0: e20263b0                 ld      [%o1+%lo(_all_psets)], %l1
F00106F4: 941263b0                 or      %o1, %lo(_all_psets), %o2
F00106F8: 80a4400a                 cmp     %l1, %o2
F00106FC: 0280001c                 be      loc_F001076C
F0010700: 113c04d3                 sethi   %hi(_default_pset), %o0! set
F0010704: ac1223c0                 or      %o0, %lo(_default_pset), %l6
F0010708: 253c04d3                 sethi   -0xFECB400, %l2
F001070C: aa100009                 mov     %o1, %l5
F0010710: a810000a                 mov     %o2, %l4
F0010714: 80a44016                 cmp     %l1, %l6
F0010718: 12800004                 bne     loc_F0010728
F001071C: 01000000                 nop
F0010720: 10800010                 ba      loc_F0010760
F0010724: e204614c                 ld      [%l1+0x14C], %l1
F0010728: c024a3b8                 clr     [%l2+0x3B8]
F001072C: 40017afa                 call    _processor_set_destroy
F0010730: 90100011                 mov     %l1, %o0
F0010734: a014a3b8                 or      %l2, 0x3B8, %l0
F0010738: d0040000                 ld      [%l0], %o0
F001073C: 80a22000                 cmp     %o0, 0
F0010740: 12bffffe                 bne     loc_F0010738
F0010744: 01000000                 nop
F0010748: 400219d8                 call    _simple_lock_try
F001074C: 90100010                 mov     %l0, %o0
F0010750: 80a22000                 cmp     %o0, 0
F0010754: 02bffff9                 be      loc_F0010738
F0010758: 01000000                 nop
F001075C: e20563b0                 ld      [%l5+0x3B0], %l1
F0010760: 80a44014                 cmp     %l1, %l4
F0010764: 12bfffed                 bne     loc_F0010718
F0010768: 80a44016                 cmp     %l1, %l6
F001076C: 113c04d3                 sethi   %hi(_all_psets_lock), %o0
F0010770: c02223b8                 clr     [%o0+%lo(_all_psets_lock)]
F0010774: 113c04d3a21223c0         set     _default_pset, %l1
F001077C: a0046158                 add     %l1, 0x158, %l0
F0010780: d0040000                 ld      [%l0], %o0
F0010784: 80a22000                 cmp     %o0, 0
F0010788: 12bffffe                 bne     loc_F0010780
F001078C: 01000000                 nop
F0010790: 400219c6                 call    _simple_lock_try
F0010794: 90100010                 mov     %l0, %o0
F0010798: 80a22000                 cmp     %o0, 0
F001079C: 02bffff9                 be      loc_F0010780
F00107A0: 01000000                 nop
F00107A4: d0046134                 ld      [%l1+0x134], %o0
F00107A8: 80a22000                 cmp     %o0, 0
F00107AC: 02800023                 be      loc_F0010838
F00107B0: e404612c                 ld      [%l1+0x12C], %l2
F00107B4: 293c04d1                 sethi   -0xFECBC00, %l4
F00107B8: 90100011                 mov     %l1, %o0
F00107BC: 400179f1                 call    _pset_remove_task
F00107C0: 92100012                 mov     %l2, %o1
F00107C4: e004a00c                 ld      [%l2+0xC], %l0
F00107C8: d0052340                 ld      [%l4+0x340], %o0
F00107CC: 80a40008                 cmp     %l0, %o0
F00107D0: 02800016                 be      loc_F0010828
F00107D4: 80a40013                 cmp     %l0, %l3
F00107D8: 22800015                 be,a    loc_F001082C
F00107DC: d0046134                 ld      [%l1+0x134], %o0
F00107E0: e624a00c                 st      %l3, [%l2+0xC]
F00107E4: 4001ce77                 call    _vm_map_reference
F00107E8: 90100013                 mov     %l3, %o0
F00107EC: c0246158                 clr     [%l1+0x158]
F00107F0: d2042014                 ld      [%l0+0x14], %o1
F00107F4: 90100010                 mov     %l0, %o0
F00107F8: d4022018                 ld      [%o0+0x18], %o2
F00107FC: 4001d2d1                 call    _vm_map_remove
F0010800: a0046158                 add     %l1, 0x158, %l0
F0010804: d0040000                 ld      [%l0], %o0
F0010808: 80a22000                 cmp     %o0, 0
F001080C: 12bffffe                 bne     loc_F0010804
F0010810: 01000000                 nop
F0010814: 400219a5                 call    _simple_lock_try
F0010818: 90100010                 mov     %l0, %o0
F001081C: 80a22000                 cmp     %o0, 0
F0010820: 02bffff9                 be      loc_F0010804
F0010824: 01000000                 nop
F0010828: d0046134                 ld      [%l1+0x134], %o0
F001082C: 80a22000                 cmp     %o0, 0
F0010830: 12bfffe2                 bne     loc_F00107B8
F0010834: e404612c                 ld      [%l1+0x12C], %l2
F0010838: c0246158                 clr     [%l1+0x158]
F001083C: 81c7e008                 ret
F0010840: 81e80000                 restore
