F00ACD30: 9de3bf88                 save    %sp, -0x78, %sp
F00ACD34: a0100018                 mov     %i0, %l0
F00ACD38: f2064000                 ld      [%i1], %i1
F00ACD3C: 11000008                 sethi   0x2000, %o0
F00ACD40: 9336600e                 srl     %i1, 14, %o1
F00ACD44: 920a601f                 and     %o1, 0x1F, %o1
F00ACD48: a3366019                 srl     %i1, 25, %l1
F00ACD4C: a20c601f                 and     %l1, 0x1F, %l1
F00ACD50: 808e4008                 btst    %o0, %i1
F00ACD54: 12800016                 bne     loc_F00ACDAC
F00ACD58: b00e601f                 and     %i1, 0x1F, %i0
F00ACD5C: 90100009                 mov     %o1, %o0
F00ACD60: 9210001a                 mov     %i2, %o1
F00ACD64: 9410001b                 mov     %i3, %o2
F00ACD68: 9607bff4                 add     %fp, var_C, %o3
F00ACD6C: 400007d7                 call    _read_iureg
F00ACD70: 98100010                 mov     %l0, %o4
F00ACD74: 80a22000                 cmp     %o0, 0
F00ACD78: 32800093                 bne,a   locret_F00ACFC4
F00ACD7C: b0102006                 mov     6, %i0
F00ACD80: 90100018                 mov     %i0, %o0
F00ACD84: 9210001a                 mov     %i2, %o1
F00ACD88: 9410001b                 mov     %i3, %o2
F00ACD8C: 9607bff0                 add     %fp, var_10, %o3
F00ACD90: 400007ce                 call    _read_iureg
F00ACD94: 98100010                 mov     %l0, %o4
F00ACD98: 80a22000                 cmp     %o0, 0
F00ACD9C: 1280008a                 bne     locret_F00ACFC4
F00ACDA0: b0102006                 mov     6, %i0
F00ACDA4: 1080000f                 ba      loc_F00ACDE0
F00ACDA8: d007bff4                 ld      [%fp+var_C], %o0
F00ACDAC: 912e6013                 sll     %i1, 19, %o0
F00ACDB0: 913a2013                 sra     %o0, 19, %o0
F00ACDB4: d027bff4                 st      %o0, [%fp+var_C]
F00ACDB8: 90100009                 mov     %o1, %o0
F00ACDBC: 9210001a                 mov     %i2, %o1
F00ACDC0: 9410001b                 mov     %i3, %o2
F00ACDC4: 9607bff0                 add     %fp, var_10, %o3
F00ACDC8: 400007c0                 call    _read_iureg
F00ACDCC: 98100010                 mov     %l0, %o4
F00ACDD0: 80a22000                 cmp     %o0, 0
F00ACDD4: 1280007c                 bne     locret_F00ACFC4
F00ACDD8: b0102006                 mov     6, %i0
F00ACDDC: d007bff4                 ld      [%fp+var_C], %o0
F00ACDE0: d207bff0                 ld      [%fp+var_10], %o1
F00ACDE4: 90020009                 add     %o0, %o1, %o0
F00ACDE8: d027bff4                 st      %o0, [%fp+var_C]
F00ACDEC: d207bff4                 ld      [%fp+var_C], %o1
F00ACDF0: 91366013                 srl     %i1, 19, %o0
F00ACDF4: 940a2007                 and     %o0, 7, %o2
F00ACDF8: 80a2a007                 cmp     %o2, 7! switch 8 cases
F00ACDFC: 18800068                 bgu     def_F00ACE14! jumptable F00ACE14 default case, cases 2,6
F00ACE00: d2242020                 st      %o1, [%l0+0x20]
F00ACE04: 113c02b39012221c         set     jpt_F00ACE14, %o0
F00ACE0C: 932aa002                 sll     %o2, 2, %o1
F00ACE10: d0024008                 ld      [%o1+%o0], %o0
F00ACE14: 81c20000                 jmp     %o0! switch jump
F00ACE18: 01000000                 nop
F00ACE3C: d007bff4                 ld      [%fp+var_C], %o0! jumptable F00ACE14 case 0
F00ACE40: 9207bfec                 add     %fp, var_14, %o1
F00ACE44: 40000776                 call    __fp_read_word
F00ACE48: 94100010                 mov     %l0, %o2
F00ACE4C: 80a22000                 cmp     %o0, 0
F00ACE50: 1280005d                 bne     locret_F00ACFC4
F00ACE54: b0100008                 mov     %o0, %i0
F00ACE58: d207bfec                 ld      [%fp+var_14], %o1
F00ACE5C: 912c6002                 sll     %l1, 2, %o0
F00ACE60: 10800053                 ba      loc_F00ACFAC
F00ACE64: d2270008                 st      %o1, [%i4+%o0]
F00ACE68: d007bff4                 ld      [%fp+var_C], %o0! jumptable F00ACE14 case 1
F00ACE6C: 9207bfec                 add     %fp, var_14, %o1
F00ACE70: 4000076b                 call    __fp_read_word
F00ACE74: 94100010                 mov     %l0, %o2
F00ACE78: 80a22000                 cmp     %o0, 0
F00ACE7C: 12800052                 bne     locret_F00ACFC4
F00ACE80: b0100008                 mov     %o0, %i0
F00ACE84: d007bfec                 ld      [%fp+var_14], %o0
F00ACE88: 10800049                 ba      loc_F00ACFAC
F00ACE8C: d0272080                 st      %o0, [%i4+0x80]
F00ACE90: d007bff4                 ld      [%fp+var_C], %o0! jumptable F00ACE14 case 3
F00ACE94: 808a2007                 btst    7, %o0
F00ACE98: 1280004b                 bne     locret_F00ACFC4
F00ACE9C: b0102005                 mov     5, %i0
F00ACEA0: b007bfec                 add     %fp, var_14, %i0
F00ACEA4: 92100018                 mov     %i0, %o1
F00ACEA8: 4000075d                 call    __fp_read_word
F00ACEAC: 94100010                 mov     %l0, %o2
F00ACEB0: 80a22000                 cmp     %o0, 0
F00ACEB4: 32800044                 bne,a   locret_F00ACFC4
F00ACEB8: b0100008                 mov     %o0, %i0
F00ACEBC: 92100018                 mov     %i0, %o1
F00ACEC0: 94100010                 mov     %l0, %o2
F00ACEC4: 900c607e                 and     %l1, 0x7E, %o0
F00ACEC8: d607bfec                 ld      [%fp+var_14], %o3
F00ACECC: a12a2002                 sll     %o0, 2, %l0
F00ACED0: d007bff4                 ld      [%fp+var_C], %o0
F00ACED4: d6270010                 st      %o3, [%i4+%l0]
F00ACED8: 40000751                 call    __fp_read_word
F00ACEDC: 90022004                 inc     4, %o0
F00ACEE0: 80a22000                 cmp     %o0, 0
F00ACEE4: 12800038                 bne     locret_F00ACFC4
F00ACEE8: b0100008                 mov     %o0, %i0
F00ACEEC: d207bfec                 ld      [%fp+var_14], %o1
F00ACEF0: 9004001c                 add     %l0, %i4, %o0
F00ACEF4: 1080002e                 ba      loc_F00ACFAC
F00ACEF8: d2222004                 st      %o1, [%o0+4]
F00ACEFC: 912c6002                 sll     %l1, 2, %o0! jumptable F00ACE14 case 4
F00ACF00: d2070008                 ld      [%i4+%o0], %o1
F00ACF04: 94100010                 mov     %l0, %o2
F00ACF08: d007bff4                 ld      [%fp+var_C], %o0
F00ACF0C: 1080001e                 ba      loc_F00ACF84
F00ACF10: d227bfec                 st      %o1, [%fp+var_14]
F00ACF14: 94100010                 mov     %l0, %o2! jumptable F00ACE14 case 5
F00ACF18: d6072080                 ld      [%i4+0x80], %o3
F00ACF1C: 13000c04                 sethi   0x301000, %o1
F00ACF20: d007bff4                 ld      [%fp+var_C], %o0
F00ACF24: 922ac009                 andn    %o3, %o1, %o1
F00ACF28: 17000380                 sethi   0xE0000, %o3
F00ACF2C: 9212400b                 bset    %o3, %o1
F00ACF30: 10800015                 ba      loc_F00ACF84
F00ACF34: d227bfec                 st      %o1, [%fp+var_14]
F00ACF38: d007bff4                 ld      [%fp+var_C], %o0! jumptable F00ACE14 case 7
F00ACF3C: 808a2007                 btst    7, %o0
F00ACF40: 12800021                 bne     locret_F00ACFC4
F00ACF44: b0102005                 mov     5, %i0
F00ACF48: 920c607e                 and     %l1, 0x7E, %o1
F00ACF4C: b12a6002                 sll     %o1, 2, %i0
F00ACF50: d2070018                 ld      [%i4+%i0], %o1
F00ACF54: 94100010                 mov     %l0, %o2
F00ACF58: 4000074a                 call    __fp_write_word
F00ACF5C: d227bfec                 st      %o1, [%fp+var_14]
F00ACF60: 80a22000                 cmp     %o0, 0
F00ACF64: 32800018                 bne,a   locret_F00ACFC4
F00ACF68: b0100008                 mov     %o0, %i0
F00ACF6C: 9006001c                 add     %i0, %i4, %o0
F00ACF70: d2022004                 ld      [%o0+4], %o1
F00ACF74: 94100010                 mov     %l0, %o2
F00ACF78: d007bff4                 ld      [%fp+var_C], %o0
F00ACF7C: d227bfec                 st      %o1, [%fp+var_14]
F00ACF80: 90022004                 inc     4, %o0
F00ACF84: 4000073f                 call    __fp_write_word
F00ACF88: 01000000                 nop
F00ACF8C: 80a22000                 cmp     %o0, 0
F00ACF90: 02800007                 be      loc_F00ACFAC
F00ACF94: b0100008                 mov     %o0, %i0
F00ACF98: 3080000b                 ba,a    locret_F00ACFC4
F00ACF9C: d006a004                 ld      [%i2+4], %o0! jumptable F00ACE14 default case, cases 2,6
F00ACFA0: b0102003                 mov     3, %i0
F00ACFA4: 10800008                 ba      locret_F00ACFC4
F00ACFA8: d0242020                 st      %o0, [%l0+0x20]
F00ACFAC: d206a008                 ld      [%i2+8], %o1
F00ACFB0: b0102000                 mov     0, %i0
F00ACFB4: d006a008                 ld      [%i2+8], %o0
F00ACFB8: d226a004                 st      %o1, [%i2+4]
F00ACFBC: 90022004                 inc     4, %o0
F00ACFC0: d026a008                 st      %o0, [%i2+8]
F00ACFC4: 81c7e008                 ret
F00ACFC8: 81e80000                 restore
