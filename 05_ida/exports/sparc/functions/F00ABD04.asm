F00ABD04: 9de3bf78                 save    %sp, -0x88, %sp
F00ABD08: d0064000                 ld      [%i1], %o0
F00ABD0C: d0268000                 st      %o0, [%i2]
F00ABD10: d0066004                 ld      [%i1+4], %o0
F00ABD14: d026a004                 st      %o0, [%i2+4]
F00ABD18: d0066008                 ld      [%i1+8], %o0
F00ABD1C: d026a008                 st      %o0, [%i2+8]
F00ABD20: d006600c                 ld      [%i1+0xC], %o0
F00ABD24: d026a00c                 st      %o0, [%i2+0xC]
F00ABD28: d0066010                 ld      [%i1+0x10], %o0
F00ABD2C: d026a010                 st      %o0, [%i2+0x10]
F00ABD30: d0066014                 ld      [%i1+0x14], %o0
F00ABD34: d026a014                 st      %o0, [%i2+0x14]
F00ABD38: d0066018                 ld      [%i1+0x18], %o0
F00ABD3C: d026a018                 st      %o0, [%i2+0x18]
F00ABD40: d006601c                 ld      [%i1+0x1C], %o0
F00ABD44: d026a01c                 st      %o0, [%i2+0x1C]
F00ABD48: d0066020                 ld      [%i1+0x20], %o0
F00ABD4C: d026a020                 st      %o0, [%i2+0x20]
F00ABD50: d2066004                 ld      [%i1+4], %o1
F00ABD54: 80a26005                 cmp     %o1, 5! switch 6 cases
F00ABD58: 1880001c                 bgu     def_F00ABD6C! jumptable F00ABD6C default case, case 3
F00ABD5C: 113c02af                 sethi   %hi(jpt_F00ABD6C), %o0
F00ABD60: 90122174                 bset    %lo(jpt_F00ABD6C), %o0
F00ABD64: 932a6002                 sll     %o1, 2, %o1
F00ABD68: d0024008                 ld      [%o1+%o0], %o0
F00ABD6C: 81c20000                 jmp     %o0! switch jump
F00ABD70: 01000000                 nop
F00ABD8C: d0064000                 ld      [%i1], %o0! jumptable F00ABD6C case 2
F00ABD90: 80a22001                 cmp     %o0, 1
F00ABD94: 1280015f                 bne     locret_F00AC310! jumptable F00ABD6C cases 0,4,5
F00ABD98: 90100018                 mov     %i0, %o0
F00ABD9C: 30800006                 ba,a    loc_F00ABDB4
F00ABDA0: d0064000                 ld      [%i1], %o0! jumptable F00ABD6C case 1
F00ABDA4: 80a22001                 cmp     %o0, 1
F00ABDA8: 32800009                 bne,a   loc_F00ABDCC
F00ABDAC: d2066008                 ld      [%i1+8], %o1
F00ABDB0: 90100018                 mov     %i0, %o0
F00ABDB4: 40000b4c                 call    _fpu_error_nan
F00ABDB8: 9210001a                 mov     %i2, %o1
F00ABDBC: 90102004                 mov     4, %o0
F00ABDC0: 10800154                 ba      locret_F00AC310! jumptable F00ABD6C cases 0,4,5
F00ABDC4: d026a004                 st      %o0, [%i2+4]
F00ABDC8: d2066008                 ld      [%i1+8], %o1! jumptable F00ABD6C default case, case 3
F00ABDCC: 808a6001                 btst    1, %o1
F00ABDD0: 0280001d                 be      loc_F00ABE44
F00ABDD4: b006600c                 add     %i1, 0xC, %i0
F00ABDD8: 90027fff                 add     %o1, -1, %o0
F00ABDDC: 9332201f                 srl     %o0, 31, %o1
F00ABDE0: 90020009                 add     %o0, %o1, %o0
F00ABDE4: 913a2001                 sra     %o0, 1, %o0
F00ABDE8: d026a008                 st      %o0, [%i2+8]
F00ABDEC: d206600c                 ld      [%i1+0xC], %o1
F00ABDF0: d0066010                 ld      [%i1+0x10], %o0
F00ABDF4: d4066010                 ld      [%i1+0x10], %o2
F00ABDF8: 932a6001                 sll     %o1, 1, %o1
F00ABDFC: 9132201f                 srl     %o0, 31, %o0
F00ABE00: 92124008                 bset    %o0, %o1
F00ABE04: d226600c                 st      %o1, [%i1+0xC]
F00ABE08: d0066014                 ld      [%i1+0x14], %o0
F00ABE0C: 952aa001                 sll     %o2, 1, %o2
F00ABE10: d2066014                 ld      [%i1+0x14], %o1
F00ABE14: 9132201f                 srl     %o0, 31, %o0
F00ABE18: 94128008                 bset    %o0, %o2
F00ABE1C: d4266010                 st      %o2, [%i1+0x10]
F00ABE20: d0066018                 ld      [%i1+0x18], %o0
F00ABE24: 932a6001                 sll     %o1, 1, %o1
F00ABE28: 9132201f                 srl     %o0, 31, %o0
F00ABE2C: 92124008                 bset    %o0, %o1
F00ABE30: d0066018                 ld      [%i1+0x18], %o0
F00ABE34: d2266014                 st      %o1, [%i1+0x14]
F00ABE38: 912a2001                 sll     %o0, 1, %o0
F00ABE3C: 10800006                 ba      loc_F00ABE54
F00ABE40: d0266018                 st      %o0, [%i1+0x18]
F00ABE44: 9132601f                 srl     %o1, 31, %o0
F00ABE48: 90024008                 add     %o1, %o0, %o0
F00ABE4C: 913a2001                 sra     %o0, 1, %o0
F00ABE50: d026a008                 st      %o0, [%i2+8]
F00ABE54: c027bff4                 clr     [%fp+var_C]
F00ABE58: c027bff0                 clr     [%fp+var_10]
F00ABE5C: c027bfec                 clr     [%fp+var_14]
F00ABE60: c027bfe8                 clr     [%fp+var_18]
F00ABE64: c027bfe4                 clr     [%fp+var_1C]
F00ABE68: c027bfe0                 clr     [%fp+var_20]
F00ABE6C: c027bfdc                 clr     [%fp+var_24]
F00ABE70: c027bfd8                 clr     [%fp+var_28]
F00ABE74: a0102000                 mov     0, %l0
F00ABE78: 33000040                 sethi   0x10000, %i1
F00ABE7C: 17200000                 sethi   0x80000000, %o3
F00ABE80: d007bfd8                 ld      [%fp+var_28], %o0
F00ABE84: 92020019                 add     %o0, %i1, %o1
F00ABE88: d227bfe8                 st      %o1, [%fp+var_18]
F00ABE8C: d0060000                 ld      [%i0], %o0
F00ABE90: 80a24008                 cmp     %o1, %o0
F00ABE94: 18800007                 bgu     loc_F00ABEB0
F00ABE98: 90024019                 add     %o1, %i1, %o0
F00ABE9C: d027bfd8                 st      %o0, [%fp+var_28]
F00ABEA0: d0060000                 ld      [%i0], %o0
F00ABEA4: a0040019                 add     %l0, %i1, %l0
F00ABEA8: 90220009                 sub     %o0, %o1, %o0
F00ABEAC: d0260000                 st      %o0, [%i0]
F00ABEB0: d2060000                 ld      [%i0], %o1
F00ABEB4: b3366001                 srl     %i1, 1, %i1
F00ABEB8: d0062004                 ld      [%i0+4], %o0
F00ABEBC: 80a66000                 cmp     %i1, 0
F00ABEC0: d4062004                 ld      [%i0+4], %o2
F00ABEC4: 932a6001                 sll     %o1, 1, %o1
F00ABEC8: 900a000b                 and     %o0, %o3, %o0
F00ABECC: 9132201f                 srl     %o0, 31, %o0
F00ABED0: 92124008                 bset    %o0, %o1
F00ABED4: d2260000                 st      %o1, [%i0]
F00ABED8: d0062008                 ld      [%i0+8], %o0
F00ABEDC: 952aa001                 sll     %o2, 1, %o2
F00ABEE0: d2062008                 ld      [%i0+8], %o1
F00ABEE4: 900a000b                 and     %o0, %o3, %o0
F00ABEE8: 9132201f                 srl     %o0, 31, %o0
F00ABEEC: 94128008                 bset    %o0, %o2
F00ABEF0: d4262004                 st      %o2, [%i0+4]
F00ABEF4: d006200c                 ld      [%i0+0xC], %o0
F00ABEF8: 932a6001                 sll     %o1, 1, %o1
F00ABEFC: 900a000b                 and     %o0, %o3, %o0
F00ABF00: 9132201f                 srl     %o0, 31, %o0
F00ABF04: 92124008                 bset    %o0, %o1
F00ABF08: d006200c                 ld      [%i0+0xC], %o0
F00ABF0C: d2262008                 st      %o1, [%i0+8]
F00ABF10: 912a2001                 sll     %o0, 1, %o0
F00ABF14: 12bfffdb                 bne     loc_F00ABE80
F00ABF18: d026200c                 st      %o0, [%i0+0xC]
F00ABF1C: e026a00c                 st      %l0, [%i2+0xC]
F00ABF20: a0102000                 mov     0, %l0
F00ABF24: 33200000                 sethi   0x80000000, %i1
F00ABF28: a407bfd8                 add     %fp, var_28, %l2
F00ABF2C: a2100019                 mov     %i1, %l1
F00ABF30: 9007bfe8                 add     %fp, var_18, %o0
F00ABF34: 92100018                 mov     %i0, %o1
F00ABF38: d607bfdc                 ld      [%fp+var_24], %o3
F00ABF3C: 94102002                 mov     2, %o2
F00ABF40: d807bfd8                 ld      [%fp+var_28], %o4
F00ABF44: 9602c019                 add     %o3, %i1, %o3
F00ABF48: d627bfec                 st      %o3, [%fp+var_14]
F00ABF4C: 40000b1d                 call    _fpu_cmpli
F00ABF50: d827bfe8                 st      %o4, [%fp+var_18]
F00ABF54: 80a22000                 cmp     %o0, 0
F00ABF58: 34800018                 bg,a    loc_F00ABFB8
F00ABF5C: d2060000                 ld      [%i0], %o1
F00ABF60: 9007bfdc                 add     %fp, var_24, %o0
F00ABF64: 94100019                 mov     %i1, %o2
F00ABF68: 96102000                 mov     0, %o3
F00ABF6C: d207bfec                 ld      [%fp+var_14], %o1
F00ABF70: 40000aeb                 call    _fpu_add3wc
F00ABF74: a0040019                 add     %l0, %i1, %l0
F00ABF78: 96100008                 mov     %o0, %o3
F00ABF7C: 90100012                 mov     %l2, %o0
F00ABF80: d207bfe8                 ld      [%fp+var_18], %o1
F00ABF84: 40000ae6                 call    _fpu_add3wc
F00ABF88: 94102000                 mov     0, %o2
F00ABF8C: d2062004                 ld      [%i0+4], %o1
F00ABF90: 90062004                 add     %i0, 4, %o0
F00ABF94: d407bfec                 ld      [%fp+var_14], %o2
F00ABF98: 40000aef                 call    _fpu_sub3wc
F00ABF9C: 96102000                 mov     0, %o3
F00ABFA0: d2060000                 ld      [%i0], %o1
F00ABFA4: 96100008                 mov     %o0, %o3
F00ABFA8: d407bfe8                 ld      [%fp+var_18], %o2
F00ABFAC: 40000aea                 call    _fpu_sub3wc
F00ABFB0: 90100018                 mov     %i0, %o0
F00ABFB4: d2060000                 ld      [%i0], %o1
F00ABFB8: b3366001                 srl     %i1, 1, %i1
F00ABFBC: d0062004                 ld      [%i0+4], %o0
F00ABFC0: 80a66000                 cmp     %i1, 0
F00ABFC4: d4062004                 ld      [%i0+4], %o2
F00ABFC8: 932a6001                 sll     %o1, 1, %o1
F00ABFCC: 900a0011                 and     %o0, %l1, %o0
F00ABFD0: 9132201f                 srl     %o0, 31, %o0
F00ABFD4: 92124008                 bset    %o0, %o1
F00ABFD8: d2260000                 st      %o1, [%i0]
F00ABFDC: d0062008                 ld      [%i0+8], %o0
F00ABFE0: 952aa001                 sll     %o2, 1, %o2
F00ABFE4: d2062008                 ld      [%i0+8], %o1
F00ABFE8: 900a0011                 and     %o0, %l1, %o0
F00ABFEC: 9132201f                 srl     %o0, 31, %o0
F00ABFF0: 94128008                 bset    %o0, %o2
F00ABFF4: d4262004                 st      %o2, [%i0+4]
F00ABFF8: d006200c                 ld      [%i0+0xC], %o0
F00ABFFC: 932a6001                 sll     %o1, 1, %o1
F00AC000: 900a0011                 and     %o0, %l1, %o0
F00AC004: 9132201f                 srl     %o0, 31, %o0
F00AC008: 92124008                 bset    %o0, %o1
F00AC00C: d006200c                 ld      [%i0+0xC], %o0
F00AC010: d2262008                 st      %o1, [%i0+8]
F00AC014: 912a2001                 sll     %o0, 1, %o0
F00AC018: 12bfffc6                 bne     loc_F00ABF30
F00AC01C: d026200c                 st      %o0, [%i0+0xC]
F00AC020: e026a010                 st      %l0, [%i2+0x10]
F00AC024: a0102000                 mov     0, %l0
F00AC028: 33200000                 sethi   0x80000000, %i1
F00AC02C: a407bfd8                 add     %fp, var_28, %l2
F00AC030: a2100019                 mov     %i1, %l1
F00AC034: 9007bfe8                 add     %fp, var_18, %o0
F00AC038: 92100018                 mov     %i0, %o1
F00AC03C: d607bfe0                 ld      [%fp+var_20], %o3
F00AC040: 94102003                 mov     3, %o2
F00AC044: d807bfdc                 ld      [%fp+var_24], %o4
F00AC048: 9602c019                 add     %o3, %i1, %o3
F00AC04C: d627bff0                 st      %o3, [%fp+var_10]
F00AC050: d607bfd8                 ld      [%fp+var_28], %o3
F00AC054: d827bfec                 st      %o4, [%fp+var_14]
F00AC058: 40000ada                 call    _fpu_cmpli
F00AC05C: d627bfe8                 st      %o3, [%fp+var_18]
F00AC060: 80a22000                 cmp     %o0, 0
F00AC064: 34800022                 bg,a    loc_F00AC0EC
F00AC068: d2060000                 ld      [%i0], %o1
F00AC06C: 9007bfe0                 add     %fp, var_20, %o0
F00AC070: 94100019                 mov     %i1, %o2
F00AC074: 96102000                 mov     0, %o3
F00AC078: d207bff0                 ld      [%fp+var_10], %o1
F00AC07C: 40000aa8                 call    _fpu_add3wc
F00AC080: a0040019                 add     %l0, %i1, %l0
F00AC084: 96100008                 mov     %o0, %o3
F00AC088: 9007bfdc                 add     %fp, var_24, %o0
F00AC08C: d207bfec                 ld      [%fp+var_14], %o1
F00AC090: 40000aa3                 call    _fpu_add3wc
F00AC094: 94102000                 mov     0, %o2
F00AC098: 96100008                 mov     %o0, %o3
F00AC09C: 90100012                 mov     %l2, %o0
F00AC0A0: d207bfe8                 ld      [%fp+var_18], %o1
F00AC0A4: 40000a9e                 call    _fpu_add3wc
F00AC0A8: 94102000                 mov     0, %o2
F00AC0AC: d2062008                 ld      [%i0+8], %o1
F00AC0B0: 90062008                 add     %i0, 8, %o0
F00AC0B4: d407bff0                 ld      [%fp+var_10], %o2
F00AC0B8: 40000aa7                 call    _fpu_sub3wc
F00AC0BC: 96102000                 mov     0, %o3
F00AC0C0: d2062004                 ld      [%i0+4], %o1
F00AC0C4: 96100008                 mov     %o0, %o3
F00AC0C8: d407bfec                 ld      [%fp+var_14], %o2
F00AC0CC: 40000aa2                 call    _fpu_sub3wc
F00AC0D0: 90062004                 add     %i0, 4, %o0
F00AC0D4: d2060000                 ld      [%i0], %o1
F00AC0D8: 96100008                 mov     %o0, %o3
F00AC0DC: d407bfe8                 ld      [%fp+var_18], %o2
F00AC0E0: 40000a9d                 call    _fpu_sub3wc
F00AC0E4: 90100018                 mov     %i0, %o0
F00AC0E8: d2060000                 ld      [%i0], %o1
F00AC0EC: b3366001                 srl     %i1, 1, %i1
F00AC0F0: d0062004                 ld      [%i0+4], %o0
F00AC0F4: 80a66000                 cmp     %i1, 0
F00AC0F8: d4062004                 ld      [%i0+4], %o2
F00AC0FC: 932a6001                 sll     %o1, 1, %o1
F00AC100: 900a0011                 and     %o0, %l1, %o0
F00AC104: 9132201f                 srl     %o0, 31, %o0
F00AC108: 92124008                 bset    %o0, %o1
F00AC10C: d2260000                 st      %o1, [%i0]
F00AC110: d0062008                 ld      [%i0+8], %o0
F00AC114: 952aa001                 sll     %o2, 1, %o2
F00AC118: d2062008                 ld      [%i0+8], %o1
F00AC11C: 900a0011                 and     %o0, %l1, %o0
F00AC120: 9132201f                 srl     %o0, 31, %o0
F00AC124: 94128008                 bset    %o0, %o2
F00AC128: d4262004                 st      %o2, [%i0+4]
F00AC12C: d006200c                 ld      [%i0+0xC], %o0
F00AC130: 932a6001                 sll     %o1, 1, %o1
F00AC134: 900a0011                 and     %o0, %l1, %o0
F00AC138: 9132201f                 srl     %o0, 31, %o0
F00AC13C: 92124008                 bset    %o0, %o1
F00AC140: d006200c                 ld      [%i0+0xC], %o0
F00AC144: d2262008                 st      %o1, [%i0+8]
F00AC148: 912a2001                 sll     %o0, 1, %o0
F00AC14C: 12bfffba                 bne     loc_F00AC034
F00AC150: d026200c                 st      %o0, [%i0+0xC]
F00AC154: e026a014                 st      %l0, [%i2+0x14]
F00AC158: a0102000                 mov     0, %l0
F00AC15C: 33200000                 sethi   0x80000000, %i1
F00AC160: a407bfd8                 add     %fp, var_28, %l2
F00AC164: a2100019                 mov     %i1, %l1
F00AC168: 9007bfe8                 add     %fp, var_18, %o0
F00AC16C: d607bfe4                 ld      [%fp+var_1C], %o3
F00AC170: 92100018                 mov     %i0, %o1
F00AC174: d807bfe0                 ld      [%fp+var_20], %o4
F00AC178: 94102004                 mov     4, %o2
F00AC17C: da07bfdc                 ld      [%fp+var_24], %o5
F00AC180: 9602c019                 add     %o3, %i1, %o3
F00AC184: d627bff4                 st      %o3, [%fp+var_C]
F00AC188: d827bff0                 st      %o4, [%fp+var_10]
F00AC18C: d607bfd8                 ld      [%fp+var_28], %o3
F00AC190: da27bfec                 st      %o5, [%fp+var_14]
F00AC194: 40000a8b                 call    _fpu_cmpli
F00AC198: d627bfe8                 st      %o3, [%fp+var_18]
F00AC19C: 80a22000                 cmp     %o0, 0
F00AC1A0: 3480002c                 bg,a    loc_F00AC250
F00AC1A4: d2060000                 ld      [%i0], %o1
F00AC1A8: 9007bfe4                 add     %fp, var_1C, %o0
F00AC1AC: 94100019                 mov     %i1, %o2
F00AC1B0: 96102000                 mov     0, %o3
F00AC1B4: d207bff4                 ld      [%fp+var_C], %o1
F00AC1B8: 40000a59                 call    _fpu_add3wc
F00AC1BC: a0040019                 add     %l0, %i1, %l0
F00AC1C0: 96100008                 mov     %o0, %o3
F00AC1C4: 9007bfe0                 add     %fp, var_20, %o0
F00AC1C8: d207bff0                 ld      [%fp+var_10], %o1
F00AC1CC: 40000a54                 call    _fpu_add3wc
F00AC1D0: 94102000                 mov     0, %o2
F00AC1D4: 96100008                 mov     %o0, %o3
F00AC1D8: 9007bfdc                 add     %fp, var_24, %o0
F00AC1DC: d207bfec                 ld      [%fp+var_14], %o1
F00AC1E0: 40000a4f                 call    _fpu_add3wc
F00AC1E4: 94102000                 mov     0, %o2
F00AC1E8: 96100008                 mov     %o0, %o3
F00AC1EC: 90100012                 mov     %l2, %o0
F00AC1F0: d207bfe8                 ld      [%fp+var_18], %o1
F00AC1F4: 40000a4a                 call    _fpu_add3wc
F00AC1F8: 94102000                 mov     0, %o2
F00AC1FC: d206200c                 ld      [%i0+0xC], %o1
F00AC200: 9006200c                 add     %i0, 0xC, %o0
F00AC204: d407bff4                 ld      [%fp+var_C], %o2
F00AC208: 40000a53                 call    _fpu_sub3wc
F00AC20C: 96102000                 mov     0, %o3
F00AC210: d2062008                 ld      [%i0+8], %o1
F00AC214: 96100008                 mov     %o0, %o3
F00AC218: d407bff0                 ld      [%fp+var_10], %o2
F00AC21C: 40000a4e                 call    _fpu_sub3wc
F00AC220: 90062008                 add     %i0, 8, %o0
F00AC224: d2062004                 ld      [%i0+4], %o1
F00AC228: 96100008                 mov     %o0, %o3
F00AC22C: d407bfec                 ld      [%fp+var_14], %o2
F00AC230: 40000a49                 call    _fpu_sub3wc
F00AC234: 90062004                 add     %i0, 4, %o0
F00AC238: d2060000                 ld      [%i0], %o1
F00AC23C: 96100008                 mov     %o0, %o3
F00AC240: d407bfe8                 ld      [%fp+var_18], %o2
F00AC244: 40000a44                 call    _fpu_sub3wc
F00AC248: 90100018                 mov     %i0, %o0
F00AC24C: d2060000                 ld      [%i0], %o1
F00AC250: b3366001                 srl     %i1, 1, %i1
F00AC254: d0062004                 ld      [%i0+4], %o0
F00AC258: 80a66000                 cmp     %i1, 0
F00AC25C: d4062004                 ld      [%i0+4], %o2
F00AC260: 932a6001                 sll     %o1, 1, %o1
F00AC264: 900a0011                 and     %o0, %l1, %o0
F00AC268: 9132201f                 srl     %o0, 31, %o0
F00AC26C: 92124008                 bset    %o0, %o1
F00AC270: d2260000                 st      %o1, [%i0]
F00AC274: d0062008                 ld      [%i0+8], %o0
F00AC278: 952aa001                 sll     %o2, 1, %o2
F00AC27C: d2062008                 ld      [%i0+8], %o1
F00AC280: 900a0011                 and     %o0, %l1, %o0
F00AC284: 9132201f                 srl     %o0, 31, %o0
F00AC288: 94128008                 bset    %o0, %o2
F00AC28C: d4262004                 st      %o2, [%i0+4]
F00AC290: d006200c                 ld      [%i0+0xC], %o0
F00AC294: 932a6001                 sll     %o1, 1, %o1
F00AC298: 900a0011                 and     %o0, %l1, %o0
F00AC29C: 9132201f                 srl     %o0, 31, %o0
F00AC2A0: 92124008                 bset    %o0, %o1
F00AC2A4: d006200c                 ld      [%i0+0xC], %o0
F00AC2A8: d2262008                 st      %o1, [%i0+8]
F00AC2AC: 912a2001                 sll     %o0, 1, %o0
F00AC2B0: 12bfffae                 bne     loc_F00AC168
F00AC2B4: d026200c                 st      %o0, [%i0+0xC]
F00AC2B8: e026a018                 st      %l0, [%i2+0x18]
F00AC2BC: d0060000                 ld      [%i0], %o0
F00AC2C0: d2062004                 ld      [%i0+4], %o1
F00AC2C4: d4062008                 ld      [%i0+8], %o2
F00AC2C8: 90120009                 bset    %o1, %o0
F00AC2CC: d206200c                 ld      [%i0+0xC], %o1
F00AC2D0: 9012000a                 bset    %o2, %o0
F00AC2D4: 80920009                 orcc    %o0, %o1, %g0
F00AC2D8: 12800005                 bne     loc_F00AC2EC
F00AC2DC: a0102001                 mov     1, %l0
F00AC2E0: c026a01c                 clr     [%i2+0x1C]
F00AC2E4: 1080000b                 ba      locret_F00AC310! jumptable F00ABD6C cases 0,4,5
F00AC2E8: c026a020                 clr     [%i2+0x20]
F00AC2EC: e026a020                 st      %l0, [%i2+0x20]
F00AC2F0: 9007bfd8                 add     %fp, var_28, %o0
F00AC2F4: 92100018                 mov     %i0, %o1
F00AC2F8: 40000a32                 call    _fpu_cmpli
F00AC2FC: 94102004                 mov     4, %o2
F00AC300: 80a22000                 cmp     %o0, 0
F00AC304: 36800003                 bge,a   locret_F00AC310! jumptable F00ABD6C cases 0,4,5
F00AC308: c026a01c                 clr     [%i2+0x1C]
F00AC30C: e026a01c                 st      %l0, [%i2+0x1C]
F00AC310: 81c7e008                 ret! jumptable F00ABD6C cases 0,4,5
F00AC314: 81e80000                 restore
