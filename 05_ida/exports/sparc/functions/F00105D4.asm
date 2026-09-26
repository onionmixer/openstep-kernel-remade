F00105D4: 9de3bf98                 save    %sp, -0x68, %sp
F00105D8: 4000009b                 call    _proc_shutdown
F00105DC: 01000000                 nop
F00105E0: 40000031                 call    _kill_tasks
F00105E4: 01000000                 nop
F00105E8: 40017157                 call    _mfs_cache_clear
F00105EC: 01000000                 nop
F00105F0: 4001dbf0                 call    _vm_object_cache_clear
F00105F4: 01000000                 nop
F00105F8: 40000159                 call    _fd_shutdown
F00105FC: 01000000                 nop
F0010600: 4001da41                 call    _vm_object_shutdown
F0010604: 01000000                 nop
F0010608: 4001ed32                 call    _vnode_pager_shutdown
F001060C: 01000000                 nop
F0010610: 113c04d4                 sethi   %hi(_rootvfs), %o0
F0010614: d0022160                 ld      [%o0+%lo(_rootvfs)], %o0
F0010618: e0020000                 ld      [%o0], %l0
F001061C: 80a42000                 cmp     %l0, 0
F0010620: 22800015                 be,a    loc_F0010674
F0010624: 113c04d4                 sethi   -0xFECB000, %o0
F0010628: 293c042c                 sethi   %hi(aUnmountingS), %l4! "unmounting %s ... "
F001062C: 273c042c                 sethi   -0xFEF5000, %l3
F0010630: 253c042c                 sethi   -0xFEF5000, %l2
F0010634: 901521e0                 or      %l4, %lo(aUnmountingS), %o0! "unmounting %s ... "
F0010638: 40001008                 call    _printf
F001063C: 92042020                 add     %l0, 0x20, %o1 ! ' '
F0010640: e2040000                 ld      [%l0], %l1
F0010644: 40004d88                 call    _dounmount
F0010648: 90100010                 mov     %l0, %o0
F001064C: 80a22000                 cmp     %o0, 0
F0010650: 12800003                 bne     loc_F001065C
F0010654: 9014e1f8                 or      %l3, 0x1F8, %o0
F0010658: 9014a200                 or      %l2, 0x200, %o0! char *
F001065C: 40000fff                 call    _printf
F0010660: a0100011                 mov     %l1, %l0
F0010664: 80a42000                 cmp     %l0, 0
F0010668: 32bffff4                 bne,a   loc_F0010638
F001066C: 901521e0                 or      %l4, 0x1E0, %o0
F0010670: 113c04d4                 sethi   -0xFECB000, %o0
F0010674: 4000613c                 call    _vn_rele
F0010678: d0022158                 ld      [%o0+0x158], %o0
F001067C: 113c04d4                 sethi   %hi(_rootvfs), %o0
F0010680: 40004d79                 call    _dounmount
F0010684: d0022160                 ld      [%o0+%lo(_rootvfs)], %o0
F0010688: 80a22000                 cmp     %o0, 0
F001068C: 02800004                 be      locret_F001069C
F0010690: 113c042c                 sethi   %hi(aRootUnmountFai), %o0! "Root unmount FAILED\n"
F0010694: 40000ff1                 call    _printf
F0010698: 90122208                 bset    %lo(aRootUnmountFai), %o0! "Root unmount FAILED\n"
F001069C: 81c7e008                 ret
F00106A0: 81e80000                 restore
