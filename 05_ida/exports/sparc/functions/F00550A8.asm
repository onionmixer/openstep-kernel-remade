F00550A8: 9de3bf98                 save    %sp, -0x68, %sp
F00550AC: e0062014                 ld      [%i0+0x14], %l0
F00550B0: d006201c                 ld      [%i0+0x1C], %o0
F00550B4: 400012fa                 call    _ipc_object_destroy
F00550B8: 920c20ff                 and     %l0, 0xFF, %o1
F00550BC: d0062020                 ld      [%i0+0x20], %o0
F00550C0: 80a22000                 cmp     %o0, 0
F00550C4: 02800008                 be      loc_F00550E4
F00550C8: 80a23fff                 cmp     %o0, -1
F00550CC: 02800006                 be      loc_F00550E4
F00550D0: 1300003f                 sethi   0xFC00, %o1
F00550D4: 92126300                 bset    0x300, %o1
F00550D8: 920c0009                 and     %l0, %o1, %o1
F00550DC: 400012f0                 call    _ipc_object_destroy
F00550E0: 93326008                 srl     %o1, 8, %o1
F00550E4: 9006202c                 add     %i0, 0x2C, %o0 ! ','
F00550E8: 7fffff76                 call    _ipc_kmsg_clean_body
F00550EC: 92100019                 mov     %i1, %o1
F00550F0: 80a6a000                 cmp     %i2, 0
F00550F4: 02800041                 be      locret_F00551F8
F00550F8: 01000000                 nop
F00550FC: d0064000                 ld      [%i1], %o0
F0055100: a9322003                 srl     %o0, 3, %l4
F0055104: 808a2004                 btst    4, %o0
F0055108: 02800007                 be      loc_F0055124
F005510C: a80d2001                 and     %l4, 1, %l4
F0055110: e4166004                 lduh    [%i1+4], %l2
F0055114: d2166006                 lduh    [%i1+6], %o1
F0055118: d0066008                 ld      [%i1+8], %o0
F005511C: 10800008                 ba      loc_F005513C
F0055120: b206600c                 inc     0xC, %i1
F0055124: e40e4000                 ldub    [%i1], %l2
F0055128: 93322010                 srl     %o0, 16, %o1
F005512C: 920a60ff                 and     %o1, 0xFF, %o1
F0055130: 91322004                 srl     %o0, 4, %o0
F0055134: 900a2fff                 and     %o0, 0xFFF, %o0
F0055138: b2066004                 inc     4, %i1
F005513C: 7ffec4f1                 call    _umul
F0055140: a204bff0                 add     %l2, -0x10, %l1
F0055144: 80a46005                 cmp     %l1, 5
F0055148: 28800003                 bleu,a  loc_F0055154
F005514C: a2102001                 mov     1, %l1
F0055150: a2102000                 mov     0, %l1
F0055154: 80a46000                 cmp     %l1, 0
F0055158: 90022007                 inc     7, %o0
F005515C: 02800018                 be      loc_F00551BC
F0055160: a7322003                 srl     %o0, 3, %l3
F0055164: 80a52000                 cmp     %l4, 0
F0055168: 12800003                 bne     loc_F0055174
F005516C: a0100019                 mov     %i1, %l0
F0055170: e0064000                 ld      [%i1], %l0
F0055174: b0102000                 mov     0, %i0
F0055178: 80a6001b                 cmp     %i0, %i3
F005517C: 1a800011                 bcc     loc_F00551C0
F0055180: 80a52000                 cmp     %l4, 0
F0055184: b4102000                 mov     0, %i2
F0055188: d0068010                 ld      [%i2+%l0], %o0
F005518C: 80a22000                 cmp     %o0, 0
F0055190: 22800008                 be,a    loc_F00551B0
F0055194: b0062001                 inc     %i0
F0055198: 80a23fff                 cmp     %o0, -1
F005519C: 22800005                 be,a    loc_F00551B0
F00551A0: b0062001                 inc     %i0
F00551A4: 400012be                 call    _ipc_object_destroy
F00551A8: 92100012                 mov     %l2, %o1
F00551AC: b0062001                 inc     %i0
F00551B0: 80a6001b                 cmp     %i0, %i3
F00551B4: 0abffff5                 bcs     loc_F0055188
F00551B8: b406a004                 inc     4, %i2
F00551BC: 80a52000                 cmp     %l4, 0
F00551C0: 1280000e                 bne     locret_F00551F8
F00551C4: 80a4e000                 cmp     %l3, 0
F00551C8: 0280000c                 be      locret_F00551F8
F00551CC: d2064000                 ld      [%i1], %o1
F00551D0: 80a46000                 cmp     %l1, 0
F00551D4: 02800005                 be      loc_F00551E8
F00551D8: 90100009                 mov     %o1, %o0
F00551DC: 40004bf1                 call    _kfree
F00551E0: 92100013                 mov     %l3, %o1! address
F00551E4: 30800005                 ba,a    locret_F00551F8
F00551E8: 113c04ef                 sethi   %hi(_ipc_soft_map), %o0
F00551EC: d0022320                 ld      [%o0+%lo(_ipc_soft_map)], %o0! target_task
F00551F0: 4000d5ac                 call    _vm_deallocate
F00551F4: 94100013                 mov     %l3, %o2
F00551F8: 81c7e008                 ret
F00551FC: 81e80000                 restore
