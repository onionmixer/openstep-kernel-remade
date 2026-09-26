F0012678: 9de3bf98                 save    %sp, -0x68, %sp
F001267C: 233c04cf                 sethi   %hi(_active_u), %l1
F0012680: d00461d8                 ld      [%l1+%lo(_active_u)], %o0
F0012684: 40021141                 call    _splusclock
F0012688: e0020000                 ld      [%o0], %l0
F001268C: 80a42000                 cmp     %l0, 0
F0012690: 02800004                 be      loc_F00126A0
F0012694: a4100008                 mov     %o0, %l2
F0012698: 900e607f                 and     %i1, 0x7F, %o0
F001269C: d02c2011                 stb     %o0, [%l0+0x11]
F00126A0: 80a66019                 cmp     %i1, 0x19
F00126A4: 34800003                 bg,a    loc_F00126B0
F00126A8: 92102001                 mov     1, %o1
F00126AC: 92102000                 mov     0, %o1
F00126B0: 40017989                 call    _assert_wait
F00126B4: 90100018                 mov     %i0, %o0
F00126B8: 80a66019                 cmp     %i1, 0x19
F00126BC: 04800054                 ble     loc_F001280C
F00126C0: 80a42000                 cmp     %l0, 0
F00126C4: 02800024                 be      loc_F0012754
F00126C8: 113c04d0                 sethi   %hi(_active_threads), %o0
F00126CC: d2022260                 ld      [%o0+%lo(_active_threads)], %o1
F00126D0: d002618c                 ld      [%o1+0x18C], %o0
F00126D4: 808a2003                 btst    3, %o0
F00126D8: 12800017                 bne     loc_F0012734
F00126DC: 113c04d0                 sethi   -0xFECC000, %o0
F00126E0: d0026084                 ld      [%o1+0x84], %o0
F00126E4: d2042018                 ld      [%l0+0x18], %o1
F00126E8: d002204c                 ld      [%o0+0x4C], %o0
F00126EC: 94924008                 orcc    %o1, %o0, %o2
F00126F0: 02800019                 be      loc_F0012754
F00126F4: 01000000                 nop
F00126F8: d0042028                 ld      [%l0+0x28], %o0
F00126FC: 808a2010                 btst    0x10, %o0
F0012700: 12800008                 bne     loc_F0012720
F0012704: 01000000                 nop
F0012708: d0042020                 ld      [%l0+0x20], %o0
F001270C: d204201c                 ld      [%l0+0x1C], %o1
F0012710: 90120009                 bset    %o1, %o0
F0012714: 80aa8008                 andncc  %o2, %o0, %g0
F0012718: 0280000f                 be      loc_F0012754
F001271C: 01000000                 nop
F0012720: 7ffffca4                 call    _issig
F0012724: 90102001                 mov     1, %o0
F0012728: 80a22000                 cmp     %o0, 0
F001272C: 0280000a                 be      loc_F0012754
F0012730: 113c04d0                 sethi   -0xFECC000, %o0
F0012734: d0022260                 ld      [%o0+0x260], %o0
F0012738: 92102002                 mov     2, %o1
F001273C: 400179bd                 call    _clear_wait
F0012740: 94102001                 mov     1, %o2
F0012744: 40021167                 call    _spl0
F0012748: 01000000                 nop
F001274C: 10800043                 ba      loc_F0012858
F0012750: 808e6100                 btst    0x100, %i1
F0012754: 40021163                 call    _spl0
F0012758: 01000000                 nop
F001275C: 113c04cf                 sethi   %hi(_active_u), %o0
F0012760: d40221d8                 ld      [%o0+%lo(_active_u)], %o2
F0012764: 113c04d0                 sethi   %hi(_master_cpu), %o0
F0012768: d20220c8                 ld      [%o0+%lo(_master_cpu)], %o1
F001276C: d002a1ac                 ld      [%o2+0x1AC], %o0
F0012770: 80a26000                 cmp     %o1, 0
F0012774: 90022001                 inc     %o0
F0012778: 02800005                 be      loc_F001278C
F001277C: d022a1ac                 st      %o0, [%o2+0x1AC]
F0012780: 113c042c                 sethi   %hi(aUnixSleepOnSla), %o0! "unix sleep: on slave?\n"
F0012784: 400007b5                 call    _printf
F0012788: 901222f0                 bset    %lo(aUnixSleepOnSla), %o0! "unix sleep: on slave?\n"
F001278C: 40017bed                 call    _thread_block_with_continuation
F0012790: 90102000                 mov     0, %o0
F0012794: 80a42000                 cmp     %l0, 0
F0012798: 0280002c                 be      loc_F0012848
F001279C: 113c04d0                 sethi   %hi(_active_threads), %o0
F00127A0: d2022260                 ld      [%o0+%lo(_active_threads)], %o1
F00127A4: d002618c                 ld      [%o1+0x18C], %o0
F00127A8: 808a2003                 btst    3, %o0
F00127AC: 1280002b                 bne     loc_F0012858
F00127B0: 808e6100                 btst    0x100, %i1
F00127B4: d0026084                 ld      [%o1+0x84], %o0
F00127B8: d2042018                 ld      [%l0+0x18], %o1
F00127BC: d002204c                 ld      [%o0+0x4C], %o0
F00127C0: 94924008                 orcc    %o1, %o0, %o2
F00127C4: 02800021                 be      loc_F0012848
F00127C8: 01000000                 nop
F00127CC: d0042028                 ld      [%l0+0x28], %o0
F00127D0: 808a2010                 btst    0x10, %o0
F00127D4: 12800008                 bne     loc_F00127F4
F00127D8: 01000000                 nop
F00127DC: d0042020                 ld      [%l0+0x20], %o0
F00127E0: d204201c                 ld      [%l0+0x1C], %o1
F00127E4: 90120009                 bset    %o1, %o0
F00127E8: 80aa8008                 andncc  %o2, %o0, %g0
F00127EC: 02800017                 be      loc_F0012848
F00127F0: 01000000                 nop
F00127F4: 7ffffc6f                 call    _issig
F00127F8: 90102001                 mov     1, %o0
F00127FC: 80a22000                 cmp     %o0, 0
F0012800: 12800016                 bne     loc_F0012858
F0012804: 808e6100                 btst    0x100, %i1
F0012808: 30800010                 ba,a    loc_F0012848
F001280C: 40021135                 call    _spl0
F0012810: 01000000                 nop
F0012814: d40461d8                 ld      [%l1+0x1D8], %o2
F0012818: 113c04d0                 sethi   %hi(_master_cpu), %o0
F001281C: d20220c8                 ld      [%o0+%lo(_master_cpu)], %o1! int
F0012820: d002a1ac                 ld      [%o2+0x1AC], %o0
F0012824: 80a26000                 cmp     %o1, 0
F0012828: 90022001                 inc     %o0
F001282C: 02800005                 be      loc_F0012840
F0012830: d022a1ac                 st      %o0, [%o2+0x1AC]
F0012834: 113c042c                 sethi   %hi(aUnixSleepOnSla_0), %o0! "unix sleep: on slave?\n"
F0012838: 40000788                 call    _printf
F001283C: 90122308                 bset    %lo(aUnixSleepOnSla_0), %o0! "unix sleep: on slave?\n"
F0012840: 40017bc0                 call    _thread_block_with_continuation
F0012844: 90102000                 mov     0, %o0
F0012848: 40021137                 call    _splx
F001284C: 90100012                 mov     %l2, %o0
F0012850: 10800008                 ba      locret_F0012870
F0012854: b0102000                 mov     0, %i0
F0012858: 12800006                 bne     locret_F0012870
F001285C: b0102001                 mov     1, %i0
F0012860: 113c04cf                 sethi   %hi(dword_F0133DDC), %o0
F0012864: d00221dc                 ld      [%o0+%lo(dword_F0133DDC)], %o0! jmp_buf
F0012868: 4002113f                 call    _longjmp
F001286C: 90022028                 inc     0x28, %o0 ! '('
F0012870: 81c7e008                 ret
F0012874: 81e80000                 restore
