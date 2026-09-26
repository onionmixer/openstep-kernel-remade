F0024FFC: 9de3bf98                 save    %sp, -0x68, %sp
F0025000: 4001c6ee                 call    _spltty
F0025004: b0102000                 mov     0, %i0
F0025008: 133c04cf92126268         set     unk_F0133E68, %o1
F0025010: 94027f78                 add     %o1, -0x88, %o2
F0025014: 80a2400a                 cmp     %o1, %o2
F0025018: 0880000e                 bleu    loc_F0025050
F002501C: 9610000a                 mov     %o2, %o3
F0025020: d402600c                 ld      [%o1+0xC], %o2
F0025024: 80a28009                 cmp     %o2, %o1
F0025028: 22800007                 be,a    loc_F0025044
F002502C: 92027fbc                 inc     -0x44, %o1
F0025030: d402a00c                 ld      [%o2+0xC], %o2
F0025034: 80a28009                 cmp     %o2, %o1
F0025038: 12bffffe                 bne     loc_F0025030
F002503C: b0062001                 inc     %i0
F0025040: 92027fbc                 inc     -0x44, %o1
F0025044: 80a2400b                 cmp     %o1, %o3
F0025048: 38bffff7                 bgu,a   loc_F0025024
F002504C: d402600c                 ld      [%o1+0xC], %o2
F0025050: 4001c735                 call    _splx
F0025054: 01000000                 nop
F0025058: 81c7e008                 ret
F002505C: 81e80000                 restore
