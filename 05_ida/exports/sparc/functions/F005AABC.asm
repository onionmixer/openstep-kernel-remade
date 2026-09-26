F005AABC: 9de3bf90                 save    %sp, -0x70, %sp
F005AAC0: 90100018                 mov     %i0, %o0
F005AAC4: 92102000                 mov     0, %o1
F005AAC8: 15000080                 sethi   0x20000, %o2
F005AACC: 96102000                 mov     0, %o3
F005AAD0: 98100019                 mov     %i1, %o4
F005AAD4: 7ffffb80                 call    _ipc_object_alloc_name
F005AAD8: 9a07bff4                 add     %fp, var_C, %o5
F005AADC: 80a22000                 cmp     %o0, 0
F005AAE0: 32800009                 bne,a   locret_F005AB04
F005AAE4: b0100008                 mov     %o0, %i0
F005AAE8: 92100018                 mov     %i0, %o1
F005AAEC: d007bff4                 ld      [%fp+var_C], %o0
F005AAF0: 7fffffca                 call    _ipc_port_init
F005AAF4: 94100019                 mov     %i1, %o2
F005AAF8: d007bff4                 ld      [%fp+var_C], %o0
F005AAFC: b0102000                 mov     0, %i0
F005AB00: d0268000                 st      %o0, [%i2]
F005AB04: 81c7e008                 ret
F005AB08: 81e80000                 restore
