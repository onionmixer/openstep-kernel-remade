F005708C: 9de3bf90                 save    %sp, -0x70, %sp
F0057090: 90100019                 mov     %i1, %o0
F0057094: 9607bff4                 add     %fp, var_C, %o3
F0057098: e2062014                 ld      [%i0+0x14], %l1
F005709C: 2100003f                 sethi   0xFC00, %l0
F00570A0: d206201c                 ld      [%i0+0x1C], %o1
F00570A4: a0142300                 bset    0x300, %l0
F00570A8: e4062020                 ld      [%i0+0x20], %l2
F00570AC: 940c60ff                 and     %l1, 0xFF, %o2
F00570B0: a00c4010                 and     %l1, %l0, %l0
F00570B4: 7ffffef7                 call    _ipc_kmsg_copyout_object
F00570B8: a1342008                 srl     %l0, 8, %l0
F00570BC: a6100008                 mov     %o0, %l3
F00570C0: 90100019                 mov     %i1, %o0
F00570C4: 92100012                 mov     %l2, %o1
F00570C8: 94100010                 mov     %l0, %o2
F00570CC: 7ffffef1                 call    _ipc_kmsg_copyout_object
F00570D0: 9607bff0                 add     %fp, var_10, %o3
F00570D4: a614c008                 bset    %o0, %l3
F00570D8: 11100000                 sethi   0x40000000, %o0
F00570DC: 902c4008                 andn    %l1, %o0, %o0
F00570E0: d0262014                 st      %o0, [%i0+0x14]
F00570E4: d207bff4                 ld      [%fp+var_C], %o1
F00570E8: 80a46000                 cmp     %l1, 0
F00570EC: d007bff0                 ld      [%fp+var_10], %o0
F00570F0: d226201c                 st      %o1, [%i0+0x1C]
F00570F4: 1680000a                 bge     locret_F005711C
F00570F8: d0262020                 st      %o0, [%i0+0x20]
F00570FC: 9006202c                 add     %i0, 0x2C, %o0 ! ','
F0057100: 94100019                 mov     %i1, %o2
F0057104: d2062018                 ld      [%i0+0x18], %o1
F0057108: 9610001a                 mov     %i2, %o3
F005710C: 92026014                 inc     0x14, %o1
F0057110: 7fffff3f                 call    _ipc_kmsg_copyout_body
F0057114: 92060009                 add     %i0, %o1, %o1
F0057118: a614c008                 bset    %o0, %l3
F005711C: 81c7e008                 ret
F0057120: 91e80013                 restore %g0, %l3, %o0
