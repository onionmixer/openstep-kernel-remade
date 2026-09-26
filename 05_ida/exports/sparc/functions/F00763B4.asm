F00763B4: 9de3bf98                 save    %sp, -0x68, %sp
F00763B8: 92102000                 mov     0, %o1
F00763BC: 113c04d4                 sethi   %hi(dword_F01350F8), %o0
F00763C0: d40220f8                 ld      [%o0+%lo(dword_F01350F8)], %o2
F00763C4: 901220f8                 bset    %lo(dword_F01350F8), %o0
F00763C8: 80a28008                 cmp     %o2, %o0
F00763CC: 0280000c                 be      loc_F00763FC
F00763D0: a0102000                 mov     0, %l0
F00763D4: 96100008                 mov     %o0, %o3
F00763D8: d002a0c0                 ld      [%o2+0xC0], %o0
F00763DC: 80a22000                 cmp     %o0, 0
F00763E0: 02800003                 be      loc_F00763EC
F00763E4: 92026001                 inc     %o1
F00763E8: a0042001                 inc     %l0
F00763EC: d402a018                 ld      [%o2+0x18], %o2
F00763F0: 80a2800b                 cmp     %o2, %o3
F00763F4: 32bffffa                 bne,a   loc_F00763DC
F00763F8: d002a0c0                 ld      [%o2+0xC0], %o0
F00763FC: 113c0442                 sethi   %hi(aDTotalThreads), %o0! "%d total threads.\n"
F0076400: 7ffe7896                 call    _printf
F0076404: 90122370                 bset    %lo(aDTotalThreads), %o0! "%d total threads.\n"
F0076408: 113c044290122388         set     aDUsingRpcReply, %o0! "%d using rpc_reply.\n"
F0076410: 7ffe7892                 call    _printf
F0076414: 92100010                 mov     %l0, %o1
F0076418: 81c7e008                 ret
F007641C: 81e80000                 restore
