F009F600: 9de3bf98                 save    %sp, -0x68, %sp
F009F604: 153c04f79412a270         set     _pmap_info, %o2
F009F60C: d002a094                 ld      [%o2+0x94], %o0
F009F610: 133c04f7                 sethi   %hi(_active_pmap), %o1
F009F614: d2026208                 ld      [%o1+%lo(_active_pmap)], %o1
F009F618: 90022001                 inc     %o0
F009F61C: 80a24018                 cmp     %o1, %i0
F009F620: 1280000a                 bne     loc_F009F648
F009F624: d022a094                 st      %o0, [%o2+0x94]
F009F628: d0062014                 ld      [%i0+0x14], %o0
F009F62C: 80a22000                 cmp     %o0, 0
F009F630: 22800007                 be,a    loc_F009F64C
F009F634: 133c04f7                 sethi   -0xFEC2400, %o1
F009F638: d0022008                 ld      [%o0+8], %o0
F009F63C: 80a20018                 cmp     %o0, %i0
F009F640: 02800038                 be      locret_F009F720
F009F644: 01000000                 nop
F009F648: 133c04f7                 sethi   -0xFEC2400, %o1
F009F64C: 92126270                 bset    0x270, %o1
F009F650: d0026098                 ld      [%o1+0x98], %o0
F009F654: a0062018                 add     %i0, 0x18, %l0
F009F658: 90022001                 inc     %o0
F009F65C: d0226098                 st      %o0, [%o1+0x98]
F009F660: d0040000                 ld      [%l0], %o0
F009F664: 80a22000                 cmp     %o0, 0
F009F668: 12bffffe                 bne     loc_F009F660
F009F66C: 01000000                 nop
F009F670: 7fffde0e                 call    _simple_lock_try
F009F674: 90100010                 mov     %l0, %o0
F009F678: 80a22000                 cmp     %o0, 0
F009F67C: 02bffff9                 be      loc_F009F660
F009F680: 113c04f0                 sethi   %hi(_kernel_pmap), %o0
F009F684: d0022100                 ld      [%o0+%lo(_kernel_pmap)], %o0
F009F688: 80a60008                 cmp     %i0, %o0
F009F68C: 02800008                 be      loc_F009F6AC
F009F690: 113c04f7                 sethi   -0xFEC2400, %o0
F009F694: d006600c                 ld      [%i1+0xC], %o0
F009F698: d002204c                 ld      [%o0+0x4C], %o0
F009F69C: 80a22000                 cmp     %o0, 0
F009F6A0: 02800007                 be      loc_F009F6BC
F009F6A4: 01000000                 nop
F009F6A8: 113c04f7                 sethi   -0xFEC2400, %o0
F009F6AC: d0022210                 ld      [%o0+0x210], %o0
F009F6B0: a0102000                 mov     0, %l0
F009F6B4: 10800012                 ba      loc_F009F6FC
F009F6B8: d0262014                 st      %o0, [%i0+0x14]
F009F6BC: 40000e78                 call    _pmap_alloc_context
F009F6C0: 90100018                 mov     %i0, %o0
F009F6C4: d2060000                 ld      [%i0], %o1
F009F6C8: a0100008                 mov     %o0, %l0
F009F6CC: d0026004                 ld      [%o1+4], %o0
F009F6D0: 153c04f6                 sethi   %hi(_contexts), %o2
F009F6D4: d20a600e                 ldub    [%o1+0xE], %o1
F009F6D8: 972c2002                 sll     %l0, 2, %o3
F009F6DC: d0022004                 ld      [%o0+4], %o0
F009F6E0: 932a600a                 sll     %o1, 10, %o1
F009F6E4: 90020009                 add     %o0, %o1, %o0
F009F6E8: 91322006                 srl     %o0, 6, %o0
F009F6EC: 912a2002                 sll     %o0, 2, %o0
F009F6F0: d202a1d8                 ld      [%o2+%lo(_contexts)], %o1
F009F6F4: 90122001                 bset    1, %o0
F009F6F8: d022400b                 st      %o0, [%o1+%o3]
F009F6FC: 7fffd7d8                 call    _mmu_flushctx
F009F700: 90100010                 mov     %l0, %o0
F009F704: 7fffd850                 call    _vac_ctxflush
F009F708: 90100010                 mov     %l0, %o0
F009F70C: 7fffd7cc                 call    _mmu_setctx
F009F710: 90100010                 mov     %l0, %o0
F009F714: 113c04f7                 sethi   %hi(_active_pmap), %o0
F009F718: f0222208                 st      %i0, [%o0+%lo(_active_pmap)]
F009F71C: c0262018                 clr     [%i0+0x18]
F009F720: 81c7e008                 ret
F009F724: 81e80000                 restore
