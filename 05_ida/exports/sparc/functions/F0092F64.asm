F0092F64: 9de3bf90                 save    %sp, -0x70, %sp
F0092F68: 912e2010                 sll     %i0, 16, %o0
F0092F6C: 400000b2                 call    sub_F0093234
F0092F70: 913a2010                 sra     %o0, 16, %o0
F0092F74: a6920000                 orcc    %o0, %g0, %l3
F0092F78: 12800004                 bne     loc_F0092F88
F0092F7C: b0102000                 mov     0, %i0
F0092F80: 108000ab                 ba      locret_F009322C
F0092F84: b0102006                 mov     6, %i0
F0092F88: 1108001c90122302         set     0x20007302, %o0
F0092F90: 80a64008                 cmp     %i1, %o0
F0092F94: 22800077                 be,a    loc_F0093170
F0092F98: 113c0504                 sethi   -0xFEBF000, %o0
F0092F9C: 1480001e                 bg      loc_F0093014
F0092FA0: 1110011c                 sethi   0x40047000, %o0
F0092FA4: 1120041c9012230c         set     -0x7FEF8CF4, %o0
F0092FAC: 80a64008                 cmp     %i1, %o0
F0092FB0: 0280004d                 be      loc_F00930E4
F0092FB4: 01000000                 nop
F0092FB8: 1480000d                 bg      loc_F0092FEC
F0092FBC: 1130161c                 sethi   -0x3FA79000, %o0
F0092FC0: 1120009c90122300         set     -0x7FFD8D00, %o0
F0092FC8: 80a64008                 cmp     %i1, %o0
F0092FCC: 02800030                 be      loc_F009308C
F0092FD0: 1120011c                 sethi   -0x7FFB9000, %o0
F0092FD4: 90122306                 bset    0x306, %o0
F0092FD8: 80a64008                 cmp     %i1, %o0
F0092FDC: 0280003a                 be      loc_F00930C4
F0092FE0: 113c0504                 sethi   -0xFEBF000, %o0
F0092FE4: 10800092                 ba      locret_F009322C
F0092FE8: b0102016                 mov     0x16, %i0
F0092FEC: 90122301                 bset    0x301, %o0
F0092FF0: 80a64008                 cmp     %i1, %o0
F0092FF4: 02800055                 be      loc_F0093148
F0092FF8: 1130171c                 sethi   -0x3FA39000, %o0
F0092FFC: 9012230e                 bset    0x30E, %o0
F0093000: 80a64008                 cmp     %i1, %o0
F0093004: 02800055                 be      loc_F0093158
F0093008: 90100013                 mov     %l3, %o0
F009300C: 10800088                 ba      locret_F009322C
F0093010: b0102016                 mov     0x16, %i0
F0093014: 90122307                 bset    0x307, %o0
F0093018: 80a64008                 cmp     %i1, %o0
F009301C: 22800060                 be,a    loc_F009319C
F0093020: 113c0504                 sethi   -0xFEBF000, %o0
F0093024: 1480000d                 bg      loc_F0093058
F0093028: 1110011c                 sethi   0x40047000, %o0
F009302C: 1108001c90122303         set     0x20007303, %o0
F0093034: 80a64008                 cmp     %i1, %o0
F0093038: 02800056                 be      loc_F0093190
F009303C: 1108001c                 sethi   0x20007000, %o0
F0093040: 90122304                 bset    0x304, %o0
F0093044: 80a64008                 cmp     %i1, %o0
F0093048: 0280006a                 be      loc_F00931F0
F009304C: 01000000                 nop
F0093050: 10800077                 ba      locret_F009322C
F0093054: b0102016                 mov     0x16, %i0
F0093058: 90122309                 bset    0x309, %o0
F009305C: 80a64008                 cmp     %i1, %o0
F0093060: 0280005b                 be      loc_F00931CC
F0093064: 113c0504                 sethi   %hi(paController), %o0
F0093068: 06800054                 bl      loc_F00931B8
F009306C: d202217c                 ld      [%o0+%lo(paController)], %o1
F0093070: 1110041c9012230d         set     0x4010730D, %o0
F0093078: 80a64008                 cmp     %i1, %o0
F009307C: 02800029                 be      loc_F0093120
F0093080: 113c0504                 sethi   -0xFEBF000, %o0
F0093084: 1080006a                 ba      locret_F009322C
F0093088: b0102016                 mov     0x16, %i0
F009308C: 113c0504                 sethi   %hi(paSettargetLunIs), %o0
F0093090: e00221d0                 ld      [%o0+%lo(paSettargetLunIs)], %l0
F0093094: e20e8000                 ldub    [%i2], %l1
F0093098: 7ffdf235                 call    _suser
F009309C: e40ea001                 ldub    [%i2+1], %l2
F00930A0: 992a2018                 sll     %o0, 24, %o4
F00930A4: 90100013                 mov     %l3, %o0! id
F00930A8: 92100010                 mov     %l0, %o1! SEL
F00930AC: 94100011                 mov     %l1, %o2
F00930B0: 96100012                 mov     %l2, %o3
F00930B4: 400179ef                 call    _objc_msgSend
F00930B8: 993b2018                 sra     %o4, 24, %o4
F00930BC: 10800016                 ba      loc_F0093114
F00930C0: 80a22000                 cmp     %o0, 0
F00930C4: d20221d4                 ld      [%o0+0x1D4], %o1! SEL
F00930C8: d4068000                 ld      [%i2], %o2
F00930CC: 400179e9                 call    _objc_msgSend
F00930D0: 90100013                 mov     %l3, %o0
F00930D4: 80a22000                 cmp     %o0, 0
F00930D8: 32800055                 bne,a   locret_F009322C
F00930DC: b0102013                 mov     0x13, %i0
F00930E0: 30800053                 ba,a    locret_F009322C
F00930E4: 7ffdf222                 call    _suser
F00930E8: 01000000                 nop
F00930EC: 852a2018                 sll     %o0, 24, %g2
F00930F0: 90100013                 mov     %l3, %o0! id
F00930F4: d41e8000                 ldd     [%i2], %o2
F00930F8: 8538a018                 sra     %g2, 24, %g2
F00930FC: d81ea008                 ldd     [%i2+8], %o4
F0093100: 133c0504                 sethi   %hi(paSetscsi3target), %o1
F0093104: d20261d8                 ld      [%o1+%lo(paSetscsi3target)], %o1! SEL
F0093108: 400179da                 call    _objc_msgSend
F009310C: c423a05c                 st      %g2, [%sp+0x70+var_14]
F0093110: 80a22000                 cmp     %o0, 0
F0093114: 32800046                 bne,a   locret_F009322C
F0093118: b010200d                 mov     0xD, %i0
F009311C: 30800044                 ba,a    locret_F009322C
F0093120: d20221dc                 ld      [%o0+0x1DC], %o1! SEL
F0093124: 400179d3                 call    _objc_msgSend
F0093128: 90100013                 mov     %l3, %o0
F009312C: d03e8000                 std     %o0, [%i2]
F0093130: 113c0504                 sethi   %hi(paScsi3Lun), %o0! id
F0093134: d20221e0                 ld      [%o0+%lo(paScsi3Lun)], %o1! SEL
F0093138: 400179ce                 call    _objc_msgSend
F009313C: 90100013                 mov     %l3, %o0
F0093140: 1080003b                 ba      locret_F009322C
F0093144: d03ea008                 std     %o0, [%i2+8]
F0093148: 90100013                 mov     %l3, %o0! id
F009314C: 9210001a                 mov     %i2, %o1
F0093150: 10800004                 ba      loc_F0093160
F0093154: 94102000                 mov     0, %o2
F0093158: 92102000                 mov     0, %o1
F009315C: 9410001a                 mov     %i2, %o2
F0093160: 40000041                 call    sub_F0093264
F0093164: 01000000                 nop
F0093168: 10800031                 ba      locret_F009322C
F009316C: b0100008                 mov     %o0, %i0
F0093170: d20221e4                 ld      [%o0+0x1E4], %o1! SEL
F0093174: 400179bf                 call    _objc_msgSend
F0093178: 90100013                 mov     %l3, %o0
F009317C: 80a22000                 cmp     %o0, 0
F0093180: 0280002b                 be      locret_F009322C
F0093184: 01000000                 nop
F0093188: 10800029                 ba      locret_F009322C
F009318C: b0102016                 mov     0x16, %i0
F0093190: 113c0504                 sethi   %hi(paDisableautosen), %o0! id
F0093194: 10bffff8                 ba      loc_F0093174
F0093198: d20221e8                 ld      [%o0+%lo(paDisableautosen)], %o1
F009319C: d20221ec                 ld      [%o0+0x1EC], %o1! SEL
F00931A0: 400179b4                 call    _objc_msgSend
F00931A4: 90100013                 mov     %l3, %o0
F00931A8: 80a00008                 cmp     %g0, %o0
F00931AC: 90402000                 addc    %g0, 0, %o0! id
F00931B0: 1080001f                 ba      locret_F009322C
F00931B4: d0268000                 st      %o0, [%i2]
F00931B8: 400179ae                 call    _objc_msgSend
F00931BC: 90100013                 mov     %l3, %o0! id
F00931C0: 133c0504                 sethi   %hi(paMaxtransfer), %o1
F00931C4: 10800007                 ba      loc_F00931E0
F00931C8: d2026168                 ld      [%o1+%lo(paMaxtransfer)], %o1
F00931CC: d202217c                 ld      [%o0+0x17C], %o1! SEL
F00931D0: 400179a8                 call    _objc_msgSend
F00931D4: 90100013                 mov     %l3, %o0! id
F00931D8: 133c0504                 sethi   %hi(paNumberoftarget), %o1
F00931DC: d20261f0                 ld      [%o1+%lo(paNumberoftarget)], %o1! SEL
F00931E0: 400179a4                 call    _objc_msgSend
F00931E4: 01000000                 nop
F00931E8: 10800011                 ba      locret_F009322C
F00931EC: d0268000                 st      %o0, [%i2]
F00931F0: 7ffdf1df                 call    _suser
F00931F4: 01000000                 nop
F00931F8: 80a22000                 cmp     %o0, 0
F00931FC: 12800006                 bne     loc_F0093214
F0093200: 113c0504                 sethi   -0xFEBF000, %o0
F0093204: 113c04cf                 sethi   %hi(dword_F0133DDC), %o0
F0093208: d00221dc                 ld      [%o0+%lo(dword_F0133DDC)], %o0! id
F009320C: 10800008                 ba      locret_F009322C
F0093210: f04a2038                 ldsb    [%o0+0x38], %i0
F0093214: d20221f4                 ld      [%o0+0x1F4], %o1! SEL
F0093218: 40017996                 call    _objc_msgSend
F009321C: 90100013                 mov     %l3, %o0
F0093220: 80a22000                 cmp     %o0, 0
F0093224: 32800002                 bne,a   locret_F009322C
F0093228: b0102005                 mov     5, %i0
F009322C: 81c7e008                 ret
F0093230: 81e80000                 restore
