F005B660: 9de3bf90                 save    %sp, -0x70, %sp
F005B664: 90100018                 mov     %i0, %o0
F005B668: 92102001                 mov     1, %o1
F005B66C: 15000200                 sethi   0x80000, %o2
F005B670: 96102000                 mov     0, %o3
F005B674: 98100019                 mov     %i1, %o4
F005B678: 7ffff897                 call    _ipc_object_alloc_name
F005B67C: 9a07bff4                 add     %fp, var_C, %o5
F005B680: 80a22000                 cmp     %o0, 0
F005B684: 12800009                 bne     locret_F005B6A8
F005B688: b0100008                 mov     %o0, %i0
F005B68C: d007bff4                 ld      [%fp+var_C], %o0
F005B690: f222200c                 st      %i1, [%o0+0xC]
F005B694: 7ffff339                 call    _ipc_mqueue_init
F005B698: 90022010                 inc     0x10, %o0
F005B69C: d007bff4                 ld      [%fp+var_C], %o0
F005B6A0: b0102000                 mov     0, %i0
F005B6A4: d0268000                 st      %o0, [%i2]
F005B6A8: 81c7e008                 ret
F005B6AC: 81e80000                 restore
