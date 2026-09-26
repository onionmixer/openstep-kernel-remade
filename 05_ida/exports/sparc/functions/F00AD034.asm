F00AD034: 9de3bf88                 save    %sp, -0x78, %sp
F00AD038: d2066004                 ld      [%i1+4], %o1
F00AD03C: d006a004                 ld      [%i2+4], %o0
F00AD040: 80a24008                 cmp     %o1, %o0
F00AD044: 36800006                 bge,a   loc_F00AD05C
F00AD048: d0064000                 ld      [%i1], %o0
F00AD04C: 90100019                 mov     %i1, %o0
F00AD050: b210001a                 mov     %i2, %i1
F00AD054: b4100008                 mov     %o0, %i2
F00AD058: d0064000                 ld      [%i1], %o0
F00AD05C: d026c000                 st      %o0, [%i3]
F00AD060: d0066004                 ld      [%i1+4], %o0
F00AD064: d026e004                 st      %o0, [%i3+4]
F00AD068: d0066008                 ld      [%i1+8], %o0
F00AD06C: d026e008                 st      %o0, [%i3+8]
F00AD070: d006600c                 ld      [%i1+0xC], %o0
F00AD074: d026e00c                 st      %o0, [%i3+0xC]
F00AD078: d0066010                 ld      [%i1+0x10], %o0
F00AD07C: d026e010                 st      %o0, [%i3+0x10]
F00AD080: d0066014                 ld      [%i1+0x14], %o0
F00AD084: d026e014                 st      %o0, [%i3+0x14]
F00AD088: d0066018                 ld      [%i1+0x18], %o0
F00AD08C: d026e018                 st      %o0, [%i3+0x18]
F00AD090: d006601c                 ld      [%i1+0x1C], %o0
F00AD094: d206e004                 ld      [%i3+4], %o1
F00AD098: d026e01c                 st      %o0, [%i3+0x1C]
F00AD09C: d0066020                 ld      [%i1+0x20], %o0
F00AD0A0: 80a26003                 cmp     %o1, 3
F00AD0A4: 14800006                 bg      loc_F00AD0BC
F00AD0A8: d026e020                 st      %o0, [%i3+0x20]
F00AD0AC: d0064000                 ld      [%i1], %o0
F00AD0B0: d2068000                 ld      [%i2], %o1
F00AD0B4: 901a0009                 btog    %o1, %o0
F00AD0B8: d026c000                 st      %o0, [%i3]
F00AD0BC: d2066004                 ld      [%i1+4], %o1
F00AD0C0: 80a26005                 cmp     %o1, 5! switch 6 cases
F00AD0C4: 1880001c                 bgu     def_F00AD0D8! jumptable F00AD0D8 default case, case 3
F00AD0C8: 113c02b4                 sethi   %hi(jpt_F00AD0D8), %o0
F00AD0CC: 901220e0                 bset    %lo(jpt_F00AD0D8), %o0
F00AD0D0: 932a6002                 sll     %o1, 2, %o1
F00AD0D4: d0024008                 ld      [%o1+%o0], %o0
F00AD0D8: 81c20000                 jmp     %o0! switch jump
F00AD0DC: 01000000                 nop
F00AD0F8: d006a004                 ld      [%i2+4], %o0! jumptable F00AD0D8 case 2
F00AD0FC: 80a22000                 cmp     %o0, 0
F00AD100: 1280012a                 bne     locret_F00AD5A8! jumptable F00AD0D8 cases 0,4,5
F00AD104: 90100018                 mov     %i0, %o0
F00AD108: 40000677                 call    _fpu_error_nan
F00AD10C: 9210001b                 mov     %i3, %o1
F00AD110: 90102004                 mov     4, %o0
F00AD114: 10800125                 ba      locret_F00AD5A8! jumptable F00AD0D8 cases 0,4,5
F00AD118: d026e004                 st      %o0, [%i3+4]
F00AD11C: d006a004                 ld      [%i2+4], %o0! jumptable F00AD0D8 case 1
F00AD120: 80a22000                 cmp     %o0, 0
F00AD124: 32800005                 bne,a   loc_F00AD138
F00AD128: c027bff4                 clr     [%fp+var_C]
F00AD12C: 1080011f                 ba      locret_F00AD5A8! jumptable F00AD0D8 cases 0,4,5
F00AD130: c026e004                 clr     [%i3+4]
F00AD134: c027bff4                 clr     [%fp+var_C]! jumptable F00AD0D8 default case, case 3
F00AD138: c027bff0                 clr     [%fp+var_10]
F00AD13C: c027bfec                 clr     [%fp+var_14]
F00AD140: c027bfe8                 clr     [%fp+var_18]
F00AD144: a2102000                 mov     0, %l1
F00AD148: e606a018                 ld      [%i2+0x18], %l3
F00AD14C: a4102000                 mov     0, %l2
F00AD150: 80a4e000                 cmp     %l3, 0
F00AD154: 02800031                 be      loc_F00AD218
F00AD158: a006600c                 add     %i1, 0xC, %l0
F00AD15C: b0102001                 mov     1, %i0
F00AD160: a807bfe8                 add     %fp, var_18, %l4
F00AD164: d007bff4                 ld      [%fp+var_C], %o0
F00AD168: a4148011                 bset    %l1, %l2
F00AD16C: d407bff0                 ld      [%fp+var_10], %o2
F00AD170: 808e0013                 btst    %l3, %i0
F00AD174: d607bfec                 ld      [%fp+var_14], %o3
F00AD178: a20a2001                 and     %o0, 1, %l1
F00AD17C: 932aa01f                 sll     %o2, 31, %o1
F00AD180: 91322001                 srl     %o0, 1, %o0
F00AD184: 98124008                 or      %o1, %o0, %o4
F00AD188: d827bff4                 st      %o4, [%fp+var_C]
F00AD18C: 912ae01f                 sll     %o3, 31, %o0
F00AD190: 9532a001                 srl     %o2, 1, %o2
F00AD194: 9012000a                 bset    %o2, %o0
F00AD198: d027bff0                 st      %o0, [%fp+var_10]
F00AD19C: d207bfe8                 ld      [%fp+var_18], %o1
F00AD1A0: 9732e001                 srl     %o3, 1, %o3
F00AD1A4: 912a601f                 sll     %o1, 31, %o0
F00AD1A8: 9012000b                 bset    %o3, %o0
F00AD1AC: d027bfec                 st      %o0, [%fp+var_14]
F00AD1B0: 93326001                 srl     %o1, 1, %o1
F00AD1B4: 02800016                 be      loc_F00AD20C
F00AD1B8: d227bfe8                 st      %o1, [%fp+var_18]
F00AD1BC: 9007bff4                 add     %fp, var_C, %o0
F00AD1C0: 9210000c                 mov     %o4, %o1
F00AD1C4: d404200c                 ld      [%l0+0xC], %o2
F00AD1C8: 40000655                 call    _fpu_add3wc
F00AD1CC: 96102000                 mov     0, %o3
F00AD1D0: d207bff0                 ld      [%fp+var_10], %o1
F00AD1D4: 96100008                 mov     %o0, %o3
F00AD1D8: d4042008                 ld      [%l0+8], %o2
F00AD1DC: 40000650                 call    _fpu_add3wc
F00AD1E0: 9007bff0                 add     %fp, var_10, %o0
F00AD1E4: d207bfec                 ld      [%fp+var_14], %o1
F00AD1E8: 96100008                 mov     %o0, %o3
F00AD1EC: d4042004                 ld      [%l0+4], %o2
F00AD1F0: 4000064b                 call    _fpu_add3wc
F00AD1F4: 9007bfec                 add     %fp, var_14, %o0
F00AD1F8: d207bfe8                 ld      [%fp+var_18], %o1
F00AD1FC: 96100008                 mov     %o0, %o3
F00AD200: d4040000                 ld      [%l0], %o2
F00AD204: 40000646                 call    _fpu_add3wc
F00AD208: 90100014                 mov     %l4, %o0
F00AD20C: b0860018                 addcc   %i0, %i0, %i0
F00AD210: 32bfffd6                 bne,a   loc_F00AD168
F00AD214: d007bff4                 ld      [%fp+var_C], %o0
F00AD218: e606a014                 ld      [%i2+0x14], %l3
F00AD21C: 80a4e000                 cmp     %l3, 0
F00AD220: 02800032                 be      loc_F00AD2E8
F00AD224: b0102001                 mov     1, %i0
F00AD228: a807bfe8                 add     %fp, var_18, %l4
F00AD22C: d007bff4                 ld      [%fp+var_C], %o0
F00AD230: a4148011                 bset    %l1, %l2
F00AD234: d407bff0                 ld      [%fp+var_10], %o2
F00AD238: 808e0013                 btst    %l3, %i0
F00AD23C: d607bfec                 ld      [%fp+var_14], %o3
F00AD240: a20a2001                 and     %o0, 1, %l1
F00AD244: 932aa01f                 sll     %o2, 31, %o1
F00AD248: 91322001                 srl     %o0, 1, %o0
F00AD24C: 98124008                 or      %o1, %o0, %o4
F00AD250: d827bff4                 st      %o4, [%fp+var_C]
F00AD254: 912ae01f                 sll     %o3, 31, %o0
F00AD258: 9532a001                 srl     %o2, 1, %o2
F00AD25C: 9012000a                 bset    %o2, %o0
F00AD260: d027bff0                 st      %o0, [%fp+var_10]
F00AD264: d207bfe8                 ld      [%fp+var_18], %o1
F00AD268: 9732e001                 srl     %o3, 1, %o3
F00AD26C: 912a601f                 sll     %o1, 31, %o0
F00AD270: 9012000b                 bset    %o3, %o0
F00AD274: d027bfec                 st      %o0, [%fp+var_14]
F00AD278: 93326001                 srl     %o1, 1, %o1
F00AD27C: 02800016                 be      loc_F00AD2D4
F00AD280: d227bfe8                 st      %o1, [%fp+var_18]
F00AD284: 9007bff4                 add     %fp, var_C, %o0
F00AD288: 9210000c                 mov     %o4, %o1
F00AD28C: d404200c                 ld      [%l0+0xC], %o2
F00AD290: 40000623                 call    _fpu_add3wc
F00AD294: 96102000                 mov     0, %o3
F00AD298: d207bff0                 ld      [%fp+var_10], %o1
F00AD29C: 96100008                 mov     %o0, %o3
F00AD2A0: d4042008                 ld      [%l0+8], %o2
F00AD2A4: 4000061e                 call    _fpu_add3wc
F00AD2A8: 9007bff0                 add     %fp, var_10, %o0
F00AD2AC: d207bfec                 ld      [%fp+var_14], %o1
F00AD2B0: 96100008                 mov     %o0, %o3
F00AD2B4: d4042004                 ld      [%l0+4], %o2
F00AD2B8: 40000619                 call    _fpu_add3wc
F00AD2BC: 9007bfec                 add     %fp, var_14, %o0
F00AD2C0: d207bfe8                 ld      [%fp+var_18], %o1
F00AD2C4: 96100008                 mov     %o0, %o3
F00AD2C8: d4040000                 ld      [%l0], %o2
F00AD2CC: 40000614                 call    _fpu_add3wc
F00AD2D0: 90100014                 mov     %l4, %o0
F00AD2D4: b0860018                 addcc   %i0, %i0, %i0
F00AD2D8: 12bfffd6                 bne     loc_F00AD230
F00AD2DC: d007bff4                 ld      [%fp+var_C], %o0
F00AD2E0: 10800010                 ba      loc_F00AD320
F00AD2E4: e606a010                 ld      [%i2+0x10], %l3
F00AD2E8: d207bff4                 ld      [%fp+var_C], %o1
F00AD2EC: 11200000                 sethi   0x80000000, %o0
F00AD2F0: 902a4008                 andn    %o1, %o0, %o0
F00AD2F4: 90144008                 bset    %l1, %o0
F00AD2F8: a4148008                 bset    %o0, %l2
F00AD2FC: d007bff0                 ld      [%fp+var_10], %o0
F00AD300: a332601f                 srl     %o1, 31, %l1
F00AD304: d207bfec                 ld      [%fp+var_14], %o1
F00AD308: d027bff4                 st      %o0, [%fp+var_C]
F00AD30C: d007bfe8                 ld      [%fp+var_18], %o0
F00AD310: d227bff0                 st      %o1, [%fp+var_10]
F00AD314: d027bfec                 st      %o0, [%fp+var_14]
F00AD318: c027bfe8                 clr     [%fp+var_18]
F00AD31C: e606a010                 ld      [%i2+0x10], %l3
F00AD320: 80a4e000                 cmp     %l3, 0
F00AD324: 02800032                 be      loc_F00AD3EC
F00AD328: b0102001                 mov     1, %i0
F00AD32C: a807bfe8                 add     %fp, var_18, %l4
F00AD330: d007bff4                 ld      [%fp+var_C], %o0
F00AD334: a4148011                 bset    %l1, %l2
F00AD338: d407bff0                 ld      [%fp+var_10], %o2
F00AD33C: 808e0013                 btst    %l3, %i0
F00AD340: d607bfec                 ld      [%fp+var_14], %o3
F00AD344: a20a2001                 and     %o0, 1, %l1
F00AD348: 932aa01f                 sll     %o2, 31, %o1
F00AD34C: 91322001                 srl     %o0, 1, %o0
F00AD350: 98124008                 or      %o1, %o0, %o4
F00AD354: d827bff4                 st      %o4, [%fp+var_C]
F00AD358: 912ae01f                 sll     %o3, 31, %o0
F00AD35C: 9532a001                 srl     %o2, 1, %o2
F00AD360: 9012000a                 bset    %o2, %o0
F00AD364: d027bff0                 st      %o0, [%fp+var_10]
F00AD368: d207bfe8                 ld      [%fp+var_18], %o1
F00AD36C: 9732e001                 srl     %o3, 1, %o3
F00AD370: 912a601f                 sll     %o1, 31, %o0
F00AD374: 9012000b                 bset    %o3, %o0
F00AD378: d027bfec                 st      %o0, [%fp+var_14]
F00AD37C: 93326001                 srl     %o1, 1, %o1
F00AD380: 02800016                 be      loc_F00AD3D8
F00AD384: d227bfe8                 st      %o1, [%fp+var_18]
F00AD388: 9007bff4                 add     %fp, var_C, %o0
F00AD38C: 9210000c                 mov     %o4, %o1
F00AD390: d404200c                 ld      [%l0+0xC], %o2
F00AD394: 400005e2                 call    _fpu_add3wc
F00AD398: 96102000                 mov     0, %o3
F00AD39C: d207bff0                 ld      [%fp+var_10], %o1
F00AD3A0: 96100008                 mov     %o0, %o3
F00AD3A4: d4042008                 ld      [%l0+8], %o2
F00AD3A8: 400005dd                 call    _fpu_add3wc
F00AD3AC: 9007bff0                 add     %fp, var_10, %o0
F00AD3B0: d207bfec                 ld      [%fp+var_14], %o1
F00AD3B4: 96100008                 mov     %o0, %o3
F00AD3B8: d4042004                 ld      [%l0+4], %o2
F00AD3BC: 400005d8                 call    _fpu_add3wc
F00AD3C0: 9007bfec                 add     %fp, var_14, %o0
F00AD3C4: d207bfe8                 ld      [%fp+var_18], %o1
F00AD3C8: 96100008                 mov     %o0, %o3
F00AD3CC: d4040000                 ld      [%l0], %o2
F00AD3D0: 400005d3                 call    _fpu_add3wc
F00AD3D4: 90100014                 mov     %l4, %o0
F00AD3D8: b0860018                 addcc   %i0, %i0, %i0
F00AD3DC: 12bfffd6                 bne     loc_F00AD334
F00AD3E0: d007bff4                 ld      [%fp+var_C], %o0
F00AD3E4: 10800010                 ba      loc_F00AD424
F00AD3E8: e606a00c                 ld      [%i2+0xC], %l3
F00AD3EC: d207bff4                 ld      [%fp+var_C], %o1
F00AD3F0: 11200000                 sethi   0x80000000, %o0
F00AD3F4: 902a4008                 andn    %o1, %o0, %o0
F00AD3F8: 90144008                 bset    %l1, %o0
F00AD3FC: a4148008                 bset    %o0, %l2
F00AD400: d007bff0                 ld      [%fp+var_10], %o0
F00AD404: a332601f                 srl     %o1, 31, %l1
F00AD408: d207bfec                 ld      [%fp+var_14], %o1
F00AD40C: d027bff4                 st      %o0, [%fp+var_C]
F00AD410: d007bfe8                 ld      [%fp+var_18], %o0
F00AD414: d227bff0                 st      %o1, [%fp+var_10]
F00AD418: d027bfec                 st      %o0, [%fp+var_14]
F00AD41C: c027bfe8                 clr     [%fp+var_18]
F00AD420: e606a00c                 ld      [%i2+0xC], %l3
F00AD424: b0102001                 mov     1, %i0
F00AD428: a807bfe8                 add     %fp, var_18, %l4
F00AD42C: d007bff4                 ld      [%fp+var_C], %o0
F00AD430: a4148011                 bset    %l1, %l2
F00AD434: d407bff0                 ld      [%fp+var_10], %o2
F00AD438: 808e0013                 btst    %l3, %i0
F00AD43C: d607bfec                 ld      [%fp+var_14], %o3
F00AD440: a20a2001                 and     %o0, 1, %l1
F00AD444: 932aa01f                 sll     %o2, 31, %o1
F00AD448: 91322001                 srl     %o0, 1, %o0
F00AD44C: 98124008                 or      %o1, %o0, %o4
F00AD450: d827bff4                 st      %o4, [%fp+var_C]
F00AD454: 912ae01f                 sll     %o3, 31, %o0
F00AD458: 9532a001                 srl     %o2, 1, %o2
F00AD45C: 9012000a                 bset    %o2, %o0
F00AD460: d027bff0                 st      %o0, [%fp+var_10]
F00AD464: d207bfe8                 ld      [%fp+var_18], %o1
F00AD468: 9732e001                 srl     %o3, 1, %o3
F00AD46C: 912a601f                 sll     %o1, 31, %o0
F00AD470: 9012000b                 bset    %o3, %o0
F00AD474: d027bfec                 st      %o0, [%fp+var_14]
F00AD478: 93326001                 srl     %o1, 1, %o1
F00AD47C: 02800016                 be      loc_F00AD4D4
F00AD480: d227bfe8                 st      %o1, [%fp+var_18]
F00AD484: 9007bff4                 add     %fp, var_C, %o0
F00AD488: 9210000c                 mov     %o4, %o1
F00AD48C: d404200c                 ld      [%l0+0xC], %o2
F00AD490: 400005a3                 call    _fpu_add3wc
F00AD494: 96102000                 mov     0, %o3
F00AD498: d207bff0                 ld      [%fp+var_10], %o1
F00AD49C: 96100008                 mov     %o0, %o3
F00AD4A0: d4042008                 ld      [%l0+8], %o2
F00AD4A4: 4000059e                 call    _fpu_add3wc
F00AD4A8: 9007bff0                 add     %fp, var_10, %o0
F00AD4AC: d207bfec                 ld      [%fp+var_14], %o1
F00AD4B0: 96100008                 mov     %o0, %o3
F00AD4B4: d4042004                 ld      [%l0+4], %o2
F00AD4B8: 40000599                 call    _fpu_add3wc
F00AD4BC: 9007bfec                 add     %fp, var_14, %o0
F00AD4C0: d207bfe8                 ld      [%fp+var_18], %o1
F00AD4C4: 96100008                 mov     %o0, %o3
F00AD4C8: d4040000                 ld      [%l0], %o2
F00AD4CC: 40000594                 call    _fpu_add3wc
F00AD4D0: 90100014                 mov     %l4, %o0
F00AD4D4: b12e2001                 sll     %i0, 1, %i0
F00AD4D8: 80a60013                 cmp     %i0, %l3
F00AD4DC: 08bfffd5                 bleu    loc_F00AD430
F00AD4E0: d007bff4                 ld      [%fp+var_C], %o0
F00AD4E4: d207bfe8                 ld      [%fp+var_18], %o1
F00AD4E8: 1100007f901223ff         set     0x1FFFF, %o0
F00AD4F0: 80a24008                 cmp     %o1, %o0
F00AD4F4: 08800020                 bleu    loc_F00AD574
F00AD4F8: d0066008                 ld      [%i1+8], %o0
F00AD4FC: d206a008                 ld      [%i2+8], %o1
F00AD500: 90020009                 add     %o0, %o1, %o0
F00AD504: 90022001                 inc     %o0
F00AD508: d026e008                 st      %o0, [%i3+8]
F00AD50C: 90148011                 or      %l2, %l1, %o0
F00AD510: d026e020                 st      %o0, [%i3+0x20]
F00AD514: d007bff4                 ld      [%fp+var_C], %o0
F00AD518: 900a2001                 and     %o0, 1, %o0
F00AD51C: d026e01c                 st      %o0, [%i3+0x1C]
F00AD520: d207bff0                 ld      [%fp+var_10], %o1
F00AD524: d007bff4                 ld      [%fp+var_C], %o0
F00AD528: 932a601f                 sll     %o1, 31, %o1
F00AD52C: 91322001                 srl     %o0, 1, %o0
F00AD530: 92124008                 bset    %o0, %o1
F00AD534: d226e018                 st      %o1, [%i3+0x18]
F00AD538: d207bfec                 ld      [%fp+var_14], %o1
F00AD53C: d007bff0                 ld      [%fp+var_10], %o0
F00AD540: 932a601f                 sll     %o1, 31, %o1
F00AD544: 91322001                 srl     %o0, 1, %o0
F00AD548: 92124008                 bset    %o0, %o1
F00AD54C: d226e014                 st      %o1, [%i3+0x14]
F00AD550: d207bfe8                 ld      [%fp+var_18], %o1
F00AD554: d007bfec                 ld      [%fp+var_14], %o0
F00AD558: 932a601f                 sll     %o1, 31, %o1
F00AD55C: 91322001                 srl     %o0, 1, %o0
F00AD560: 92124008                 bset    %o0, %o1
F00AD564: d226e010                 st      %o1, [%i3+0x10]
F00AD568: d007bfe8                 ld      [%fp+var_18], %o0
F00AD56C: 1080000e                 ba      loc_F00AD5A4
F00AD570: 91322001                 srl     %o0, 1, %o0
F00AD574: d206a008                 ld      [%i2+8], %o1
F00AD578: 90020009                 add     %o0, %o1, %o0
F00AD57C: d026e008                 st      %o0, [%i3+8]
F00AD580: e426e020                 st      %l2, [%i3+0x20]
F00AD584: e226e01c                 st      %l1, [%i3+0x1C]
F00AD588: d007bff4                 ld      [%fp+var_C], %o0
F00AD58C: d026e018                 st      %o0, [%i3+0x18]
F00AD590: d007bff0                 ld      [%fp+var_10], %o0
F00AD594: d026e014                 st      %o0, [%i3+0x14]
F00AD598: d007bfec                 ld      [%fp+var_14], %o0
F00AD59C: d026e010                 st      %o0, [%i3+0x10]
F00AD5A0: d007bfe8                 ld      [%fp+var_18], %o0
F00AD5A4: d026e00c                 st      %o0, [%i3+0xC]
F00AD5A8: 81c7e008                 ret! jumptable F00AD0D8 cases 0,4,5
F00AD5AC: 81e80000                 restore
