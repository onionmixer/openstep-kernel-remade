F0043E08: 9de3bf98                 save    %sp, -0x68, %sp
F0043E0C: 90100018                 mov     %i0, %o0! XDR *
F0043E10: 4000064e                 call    _xdr_enum
F0043E14: 92100019                 mov     %i1, %o1
F0043E18: 80a22000                 cmp     %o0, 0
F0043E1C: 12800004                 bne     loc_F0043E2C
F0043E20: 90100018                 mov     %i0, %o0! XDR *
F0043E24: 10800007                 ba      locret_F0043E40
F0043E28: b0102000                 mov     0, %i0
F0043E2C: 92066004                 add     %i1, 4, %o1! char **
F0043E30: 94066008                 add     %i1, 8, %o2! unsigned int *
F0043E34: 40000689                 call    _xdr_bytes
F0043E38: 96102190                 mov     0x190, %o3
F0043E3C: b0100008                 mov     %o0, %i0
F0043E40: 81c7e008                 ret
F0043E44: 81e80000                 restore
