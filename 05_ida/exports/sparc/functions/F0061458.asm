F0061458: 9de3bf90                 save    %sp, -0x70, %sp
F006145C: 9410001a                 mov     %i2, %o2
F0061460: 133c04d0                 sethi   %hi(_active_threads), %o1
F0061464: 9002a003                 add     %o2, 3, %o0
F0061468: 960a3ffc                 and     %o0, -4, %o3
F006146C: d0026260                 ld      [%o1+%lo(_active_threads)], %o0
F0061470: d202200c                 ld      [%o0+0xC], %o1
F0061474: 9422800b                 sub     %o2, %o3, %o2
F0061478: e0026088                 ld      [%o1+0x88], %l0
F006147C: 11000008                 sethi   0x2000, %o0
F0061480: 80a2c008                 cmp     %o3, %o0
F0061484: 08800004                 bleu    loc_F0061494
F0061488: f402600c                 ld      [%o1+0xC], %i2
F006148C: 1080005d                 ba      locret_F0061600
F0061490: b0103f93                 mov     -0x6D, %i0
F0061494: 90100018                 mov     %i0, %o0
F0061498: 9210000b                 mov     %o3, %o1
F006149C: 7fffcf6c                 call    _ipc_kmsg_get
F00614A0: 9607bff4                 add     %fp, var_C, %o3
F00614A4: b0920000                 orcc    %o0, %g0, %i0
F00614A8: 22800007                 be,a    loc_F00614C4
F00614AC: d007bff4                 ld      [%fp+var_C], %o0
F00614B0: 30800051                 ba,a    loc_F00615F4
F00614B4: 40001b3b                 call    _kfree
F00614B8: 01000000                 nop
F00614BC: 1080004e                 ba      loc_F00615F4
F00614C0: 90100018                 mov     %i0, %o0
F00614C4: 92100010                 mov     %l0, %o1
F00614C8: 7fffd761                 call    _ipc_kmsg_copyin_compat
F00614CC: 9410001a                 mov     %i2, %o2
F00614D0: b0920000                 orcc    %o0, %g0, %i0
F00614D4: 0280000a                 be      loc_F00614FC
F00614D8: d007bff4                 ld      [%fp+var_C], %o0
F00614DC: d2022008                 ld      [%o0+8], %o1
F00614E0: 80a26000                 cmp     %o1, 0
F00614E4: 14bffff4                 bg      loc_F00614B4
F00614E8: 01000000                 nop
F00614EC: 7fffcf45                 call    _ipc_kmsg_free
F00614F0: 01000000                 nop
F00614F4: 10800040                 ba      loc_F00615F4
F00614F8: 90100018                 mov     %i0, %o0
F00614FC: 808e6002                 btst    2, %i1
F0061500: 02800023                 be      loc_F006158C
F0061504: 808e6020                 btst    0x20, %i1 ! ' '
F0061508: 02800005                 be      loc_F006151C
F006150C: d407bff4                 ld      [%fp+var_C], %o2
F0061510: 11000080                 sethi   0x20000, %o0
F0061514: 10800003                 ba      loc_F0061520
F0061518: 92122010                 or      %o0, 0x10, %o1
F006151C: 92102010                 mov     0x10, %o1
F0061520: 9010000a                 mov     %o2, %o0
F0061524: 940e6001                 and     %i1, 1, %o2
F0061528: 9420000a                 neg     %o2
F006152C: 940ec00a                 and     %i3, %o2, %o2
F0061530: 7fffdbd3                 call    _ipc_mqueue_send
F0061534: 96102000                 mov     0, %o3
F0061538: b0100008                 mov     %o0, %i0
F006153C: 1104000090122004         set     0x10000004, %o0
F0061544: 80a60008                 cmp     %i0, %o0
F0061548: 12800026                 bne     loc_F00615E0
F006154C: 80a62000                 cmp     %i0, 0
F0061550: d607bff4                 ld      [%fp+var_C], %o3
F0061554: 90100010                 mov     %l0, %o0
F0061558: d202e01c                 ld      [%o3+0x1C], %o1
F006155C: 94102000                 mov     0, %o2
F0061560: 7fffda11                 call    _ipc_marequest_create
F0061564: 9602e00c                 inc     0xC, %o3
F0061568: b0920000                 orcc    %o0, %g0, %i0
F006156C: 1280001d                 bne     loc_F00615E0
F0061570: d007bff4                 ld      [%fp+var_C], %o0
F0061574: 13000040                 sethi   0x10000, %o1
F0061578: 94102000                 mov     0, %o2
F006157C: 7fffdbc0                 call    _ipc_mqueue_send
F0061580: 96102000                 mov     0, %o3
F0061584: 1080001f                 ba      locret_F0061600
F0061588: b0103f97                 mov     -0x69, %i0
F006158C: 0280000d                 be      loc_F00615C0
F0061590: 808e6001                 btst    1, %i1
F0061594: 02800005                 be      loc_F00615A8
F0061598: d407bff4                 ld      [%fp+var_C], %o2
F006159C: 11000080                 sethi   0x20000, %o0
F00615A0: 10800003                 ba      loc_F00615AC
F00615A4: 92122010                 or      %o0, 0x10, %o1
F00615A8: 13000080                 sethi   0x20000, %o1
F00615AC: 9010000a                 mov     %o2, %o0
F00615B0: 9410001b                 mov     %i3, %o2
F00615B4: 173c0185                 sethi   %hi(_msg_send_switch_continue), %o3
F00615B8: 10800007                 ba      loc_F00615D4
F00615BC: 9612e208                 bset    %lo(_msg_send_switch_continue), %o3
F00615C0: d007bff4                 ld      [%fp+var_C], %o0
F00615C4: 920e6001                 and     %i1, 1, %o1
F00615C8: 932a6004                 sll     %o1, 4, %o1
F00615CC: 9410001b                 mov     %i3, %o2
F00615D0: 96102000                 mov     0, %o3
F00615D4: 7fffdbaa                 call    _ipc_mqueue_send
F00615D8: 01000000                 nop
F00615DC: b0920000                 orcc    %o0, %g0, %i0
F00615E0: 02800005                 be      loc_F00615F4
F00615E4: 90100018                 mov     %i0, %o0
F00615E8: 7fffce10                 call    _ipc_kmsg_destroy
F00615EC: d007bff4                 ld      [%fp+var_C], %o0
F00615F0: 90100018                 mov     %i0, %o0
F00615F4: 7fffff1b                 call    _msg_return_translate
F00615F8: 01000000                 nop
F00615FC: b0100008                 mov     %o0, %i0
F0061600: 81c7e008                 ret
F0061604: 81e80000                 restore
