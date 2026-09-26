F0054E28: 9de3bf98                 save    %sp, -0x68, %sp
F0054E2C: 113c04d0                 sethi   %hi(_active_threads), %o0
F0054E30: e2022260                 ld      [%o0+%lo(_active_threads)], %l1
F0054E34: 92100018                 mov     %i0, %o1
F0054E38: b00460a4                 add     %l1, 0xA4, %i0
F0054E3C: d40460a4                 ld      [%l1+0xA4], %o2
F0054E40: 90100018                 mov     %i0, %o0
F0054E44: 80a0000a                 cmp     %g0, %o2
F0054E48: 7fffffc1                 call    _ipc_kmsg_enqueue
F0054E4C: a0603fff                 subc    %g0, -1, %l0
F0054E50: 80a42000                 cmp     %l0, 0
F0054E54: 02800019                 be      locret_F0054EB8
F0054E58: 01000000                 nop
F0054E5C: e00460a4                 ld      [%l1+0xA4], %l0
F0054E60: 80a42000                 cmp     %l0, 0
F0054E64: 02800015                 be      locret_F0054EB8
F0054E68: 01000000                 nop
F0054E6C: 4000006c                 call    _ipc_kmsg_clean
F0054E70: 90100010                 mov     %l0, %o0
F0054E74: 90100018                 mov     %i0, %o0
F0054E78: 7fffffd5                 call    _ipc_kmsg_rmqueue
F0054E7C: 92100010                 mov     %l0, %o1
F0054E80: d2042008                 ld      [%l0+8], %o1
F0054E84: 80a26000                 cmp     %o1, 0
F0054E88: 04800006                 ble     loc_F0054EA0
F0054E8C: 01000000                 nop
F0054E90: 40004cc4                 call    _kfree
F0054E94: 90100010                 mov     %l0, %o0
F0054E98: 10800005                 ba      loc_F0054EAC
F0054E9C: e0060000                 ld      [%i0], %l0
F0054EA0: 400000d8                 call    _ipc_kmsg_free
F0054EA4: 90100010                 mov     %l0, %o0
F0054EA8: e0060000                 ld      [%i0], %l0
F0054EAC: 80a42000                 cmp     %l0, 0
F0054EB0: 12bfffef                 bne     loc_F0054E6C
F0054EB4: 01000000                 nop
F0054EB8: 81c7e008                 ret
F0054EBC: 81e80000                 restore
