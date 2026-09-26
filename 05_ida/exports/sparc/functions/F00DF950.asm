F00DF950: 9de3bb58                 save    %sp, -0x4A8, %sp
F00DF954: a8102064                 mov     0x64, %l4 ! 'd'
F00DF958: c027bfe8                 clr     [%fp+var_18]
F00DF95C: c027bff4                 clr     [%fp+var_C]
F00DF960: c027bff0                 clr     [%fp+var_10]
F00DF964: d0062014                 ld      [%i0+0x14], %o0
F00DF968: 92023f9c                 add     %o0, -0x64, %o1
F00DF96C: 80a26010                 cmp     %o1, 0x10! switch 17 cases
F00DF970: 18800266                 bgu     def_F00DF988! jumptable F00DF988 default case
F00DF974: a0102000                 mov     0, %l0
F00DF978: 113c037e90122190         set     jpt_F00DF988, %o0
F00DF980: 932a6002                 sll     %o1, 2, %o1
F00DF984: d0024008                 ld      [%o1+%o0], %o0
F00DF988: 81c20000                 jmp     %o0! switch jump
F00DF98C: 01000000                 nop
F00DF9D4: d0062004                 ld      [%i0+4], %o0! jumptable F00DF988 case 0
F00DF9D8: 80a22028                 cmp     %o0, 0x28 ! '('
F00DF9DC: 3280024c                 bne,a   locret_F00E030C
F00DF9E0: b0102067                 mov     0x67, %i0 ! 'g'
F00DF9E4: d006201c                 ld      [%i0+0x1C], %o0
F00DF9E8: 80a22082                 cmp     %o0, 0x82
F00DF9EC: 12800016                 bne     loc_F00DFA44
F00DF9F0: 80a22081                 cmp     %o0, 0x81
F00DF9F4: 113c0506                 sethi   %hi(paIoaudio), %o0
F00DF9F8: d00222d4                 ld      [%o0+%lo(paIoaudio)], %o0! id
F00DF9FC: 133c0504                 sethi   %hi(paInputchannelfo), %o1
F00DFA00: d20263c8                 ld      [%o1+%lo(paInputchannelfo)], %o1! SEL
F00DFA04: 4000479b                 call    _objc_msgSend
F00DFA08: d406200c                 ld      [%i0+0xC], %o2
F00DFA0C: 133c0504                 sethi   %hi(paStreamuserforo), %o1
F00DFA10: d20263c4                 ld      [%o1+%lo(paStreamuserforo)], %o1! SEL
F00DFA14: a2100008                 mov     %o0, %l1
F00DFA18: 40004796                 call    _objc_msgSend
F00DFA1C: d4062024                 ld      [%i0+0x24], %o2
F00DFA20: 80a22000                 cmp     %o0, 0
F00DFA24: 12800020                 bne     loc_F00DFAA4
F00DFA28: d027bfec                 st      %o0, [%fp+var_14]
F00DFA2C: 90100011                 mov     %l1, %o0
F00DFA30: 9207bfec                 add     %fp, var_14, %o1
F00DFA34: d4062024                 ld      [%i0+0x24], %o2
F00DFA38: 96102000                 mov     0, %o3
F00DFA3C: 10800018                 ba      loc_F00DFA9C
F00DFA40: 98102001                 mov     1, %o4
F00DFA44: 12800003                 bne     loc_F00DFA50
F00DFA48: a0102004                 mov     4, %l0
F00DFA4C: a0102003                 mov     3, %l0
F00DFA50: 113c0506                 sethi   %hi(paIoaudio), %o0
F00DFA54: d00222d4                 ld      [%o0+%lo(paIoaudio)], %o0! id
F00DFA58: 133c0504                 sethi   %hi(paOutputchannelf), %o1
F00DFA5C: d20263c0                 ld      [%o1+%lo(paOutputchannelf)], %o1! SEL
F00DFA60: 40004784                 call    _objc_msgSend
F00DFA64: d406200c                 ld      [%i0+0xC], %o2
F00DFA68: 133c0504                 sethi   %hi(paStreamuserforo), %o1
F00DFA6C: d20263c4                 ld      [%o1+%lo(paStreamuserforo)], %o1! SEL
F00DFA70: a2100008                 mov     %o0, %l1
F00DFA74: 4000477f                 call    _objc_msgSend
F00DFA78: d4062024                 ld      [%i0+0x24], %o2
F00DFA7C: 80a22000                 cmp     %o0, 0
F00DFA80: 12800009                 bne     loc_F00DFAA4
F00DFA84: d027bfec                 st      %o0, [%fp+var_14]
F00DFA88: 90100011                 mov     %l1, %o0
F00DFA8C: 9207bfec                 add     %fp, var_14, %o1
F00DFA90: d4062024                 ld      [%i0+0x24], %o2
F00DFA94: 96102000                 mov     0, %o3
F00DFA98: 98100010                 mov     %l0, %o4
F00DFA9C: 7ffff9e5                 call    __NXAudioAddStream
F00DFAA0: 01000000                 nop
F00DFAA4: d2062010                 ld      [%i0+0x10], %o1
F00DFAA8: 90100019                 mov     %i1, %o0
F00DFAAC: d407bfec                 ld      [%fp+var_14], %o2
F00DFAB0: 40000679                 call    _audio_snd_reply_ret_stream
F00DFAB4: a8102000                 mov     0, %l4
F00DFAB8: 10800215                 ba      locret_F00E030C
F00DFABC: b0100014                 mov     %l4, %i0
F00DFAC0: d0062004                 ld      [%i0+4], %o0! jumptable F00DF988 case 1
F00DFAC4: 80a22020                 cmp     %o0, 0x20 ! ' '
F00DFAC8: 32800211                 bne,a   locret_F00E030C
F00DFACC: b0102067                 mov     0x67, %i0 ! 'g'
F00DFAD0: 113c0506                 sethi   %hi(paIoaudio), %o0
F00DFAD4: d00222d4                 ld      [%o0+%lo(paIoaudio)], %o0! id
F00DFAD8: 133c0504                 sethi   %hi(paOutputchannelf), %o1
F00DFADC: d20263c0                 ld      [%o1+%lo(paOutputchannelf)], %o1! SEL
F00DFAE0: 40004764                 call    _objc_msgSend
F00DFAE4: d406200c                 ld      [%i0+0xC], %o2
F00DFAE8: a2100008                 mov     %o0, %l1
F00DFAEC: 7ffffa49                 call    __NXAudioGetSndoutOptions
F00DFAF0: 9207bfe8                 add     %fp, var_18, %o1
F00DFAF4: d006201c                 ld      [%i0+0x1C], %o0
F00DFAF8: 808a2004                 btst    4, %o0
F00DFAFC: 02800004                 be      loc_F00DFB0C
F00DFB00: d007bfe8                 ld      [%fp+var_18], %o0
F00DFB04: 10800003                 ba      loc_F00DFB10
F00DFB08: 90122001                 bset    1, %o0
F00DFB0C: 900a3ffe                 and     %o0, -2, %o0
F00DFB10: d027bfe8                 st      %o0, [%fp+var_18]
F00DFB14: d006201c                 ld      [%i0+0x1C], %o0
F00DFB18: 808a2002                 btst    2, %o0
F00DFB1C: 02800004                 be      loc_F00DFB2C
F00DFB20: d007bfe8                 ld      [%fp+var_18], %o0
F00DFB24: 10800003                 ba      loc_F00DFB30
F00DFB28: 90122010                 bset    0x10, %o0
F00DFB2C: 900a3fef                 and     %o0, -0x11, %o0
F00DFB30: d027bfe8                 st      %o0, [%fp+var_18]
F00DFB34: d006201c                 ld      [%i0+0x1C], %o0
F00DFB38: 808a2001                 btst    1, %o0
F00DFB3C: 02800004                 be      loc_F00DFB4C
F00DFB40: d007bfe8                 ld      [%fp+var_18], %o0
F00DFB44: 1080018b                 ba      loc_F00E0170
F00DFB48: 90122008                 bset    8, %o0
F00DFB4C: 10800189                 ba      loc_F00E0170
F00DFB50: 900a3ff7                 and     %o0, -9, %o0
F00DFB54: d0062004                 ld      [%i0+4], %o0! jumptable F00DF988 case 2
F00DFB58: 80a22018                 cmp     %o0, 0x18
F00DFB5C: 328001ec                 bne,a   locret_F00E030C
F00DFB60: b0102067                 mov     0x67, %i0 ! 'g'
F00DFB64: 113c0506                 sethi   %hi(paIoaudio), %o0
F00DFB68: d00222d4                 ld      [%o0+%lo(paIoaudio)], %o0! id
F00DFB6C: 133c0504                 sethi   %hi(paOutputchannelf), %o1
F00DFB70: d20263c0                 ld      [%o1+%lo(paOutputchannelf)], %o1! SEL
F00DFB74: 4000473f                 call    _objc_msgSend
F00DFB78: d406200c                 ld      [%i0+0xC], %o2
F00DFB7C: 7ffffa25                 call    __NXAudioGetSndoutOptions
F00DFB80: 9207bfe8                 add     %fp, var_18, %o1
F00DFB84: d007bfe8                 ld      [%fp+var_18], %o0
F00DFB88: 808a2001                 btst    1, %o0
F00DFB8C: 32800002                 bne,a   loc_F00DFB94
F00DFB90: a0142004                 bset    4, %l0
F00DFB94: 808a2010                 btst    0x10, %o0
F00DFB98: 32800002                 bne,a   loc_F00DFBA0
F00DFB9C: a0142002                 bset    2, %l0
F00DFBA0: 808a2008                 btst    8, %o0
F00DFBA4: 32800002                 bne,a   loc_F00DFBAC
F00DFBA8: a0142001                 bset    1, %l0
F00DFBAC: 90100019                 mov     %i1, %o0
F00DFBB0: d2062010                 ld      [%i0+0x10], %o1
F00DFBB4: 94100010                 mov     %l0, %o2
F00DFBB8: 400006c8                 call    _audio_snd_reply_ret_parms
F00DFBBC: a8102000                 mov     0, %l4
F00DFBC0: 108001d3                 ba      locret_F00E030C
F00DFBC4: b0100014                 mov     %l4, %i0
F00DFBC8: d0062004                 ld      [%i0+4], %o0! jumptable F00DF988 case 3
F00DFBCC: 80a22020                 cmp     %o0, 0x20 ! ' '
F00DFBD0: 328001cf                 bne,a   locret_F00E030C
F00DFBD4: b0102067                 mov     0x67, %i0 ! 'g'
F00DFBD8: 113c0506                 sethi   %hi(paIoaudio), %o0
F00DFBDC: d00222d4                 ld      [%o0+%lo(paIoaudio)], %o0! id
F00DFBE0: 133c0504                 sethi   %hi(paOutputchannelf), %o1
F00DFBE4: d20263c0                 ld      [%o1+%lo(paOutputchannelf)], %o1! SEL
F00DFBE8: 1700003f                 sethi   0xFC00, %o3
F00DFBEC: d806201c                 ld      [%i0+0x1C], %o4
F00DFBF0: 9612e300                 bset    0x300, %o3
F00DFBF4: d406200c                 ld      [%i0+0xC], %o2
F00DFBF8: 960b000b                 and     %o4, %o3, %o3
F00DFBFC: 9732e008                 srl     %o3, 8, %o3
F00DFC00: d627bfe4                 st      %o3, [%fp+var_1C]
F00DFC04: 980b20ff                 and     %o4, 0xFF, %o4
F00DFC08: d827bfe0                 st      %o4, [%fp+var_20]
F00DFC0C: 972ae001                 sll     %o3, 1, %o3
F00DFC10: 9602ffaa                 inc     -0x56, %o3
F00DFC14: d627bfe4                 st      %o3, [%fp+var_1C]
F00DFC18: 992b2001                 sll     %o4, 1, %o4
F00DFC1C: 98033faa                 inc     -0x56, %o4
F00DFC20: 40004714                 call    _objc_msgSend
F00DFC24: d827bfe0                 st      %o4, [%fp+var_20]
F00DFC28: d407bfe4                 ld      [%fp+var_1C], %o2
F00DFC2C: d607bfe0                 ld      [%fp+var_20], %o3
F00DFC30: 7ffffab6                 call    __NXAudioSetSpeaker
F00DFC34: 92102000                 mov     0, %o1
F00DFC38: 108001b5                 ba      locret_F00E030C
F00DFC3C: b0100014                 mov     %l4, %i0
F00DFC40: d0062004                 ld      [%i0+4], %o0! jumptable F00DF988 case 4
F00DFC44: 80a22018                 cmp     %o0, 0x18
F00DFC48: 328001b1                 bne,a   locret_F00E030C
F00DFC4C: b0102067                 mov     0x67, %i0 ! 'g'
F00DFC50: 113c0506                 sethi   %hi(paIoaudio), %o0
F00DFC54: d00222d4                 ld      [%o0+%lo(paIoaudio)], %o0! id
F00DFC58: 133c0504                 sethi   %hi(paOutputchannelf), %o1
F00DFC5C: d20263c0                 ld      [%o1+%lo(paOutputchannelf)], %o1! SEL
F00DFC60: d406200c                 ld      [%i0+0xC], %o2
F00DFC64: 40004703                 call    _objc_msgSend
F00DFC68: a8102000                 mov     0, %l4
F00DFC6C: 9207bfe4                 add     %fp, var_1C, %o1
F00DFC70: 7ffffa8a                 call    __NXAudioGetSpeaker
F00DFC74: 9407bfe0                 add     %fp, var_20, %o2
F00DFC78: d607bfe4                 ld      [%fp+var_1C], %o3
F00DFC7C: 90100019                 mov     %i1, %o0
F00DFC80: d2062010                 ld      [%i0+0x10], %o1
F00DFC84: 9532e01f                 srl     %o3, 31, %o2
F00DFC88: 9602c00a                 add     %o3, %o2, %o3
F00DFC8C: 973ae001                 sra     %o3, 1, %o3
F00DFC90: 9602e02b                 inc     0x2B, %o3 ! '+'
F00DFC94: d627bfe4                 st      %o3, [%fp+var_1C]
F00DFC98: d407bfe0                 ld      [%fp+var_20], %o2
F00DFC9C: 972ae008                 sll     %o3, 8, %o3
F00DFCA0: 9932a01f                 srl     %o2, 31, %o4
F00DFCA4: 9402800c                 add     %o2, %o4, %o2
F00DFCA8: 953aa001                 sra     %o2, 1, %o2
F00DFCAC: 9402a02b                 inc     0x2B, %o2 ! '+'
F00DFCB0: d427bfe0                 st      %o2, [%fp+var_20]
F00DFCB4: 40000695                 call    _audio_snd_reply_ret_volume
F00DFCB8: 9412c00a                 bset    %o3, %o2
F00DFCBC: 10800194                 ba      locret_F00E030C
F00DFCC0: b0100014                 mov     %l4, %i0
F00DFCC4: d0062004                 ld      [%i0+4], %o0! jumptable F00DF988 case 15
F00DFCC8: 80a22018                 cmp     %o0, 0x18
F00DFCCC: 32800190                 bne,a   locret_F00E030C
F00DFCD0: b0102067                 mov     0x67, %i0 ! 'g'
F00DFCD4: 113c0506                 sethi   %hi(paIoaudio), %o0
F00DFCD8: d00222d4                 ld      [%o0+%lo(paIoaudio)], %o0! id
F00DFCDC: 133c0504                 sethi   %hi(paOutputchannelf), %o1
F00DFCE0: d20263c0                 ld      [%o1+%lo(paOutputchannelf)], %o1! SEL
F00DFCE4: 400046e3                 call    _objc_msgSend
F00DFCE8: d406200c                 ld      [%i0+0xC], %o2
F00DFCEC: a2100008                 mov     %o0, %l1
F00DFCF0: 9207bbc4                 add     %fp, var_43C, %o1
F00DFCF4: 9407bfd8                 add     %fp, var_28, %o2
F00DFCF8: 9607bfd4                 add     %fp, var_2C, %o3
F00DFCFC: 9807bbc8                 add     %fp, var_438, %o4
F00DFD00: 9a07bbc0                 add     %fp, var_440, %o5
F00DFD04: 7ffffcc2                 call    __NXAudioGetSamplingRates
F00DFD08: a007bfc8                 add     %fp, var_38, %l0
F00DFD0C: d007bbc4                 ld      [%fp+var_43C], %o0
F00DFD10: 80a22000                 cmp     %o0, 0
F00DFD14: 02800004                 be      loc_F00DFD24
F00DFD18: c027bfdc                 clr     [%fp+var_24]
F00DFD1C: 90102001                 mov     1, %o0
F00DFD20: d027bfdc                 st      %o0, [%fp+var_24]
F00DFD24: d207bbc0                 ld      [%fp+var_440], %o1
F00DFD28: 94102000                 mov     0, %o2
F00DFD2C: 80a28009                 cmp     %o2, %o1
F00DFD30: 16800041                 bge     loc_F00DFE34
F00DFD34: 90100011                 mov     %l1, %o0
F00DFD38: 113ffff8a81220c0         set     -0x1F40, %l4
F00DFD40: 110000159a122222         set     0x5622, %o5
F00DFD48: 1100000aa6122311         set     0x2B11, %l3
F00DFD50: 1100000fa4122280         set     0x3E80, %l2
F00DFD58: 1100002b98122044         set     0xAC44, %o4
F00DFD60: 1100001f9e122100         set     0x7D00, %o7
F00DFD68: 1100002e86122380         set     0xBB80, %g3
F00DFD70: 84100009                 mov     %o1, %g2
F00DFD74: 96100010                 mov     %l0, %o3
F00DFD78: d202fc00                 ld      [%o3-0x400], %o1
F00DFD7C: 90024014                 add     %o1, %l4, %o0
F00DFD80: 80a2200d                 cmp     %o0, 0xD
F00DFD84: 18800004                 bgu     loc_F00DFD94
F00DFD88: d007bfdc                 ld      [%fp+var_24], %o0
F00DFD8C: 10800024                 ba      loc_F00DFE1C
F00DFD90: 90122002                 bset    2, %o0
F00DFD94: 80a2400d                 cmp     %o1, %o5
F00DFD98: 22800021                 be,a    loc_F00DFE1C
F00DFD9C: 90122010                 bset    0x10, %o0
F00DFDA0: 14800009                 bg      loc_F00DFDC4
F00DFDA4: 80a2400c                 cmp     %o1, %o4
F00DFDA8: 80a24013                 cmp     %o1, %l3
F00DFDAC: 02800013                 be      loc_F00DFDF8
F00DFDB0: 80a24012                 cmp     %o1, %l2
F00DFDB4: 0280001a                 be      loc_F00DFE1C
F00DFDB8: 90122008                 bset    8, %o0
F00DFDBC: 1080001a                 ba      loc_F00DFE24
F00DFDC0: 9402a001                 inc     %o2
F00DFDC4: 02800012                 be      loc_F00DFE0C
F00DFDC8: 80a2400c                 cmp     %o1, %o4
F00DFDCC: 14800007                 bg      loc_F00DFDE8
F00DFDD0: 80a24003                 cmp     %o1, %g3
F00DFDD4: 80a2400f                 cmp     %o1, %o7
F00DFDD8: 0280000b                 be      loc_F00DFE04
F00DFDDC: d007bfdc                 ld      [%fp+var_24], %o0
F00DFDE0: 10800011                 ba      loc_F00DFE24
F00DFDE4: 9402a001                 inc     %o2
F00DFDE8: 0280000c                 be      loc_F00DFE18
F00DFDEC: d007bfdc                 ld      [%fp+var_24], %o0
F00DFDF0: 1080000d                 ba      loc_F00DFE24
F00DFDF4: 9402a001                 inc     %o2
F00DFDF8: d007bfdc                 ld      [%fp+var_24], %o0
F00DFDFC: 10800008                 ba      loc_F00DFE1C
F00DFE00: 90122004                 bset    4, %o0
F00DFE04: 10800006                 ba      loc_F00DFE1C
F00DFE08: 90122020                 bset    0x20, %o0 ! ' '
F00DFE0C: d007bfdc                 ld      [%fp+var_24], %o0
F00DFE10: 10800003                 ba      loc_F00DFE1C
F00DFE14: 90122040                 bset    0x40, %o0 ! '@'
F00DFE18: 90122080                 bset    0x80, %o0
F00DFE1C: d027bfdc                 st      %o0, [%fp+var_24]
F00DFE20: 9402a001                 inc     %o2
F00DFE24: 80a28002                 cmp     %o2, %g2
F00DFE28: 06bfffd4                 bl      loc_F00DFD78
F00DFE2C: 9602e004                 inc     4, %o3
F00DFE30: 90100011                 mov     %l1, %o0
F00DFE34: 9207bbc8                 add     %fp, var_438, %o1
F00DFE38: 7ffffc99                 call    __NXAudioGetDataEncodings
F00DFE3C: 9407bbc0                 add     %fp, var_440, %o2
F00DFE40: c027bfd0                 clr     [%fp+var_30]
F00DFE44: d007bbc0                 ld      [%fp+var_440], %o0
F00DFE48: 94102000                 mov     0, %o2
F00DFE4C: 80a28008                 cmp     %o2, %o0
F00DFE50: 3680009e                 bge,a   loc_F00E00C8
F00DFE54: 90100011                 mov     %l1, %o0
F00DFE58: 96100008                 mov     %o0, %o3
F00DFE5C: 92100010                 mov     %l0, %o1
F00DFE60: d0027c00                 ld      [%o1-0x400], %o0
F00DFE64: 80a22259                 cmp     %o0, 0x259
F00DFE68: 2280000e                 be,a    loc_F00DFEA0
F00DFE6C: d007bfd0                 ld      [%fp+var_30], %o0
F00DFE70: 14800007                 bg      loc_F00DFE8C
F00DFE74: 80a2225a                 cmp     %o0, 0x25A
F00DFE78: 80a22258                 cmp     %o0, 0x258
F00DFE7C: 0280000b                 be      loc_F00DFEA8
F00DFE80: d007bfd0                 ld      [%fp+var_30], %o0
F00DFE84: 1080000c                 ba      loc_F00DFEB4
F00DFE88: 9402a001                 inc     %o2
F00DFE8C: 3280000a                 bne,a   loc_F00DFEB4
F00DFE90: 9402a001                 inc     %o2
F00DFE94: d007bfd0                 ld      [%fp+var_30], %o0
F00DFE98: 10800005                 ba      loc_F00DFEAC
F00DFE9C: 90122001                 bset    1, %o0
F00DFEA0: 10800003                 ba      loc_F00DFEAC
F00DFEA4: 90122002                 bset    2, %o0
F00DFEA8: 90122004                 bset    4, %o0
F00DFEAC: d027bfd0                 st      %o0, [%fp+var_30]
F00DFEB0: 9402a001                 inc     %o2
F00DFEB4: 80a2800b                 cmp     %o2, %o3
F00DFEB8: 06bfffea                 bl      loc_F00DFE60
F00DFEBC: 92026004                 inc     4, %o1
F00DFEC0: 10800082                 ba      loc_F00E00C8
F00DFEC4: 90100011                 mov     %l1, %o0
F00DFEC8: d0062004                 ld      [%i0+4], %o0! jumptable F00DF988 case 16
F00DFECC: 80a22018                 cmp     %o0, 0x18
F00DFED0: 3280010f                 bne,a   locret_F00E030C
F00DFED4: b0102067                 mov     0x67, %i0 ! 'g'
F00DFED8: 113c0506                 sethi   %hi(paIoaudio), %o0
F00DFEDC: d00222d4                 ld      [%o0+%lo(paIoaudio)], %o0! id
F00DFEE0: 133c0504                 sethi   %hi(paInputchannelfo), %o1
F00DFEE4: d20263c8                 ld      [%o1+%lo(paInputchannelfo)], %o1! SEL
F00DFEE8: 40004662                 call    _objc_msgSend
F00DFEEC: d406200c                 ld      [%i0+0xC], %o2
F00DFEF0: a2100008                 mov     %o0, %l1
F00DFEF4: 9207bbc4                 add     %fp, var_43C, %o1
F00DFEF8: 9407bfd8                 add     %fp, var_28, %o2
F00DFEFC: 9607bfd4                 add     %fp, var_2C, %o3
F00DFF00: 9807bbc8                 add     %fp, var_438, %o4
F00DFF04: 9a07bbc0                 add     %fp, var_440, %o5
F00DFF08: 7ffffc41                 call    __NXAudioGetSamplingRates
F00DFF0C: a007bfc8                 add     %fp, var_38, %l0
F00DFF10: d007bbc4                 ld      [%fp+var_43C], %o0
F00DFF14: 80a22000                 cmp     %o0, 0
F00DFF18: 02800004                 be      loc_F00DFF28
F00DFF1C: c027bfdc                 clr     [%fp+var_24]
F00DFF20: 90102001                 mov     1, %o0
F00DFF24: d027bfdc                 st      %o0, [%fp+var_24]
F00DFF28: d207bbc0                 ld      [%fp+var_440], %o1
F00DFF2C: 94102000                 mov     0, %o2
F00DFF30: 80a28009                 cmp     %o2, %o1
F00DFF34: 16800041                 bge     loc_F00E0038
F00DFF38: 90100011                 mov     %l1, %o0
F00DFF3C: 113ffff8a81220c0         set     -0x1F40, %l4
F00DFF44: 110000159a122222         set     0x5622, %o5
F00DFF4C: 1100000aa6122311         set     0x2B11, %l3
F00DFF54: 1100000fa4122280         set     0x3E80, %l2
F00DFF5C: 1100002b98122044         set     0xAC44, %o4
F00DFF64: 1100001f9e122100         set     0x7D00, %o7
F00DFF6C: 1100002e86122380         set     0xBB80, %g3
F00DFF74: 84100009                 mov     %o1, %g2
F00DFF78: 96100010                 mov     %l0, %o3
F00DFF7C: d202fc00                 ld      [%o3-0x400], %o1
F00DFF80: 90024014                 add     %o1, %l4, %o0
F00DFF84: 80a2200d                 cmp     %o0, 0xD
F00DFF88: 18800004                 bgu     loc_F00DFF98
F00DFF8C: d007bfdc                 ld      [%fp+var_24], %o0
F00DFF90: 10800024                 ba      loc_F00E0020
F00DFF94: 90122002                 bset    2, %o0
F00DFF98: 80a2400d                 cmp     %o1, %o5
F00DFF9C: 22800021                 be,a    loc_F00E0020
F00DFFA0: 90122010                 bset    0x10, %o0
F00DFFA4: 14800009                 bg      loc_F00DFFC8
F00DFFA8: 80a2400c                 cmp     %o1, %o4
F00DFFAC: 80a24013                 cmp     %o1, %l3
F00DFFB0: 02800013                 be      loc_F00DFFFC
F00DFFB4: 80a24012                 cmp     %o1, %l2
F00DFFB8: 0280001a                 be      loc_F00E0020
F00DFFBC: 90122008                 bset    8, %o0
F00DFFC0: 1080001a                 ba      loc_F00E0028
F00DFFC4: 9402a001                 inc     %o2
F00DFFC8: 02800012                 be      loc_F00E0010
F00DFFCC: 80a2400c                 cmp     %o1, %o4
F00DFFD0: 14800007                 bg      loc_F00DFFEC
F00DFFD4: 80a24003                 cmp     %o1, %g3
F00DFFD8: 80a2400f                 cmp     %o1, %o7
F00DFFDC: 0280000b                 be      loc_F00E0008
F00DFFE0: d007bfdc                 ld      [%fp+var_24], %o0
F00DFFE4: 10800011                 ba      loc_F00E0028
F00DFFE8: 9402a001                 inc     %o2
F00DFFEC: 0280000c                 be      loc_F00E001C
F00DFFF0: d007bfdc                 ld      [%fp+var_24], %o0
F00DFFF4: 1080000d                 ba      loc_F00E0028
F00DFFF8: 9402a001                 inc     %o2
F00DFFFC: d007bfdc                 ld      [%fp+var_24], %o0
F00E0000: 10800008                 ba      loc_F00E0020
F00E0004: 90122004                 bset    4, %o0
F00E0008: 10800006                 ba      loc_F00E0020
F00E000C: 90122020                 bset    0x20, %o0 ! ' '
F00E0010: d007bfdc                 ld      [%fp+var_24], %o0
F00E0014: 10800003                 ba      loc_F00E0020
F00E0018: 90122040                 bset    0x40, %o0 ! '@'
F00E001C: 90122080                 bset    0x80, %o0
F00E0020: d027bfdc                 st      %o0, [%fp+var_24]
F00E0024: 9402a001                 inc     %o2
F00E0028: 80a28002                 cmp     %o2, %g2
F00E002C: 06bfffd4                 bl      loc_F00DFF7C
F00E0030: 9602e004                 inc     4, %o3
F00E0034: 90100011                 mov     %l1, %o0
F00E0038: 9207bbc8                 add     %fp, var_438, %o1
F00E003C: 7ffffc18                 call    __NXAudioGetDataEncodings
F00E0040: 9407bbc0                 add     %fp, var_440, %o2
F00E0044: c027bfd0                 clr     [%fp+var_30]
F00E0048: d007bbc0                 ld      [%fp+var_440], %o0
F00E004C: 94102000                 mov     0, %o2
F00E0050: 80a28008                 cmp     %o2, %o0
F00E0054: 3680001d                 bge,a   loc_F00E00C8
F00E0058: 90100011                 mov     %l1, %o0
F00E005C: 96100008                 mov     %o0, %o3
F00E0060: 92100010                 mov     %l0, %o1
F00E0064: d0027c00                 ld      [%o1-0x400], %o0
F00E0068: 80a22259                 cmp     %o0, 0x259
F00E006C: 2280000e                 be,a    loc_F00E00A4
F00E0070: d007bfd0                 ld      [%fp+var_30], %o0
F00E0074: 14800007                 bg      loc_F00E0090
F00E0078: 80a2225a                 cmp     %o0, 0x25A
F00E007C: 80a22258                 cmp     %o0, 0x258
F00E0080: 0280000b                 be      loc_F00E00AC
F00E0084: d007bfd0                 ld      [%fp+var_30], %o0
F00E0088: 1080000c                 ba      loc_F00E00B8
F00E008C: 9402a001                 inc     %o2
F00E0090: 3280000a                 bne,a   loc_F00E00B8
F00E0094: 9402a001                 inc     %o2
F00E0098: d007bfd0                 ld      [%fp+var_30], %o0
F00E009C: 10800005                 ba      loc_F00E00B0
F00E00A0: 90122001                 bset    1, %o0
F00E00A4: 10800003                 ba      loc_F00E00B0
F00E00A8: 90122002                 bset    2, %o0
F00E00AC: 90122004                 bset    4, %o0
F00E00B0: d027bfd0                 st      %o0, [%fp+var_30]
F00E00B4: 9402a001                 inc     %o2
F00E00B8: 80a2800b                 cmp     %o2, %o3
F00E00BC: 06bfffea                 bl      loc_F00E0064
F00E00C0: 92026004                 inc     4, %o1
F00E00C4: 90100011                 mov     %l1, %o0
F00E00C8: 7ffffc07                 call    __NXAudioGetChannelCountLimit
F00E00CC: 9207bfcc                 add     %fp, var_34, %o1
F00E00D0: d2062010                 ld      [%i0+0x10], %o1
F00E00D4: d407bfdc                 ld      [%fp+var_24], %o2
F00E00D8: d607bfd8                 ld      [%fp+var_28], %o3
F00E00DC: d807bfd4                 ld      [%fp+var_2C], %o4
F00E00E0: da07bfd0                 ld      [%fp+var_30], %o5
F00E00E4: 90100019                 mov     %i1, %o0
F00E00E8: c407bfcc                 ld      [%fp+var_34], %g2
F00E00EC: a8102000                 mov     0, %l4
F00E00F0: 40000592                 call    _audio_snd_reply_ret_formats
F00E00F4: c423a05c                 st      %g2, [%sp+0x4A8+var_44C]
F00E00F8: 10800085                 ba      locret_F00E030C
F00E00FC: b0100014                 mov     %l4, %i0
F00E0100: d0062004                 ld      [%i0+4], %o0! jumptable F00DF988 case 14
F00E0104: 80a22020                 cmp     %o0, 0x20 ! ' '
F00E0108: 32800081                 bne,a   locret_F00E030C
F00E010C: b0102067                 mov     0x67, %i0 ! 'g'
F00E0110: 113c0506                 sethi   %hi(paIoaudio), %o0
F00E0114: d00222d4                 ld      [%o0+%lo(paIoaudio)], %o0! id
F00E0118: 133c0504                 sethi   %hi(paOutputchannelf), %o1
F00E011C: d20263c0                 ld      [%o1+%lo(paOutputchannelf)], %o1! SEL
F00E0120: 400045d4                 call    _objc_msgSend
F00E0124: d406200c                 ld      [%i0+0xC], %o2
F00E0128: a2100008                 mov     %o0, %l1
F00E012C: 7ffff8b9                 call    __NXAudioGetSndoutOptions
F00E0130: 9207bfe8                 add     %fp, var_18, %o1
F00E0134: d006201c                 ld      [%i0+0x1C], %o0
F00E0138: 808a2001                 btst    1, %o0
F00E013C: 02800004                 be      loc_F00E014C
F00E0140: d007bfe8                 ld      [%fp+var_18], %o0
F00E0144: 10800003                 ba      loc_F00E0150
F00E0148: 90122002                 bset    2, %o0
F00E014C: 900a3ffd                 and     %o0, -3, %o0
F00E0150: d027bfe8                 st      %o0, [%fp+var_18]
F00E0154: d006201c                 ld      [%i0+0x1C], %o0
F00E0158: 808a2002                 btst    2, %o0
F00E015C: 02800004                 be      loc_F00E016C
F00E0160: d007bfe8                 ld      [%fp+var_18], %o0
F00E0164: 10800003                 ba      loc_F00E0170
F00E0168: 90122004                 bset    4, %o0
F00E016C: 900a3ffb                 and     %o0, -5, %o0
F00E0170: d027bfe8                 st      %o0, [%fp+var_18]
F00E0174: 90100011                 mov     %l1, %o0
F00E0178: d407bfe8                 ld      [%fp+var_18], %o2
F00E017C: 7ffff8ea                 call    __NXAudioSetSndoutOptions
F00E0180: 92102000                 mov     0, %o1
F00E0184: 10800062                 ba      locret_F00E030C
F00E0188: b0100014                 mov     %l4, %i0
F00E018C: d0062004                 ld      [%i0+4], %o0! jumptable F00DF988 cases 6,7
F00E0190: 80a22028                 cmp     %o0, 0x28 ! '('
F00E0194: 3280005e                 bne,a   locret_F00E030C
F00E0198: b0102067                 mov     0x67, %i0 ! 'g'
F00E019C: 113c0506                 sethi   %hi(paAudiochannel), %o0
F00E01A0: d00222d0                 ld      [%o0+%lo(paAudiochannel)], %o0! id
F00E01A4: 133c0504                 sethi   %hi(paStreamforowner), %o1
F00E01A8: d20263ec                 ld      [%o1+%lo(paStreamforowner)], %o1! SEL
F00E01AC: 400045b1                 call    _objc_msgSend
F00E01B0: d4062024                 ld      [%i0+0x24], %o2
F00E01B4: 80a22000                 cmp     %o0, 0
F00E01B8: 02800054                 be      def_F00DF988! jumptable F00DF988 default case
F00E01BC: 92102002                 mov     2, %o1
F00E01C0: d807bff0                 ld      [%fp+var_10], %o4
F00E01C4: 9407bbc0                 add     %fp, var_440, %o2
F00E01C8: d607bff4                 ld      [%fp+var_C], %o3
F00E01CC: d827bbc0                 st      %o4, [%fp+var_440]
F00E01D0: 7ffff99f                 call    __NXAudioStreamControl
F00E01D4: d627bbc4                 st      %o3, [%fp+var_43C]
F00E01D8: 1080004d                 ba      locret_F00E030C
F00E01DC: b0100014                 mov     %l4, %i0
F00E01E0: d0062004                 ld      [%i0+4], %o0! jumptable F00DF988 case 10
F00E01E4: 80a22020                 cmp     %o0, 0x20 ! ' '
F00E01E8: 32800049                 bne,a   locret_F00E030C
F00E01EC: b0102067                 mov     0x67, %i0 ! 'g'
F00E01F0: 113c0504                 sethi   %hi(paOutputchannelf), %o0
F00E01F4: d20223c0                 ld      [%o0+%lo(paOutputchannelf)], %o1! SEL
F00E01F8: 113c0506                 sethi   %hi(paIoaudio), %o0! id
F00E01FC: e60222d4                 ld      [%o0+%lo(paIoaudio)], %l3
F00E0200: d406200c                 ld      [%i0+0xC], %o2
F00E0204: 4000459b                 call    _objc_msgSend
F00E0208: 90100013                 mov     %l3, %o0
F00E020C: a2100008                 mov     %o0, %l1
F00E0210: 113c0505                 sethi   %hi(paAudiodevice), %o0! id
F00E0214: d2022224                 ld      [%o0+%lo(paAudiodevice)], %o1! SEL
F00E0218: 40004596                 call    _objc_msgSend
F00E021C: 90100011                 mov     %l1, %o0
F00E0220: 7ffff5cd                 call    _audio_reset_snd_dev_port
F00E0224: d206201c                 ld      [%i0+0x1C], %o1! SEL
F00E0228: a4920000                 orcc    %o0, %g0, %l2
F00E022C: 12800004                 bne     loc_F00E023C
F00E0230: 113c0504                 sethi   -0xFEBF000, %o0
F00E0234: 10800036                 ba      locret_F00E030C
F00E0238: b0102070                 mov     0x70, %i0 ! 'p'
F00E023C: e00223bc                 ld      [%o0+0x3BC], %l0
F00E0240: 90100011                 mov     %l1, %o0! id
F00E0244: 4000458b                 call    _objc_msgSend
F00E0248: 92100010                 mov     %l0, %o1
F00E024C: 113c0504                 sethi   %hi(paInputchannelfo), %o0! id
F00E0250: d20223c8                 ld      [%o0+%lo(paInputchannelfo)], %o1! SEL
F00E0254: a8102000                 mov     0, %l4
F00E0258: d406200c                 ld      [%i0+0xC], %o2
F00E025C: 40004585                 call    _objc_msgSend
F00E0260: 90100013                 mov     %l3, %o0! id
F00E0264: 40004583                 call    _objc_msgSend
F00E0268: 92100010                 mov     %l0, %o1
F00E026C: 90100019                 mov     %i1, %o0
F00E0270: d2062010                 ld      [%i0+0x10], %o1
F00E0274: 40000481                 call    _audio_snd_reply_ret_device
F00E0278: 94100012                 mov     %l2, %o2
F00E027C: 10800024                 ba      locret_F00E030C
F00E0280: b0100014                 mov     %l4, %i0
F00E0284: d0062004                 ld      [%i0+4], %o0! jumptable F00DF988 case 12
F00E0288: 80a22030                 cmp     %o0, 0x30 ! '0'
F00E028C: 32800020                 bne,a   locret_F00E030C
F00E0290: b0102067                 mov     0x67, %i0 ! 'g'
F00E0294: 113c0506                 sethi   %hi(paAudiochannel), %o0
F00E0298: d00222d0                 ld      [%o0+%lo(paAudiochannel)], %o0! id
F00E029C: 133c0504                 sethi   %hi(paStreamforowner), %o1
F00E02A0: d20263ec                 ld      [%o1+%lo(paStreamforowner)], %o1! SEL
F00E02A4: 40004573                 call    _objc_msgSend
F00E02A8: d406201c                 ld      [%i0+0x1C], %o2
F00E02AC: 80a22000                 cmp     %o0, 0
F00E02B0: 02800017                 be      locret_F00E030C
F00E02B4: b010206a                 mov     0x6A, %i0 ! 'j'
F00E02B8: 3080000f                 ba,a    loc_F00E02F4
F00E02BC: d0062004                 ld      [%i0+4], %o0! jumptable F00DF988 case 13
F00E02C0: 80a22030                 cmp     %o0, 0x30 ! '0'
F00E02C4: 02800004                 be      loc_F00E02D4
F00E02C8: 113c0506                 sethi   -0xFEBE800, %o0
F00E02CC: 10800010                 ba      locret_F00E030C
F00E02D0: b0102067                 mov     0x67, %i0 ! 'g'
F00E02D4: d00222d0                 ld      [%o0+0x2D0], %o0! id
F00E02D8: 133c0504                 sethi   %hi(paStreamforowner), %o1
F00E02DC: d20263ec                 ld      [%o1+%lo(paStreamforowner)], %o1! SEL
F00E02E0: 40004564                 call    _objc_msgSend
F00E02E4: d406201c                 ld      [%i0+0x1C], %o2
F00E02E8: 80a22000                 cmp     %o0, 0
F00E02EC: 02800008                 be      locret_F00E030C
F00E02F0: b010206a                 mov     0x6A, %i0 ! 'j'
F00E02F4: 7ffff9a4                 call    __NXAudioRemoveStream
F00E02F8: b0100014                 mov     %l4, %i0
F00E02FC: 30800004                 ba,a    locret_F00E030C
F00E0300: 10800003                 ba      locret_F00E030C! jumptable F00DF988 cases 5,8,9,11
F00E0304: b010206c                 mov     0x6C, %i0 ! 'l'
F00E0308: b0100014                 mov     %l4, %i0! jumptable F00DF988 default case
F00E030C: 81c7e008                 ret
F00E0310: 81e80000                 restore
