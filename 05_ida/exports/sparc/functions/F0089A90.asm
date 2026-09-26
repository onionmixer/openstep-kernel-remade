F0089A90: 9de3bf98                 save    %sp, -0x68, %sp
F0089A94: a2100018                 mov     %i0, %l1
F0089A98: f0046028                 ld      [%l1+0x28], %i0
F0089A9C: 113c04f0a0122230         set     _vm_page_queue_lock, %l0
F0089AA4: d0040000                 ld      [%l0], %o0
F0089AA8: 80a22000                 cmp     %o0, 0
F0089AAC: 12bffffe                 bne     loc_F0089AA4
F0089AB0: 01000000                 nop
F0089AB4: 400034fd                 call    _simple_lock_try
F0089AB8: 90100010                 mov     %l0, %o0
F0089ABC: 80a22000                 cmp     %o0, 0
F0089AC0: 02bffff9                 be      loc_F0089AA4
F0089AC4: 01000000                 nop
F0089AC8: d006601c                 ld      [%i1+0x1C], %o0
F0089ACC: 808a2400                 btst    0x400, %o0
F0089AD0: 2280000b                 be,a    loc_F0089AFC
F0089AD4: d0066020                 ld      [%i1+0x20], %o0
F0089AD8: 40005685                 call    _pmap_is_modified
F0089ADC: d0066024                 ld      [%i1+0x24], %o0
F0089AE0: 80a22000                 cmp     %o0, 0
F0089AE4: 32800006                 bne,a   loc_F0089AFC
F0089AE8: d0066020                 ld      [%i1+0x20], %o0
F0089AEC: 113c04f0                 sethi   %hi(_vm_page_queue_lock), %o0
F0089AF0: c0222230                 clr     [%o0+%lo(_vm_page_queue_lock)]
F0089AF4: 10800069                 ba      locret_F0089C98
F0089AF8: b0102000                 mov     0, %i0
F0089AFC: 80a22000                 cmp     %o0, 0
F0089B00: 3680001b                 bge,a   loc_F0089B6C
F0089B04: d0146044                 lduh    [%l1+0x44], %o0
F0089B08: 113c04f0                 sethi   %hi(_vm_page_queue_lock), %o0
F0089B0C: c0222230                 clr     [%o0+%lo(_vm_page_queue_lock)]
F0089B10: 90100019                 mov     %i1, %o0
F0089B14: 92102000                 mov     0, %o1
F0089B18: 94046010                 add     %l1, 0x10, %o2
F0089B1C: a010000a                 mov     %o2, %l0
F0089B20: d4022020                 ld      [%o0+0x20], %o2
F0089B24: 17100000                 sethi   0x40000000, %o3
F0089B28: 9412800b                 bset    %o3, %o2
F0089B2C: 7fff9c6a                 call    _assert_wait
F0089B30: d4222020                 st      %o2, [%o0+0x20]
F0089B34: c0246010                 clr     [%l1+0x10]
F0089B38: 7fffa2e2                 call    _thread_block
F0089B3C: 01000000                 nop
F0089B40: d0040000                 ld      [%l0], %o0
F0089B44: 80a22000                 cmp     %o0, 0
F0089B48: 12bffffe                 bne     loc_F0089B40
F0089B4C: 01000000                 nop
F0089B50: 400034d6                 call    _simple_lock_try
F0089B54: 90100010                 mov     %l0, %o0
F0089B58: 80a22000                 cmp     %o0, 0
F0089B5C: 02bffff9                 be      loc_F0089B40
F0089B60: 01000000                 nop
F0089B64: 1080004d                 ba      locret_F0089C98
F0089B68: b0102002                 mov     2, %i0
F0089B6C: 90022001                 inc     %o0
F0089B70: d0346044                 sth     %o0, [%l1+0x44]
F0089B74: d0066020                 ld      [%i1+0x20], %o0
F0089B78: 13200000                 sethi   0x80000000, %o1
F0089B7C: 90120009                 bset    %o1, %o0
F0089B80: d0266020                 st      %o0, [%i1+0x20]
F0089B84: d206601c                 ld      [%i1+0x1C], %o1
F0089B88: 11000020                 sethi   0x8000, %o0
F0089B8C: 808a4008                 btst    %o0, %o1
F0089B90: 02800004                 be      loc_F0089BA0
F0089B94: 01000000                 nop
F0089B98: 7fffff13                 call    _vm_page_activate
F0089B9C: 90100019                 mov     %i1, %o0
F0089BA0: 7ffffecf                 call    _vm_page_deactivate
F0089BA4: 90100019                 mov     %i1, %o0
F0089BA8: 40004f14                 call    _pmap_remove_all
F0089BAC: d0066024                 ld      [%i1+0x24], %o0
F0089BB0: 113c04f0                 sethi   %hi(_vm_page_queue_lock), %o0
F0089BB4: c0222230                 clr     [%o0+%lo(_vm_page_queue_lock)]
F0089BB8: 133c04f092126240         set     _vm_stat, %o1
F0089BC0: d0026020                 ld      [%o1+0x20], %o0
F0089BC4: 80a62000                 cmp     %i0, 0
F0089BC8: 90022001                 inc     %o0
F0089BCC: 12800007                 bne     loc_F0089BE8
F0089BD0: d0226020                 st      %o0, [%o1+0x20]
F0089BD4: d0146044                 lduh    [%l1+0x44], %o0
F0089BD8: b0102001                 mov     1, %i0
F0089BDC: 90023fff                 inc     -1, %o0
F0089BE0: 1080002e                 ba      locret_F0089C98
F0089BE4: d0346044                 sth     %o0, [%l1+0x44]
F0089BE8: c0246010                 clr     [%l1+0x10]
F0089BEC: 90100018                 mov     %i0, %o0
F0089BF0: 7ffff98f                 call    _vm_pager_put
F0089BF4: 92100019                 mov     %i1, %o1
F0089BF8: 80a00008                 cmp     %g0, %o0
F0089BFC: b0402000                 addc    %g0, 0, %i0
F0089C00: 90046010                 add     %l1, 0x10, %o0
F0089C04: a0100008                 mov     %o0, %l0
F0089C08: d0040000                 ld      [%l0], %o0
F0089C0C: 80a22000                 cmp     %o0, 0
F0089C10: 12bffffe                 bne     loc_F0089C08
F0089C14: 01000000                 nop
F0089C18: 400034a4                 call    _simple_lock_try
F0089C1C: 90100010                 mov     %l0, %o0
F0089C20: 80a22000                 cmp     %o0, 0
F0089C24: 02bffff9                 be      loc_F0089C08
F0089C28: 113c04f0                 sethi   %hi(_vm_page_queue_lock), %o0
F0089C2C: a0122230                 or      %o0, %lo(_vm_page_queue_lock), %l0
F0089C30: d0040000                 ld      [%l0], %o0
F0089C34: 80a22000                 cmp     %o0, 0
F0089C38: 12bffffe                 bne     loc_F0089C30
F0089C3C: 01000000                 nop
F0089C40: 4000349a                 call    _simple_lock_try
F0089C44: 90100010                 mov     %l0, %o0
F0089C48: 80a22000                 cmp     %o0, 0
F0089C4C: 02bffff9                 be      loc_F0089C30
F0089C50: 13200000                 sethi   0x80000000, %o1
F0089C54: d0066020                 ld      [%i1+0x20], %o0
F0089C58: 922a0009                 andn    %o0, %o1, %o1
F0089C5C: 11100000                 sethi   0x40000000, %o0
F0089C60: 808a4008                 btst    %o0, %o1
F0089C64: 02800008                 be      loc_F0089C84
F0089C68: d2266020                 st      %o1, [%i1+0x20]
F0089C6C: 902a4008                 andn    %o1, %o0, %o0
F0089C70: d0266020                 st      %o0, [%i1+0x20]
F0089C74: 90100019                 mov     %i1, %o0
F0089C78: 92102000                 mov     0, %o1
F0089C7C: 7fff9ce0                 call    _thread_wakeup_prim
F0089C80: 94102000                 mov     0, %o2
F0089C84: d0146044                 lduh    [%l1+0x44], %o0
F0089C88: 90023fff                 inc     -1, %o0
F0089C8C: d0346044                 sth     %o0, [%l1+0x44]
F0089C90: 113c04f0                 sethi   %hi(_vm_page_queue_lock), %o0
F0089C94: c0222230                 clr     [%o0+%lo(_vm_page_queue_lock)]
F0089C98: 81c7e008                 ret
F0089C9C: 81e80000                 restore
