F001BE78: 9de3bf30                 save    %sp, -0xD0, %sp
F001BE7C: a4102000                 mov     0, %l2
F001BE80: b00e20ff                 and     %i0, 0xFF, %i0
F001BE84: b12e2004                 sll     %i0, 4, %i0
F001BE88: 113c04bc90122204         set     unk_F012F204, %o0
F001BE90: b0060008                 add     %i0, %o0, %i0
F001BE94: e2062008                 ld      [%i0+8], %l1
F001BE98: a0102000                 mov     0, %l0
F001BE9C: e6064000                 ld      [%i1], %l3
F001BEA0: a8102000                 mov     0, %l4
F001BEA4: ea06200c                 ld      [%i0+0xC], %l5
F001BEA8: d0046040                 ld      [%l1+0x40], %o0
F001BEAC: 808a2004                 btst    4, %o0
F001BEB0: 02800091                 be      loc_F001C0F4
F001BEB4: 808a2010                 btst    0x10, %o0
F001BEB8: d0054000                 ld      [%l5], %o0
F001BEBC: 808a2020                 btst    0x20, %o0 ! ' '
F001BEC0: 22800044                 be,a    loc_F001BFD0
F001BEC4: d2066004                 ld      [%i1+4], %o1
F001BEC8: d004600c                 ld      [%l1+0xC], %o0
F001BECC: 80a22000                 cmp     %o0, 0
F001BED0: 32800088                 bne,a   loc_F001C0F0
F001BED4: d0046040                 ld      [%l1+0x40], %o0
F001BED8: d2066004                 ld      [%i1+4], %o1
F001BEDC: 80a26000                 cmp     %o1, 0
F001BEE0: 04800032                 ble     loc_F001BFA8
F001BEE4: a81023ff                 mov     0x3FF, %l4
F001BEE8: d404600c                 ld      [%l1+0xC], %o2
F001BEEC: 80a2a3fe                 cmp     %o2, 0x3FE
F001BEF0: 1480002f                 bg      loc_F001BFAC
F001BEF4: 90102000                 mov     0, %o0
F001BEF8: e6064000                 ld      [%i1], %l3
F001BEFC: d004e004                 ld      [%l3+4], %o0
F001BF00: 80a22000                 cmp     %o0, 0
F001BF04: 12800008                 bne     loc_F001BF24
F001BF08: 80a42000                 cmp     %l0, 0
F001BF0C: 92027fff                 inc     -1, %o1
F001BF10: d0064000                 ld      [%i1], %o0
F001BF14: d2266004                 st      %o1, [%i1+4]
F001BF18: 90022008                 inc     8, %o0
F001BF1C: 1080001f                 ba      loc_F001BF98
F001BF20: d0264000                 st      %o0, [%i1]
F001BF24: 12800017                 bne     loc_F001BF80
F001BF28: 80a42000                 cmp     %l0, 0
F001BF2C: a0100008                 mov     %o0, %l0
F001BF30: 80a42064                 cmp     %l0, 0x64 ! 'd'
F001BF34: 34800002                 bg,a    loc_F001BF3C
F001BF38: a0102064                 mov     0x64, %l0 ! 'd'
F001BF3C: 9025000a                 sub     %l4, %o2, %o0
F001BF40: 80a40008                 cmp     %l0, %o0
F001BF44: 34800002                 bg,a    loc_F001BF4C
F001BF48: a0100008                 mov     %o0, %l0
F001BF4C: a407bf90                 add     %fp, var_70, %l2
F001BF50: 90100012                 mov     %l2, %o0
F001BF54: 92100010                 mov     %l0, %o1
F001BF58: 94102001                 mov     1, %o2
F001BF5C: 7fffd8ef                 call    _uiomove
F001BF60: 96100019                 mov     %i1, %o3
F001BF64: 80a22000                 cmp     %o0, 0
F001BF68: 12800086                 bne     locret_F001C180
F001BF6C: b0100008                 mov     %o0, %i0
F001BF70: d0046040                 ld      [%l1+0x40], %o0
F001BF74: 808a2004                 btst    4, %o0
F001BF78: 02800061                 be      loc_F001C0FC
F001BF7C: 80a42000                 cmp     %l0, 0
F001BF80: 02800005                 be      loc_F001BF94
F001BF84: 90100012                 mov     %l2, %o0
F001BF88: 92100010                 mov     %l0, %o1
F001BF8C: 4000033c                 call    _b_to_q
F001BF90: 9404600c                 add     %l1, 0xC, %o2
F001BF94: a0102000                 mov     0, %l0
F001BF98: d2066004                 ld      [%i1+4], %o1! FILE *
F001BF9C: 80a26000                 cmp     %o1, 0
F001BFA0: 34bfffd3                 bg,a    loc_F001BEEC
F001BFA4: d404600c                 ld      [%l1+0xC], %o2
F001BFA8: 90102000                 mov     0, %o0! int
F001BFAC: a004600c                 add     %l1, 0xC, %l0
F001BFB0: 400002e8                 call    _putc
F001BFB4: 92100010                 mov     %l0, %o1
F001BFB8: 7ffff97b                 call    _ttwakeup
F001BFBC: 90100011                 mov     %l1, %o0
F001BFC0: 7fffdb8a                 call    _wakeup
F001BFC4: 90100010                 mov     %l0, %o0
F001BFC8: 1080006e                 ba      locret_F001C180
F001BFCC: b0102000                 mov     0, %i0
F001BFD0: 80a26000                 cmp     %o1, 0
F001BFD4: 04bffffd                 ble     loc_F001BFC8
F001BFD8: 113c042e                 sethi   %hi(_linesw), %o0
F001BFDC: b01220cc                 or      %o0, %lo(_linesw), %i0
F001BFE0: 80a42000                 cmp     %l0, 0
F001BFE4: 12800039                 bne     loc_F001C0C8
F001BFE8: e6064000                 ld      [%i1], %l3
F001BFEC: d004e004                 ld      [%l3+4], %o0
F001BFF0: 80a22000                 cmp     %o0, 0
F001BFF4: 32800008                 bne,a   loc_F001C014
F001BFF8: a0100008                 mov     %o0, %l0
F001BFFC: 92027fff                 inc     -1, %o1
F001C000: d0064000                 ld      [%i1], %o0
F001C004: d2266004                 st      %o1, [%i1+4]
F001C008: 90022008                 inc     8, %o0
F001C00C: 10800033                 ba      loc_F001C0D8
F001C010: d0264000                 st      %o0, [%i1]
F001C014: 80a42064                 cmp     %l0, 0x64 ! 'd'
F001C018: 34800002                 bg,a    loc_F001C020
F001C01C: a0102064                 mov     0x64, %l0 ! 'd'
F001C020: a407bf90                 add     %fp, var_70, %l2
F001C024: 90100012                 mov     %l2, %o0
F001C028: 92100010                 mov     %l0, %o1
F001C02C: 94102001                 mov     1, %o2
F001C030: 7fffd8ba                 call    _uiomove
F001C034: 96100019                 mov     %i1, %o3
F001C038: 80a22000                 cmp     %o0, 0
F001C03C: 32800051                 bne,a   locret_F001C180
F001C040: b0100008                 mov     %o0, %i0
F001C044: d0046040                 ld      [%l1+0x40], %o0
F001C048: 808a2004                 btst    4, %o0
F001C04C: 2280004d                 be,a    locret_F001C180
F001C050: b0102005                 mov     5, %i0
F001C054: 1080001e                 ba      loc_F001C0CC
F001C058: 80a42000                 cmp     %l0, 0
F001C05C: d204600c                 ld      [%l1+0xC], %o1
F001C060: 90020009                 add     %o0, %o1, %o0
F001C064: 80a223fd                 cmp     %o0, 0x3FD
F001C068: 0480000c                 ble     loc_F001C098
F001C06C: 80a26000                 cmp     %o1, 0
F001C070: 14800006                 bg      loc_F001C088
F001C074: 01000000                 nop
F001C078: d004603c                 ld      [%l1+0x3C], %o0
F001C07C: 808a2022                 btst    0x22, %o0 ! '"'
F001C080: 02800007                 be      loc_F001C09C
F001C084: 92100011                 mov     %l1, %o1
F001C088: 7fffdb58                 call    _wakeup
F001C08C: 90100011                 mov     %l1, %o0
F001C090: 10800018                 ba      loc_F001C0F0
F001C094: d0046040                 ld      [%l1+0x40], %o0
F001C098: 92100011                 mov     %l1, %o1
F001C09C: a8052001                 inc     %l4
F001C0A0: d64c6047                 ldsb    [%l1+0x47], %o3
F001C0A4: a0043fff                 inc     -1, %l0
F001C0A8: d00c8000                 ldub    [%l2], %o0
F001C0AC: 952ae001                 sll     %o3, 1, %o2
F001C0B0: 9402800b                 add     %o2, %o3, %o2
F001C0B4: 952aa004                 sll     %o2, 4, %o2
F001C0B8: 94028018                 add     %o2, %i0, %o2
F001C0BC: d402a014                 ld      [%o2+0x14], %o2
F001C0C0: 9fc28000                 call    %o2
F001C0C4: a404a001                 inc     %l2
F001C0C8: 80a42000                 cmp     %l0, 0
F001C0CC: 34bfffe4                 bg,a    loc_F001C05C
F001C0D0: d0044000                 ld      [%l1], %o0
F001C0D4: a0102000                 mov     0, %l0
F001C0D8: d2066004                 ld      [%i1+4], %o1
F001C0DC: 80a26000                 cmp     %o1, 0
F001C0E0: 14bfffc1                 bg      loc_F001BFE4
F001C0E4: 80a42000                 cmp     %l0, 0
F001C0E8: 10800026                 ba      locret_F001C180
F001C0EC: b0102000                 mov     0, %i0
F001C0F0: 808a2010                 btst    0x10, %o0
F001C0F4: 32800004                 bne,a   loc_F001C104
F001C0F8: d0054000                 ld      [%l5], %o0
F001C0FC: 10800021                 ba      locret_F001C180
F001C100: b0102005                 mov     5, %i0
F001C104: 808a2004                 btst    4, %o0
F001C108: 02800019                 be      loc_F001C16C
F001C10C: 80a52000                 cmp     %l4, 0
F001C110: d004c000                 ld      [%l3], %o0
F001C114: d204e004                 ld      [%l3+4], %o1
F001C118: 90220010                 sub     %o0, %l0, %o0
F001C11C: d024c000                 st      %o0, [%l3]
F001C120: 92024010                 add     %o1, %l0, %o1
F001C124: d224e004                 st      %o1, [%l3+4]
F001C128: d2066014                 ld      [%i1+0x14], %o1
F001C12C: d0066008                 ld      [%i1+8], %o0
F001C130: 92024010                 add     %o1, %l0, %o1
F001C134: d2266014                 st      %o1, [%i1+0x14]
F001C138: 90220010                 sub     %o0, %l0, %o0
F001C13C: 12bfffa3                 bne     loc_F001BFC8
F001C140: d0266008                 st      %o0, [%i1+8]
F001C144: 113c04cf                 sethi   %hi(_active_u), %o0
F001C148: d00221d8                 ld      [%o0+%lo(_active_u)], %o0
F001C14C: d0020000                 ld      [%o0], %o0
F001C150: d2022014                 ld      [%o0+0x14], %o1
F001C154: 11000010                 sethi   0x4000, %o0
F001C158: 808a4008                 btst    %o0, %o1
F001C15C: 02800009                 be      locret_F001C180
F001C160: b0102023                 mov     0x23, %i0 ! '#'
F001C164: 10800007                 ba      locret_F001C180
F001C168: b010200b                 mov     0xB, %i0
F001C16C: 90046004                 add     %l1, 4, %o0! unsigned int
F001C170: 7fffd942                 call    _sleep
F001C174: 9210201d                 mov     0x1D, %o1
F001C178: 10bfff4d                 ba      loc_F001BEAC
F001C17C: d0046040                 ld      [%l1+0x40], %o0
F001C180: 81c7e008                 ret
F001C184: 81e80000                 restore
