F0012A8C: 9de3bf98                 save    %sp, -0x68, %sp
F0012A90: 233c04cf                 sethi   %hi(_active_u), %l1
F0012A94: d00461d8                 ld      [%l1+%lo(_active_u)], %o0
F0012A98: 4002103c                 call    _splusclock
F0012A9C: e0020000                 ld      [%o0], %l0
F0012AA0: 80a42000                 cmp     %l0, 0
F0012AA4: 02800004                 be      loc_F0012AB4
F0012AA8: a4100008                 mov     %o0, %l2
F0012AAC: 900e607f                 and     %i1, 0x7F, %o0
F0012AB0: d02c2011                 stb     %o0, [%l0+0x11]
F0012AB4: 80a66019                 cmp     %i1, 0x19
F0012AB8: 34800003                 bg,a    loc_F0012AC4
F0012ABC: 92102001                 mov     1, %o1
F0012AC0: 92102000                 mov     0, %o1
F0012AC4: 40017884                 call    _assert_wait
F0012AC8: 90100018                 mov     %i0, %o0
F0012ACC: 80a66019                 cmp     %i1, 0x19
F0012AD0: 0480005b                 ble     loc_F0012C3C
F0012AD4: 80a42000                 cmp     %l0, 0
F0012AD8: 02800024                 be      loc_F0012B68
F0012ADC: 113c04d0                 sethi   %hi(_active_threads), %o0
F0012AE0: d2022260                 ld      [%o0+%lo(_active_threads)], %o1
F0012AE4: d002618c                 ld      [%o1+0x18C], %o0
F0012AE8: 808a2003                 btst    3, %o0
F0012AEC: 12800017                 bne     loc_F0012B48
F0012AF0: 113c04d0                 sethi   -0xFECC000, %o0
F0012AF4: d0026084                 ld      [%o1+0x84], %o0
F0012AF8: d2042018                 ld      [%l0+0x18], %o1
F0012AFC: d002204c                 ld      [%o0+0x4C], %o0
F0012B00: 94924008                 orcc    %o1, %o0, %o2
F0012B04: 0280001a                 be      loc_F0012B6C
F0012B08: 80a6e000                 cmp     %i3, 0
F0012B0C: d0042028                 ld      [%l0+0x28], %o0
F0012B10: 808a2010                 btst    0x10, %o0
F0012B14: 12800008                 bne     loc_F0012B34
F0012B18: 01000000                 nop
F0012B1C: d0042020                 ld      [%l0+0x20], %o0
F0012B20: d204201c                 ld      [%l0+0x1C], %o1
F0012B24: 90120009                 bset    %o1, %o0
F0012B28: 80aa8008                 andncc  %o2, %o0, %g0
F0012B2C: 02800010                 be      loc_F0012B6C
F0012B30: 80a6e000                 cmp     %i3, 0
F0012B34: 7ffffb9f                 call    _issig
F0012B38: 90102001                 mov     1, %o0
F0012B3C: 80a22000                 cmp     %o0, 0
F0012B40: 0280000a                 be      loc_F0012B68
F0012B44: 113c04d0                 sethi   -0xFECC000, %o0
F0012B48: d0022260                 ld      [%o0+0x260], %o0
F0012B4C: 92102002                 mov     2, %o1
F0012B50: 400178b8                 call    _clear_wait
F0012B54: 94102001                 mov     1, %o2
F0012B58: 40021062                 call    _spl0
F0012B5C: 01000000                 nop
F0012B60: 10800051                 ba      loc_F0012CA4
F0012B64: 80a6a000                 cmp     %i2, 0
F0012B68: 80a6e000                 cmp     %i3, 0
F0012B6C: 02800006                 be      loc_F0012B84
F0012B70: 01000000                 nop
F0012B74: 7fffdd3e                 call    _hzto
F0012B78: 9010001b                 mov     %i3, %o0
F0012B7C: 4001782d                 call    _thread_set_timeout
F0012B80: 01000000                 nop
F0012B84: 40021057                 call    _spl0
F0012B88: 01000000                 nop
F0012B8C: 113c04cf                 sethi   %hi(_active_u), %o0
F0012B90: d40221d8                 ld      [%o0+%lo(_active_u)], %o2
F0012B94: 113c04d0                 sethi   %hi(_master_cpu), %o0
F0012B98: d20220c8                 ld      [%o0+%lo(_master_cpu)], %o1
F0012B9C: d002a1ac                 ld      [%o2+0x1AC], %o0
F0012BA0: 80a26000                 cmp     %o1, 0
F0012BA4: 90022001                 inc     %o0
F0012BA8: 02800005                 be      loc_F0012BBC
F0012BAC: d022a1ac                 st      %o0, [%o2+0x1AC]
F0012BB0: 113c042c                 sethi   %hi(aUnixSleepOnSla), %o0! "unix sleep: on slave?\n"
F0012BB4: 400006a9                 call    _printf
F0012BB8: 901222f0                 bset    %lo(aUnixSleepOnSla), %o0! "unix sleep: on slave?\n"
F0012BBC: 40017ae1                 call    _thread_block_with_continuation
F0012BC0: 9010001a                 mov     %i2, %o0
F0012BC4: 80a42000                 cmp     %l0, 0
F0012BC8: 02800033                 be      loc_F0012C94
F0012BCC: 113c04d0                 sethi   %hi(_active_threads), %o0
F0012BD0: d2022260                 ld      [%o0+%lo(_active_threads)], %o1
F0012BD4: d002618c                 ld      [%o1+0x18C], %o0
F0012BD8: 808a2003                 btst    3, %o0
F0012BDC: 12800032                 bne     loc_F0012CA4
F0012BE0: 80a6a000                 cmp     %i2, 0
F0012BE4: d0026084                 ld      [%o1+0x84], %o0
F0012BE8: d2042018                 ld      [%l0+0x18], %o1
F0012BEC: d002204c                 ld      [%o0+0x4C], %o0
F0012BF0: 94924008                 orcc    %o1, %o0, %o2
F0012BF4: 02800028                 be      loc_F0012C94
F0012BF8: 01000000                 nop
F0012BFC: d0042028                 ld      [%l0+0x28], %o0
F0012C00: 808a2010                 btst    0x10, %o0
F0012C04: 12800008                 bne     loc_F0012C24
F0012C08: 01000000                 nop
F0012C0C: d0042020                 ld      [%l0+0x20], %o0
F0012C10: d204201c                 ld      [%l0+0x1C], %o1
F0012C14: 90120009                 bset    %o1, %o0
F0012C18: 80aa8008                 andncc  %o2, %o0, %g0
F0012C1C: 0280001e                 be      loc_F0012C94
F0012C20: 01000000                 nop
F0012C24: 7ffffb63                 call    _issig
F0012C28: 90102001                 mov     1, %o0
F0012C2C: 80a22000                 cmp     %o0, 0
F0012C30: 1280001d                 bne     loc_F0012CA4
F0012C34: 80a6a000                 cmp     %i2, 0
F0012C38: 30800017                 ba,a    loc_F0012C94
F0012C3C: 80a6e000                 cmp     %i3, 0
F0012C40: 02800006                 be      loc_F0012C58
F0012C44: 01000000                 nop
F0012C48: 7fffdd09                 call    _hzto
F0012C4C: 9010001b                 mov     %i3, %o0
F0012C50: 400177f8                 call    _thread_set_timeout
F0012C54: 01000000                 nop
F0012C58: 40021022                 call    _spl0
F0012C5C: 01000000                 nop
F0012C60: d40461d8                 ld      [%l1+0x1D8], %o2
F0012C64: 113c04d0                 sethi   %hi(_master_cpu), %o0
F0012C68: d20220c8                 ld      [%o0+%lo(_master_cpu)], %o1! int
F0012C6C: d002a1ac                 ld      [%o2+0x1AC], %o0
F0012C70: 80a26000                 cmp     %o1, 0
F0012C74: 90022001                 inc     %o0
F0012C78: 02800005                 be      loc_F0012C8C
F0012C7C: d022a1ac                 st      %o0, [%o2+0x1AC]
F0012C80: 113c042c                 sethi   %hi(aUnixSleepOnSla_0), %o0! "unix sleep: on slave?\n"
F0012C84: 40000675                 call    _printf
F0012C88: 90122308                 bset    %lo(aUnixSleepOnSla_0), %o0! "unix sleep: on slave?\n"
F0012C8C: 40017aad                 call    _thread_block_with_continuation
F0012C90: 9010001a                 mov     %i2, %o0
F0012C94: 40021024                 call    _splx
F0012C98: 90100012                 mov     %l2, %o0
F0012C9C: 1080000d                 ba      locret_F0012CD0
F0012CA0: b0102000                 mov     0, %i0
F0012CA4: 02800005                 be      loc_F0012CB8
F0012CA8: 808e6100                 btst    0x100, %i1
F0012CAC: 4002078e                 call    _call_continuation
F0012CB0: 9010001a                 mov     %i2, %o0
F0012CB4: 808e6100                 btst    0x100, %i1
F0012CB8: 12800006                 bne     locret_F0012CD0
F0012CBC: b0102001                 mov     1, %i0
F0012CC0: 113c04cf                 sethi   %hi(dword_F0133DDC), %o0
F0012CC4: d00221dc                 ld      [%o0+%lo(dword_F0133DDC)], %o0! jmp_buf
F0012CC8: 40021027                 call    _longjmp
F0012CCC: 90022028                 inc     0x28, %o0 ! '('
F0012CD0: 81c7e008                 ret
F0012CD4: 81e80000                 restore
