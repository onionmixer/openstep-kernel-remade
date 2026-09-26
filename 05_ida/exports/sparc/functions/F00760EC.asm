F00760EC: 9de3bf90                 save    %sp, -0x70, %sp
F00760F0: 80a62000                 cmp     %i0, 0
F00760F4: 12800004                 bne     loc_F0076104
F00760F8: e007a05c                 ld      [%fp+arg_5C], %l0
F00760FC: 10800027                 ba      locret_F0076198
F0076100: b0102016                 mov     0x16, %i0
F0076104: 113c04f2b0122170         set     _stack_usage_lock, %i0
F007610C: d0060000                 ld      [%i0], %o0
F0076110: 80a22000                 cmp     %o0, 0
F0076114: 12bffffe                 bne     loc_F007610C
F0076118: 01000000                 nop
F007611C: 40008363                 call    _simple_lock_try
F0076120: 90100018                 mov     %i0, %o0
F0076124: 80a22000                 cmp     %o0, 0
F0076128: 02bffff9                 be      loc_F007610C
F007612C: 113c04f2                 sethi   %hi(_stack_usage_lock), %o0
F0076130: c0222170                 clr     [%o0+%lo(_stack_usage_lock)]
F0076134: 113c0442                 sethi   %hi(_stack_max_usage), %o0
F0076138: d2022294                 ld      [%o0+%lo(_stack_max_usage)], %o1
F007613C: 9007bff4                 add     %fp, var_C, %o0
F0076140: d227bff0                 st      %o1, [%fp+var_10]
F0076144: 7fffcaba                 call    _stack_statistics
F0076148: 9207bff0                 add     %fp, var_10, %o1
F007614C: c0264000                 clr     [%i1]
F0076150: d007bff4                 ld      [%fp+var_C], %o0
F0076154: d0268000                 st      %o0, [%i2]
F0076158: d207bff4                 ld      [%fp+var_C], %o1
F007615C: 912a600a                 sll     %o1, 10, %o0
F0076160: 90220009                 sub     %o0, %o1, %o0
F0076164: 912a2002                 sll     %o0, 2, %o0
F0076168: 90020009                 add     %o0, %o1, %o0
F007616C: 133c04d0                 sethi   %hi(_page_mask), %o1
F0076170: d20260d8                 ld      [%o1+%lo(_page_mask)], %o1
F0076174: 912a2002                 sll     %o0, 2, %o0
F0076178: 90020009                 add     %o0, %o1, %o0
F007617C: 922a0009                 andn    %o0, %o1, %o1
F0076180: d226c000                 st      %o1, [%i3]
F0076184: d2270000                 st      %o1, [%i4]
F0076188: d007bff0                 ld      [%fp+var_10], %o0
F007618C: b0102000                 mov     0, %i0
F0076190: d0274000                 st      %o0, [%i5]
F0076194: c0240000                 clr     [%l0]
F0076198: 81c7e008                 ret
F007619C: 81e80000                 restore
