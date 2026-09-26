F00730A8: 9de3bf98                 save    %sp, -0x68, %sp
F00730AC: 80a62000                 cmp     %i0, 0
F00730B0: 0280002b                 be      locret_F007315C
F00730B4: 01000000                 nop
F00730B8: d0060000                 ld      [%i0], %o0
F00730BC: 80a22000                 cmp     %o0, 0
F00730C0: 12bffffe                 bne     loc_F00730B8
F00730C4: 01000000                 nop
F00730C8: 40008f78                 call    _simple_lock_try
F00730CC: 90100018                 mov     %i0, %o0
F00730D0: 80a22000                 cmp     %o0, 0
F00730D4: 02bffff9                 be      loc_F00730B8
F00730D8: 01000000                 nop
F00730DC: d0062004                 ld      [%i0+4], %o0
F00730E0: c0260000                 clr     [%i0]
F00730E4: 90023fff                 inc     -1, %o0
F00730E8: 80a22000                 cmp     %o0, 0
F00730EC: 1280001c                 bne     locret_F007315C
F00730F0: d0262004                 st      %o0, [%i0+4]
F00730F4: e206202c                 ld      [%i0+0x2C], %l1
F00730F8: a0046158                 add     %l1, 0x158, %l0
F00730FC: d0040000                 ld      [%l0], %o0
F0073100: 80a22000                 cmp     %o0, 0
F0073104: 12bffffe                 bne     loc_F00730FC
F0073108: 01000000                 nop
F007310C: 40008f67                 call    _simple_lock_try
F0073110: 90100010                 mov     %l0, %o0
F0073114: 80a22000                 cmp     %o0, 0
F0073118: 02bffff9                 be      loc_F00730FC
F007311C: 90100011                 mov     %l1, %o0
F0073120: 7fffef98                 call    _pset_remove_task
F0073124: 92100018                 mov     %i0, %o1
F0073128: c0246158                 clr     [%l1+0x158]
F007312C: 7ffff003                 call    _pset_deallocate
F0073130: 90100011                 mov     %l1, %o0
F0073134: 40004436                 call    _vm_map_deallocate
F0073138: d006200c                 ld      [%i0+0xC], %o0
F007313C: 7fffab43                 call    _ipc_space_release
F0073140: d0062088                 ld      [%i0+0x88], %o0
F0073144: 7ffe6b04                 call    _utask_free
F0073148: d0062038                 ld      [%i0+0x38], %o0
F007314C: 113c04f2                 sethi   %hi(_task_zone), %o0
F0073150: d0022158                 ld      [%o0+%lo(_task_zone)], %o0
F0073154: 4000181f                 call    _zfree
F0073158: 92100018                 mov     %i0, %o1
F007315C: 81c7e008                 ret
F0073160: 81e80000                 restore
