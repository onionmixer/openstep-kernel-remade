F009C89C: 9de3bf98                 save    %sp, -0x68, %sp
F009C8A0: 133c04f792126270         set     _pmap_info, %o1
F009C8A8: d0026040                 ld      [%o1+0x40], %o0
F009C8AC: 90022001                 inc     %o0
F009C8B0: 40000cbc                 call    _pmap_print_info
F009C8B4: d0226040                 st      %o0, [%o1+0x40]
F009C8B8: 80a62000                 cmp     %i0, 0
F009C8BC: 02800021                 be      locret_F009C940
F009C8C0: 113c04f0                 sethi   %hi(_kernel_pmap), %o0
F009C8C4: d0022100                 ld      [%o0+%lo(_kernel_pmap)], %o0
F009C8C8: 80a60008                 cmp     %i0, %o0
F009C8CC: 0280001d                 be      locret_F009C940
F009C8D0: 01000000                 nop
F009C8D4: 7fffe90a                 call    _splvm
F009C8D8: a0062018                 add     %i0, 0x18, %l0
F009C8DC: a2100008                 mov     %o0, %l1
F009C8E0: d0040000                 ld      [%l0], %o0
F009C8E4: 80a22000                 cmp     %o0, 0
F009C8E8: 12bffffe                 bne     loc_F009C8E0
F009C8EC: 01000000                 nop
F009C8F0: 7fffe96e                 call    _simple_lock_try
F009C8F4: 90100010                 mov     %l0, %o0
F009C8F8: 80a22000                 cmp     %o0, 0
F009C8FC: 02bffff9                 be      loc_F009C8E0
F009C900: 01000000                 nop
F009C904: c0262018                 clr     [%i0+0x18]
F009C908: e006201c                 ld      [%i0+0x1C], %l0
F009C90C: 90100011                 mov     %l1, %o0
F009C910: a0043fff                 inc     -1, %l0
F009C914: 7fffe904                 call    _splx
F009C918: e026201c                 st      %l0, [%i0+0x1C]
F009C91C: 80a42000                 cmp     %l0, 0
F009C920: 12800008                 bne     locret_F009C940
F009C924: 01000000                 nop
F009C928: 400016c7                 call    _pmap_dealloc_reg_entry
F009C92C: 90100018                 mov     %i0, %o0
F009C930: 113c04f7                 sethi   %hi(_pmap_zone), %o0
F009C934: d0022378                 ld      [%o0+%lo(_pmap_zone)], %o0
F009C938: 7fff7226                 call    _zfree
F009C93C: 92100018                 mov     %i0, %o1
F009C940: 81c7e008                 ret
F009C944: 81e80000                 restore
