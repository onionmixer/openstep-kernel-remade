F0074B48: 9de3bf98                 save    %sp, -0x68, %sp
F0074B4C: 113c04d0                 sethi   %hi(_active_threads), %o0
F0074B50: e4022260                 ld      [%o0+%lo(_active_threads)], %l2
F0074B54: 80a60012                 cmp     %i0, %l2
F0074B58: 12800006                 bne     loc_F0074B70
F0074B5C: 80a66000                 cmp     %i1, 0
F0074B60: 113c0442                 sethi   %hi(aThreadHaltTryi), %o0! "thread_halt: trying to halt current thr"...
F0074B64: 7ffe8183                 call    _panic
F0074B68: 901222f8                 bset    %lo(aThreadHaltTryi), %o0! "thread_halt: trying to halt current thr"...
F0074B6C: 80a66000                 cmp     %i1, 0
F0074B70: 1280004b                 bne     loc_F0074C9C
F0074B74: 01000000                 nop
F0074B78: 40008804                 call    _splusclock
F0074B7C: 01000000                 nop
F0074B80: 80a60012                 cmp     %i0, %l2
F0074B84: 1a800018                 bcc     loc_F0074BE4
F0074B88: a2100008                 mov     %o0, %l1
F0074B8C: a0062020                 add     %i0, 0x20, %l0 ! ' '
F0074B90: d0040000                 ld      [%l0], %o0
F0074B94: 80a22000                 cmp     %o0, 0
F0074B98: 12bffffe                 bne     loc_F0074B90
F0074B9C: 01000000                 nop
F0074BA0: 400088c2                 call    _simple_lock_try
F0074BA4: 90100010                 mov     %l0, %o0
F0074BA8: 80a22000                 cmp     %o0, 0
F0074BAC: 02bffff9                 be      loc_F0074B90
F0074BB0: 01000000                 nop
F0074BB4: a004a020                 add     %l2, 0x20, %l0 ! ' '
F0074BB8: d0040000                 ld      [%l0], %o0
F0074BBC: 80a22000                 cmp     %o0, 0
F0074BC0: 12bffffe                 bne     loc_F0074BB8
F0074BC4: 01000000                 nop
F0074BC8: 400088b8                 call    _simple_lock_try
F0074BCC: 90100010                 mov     %l0, %o0
F0074BD0: 80a22000                 cmp     %o0, 0
F0074BD4: 02bffff9                 be      loc_F0074BB8
F0074BD8: 01000000                 nop
F0074BDC: 10800017                 ba      loc_F0074C38
F0074BE0: d006204c                 ld      [%i0+0x4C], %o0
F0074BE4: a004a020                 add     %l2, 0x20, %l0 ! ' '
F0074BE8: d0040000                 ld      [%l0], %o0
F0074BEC: 80a22000                 cmp     %o0, 0
F0074BF0: 12bffffe                 bne     loc_F0074BE8
F0074BF4: 01000000                 nop
F0074BF8: 400088ac                 call    _simple_lock_try
F0074BFC: 90100010                 mov     %l0, %o0
F0074C00: 80a22000                 cmp     %o0, 0
F0074C04: 02bffff9                 be      loc_F0074BE8
F0074C08: 01000000                 nop
F0074C0C: a0062020                 add     %i0, 0x20, %l0 ! ' '
F0074C10: d0040000                 ld      [%l0], %o0
F0074C14: 80a22000                 cmp     %o0, 0
F0074C18: 12bffffe                 bne     loc_F0074C10
F0074C1C: 01000000                 nop
F0074C20: 400088a2                 call    _simple_lock_try
F0074C24: 90100010                 mov     %l0, %o0
F0074C28: 80a22000                 cmp     %o0, 0
F0074C2C: 02bffff9                 be      loc_F0074C10
F0074C30: 01000000                 nop
F0074C34: d006204c                 ld      [%i0+0x4C], %o0
F0074C38: 808a2010                 btst    0x10, %o0
F0074C3C: 22800009                 be,a    loc_F0074C60
F0074C40: d004a18c                 ld      [%l2+0x18C], %o0
F0074C44: d2062040                 ld      [%i0+0x40], %o1
F0074C48: 92026001                 inc     %o1
F0074C4C: d2262040                 st      %o1, [%i0+0x40]
F0074C50: c024a020                 clr     [%l2+0x20]
F0074C54: c0262020                 clr     [%i0+0x20]
F0074C58: 108000d0                 ba      loc_F0074F98
F0074C5C: 90100011                 mov     %l1, %o0
F0074C60: 808a2001                 btst    1, %o0
F0074C64: 0280000b                 be      loc_F0074C90
F0074C68: 9004a048                 add     %l2, 0x48, %o0 ! 'H'
F0074C6C: 92102000                 mov     0, %o1
F0074C70: 7ffff0e3                 call    _thread_wakeup_prim
F0074C74: 94102002                 mov     2, %o2
F0074C78: c0262020                 clr     [%i0+0x20]
F0074C7C: c024a020                 clr     [%l2+0x20]
F0074C80: 40008829                 call    _splx
F0074C84: 90100011                 mov     %l1, %o0
F0074C88: 108000c6                 ba      locret_F0074FA0
F0074C8C: b0102005                 mov     5, %i0
F0074C90: c024a020                 clr     [%l2+0x20]
F0074C94: 10800018                 ba      loc_F0074CF4
F0074C98: d0062040                 ld      [%i0+0x40], %o0
F0074C9C: 400087bb                 call    _splusclock
F0074CA0: a0062020                 add     %i0, 0x20, %l0 ! ' '
F0074CA4: a2100008                 mov     %o0, %l1
F0074CA8: d0040000                 ld      [%l0], %o0
F0074CAC: 80a22000                 cmp     %o0, 0
F0074CB0: 12bffffe                 bne     loc_F0074CA8
F0074CB4: 01000000                 nop
F0074CB8: 4000887c                 call    _simple_lock_try
F0074CBC: 90100010                 mov     %l0, %o0
F0074CC0: 80a22000                 cmp     %o0, 0
F0074CC4: 02bffff9                 be      loc_F0074CA8
F0074CC8: 01000000                 nop
F0074CCC: d006204c                 ld      [%i0+0x4C], %o0
F0074CD0: 808a2010                 btst    0x10, %o0
F0074CD4: 22800008                 be,a    loc_F0074CF4
F0074CD8: d0062040                 ld      [%i0+0x40], %o0
F0074CDC: c0262020                 clr     [%i0+0x20]
F0074CE0: d2062040                 ld      [%i0+0x40], %o1
F0074CE4: 90100011                 mov     %l1, %o0
F0074CE8: 92026001                 inc     %o1
F0074CEC: 108000ab                 ba      loc_F0074F98
F0074CF0: d2262040                 st      %o1, [%i0+0x40]
F0074CF4: d206204c                 ld      [%i0+0x4C], %o1
F0074CF8: 90022001                 inc     %o0
F0074CFC: d0262040                 st      %o0, [%i0+0x40]
F0074D00: 92126002                 bset    2, %o1
F0074D04: d006218c                 ld      [%i0+0x18C], %o0
F0074D08: 808a2001                 btst    1, %o0
F0074D0C: 02800028                 be      loc_F0074DAC
F0074D10: d226204c                 st      %o1, [%i0+0x4C]
F0074D14: 808a6010                 btst    0x10, %o1
F0074D18: 32800026                 bne,a   loc_F0074DB0
F0074D1C: d006218c                 ld      [%i0+0x18C], %o0
F0074D20: a6102001                 mov     1, %l3
F0074D24: 253c04d0                 sethi   -0xFECC000, %l2
F0074D28: e6262048                 st      %l3, [%i0+0x48]
F0074D2C: 90062048                 add     %i0, 0x48, %o0 ! 'H'
F0074D30: 92062020                 add     %i0, 0x20, %o1 ! ' '
F0074D34: 7ffff122                 call    _thread_sleep
F0074D38: 94102001                 mov     1, %o2
F0074D3C: d006204c                 ld      [%i0+0x4C], %o0
F0074D40: 808a2010                 btst    0x10, %o0
F0074D44: 12800094                 bne     loc_F0074F94
F0074D48: d004a260                 ld      [%l2+0x260], %o0
F0074D4C: d0022044                 ld      [%o0+0x44], %o0
F0074D50: 80a22000                 cmp     %o0, 0
F0074D54: 02800004                 be      loc_F0074D64
F0074D58: 80a66000                 cmp     %i1, 0
F0074D5C: 02800088                 be      loc_F0074F7C
F0074D60: 01000000                 nop
F0074D64: a0062020                 add     %i0, 0x20, %l0 ! ' '
F0074D68: d0040000                 ld      [%l0], %o0
F0074D6C: 80a22000                 cmp     %o0, 0
F0074D70: 12bffffe                 bne     loc_F0074D68
F0074D74: 01000000                 nop
F0074D78: 4000884c                 call    _simple_lock_try
F0074D7C: 90100010                 mov     %l0, %o0
F0074D80: 80a22000                 cmp     %o0, 0
F0074D84: 02bffff9                 be      loc_F0074D68
F0074D88: 01000000                 nop
F0074D8C: d006218c                 ld      [%i0+0x18C], %o0
F0074D90: 808a2001                 btst    1, %o0
F0074D94: 02800008                 be      loc_F0074DB4
F0074D98: 90122001                 bset    1, %o0
F0074D9C: d006204c                 ld      [%i0+0x4C], %o0
F0074DA0: 808a2010                 btst    0x10, %o0
F0074DA4: 22bfffe2                 be,a    loc_F0074D2C
F0074DA8: e6262048                 st      %l3, [%i0+0x48]
F0074DAC: d006218c                 ld      [%i0+0x18C], %o0
F0074DB0: 90122001                 bset    1, %o0
F0074DB4: d026218c                 st      %o0, [%i0+0x18C]
F0074DB8: c0262020                 clr     [%i0+0x20]
F0074DBC: 400087da                 call    _splx
F0074DC0: 90100011                 mov     %l1, %o0
F0074DC4: 90100018                 mov     %i0, %o0
F0074DC8: 4000013d                 call    _thread_dowait
F0074DCC: 92100019                 mov     %i1, %o1
F0074DD0: a4920000                 orcc    %o0, %g0, %l2
F0074DD4: 0280001b                 be      loc_F0074E40
F0074DD8: a0062020                 add     %i0, 0x20, %l0 ! ' '
F0074DDC: 4000876b                 call    _splusclock
F0074DE0: 01000000                 nop
F0074DE4: a2100008                 mov     %o0, %l1
F0074DE8: d0040000                 ld      [%l0], %o0
F0074DEC: 80a22000                 cmp     %o0, 0
F0074DF0: 12bffffe                 bne     loc_F0074DE8
F0074DF4: 01000000                 nop
F0074DF8: 4000882c                 call    _simple_lock_try
F0074DFC: 90100010                 mov     %l0, %o0
F0074E00: 80a22000                 cmp     %o0, 0
F0074E04: 02bffff9                 be      loc_F0074DE8
F0074E08: 90062048                 add     %i0, 0x48, %o0 ! 'H'
F0074E0C: 92102000                 mov     0, %o1
F0074E10: d606218c                 ld      [%i0+0x18C], %o3
F0074E14: 94102002                 mov     2, %o2
F0074E18: 960afffe                 and     %o3, -2, %o3
F0074E1C: 7ffff078                 call    _thread_wakeup_prim
F0074E20: d626218c                 st      %o3, [%i0+0x18C]
F0074E24: c0262020                 clr     [%i0+0x20]
F0074E28: 400087bf                 call    _splx
F0074E2C: 90100011                 mov     %l1, %o0
F0074E30: 40000181                 call    _thread_release
F0074E34: 90100018                 mov     %i0, %o0
F0074E38: 1080005a                 ba      locret_F0074FA0
F0074E3C: b0100012                 mov     %l2, %i0
F0074E40: 90100018                 mov     %i0, %o0
F0074E44: 92102002                 mov     2, %o1
F0074E48: 7fffeffa                 call    _clear_wait
F0074E4C: 94102001                 mov     1, %o2
F0074E50: d006204c                 ld      [%i0+0x4C], %o0
F0074E54: 808a2010                 btst    0x10, %o0
F0074E58: 32800052                 bne,a   locret_F0074FA0
F0074E5C: b0102000                 mov     0, %i0
F0074E60: d2062034                 ld      [%i0+0x34], %o1
F0074E64: 113c018490122088         set     _mach_msg_continue, %o0
F0074E6C: 80a24008                 cmp     %o1, %o0
F0074E70: 02800006                 be      loc_F0074E88
F0074E74: 113c017e                 sethi   %hi(_mach_msg_receive_continue), %o0
F0074E78: 90122380                 bset    %lo(_mach_msg_receive_continue), %o0
F0074E7C: 80a24008                 cmp     %o1, %o0
F0074E80: 12800008                 bne     loc_F0074EA0
F0074E84: 113c026f                 sethi   -0xFF64400, %o0
F0074E88: 7fffb0d4                 call    _mach_msg_interrupt
F0074E8C: 90100018                 mov     %i0, %o0
F0074E90: 80a22000                 cmp     %o0, 0
F0074E94: 1280000b                 bne     loc_F0074EC0
F0074E98: 113c026f                 sethi   -0xFF64400, %o0
F0074E9C: d2062034                 ld      [%i0+0x34], %o1
F0074EA0: 901223e4                 bset    0x3E4, %o0
F0074EA4: 80a24008                 cmp     %o1, %o0
F0074EA8: 02800006                 be      loc_F0074EC0
F0074EAC: 113c026f                 sethi   %hi(_thread_bootstrap_return), %o0
F0074EB0: 901223d0                 bset    %lo(_thread_bootstrap_return), %o0
F0074EB4: 80a24008                 cmp     %o1, %o0
F0074EB8: 12800017                 bne     loc_F0074F14
F0074EBC: 01000000                 nop
F0074EC0: 40008732                 call    _splusclock
F0074EC4: a0062020                 add     %i0, 0x20, %l0 ! ' '
F0074EC8: a2100008                 mov     %o0, %l1
F0074ECC: d0040000                 ld      [%l0], %o0
F0074ED0: 80a22000                 cmp     %o0, 0
F0074ED4: 12bffffe                 bne     loc_F0074ECC
F0074ED8: 01000000                 nop
F0074EDC: 400087f3                 call    _simple_lock_try
F0074EE0: 90100010                 mov     %l0, %o0
F0074EE4: 80a22000                 cmp     %o0, 0
F0074EE8: 02bffff9                 be      loc_F0074ECC
F0074EEC: 01000000                 nop
F0074EF0: c0262020                 clr     [%i0+0x20]
F0074EF4: d406204c                 ld      [%i0+0x4C], %o2
F0074EF8: 90100011                 mov     %l1, %o0
F0074EFC: d206218c                 ld      [%i0+0x18C], %o1
F0074F00: 9412a010                 bset    0x10, %o2
F0074F04: d426204c                 st      %o2, [%i0+0x4C]
F0074F08: 920a7ffe                 and     %o1, -2, %o1
F0074F0C: 10800023                 ba      loc_F0074F98
F0074F10: d226218c                 st      %o1, [%i0+0x18C]
F0074F14: 4000871d                 call    _splusclock
F0074F18: a0062020                 add     %i0, 0x20, %l0 ! ' '
F0074F1C: a2100008                 mov     %o0, %l1
F0074F20: d0040000                 ld      [%l0], %o0
F0074F24: 80a22000                 cmp     %o0, 0
F0074F28: 12bffffe                 bne     loc_F0074F20
F0074F2C: 01000000                 nop
F0074F30: 400087de                 call    _simple_lock_try
F0074F34: 90100010                 mov     %l0, %o0
F0074F38: 80a22000                 cmp     %o0, 0
F0074F3C: 02bffff9                 be      loc_F0074F20
F0074F40: 01000000                 nop
F0074F44: d006204c                 ld      [%i0+0x4C], %o0
F0074F48: 900a200f                 and     %o0, 0xF, %o0
F0074F4C: 80a22002                 cmp     %o0, 2
F0074F50: 02800004                 be      loc_F0074F60
F0074F54: 113c0442                 sethi   %hi(aThreadHalt), %o0! "thread_halt"
F0074F58: 7ffe8086                 call    _panic
F0074F5C: 90122328                 bset    %lo(aThreadHalt), %o0! "thread_halt"
F0074F60: 90100018                 mov     %i0, %o0
F0074F64: d406204c                 ld      [%i0+0x4C], %o2
F0074F68: 92102000                 mov     0, %o1
F0074F6C: 9412a00c                 bset    0xC, %o2
F0074F70: 7ffff34c                 call    _thread_setrun
F0074F74: d426204c                 st      %o2, [%i0+0x4C]
F0074F78: 30bfff90                 ba,a    loc_F0074DB8
F0074F7C: 4000876a                 call    _splx
F0074F80: 90100011                 mov     %l1, %o0
F0074F84: 4000012c                 call    _thread_release
F0074F88: 90100018                 mov     %i0, %o0
F0074F8C: 10800005                 ba      locret_F0074FA0
F0074F90: b0102005                 mov     5, %i0
F0074F94: 90100011                 mov     %l1, %o0
F0074F98: 40008763                 call    _splx
F0074F9C: b0102000                 mov     0, %i0
F0074FA0: 81c7e008                 ret
F0074FA4: 81e80000                 restore
