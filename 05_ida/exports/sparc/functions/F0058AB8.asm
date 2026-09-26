F0058AB8: 9de3bf98                 save    %sp, -0x68, %sp
F0058ABC: e407a05c                 ld      [%fp+arg_5C], %l2
F0058AC0: 80a72000                 cmp     %i4, 0
F0058AC4: e607a060                 ld      [%fp+arg_60], %l3
F0058AC8: 113c04d0                 sethi   %hi(_active_threads), %o0
F0058ACC: f8022260                 ld      [%o0+%lo(_active_threads)], %i4
F0058AD0: 1280003e                 bne     loc_F0058BC8
F0058AD4: a2062004                 add     %i0, 4, %l1
F0058AD8: e0044000                 ld      [%l1], %l0
F0058ADC: 80a42000                 cmp     %l0, 0
F0058AE0: 02800018                 be      loc_F0058B40
F0058AE4: 808e6100                 btst    0x100, %i1
F0058AE8: d0042018                 ld      [%l0+0x18], %o0
F0058AEC: 80a2001a                 cmp     %o0, %i2
F0058AF0: 28800007                 bleu,a  loc_F0058B0C
F0058AF4: d2040000                 ld      [%l0], %o1
F0058AF8: d0248000                 st      %o0, [%l2]
F0058AFC: c0260000                 clr     [%i0]
F0058B00: 31040010                 sethi   0x10004000, %i0
F0058B04: 10800098                 ba      locret_F0058D64
F0058B08: b0162004                 bset    4, %i0
F0058B0C: 80a24010                 cmp     %o1, %l0
F0058B10: 22800006                 be,a    loc_F0058B28
F0058B14: c0244000                 clr     [%l1]
F0058B18: d0042004                 ld      [%l0+4], %o0
F0058B1C: d2244000                 st      %o1, [%l1]
F0058B20: d0226004                 st      %o0, [%o1+4]
F0058B24: d2220000                 st      %o1, [%o0]
F0058B28: f204201c                 ld      [%l0+0x1C], %i1
F0058B2C: d2066034                 ld      [%i1+0x34], %o1
F0058B30: 90026001                 add     %o1, 1, %o0
F0058B34: d0266034                 st      %o0, [%i1+0x34]
F0058B38: 10800062                 ba      loc_F0058CC0
F0058B3C: a2100009                 mov     %o1, %l1
F0058B40: 0280000c                 be      loc_F0058B70
F0058B44: 80a6e000                 cmp     %i3, 0
F0058B48: 12800006                 bne     loc_F0058B60
F0058B4C: 9010001c                 mov     %i4, %o0
F0058B50: c0260000                 clr     [%i0]
F0058B54: 31040010                 sethi   0x10004000, %i0
F0058B58: 10800083                 ba      locret_F0058D64
F0058B5C: b0162003                 bset    3, %i0
F0058B60: 40003752                 call    _thread_will_wait_with_timeout
F0058B64: 9210001b                 mov     %i3, %o1
F0058B68: 10800005                 ba      loc_F0058B7C
F0058B6C: d2062008                 ld      [%i0+8], %o1
F0058B70: 40003739                 call    _thread_will_wait
F0058B74: 9010001c                 mov     %i4, %o0
F0058B78: d2062008                 ld      [%i0+8], %o1
F0058B7C: 80a26000                 cmp     %o1, 0
F0058B80: 22800007                 be,a    loc_F0058B9C
F0058B84: f8262008                 st      %i4, [%i0+8]
F0058B88: d0026094                 ld      [%o1+0x94], %o0
F0058B8C: d2272090                 st      %o1, [%i4+0x90]
F0058B90: d0272094                 st      %o0, [%i4+0x94]
F0058B94: f8226094                 st      %i4, [%o1+0x94]
F0058B98: f8222090                 st      %i4, [%o0+0x90]
F0058B9C: 1104001090122001         set     0x10004001, %o0
F0058BA4: d0272098                 st      %o0, [%i4+0x98]
F0058BA8: f427209c                 st      %i2, [%i4+0x9C]
F0058BAC: c0260000                 clr     [%i0]
F0058BB0: 80a76000                 cmp     %i5, 0
F0058BB4: 02800003                 be      loc_F0058BC0
F0058BB8: 90102000                 mov     0, %o0
F0058BBC: 9010001d                 mov     %i5, %o0
F0058BC0: 400062e0                 call    _thread_block_with_continuation
F0058BC4: 01000000                 nop
F0058BC8: d0060000                 ld      [%i0], %o0
F0058BCC: 80a22000                 cmp     %o0, 0
F0058BD0: 12bffffe                 bne     loc_F0058BC8
F0058BD4: 01000000                 nop
F0058BD8: 4000f8b4                 call    _simple_lock_try
F0058BDC: 90100018                 mov     %i0, %o0
F0058BE0: 80a22000                 cmp     %o0, 0
F0058BE4: 02bffff9                 be      loc_F0058BC8
F0058BE8: 01000000                 nop
F0058BEC: d2072098                 ld      [%i4+0x98], %o1
F0058BF0: 80a26000                 cmp     %o1, 0
F0058BF4: 12800006                 bne     loc_F0058C0C
F0058BF8: 11040010                 sethi   0x10004000, %o0
F0058BFC: e007209c                 ld      [%i4+0x9C], %l0
F0058C00: e20720a0                 ld      [%i4+0xA0], %l1
F0058C04: 1080002f                 ba      loc_F0058CC0
F0058C08: f204201c                 ld      [%l0+0x1C], %i1
F0058C0C: 90122004                 bset    4, %o0
F0058C10: 80a24008                 cmp     %o1, %o0
F0058C14: 22800014                 be,a    loc_F0058C64
F0058C18: d007209c                 ld      [%i4+0x9C], %o0
F0058C1C: 14800009                 bg      loc_F0058C40
F0058C20: 11040010                 sethi   0x10004000, %o0
F0058C24: 1104001090122001         set     0x10004001, %o0
F0058C2C: 80a24008                 cmp     %o1, %o0
F0058C30: 02800011                 be      loc_F0058C74
F0058C34: 90062008                 add     %i0, 8, %o0
F0058C38: 1080001e                 ba      loc_F0058CB0
F0058C3C: 113c043d                 sethi   -0xFEF0C00, %o0
F0058C40: 90122006                 bset    6, %o0
F0058C44: 80a24008                 cmp     %o1, %o0
F0058C48: 02800008                 be      loc_F0058C68
F0058C4C: 11040010                 sethi   0x10004000, %o0
F0058C50: 90122009                 bset    9, %o0
F0058C54: 80a24008                 cmp     %o1, %o0
F0058C58: 02800004                 be      loc_F0058C68
F0058C5C: 113c043d                 sethi   -0xFEF0C00, %o0
F0058C60: 30800014                 ba,a    loc_F0058CB0
F0058C64: d0248000                 st      %o0, [%l2]
F0058C68: c0260000                 clr     [%i0]
F0058C6C: 1080003e                 ba      locret_F0058D64
F0058C70: f0072098                 ld      [%i4+0x98], %i0
F0058C74: 40001867                 call    _ipc_thread_rmqueue
F0058C78: 9210001c                 mov     %i4, %o1
F0058C7C: d0072044                 ld      [%i4+0x44], %o0! char *
F0058C80: 80a22001                 cmp     %o0, 1
F0058C84: 22bfff95                 be,a    loc_F0058AD8
F0058C88: b6102000                 mov     0, %i3
F0058C8C: 26bfff94                 bl,a    loc_F0058ADC
F0058C90: e0044000                 ld      [%l1], %l0
F0058C94: 80a22003                 cmp     %o0, 3
F0058C98: 34bfff91                 bg,a    loc_F0058ADC
F0058C9C: e0044000                 ld      [%l1], %l0
F0058CA0: c0260000                 clr     [%i0]
F0058CA4: 31040010                 sethi   0x10004000, %i0
F0058CA8: 1080002f                 ba      locret_F0058D64
F0058CAC: b0162005                 bset    5, %i0
F0058CB0: 7ffef130                 call    _panic
F0058CB4: 90122040                 bset    0x40, %o0 ! '@'
F0058CB8: 10bfff89                 ba      loc_F0058ADC
F0058CBC: e0044000                 ld      [%l1], %l0
F0058CC0: c0260000                 clr     [%i0]
F0058CC4: d004200c                 ld      [%l0+0xC], %o0
F0058CC8: 80a22000                 cmp     %o0, 0
F0058CCC: 02800005                 be      loc_F0058CE0
F0058CD0: 01000000                 nop
F0058CD4: 7ffffd1a                 call    _ipc_marequest_destroy
F0058CD8: 01000000                 nop
F0058CDC: c024200c                 clr     [%l0+0xC]
F0058CE0: d0064000                 ld      [%i1], %o0
F0058CE4: 80a22000                 cmp     %o0, 0
F0058CE8: 12bffffe                 bne     loc_F0058CE0
F0058CEC: 01000000                 nop
F0058CF0: 4000f86e                 call    _simple_lock_try
F0058CF4: 90100019                 mov     %i1, %o0
F0058CF8: 80a22000                 cmp     %o0, 0
F0058CFC: 02bffff9                 be      loc_F0058CE0
F0058D00: 01000000                 nop
F0058D04: d0066008                 ld      [%i1+8], %o0
F0058D08: 80a22000                 cmp     %o0, 0
F0058D0C: 16800012                 bge     loc_F0058D54
F0058D10: 9406604c                 add     %i1, 0x4C, %o2 ! 'L'
F0058D14: d0066038                 ld      [%i1+0x38], %o0
F0058D18: f006604c                 ld      [%i1+0x4C], %i0
F0058D1C: 92023fff                 add     %o0, -1, %o1
F0058D20: 80a62000                 cmp     %i0, 0
F0058D24: 0280000c                 be      loc_F0058D54
F0058D28: d2266038                 st      %o1, [%i1+0x38]
F0058D2C: d006603c                 ld      [%i1+0x3C], %o0
F0058D30: 80a24008                 cmp     %o1, %o0
F0058D34: 1a800008                 bcc     loc_F0058D54
F0058D38: 01000000                 nop
F0058D3C: 9010000a                 mov     %o2, %o0
F0058D40: 40001834                 call    _ipc_thread_rmqueue
F0058D44: 92100018                 mov     %i0, %o1
F0058D48: c0262098                 clr     [%i0+0x98]
F0058D4C: 40003632                 call    _thread_go
F0058D50: 90100018                 mov     %i0, %o0
F0058D54: c0264000                 clr     [%i1]
F0058D58: e0248000                 st      %l0, [%l2]
F0058D5C: e224c000                 st      %l1, [%l3]
F0058D60: b0102000                 mov     0, %i0
F0058D64: 81c7e008                 ret
F0058D68: 81e80000                 restore
