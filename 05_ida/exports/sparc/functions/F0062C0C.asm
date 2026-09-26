F0062C0C: 9de3bf98                 save    %sp, -0x68, %sp
F0062C10: 98100019                 mov     %i1, %o4
F0062C14: 9210001a                 mov     %i2, %o1
F0062C18: 80a62000                 cmp     %i0, 0
F0062C1C: 12800004                 bne     loc_F0062C2C
F0062C20: 9410001b                 mov     %i3, %o2
F0062C24: 10800015                 ba      locret_F0062C78
F0062C28: b0102010                 mov     0x10, %i0
F0062C2C: 80a32000                 cmp     %o4, 0
F0062C30: 02800007                 be      loc_F0062C4C
F0062C34: 80a33fff                 cmp     %o4, -1
F0062C38: 02800005                 be      loc_F0062C4C
F0062C3C: 9002bff0                 add     %o2, -0x10, %o0
F0062C40: 80a22002                 cmp     %o0, 2
F0062C44: 08800004                 bleu    loc_F0062C54
F0062C48: 80a26000                 cmp     %o1, 0
F0062C4C: 1080000b                 ba      locret_F0062C78
F0062C50: b0102012                 mov     0x12, %i0
F0062C54: 02800004                 be      loc_F0062C64
F0062C58: 80a27fff                 cmp     %o1, -1
F0062C5C: 12800004                 bne     loc_F0062C6C
F0062C60: 90100018                 mov     %i0, %o0
F0062C64: 10800005                 ba      locret_F0062C78
F0062C68: b0102014                 mov     0x14, %i0
F0062C6C: 7fffdc70                 call    _ipc_object_copyout_name
F0062C70: 96102000                 mov     0, %o3
F0062C74: b0100008                 mov     %o0, %i0
F0062C78: 81c7e008                 ret
F0062C7C: 81e80000                 restore
