F005FD98: 9de3bf60                 save    %sp, -0xA0, %sp
F005FD9C: 80a66003                 cmp     %i1, 3
F005FDA0: 1280040c                 bne     loc_F0060DD0
F005FDA4: f027bfcc                 st      %i0, [%fp+var_34]
F005FDA8: 113c04d0                 sethi   %hi(_active_threads), %o0
F005FDAC: ec022260                 ld      [%o0+%lo(_active_threads)], %l6
F005FDB0: d005a00c                 ld      [%l6+0xC], %o0
F005FDB4: f0022088                 ld      [%o0+0x88], %i0
F005FDB8: 9006bfe8                 add     %i2, -0x18, %o0
F005FDBC: 80a220d4                 cmp     %o0, 0xD4
F005FDC0: 188002d2                 bgu     loc_F0060908
F005FDC4: 808ea003                 btst    3, %i2
F005FDC8: 128002d1                 bne     loc_F006090C
F005FDCC: d007bfcc                 ld      [%fp+var_34], %o0
F005FDD0: 113c04ef                 sethi   %hi(_ipc_kmsg_cache), %o0
F005FDD4: e8022348                 ld      [%o0+%lo(_ipc_kmsg_cache)], %l4
F005FDD8: 80a52000                 cmp     %l4, 0
F005FDDC: 028002cb                 be      loc_F0060908
F005FDE0: 92052014                 add     %l4, 0x14, %o1
F005FDE4: c0222348                 clr     [%o0+%lo(_ipc_kmsg_cache)]
F005FDE8: c0252010                 clr     [%l4+0x10]
F005FDEC: d007bfcc                 ld      [%fp+var_34], %o0
F005FDF0: 4000e0b0                 call    _copyinmsg
F005FDF4: 9410001a                 mov     %i2, %o2
F005FDF8: 80a22000                 cmp     %o0, 0
F005FDFC: 2280000a                 be,a    loc_F005FE24
F005FE00: c0252010                 clr     [%l4+0x10]
F005FE04: d2052008                 ld      [%l4+8], %o1
F005FE08: 80a26000                 cmp     %o1, 0
F005FE0C: 148002bd                 bg      loc_F0060900
F005FE10: 01000000                 nop
F005FE14: 7fffd4fb                 call    _ipc_kmsg_free
F005FE18: 90100014                 mov     %l4, %o0
F005FE1C: 108002bc                 ba      loc_F006090C
F005FE20: d007bfcc                 ld      [%fp+var_34], %o0
F005FE24: f4252018                 st      %i2, [%l4+0x18]
F005FE28: d2052014                 ld      [%l4+0x14], %o1
F005FE2C: 80a26012                 cmp     %o1, 0x12
F005FE30: 0280007c                 be      loc_F0060020
F005FE34: 11000005                 sethi   0x1400, %o0
F005FE38: 90122113                 bset    0x113, %o0
F005FE3C: 80a24008                 cmp     %o1, %o0
F005FE40: 128002c1                 bne     loc_F0060944
F005FE44: 113c04d0                 sethi   -0xFECC000, %o0
F005FE48: d0052020                 ld      [%l4+0x20], %o0
F005FE4C: 80a2001c                 cmp     %o0, %i4
F005FE50: 128002bd                 bne     loc_F0060944
F005FE54: 113c04d0                 sethi   -0xFECC000, %o0
F005FE58: a3372008                 srl     %i4, 8, %l1
F005FE5C: a52f2018                 sll     %i4, 24, %l2
F005FE60: a0062008                 add     %i0, 8, %l0
F005FE64: d0040000                 ld      [%l0], %o0
F005FE68: 80a22000                 cmp     %o0, 0
F005FE6C: 12bffffe                 bne     loc_F005FE64
F005FE70: 01000000                 nop
F005FE74: 4000dc0d                 call    _simple_lock_try
F005FE78: 90100010                 mov     %l0, %o0
F005FE7C: 80a22000                 cmp     %o0, 0
F005FE80: 02bffff9                 be      loc_F005FE64
F005FE84: 01000000                 nop
F005FE88: d8062018                 ld      [%i0+0x18], %o4
F005FE8C: 80a4400c                 cmp     %l1, %o4
F005FE90: 1a8000d9                 bcc     loc_F00601F4
F005FE94: d6062014                 ld      [%i0+0x14], %o3
F005FE98: 952c6004                 sll     %l1, 4, %o2
F005FE9C: d202c00a                 ld      [%o3+%o2], %o1
F005FEA0: 113fc080                 sethi   -0xFE0000, %o0
F005FEA4: 920a4008                 and     %o1, %o0, %o1
F005FEA8: 1100008090148008         set     0x20000, %o0
F005FEB0: 80a24008                 cmp     %o1, %o0
F005FEB4: 128000d0                 bne     loc_F00601F4
F005FEB8: 9202c00a                 add     %o3, %o2, %o1
F005FEBC: d005201c                 ld      [%l4+0x1C], %o0
F005FEC0: e0026004                 ld      [%o1+4], %l0
F005FEC4: 95322008                 srl     %o0, 8, %o2
F005FEC8: 80a2800c                 cmp     %o2, %o4
F005FECC: 1a8000ca                 bcc     loc_F00601F4
F005FED0: 992a2018                 sll     %o0, 24, %o4
F005FED4: 952aa004                 sll     %o2, 4, %o2
F005FED8: d202c00a                 ld      [%o3+%o2], %o1
F005FEDC: 113fc040                 sethi   -0xFF0000, %o0
F005FEE0: 920a4008                 and     %o1, %o0, %o1
F005FEE4: 1100004090130008         set     0x10000, %o0
F005FEEC: 80a24008                 cmp     %o1, %o0
F005FEF0: 128000c1                 bne     loc_F00601F4
F005FEF4: 9002c00a                 add     %o3, %o2, %o0
F005FEF8: e2022004                 ld      [%o0+4], %l1
F005FEFC: d0044000                 ld      [%l1], %o0
F005FF00: 80a22000                 cmp     %o0, 0
F005FF04: 12bffffe                 bne     loc_F005FEFC
F005FF08: 01000000                 nop
F005FF0C: 4000dbe7                 call    _simple_lock_try
F005FF10: 90100011                 mov     %l1, %o0
F005FF14: 80a22000                 cmp     %o0, 0
F005FF18: 02bffff9                 be      loc_F005FEFC
F005FF1C: 01000000                 nop
F005FF20: d0046008                 ld      [%l1+8], %o0
F005FF24: 80a22000                 cmp     %o0, 0
F005FF28: 1680006e                 bge     loc_F00600E0
F005FF2C: 01000000                 nop
F005FF30: 4000dbde                 call    _simple_lock_try
F005FF34: 90100010                 mov     %l0, %o0
F005FF38: 80a22000                 cmp     %o0, 0
F005FF3C: 02800069                 be      loc_F00600E0
F005FF40: 01000000                 nop
F005FF44: c0262008                 clr     [%i0+8]
F005FF48: d004601c                 ld      [%l1+0x1C], %o0
F005FF4C: 90022001                 inc     %o0
F005FF50: d024601c                 st      %o0, [%l1+0x1C]
F005FF54: d0046004                 ld      [%l1+4], %o0
F005FF58: 90022001                 inc     %o0
F005FF5C: d0246004                 st      %o0, [%l1+4]
F005FF60: d0042020                 ld      [%l0+0x20], %o0
F005FF64: 90022001                 inc     %o0
F005FF68: d0242020                 st      %o0, [%l0+0x20]
F005FF6C: d0042004                 ld      [%l0+4], %o0
F005FF70: 90022001                 inc     %o0
F005FF74: d0242004                 st      %o0, [%l0+4]
F005FF78: 1100000490122211         set     0x1211, %o0
F005FF80: d0252014                 st      %o0, [%l4+0x14]
F005FF84: e225201c                 st      %l1, [%l4+0x1C]
F005FF88: e0252020                 st      %l0, [%l4+0x20]
F005FF8C: d204600c                 ld      [%l1+0xC], %o1
F005FF90: 113c04ef                 sethi   %hi(_ipc_space_kernel), %o0
F005FF94: d0022330                 ld      [%o0+%lo(_ipc_space_kernel)], %o0
F005FF98: 80a24008                 cmp     %o1, %o0
F005FF9C: 32800005                 bne,a   loc_F005FFB0
F005FFA0: d2046038                 ld      [%l1+0x38], %o1
F005FFA4: c0240000                 clr     [%l0]
F005FFA8: c0244000                 clr     [%l1]
F005FFAC: 308002c9                 ba,a    loc_F0060AD0
F005FFB0: d004603c                 ld      [%l1+0x3C], %o0
F005FFB4: 80a24008                 cmp     %o1, %o0
F005FFB8: 1a800016                 bcc     loc_F0060010
F005FFBC: 01000000                 nop
F005FFC0: d0042030                 ld      [%l0+0x30], %o0
F005FFC4: 80a22000                 cmp     %o0, 0
F005FFC8: 12800012                 bne     loc_F0060010
F005FFCC: a4100010                 mov     %l0, %l2
F005FFD0: d004a004                 ld      [%l2+4], %o0
F005FFD4: 90022001                 inc     %o0
F005FFD8: d024a004                 st      %o0, [%l2+4]
F005FFDC: a604a040                 add     %l2, 0x40, %l3 ! '@'
F005FFE0: d004c000                 ld      [%l3], %o0
F005FFE4: 80a22000                 cmp     %o0, 0
F005FFE8: 12bffffe                 bne     loc_F005FFE0
F005FFEC: 01000000                 nop
F005FFF0: 4000dbae                 call    _simple_lock_try
F005FFF4: 90100013                 mov     %l3, %o0
F005FFF8: 80a22000                 cmp     %o0, 0
F005FFFC: 02bffff9                 be      loc_F005FFE0
F0060000: 01000000                 nop
F0060004: c0248000                 clr     [%l2]
F0060008: 10800082                 ba      loc_F0060210
F006000C: d0046030                 ld      [%l1+0x30], %o0
F0060010: c0244000                 clr     [%l1]
F0060014: c0240000                 clr     [%l0]
F0060018: 108002f9                 ba      loc_F0060BFC
F006001C: 90100014                 mov     %l4, %o0
F0060020: d0052020                 ld      [%l4+0x20], %o0
F0060024: 80a22000                 cmp     %o0, 0
F0060028: 12800247                 bne     loc_F0060944
F006002C: 113c04d0                 sethi   -0xFECC000, %o0
F0060030: a0062008                 add     %i0, 8, %l0
F0060034: d0040000                 ld      [%l0], %o0
F0060038: 80a22000                 cmp     %o0, 0
F006003C: 12bffffe                 bne     loc_F0060034
F0060040: 01000000                 nop
F0060044: 4000db99                 call    _simple_lock_try
F0060048: 90100010                 mov     %l0, %o0
F006004C: 80a22000                 cmp     %o0, 0
F0060050: 02bffff9                 be      loc_F0060034
F0060054: 01000000                 nop
F0060058: d005201c                 ld      [%l4+0x1C], %o0
F006005C: ee062018                 ld      [%i0+0x18], %l7
F0060060: e4062014                 ld      [%i0+0x14], %l2
F0060064: a7322008                 srl     %o0, 8, %l3
F0060068: 80a4c017                 cmp     %l3, %l7
F006006C: 1a800062                 bcc     loc_F00601F4
F0060070: ab2a2018                 sll     %o0, 24, %l5
F0060074: 952ce004                 sll     %l3, 4, %o2
F0060078: d204800a                 ld      [%l2+%o2], %o1
F006007C: 113fe100                 sethi   -0x7C0000, %o0
F0060080: 920a4008                 and     %o1, %o0, %o1
F0060084: 1100010090154008         set     0x40000, %o0
F006008C: 80a24008                 cmp     %o1, %o0
F0060090: 12800059                 bne     loc_F00601F4
F0060094: a004800a                 add     %l2, %o2, %l0
F0060098: d0042008                 ld      [%l0+8], %o0
F006009C: 80a22000                 cmp     %o0, 0
F00600A0: 12800055                 bne     loc_F00601F4
F00600A4: 01000000                 nop
F00600A8: e2042004                 ld      [%l0+4], %l1
F00600AC: d0044000                 ld      [%l1], %o0
F00600B0: 80a22000                 cmp     %o0, 0
F00600B4: 12bffffe                 bne     loc_F00600AC
F00600B8: 01000000                 nop
F00600BC: 4000db7b                 call    _simple_lock_try
F00600C0: 90100011                 mov     %l1, %o0
F00600C4: 80a22000                 cmp     %o0, 0
F00600C8: 02bffff9                 be      loc_F00600AC
F00600CC: 01000000                 nop
F00600D0: d0046008                 ld      [%l1+8], %o0
F00600D4: 80a22000                 cmp     %o0, 0
F00600D8: 26800004                 bl,a    loc_F00600E8
F00600DC: d004a008                 ld      [%l2+8], %o0
F00600E0: c0244000                 clr     [%l1]
F00600E4: 30800044                 ba,a    loc_F00601F4
F00600E8: 93372008                 srl     %i4, 8, %o1
F00600EC: 80a24017                 cmp     %o1, %l7
F00600F0: 972f2018                 sll     %i4, 24, %o3
F00600F4: d0242008                 st      %o0, [%l0+8]
F00600F8: e624a008                 st      %l3, [%l2+8]
F00600FC: ea240000                 st      %l5, [%l0]
F0060100: c0242004                 clr     [%l0+4]
F0060104: 90102012                 mov     0x12, %o0
F0060108: d0252014                 st      %o0, [%l4+0x14]
F006010C: 1a80003d                 bcc     loc_F0060200
F0060110: e225201c                 st      %l1, [%l4+0x1C]
F0060114: 932a6004                 sll     %o1, 4, %o1
F0060118: d4048009                 ld      [%l2+%o1], %o2
F006011C: 113fc000                 sethi   -0x1000000, %o0
F0060120: 900a8008                 and     %o2, %o0, %o0
F0060124: 80a2000b                 cmp     %o0, %o3
F0060128: 12800036                 bne     loc_F0060200
F006012C: 92048009                 add     %l2, %o1, %o1
F0060130: 11000200                 sethi   0x80000, %o0
F0060134: 808a8008                 btst    %o0, %o2
F0060138: 0280000f                 be      loc_F0060174
F006013C: 11000080                 sethi   0x20000, %o0
F0060140: e0026004                 ld      [%o1+4], %l0
F0060144: d0040000                 ld      [%l0], %o0
F0060148: 80a22000                 cmp     %o0, 0
F006014C: 12bffffe                 bne     loc_F0060144
F0060150: 01000000                 nop
F0060154: 4000db55                 call    _simple_lock_try
F0060158: 90100010                 mov     %l0, %o0
F006015C: 80a22000                 cmp     %o0, 0
F0060160: 02bffff9                 be      loc_F0060144
F0060164: 01000000                 nop
F0060168: a4100010                 mov     %l0, %l2
F006016C: 10800012                 ba      loc_F00601B4
F0060170: a604a010                 add     %l2, 0x10, %l3
F0060174: 808a8008                 btst    %o0, %o2
F0060178: 02800022                 be      loc_F0060200
F006017C: 01000000                 nop
F0060180: e0026004                 ld      [%o1+4], %l0
F0060184: 4000db49                 call    _simple_lock_try
F0060188: 90100010                 mov     %l0, %o0
F006018C: 80a22000                 cmp     %o0, 0
F0060190: 0280001c                 be      loc_F0060200
F0060194: 01000000                 nop
F0060198: d0042030                 ld      [%l0+0x30], %o0
F006019C: 80a22000                 cmp     %o0, 0
F00601A0: 02800004                 be      loc_F00601B0
F00601A4: a4100010                 mov     %l0, %l2
F00601A8: c0240000                 clr     [%l0]
F00601AC: 30800015                 ba,a    loc_F0060200
F00601B0: a604a040                 add     %l2, 0x40, %l3 ! '@'
F00601B4: c0262008                 clr     [%i0+8]
F00601B8: d004a004                 ld      [%l2+4], %o0
F00601BC: 90022001                 inc     %o0
F00601C0: d024a004                 st      %o0, [%l2+4]
F00601C4: d004c000                 ld      [%l3], %o0
F00601C8: 80a22000                 cmp     %o0, 0
F00601CC: 12bffffe                 bne     loc_F00601C4
F00601D0: 01000000                 nop
F00601D4: 4000db35                 call    _simple_lock_try
F00601D8: 90100013                 mov     %l3, %o0
F00601DC: 80a22000                 cmp     %o0, 0
F00601E0: 02bffff9                 be      loc_F00601C4
F00601E4: 01000000                 nop
F00601E8: c0248000                 clr     [%l2]
F00601EC: 10800009                 ba      loc_F0060210
F00601F0: d0046030                 ld      [%l1+0x30], %o0
F00601F4: c0262008                 clr     [%i0+8]
F00601F8: 108001d3                 ba      loc_F0060944
F00601FC: 113c04d0                 sethi   -0xFECC000, %o0
F0060200: c0244000                 clr     [%l1]
F0060204: c0262008                 clr     [%i0+8]
F0060208: 1080027d                 ba      loc_F0060BFC
F006020C: 90100014                 mov     %l4, %o0
F0060210: 80a22000                 cmp     %o0, 0
F0060214: 12800003                 bne     loc_F0060220
F0060218: aa022010                 add     %o0, 0x10, %l5
F006021C: aa046040                 add     %l1, 0x40, %l5 ! '@'
F0060220: 4000db22                 call    _simple_lock_try
F0060224: 90100015                 mov     %l5, %o0
F0060228: 80a22000                 cmp     %o0, 0
F006022C: 32800008                 bne,a   loc_F006024C
F0060230: e0056008                 ld      [%l5+8], %l0
F0060234: c0244000                 clr     [%l1]
F0060238: c024c000                 clr     [%l3]
F006023C: 7fffe50d                 call    _ipc_object_release
F0060240: 90100012                 mov     %l2, %o0
F0060244: 1080026e                 ba      loc_F0060BFC
F0060248: 90100014                 mov     %l4, %o0
F006024C: 80a42000                 cmp     %l0, 0
F0060250: 0280007f                 be      loc_F006044C
F0060254: 01000000                 nop
F0060258: d004e004                 ld      [%l3+4], %o0
F006025C: 80a22000                 cmp     %o0, 0
F0060260: 22800003                 be,a    loc_F006026C
F0060264: f625a0cc                 st      %i3, [%l6+0xCC]
F0060268: 30800079                 ba,a    loc_F006044C
F006026C: e425a0d8                 st      %l2, [%l6+0xD8]
F0060270: e625a0dc                 st      %l3, [%l6+0xDC]
F0060274: c607bfcc                 ld      [%fp+var_34], %g3
F0060278: 113c0184                 sethi   %hi(_mach_msg_continue), %o0
F006027C: c625a0c4                 st      %g3, [%l6+0xC4]
F0060280: d2042034                 ld      [%l0+0x34], %o1
F0060284: ae122088                 or      %o0, %lo(_mach_msg_continue), %l7
F0060288: 80a24017                 cmp     %o1, %l7
F006028C: 1280000a                 bne     loc_F00602B4
F0060290: 113c0192                 sethi   -0xFF9B800, %o0
F0060294: 90100016                 mov     %l6, %o0
F0060298: 92100017                 mov     %l7, %o1
F006029C: 400019a7                 call    _thread_handoff
F00602A0: 94100010                 mov     %l0, %o2
F00602A4: 80a22000                 cmp     %o0, 0
F00602A8: 1280006b                 bne     loc_F0060454
F00602AC: 113c0192                 sethi   -0xFF9B800, %o0
F00602B0: d2042034                 ld      [%l0+0x34], %o1
F00602B4: 901220e8                 bset    0xE8, %o0
F00602B8: 80a24008                 cmp     %o1, %o0
F00602BC: 32800028                 bne,a   loc_F006035C
F00602C0: d004209c                 ld      [%l0+0x9C], %o0
F00602C4: 90100016                 mov     %l6, %o0
F00602C8: 92100017                 mov     %l7, %o1
F00602CC: 4000199b                 call    _thread_handoff
F00602D0: 94100010                 mov     %l0, %o2
F00602D4: 80a22000                 cmp     %o0, 0
F00602D8: 22800021                 be,a    loc_F006035C
F00602DC: d004209c                 ld      [%l0+0x9C], %o0
F00602E0: d204e008                 ld      [%l3+8], %o1
F00602E4: 80a26000                 cmp     %o1, 0
F00602E8: 22800007                 be,a    loc_F0060304
F00602EC: ec24e008                 st      %l6, [%l3+8]
F00602F0: d0026094                 ld      [%o1+0x94], %o0
F00602F4: d225a090                 st      %o1, [%l6+0x90]
F00602F8: d025a094                 st      %o0, [%l6+0x94]
F00602FC: ec226094                 st      %l6, [%o1+0x94]
F0060300: ec222090                 st      %l6, [%o0+0x90]
F0060304: 1104001090122001         set     0x10004001, %o0
F006030C: d025a098                 st      %o0, [%l6+0x98]
F0060310: 90103fff                 mov     -1, %o0
F0060314: d025a09c                 st      %o0, [%l6+0x9C]
F0060318: c024c000                 clr     [%l3]
F006031C: d2042090                 ld      [%l0+0x90], %o1
F0060320: 80a24010                 cmp     %o1, %l0
F0060324: 22800008                 be,a    loc_F0060344
F0060328: c0256008                 clr     [%l5+8]
F006032C: d0042094                 ld      [%l0+0x94], %o0
F0060330: d2256008                 st      %o1, [%l5+8]
F0060334: d0226094                 st      %o0, [%o1+0x94]
F0060338: d2222090                 st      %o1, [%o0+0x90]
F006033C: e0242090                 st      %l0, [%l0+0x90]
F0060340: e0242094                 st      %l0, [%l0+0x94]
F0060344: c0254000                 clr     [%l5]
F0060348: 90100011                 mov     %l1, %o0
F006034C: 40001209                 call    _exception_raise_continue_fast
F0060350: 92100014                 mov     %l4, %o1
F0060354: 1080034b                 ba      locret_F0061080
F0060358: b0102000                 mov     0, %i0
F006035C: 80a68008                 cmp     %i2, %o0
F0060360: 1880003b                 bgu     loc_F006044C
F0060364: 90100016                 mov     %l6, %o0
F0060368: 133c018492126088         set     _mach_msg_continue, %o1
F0060370: 40001972                 call    _thread_handoff
F0060374: 94100010                 mov     %l0, %o2
F0060378: 80a22000                 cmp     %o0, 0
F006037C: 02800034                 be      loc_F006044C
F0060380: 113c017e                 sethi   %hi(_mach_msg_receive_continue), %o0
F0060384: d2042034                 ld      [%l0+0x34], %o1
F0060388: 90122380                 bset    %lo(_mach_msg_receive_continue), %o0
F006038C: 80a24008                 cmp     %o1, %o0
F0060390: 32800007                 bne,a   loc_F00603AC
F0060394: d0046038                 ld      [%l1+0x38], %o0
F0060398: d00420c8                 ld      [%l0+0xC8], %o0
F006039C: 808a2200                 btst    0x200, %o0
F00603A0: 0280002d                 be      loc_F0060454
F00603A4: 01000000                 nop
F00603A8: d0046038                 ld      [%l1+0x38], %o0
F00603AC: c0244000                 clr     [%l1]
F00603B0: 90022001                 inc     %o0
F00603B4: d0246038                 st      %o0, [%l1+0x38]
F00603B8: d204e008                 ld      [%l3+8], %o1
F00603BC: 80a26000                 cmp     %o1, 0
F00603C0: 22800007                 be,a    loc_F00603DC
F00603C4: ec24e008                 st      %l6, [%l3+8]
F00603C8: d0026094                 ld      [%o1+0x94], %o0
F00603CC: d225a090                 st      %o1, [%l6+0x90]
F00603D0: d025a094                 st      %o0, [%l6+0x94]
F00603D4: ec226094                 st      %l6, [%o1+0x94]
F00603D8: ec222090                 st      %l6, [%o0+0x90]
F00603DC: 1104001090122001         set     0x10004001, %o0
F00603E4: d025a098                 st      %o0, [%l6+0x98]
F00603E8: 90103fff                 mov     -1, %o0
F00603EC: d025a09c                 st      %o0, [%l6+0x9C]
F00603F0: c024c000                 clr     [%l3]
F00603F4: d2042090                 ld      [%l0+0x90], %o1
F00603F8: 80a24010                 cmp     %o1, %l0
F00603FC: 22800008                 be,a    loc_F006041C
F0060400: c0256008                 clr     [%l5+8]
F0060404: d0042094                 ld      [%l0+0x94], %o0
F0060408: d2256008                 st      %o1, [%l5+8]
F006040C: d0226094                 st      %o0, [%o1+0x94]
F0060410: d2222090                 st      %o1, [%o0+0x90]
F0060414: e0242090                 st      %l0, [%l0+0x90]
F0060418: e0242094                 st      %l0, [%l0+0x94]
F006041C: c0242098                 clr     [%l0+0x98]
F0060420: e824209c                 st      %l4, [%l0+0x9C]
F0060424: d0046034                 ld      [%l1+0x34], %o0
F0060428: 92022001                 add     %o0, 1, %o1
F006042C: d2246034                 st      %o1, [%l1+0x34]
F0060430: d02420a0                 st      %o0, [%l0+0xA0]
F0060434: c0254000                 clr     [%l5]
F0060438: d0042034                 ld      [%l0+0x34], %o0
F006043C: 9fc20000                 call    %o0
F0060440: c0242044                 clr     [%l0+0x44]
F0060444: 1080030f                 ba      locret_F0061080
F0060448: b0102000                 mov     0, %i0
F006044C: c0254000                 clr     [%l5]
F0060450: 30bfff79                 ba,a    loc_F0060234
F0060454: c0244000                 clr     [%l1]
F0060458: d204e008                 ld      [%l3+8], %o1
F006045C: 80a26000                 cmp     %o1, 0
F0060460: 22800007                 be,a    loc_F006047C
F0060464: ec24e008                 st      %l6, [%l3+8]
F0060468: d0026094                 ld      [%o1+0x94], %o0
F006046C: d225a090                 st      %o1, [%l6+0x90]
F0060470: d025a094                 st      %o0, [%l6+0x94]
F0060474: ec226094                 st      %l6, [%o1+0x94]
F0060478: ec222090                 st      %l6, [%o0+0x90]
F006047C: 1104001090122001         set     0x10004001, %o0
F0060484: d025a098                 st      %o0, [%l6+0x98]
F0060488: 90103fff                 mov     -1, %o0
F006048C: d025a09c                 st      %o0, [%l6+0x9C]
F0060490: c024c000                 clr     [%l3]
F0060494: d2042090                 ld      [%l0+0x90], %o1
F0060498: 80a24010                 cmp     %o1, %l0
F006049C: 22800008                 be,a    loc_F00604BC
F00604A0: c0256008                 clr     [%l5+8]
F00604A4: d0042094                 ld      [%l0+0x94], %o0
F00604A8: d2256008                 st      %o1, [%l5+8]
F00604AC: d0226094                 st      %o0, [%o1+0x94]
F00604B0: d2222090                 st      %o1, [%o0+0x90]
F00604B4: e0242090                 st      %l0, [%l0+0x90]
F00604B8: e0242094                 st      %l0, [%l0+0x94]
F00604BC: d0046034                 ld      [%l1+0x34], %o0
F00604C0: ac100010                 mov     %l0, %l6
F00604C4: 92022001                 add     %o0, 1, %o1
F00604C8: d2246034                 st      %o1, [%l1+0x34]
F00604CC: d0252024                 st      %o0, [%l4+0x24]
F00604D0: c0254000                 clr     [%l5]
F00604D4: c605a0c4                 ld      [%l6+0xC4], %g3
F00604D8: f605a0cc                 ld      [%l6+0xCC], %i3
F00604DC: e405a0d8                 ld      [%l6+0xD8], %l2
F00604E0: d005a00c                 ld      [%l6+0xC], %o0
F00604E4: c627bfcc                 st      %g3, [%fp+var_34]
F00604E8: f0022088                 ld      [%o0+0x88], %i0
F00604EC: d0048000                 ld      [%l2], %o0
F00604F0: 80a22000                 cmp     %o0, 0
F00604F4: 12bffffe                 bne     loc_F00604EC
F00604F8: 01000000                 nop
F00604FC: 4000da6b                 call    _simple_lock_try
F0060500: 90100012                 mov     %l2, %o0
F0060504: 80a22000                 cmp     %o0, 0
F0060508: 02bffff9                 be      loc_F00604EC
F006050C: 01000000                 nop
F0060510: d004a004                 ld      [%l2+4], %o0
F0060514: 90023fff                 inc     -1, %o0
F0060518: d024a004                 st      %o0, [%l2+4]
F006051C: c0248000                 clr     [%l2]
F0060520: 80a22000                 cmp     %o0, 0
F0060524: 1280000b                 bne     loc_F0060550
F0060528: 133c04ef                 sethi   %hi(_ipc_object_zones), %o1
F006052C: d004a008                 ld      [%l2+8], %o0
F0060530: 92126300                 bset    %lo(_ipc_object_zones), %o1
F0060534: 912a2001                 sll     %o0, 1, %o0
F0060538: 91322011                 srl     %o0, 17, %o0
F006053C: 912a2002                 sll     %o0, 2, %o0
F0060540: d0020009                 ld      [%o0+%o1], %o0
F0060544: 92100012                 mov     %l2, %o1
F0060548: 40006322                 call    _zfree
F006054C: 01000000                 nop
F0060550: d2052018                 ld      [%l4+0x18], %o1
F0060554: d0052010                 ld      [%l4+0x10], %o0
F0060558: a6024008                 add     %o1, %o0, %l3
F006055C: 80a6c013                 cmp     %i3, %l3
F0060560: 0a8001e8                 bcs     loc_F0060D00
F0060564: 11000004                 sethi   0x1000, %o0
F0060568: d2052014                 ld      [%l4+0x14], %o1
F006056C: 90122211                 bset    0x211, %o0
F0060570: 80a24008                 cmp     %o1, %o0
F0060574: 2280000f                 be,a    loc_F00605B0
F0060578: e4052020                 ld      [%l4+0x20], %l2
F006057C: 18800006                 bgu     loc_F0060594
F0060580: 80a26012                 cmp     %o1, 0x12
F0060584: 0280006a                 be      loc_F006072C
F0060588: 01000000                 nop
F006058C: 108001dd                 ba      loc_F0060D00
F0060590: d2052018                 ld      [%l4+0x18], %o1
F0060594: 1120000090122012         set     -0x7FFFFFEE, %o0
F006059C: 80a24008                 cmp     %o1, %o0
F00605A0: 02800088                 be      loc_F00607C0
F00605A4: 01000000                 nop
F00605A8: 108001d6                 ba      loc_F0060D00
F00605AC: d2052018                 ld      [%l4+0x18], %o1
F00605B0: 80a4a000                 cmp     %l2, 0
F00605B4: 028001d2                 be      loc_F0060CFC
F00605B8: 80a4bfff                 cmp     %l2, -1
F00605BC: 028001d0                 be      loc_F0060CFC
F00605C0: a0062008                 add     %i0, 8, %l0
F00605C4: d0040000                 ld      [%l0], %o0
F00605C8: 80a22000                 cmp     %o0, 0
F00605CC: 12bffffe                 bne     loc_F00605C4
F00605D0: 01000000                 nop
F00605D4: 4000da35                 call    _simple_lock_try
F00605D8: 90100010                 mov     %l0, %o0
F00605DC: 80a22000                 cmp     %o0, 0
F00605E0: 02bffff9                 be      loc_F00605C4
F00605E4: 01000000                 nop
F00605E8: d0044000                 ld      [%l1], %o0
F00605EC: 80a22000                 cmp     %o0, 0
F00605F0: 12bffffe                 bne     loc_F00605E8
F00605F4: 01000000                 nop
F00605F8: 4000da2c                 call    _simple_lock_try
F00605FC: 90100011                 mov     %l1, %o0
F0060600: 80a22000                 cmp     %o0, 0
F0060604: 02bffff9                 be      loc_F00605E8
F0060608: 01000000                 nop
F006060C: d0046008                 ld      [%l1+8], %o0
F0060610: 80a22000                 cmp     %o0, 0
F0060614: 16800042                 bge     loc_F006071C
F0060618: 01000000                 nop
F006061C: 4000da23                 call    _simple_lock_try
F0060620: 90100012                 mov     %l2, %o0
F0060624: 80a22000                 cmp     %o0, 0
F0060628: 0280003d                 be      loc_F006071C
F006062C: 01000000                 nop
F0060630: d004a008                 ld      [%l2+8], %o0
F0060634: 80a22000                 cmp     %o0, 0
F0060638: 06800004                 bl      loc_F0060648
F006063C: 01000000                 nop
F0060640: c0248000                 clr     [%l2]
F0060644: 30800036                 ba,a    loc_F006071C
F0060648: c0248000                 clr     [%l2]
F006064C: d8062014                 ld      [%i0+0x14], %o4
F0060650: da032008                 ld      [%o4+8], %o5
F0060654: 80a36000                 cmp     %o5, 0
F0060658: 02800031                 be      loc_F006071C
F006065C: 952b6004                 sll     %o5, 4, %o2
F0060660: 9603000a                 add     %o4, %o2, %o3
F0060664: d002e008                 ld      [%o3+8], %o0
F0060668: d0232008                 st      %o0, [%o4+8]
F006066C: c022e008                 clr     [%o3+8]
F0060670: d203000a                 ld      [%o4+%o2], %o1
F0060674: 11004000                 sethi   0x1000000, %o0
F0060678: 92024008                 add     %o1, %o0, %o1
F006067C: 1100010090122001         set     0x40001, %o0
F0060684: 90124008                 bset    %o1, %o0
F0060688: d023000a                 st      %o0, [%o4+%o2]
F006068C: e422e004                 st      %l2, [%o3+4]
F0060690: c0262008                 clr     [%i0+8]
F0060694: 912b6008                 sll     %o5, 8, %o0
F0060698: 93326018                 srl     %o1, 24, %o1
F006069C: a4120009                 or      %o0, %o1, %l2
F00606A0: d0046004                 ld      [%l1+4], %o0
F00606A4: 90023fff                 inc     -1, %o0
F00606A8: d0246004                 st      %o0, [%l1+4]
F00606AC: d004600c                 ld      [%l1+0xC], %o0
F00606B0: 80a20018                 cmp     %o0, %i0
F00606B4: 12800003                 bne     loc_F00606C0
F00606B8: a0102000                 mov     0, %l0
F00606BC: e0046010                 ld      [%l1+0x10], %l0
F00606C0: d004601c                 ld      [%l1+0x1C], %o0
F00606C4: 90023fff                 inc     -1, %o0
F00606C8: 80a22000                 cmp     %o0, 0
F00606CC: 1280000d                 bne     loc_F0060700
F00606D0: d024601c                 st      %o0, [%l1+0x1C]
F00606D4: d0046024                 ld      [%l1+0x24], %o0
F00606D8: 80a22000                 cmp     %o0, 0
F00606DC: 02800009                 be      loc_F0060700
F00606E0: 01000000                 nop
F00606E4: c0246024                 clr     [%l1+0x24]
F00606E8: d2046018                 ld      [%l1+0x18], %o1
F00606EC: c0244000                 clr     [%l1]
F00606F0: 7fffe2c5                 call    _ipc_notify_no_senders
F00606F4: 01000000                 nop
F00606F8: 10800004                 ba      loc_F0060708
F00606FC: 11000004                 sethi   0x1000, %o0
F0060700: c0244000                 clr     [%l1]
F0060704: 11000004                 sethi   0x1000, %o0
F0060708: 90122112                 bset    0x112, %o0
F006070C: d0252014                 st      %o0, [%l4+0x14]
F0060710: e425201c                 st      %l2, [%l4+0x1C]
F0060714: 10800065                 ba      loc_F00608A8
F0060718: e0252020                 st      %l0, [%l4+0x20]
F006071C: c0244000                 clr     [%l1]
F0060720: c0262008                 clr     [%i0+8]
F0060724: 10800177                 ba      loc_F0060D00
F0060728: d2052018                 ld      [%l4+0x18], %o1
F006072C: d0044000                 ld      [%l1], %o0
F0060730: 80a22000                 cmp     %o0, 0
F0060734: 12bffffe                 bne     loc_F006072C
F0060738: 01000000                 nop
F006073C: 4000d9db                 call    _simple_lock_try
F0060740: 90100011                 mov     %l1, %o0
F0060744: 80a22000                 cmp     %o0, 0
F0060748: 02bffff9                 be      loc_F006072C
F006074C: 01000000                 nop
F0060750: d0046008                 ld      [%l1+8], %o0
F0060754: 80a22000                 cmp     %o0, 0
F0060758: 3680016a                 bge,a   loc_F0060D00
F006075C: d2052018                 ld      [%l4+0x18], %o1
F0060760: d004600c                 ld      [%l1+0xC], %o0
F0060764: 80a20018                 cmp     %o0, %i0
F0060768: 1280000c                 bne     loc_F0060798
F006076C: 01000000                 nop
F0060770: d0046004                 ld      [%l1+4], %o0
F0060774: 90023fff                 inc     -1, %o0
F0060778: d0246004                 st      %o0, [%l1+4]
F006077C: d0046020                 ld      [%l1+0x20], %o0
F0060780: 90023fff                 inc     -1, %o0
F0060784: d0246020                 st      %o0, [%l1+0x20]
F0060788: d2046010                 ld      [%l1+0x10], %o1
F006078C: c0244000                 clr     [%l1]
F0060790: 10800007                 ba      loc_F00607AC
F0060794: 11000004                 sethi   0x1000, %o0
F0060798: c0244000                 clr     [%l1]
F006079C: 7fffe2c6                 call    _ipc_notify_send_once
F00607A0: 90100011                 mov     %l1, %o0
F00607A4: 92102000                 mov     0, %o1
F00607A8: 11000004                 sethi   0x1000, %o0
F00607AC: 90122200                 bset    0x200, %o0
F00607B0: d0252014                 st      %o0, [%l4+0x14]
F00607B4: c025201c                 clr     [%l4+0x1C]
F00607B8: 1080003c                 ba      loc_F00608A8
F00607BC: d2252020                 st      %o1, [%l4+0x20]
F00607C0: d0044000                 ld      [%l1], %o0
F00607C4: 80a22000                 cmp     %o0, 0
F00607C8: 12bffffe                 bne     loc_F00607C0
F00607CC: 01000000                 nop
F00607D0: 4000d9b6                 call    _simple_lock_try
F00607D4: 90100011                 mov     %l1, %o0
F00607D8: 80a22000                 cmp     %o0, 0
F00607DC: 02bffff9                 be      loc_F00607C0
F00607E0: 01000000                 nop
F00607E4: d0046008                 ld      [%l1+8], %o0
F00607E8: 80a22000                 cmp     %o0, 0
F00607EC: 36800145                 bge,a   loc_F0060D00
F00607F0: d2052018                 ld      [%l4+0x18], %o1
F00607F4: d004600c                 ld      [%l1+0xC], %o0
F00607F8: 80a20018                 cmp     %o0, %i0
F00607FC: 1280000c                 bne     loc_F006082C
F0060800: 01000000                 nop
F0060804: d0046004                 ld      [%l1+4], %o0
F0060808: 90023fff                 inc     -1, %o0
F006080C: d0246004                 st      %o0, [%l1+4]
F0060810: d0046020                 ld      [%l1+0x20], %o0
F0060814: 90023fff                 inc     -1, %o0
F0060818: d0246020                 st      %o0, [%l1+0x20]
F006081C: d2046010                 ld      [%l1+0x10], %o1
F0060820: c0244000                 clr     [%l1]
F0060824: 10800007                 ba      loc_F0060840
F0060828: 11200004                 sethi   -0x7FFFF000, %o0
F006082C: c0244000                 clr     [%l1]
F0060830: 7fffe2a1                 call    _ipc_notify_send_once
F0060834: 90100011                 mov     %l1, %o0
F0060838: 92102000                 mov     0, %o1
F006083C: 11200004                 sethi   -0x7FFFF000, %o0
F0060840: 90122200                 bset    0x200, %o0
F0060844: d0252014                 st      %o0, [%l4+0x14]
F0060848: c025201c                 clr     [%l4+0x1C]
F006084C: d2252020                 st      %o1, [%l4+0x20]
F0060850: 113c04d0                 sethi   %hi(_active_threads), %o0
F0060854: d4022260                 ld      [%o0+%lo(_active_threads)], %o2
F0060858: d2052018                 ld      [%l4+0x18], %o1
F006085C: 9005202c                 add     %l4, 0x2C, %o0 ! ','
F0060860: 92026014                 inc     0x14, %o1
F0060864: d602a00c                 ld      [%o2+0xC], %o3
F0060868: 92050009                 add     %l4, %o1, %o1
F006086C: d602e00c                 ld      [%o3+0xC], %o3
F0060870: 7fffd967                 call    _ipc_kmsg_copyout_body
F0060874: 94100018                 mov     %i0, %o2
F0060878: a0920000                 orcc    %o0, %g0, %l0
F006087C: 0280000b                 be      loc_F00608A8
F0060880: 92100014                 mov     %l4, %o1
F0060884: d6052018                 ld      [%l4+0x18], %o3
F0060888: d4052010                 ld      [%l4+0x10], %o2
F006088C: d007bfcc                 ld      [%fp+var_34], %o0
F0060890: 7fffd2c4                 call    _ipc_kmsg_put
F0060894: 9402c00a                 add     %o3, %o2, %o2
F0060898: 31040010b016200c         set     0x1000400C, %i0
F00608A0: 108001f8                 ba      locret_F0061080
F00608A4: b0140018                 bset    %l0, %i0
F00608A8: c0252010                 clr     [%l4+0x10]
F00608AC: d0052008                 ld      [%l4+8], %o0
F00608B0: 80a22100                 cmp     %o0, 0x100
F00608B4: 12800143                 bne     loc_F0060DC0
F00608B8: d007bfcc                 ld      [%fp+var_34], %o0
F00608BC: 90052014                 add     %l4, 0x14, %o0
F00608C0: d207bfcc                 ld      [%fp+var_34], %o1
F00608C4: 4000de18                 call    _copyoutmsg
F00608C8: 94100013                 mov     %l3, %o2
F00608CC: 80a22000                 cmp     %o0, 0
F00608D0: 1280013c                 bne     loc_F0060DC0
F00608D4: d007bfcc                 ld      [%fp+var_34], %o0
F00608D8: 133c04ef                 sethi   %hi(_ipc_kmsg_cache), %o1
F00608DC: d0026348                 ld      [%o1+%lo(_ipc_kmsg_cache)], %o0
F00608E0: 80a22000                 cmp     %o0, 0
F00608E4: 12800137                 bne     loc_F0060DC0
F00608E8: d007bfcc                 ld      [%fp+var_34], %o0
F00608EC: e8226348                 st      %l4, [%o1+%lo(_ipc_kmsg_cache)]
F00608F0: 4000edc7                 call    _thread_syscall_return
F00608F4: 90102000                 mov     0, %o0
F00608F8: 108001e2                 ba      locret_F0061080
F00608FC: b0102000                 mov     0, %i0
F0060900: 40001e28                 call    _kfree
F0060904: 90100014                 mov     %l4, %o0
F0060908: d007bfcc                 ld      [%fp+var_34], %o0
F006090C: 9210001a                 mov     %i2, %o1
F0060910: 94102000                 mov     0, %o2
F0060914: 7fffd24e                 call    _ipc_kmsg_get
F0060918: 9607bff4                 add     %fp, var_C, %o3
F006091C: a0920000                 orcc    %o0, %g0, %l0
F0060920: 02bffd42                 be      loc_F005FE28
F0060924: e807bff4                 ld      [%fp+var_C], %l4
F0060928: 4000edb9                 call    _thread_syscall_return
F006092C: 01000000                 nop
F0060930: 10bffd3e                 ba      loc_F005FE28
F0060934: e807bff4                 ld      [%fp+var_C], %l4
F0060938: 40001e1a                 call    _kfree
F006093C: 90100014                 mov     %l4, %o0
F0060940: 30800011                 ba,a    loc_F0060984
F0060944: d2022260                 ld      [%o0+0x260], %o1
F0060948: 96102000                 mov     0, %o3
F006094C: d402600c                 ld      [%o1+0xC], %o2
F0060950: 90100014                 mov     %l4, %o0
F0060954: d402a00c                 ld      [%o2+0xC], %o2
F0060958: 7fffd53e                 call    _ipc_kmsg_copyin
F006095C: 92100018                 mov     %i0, %o1
F0060960: a0920000                 orcc    %o0, %g0, %l0
F0060964: 2280000b                 be,a    loc_F0060990
F0060968: d2052014                 ld      [%l4+0x14], %o1
F006096C: d2052008                 ld      [%l4+8], %o1
F0060970: 80a26000                 cmp     %o1, 0
F0060974: 14bffff1                 bg      loc_F0060938
F0060978: 01000000                 nop
F006097C: 7fffd221                 call    _ipc_kmsg_free
F0060980: 90100014                 mov     %l4, %o0
F0060984: 4000eda2                 call    _thread_syscall_return
F0060988: 90100010                 mov     %l0, %o0
F006098C: d2052014                 ld      [%l4+0x14], %o1
F0060990: 11100000                 sethi   0x40000000, %o0
F0060994: 808a4008                 btst    %o0, %o1
F0060998: 12800099                 bne     loc_F0060BFC
F006099C: 90100014                 mov     %l4, %o0
F00609A0: e205201c                 ld      [%l4+0x1C], %l1
F00609A4: d0044000                 ld      [%l1], %o0
F00609A8: 80a22000                 cmp     %o0, 0
F00609AC: 12bffffe                 bne     loc_F00609A4
F00609B0: 01000000                 nop
F00609B4: 4000d93d                 call    _simple_lock_try
F00609B8: 90100011                 mov     %l1, %o0
F00609BC: 80a22000                 cmp     %o0, 0
F00609C0: 02bffff9                 be      loc_F00609A4
F00609C4: 133c04ef                 sethi   %hi(_ipc_space_kernel), %o1
F00609C8: d004600c                 ld      [%l1+0xC], %o0
F00609CC: d2026330                 ld      [%o1+%lo(_ipc_space_kernel)], %o1
F00609D0: 80a20009                 cmp     %o0, %o1
F00609D4: 32800004                 bne,a   loc_F00609E4
F00609D8: d0046008                 ld      [%l1+8], %o0
F00609DC: c0244000                 clr     [%l1]
F00609E0: 3080003c                 ba,a    loc_F0060AD0
F00609E4: 80a22000                 cmp     %o0, 0
F00609E8: 16800037                 bge     loc_F0060AC4
F00609EC: 01000000                 nop
F00609F0: d2046038                 ld      [%l1+0x38], %o1
F00609F4: d004603c                 ld      [%l1+0x3C], %o0
F00609F8: 80a24008                 cmp     %o1, %o0
F00609FC: 2a800007                 bcs,a   loc_F0060A18
F0060A00: e0052020                 ld      [%l4+0x20], %l0
F0060A04: d00d2017                 ldub    [%l4+0x17], %o0
F0060A08: 80a22012                 cmp     %o0, 0x12
F0060A0C: 1280002e                 bne     loc_F0060AC4
F0060A10: 01000000                 nop
F0060A14: e0052020                 ld      [%l4+0x20], %l0
F0060A18: 80a42000                 cmp     %l0, 0
F0060A1C: 0280002a                 be      loc_F0060AC4
F0060A20: 80a43fff                 cmp     %l0, -1
F0060A24: 02800028                 be      loc_F0060AC4
F0060A28: 01000000                 nop
F0060A2C: 4000d91f                 call    _simple_lock_try
F0060A30: 90100010                 mov     %l0, %o0
F0060A34: 80a22000                 cmp     %o0, 0
F0060A38: 02800023                 be      loc_F0060AC4
F0060A3C: 01000000                 nop
F0060A40: d0042008                 ld      [%l0+8], %o0
F0060A44: 80a22000                 cmp     %o0, 0
F0060A48: 1680001e                 bge     loc_F0060AC0
F0060A4C: 01000000                 nop
F0060A50: d004200c                 ld      [%l0+0xC], %o0
F0060A54: 80a20018                 cmp     %o0, %i0
F0060A58: 1280001a                 bne     loc_F0060AC0
F0060A5C: 01000000                 nop
F0060A60: d0042010                 ld      [%l0+0x10], %o0
F0060A64: 80a2001c                 cmp     %o0, %i4
F0060A68: 12800016                 bne     loc_F0060AC0
F0060A6C: 01000000                 nop
F0060A70: d0042030                 ld      [%l0+0x30], %o0
F0060A74: 80a22000                 cmp     %o0, 0
F0060A78: 12800012                 bne     loc_F0060AC0
F0060A7C: a4100010                 mov     %l0, %l2
F0060A80: d004a004                 ld      [%l2+4], %o0
F0060A84: 90022001                 inc     %o0
F0060A88: d024a004                 st      %o0, [%l2+4]
F0060A8C: a604a040                 add     %l2, 0x40, %l3 ! '@'
F0060A90: d004c000                 ld      [%l3], %o0
F0060A94: 80a22000                 cmp     %o0, 0
F0060A98: 12bffffe                 bne     loc_F0060A90
F0060A9C: 01000000                 nop
F0060AA0: 4000d902                 call    _simple_lock_try
F0060AA4: 90100013                 mov     %l3, %o0
F0060AA8: 80a22000                 cmp     %o0, 0
F0060AAC: 02bffff9                 be      loc_F0060A90
F0060AB0: 01000000                 nop
F0060AB4: c0248000                 clr     [%l2]
F0060AB8: 10bffdd6                 ba      loc_F0060210
F0060ABC: d0046030                 ld      [%l1+0x30], %o0
F0060AC0: c0240000                 clr     [%l0]
F0060AC4: c0244000                 clr     [%l1]
F0060AC8: 1080004d                 ba      loc_F0060BFC
F0060ACC: 90100014                 mov     %l4, %o0
F0060AD0: 400012bd                 call    _ipc_kobject_server
F0060AD4: 90100014                 mov     %l4, %o0
F0060AD8: a8920000                 orcc    %o0, %g0, %l4
F0060ADC: 0280005f                 be      loc_F0060C58
F0060AE0: 90100018                 mov     %i0, %o0
F0060AE4: e005201c                 ld      [%l4+0x1C], %l0
F0060AE8: d0040000                 ld      [%l0], %o0
F0060AEC: 80a22000                 cmp     %o0, 0
F0060AF0: 12bffffe                 bne     loc_F0060AE8
F0060AF4: 01000000                 nop
F0060AF8: 4000d8ec                 call    _simple_lock_try
F0060AFC: 90100010                 mov     %l0, %o0
F0060B00: 80a22000                 cmp     %o0, 0
F0060B04: 02bffff9                 be      loc_F0060AE8
F0060B08: 01000000                 nop
F0060B0C: d0042008                 ld      [%l0+8], %o0
F0060B10: 80a22000                 cmp     %o0, 0
F0060B14: 16800020                 bge     loc_F0060B94
F0060B18: 01000000                 nop
F0060B1C: d004200c                 ld      [%l0+0xC], %o0
F0060B20: 80a20018                 cmp     %o0, %i0
F0060B24: 1280001c                 bne     loc_F0060B94
F0060B28: 01000000                 nop
F0060B2C: d0042010                 ld      [%l0+0x10], %o0
F0060B30: 80a2001c                 cmp     %o0, %i4
F0060B34: 12800018                 bne     loc_F0060B94
F0060B38: 01000000                 nop
F0060B3C: d0042030                 ld      [%l0+0x30], %o0
F0060B40: 80a22000                 cmp     %o0, 0
F0060B44: 12800014                 bne     loc_F0060B94
F0060B48: a6042040                 add     %l0, 0x40, %l3 ! '@'
F0060B4C: d004c000                 ld      [%l3], %o0
F0060B50: 80a22000                 cmp     %o0, 0
F0060B54: 12bffffe                 bne     loc_F0060B4C
F0060B58: 01000000                 nop
F0060B5C: 4000d8d3                 call    _simple_lock_try
F0060B60: 90100013                 mov     %l3, %o0
F0060B64: 80a22000                 cmp     %o0, 0
F0060B68: 02bffff9                 be      loc_F0060B4C
F0060B6C: 01000000                 nop
F0060B70: d004e008                 ld      [%l3+8], %o0
F0060B74: 80a22000                 cmp     %o0, 0
F0060B78: 12800006                 bne     loc_F0060B90
F0060B7C: 01000000                 nop
F0060B80: d004e004                 ld      [%l3+4], %o0
F0060B84: 80a22000                 cmp     %o0, 0
F0060B88: 0280000b                 be      loc_F0060BB4
F0060B8C: a2100010                 mov     %l0, %l1
F0060B90: c024c000                 clr     [%l3]
F0060B94: c0240000                 clr     [%l0]
F0060B98: 90100014                 mov     %l4, %o0
F0060B9C: 13000040                 sethi   0x10000, %o1
F0060BA0: 94102000                 mov     0, %o2
F0060BA4: 7fffde36                 call    _ipc_mqueue_send
F0060BA8: 96102000                 mov     0, %o3
F0060BAC: 1080002b                 ba      loc_F0060C58
F0060BB0: 90100018                 mov     %i0, %o0
F0060BB4: d2046034                 ld      [%l1+0x34], %o1
F0060BB8: 90026001                 add     %o1, 1, %o0
F0060BBC: d0246034                 st      %o0, [%l1+0x34]
F0060BC0: d2252024                 st      %o1, [%l4+0x24]
F0060BC4: c024c000                 clr     [%l3]
F0060BC8: d0046004                 ld      [%l1+4], %o0
F0060BCC: c0244000                 clr     [%l1]
F0060BD0: 80a22000                 cmp     %o0, 0
F0060BD4: 12bffe5f                 bne     loc_F0060550
F0060BD8: 133c04ef                 sethi   %hi(_ipc_object_zones), %o1
F0060BDC: d0046008                 ld      [%l1+8], %o0
F0060BE0: 92126300                 bset    %lo(_ipc_object_zones), %o1
F0060BE4: 912a2001                 sll     %o0, 1, %o0
F0060BE8: 91322011                 srl     %o0, 17, %o0
F0060BEC: 912a2002                 sll     %o0, 2, %o0
F0060BF0: d0020009                 ld      [%o0+%o1], %o0
F0060BF4: 10bffe55                 ba      loc_F0060548
F0060BF8: 92100011                 mov     %l1, %o1
F0060BFC: 92102000                 mov     0, %o1
F0060C00: 94102000                 mov     0, %o2
F0060C04: 7fffde1e                 call    _ipc_mqueue_send
F0060C08: 96102000                 mov     0, %o3
F0060C0C: a0920000                 orcc    %o0, %g0, %l0
F0060C10: 02800011                 be      loc_F0060C54
F0060C14: 113c04d0                 sethi   %hi(_active_threads), %o0
F0060C18: d0022260                 ld      [%o0+%lo(_active_threads)], %o0
F0060C1C: d202200c                 ld      [%o0+0xC], %o1
F0060C20: d402600c                 ld      [%o1+0xC], %o2
F0060C24: 90100014                 mov     %l4, %o0
F0060C28: 7fffd919                 call    _ipc_kmsg_copyout_pseudo
F0060C2C: 92100018                 mov     %i0, %o1
F0060C30: d6052018                 ld      [%l4+0x18], %o3
F0060C34: a0140008                 bset    %o0, %l0
F0060C38: d4052010                 ld      [%l4+0x10], %o2
F0060C3C: 92100014                 mov     %l4, %o1
F0060C40: d007bfcc                 ld      [%fp+var_34], %o0
F0060C44: 7fffd1d7                 call    _ipc_kmsg_put
F0060C48: 9402c00a                 add     %o3, %o2, %o2
F0060C4C: 4000ecf0                 call    _thread_syscall_return
F0060C50: 90100010                 mov     %l0, %o0
F0060C54: 90100018                 mov     %i0, %o0
F0060C58: 9210001c                 mov     %i4, %o1
F0060C5C: 9407bff0                 add     %fp, var_10, %o2
F0060C60: 7fffdf27                 call    _ipc_mqueue_copyin
F0060C64: 9607bfec                 add     %fp, var_14, %o3
F0060C68: a0920000                 orcc    %o0, %g0, %l0
F0060C6C: 22800005                 be,a    loc_F0060C80
F0060C70: f625a0cc                 st      %i3, [%l6+0xCC]
F0060C74: 4000ece6                 call    _thread_syscall_return
F0060C78: 01000000                 nop
F0060C7C: f625a0cc                 st      %i3, [%l6+0xCC]
F0060C80: 92102000                 mov     0, %o1
F0060C84: 94103fff                 mov     -1, %o2
F0060C88: 96102000                 mov     0, %o3
F0060C8C: 98102000                 mov     0, %o4
F0060C90: 1b3c0184                 sethi   %hi(_mach_msg_continue), %o5
F0060C94: c607bfcc                 ld      [%fp+var_34], %g3
F0060C98: 9a136088                 bset    %lo(_mach_msg_continue), %o5
F0060C9C: e407bfec                 ld      [%fp+var_14], %l2
F0060CA0: 9007bff4                 add     %fp, var_C, %o0
F0060CA4: e607bff0                 ld      [%fp+var_10], %l3
F0060CA8: c625a0c4                 st      %g3, [%l6+0xC4]
F0060CAC: e425a0d8                 st      %l2, [%l6+0xD8]
F0060CB0: e625a0dc                 st      %l3, [%l6+0xDC]
F0060CB4: d023a05c                 st      %o0, [%sp+0xA0+var_44]
F0060CB8: 9007bfe8                 add     %fp, var_18, %o0
F0060CBC: d023a060                 st      %o0, [%sp+0xA0+var_40]
F0060CC0: 7fffdf7e                 call    _ipc_mqueue_receive
F0060CC4: 90100013                 mov     %l3, %o0
F0060CC8: a0100008                 mov     %o0, %l0
F0060CCC: 7fffe269                 call    _ipc_object_release
F0060CD0: 90100012                 mov     %l2, %o0
F0060CD4: 80a42000                 cmp     %l0, 0
F0060CD8: 02800005                 be      loc_F0060CEC
F0060CDC: e807bff4                 ld      [%fp+var_C], %l4
F0060CE0: 4000eccb                 call    _thread_syscall_return
F0060CE4: 90100010                 mov     %l0, %o0
F0060CE8: e807bff4                 ld      [%fp+var_C], %l4
F0060CEC: d007bfe8                 ld      [%fp+var_18], %o0
F0060CF0: e205201c                 ld      [%l4+0x1C], %l1
F0060CF4: 10bffe17                 ba      loc_F0060550
F0060CF8: d0252024                 st      %o0, [%l4+0x24]
F0060CFC: d2052018                 ld      [%l4+0x18], %o1
F0060D00: d0052010                 ld      [%l4+0x10], %o0
F0060D04: a6024008                 add     %o1, %o0, %l3
F0060D08: 80a6c013                 cmp     %i3, %l3
F0060D0C: 1a80000b                 bcc     loc_F0060D38
F0060D10: 90100014                 mov     %l4, %o0
F0060D14: 7fffd904                 call    _ipc_kmsg_copyout_dest
F0060D18: 92100018                 mov     %i0, %o1
F0060D1C: d007bfcc                 ld      [%fp+var_34], %o0
F0060D20: 92100014                 mov     %l4, %o1
F0060D24: 7fffd19f                 call    _ipc_kmsg_put
F0060D28: 94102018                 mov     0x18, %o2
F0060D2C: 11040010                 sethi   0x10004000, %o0
F0060D30: 4000ecb7                 call    _thread_syscall_return
F0060D34: 90122004                 bset    4, %o0
F0060D38: 113c04d0                 sethi   %hi(_active_threads), %o0
F0060D3C: d2022260                 ld      [%o0+%lo(_active_threads)], %o1
F0060D40: 96102000                 mov     0, %o3
F0060D44: d402600c                 ld      [%o1+0xC], %o2
F0060D48: 90100014                 mov     %l4, %o0
F0060D4C: d402a00c                 ld      [%o2+0xC], %o2
F0060D50: 7fffd8b6                 call    _ipc_kmsg_copyout
F0060D54: 92100018                 mov     %i0, %o1
F0060D58: a0920000                 orcc    %o0, %g0, %l0
F0060D5C: 02bffed3                 be      loc_F00608A8
F0060D60: 1300000f                 sethi   0x3C00, %o1
F0060D64: 922c0009                 andn    %l0, %o1, %o1
F0060D68: 110400109012200c         set     0x1000400C, %o0
F0060D70: 80a24008                 cmp     %o1, %o0
F0060D74: 32800008                 bne,a   loc_F0060D94
F0060D78: 90100014                 mov     %l4, %o0
F0060D7C: d6052018                 ld      [%l4+0x18], %o3
F0060D80: d4052010                 ld      [%l4+0x10], %o2
F0060D84: 92100014                 mov     %l4, %o1
F0060D88: d007bfcc                 ld      [%fp+var_34], %o0
F0060D8C: 10800007                 ba      loc_F0060DA8
F0060D90: 9402c00a                 add     %o3, %o2, %o2
F0060D94: 7fffd8e4                 call    _ipc_kmsg_copyout_dest
F0060D98: 92100018                 mov     %i0, %o1
F0060D9C: d007bfcc                 ld      [%fp+var_34], %o0
F0060DA0: 92100014                 mov     %l4, %o1
F0060DA4: 94102018                 mov     0x18, %o2
F0060DA8: 7fffd17e                 call    _ipc_kmsg_put
F0060DAC: 01000000                 nop
F0060DB0: 4000ec97                 call    _thread_syscall_return
F0060DB4: 90100010                 mov     %l0, %o0
F0060DB8: 10bffebd                 ba      loc_F00608AC
F0060DBC: c0252010                 clr     [%l4+0x10]
F0060DC0: 92100014                 mov     %l4, %o1
F0060DC4: 7fffd177                 call    _ipc_kmsg_put
F0060DC8: 94100013                 mov     %l3, %o2
F0060DCC: 30800093                 ba,a    loc_F0061018
F0060DD0: 80a66001                 cmp     %i1, 1
F0060DD4: 12800033                 bne     loc_F0060EA0
F0060DD8: 80a66002                 cmp     %i1, 2
F0060DDC: 113c04d0                 sethi   %hi(_active_threads), %o0
F0060DE0: d2022260                 ld      [%o0+%lo(_active_threads)], %o1
F0060DE4: d602600c                 ld      [%o1+0xC], %o3
F0060DE8: d007bfcc                 ld      [%fp+var_34], %o0
F0060DEC: e202e088                 ld      [%o3+0x88], %l1
F0060DF0: 94102000                 mov     0, %o2
F0060DF4: e402e00c                 ld      [%o3+0xC], %l2
F0060DF8: 9210001a                 mov     %i2, %o1
F0060DFC: 7fffd114                 call    _ipc_kmsg_get
F0060E00: 9607bfe4                 add     %fp, var_1C, %o3
F0060E04: a0920000                 orcc    %o0, %g0, %l0
F0060E08: 02800007                 be      loc_F0060E24
F0060E0C: d007bfe4                 ld      [%fp+var_1C], %o0
F0060E10: 1080009c                 ba      locret_F0061080
F0060E14: b0100010                 mov     %l0, %i0
F0060E18: 40001ce2                 call    _kfree
F0060E1C: b0100010                 mov     %l0, %i0
F0060E20: 30800098                 ba,a    locret_F0061080
F0060E24: 92100011                 mov     %l1, %o1
F0060E28: 94100012                 mov     %l2, %o2
F0060E2C: 7fffd409                 call    _ipc_kmsg_copyin
F0060E30: 96102000                 mov     0, %o3
F0060E34: a0920000                 orcc    %o0, %g0, %l0
F0060E38: 02800009                 be      loc_F0060E5C
F0060E3C: d007bfe4                 ld      [%fp+var_1C], %o0
F0060E40: d2022008                 ld      [%o0+8], %o1
F0060E44: 80a26000                 cmp     %o1, 0
F0060E48: 14bffff4                 bg      loc_F0060E18
F0060E4C: 01000000                 nop
F0060E50: 7fffd0ec                 call    _ipc_kmsg_free
F0060E54: b0100010                 mov     %l0, %i0
F0060E58: 3080008a                 ba,a    locret_F0061080
F0060E5C: 92102000                 mov     0, %o1
F0060E60: 94102000                 mov     0, %o2
F0060E64: 7fffdd86                 call    _ipc_mqueue_send
F0060E68: 96102000                 mov     0, %o3
F0060E6C: a0920000                 orcc    %o0, %g0, %l0
F0060E70: 02bfffe8                 be      loc_F0060E10
F0060E74: 92100011                 mov     %l1, %o1
F0060E78: d007bfe4                 ld      [%fp+var_1C], %o0
F0060E7C: 7fffd884                 call    _ipc_kmsg_copyout_pseudo
F0060E80: 94100012                 mov     %l2, %o2
F0060E84: d207bfe4                 ld      [%fp+var_1C], %o1
F0060E88: d6026018                 ld      [%o1+0x18], %o3
F0060E8C: d4026010                 ld      [%o1+0x10], %o2
F0060E90: a0140008                 bset    %o0, %l0
F0060E94: d007bfcc                 ld      [%fp+var_34], %o0
F0060E98: 10800052                 ba      loc_F0060FE0
F0060E9C: 9402c00a                 add     %o3, %o2, %o2
F0060EA0: 1280005b                 bne     loc_F006100C
F0060EA4: 80a66000                 cmp     %i1, 0
F0060EA8: 113c04d0                 sethi   %hi(_active_threads), %o0
F0060EAC: e2022260                 ld      [%o0+%lo(_active_threads)], %l1
F0060EB0: d004600c                 ld      [%l1+0xC], %o0
F0060EB4: 9210001c                 mov     %i4, %o1
F0060EB8: e4022088                 ld      [%o0+0x88], %l2
F0060EBC: 9407bfe0                 add     %fp, var_20, %o2
F0060EC0: e602200c                 ld      [%o0+0xC], %l3
F0060EC4: 9607bfdc                 add     %fp, var_24, %o3
F0060EC8: 7fffde8d                 call    _ipc_mqueue_copyin
F0060ECC: 90100012                 mov     %l2, %o0
F0060ED0: a0920000                 orcc    %o0, %g0, %l0
F0060ED4: 1280006b                 bne     locret_F0061080
F0060ED8: b0100010                 mov     %l0, %i0
F0060EDC: f62460cc                 st      %i3, [%l1+0xCC]
F0060EE0: 92102000                 mov     0, %o1
F0060EE4: 94103fff                 mov     -1, %o2
F0060EE8: 96102000                 mov     0, %o3
F0060EEC: 98102000                 mov     0, %o4
F0060EF0: c607bfcc                 ld      [%fp+var_34], %g3
F0060EF4: 1b3c0184                 sethi   %hi(_mach_msg_continue), %o5
F0060EF8: c407bfdc                 ld      [%fp+var_24], %g2
F0060EFC: 9a136088                 bset    %lo(_mach_msg_continue), %o5
F0060F00: d007bfe0                 ld      [%fp+var_20], %o0
F0060F04: c62460c4                 st      %g3, [%l1+0xC4]
F0060F08: c42460d8                 st      %g2, [%l1+0xD8]
F0060F0C: d02460dc                 st      %o0, [%l1+0xDC]
F0060F10: 8407bfd8                 add     %fp, var_28, %g2
F0060F14: c423a05c                 st      %g2, [%sp+0xA0+var_44]
F0060F18: 8407bfd4                 add     %fp, var_2C, %g2
F0060F1C: 7fffdee7                 call    _ipc_mqueue_receive
F0060F20: c423a060                 st      %g2, [%sp+0xA0+var_40]
F0060F24: a0100008                 mov     %o0, %l0
F0060F28: 7fffe1d2                 call    _ipc_object_release
F0060F2C: d007bfdc                 ld      [%fp+var_24], %o0
F0060F30: 80a42000                 cmp     %l0, 0
F0060F34: 12800053                 bne     locret_F0061080
F0060F38: b0100010                 mov     %l0, %i0
F0060F3C: d407bfd8                 ld      [%fp+var_28], %o2
F0060F40: d007bfd4                 ld      [%fp+var_2C], %o0
F0060F44: d202a018                 ld      [%o2+0x18], %o1
F0060F48: 80a6c009                 cmp     %i3, %o1
F0060F4C: 1a80000c                 bcc     loc_F0060F7C
F0060F50: d022a024                 st      %o0, [%o2+0x24]
F0060F54: 9010000a                 mov     %o2, %o0
F0060F58: 7fffd873                 call    _ipc_kmsg_copyout_dest
F0060F5C: 92100012                 mov     %l2, %o1
F0060F60: d007bfcc                 ld      [%fp+var_34], %o0
F0060F64: d207bfd8                 ld      [%fp+var_28], %o1
F0060F68: 7fffd10e                 call    _ipc_kmsg_put
F0060F6C: 94102018                 mov     0x18, %o2
F0060F70: 31040010                 sethi   0x10004000, %i0
F0060F74: 10800043                 ba      locret_F0061080
F0060F78: b0162004                 bset    4, %i0
F0060F7C: 9010000a                 mov     %o2, %o0
F0060F80: 92100012                 mov     %l2, %o1
F0060F84: 94100013                 mov     %l3, %o2
F0060F88: 7fffd828                 call    _ipc_kmsg_copyout
F0060F8C: 96102000                 mov     0, %o3
F0060F90: a0920000                 orcc    %o0, %g0, %l0
F0060F94: 02800016                 be      loc_F0060FEC
F0060F98: 1300000f                 sethi   0x3C00, %o1
F0060F9C: 922c0009                 andn    %l0, %o1, %o1
F0060FA0: 110400109012200c         set     0x1000400C, %o0
F0060FA8: 80a24008                 cmp     %o1, %o0
F0060FAC: 12800008                 bne     loc_F0060FCC
F0060FB0: d007bfd8                 ld      [%fp+var_28], %o0
F0060FB4: d207bfd8                 ld      [%fp+var_28], %o1
F0060FB8: d6026018                 ld      [%o1+0x18], %o3
F0060FBC: d4026010                 ld      [%o1+0x10], %o2
F0060FC0: d007bfcc                 ld      [%fp+var_34], %o0
F0060FC4: 10800007                 ba      loc_F0060FE0
F0060FC8: 9402c00a                 add     %o3, %o2, %o2
F0060FCC: 7fffd856                 call    _ipc_kmsg_copyout_dest
F0060FD0: 92100012                 mov     %l2, %o1
F0060FD4: d007bfcc                 ld      [%fp+var_34], %o0
F0060FD8: d207bfd8                 ld      [%fp+var_28], %o1
F0060FDC: 94102018                 mov     0x18, %o2
F0060FE0: 7fffd0f0                 call    _ipc_kmsg_put
F0060FE4: b0100010                 mov     %l0, %i0
F0060FE8: 30800026                 ba,a    locret_F0061080
F0060FEC: d207bfd8                 ld      [%fp+var_28], %o1
F0060FF0: d6026018                 ld      [%o1+0x18], %o3
F0060FF4: d4026010                 ld      [%o1+0x10], %o2
F0060FF8: d007bfcc                 ld      [%fp+var_34], %o0
F0060FFC: 7fffd0e9                 call    _ipc_kmsg_put
F0061000: 9402c00a                 add     %o3, %o2, %o2
F0061004: 1080001f                 ba      locret_F0061080
F0061008: b0100008                 mov     %o0, %i0
F006100C: 12800006                 bne     loc_F0061024
F0061010: 808e6001                 btst    1, %i1
F0061014: 90102000                 mov     0, %o0
F0061018: 4000ebfd                 call    _thread_syscall_return
F006101C: 01000000                 nop
F0061020: 808e6001                 btst    1, %i1
F0061024: 0280000a                 be      loc_F006104C
F0061028: 92100019                 mov     %i1, %o1
F006102C: d007bfcc                 ld      [%fp+var_34], %o0! mach_msg_header_t *
F0061030: 9410001a                 mov     %i2, %o2
F0061034: d807a05c                 ld      [%fp+arg_5C], %o4
F0061038: 7ffff9e1                 call    _mach_msg_send
F006103C: 9610001d                 mov     %i5, %o3
F0061040: a0920000                 orcc    %o0, %g0, %l0
F0061044: 1280000f                 bne     locret_F0061080
F0061048: b0100010                 mov     %l0, %i0
F006104C: 808e6002                 btst    2, %i1
F0061050: 0280000b                 be      loc_F006107C
F0061054: 92100019                 mov     %i1, %o1
F0061058: 9410001b                 mov     %i3, %o2
F006105C: d007bfcc                 ld      [%fp+var_34], %o0! mach_msg_header_t *
F0061060: 9610001c                 mov     %i4, %o3
F0061064: da07a05c                 ld      [%fp+arg_5C], %o5
F0061068: 7ffffa3b                 call    _mach_msg_receive
F006106C: 9810001d                 mov     %i5, %o4
F0061070: a0920000                 orcc    %o0, %g0, %l0
F0061074: 12800003                 bne     locret_F0061080
F0061078: b0100010                 mov     %l0, %i0
F006107C: b0102000                 mov     0, %i0
F0061080: 81c7e008                 ret
F0061084: 81e80000                 restore
