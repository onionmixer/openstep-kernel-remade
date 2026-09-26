F005CE70: 9de3bf98                 save    %sp, -0x68, %sp
F005CE74: e0068000                 ld      [%i2], %l0
F005CE78: 9206fff0                 add     %i3, -0x10, %o1
F005CE7C: 80a26005                 cmp     %o1, 5! switch 6 cases
F005CE80: 18800106                 bgu     def_F005CE98! jumptable F005CE98 default case
F005CE84: e407a05c                 ld      [%fp+arg_5C], %l2
F005CE88: 113c0173901222a0         set     jpt_F005CE98, %o0
F005CE90: 932a6002                 sll     %o1, 2, %o1
F005CE94: d0024008                 ld      [%o1+%o0], %o0
F005CE98: 81c20000                 jmp     %o0! switch jump
F005CE9C: 01000000                 nop
F005CEB8: 11000080                 sethi   0x20000, %o0! jumptable F005CE98 case 4
F005CEBC: 808c0008                 btst    %o0, %l0
F005CEC0: 02800110                 be      locret_F005D300
F005CEC4: b0102011                 mov     0x11, %i0
F005CEC8: f406a004                 ld      [%i2+4], %i2
F005CECC: d0068000                 ld      [%i2], %o0
F005CED0: 80a22000                 cmp     %o0, 0
F005CED4: 12bffffe                 bne     loc_F005CECC
F005CED8: 01000000                 nop
F005CEDC: 4000e7f3                 call    _simple_lock_try
F005CEE0: 9010001a                 mov     %i2, %o0
F005CEE4: 80a22000                 cmp     %o0, 0
F005CEE8: 02bffff9                 be      loc_F005CECC
F005CEEC: 01000000                 nop
F005CEF0: d006a018                 ld      [%i2+0x18], %o0
F005CEF4: d206a01c                 ld      [%i2+0x1C], %o1
F005CEF8: 90022001                 inc     %o0
F005CEFC: d026a018                 st      %o0, [%i2+0x18]
F005CF00: 92026001                 inc     %o1
F005CF04: 10800013                 ba      loc_F005CF50
F005CF08: d226a01c                 st      %o1, [%i2+0x1C]
F005CF0C: 11000080                 sethi   0x20000, %o0! jumptable F005CE98 case 5
F005CF10: 808c0008                 btst    %o0, %l0
F005CF14: 028000fb                 be      locret_F005D300
F005CF18: b0102011                 mov     0x11, %i0
F005CF1C: f406a004                 ld      [%i2+4], %i2
F005CF20: d0068000                 ld      [%i2], %o0
F005CF24: 80a22000                 cmp     %o0, 0
F005CF28: 12bffffe                 bne     loc_F005CF20
F005CF2C: 01000000                 nop
F005CF30: 4000e7de                 call    _simple_lock_try
F005CF34: 9010001a                 mov     %i2, %o0
F005CF38: 80a22000                 cmp     %o0, 0
F005CF3C: 02bffff9                 be      loc_F005CF20
F005CF40: 01000000                 nop
F005CF44: d006a020                 ld      [%i2+0x20], %o0
F005CF48: 90022001                 inc     %o0
F005CF4C: d026a020                 st      %o0, [%i2+0x20]
F005CF50: d006a004                 ld      [%i2+4], %o0
F005CF54: 90022001                 inc     %o0
F005CF58: d026a004                 st      %o0, [%i2+4]
F005CF5C: c0268000                 clr     [%i2]
F005CF60: 108000e4                 ba      loc_F005D2F0
F005CF64: f4274000                 st      %i2, [%i5]
F005CF68: 11000080                 sethi   0x20000, %o0! jumptable F005CE98 case 0
F005CF6C: 808c0008                 btst    %o0, %l0
F005CF70: 028000e3                 be      loc_F005D2FC
F005CF74: b8102000                 mov     0, %i4
F005CF78: f606a004                 ld      [%i2+4], %i3
F005CF7C: d006c000                 ld      [%i3], %o0
F005CF80: 80a22000                 cmp     %o0, 0
F005CF84: 12bffffe                 bne     loc_F005CF7C
F005CF88: 01000000                 nop
F005CF8C: 4000e7c7                 call    _simple_lock_try
F005CF90: 9010001b                 mov     %i3, %o0
F005CF94: 80a22000                 cmp     %o0, 0
F005CF98: 02bffff9                 be      loc_F005CF7C
F005CF9C: 11000040                 sethi   0x10000, %o0
F005CFA0: 808c0008                 btst    %o0, %l0
F005CFA4: 0280000a                 be      loc_F005CFCC
F005CFA8: 90100018                 mov     %i0, %o0
F005CFAC: 9210001b                 mov     %i3, %o1
F005CFB0: 94100019                 mov     %i1, %o2
F005CFB4: 7fffdd6a                 call    _ipc_hash_insert
F005CFB8: 9610001a                 mov     %i2, %o3
F005CFBC: d006e004                 ld      [%i3+4], %o0
F005CFC0: 90022001                 inc     %o0
F005CFC4: 10800014                 ba      loc_F005D014
F005CFC8: d026e004                 st      %o0, [%i3+4]
F005CFCC: d006a008                 ld      [%i2+8], %o0
F005CFD0: 80a22000                 cmp     %o0, 0
F005CFD4: 02800008                 be      loc_F005CFF4
F005CFD8: 90100018                 mov     %i0, %o0
F005CFDC: 9210001b                 mov     %i3, %o1
F005CFE0: 94100019                 mov     %i1, %o2
F005CFE4: 7ffffb62                 call    _ipc_right_dncancel
F005CFE8: 9610001a                 mov     %i2, %o3
F005CFEC: 10800003                 ba      loc_F005CFF8
F005CFF0: b8100008                 mov     %o0, %i4
F005CFF4: b8102000                 mov     0, %i4
F005CFF8: 11000800                 sethi   0x200000, %o0
F005CFFC: 808c0008                 btst    %o0, %l0
F005D000: 02800004                 be      loc_F005D010
F005D004: 90100018                 mov     %i0, %o0
F005D008: 7fffebda                 call    _ipc_marequest_cancel
F005D00C: 92100019                 mov     %i1, %o1
F005D010: c026a004                 clr     [%i2+4]
F005D014: 11000080                 sethi   0x20000, %o0
F005D018: 902c0008                 andn    %l0, %o0, %o0
F005D01C: d0268000                 st      %o0, [%i2]
F005D020: 7ffff642                 call    _ipc_port_clear_receiver
F005D024: 9010001b                 mov     %i3, %o0
F005D028: c026e010                 clr     [%i3+0x10]
F005D02C: c026e00c                 clr     [%i3+0xC]
F005D030: c026c000                 clr     [%i3]
F005D034: f6274000                 st      %i3, [%i5]
F005D038: 108000af                 ba      loc_F005D2F4
F005D03C: f8248000                 st      %i4, [%l2]
F005D040: 11000400                 sethi   0x100000, %o0! jumptable F005CE98 case 3
F005D044: 808c0008                 btst    %o0, %l0
F005D048: 12800099                 bne     loc_F005D2AC
F005D04C: 80a72000                 cmp     %i4, 0
F005D050: 11000140                 sethi   0x50000, %o0
F005D054: 808c0008                 btst    %o0, %l0
F005D058: 028000a9                 be      loc_F005D2FC
F005D05C: 90100018                 mov     %i0, %o0
F005D060: 94100019                 mov     %i1, %o2
F005D064: f006a004                 ld      [%i2+4], %i0
F005D068: 9610001a                 mov     %i2, %o3
F005D06C: 7ffffb8e                 call    _ipc_right_check
F005D070: 92100018                 mov     %i0, %o1
F005D074: 80a22000                 cmp     %o0, 0
F005D078: 02800007                 be      loc_F005D094
F005D07C: 11001000                 sethi   0x400000, %o0
F005D080: 808c0008                 btst    %o0, %l0
F005D084: 1280009f                 bne     locret_F005D300
F005D088: b010200f                 mov     0xF, %i0
F005D08C: 10800088                 ba      loc_F005D2AC
F005D090: 80a72000                 cmp     %i4, 0
F005D094: 11000040                 sethi   0x10000, %o0
F005D098: 808c0008                 btst    %o0, %l0
F005D09C: 32800005                 bne,a   loc_F005D0B0
F005D0A0: d006201c                 ld      [%i0+0x1C], %o0
F005D0A4: c0260000                 clr     [%i0]
F005D0A8: 10800096                 ba      locret_F005D300
F005D0AC: b0102011                 mov     0x11, %i0
F005D0B0: 90022001                 inc     %o0
F005D0B4: d026201c                 st      %o0, [%i0+0x1C]
F005D0B8: d0062004                 ld      [%i0+4], %o0
F005D0BC: 90022001                 inc     %o0
F005D0C0: d0262004                 st      %o0, [%i0+4]
F005D0C4: c0260000                 clr     [%i0]
F005D0C8: 1080008a                 ba      loc_F005D2F0
F005D0CC: f0274000                 st      %i0, [%i5]
F005D0D0: 11000400                 sethi   0x100000, %o0! jumptable F005CE98 case 1
F005D0D4: 808c0008                 btst    %o0, %l0
F005D0D8: 12800079                 bne     loc_F005D2BC
F005D0DC: a2102000                 mov     0, %l1
F005D0E0: 11000140                 sethi   0x50000, %o0
F005D0E4: 808c0008                 btst    %o0, %l0
F005D0E8: 02800085                 be      loc_F005D2FC
F005D0EC: 90100018                 mov     %i0, %o0
F005D0F0: 94100019                 mov     %i1, %o2
F005D0F4: f606a004                 ld      [%i2+4], %i3
F005D0F8: 9610001a                 mov     %i2, %o3
F005D0FC: 7ffffb6a                 call    _ipc_right_check
F005D100: 9210001b                 mov     %i3, %o1
F005D104: 80a22000                 cmp     %o0, 0
F005D108: 12800046                 bne     loc_F005D220
F005D10C: 11001000                 sethi   0x400000, %o0
F005D110: 11000040                 sethi   0x10000, %o0
F005D114: 808c0008                 btst    %o0, %l0
F005D118: 0280004b                 be      loc_F005D244
F005D11C: 1100003f                 sethi   0xFC00, %o0
F005D120: 901223ff                 bset    0x3FF, %o0
F005D124: 900c0008                 and     %l0, %o0, %o0
F005D128: 80a22001                 cmp     %o0, 1
F005D12C: 32800022                 bne,a   loc_F005D1B4
F005D130: d006e01c                 ld      [%i3+0x1C], %o0
F005D134: 11000080                 sethi   0x20000, %o0
F005D138: 808c0008                 btst    %o0, %l0
F005D13C: 22800006                 be,a    loc_F005D154
F005D140: d006a008                 ld      [%i2+8], %o0
F005D144: d006e004                 ld      [%i3+4], %o0
F005D148: 90022001                 inc     %o0
F005D14C: 10800017                 ba      loc_F005D1A8
F005D150: d026e004                 st      %o0, [%i3+4]
F005D154: 80a22000                 cmp     %o0, 0
F005D158: 02800007                 be      loc_F005D174
F005D15C: 90100018                 mov     %i0, %o0
F005D160: 9210001b                 mov     %i3, %o1
F005D164: 94100019                 mov     %i1, %o2
F005D168: 7ffffb01                 call    _ipc_right_dncancel
F005D16C: 9610001a                 mov     %i2, %o3
F005D170: a2100008                 mov     %o0, %l1
F005D174: 90100018                 mov     %i0, %o0
F005D178: 9210001b                 mov     %i3, %o1
F005D17C: 94100019                 mov     %i1, %o2
F005D180: 7fffdd0c                 call    _ipc_hash_delete
F005D184: 9610001a                 mov     %i2, %o3
F005D188: 11000800                 sethi   0x200000, %o0
F005D18C: 808c0008                 btst    %o0, %l0
F005D190: 22800006                 be,a    loc_F005D1A8
F005D194: c026a004                 clr     [%i2+4]
F005D198: 90100018                 mov     %i0, %o0
F005D19C: 7fffeb75                 call    _ipc_marequest_cancel
F005D1A0: 92100019                 mov     %i1, %o1
F005D1A4: c026a004                 clr     [%i2+4]
F005D1A8: 113fff80                 sethi   -0x20000, %o0
F005D1AC: 10800008                 ba      loc_F005D1CC
F005D1B0: 900c0008                 and     %l0, %o0, %o0
F005D1B4: 90022001                 inc     %o0
F005D1B8: d026e01c                 st      %o0, [%i3+0x1C]
F005D1BC: d006e004                 ld      [%i3+4], %o0
F005D1C0: 90022001                 inc     %o0
F005D1C4: d026e004                 st      %o0, [%i3+4]
F005D1C8: 90043fff                 add     %l0, -1, %o0
F005D1CC: d0268000                 st      %o0, [%i2]
F005D1D0: c026c000                 clr     [%i3]
F005D1D4: f6274000                 st      %i3, [%i5]
F005D1D8: 10800047                 ba      loc_F005D2F4
F005D1DC: e2248000                 st      %l1, [%l2]
F005D1E0: 11000400                 sethi   0x100000, %o0! jumptable F005CE98 case 2
F005D1E4: 808c0008                 btst    %o0, %l0
F005D1E8: 12800036                 bne     loc_F005D2C0
F005D1EC: 80a72000                 cmp     %i4, 0
F005D1F0: 11000140                 sethi   0x50000, %o0
F005D1F4: 808c0008                 btst    %o0, %l0
F005D1F8: 02800041                 be      loc_F005D2FC
F005D1FC: 90100018                 mov     %i0, %o0
F005D200: 94100019                 mov     %i1, %o2
F005D204: f606a004                 ld      [%i2+4], %i3
F005D208: 9610001a                 mov     %i2, %o3
F005D20C: 7ffffb26                 call    _ipc_right_check
F005D210: 9210001b                 mov     %i3, %o1
F005D214: 80a22000                 cmp     %o0, 0
F005D218: 02800007                 be      loc_F005D234
F005D21C: 11001000                 sethi   0x400000, %o0
F005D220: 808c0008                 btst    %o0, %l0
F005D224: 12800037                 bne     locret_F005D300
F005D228: b010200f                 mov     0xF, %i0
F005D22C: 10800024                 ba      loc_F005D2BC
F005D230: e0068000                 ld      [%i2], %l0
F005D234: 11000100                 sethi   0x40000, %o0
F005D238: 808c0008                 btst    %o0, %l0
F005D23C: 32800005                 bne,a   loc_F005D250
F005D240: d006a008                 ld      [%i2+8], %o0
F005D244: c026c000                 clr     [%i3]
F005D248: 1080002e                 ba      locret_F005D300
F005D24C: b0102011                 mov     0x11, %i0
F005D250: 80a22000                 cmp     %o0, 0
F005D254: 02800008                 be      loc_F005D274
F005D258: 90100018                 mov     %i0, %o0
F005D25C: 9210001b                 mov     %i3, %o1
F005D260: 94100019                 mov     %i1, %o2
F005D264: 7ffffac2                 call    _ipc_right_dncancel
F005D268: 9610001a                 mov     %i2, %o3
F005D26C: 10800003                 ba      loc_F005D278
F005D270: 92100008                 mov     %o0, %o1
F005D274: 92102000                 mov     0, %o1
F005D278: c026c000                 clr     [%i3]
F005D27C: c026a004                 clr     [%i2+4]
F005D280: 11000100                 sethi   0x40000, %o0
F005D284: 902c0008                 andn    %l0, %o0, %o0
F005D288: d0268000                 st      %o0, [%i2]
F005D28C: f6274000                 st      %i3, [%i5]
F005D290: 10800019                 ba      loc_F005D2F4
F005D294: d2248000                 st      %o1, [%l2]
F005D298: 113c043d                 sethi   %hi(aIpcRightCopyin_0), %o0! jumptable F005CE98 default case
F005D29C: 7ffedfb5                 call    _panic
F005D2A0: 90122320                 bset    %lo(aIpcRightCopyin_0), %o0! "ipc_right_copyin: strange rights"
F005D2A4: 10800017                 ba      locret_F005D300
F005D2A8: b0102000                 mov     0, %i0
F005D2AC: 02800015                 be      locret_F005D300
F005D2B0: b0102011                 mov     0x11, %i0
F005D2B4: 1080000e                 ba      loc_F005D2EC
F005D2B8: 90103fff                 mov     -1, %o0
F005D2BC: 80a72000                 cmp     %i4, 0
F005D2C0: 0280000f                 be      loc_F005D2FC
F005D2C4: 1100003f                 sethi   0xFC00, %o0
F005D2C8: 901223ff                 bset    0x3FF, %o0
F005D2CC: 900c0008                 and     %l0, %o0, %o0
F005D2D0: 80a22001                 cmp     %o0, 1
F005D2D4: 32800004                 bne,a   loc_F005D2E4
F005D2D8: 90043fff                 add     %l0, -1, %o0
F005D2DC: 11000400                 sethi   0x100000, %o0
F005D2E0: 902c0008                 andn    %l0, %o0, %o0
F005D2E4: d0268000                 st      %o0, [%i2]
F005D2E8: 90103fff                 mov     -1, %o0
F005D2EC: d0274000                 st      %o0, [%i5]
F005D2F0: c0248000                 clr     [%l2]
F005D2F4: 10800003                 ba      locret_F005D300
F005D2F8: b0102000                 mov     0, %i0
F005D2FC: b0102011                 mov     0x11, %i0
F005D300: 81c7e008                 ret
F005D304: 81e80000                 restore
