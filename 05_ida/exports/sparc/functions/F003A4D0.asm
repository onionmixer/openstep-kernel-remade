F003A4D0: 9de3bf80                 save    %sp, -0x80, %sp
F003A4D4: 213c04cf                 sethi   %hi(dword_F0133DDC), %l0
F003A4D8: d00421dc                 ld      [%l0+%lo(dword_F0133DDC)], %o0
F003A4DC: d2022024                 ld      [%o0+0x24], %o1
F003A4E0: d0024000                 ld      [%o1], %o0
F003A4E4: 7fff9fbb                 call    _getsock
F003A4E8: d227bff4                 st      %o1, [%fp+var_C]
F003A4EC: 80a22000                 cmp     %o0, 0
F003A4F0: 12800006                 bne     loc_F003A508
F003A4F4: d027bfec                 st      %o0, [%fp+var_14]
F003A4F8: d20421dc                 ld      [%l0+%lo(dword_F0133DDC)], %o1
F003A4FC: 90102009                 mov     9, %o0
F003A500: 1080004a                 ba      locret_F003A628
F003A504: d02a6038                 stb     %o0, [%o1+0x38]
F003A508: d0022018                 ld      [%o0+0x18], %o0
F003A50C: 133c0432                 sethi   %hi(_nfs_chars), %o1
F003A510: d20261f8                 ld      [%o1+%lo(_nfs_chars)], %o1
F003A514: d027bff0                 st      %o0, [%fp+var_10]
F003A518: 7fff97d7                 call    _soreserve
F003A51C: 94026020                 add     %o1, 0x20, %o2 ! ' '
F003A520: 80a22000                 cmp     %o0, 0
F003A524: 02800006                 be      loc_F003A53C
F003A528: d027bfe0                 st      %o0, [%fp+var_20]
F003A52C: d20421dc                 ld      [%l0+0x1DC], %o1
F003A530: d00fbfe3                 ldub    [%fp+var_20+3], %o0
F003A534: 1080003d                 ba      locret_F003A628
F003A538: d02a6038                 stb     %o0, [%o1+0x38]
F003A53C: d007bff0                 ld      [%fp+var_10], %o0
F003A540: 92102801                 mov     0x801, %o1
F003A544: 233c00ef                 sethi   -0xFFC4400, %l1
F003A548: 40002a4c                 call    _svckudp_create
F003A54C: 21000061                 sethi   0x18400, %l0
F003A550: d027bfe8                 st      %o0, [%fp+var_18]
F003A554: 90102002                 mov     2, %o0
F003A558: d027bfe4                 st      %o0, [%fp+var_1C]
F003A55C: 921422a3                 or      %l0, 0x2A3, %o1! unsigned __int32
F003A560: d007bfe8                 ld      [%fp+var_18], %o0! SVCXPRT *
F003A564: 961460d8                 or      %l1, 0xD8, %o3! void (*)(void)
F003A568: d407bfe4                 ld      [%fp+var_1C], %o2! unsigned __int32
F003A56C: 40002877                 call    _svc_register
F003A570: 98102000                 mov     0, %o4
F003A574: d007bfe4                 ld      [%fp+var_1C], %o0
F003A578: 90022001                 inc     %o0
F003A57C: 80a22002                 cmp     %o0, 2
F003A580: 08bffff7                 bleu    loc_F003A55C
F003A584: d027bfe4                 st      %o0, [%fp+var_1C]
F003A588: 113c04cf                 sethi   %hi(dword_F0133DDC), %o0
F003A58C: d00221dc                 ld      [%o0+%lo(dword_F0133DDC)], %o0! jmp_buf
F003A590: 400171f1                 call    _setjmp
F003A594: 90022028                 inc     0x28, %o0 ! '('
F003A598: 80a22000                 cmp     %o0, 0
F003A59C: 0280001d                 be      loc_F003A610
F003A5A0: 133c0432                 sethi   %hi(_nfsd_count), %o1
F003A5A4: d00261fc                 ld      [%o1+%lo(_nfsd_count)], %o0
F003A5A8: 90023fff                 inc     -1, %o0
F003A5AC: 80a22000                 cmp     %o0, 0
F003A5B0: 1280000d                 bne     loc_F003A5E4
F003A5B4: d02261fc                 st      %o0, [%o1+%lo(_nfsd_count)]
F003A5B8: 90102002                 mov     2, %o0! unsigned __int32
F003A5BC: d027bfe4                 st      %o0, [%fp+var_1C]
F003A5C0: 21000061                 sethi   0x18400, %l0
F003A5C4: d207bfe4                 ld      [%fp+var_1C], %o1! unsigned __int32
F003A5C8: 4000287a                 call    _svc_unregister
F003A5CC: 901422a3                 or      %l0, 0x2A3, %o0
F003A5D0: d007bfe4                 ld      [%fp+var_1C], %o0
F003A5D4: 90022001                 inc     %o0
F003A5D8: 80a22002                 cmp     %o0, 2
F003A5DC: 08bffffa                 bleu    loc_F003A5C4
F003A5E0: d027bfe4                 st      %o0, [%fp+var_1C]
F003A5E4: d007bfe8                 ld      [%fp+var_18], %o0
F003A5E8: d2022008                 ld      [%o0+8], %o1
F003A5EC: d2026014                 ld      [%o1+0x14], %o1
F003A5F0: 9fc24000                 call    %o1
F003A5F4: 01000000                 nop
F003A5F8: 133c04cf                 sethi   %hi(dword_F0133DDC), %o1
F003A5FC: d40261dc                 ld      [%o1+%lo(dword_F0133DDC)], %o2
F003A600: 90102000                 mov     0, %o0! int
F003A604: 92102004                 mov     4, %o1
F003A608: 7fff4843                 call    _exit
F003A60C: d22aa038                 stb     %o1, [%o2+0x38]
F003A610: 153c0432                 sethi   %hi(_nfsd_count), %o2
F003A614: d202a1fc                 ld      [%o2+%lo(_nfsd_count)], %o1
F003A618: d007bfe8                 ld      [%fp+var_18], %o0
F003A61C: 92026001                 inc     %o1
F003A620: 40002978                 call    _svc_run
F003A624: d222a1fc                 st      %o1, [%o2+%lo(_nfsd_count)]
F003A628: 81c7e008                 ret
F003A62C: 81e80000                 restore
