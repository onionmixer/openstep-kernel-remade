F00DCB1C: 9de3bf80                 save    %sp, -0x80, %sp
F00DCB20: e6062068                 ld      [%i0+0x68], %l3
F00DCB24: e006a008                 ld      [%i2+8], %l0
F00DCB28: ac102000                 mov     0, %l6
F00DCB2C: c407a060                 ld      [%fp+arg_60], %g2
F00DCB30: c027bfec                 clr     [%fp+var_14]
F00DCB34: d807a064                 ld      [%fp+arg_64], %o4
F00DCB38: c027bfe8                 clr     [%fp+var_18]
F00DCB3C: da07a068                 ld      [%fp+arg_68], %o5
F00DCB40: aa102000                 mov     0, %l5
F00DCB44: f20fa05f                 ldub    [%fp+arg_5F], %i1
F00DCB48: 94102000                 mov     0, %o2
F00DCB4C: d006a004                 ld      [%i2+4], %o0
F00DCB50: ae102001                 mov     1, %l7
F00DCB54: e4062070                 ld      [%i0+0x70], %l2
F00DCB58: a210001d                 mov     %i5, %l1
F00DCB5C: 96220010                 sub     %o0, %l0, %o3
F00DCB60: 80a7400b                 cmp     %i5, %o3
F00DCB64: 08800004                 bleu    loc_F00DCB74
F00DCB68: e8062074                 ld      [%i0+0x74], %l4
F00DCB6C: ba10000b                 mov     %o3, %i5
F00DCB70: a210001d                 mov     %i5, %l1
F00DCB74: 80a4e000                 cmp     %l3, 0
F00DCB78: 22800002                 be,a    loc_F00DCB80
F00DCB7C: 94102001                 mov     1, %o2
F00DCB80: d2062078                 ld      [%i0+0x78], %o1
F00DCB84: 11000020                 sethi   0x8000, %o0
F00DCB88: 80a24008                 cmp     %o1, %o0
F00DCB8C: 32800007                 bne,a   loc_F00DCBA8
F00DCB90: 9412a002                 bset    2, %o2
F00DCB94: d006207c                 ld      [%i0+0x7C], %o0
F00DCB98: 80a20009                 cmp     %o0, %o1
F00DCB9C: 22800004                 be,a    loc_F00DCBAC
F00DCBA0: d006206c                 ld      [%i0+0x6C], %o0
F00DCBA4: 9412a002                 bset    2, %o2
F00DCBA8: d006206c                 ld      [%i0+0x6C], %o0
F00DCBAC: 80a22001                 cmp     %o0, 1
F00DCBB0: 32800007                 bne,a   loc_F00DCBCC
F00DCBB4: d006206c                 ld      [%i0+0x6C], %o0
F00DCBB8: 80a36002                 cmp     %o5, 2
F00DCBBC: 32800004                 bne,a   loc_F00DCBCC
F00DCBC0: d006206c                 ld      [%i0+0x6C], %o0
F00DCBC4: 10800008                 ba      loc_F00DCBE4
F00DCBC8: 9412a010                 bset    0x10, %o2
F00DCBCC: 80a22002                 cmp     %o0, 2
F00DCBD0: 32800006                 bne,a   loc_F00DCBE8
F00DCBD4: d2062064                 ld      [%i0+0x64], %o1
F00DCBD8: 80a36001                 cmp     %o5, 1
F00DCBDC: 22800002                 be,a    loc_F00DCBE4
F00DCBE0: 9412a020                 bset    0x20, %o2 ! ' '
F00DCBE4: d2062064                 ld      [%i0+0x64], %o1
F00DCBE8: 1100001590122222         set     0x5622, %o0
F00DCBF0: 80a24008                 cmp     %o1, %o0
F00DCBF4: 32800009                 bne,a   loc_F00DCC18
F00DCBF8: d2062064                 ld      [%i0+0x64], %o1
F00DCBFC: 1100002b90122044         set     0xAC44, %o0
F00DCC04: 80a08008                 cmp     %g2, %o0
F00DCC08: 32800004                 bne,a   loc_F00DCC18
F00DCC0C: d2062064                 ld      [%i0+0x64], %o1
F00DCC10: 1080000c                 ba      loc_F00DCC40
F00DCC14: 9412a004                 bset    4, %o2
F00DCC18: 1100002b90122044         set     0xAC44, %o0
F00DCC20: 80a24008                 cmp     %o1, %o0
F00DCC24: 12800008                 bne     loc_F00DCC44
F00DCC28: 80a4e003                 cmp     %l3, 3
F00DCC2C: 1100001590122222         set     0x5622, %o0
F00DCC34: 80a08008                 cmp     %g2, %o0
F00DCC38: 22800002                 be,a    loc_F00DCC40
F00DCC3C: 9412a008                 bset    8, %o2
F00DCC40: 80a4e003                 cmp     %l3, 3
F00DCC44: 12800007                 bne     loc_F00DCC60
F00DCC48: 80a4e003                 cmp     %l3, 3
F00DCC4C: 80a32000                 cmp     %o4, 0
F00DCC50: 12800004                 bne     loc_F00DCC60
F00DCC54: 80a4e003                 cmp     %l3, 3
F00DCC58: 10800023                 ba      loc_F00DCCE4
F00DCC5C: 9412a040                 bset    0x40, %o2 ! '@'
F00DCC60: 12800007                 bne     loc_F00DCC7C
F00DCC64: 80a4e000                 cmp     %l3, 0
F00DCC68: 80a32001                 cmp     %o4, 1
F00DCC6C: 12800004                 bne     loc_F00DCC7C
F00DCC70: 80a4e000                 cmp     %l3, 0
F00DCC74: 1080001c                 ba      loc_F00DCCE4
F00DCC78: 9412a080                 bset    0x80, %o2
F00DCC7C: 12800007                 bne     loc_F00DCC98
F00DCC80: 80a4e000                 cmp     %l3, 0
F00DCC84: 80a32003                 cmp     %o4, 3
F00DCC88: 12800004                 bne     loc_F00DCC98
F00DCC8C: 80a4e000                 cmp     %l3, 0
F00DCC90: 10800015                 ba      loc_F00DCCE4
F00DCC94: 9412a100                 bset    0x100, %o2
F00DCC98: 12800007                 bne     loc_F00DCCB4
F00DCC9C: 80a4e001                 cmp     %l3, 1
F00DCCA0: 80a32001                 cmp     %o4, 1
F00DCCA4: 12800004                 bne     loc_F00DCCB4
F00DCCA8: 80a4e001                 cmp     %l3, 1
F00DCCAC: 1080000e                 ba      loc_F00DCCE4
F00DCCB0: 9412a200                 bset    0x200, %o2
F00DCCB4: 12800007                 bne     loc_F00DCCD0
F00DCCB8: 80a4e001                 cmp     %l3, 1
F00DCCBC: 80a32000                 cmp     %o4, 0
F00DCCC0: 12800004                 bne     loc_F00DCCD0
F00DCCC4: 80a4e001                 cmp     %l3, 1
F00DCCC8: 10800007                 ba      loc_F00DCCE4
F00DCCCC: 9412a400                 bset    0x400, %o2
F00DCCD0: 12800006                 bne     loc_F00DCCE8
F00DCCD4: 80a2a018                 cmp     %o2, 0x18
F00DCCD8: 80a32003                 cmp     %o4, 3
F00DCCDC: 22800002                 be,a    loc_F00DCCE4
F00DCCE0: 9412a800                 bset    0x800, %o2
F00DCCE4: 80a2a018                 cmp     %o2, 0x18
F00DCCE8: 028000a1                 be      loc_F00DCF6C
F00DCCEC: 80a2a018                 cmp     %o2, 0x18
F00DCCF0: 18800030                 bgu     loc_F00DCDB0
F00DCCF4: 80a2a005                 cmp     %o2, 5
F00DCCF8: 228000fb                 be,a    loc_F00DD0E4
F00DCCFC: a3346001                 srl     %l1, 1, %l1
F00DCD00: 18800013                 bgu     loc_F00DCD4C
F00DCD04: 80a2a002                 cmp     %o2, 2
F00DCD08: 02800060                 be      loc_F00DCE88
F00DCD0C: 90100010                 mov     %l0, %o0
F00DCD10: 18800008                 bgu     loc_F00DCD30
F00DCD14: 80a2a000                 cmp     %o2, 0
F00DCD18: 02800174                 be      loc_F00DD2E8
F00DCD1C: 80a2a001                 cmp     %o2, 1
F00DCD20: 028000c2                 be      loc_F00DD028
F00DCD24: 92100012                 mov     %l2, %o1
F00DCD28: 1080016c                 ba      loc_F00DD2D8
F00DCD2C: 113c03f1                 sethi   -0xFF03C00, %o0
F00DCD30: 80a2a003                 cmp     %o2, 3
F00DCD34: 028000c1                 be      loc_F00DD038
F00DCD38: 80a2a004                 cmp     %o2, 4
F00DCD3C: 22800068                 be,a    loc_F00DCEDC
F00DCD40: a3346001                 srl     %l1, 1, %l1
F00DCD44: 10800165                 ba      loc_F00DD2D8
F00DCD48: 113c03f1                 sethi   -0xFF03C00, %o0
F00DCD4C: 80a2a010                 cmp     %o2, 0x10
F00DCD50: 22800050                 be,a    loc_F00DCE90
F00DCD54: a3346001                 srl     %l1, 1, %l1
F00DCD58: 18800008                 bgu     loc_F00DCD78
F00DCD5C: 80a2a008                 cmp     %o2, 8
F00DCD60: 02800063                 be      loc_F00DCEEC
F00DCD64: 80a2a009                 cmp     %o2, 9
F00DCD68: 228000ea                 be,a    loc_F00DD110
F00DCD6C: a32c6001                 sll     %l1, 1, %l1
F00DCD70: 1080015a                 ba      loc_F00DD2D8
F00DCD74: 113c03f1                 sethi   -0xFF03C00, %o0
F00DCD78: 80a2a014                 cmp     %o2, 0x14
F00DCD7C: 22800065                 be,a    loc_F00DCF10
F00DCD80: a3346002                 srl     %l1, 2, %l1
F00DCD84: 18800006                 bgu     loc_F00DCD9C
F00DCD88: 80a2a011                 cmp     %o2, 0x11
F00DCD8C: 228000bb                 be,a    loc_F00DD078
F00DCD90: a3346001                 srl     %l1, 1, %l1
F00DCD94: 10800151                 ba      loc_F00DD2D8
F00DCD98: 113c03f1                 sethi   -0xFF03C00, %o0
F00DCD9C: 80a2a015                 cmp     %o2, 0x15
F00DCDA0: 228000ec                 be,a    loc_F00DD150
F00DCDA4: a3346002                 srl     %l1, 2, %l1
F00DCDA8: 1080014c                 ba      loc_F00DD2D8
F00DCDAC: 113c03f1                 sethi   -0xFF03C00, %o0
F00DCDB0: 80a2a029                 cmp     %o2, 0x29 ! ')'
F00DCDB4: 228000f4                 be,a    loc_F00DD184
F00DCDB8: a32c6002                 sll     %l1, 2, %l1
F00DCDBC: 1880001a                 bgu     loc_F00DCE24
F00DCDC0: 80a2a021                 cmp     %o2, 0x21 ! '!'
F00DCDC4: 228000b8                 be,a    loc_F00DD0A4
F00DCDC8: a32c6001                 sll     %l1, 1, %l1
F00DCDCC: 18800008                 bgu     loc_F00DCDEC
F00DCDD0: 80a2a019                 cmp     %o2, 0x19
F00DCDD4: 028000ff                 be      loc_F00DD1D0
F00DCDD8: 80a2a020                 cmp     %o2, 0x20 ! ' '
F00DCDDC: 22800034                 be,a    loc_F00DCEAC
F00DCDE0: a32c6001                 sll     %l1, 1, %l1
F00DCDE4: 1080013d                 ba      loc_F00DD2D8
F00DCDE8: 113c03f1                 sethi   -0xFF03C00, %o0
F00DCDEC: 80a2a025                 cmp     %o2, 0x25 ! '%'
F00DCDF0: 02800109                 be      loc_F00DD214
F00DCDF4: 90100010                 mov     %l0, %o0
F00DCDF8: 18800006                 bgu     loc_F00DCE10
F00DCDFC: 80a2a024                 cmp     %o2, 0x24 ! '$'
F00DCE00: 02800068                 be      loc_F00DCFA0
F00DCE04: 92100012                 mov     %l2, %o1
F00DCE08: 10800134                 ba      loc_F00DD2D8
F00DCE0C: 113c03f1                 sethi   -0xFF03C00, %o0
F00DCE10: 80a2a028                 cmp     %o2, 0x28 ! '('
F00DCE14: 22800048                 be,a    loc_F00DCF34
F00DCE18: a32c6002                 sll     %l1, 2, %l1
F00DCE1C: 1080012f                 ba      loc_F00DD2D8
F00DCE20: 113c03f1                 sethi   -0xFF03C00, %o0
F00DCE24: 80a2a101                 cmp     %o2, 0x101
F00DCE28: 2280010c                 be,a    loc_F00DD258
F00DCE2C: a32c6001                 sll     %l1, 1, %l1
F00DCE30: 18800008                 bgu     loc_F00DCE50
F00DCE34: 80a2a040                 cmp     %o2, 0x40 ! '@'
F00DCE38: 0280006e                 be      loc_F00DCFF0
F00DCE3C: 80a2a080                 cmp     %o2, 0x80
F00DCE40: 02800074                 be      loc_F00DD010
F00DCE44: 90100010                 mov     %l0, %o0
F00DCE48: 10800124                 ba      loc_F00DD2D8
F00DCE4C: 113c03f1                 sethi   -0xFF03C00, %o0
F00DCE50: 80a2a400                 cmp     %o2, 0x400
F00DCE54: 2280005b                 be,a    loc_F00DCFC0
F00DCE58: a3346001                 srl     %l1, 1, %l1
F00DCE5C: 18800006                 bgu     loc_F00DCE74
F00DCE60: 80a2a201                 cmp     %o2, 0x201
F00DCE64: 2280010d                 be,a    loc_F00DD298
F00DCE68: a32c6001                 sll     %l1, 1, %l1
F00DCE6C: 1080011b                 ba      loc_F00DD2D8
F00DCE70: 113c03f1                 sethi   -0xFF03C00, %o0
F00DCE74: 80a2a800                 cmp     %o2, 0x800
F00DCE78: 02800058                 be      loc_F00DCFD8
F00DCE7C: 90100010                 mov     %l0, %o0
F00DCE80: 10800116                 ba      loc_F00DD2D8
F00DCE84: 113c03f1                 sethi   -0xFF03C00, %o0
F00DCE88: 10800072                 ba      loc_F00DD050
F00DCE8C: 92100012                 mov     %l2, %o1
F00DCE90: 90100010                 mov     %l0, %o0
F00DCE94: 92100012                 mov     %l2, %o1
F00DCE98: 94100011                 mov     %l1, %o2
F00DCE9C: 400013a4                 call    _audio_convertMonoToStereo
F00DCEA0: 96100013                 mov     %l3, %o3
F00DCEA4: 10800111                 ba      loc_F00DD2E8
F00DCEA8: a0100012                 mov     %l2, %l0
F00DCEAC: 80a4400b                 cmp     %l1, %o3
F00DCEB0: 38800002                 bgu,a   loc_F00DCEB8
F00DCEB4: a210000b                 mov     %o3, %l1
F00DCEB8: bb346001                 srl     %l1, 1, %i5
F00DCEBC: 90100010                 mov     %l0, %o0
F00DCEC0: 92100012                 mov     %l2, %o1
F00DCEC4: 94100011                 mov     %l1, %o2
F00DCEC8: 96100013                 mov     %l3, %o3
F00DCECC: 400013c9                 call    _audio_convertStereoToMono
F00DCED0: 98062084                 add     %i0, 0x84, %o4
F00DCED4: 10800105                 ba      loc_F00DD2E8
F00DCED8: a0100012                 mov     %l2, %l0
F00DCEDC: 90100010                 mov     %l0, %o0
F00DCEE0: 92100012                 mov     %l2, %o1
F00DCEE4: 108000d9                 ba      loc_F00DD248
F00DCEE8: 94100011                 mov     %l1, %o2
F00DCEEC: a32c6001                 sll     %l1, 1, %l1
F00DCEF0: 80a4400b                 cmp     %l1, %o3
F00DCEF4: 38800002                 bgu,a   loc_F00DCEFC
F00DCEF8: a210000b                 mov     %o3, %l1
F00DCEFC: bb346001                 srl     %l1, 1, %i5
F00DCF00: 90100010                 mov     %l0, %o0
F00DCF04: 92100012                 mov     %l2, %o1
F00DCF08: 108000be                 ba      loc_F00DD200
F00DCF0C: 94100011                 mov     %l1, %o2
F00DCF10: 90100010                 mov     %l0, %o0
F00DCF14: 92100012                 mov     %l2, %o1
F00DCF18: 94100011                 mov     %l1, %o2
F00DCF1C: 40001384                 call    _audio_convertMonoToStereo
F00DCF20: 96100013                 mov     %l3, %o3
F00DCF24: 90100012                 mov     %l2, %o0
F00DCF28: 92100014                 mov     %l4, %o1
F00DCF2C: 10800075                 ba      loc_F00DD100
F00DCF30: 952c6001                 sll     %l1, 1, %o2
F00DCF34: 80a4400b                 cmp     %l1, %o3
F00DCF38: 38800002                 bgu,a   loc_F00DCF40
F00DCF3C: a210000b                 mov     %o3, %l1
F00DCF40: bb346002                 srl     %l1, 2, %i5
F00DCF44: 90100010                 mov     %l0, %o0
F00DCF48: 92100012                 mov     %l2, %o1
F00DCF4C: 94100011                 mov     %l1, %o2
F00DCF50: 96100013                 mov     %l3, %o3
F00DCF54: 400013a7                 call    _audio_convertStereoToMono
F00DCF58: 98062084                 add     %i0, 0x84, %o4
F00DCF5C: 90100012                 mov     %l2, %o0
F00DCF60: 92100014                 mov     %l4, %o1
F00DCF64: 1080000a                 ba      loc_F00DCF8C
F00DCF68: 95346001                 srl     %l1, 1, %o2
F00DCF6C: 90100010                 mov     %l0, %o0
F00DCF70: 92100012                 mov     %l2, %o1
F00DCF74: 94100011                 mov     %l1, %o2
F00DCF78: 4000136d                 call    _audio_convertMonoToStereo
F00DCF7C: 96100013                 mov     %l3, %o3
F00DCF80: 90100012                 mov     %l2, %o0
F00DCF84: 92100014                 mov     %l4, %o1
F00DCF88: 952c6001                 sll     %l1, 1, %o2
F00DCF8C: 96100013                 mov     %l3, %o3
F00DCF90: 4000133a                 call    _audio_resample44To22
F00DCF94: 98062080                 add     %i0, 0x80, %o4
F00DCF98: 108000d4                 ba      loc_F00DD2E8
F00DCF9C: a0100014                 mov     %l4, %l0
F00DCFA0: 94100011                 mov     %l1, %o2
F00DCFA4: 96100013                 mov     %l3, %o3
F00DCFA8: 40001392                 call    _audio_convertStereoToMono
F00DCFAC: 98062084                 add     %i0, 0x84, %o4
F00DCFB0: 90100012                 mov     %l2, %o0
F00DCFB4: 92100014                 mov     %l4, %o1
F00DCFB8: 10800052                 ba      loc_F00DD100
F00DCFBC: 95346001                 srl     %l1, 1, %o2
F00DCFC0: 90100010                 mov     %l0, %o0
F00DCFC4: 92100012                 mov     %l2, %o1
F00DCFC8: 4000141d                 call    _audio_convertMulaw8ToLinear16
F00DCFCC: 94100011                 mov     %l1, %o2
F00DCFD0: 1080000e                 ba      loc_F00DD008
F00DCFD4: a6102000                 mov     0, %l3
F00DCFD8: 92100012                 mov     %l2, %o1
F00DCFDC: 40001429                 call    _audio_convertMulaw8ToLinear8
F00DCFE0: 94100011                 mov     %l1, %o2
F00DCFE4: a6102003                 mov     3, %l3
F00DCFE8: 108000c0                 ba      loc_F00DD2E8
F00DCFEC: a0100012                 mov     %l2, %l0
F00DCFF0: a3346001                 srl     %l1, 1, %l1
F00DCFF4: 90100010                 mov     %l0, %o0
F00DCFF8: 92100012                 mov     %l2, %o1
F00DCFFC: 400013d4                 call    _audio_convertLinear8ToLinear16
F00DD000: 94100011                 mov     %l1, %o2
F00DD004: a6102000                 mov     0, %l3
F00DD008: 108000b8                 ba      loc_F00DD2E8
F00DD00C: a0100012                 mov     %l2, %l0
F00DD010: 92100012                 mov     %l2, %o1
F00DD014: 400013dd                 call    _audio_convertLinear8ToMulaw8
F00DD018: 94100011                 mov     %l1, %o2
F00DD01C: a6102001                 mov     1, %l3
F00DD020: 108000b2                 ba      loc_F00DD2E8
F00DD024: a0100012                 mov     %l2, %l0
F00DD028: 400011d9                 call    _audio_swapSamples
F00DD02C: 95346001                 srl     %l1, 1, %o2
F00DD030: 108000ae                 ba      loc_F00DD2E8
F00DD034: a0100012                 mov     %l2, %l0
F00DD038: 90100010                 mov     %l0, %o0
F00DD03C: 92100012                 mov     %l2, %o1
F00DD040: 400011d3                 call    _audio_swapSamples
F00DD044: 95346001                 srl     %l1, 1, %o2
F00DD048: 90100012                 mov     %l2, %o0
F00DD04C: 92100014                 mov     %l4, %o1
F00DD050: d806206c                 ld      [%i0+0x6C], %o4
F00DD054: 94100011                 mov     %l1, %o2
F00DD058: da062078                 ld      [%i0+0x78], %o5
F00DD05C: 96100013                 mov     %l3, %o3
F00DD060: c406207c                 ld      [%i0+0x7C], %g2
F00DD064: a0100009                 mov     %o1, %l0
F00DD068: 400011ee                 call    _audio_scaleSamples
F00DD06C: c423a05c                 st      %g2, [%sp+0x80+var_24]
F00DD070: 1080009e                 ba      loc_F00DD2E8
F00DD074: ac100008                 mov     %o0, %l6
F00DD078: 90100010                 mov     %l0, %o0
F00DD07C: 92100012                 mov     %l2, %o1
F00DD080: 400011c3                 call    _audio_swapSamples
F00DD084: 95346001                 srl     %l1, 1, %o2
F00DD088: 90100012                 mov     %l2, %o0
F00DD08C: 92100014                 mov     %l4, %o1
F00DD090: 94100011                 mov     %l1, %o2
F00DD094: 40001326                 call    _audio_convertMonoToStereo
F00DD098: 96100013                 mov     %l3, %o3
F00DD09C: 10800093                 ba      loc_F00DD2E8
F00DD0A0: a0100014                 mov     %l4, %l0
F00DD0A4: 80a4400b                 cmp     %l1, %o3
F00DD0A8: 38800002                 bgu,a   loc_F00DD0B0
F00DD0AC: a210000b                 mov     %o3, %l1
F00DD0B0: bb346001                 srl     %l1, 1, %i5
F00DD0B4: 90100010                 mov     %l0, %o0
F00DD0B8: 92100012                 mov     %l2, %o1
F00DD0BC: 400011b4                 call    _audio_swapSamples
F00DD0C0: 9410001d                 mov     %i5, %o2
F00DD0C4: 90100012                 mov     %l2, %o0
F00DD0C8: 92100014                 mov     %l4, %o1
F00DD0CC: 94100011                 mov     %l1, %o2
F00DD0D0: 96100013                 mov     %l3, %o3
F00DD0D4: 40001347                 call    _audio_convertStereoToMono
F00DD0D8: 98062084                 add     %i0, 0x84, %o4
F00DD0DC: 10800083                 ba      loc_F00DD2E8
F00DD0E0: a0100014                 mov     %l4, %l0
F00DD0E4: 90100010                 mov     %l0, %o0
F00DD0E8: 92100012                 mov     %l2, %o1
F00DD0EC: 400011a8                 call    _audio_swapSamples
F00DD0F0: 95346001                 srl     %l1, 1, %o2
F00DD0F4: 90100012                 mov     %l2, %o0
F00DD0F8: 92100014                 mov     %l4, %o1
F00DD0FC: 94100011                 mov     %l1, %o2
F00DD100: 400012d6                 call    _audio_resample22To44
F00DD104: 96100013                 mov     %l3, %o3
F00DD108: 10800078                 ba      loc_F00DD2E8
F00DD10C: a0100014                 mov     %l4, %l0
F00DD110: 80a4400b                 cmp     %l1, %o3
F00DD114: 38800002                 bgu,a   loc_F00DD11C
F00DD118: a210000b                 mov     %o3, %l1
F00DD11C: bb346001                 srl     %l1, 1, %i5
F00DD120: 90100010                 mov     %l0, %o0
F00DD124: 92100012                 mov     %l2, %o1
F00DD128: 94100011                 mov     %l1, %o2
F00DD12C: 96100013                 mov     %l3, %o3
F00DD130: 400012d2                 call    _audio_resample44To22
F00DD134: 98062080                 add     %i0, 0x80, %o4
F00DD138: 90100012                 mov     %l2, %o0
F00DD13C: 92100014                 mov     %l4, %o1
F00DD140: 40001193                 call    _audio_swapSamples
F00DD144: 95346002                 srl     %l1, 2, %o2
F00DD148: 10800068                 ba      loc_F00DD2E8
F00DD14C: a0100014                 mov     %l4, %l0
F00DD150: 90100010                 mov     %l0, %o0
F00DD154: 92100012                 mov     %l2, %o1
F00DD158: 4000118d                 call    _audio_swapSamples
F00DD15C: 95346001                 srl     %l1, 1, %o2
F00DD160: 90100012                 mov     %l2, %o0
F00DD164: 92100014                 mov     %l4, %o1
F00DD168: 94100011                 mov     %l1, %o2
F00DD16C: 400012f0                 call    _audio_convertMonoToStereo
F00DD170: 96100013                 mov     %l3, %o3
F00DD174: 90100014                 mov     %l4, %o0
F00DD178: 92100012                 mov     %l2, %o1
F00DD17C: 10800033                 ba      loc_F00DD248
F00DD180: 952c6001                 sll     %l1, 1, %o2
F00DD184: 80a4400b                 cmp     %l1, %o3
F00DD188: 38800002                 bgu,a   loc_F00DD190
F00DD18C: a210000b                 mov     %o3, %l1
F00DD190: bb346002                 srl     %l1, 2, %i5
F00DD194: 90100010                 mov     %l0, %o0
F00DD198: 92100012                 mov     %l2, %o1
F00DD19C: a1346001                 srl     %l1, 1, %l0
F00DD1A0: 4000117b                 call    _audio_swapSamples
F00DD1A4: 94100010                 mov     %l0, %o2
F00DD1A8: 90100012                 mov     %l2, %o0
F00DD1AC: 92100014                 mov     %l4, %o1
F00DD1B0: 94100011                 mov     %l1, %o2
F00DD1B4: 96100013                 mov     %l3, %o3
F00DD1B8: 4000130e                 call    _audio_convertStereoToMono
F00DD1BC: 98062084                 add     %i0, 0x84, %o4
F00DD1C0: 90100014                 mov     %l4, %o0
F00DD1C4: 92100012                 mov     %l2, %o1
F00DD1C8: 1080000e                 ba      loc_F00DD200
F00DD1CC: 94100010                 mov     %l0, %o2
F00DD1D0: 90100010                 mov     %l0, %o0
F00DD1D4: 92100012                 mov     %l2, %o1
F00DD1D8: 4000116d                 call    _audio_swapSamples
F00DD1DC: 95346001                 srl     %l1, 1, %o2
F00DD1E0: 90100012                 mov     %l2, %o0
F00DD1E4: 92100014                 mov     %l4, %o1
F00DD1E8: 94100011                 mov     %l1, %o2
F00DD1EC: 400012d0                 call    _audio_convertMonoToStereo
F00DD1F0: 96100013                 mov     %l3, %o3
F00DD1F4: 90100014                 mov     %l4, %o0
F00DD1F8: 92100012                 mov     %l2, %o1
F00DD1FC: 952c6001                 sll     %l1, 1, %o2
F00DD200: 96100013                 mov     %l3, %o3
F00DD204: 4000129d                 call    _audio_resample44To22
F00DD208: 98062080                 add     %i0, 0x80, %o4
F00DD20C: 10800037                 ba      loc_F00DD2E8
F00DD210: a0100012                 mov     %l2, %l0
F00DD214: 92100012                 mov     %l2, %o1
F00DD218: a1346001                 srl     %l1, 1, %l0
F00DD21C: 4000115c                 call    _audio_swapSamples
F00DD220: 94100010                 mov     %l0, %o2
F00DD224: 90100012                 mov     %l2, %o0
F00DD228: 92100014                 mov     %l4, %o1
F00DD22C: 94100011                 mov     %l1, %o2
F00DD230: 96100013                 mov     %l3, %o3
F00DD234: 400012ef                 call    _audio_convertStereoToMono
F00DD238: 98062084                 add     %i0, 0x84, %o4
F00DD23C: 90100014                 mov     %l4, %o0
F00DD240: 92100012                 mov     %l2, %o1
F00DD244: 94100010                 mov     %l0, %o2
F00DD248: 40001284                 call    _audio_resample22To44
F00DD24C: 96100013                 mov     %l3, %o3
F00DD250: 10800026                 ba      loc_F00DD2E8
F00DD254: a0100012                 mov     %l2, %l0
F00DD258: 80a4400b                 cmp     %l1, %o3
F00DD25C: 38800002                 bgu,a   loc_F00DD264
F00DD260: a210000b                 mov     %o3, %l1
F00DD264: bb346001                 srl     %l1, 1, %i5
F00DD268: 90100010                 mov     %l0, %o0
F00DD26C: 92100012                 mov     %l2, %o1
F00DD270: 40001147                 call    _audio_swapSamples
F00DD274: 9410001d                 mov     %i5, %o2
F00DD278: 90100012                 mov     %l2, %o0
F00DD27C: 92100014                 mov     %l4, %o1
F00DD280: 9410001d                 mov     %i5, %o2
F00DD284: 40001351                 call    _audio_convertLinear16ToLinear8
F00DD288: 96062088                 add     %i0, 0x88, %o3
F00DD28C: a6102003                 mov     3, %l3
F00DD290: 10800016                 ba      loc_F00DD2E8
F00DD294: a0100014                 mov     %l4, %l0
F00DD298: 80a4400b                 cmp     %l1, %o3
F00DD29C: 38800002                 bgu,a   loc_F00DD2A4
F00DD2A0: a210000b                 mov     %o3, %l1
F00DD2A4: bb346001                 srl     %l1, 1, %i5
F00DD2A8: 90100010                 mov     %l0, %o0
F00DD2AC: 92100012                 mov     %l2, %o1
F00DD2B0: 40001137                 call    _audio_swapSamples
F00DD2B4: 9410001d                 mov     %i5, %o2
F00DD2B8: 90100012                 mov     %l2, %o0
F00DD2BC: 92100014                 mov     %l4, %o1
F00DD2C0: 9410001d                 mov     %i5, %o2
F00DD2C4: 40001350                 call    _audio_convertLinear16ToMulaw8
F00DD2C8: 96062088                 add     %i0, 0x88, %o3
F00DD2CC: a6102001                 mov     1, %l3
F00DD2D0: 10800006                 ba      loc_F00DD2E8
F00DD2D4: a0100014                 mov     %l4, %l0
F00DD2D8: 901222c0                 bset    0x2C0, %o0
F00DD2DC: 7fffa386                 call    _IOLog
F00DD2E0: 9210000a                 mov     %o2, %o1
F00DD2E4: ae102000                 mov     0, %l7
F00DD2E8: 80a5e000                 cmp     %l7, 0
F00DD2EC: 2280002b                 be,a    loc_F00DD398
F00DD2F0: 92100016                 mov     %l6, %o1
F00DD2F4: d04e2094                 ldsb    [%i0+0x94], %o0
F00DD2F8: 80a22000                 cmp     %o0, 0
F00DD2FC: 0280001e                 be      loc_F00DD374
F00DD300: 80a4e000                 cmp     %l3, 0
F00DD304: 1280000a                 bne     loc_F00DD32C
F00DD308: 80a4e003                 cmp     %l3, 3
F00DD30C: d006206c                 ld      [%i0+0x6C], %o0
F00DD310: 92100010                 mov     %l0, %o1
F00DD314: 9410001d                 mov     %i5, %o2
F00DD318: 9607bfec                 add     %fp, var_14, %o3
F00DD31C: 4000143b                 call    _audio_linear16_peak
F00DD320: 9807bfe8                 add     %fp, var_18, %o4
F00DD324: 10800015                 ba      loc_F00DD378
F00DD328: 90100010                 mov     %l0, %o0
F00DD32C: 1280000a                 bne     loc_F00DD354
F00DD330: 80a4e001                 cmp     %l3, 1
F00DD334: d006206c                 ld      [%i0+0x6C], %o0
F00DD338: 92100010                 mov     %l0, %o1
F00DD33C: 9410001d                 mov     %i5, %o2
F00DD340: 9607bfec                 add     %fp, var_14, %o3
F00DD344: 40001471                 call    _audio_linear8_peak
F00DD348: 9807bfe8                 add     %fp, var_18, %o4
F00DD34C: 1080000b                 ba      loc_F00DD378
F00DD350: 90100010                 mov     %l0, %o0
F00DD354: 12800009                 bne     loc_F00DD378
F00DD358: 90100010                 mov     %l0, %o0
F00DD35C: d006206c                 ld      [%i0+0x6C], %o0
F00DD360: 92100010                 mov     %l0, %o1
F00DD364: 9410001d                 mov     %i5, %o2
F00DD368: 9607bfec                 add     %fp, var_14, %o3
F00DD36C: 400013de                 call    _audio_mulaw8_peak
F00DD370: 9807bfe8                 add     %fp, var_18, %o4
F00DD374: 90100010                 mov     %l0, %o0
F00DD378: 9210001c                 mov     %i4, %o1
F00DD37C: 9410001d                 mov     %i5, %o2
F00DD380: 96100013                 mov     %l3, %o3
F00DD384: 992e6018                 sll     %i1, 24, %o4
F00DD388: 40001341                 call    _audio_mix
F00DD38C: 993b2018                 sra     %o4, 24, %o4
F00DD390: aa100008                 mov     %o0, %l5
F00DD394: 92100016                 mov     %l6, %o1
F00DD398: d006a008                 ld      [%i2+8], %o0
F00DD39C: 80a24015                 cmp     %o1, %l5
F00DD3A0: 90020011                 add     %o0, %l1, %o0
F00DD3A4: 1a800003                 bcc     loc_F00DD3B0
F00DD3A8: d026a008                 st      %o0, [%i2+8]
F00DD3AC: 92100015                 mov     %l5, %o1
F00DD3B0: d406208c                 ld      [%i0+0x8C], %o2
F00DD3B4: 9606208c                 add     %i0, 0x8C, %o3
F00DD3B8: da07bfec                 ld      [%fp+var_14], %o5
F00DD3BC: 90100009                 mov     %o1, %o0
F00DD3C0: 80a2c00a                 cmp     %o3, %o2
F00DD3C4: 02800012                 be      locret_F00DD40C
F00DD3C8: d807bfe8                 ld      [%fp+var_18], %o4
F00DD3CC: 9210000a                 mov     %o2, %o1
F00DD3D0: d4024000                 ld      [%o1], %o2
F00DD3D4: 80a6c00a                 cmp     %i3, %o2
F00DD3D8: 02800004                 be      loc_F00DD3E8
F00DD3DC: 80a2a000                 cmp     %o2, 0
F00DD3E0: 32800008                 bne,a   loc_F00DD400
F00DD3E4: d2026014                 ld      [%o1+0x14], %o1
F00DD3E8: f6224000                 st      %i3, [%o1]
F00DD3EC: e2226004                 st      %l1, [%o1+4]
F00DD3F0: da226008                 st      %o5, [%o1+8]
F00DD3F4: d822600c                 st      %o4, [%o1+0xC]
F00DD3F8: 10800005                 ba      locret_F00DD40C
F00DD3FC: d0226010                 st      %o0, [%o1+0x10]
F00DD400: 80a2c009                 cmp     %o3, %o1
F00DD404: 32bffff4                 bne,a   loc_F00DD3D4
F00DD408: d4024000                 ld      [%o1], %o2
F00DD40C: 81c7e008                 ret
F00DD410: 91e8001d                 restore %g0, %i5, %o0
