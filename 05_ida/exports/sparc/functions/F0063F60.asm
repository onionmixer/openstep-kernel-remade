F0063F60: 9de3bf98                 save    %sp, -0x68, %sp
F0063F64: 113c04d0                 sethi   %hi(_active_threads), %o0
F0063F68: e6022260                 ld      [%o0+%lo(_active_threads)], %l3
F0063F6C: e404e00c                 ld      [%l3+0xC], %l2
F0063F70: a004a064                 add     %l2, 0x64, %l0 ! 'd'
F0063F74: d0040000                 ld      [%l0], %o0
F0063F78: 80a22000                 cmp     %o0, 0
F0063F7C: 12bffffe                 bne     loc_F0063F74
F0063F80: 01000000                 nop
F0063F84: 4000cbc9                 call    _simple_lock_try
F0063F88: 90100010                 mov     %l0, %o0
F0063F8C: 80a22000                 cmp     %o0, 0
F0063F90: 02bffff9                 be      loc_F0063F74
F0063F94: 01000000                 nop
F0063F98: e204a070                 ld      [%l2+0x70], %l1
F0063F9C: 80a46000                 cmp     %l1, 0
F0063FA0: 02800004                 be      loc_F0063FB0
F0063FA4: 80a47fff                 cmp     %l1, -1
F0063FA8: 12800005                 bne     loc_F0063FBC
F0063FAC: 01000000                 nop
F0063FB0: c024a064                 clr     [%l2+0x64]
F0063FB4: 40000028                 call    _exception_no_server
F0063FB8: 9e03e090                 inc     0x90, %o7
F0063FBC: d0044000                 ld      [%l1], %o0
F0063FC0: 80a22000                 cmp     %o0, 0
F0063FC4: 12bffffe                 bne     loc_F0063FBC
F0063FC8: 01000000                 nop
F0063FCC: 4000cbb7                 call    _simple_lock_try
F0063FD0: 90100011                 mov     %l1, %o0
F0063FD4: 80a22000                 cmp     %o0, 0
F0063FD8: 02bffff9                 be      loc_F0063FBC
F0063FDC: 01000000                 nop
F0063FE0: c024a064                 clr     [%l2+0x64]
F0063FE4: d0046008                 ld      [%l1+8], %o0
F0063FE8: 80a22000                 cmp     %o0, 0
F0063FEC: 26800005                 bl,a    loc_F0064000
F0063FF0: d0046004                 ld      [%l1+4], %o0
F0063FF4: c0244000                 clr     [%l1]
F0063FF8: 40000017                 call    _exception_no_server
F0063FFC: 9e03e04c                 inc     0x4C, %o7 ! 'L'
F0064000: 90022001                 inc     %o0
F0064004: d0246004                 st      %o0, [%l1+4]
F0064008: d004601c                 ld      [%l1+0x1C], %o0
F006400C: 90022001                 inc     %o0
F0064010: d024601c                 st      %o0, [%l1+0x1C]
F0064014: c0244000                 clr     [%l1]
F0064018: c024e0c8                 clr     [%l3+0xC8]
F006401C: 40000c22                 call    _retrieve_thread_self_fast
F0064020: 90100013                 mov     %l3, %o0
F0064024: a0100008                 mov     %o0, %l0
F0064028: 40000bf7                 call    _retrieve_task_self_fast
F006402C: 90100012                 mov     %l2, %o0
F0064030: 94100008                 mov     %o0, %o2! task
F0064034: 90100011                 mov     %l1, %o0! exception_port
F0064038: 92100010                 mov     %l0, %o1! thread
F006403C: 96100018                 mov     %i0, %o3! exception
F0064040: 98100019                 mov     %i1, %o4! code
F0064044: 40000014                 call    _exception_raise
F0064048: 9a10001a                 mov     %i2, %o5
F006404C: 81c7e008                 ret
F0064050: 81e80000                 restore
