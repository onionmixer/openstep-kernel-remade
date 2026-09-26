F006A070: 9de3bf98                 save    %sp, -0x68, %sp
F006A074: a6100018                 mov     %i0, %l3
F006A078: d004e010                 ld      [%l3+0x10], %o0
F006A07C: a4102000                 mov     0, %l2
F006A080: 80a48008                 cmp     %l2, %o0
F006A084: 1a80002f                 bcc     loc_F006A140
F006A088: a204e01c                 add     %l3, 0x1C, %l1
F006A08C: d0044000                 ld      [%l1], %o0
F006A090: 80a22001                 cmp     %o0, 1
F006A094: 32800026                 bne,a   loc_F006A12C
F006A098: d2046004                 ld      [%l1+4], %o1
F006A09C: 90046008                 add     %l1, 8, %o0! __s1
F006A0A0: 92100019                 mov     %i1, %o1! __s2
F006A0A4: 7ffe7911                 call    _strncmp
F006A0A8: 94102010                 mov     0x10, %o2! __n
F006A0AC: 80a22000                 cmp     %o0, 0
F006A0B0: 22800007                 be,a    loc_F006A0CC
F006A0B4: d0046030                 ld      [%l1+0x30], %o0
F006A0B8: d004e00c                 ld      [%l3+0xC], %o0
F006A0BC: 80a22001                 cmp     %o0, 1
F006A0C0: 3280001b                 bne,a   loc_F006A12C
F006A0C4: d2046004                 ld      [%l1+4], %o1
F006A0C8: d0046030                 ld      [%l1+0x30], %o0
F006A0CC: a0102000                 mov     0, %l0
F006A0D0: 80a40008                 cmp     %l0, %o0
F006A0D4: 1a800015                 bcc     loc_F006A128
F006A0D8: b0046038                 add     %l1, 0x38, %i0 ! '8'
F006A0DC: 90100018                 mov     %i0, %o0! __s1
F006A0E0: 9210001a                 mov     %i2, %o1! __s2
F006A0E4: 7ffe7901                 call    _strncmp
F006A0E8: 94102010                 mov     0x10, %o2! __n
F006A0EC: 80a22000                 cmp     %o0, 0
F006A0F0: 3280000a                 bne,a   loc_F006A118
F006A0F4: d0046030                 ld      [%l1+0x30], %o0
F006A0F8: 90062010                 add     %i0, 0x10, %o0! __s1
F006A0FC: 92100019                 mov     %i1, %o1! __s2
F006A100: 7ffe78fa                 call    _strncmp
F006A104: 94102010                 mov     0x10, %o2
F006A108: 80a22000                 cmp     %o0, 0
F006A10C: 0280000e                 be      locret_F006A144
F006A110: 01000000                 nop
F006A114: d0046030                 ld      [%l1+0x30], %o0
F006A118: a0042001                 inc     %l0
F006A11C: 80a40008                 cmp     %l0, %o0
F006A120: 0abfffef                 bcs     loc_F006A0DC
F006A124: b0062044                 inc     0x44, %i0 ! 'D'
F006A128: d2046004                 ld      [%l1+4], %o1
F006A12C: a404a001                 inc     %l2
F006A130: d004e010                 ld      [%l3+0x10], %o0
F006A134: 80a48008                 cmp     %l2, %o0
F006A138: 0abfffd5                 bcs     loc_F006A08C
F006A13C: a2044009                 add     %l1, %o1, %l1
F006A140: b0102000                 mov     0, %i0
F006A144: 81c7e008                 ret
F006A148: 81e80000                 restore
