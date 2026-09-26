F005AB0C: 9de3bf90                 save    %sp, -0x70, %sp
F005AB10: 90100019                 mov     %i1, %o0
F005AB14: 9210001a                 mov     %i2, %o1
F005AB18: 400003d9                 call    _ipc_right_lookup_write
F005AB1C: 9407bff4                 add     %fp, var_C, %o2
F005AB20: 80a22000                 cmp     %o0, 0
F005AB24: 12800018                 bne     loc_F005AB84
F005AB28: d007bff4                 ld      [%fp+var_C], %o0
F005AB2C: d0022004                 ld      [%o0+4], %o0
F005AB30: 80a20018                 cmp     %o0, %i0
F005AB34: 1280000b                 bne     loc_F005AB60
F005AB38: 01000000                 nop
F005AB3C: 40000140                 call    _ipc_port_copy_send
F005AB40: d0066044                 ld      [%i1+0x44], %o0
F005AB44: b0100008                 mov     %o0, %i0
F005AB48: 90100019                 mov     %i1, %o0
F005AB4C: d407bff4                 ld      [%fp+var_C], %o2
F005AB50: 4000059a                 call    _ipc_right_destroy
F005AB54: 9210001a                 mov     %i2, %o1
F005AB58: 10800005                 ba      loc_F005AB6C
F005AB5C: 80a62000                 cmp     %i0, 0
F005AB60: c0266008                 clr     [%i1+8]
F005AB64: b0102000                 mov     0, %i0
F005AB68: 80a62000                 cmp     %i0, 0
F005AB6C: 02800006                 be      loc_F005AB84
F005AB70: 80a63fff                 cmp     %i0, -1
F005AB74: 02800004                 be      loc_F005AB84
F005AB78: 90100018                 mov     %i0, %o0
F005AB7C: 7ffffa20                 call    _ipc_notify_port_deleted_compat
F005AB80: 9210001a                 mov     %i2, %o1
F005AB84: 40000cb1                 call    _ipc_space_release
F005AB88: 90100019                 mov     %i1, %o0
F005AB8C: 81c7e008                 ret
F005AB90: 81e80000                 restore
