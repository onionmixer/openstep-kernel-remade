F00685B8: 9de3bf90                 save    %sp, -0x70, %sp
F00685BC: 113c04d1                 sethi   %hi(_kernel_map), %o0
F00685C0: d0022340                 ld      [%o0+%lo(_kernel_map)], %o0
F00685C4: 253c04bd                 sethi   %hi(dword_F012F678), %l2
F00685C8: d404a278                 ld      [%l2+%lo(dword_F012F678)], %o2
F00685CC: 40006c8e                 call    _kmem_alloc_wired
F00685D0: 9207bff4                 add     %fp, var_C, %o1
F00685D4: 80a22000                 cmp     %o0, 0
F00685D8: 1280002d                 bne     locret_F006868C
F00685DC: b0102000                 mov     0, %i0
F00685E0: 153c04f0                 sethi   %hi(_stackStats), %o2
F00685E4: d002a0c0                 ld      [%o2+%lo(_stackStats)], %o0
F00685E8: 92102002                 mov     2, %o1
F00685EC: 90022001                 inc     %o0
F00685F0: d022a0c0                 st      %o0, [%o2+%lo(_stackStats)]
F00685F4: d007bff4                 ld      [%fp+var_C], %o0
F00685F8: 9412a0c0                 bset    %lo(_stackStats), %o2
F00685FC: d2222008                 st      %o1, [%o0+8]
F0068600: d202a004                 ld      [%o2+4], %o1
F0068604: 9002200c                 inc     0xC, %o0
F0068608: 92026001                 inc     %o1
F006860C: 4000368c                 call    _stack_init
F0068610: d222a004                 st      %o1, [%o2+4]
F0068614: 233c04bd                 sethi   %hi(dword_F012F67C), %l1
F0068618: d004627c                 ld      [%l1+%lo(dword_F012F67C)], %o0
F006861C: 80a22001                 cmp     %o0, 1
F0068620: 2480001a                 ble,a   loc_F0068688
F0068624: f007bff4                 ld      [%fp+var_C], %i0
F0068628: 113c04f0                 sethi   %hi(_stack_queue_lock), %o0
F006862C: 400001e6                 call    _lock_write
F0068630: 901220e0                 bset    %lo(_stack_queue_lock), %o0
F0068634: d407bff4                 ld      [%fp+var_C], %o2
F0068638: d204a278                 ld      [%l2+0x278], %o1
F006863C: a0102001                 mov     1, %l0
F0068640: d004627c                 ld      [%l1+%lo(dword_F012F67C)], %o0
F0068644: 80a40008                 cmp     %l0, %o0
F0068648: 1680000c                 bge     loc_F0068678
F006864C: b0028009                 add     %o2, %o1, %i0
F0068650: 4000367b                 call    _stack_init
F0068654: 9006200c                 add     %i0, 0xC, %o0
F0068658: 7fffff4b                 call    sub_F0068384
F006865C: 90100018                 mov     %i0, %o0
F0068660: d204a278                 ld      [%l2+0x278], %o1
F0068664: a0042001                 inc     %l0
F0068668: d004627c                 ld      [%l1+0x27C], %o0
F006866C: 80a40008                 cmp     %l0, %o0
F0068670: 06bffff8                 bl      loc_F0068650
F0068674: b0060009                 add     %i0, %o1, %i0
F0068678: 113c04f0                 sethi   %hi(_stack_queue_lock), %o0
F006867C: 4000026e                 call    _lock_done
F0068680: 901220e0                 bset    %lo(_stack_queue_lock), %o0
F0068684: f007bff4                 ld      [%fp+var_C], %i0
F0068688: b006200c                 inc     0xC, %i0
F006868C: 81c7e008                 ret
F0068690: 81e80000                 restore
