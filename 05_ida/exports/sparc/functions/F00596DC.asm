F00596DC: 9de3bf90                 save    %sp, -0x70, %sp
F00596E0: 90100018                 mov     %i0, %o0
F00596E4: 92100019                 mov     %i1, %o1
F00596E8: 400008e5                 call    _ipc_right_lookup_write
F00596EC: 9407bff4                 add     %fp, var_C, %o2
F00596F0: 80a22000                 cmp     %o0, 0
F00596F4: 22800004                 be,a    loc_F0059704
F00596F8: 9006a010                 add     %i2, 0x10, %o0
F00596FC: 10800018                 ba      locret_F005975C
F0059700: b0100008                 mov     %o0, %i0
F0059704: d607bff4                 ld      [%fp+var_C], %o3
F0059708: 92102001                 mov     1, %o1
F005970C: d402c000                 ld      [%o3], %o2
F0059710: 932a4008                 sll     %o1, %o0, %o1
F0059714: 808a8009                 btst    %o1, %o2
F0059718: 32800005                 bne,a   loc_F005972C
F005971C: f202e004                 ld      [%o3+4], %i1
F0059720: c0262008                 clr     [%i0+8]
F0059724: 1080000e                 ba      locret_F005975C
F0059728: b0102011                 mov     0x11, %i0
F005972C: d0064000                 ld      [%i1], %o0
F0059730: 80a22000                 cmp     %o0, 0
F0059734: 12bffffe                 bne     loc_F005972C
F0059738: 01000000                 nop
F005973C: 4000f5db                 call    _simple_lock_try
F0059740: 90100019                 mov     %i1, %o0
F0059744: 80a22000                 cmp     %o0, 0
F0059748: 02bffff9                 be      loc_F005972C
F005974C: 01000000                 nop
F0059750: c0262008                 clr     [%i0+8]
F0059754: f226c000                 st      %i1, [%i3]
F0059758: b0102000                 mov     0, %i0
F005975C: 81c7e008                 ret
F0059760: 81e80000                 restore
