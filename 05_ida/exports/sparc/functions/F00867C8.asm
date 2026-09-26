F00867C8: 9de3bf98                 save    %sp, -0x68, %sp
F00867CC: 90100019                 mov     %i1, %o0! __dst
F00867D0: 133c04f692126040         set     _vm_object_template, %o1! __src
F00867D8: 7ffe02b2                 call    _memcpy
F00867DC: 94102058                 mov     0x58, %o2 ! 'X'
F00867E0: f2266004                 st      %i1, [%i1+4]
F00867E4: f2264000                 st      %i1, [%i1]
F00867E8: c0266010                 clr     [%i1+0x10]
F00867EC: f0266014                 st      %i0, [%i1+0x14]
F00867F0: 113c04f6b0122038         set     _vm_object_list_lock, %i0
F00867F8: d0060000                 ld      [%i0], %o0
F00867FC: 80a22000                 cmp     %o0, 0
F0086800: 12bffffe                 bne     loc_F00867F8
F0086804: 01000000                 nop
F0086808: 400041a8                 call    _simple_lock_try
F008680C: 90100018                 mov     %i0, %o0
F0086810: 80a22000                 cmp     %o0, 0
F0086814: 02bffff9                 be      loc_F00867F8
F0086818: 113c04f6                 sethi   %hi(dword_F013D834), %o0
F008681C: d2022034                 ld      [%o0+%lo(dword_F013D834)], %o1
F0086820: 94122034                 or      %o0, %lo(dword_F013D834), %o2
F0086824: 9002bffc                 add     %o2, -4, %o0
F0086828: 80a24008                 cmp     %o1, %o0
F008682C: 32800003                 bne,a   loc_F0086838
F0086830: f2226008                 st      %i1, [%o1+8]
F0086834: f222bffc                 st      %i1, [%o2-4]
F0086838: d226600c                 st      %o1, [%i1+0xC]
F008683C: 113c04f690122030         set     _vm_object_list, %o0
F0086844: d0266008                 st      %o0, [%i1+8]
F0086848: f2222004                 st      %i1, [%o0+4]
F008684C: 153c04f5                 sethi   %hi(_vm_object_count), %o2
F0086850: d002a020                 ld      [%o2+%lo(_vm_object_count)], %o0
F0086854: 133c04f6                 sethi   %hi(_vm_object_list_lock), %o1
F0086858: c0226038                 clr     [%o1+%lo(_vm_object_list_lock)]
F008685C: 90022001                 inc     %o0
F0086860: d022a020                 st      %o0, [%o2+%lo(_vm_object_count)]
F0086864: 81c7e008                 ret
F0086868: 81e80000                 restore
