F005501C: 9de3bf98                 save    %sp, -0x68, %sp
F0055020: d006200c                 ld      [%i0+0xC], %o0
F0055024: 80a22000                 cmp     %o0, 0
F0055028: 02800004                 be      loc_F0055038
F005502C: e0062014                 ld      [%i0+0x14], %l0
F0055030: 40000c43                 call    _ipc_marequest_destroy
F0055034: 01000000                 nop
F0055038: d006201c                 ld      [%i0+0x1C], %o0
F005503C: 80a22000                 cmp     %o0, 0
F0055040: 02800006                 be      loc_F0055058
F0055044: 80a23fff                 cmp     %o0, -1
F0055048: 22800005                 be,a    loc_F005505C
F005504C: d0062020                 ld      [%i0+0x20], %o0
F0055050: 40001313                 call    _ipc_object_destroy
F0055054: 920c20ff                 and     %l0, 0xFF, %o1
F0055058: d0062020                 ld      [%i0+0x20], %o0
F005505C: 80a22000                 cmp     %o0, 0
F0055060: 02800009                 be      loc_F0055084
F0055064: 80a23fff                 cmp     %o0, -1
F0055068: 02800008                 be      loc_F0055088
F005506C: 80a42000                 cmp     %l0, 0
F0055070: 1300003f92126300         set     0xFF00, %o1
F0055078: 920c0009                 and     %l0, %o1, %o1
F005507C: 40001308                 call    _ipc_object_destroy
F0055080: 93326008                 srl     %o1, 8, %o1
F0055084: 80a42000                 cmp     %l0, 0
F0055088: 16800006                 bge     locret_F00550A0
F005508C: 9006202c                 add     %i0, 0x2C, %o0 ! ','
F0055090: d2062018                 ld      [%i0+0x18], %o1
F0055094: 92026014                 inc     0x14, %o1
F0055098: 7fffff8a                 call    _ipc_kmsg_clean_body
F005509C: 92060009                 add     %i0, %o1, %o1
F00550A0: 81c7e008                 ret
F00550A4: 81e80000                 restore
