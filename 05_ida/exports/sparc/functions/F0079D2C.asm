F0079D2C: 9de3bf48                 save    %sp, -0xB8, %sp
F0079D30: 7fffb8d0                 call    _kalloc
F0079D34: 901024d4                 mov     0x4D4, %o0
F0079D38: d027bfb4                 st      %o0, [%fp+var_50+4]
F0079D3C: 9007bfb8                 add     %fp, var_48, %o0! __dst
F0079D40: 133c03d39212615c         set     _kern_serv_proto, %o1! __src
F0079D48: 7ffe3556                 call    _memcpy
F0079D4C: 9410203c                 mov     0x3C, %o2 ! '<'
F0079D50: 9207bfb4                 add     %fp, var_50+4, %o1
F0079D54: 213c04d0                 sethi   %hi(_active_threads), %l0
F0079D58: d0042260                 ld      [%l0+%lo(_active_threads)], %o0
F0079D5C: d227bfb8                 st      %o1, [%fp+var_48]
F0079D60: d202200c                 ld      [%o0+0xC], %o1! size_t
F0079D64: 113c0442                 sethi   %hi(_kernel_task), %o0
F0079D68: d0022250                 ld      [%o0+%lo(_kernel_task)], %o0
F0079D6C: 80a24008                 cmp     %o1, %o0
F0079D70: 02800003                 be      loc_F0079D7C
F0079D74: 90102001                 mov     1, %o0
F0079D78: d0226050                 st      %o0, [%o1+0x50]
F0079D7C: d007bfb4                 ld      [%fp+var_50+4], %o0! void *
F0079D80: 40006c36                 call    _bzero
F0079D84: 921024d4                 mov     0x4D4, %o1
F0079D88: d207bfb4                 ld      [%fp+var_50+4], %o1
F0079D8C: 90103fff                 mov     -1, %o0
F0079D90: 7fffb548                 call    _task_self
F0079D94: d02264c8                 st      %o0, [%o1+0x4C8]
F0079D98: d207bfb4                 ld      [%fp+var_50+4], %o1
F0079D9C: 9810217c                 mov     0x17C, %o4
F0079DA0: d0226008                 st      %o0, [%o1+8]
F0079DA4: 9002603c                 add     %o1, 0x3C, %o0 ! '<'
F0079DA8: 9a100008                 mov     %o0, %o5
F0079DAC: 96026130                 add     %o1, 0x130, %o3
F0079DB0: d0042260                 ld      [%l0+0x260], %o0
F0079DB4: 84100009                 mov     %o1, %g2
F0079DB8: d022600c                 st      %o0, [%o1+0xC]
F0079DBC: c0224000                 clr     [%o1]
F0079DC0: 90026034                 add     %o1, 0x34, %o0 ! '4'
F0079DC4: d0226038                 st      %o0, [%o1+0x38]
F0079DC8: d0226034                 st      %o0, [%o1+0x34]
F0079DCC: da226040                 st      %o5, [%o1+0x40]
F0079DD0: da22603c                 st      %o5, [%o1+0x3C]
F0079DD4: 900264c0                 add     %o1, 0x4C0, %o0
F0079DD8: d02264c4                 st      %o0, [%o1+0x4C4]
F0079DDC: d02264c0                 st      %o0, [%o1+0x4C0]
F0079DE0: d4026040                 ld      [%o1+0x40], %o2
F0079DE4: 80a3400a                 cmp     %o5, %o2
F0079DE8: 12800004                 bne     loc_F0079DF8
F0079DEC: 9002400c                 add     %o1, %o4, %o0
F0079DF0: 10800003                 ba      loc_F0079DFC
F0079DF4: d022603c                 st      %o0, [%o1+0x3C]
F0079DF8: d022a008                 st      %o0, [%o2+8]
F0079DFC: d422e058                 st      %o2, [%o3+0x58]
F0079E00: da22e054                 st      %o5, [%o3+0x54]
F0079E04: 9002400c                 add     %o1, %o4, %o0
F0079E08: d0226040                 st      %o0, [%o1+0x40]
F0079E0C: 9602fff0                 inc     -0x10, %o3
F0079E10: 80a2c002                 cmp     %o3, %g2
F0079E14: 16bffff3                 bge     loc_F0079DE0
F0079E18: 98033ff0                 inc     -0x10, %o4
F0079E1C: 7fffb539                 call    _thread_self
F0079E20: 01000000                 nop
F0079E24: 92102002                 mov     2, %o1
F0079E28: 4001e8d7                 call    _thread_get_special_port_EXTERNAL
F0079E2C: 9407bfb0                 add     %fp, var_50, %o2
F0079E30: 80a22000                 cmp     %o0, 0
F0079E34: 12800007                 bne     loc_F0079E50
F0079E38: 113c0443                 sethi   -0xFEEF400, %o0
F0079E3C: d007bfb0                 ld      [%fp+var_50], %o0
F0079E40: 80a22000                 cmp     %o0, 0
F0079E44: 3280000b                 bne,a   loc_F0079E70
F0079E48: d207bfb4                 ld      [%fp+var_50+4], %o1
F0079E4C: 113c0443                 sethi   -0xFEEF400, %o0! char *
F0079E50: 7ffe6a02                 call    _printf
F0079E54: 901220a8                 bset    0xA8, %o0
F0079E58: 113c04d0                 sethi   %hi(_active_threads), %o0! target_act
F0079E5C: 7fffea8e                 call    _thread_terminate
F0079E60: d0022260                 ld      [%o0+%lo(_active_threads)], %o0
F0079E64: 7fffecaa                 call    _thread_halt_self
F0079E68: 01000000                 nop
F0079E6C: d01fbfb0                 ldd     [%fp+var_50], %o0
F0079E70: 7fffb510                 call    _task_self
F0079E74: d0226014                 st      %o0, [%o1+0x14]
F0079E78: 4001e73a                 call    _port_allocate_EXTERNAL
F0079E7C: 9207bfac                 add     %fp, var_54, %o1
F0079E80: 80a22000                 cmp     %o0, 0
F0079E84: 02800009                 be      loc_F0079EA8
F0079E88: 113c0443                 sethi   %hi(aKServerCanTAll), %o0! "k_server: can't allocate reply port..te"...
F0079E8C: 7ffe69f3                 call    _printf
F0079E90: 901220e0                 bset    %lo(aKServerCanTAll), %o0! "k_server: can't allocate reply port..te"...
F0079E94: 113c04d0                 sethi   %hi(_active_threads), %o0! target_act
F0079E98: 7fffea7f                 call    _thread_terminate
F0079E9C: d0022260                 ld      [%o0+%lo(_active_threads)], %o0
F0079EA0: 7fffec9b                 call    _thread_halt_self
F0079EA4: 01000000                 nop
F0079EA8: 7fffb516                 call    _thread_self
F0079EAC: 01000000                 nop
F0079EB0: d407bfac                 ld      [%fp+var_54], %o2
F0079EB4: 4001e8fb                 call    _thread_set_special_port_EXTERNAL
F0079EB8: 92102002                 mov     2, %o1
F0079EBC: 80a22000                 cmp     %o0, 0
F0079EC0: 02800009                 be      loc_F0079EE4
F0079EC4: 113c0443                 sethi   %hi(aKServerCanTSet), %o0! "k_server: can't set reply port..termina"...
F0079EC8: 7ffe69e4                 call    _printf
F0079ECC: 90122118                 bset    %lo(aKServerCanTSet), %o0! "k_server: can't set reply port..termina"...
F0079ED0: 113c04d0                 sethi   %hi(_active_threads), %o0! target_act
F0079ED4: 7fffea70                 call    _thread_terminate
F0079ED8: d0022260                 ld      [%o0+%lo(_active_threads)], %o0
F0079EDC: 7fffec8c                 call    _thread_halt_self
F0079EE0: 01000000                 nop
F0079EE4: 7fffb4f3                 call    _task_self
F0079EE8: 01000000                 nop
F0079EEC: 4001e7e2                 call    _port_set_allocate_EXTERNAL
F0079EF0: 9207bfa8                 add     %fp, var_58, %o1
F0079EF4: 80a22000                 cmp     %o0, 0
F0079EF8: 02800009                 be      loc_F0079F1C
F0079EFC: 113c0443                 sethi   %hi(aKServerCanTAll_0), %o0! "k_server: can't allocate port set..term"...
F0079F00: 7ffe69d6                 call    _printf
F0079F04: 90122148                 bset    %lo(aKServerCanTAll_0), %o0! "k_server: can't allocate port set..term"...
F0079F08: 113c04d0                 sethi   %hi(_active_threads), %o0! target_act
F0079F0C: 7fffea62                 call    _thread_terminate
F0079F10: d0022260                 ld      [%o0+%lo(_active_threads)], %o0
F0079F14: 7fffec7e                 call    _thread_halt_self
F0079F18: 01000000                 nop
F0079F1C: d207bfb4                 ld      [%fp+var_50+4], %o1
F0079F20: d007bfa8                 ld      [%fp+var_58], %o0
F0079F24: 7fffb4e3                 call    _task_self
F0079F28: d0226020                 st      %o0, [%o1+0x20]
F0079F2C: d207bfa8                 ld      [%fp+var_58], %o1
F0079F30: 4001e78e                 call    _port_set_add_EXTERNAL
F0079F34: d407bfb0                 ld      [%fp+var_50], %o2
F0079F38: 80a22000                 cmp     %o0, 0
F0079F3C: 02800009                 be      loc_F0079F60
F0079F40: 113c0443                 sethi   %hi(aKServerCanTAdd), %o0! "k_server: can't add listener port\n"
F0079F44: 7ffe69c5                 call    _printf
F0079F48: 90122178                 bset    %lo(aKServerCanTAdd), %o0! "k_server: can't add listener port\n"
F0079F4C: 113c04d0                 sethi   %hi(_active_threads), %o0! target_act
F0079F50: 7fffea51                 call    _thread_terminate
F0079F54: d0022260                 ld      [%o0+%lo(_active_threads)], %o0
F0079F58: 7fffec6d                 call    _thread_halt_self
F0079F5C: 01000000                 nop
F0079F60: d207bfb4                 ld      [%fp+var_50+4], %o1
F0079F64: d0026008                 ld      [%o1+8], %o0
F0079F68: 4001e6fe                 call    _port_allocate_EXTERNAL
F0079F6C: 9202601c                 inc     0x1C, %o1
F0079F70: 80a22000                 cmp     %o0, 0
F0079F74: 12800009                 bne     loc_F0079F98
F0079F78: d007bfb4                 ld      [%fp+var_50+4], %o0
F0079F7C: d407bfb4                 ld      [%fp+var_50+4], %o2
F0079F80: d002a008                 ld      [%o2+8], %o0
F0079F84: d202a020                 ld      [%o2+0x20], %o1
F0079F88: 4001e778                 call    _port_set_add_EXTERNAL
F0079F8C: d402a01c                 ld      [%o2+0x1C], %o2
F0079F90: 10800007                 ba      loc_F0079FAC
F0079F94: 113c04d0                 sethi   -0xFECC000, %o0
F0079F98: 133c0443                 sethi   %hi(aKServerCanTGet), %o1! "k_server: can't get notify port"
F0079F9C: d0022010                 ld      [%o0+0x10], %o0
F0079FA0: 40000715                 call    _kern_serv_panic
F0079FA4: 921261a0                 bset    %lo(aKServerCanTGet), %o1! "k_server: can't get notify port"
F0079FA8: 113c04d0                 sethi   -0xFECC000, %o0
F0079FAC: d0022260                 ld      [%o0+0x260], %o0
F0079FB0: d202200c                 ld      [%o0+0xC], %o1
F0079FB4: 113c0442                 sethi   %hi(_kernel_task), %o0
F0079FB8: d0022250                 ld      [%o0+%lo(_kernel_task)], %o0
F0079FBC: 80a24008                 cmp     %o1, %o0
F0079FC0: 22800009                 be,a    loc_F0079FE4
F0079FC4: d007bfb4                 ld      [%fp+var_50+4], %o0
F0079FC8: 7fffb4ba                 call    _task_self
F0079FCC: 01000000                 nop
F0079FD0: d207bfb4                 ld      [%fp+var_50+4], %o1
F0079FD4: d402601c                 ld      [%o1+0x1C], %o2
F0079FD8: 4001e829                 call    _task_set_special_port_EXTERNAL
F0079FDC: 92102002                 mov     2, %o1
F0079FE0: d007bfb4                 ld      [%fp+var_50+4], %o0
F0079FE4: d202201c                 ld      [%o0+0x1C], %o1
F0079FE8: d4022010                 ld      [%o0+0x10], %o2
F0079FEC: 4000015d                 call    _kern_serv_notify
F0079FF0: 9007bfb4                 add     %fp, var_50+4, %o0
F0079FF4: 400003a8                 call    _kern_serv_kernel_task_port
F0079FF8: 01000000                 nop
F0079FFC: d207bfb4                 ld      [%fp+var_50+4], %o1
F007A000: d02264cc                 st      %o0, [%o1+0x4CC]
F007A004: 7fffb81b                 call    _kalloc
F007A008: 90102030                 mov     0x30, %o0 ! '0'
F007A00C: a4100008                 mov     %o0, %l2
F007A010: d207bfb4                 ld      [%fp+var_50+4], %o1
F007A014: 90102030                 mov     0x30, %o0 ! '0'
F007A018: e4226044                 st      %l2, [%o1+0x44]
F007A01C: d0226048                 st      %o0, [%o1+0x48]
F007A020: 400072da                 call    _splusclock
F007A024: 01000000                 nop
F007A028: a6100008                 mov     %o0, %l3
F007A02C: e007bfb4                 ld      [%fp+var_50+4], %l0
F007A030: d0040000                 ld      [%l0], %o0
F007A034: 80a22000                 cmp     %o0, 0
F007A038: 12bffffe                 bne     loc_F007A030
F007A03C: 01000000                 nop
F007A040: 4000739a                 call    _simple_lock_try
F007A044: 90100010                 mov     %l0, %o0
F007A048: 80a22000                 cmp     %o0, 0
F007A04C: 02bffff9                 be      loc_F007A030
F007A050: d407bfb4                 ld      [%fp+var_50+4], %o2
F007A054: 1080002a                 ba      loc_F007A0FC
F007A058: d202a034                 ld      [%o2+0x34], %o1
F007A05C: d2046008                 ld      [%l1+8], %o1
F007A060: 9002a034                 add     %o2, 0x34, %o0 ! '4'
F007A064: 80a20009                 cmp     %o0, %o1
F007A068: 32800003                 bne,a   loc_F007A074
F007A06C: d022600c                 st      %o0, [%o1+0xC]
F007A070: d222a038                 st      %o1, [%o2+0x38]
F007A074: d007bfb4                 ld      [%fp+var_50+4], %o0
F007A078: d2222034                 st      %o1, [%o0+0x34]
F007A07C: c0220000                 clr     [%o0]
F007A080: 40007329                 call    _splx
F007A084: 90100013                 mov     %l3, %o0
F007A088: d2044000                 ld      [%l1], %o1
F007A08C: 9fc24000                 call    %o1
F007A090: d0046004                 ld      [%l1+4], %o0
F007A094: 400072bd                 call    _splusclock
F007A098: 01000000                 nop
F007A09C: a6100008                 mov     %o0, %l3
F007A0A0: e007bfb4                 ld      [%fp+var_50+4], %l0
F007A0A4: d0040000                 ld      [%l0], %o0
F007A0A8: 80a22000                 cmp     %o0, 0
F007A0AC: 12bffffe                 bne     loc_F007A0A4
F007A0B0: 01000000                 nop
F007A0B4: 4000737d                 call    _simple_lock_try
F007A0B8: 90100010                 mov     %l0, %o0
F007A0BC: 80a22000                 cmp     %o0, 0
F007A0C0: 02bffff9                 be      loc_F007A0A4
F007A0C4: d207bfb4                 ld      [%fp+var_50+4], %o1
F007A0C8: d4026040                 ld      [%o1+0x40], %o2
F007A0CC: 9002603c                 add     %o1, 0x3C, %o0 ! '<'
F007A0D0: 80a2000a                 cmp     %o0, %o2
F007A0D4: 32800003                 bne,a   loc_F007A0E0
F007A0D8: e222a008                 st      %l1, [%o2+8]
F007A0DC: e222603c                 st      %l1, [%o1+0x3C]
F007A0E0: d207bfb4                 ld      [%fp+var_50+4], %o1
F007A0E4: d424600c                 st      %o2, [%l1+0xC]
F007A0E8: 9002603c                 add     %o1, 0x3C, %o0 ! '<'
F007A0EC: d0246008                 st      %o0, [%l1+8]
F007A0F0: e2226040                 st      %l1, [%o1+0x40]
F007A0F4: 94100009                 mov     %o1, %o2
F007A0F8: d202a034                 ld      [%o2+0x34], %o1
F007A0FC: 9002a034                 add     %o2, 0x34, %o0 ! '4'
F007A100: 80a20009                 cmp     %o0, %o1
F007A104: 32bfffd6                 bne,a   loc_F007A05C
F007A108: e202a034                 ld      [%o2+0x34], %l1
F007A10C: d207bfb4                 ld      [%fp+var_50+4], %o1
F007A110: 90100013                 mov     %l3, %o0
F007A114: c0224000                 clr     [%o1]
F007A118: 40007303                 call    _splx
F007A11C: 01000000                 nop
F007A120: 90100012                 mov     %l2, %o0
F007A124: d607bfa8                 ld      [%fp+var_58], %o3
F007A128: 13000005                 sethi   0x1400, %o1
F007A12C: d407bfb4                 ld      [%fp+var_50+4], %o2
F007A130: d624a00c                 st      %o3, [%l2+0xC]
F007A134: d602a048                 ld      [%o2+0x48], %o3
F007A138: 92126100                 bset    0x100, %o1
F007A13C: 941023e8                 mov     0x3E8, %o2
F007A140: 7fffaf47                 call    _msg_receive
F007A144: d624a004                 st      %o3, [%l2+4]
F007A148: 80a23f34                 cmp     %o0, -0xCC
F007A14C: 2280000f                 be,a    loc_F007A188
F007A150: d007bfb4                 ld      [%fp+var_50+4], %o0
F007A154: 14800007                 bg      loc_F007A170
F007A158: 80a23f35                 cmp     %o0, -0xCB
F007A15C: 80a23f31                 cmp     %o0, -0xCF
F007A160: 0280001b                 be      loc_F007A1CC
F007A164: d407bfb4                 ld      [%fp+var_50+4], %o2
F007A168: 10800014                 ba      loc_F007A1B8
F007A16C: d007bfb4                 ld      [%fp+var_50+4], %o0
F007A170: 02bfffac                 be      loc_F007A020
F007A174: 80a22000                 cmp     %o0, 0
F007A178: 02800015                 be      loc_F007A1CC
F007A17C: d407bfb4                 ld      [%fp+var_50+4], %o2
F007A180: 1080000e                 ba      loc_F007A1B8
F007A184: d007bfb4                 ld      [%fp+var_50+4], %o0
F007A188: d2022048                 ld      [%o0+0x48], %o1
F007A18C: d0022044                 ld      [%o0+0x44], %o0
F007A190: 7fffb804                 call    _kfree
F007A194: e0022004                 ld      [%o0+4], %l0
F007A198: d207bfb4                 ld      [%fp+var_50+4], %o1
F007A19C: 90100010                 mov     %l0, %o0
F007A1A0: 7fffb7b4                 call    _kalloc
F007A1A4: d0226048                 st      %o0, [%o1+0x48]
F007A1A8: d207bfb4                 ld      [%fp+var_50+4], %o1
F007A1AC: a4100008                 mov     %o0, %l2
F007A1B0: 10bfffdc                 ba      loc_F007A120
F007A1B4: e4226044                 st      %l2, [%o1+0x44]
F007A1B8: 133c0443                 sethi   %hi(aKernServerMain), %o1! "kern_server_main: received return bad r"...
F007A1BC: d0022010                 ld      [%o0+0x10], %o0
F007A1C0: 4000068d                 call    _kern_serv_panic
F007A1C4: 921261c0                 bset    %lo(aKernServerMain), %o1! "kern_server_main: received return bad r"...
F007A1C8: d407bfb4                 ld      [%fp+var_50+4], %o2
F007A1CC: d204a00c                 ld      [%l2+0xC], %o1
F007A1D0: d002a01c                 ld      [%o2+0x1C], %o0
F007A1D4: 80a24008                 cmp     %o1, %o0
F007A1D8: 32800022                 bne,a   loc_F007A260
F007A1DC: d004a014                 ld      [%l2+0x14], %o0
F007A1E0: d204a014                 ld      [%l2+0x14], %o1
F007A1E4: 80a26041                 cmp     %o1, 0x41 ! 'A'
F007A1E8: 12800017                 bne     loc_F007A244
F007A1EC: a0100012                 mov     %l2, %l0
F007A1F0: d202a4b8                 ld      [%o2+0x4B8], %o1
F007A1F4: 80a26000                 cmp     %o1, 0
F007A1F8: 22800009                 be,a    loc_F007A21C
F007A1FC: d402a4bc                 ld      [%o2+0x4BC], %o2
F007A200: 9fc24000                 call    %o1
F007A204: d004a01c                 ld      [%l2+0x1C], %o0
F007A208: 80a22000                 cmp     %o0, 0
F007A20C: 12bfff85                 bne     loc_F007A020
F007A210: 01000000                 nop
F007A214: 10800009                 ba      loc_F007A238
F007A218: d204201c                 ld      [%l0+0x1C], %o1
F007A21C: 80a2a000                 cmp     %o2, 0
F007A220: 22800006                 be,a    loc_F007A238
F007A224: d204201c                 ld      [%l0+0x1C], %o1
F007A228: d004a01c                 ld      [%l2+0x1C], %o0
F007A22C: 9fc28000                 call    %o2
F007A230: 92102041                 mov     0x41, %o1 ! 'A'
F007A234: d204201c                 ld      [%l0+0x1C], %o1
F007A238: 40000098                 call    _kern_serv_port_gone
F007A23C: 9007bfb4                 add     %fp, var_50+4, %o0
F007A240: 30bfff78                 ba,a    loc_F007A020
F007A244: d402a4bc                 ld      [%o2+0x4BC], %o2
F007A248: 80a2a000                 cmp     %o2, 0
F007A24C: 02bfff75                 be      loc_F007A020
F007A250: 01000000                 nop
F007A254: 9fc28000                 call    %o2
F007A258: d004a01c                 ld      [%l2+0x1C], %o0
F007A25C: 30bfff71                 ba,a    loc_F007A020
F007A260: 90023fc0                 inc     -0x40, %o0
F007A264: 80a2200c                 cmp     %o0, 0xC
F007A268: 18800029                 bgu     loc_F007A30C
F007A26C: 9002a4c0                 add     %o2, 0x4C0, %o0
F007A270: e002a4c0                 ld      [%o2+0x4C0], %l0
F007A274: 80a20010                 cmp     %o0, %l0
F007A278: 02800025                 be      loc_F007A30C
F007A27C: a2100012                 mov     %l2, %l1
F007A280: d2042004                 ld      [%l0+4], %o1
F007A284: d004601c                 ld      [%l1+0x1C], %o0
F007A288: 80a24008                 cmp     %o1, %o0
F007A28C: 1280001b                 bne     loc_F007A2F8
F007A290: d007bfb4                 ld      [%fp+var_50+4], %o0
F007A294: 90100012                 mov     %l2, %o0
F007A298: 92102000                 mov     0, %o1
F007A29C: d6040000                 ld      [%l0], %o3
F007A2A0: 94102000                 mov     0, %o2
F007A2A4: 7fffae8c                 call    _msg_send
F007A2A8: d624a010                 st      %o3, [%l2+0x10]
F007A2AC: d6042008                 ld      [%l0+8], %o3
F007A2B0: d407bfb4                 ld      [%fp+var_50+4], %o2
F007A2B4: 9002a4c0                 add     %o2, 0x4C0, %o0
F007A2B8: 80a2000b                 cmp     %o0, %o3
F007A2BC: 12800004                 bne     loc_F007A2CC
F007A2C0: d204200c                 ld      [%l0+0xC], %o1
F007A2C4: 10800003                 ba      loc_F007A2D0
F007A2C8: d222a4c4                 st      %o1, [%o2+0x4C4]
F007A2CC: d222e00c                 st      %o1, [%o3+0xC]
F007A2D0: d407bfb4                 ld      [%fp+var_50+4], %o2
F007A2D4: 9002a4c0                 add     %o2, 0x4C0, %o0
F007A2D8: 80a20009                 cmp     %o0, %o1
F007A2DC: 32800003                 bne,a   loc_F007A2E8
F007A2E0: d6226008                 st      %o3, [%o1+8]
F007A2E4: d622a4c0                 st      %o3, [%o2+0x4C0]
F007A2E8: 90100010                 mov     %l0, %o0
F007A2EC: 7fffb7ad                 call    _kfree
F007A2F0: 92102010                 mov     0x10, %o1
F007A2F4: d007bfb4                 ld      [%fp+var_50+4], %o0
F007A2F8: e0042008                 ld      [%l0+8], %l0
F007A2FC: 900224c0                 inc     0x4C0, %o0
F007A300: 80a20010                 cmp     %o0, %l0
F007A304: 32bfffe0                 bne,a   loc_F007A284
F007A308: d2042004                 ld      [%l0+4], %o1
F007A30C: d207bfb4                 ld      [%fp+var_50+4], %o1
F007A310: d404a00c                 ld      [%l2+0xC], %o2
F007A314: 90100012                 mov     %l2, %o0
F007A318: 40000031                 call    sub_F007A3DC
F007A31C: d4226004                 st      %o2, [%o1+4]
F007A320: 80a23ed1                 cmp     %o0, -0x12F
F007A324: 12bfff3f                 bne     loc_F007A020
F007A328: d007bfb0                 ld      [%fp+var_50], %o0
F007A32C: d204a00c                 ld      [%l2+0xC], %o1
F007A330: 80a24008                 cmp     %o1, %o0
F007A334: 12bfff3b                 bne     loc_F007A020
F007A338: 90100012                 mov     %l2, %o0
F007A33C: 400005fe                 call    _kern_serv_handler
F007A340: 9207bfb8                 add     %fp, var_48, %o1
F007A344: 30bfff37                 ba,a    loc_F007A020
