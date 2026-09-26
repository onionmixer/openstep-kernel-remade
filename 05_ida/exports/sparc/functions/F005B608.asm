F005B608: 9de3bf90                 save    %sp, -0x70, %sp
F005B60C: 90100018                 mov     %i0, %o0
F005B610: 92102001                 mov     1, %o1
F005B614: 15000200                 sethi   0x80000, %o2
F005B618: 96102000                 mov     0, %o3
F005B61C: 9807bff4                 add     %fp, var_10+4, %o4
F005B620: 7ffff87e                 call    _ipc_object_alloc
F005B624: 9a07bff0                 add     %fp, var_10, %o5
F005B628: 80a22000                 cmp     %o0, 0
F005B62C: 1280000b                 bne     locret_F005B658
F005B630: b0100008                 mov     %o0, %i0
F005B634: d01fbff0                 ldd     [%fp+var_10], %o0
F005B638: d222200c                 st      %o1, [%o0+0xC]
F005B63C: 7ffff34f                 call    _ipc_mqueue_init
F005B640: 90022010                 inc     0x10, %o0
F005B644: d007bff4                 ld      [%fp+var_10+4], %o0
F005B648: d0264000                 st      %o0, [%i1]
F005B64C: d007bff0                 ld      [%fp+var_10], %o0
F005B650: b0102000                 mov     0, %i0
F005B654: d0268000                 st      %o0, [%i2]
F005B658: 81c7e008                 ret
F005B65C: 81e80000                 restore
