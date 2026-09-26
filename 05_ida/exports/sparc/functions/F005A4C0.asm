F005A4C0: 9de3bf98                 save    %sp, -0x68, %sp
F005A4C4: 113c04efb0122318         set     _ipc_port_timestamp_lock_data, %i0
F005A4CC: d0060000                 ld      [%i0], %o0
F005A4D0: 80a22000                 cmp     %o0, 0
F005A4D4: 12bffffe                 bne     loc_F005A4CC
F005A4D8: 01000000                 nop
F005A4DC: 4000f273                 call    _simple_lock_try
F005A4E0: 90100018                 mov     %i0, %o0
F005A4E4: 80a22000                 cmp     %o0, 0
F005A4E8: 02bffff9                 be      loc_F005A4CC
F005A4EC: 133c04ef                 sethi   %hi(_ipc_port_timestamp_data), %o1
F005A4F0: f0026310                 ld      [%o1+%lo(_ipc_port_timestamp_data)], %i0
F005A4F4: 113c04ef                 sethi   %hi(_ipc_port_timestamp_lock_data), %o0
F005A4F8: c0222318                 clr     [%o0+%lo(_ipc_port_timestamp_lock_data)]
F005A4FC: 90062001                 add     %i0, 1, %o0
F005A500: d0226310                 st      %o0, [%o1+%lo(_ipc_port_timestamp_data)]
F005A504: 81c7e008                 ret
F005A508: 81e80000                 restore
