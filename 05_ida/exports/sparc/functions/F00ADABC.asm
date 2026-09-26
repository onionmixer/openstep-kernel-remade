F00ADABC: 9de3bf98                 save    %sp, -0x68, %sp
F00ADAC0: d4068000                 ld      [%i2], %o2
F00ADAC4: 13200000                 sethi   0x80000000, %o1
F00ADAC8: d0064000                 ld      [%i1], %o0
F00ADACC: 922a8009                 andn    %o2, %o1, %o1
F00ADAD0: 912a201f                 sll     %o0, 31, %o0
F00ADAD4: 92124008                 bset    %o0, %o1
F00ADAD8: d2268000                 st      %o1, [%i2]
F00ADADC: d2066004                 ld      [%i1+4], %o1
F00ADAE0: 80a26005                 cmp     %o1, 5! switch 6 cases
F00ADAE4: 188000ab                 bgu     def_F00ADAF8! jumptable F00ADAF8 default case, case 3
F00ADAE8: 113c02b6                 sethi   %hi(jpt_F00ADAF8), %o0
F00ADAEC: 90122300                 bset    %lo(jpt_F00ADAF8), %o0
F00ADAF0: 932a6002                 sll     %o1, 2, %o1
F00ADAF4: d0024008                 ld      [%o1+%o0], %o0
F00ADAF8: 81c20000                 jmp     %o0! switch jump
F00ADAFC: 01000000                 nop
F00ADB18: d0068000                 ld      [%i2], %o0! jumptable F00ADAF8 case 0
F00ADB1C: 131ffc00                 sethi   0x7FF00000, %o1
F00ADB20: 922a0009                 andn    %o0, %o1, %o1
F00ADB24: 113ffc00                 sethi   -0x100000, %o0
F00ADB28: 920a4008                 and     %o1, %o0, %o1
F00ADB2C: d2268000                 st      %o1, [%i2]
F00ADB30: 10800098                 ba      def_F00ADAF8! jumptable F00ADAF8 default case, case 3
F00ADB34: c026c000                 clr     [%i3]
F00ADB38: d0068000                 ld      [%i2], %o0! jumptable F00ADAF8 case 2
F00ADB3C: 131ffc00                 sethi   0x7FF00000, %o1
F00ADB40: 90120009                 bset    %o1, %o0
F00ADB44: 133ffc00                 sethi   -0x100000, %o1
F00ADB48: 900a0009                 and     %o0, %o1, %o0
F00ADB4C: d0268000                 st      %o0, [%i2]
F00ADB50: 10800090                 ba      def_F00ADAF8! jumptable F00ADAF8 default case, case 3
F00ADB54: c026c000                 clr     [%i3]
F00ADB58: 90100019                 mov     %i1, %o0! jumptable F00ADAF8 cases 4,5
F00ADB5C: 40000381                 call    _fpu_rightshift
F00ADB60: 9210203c                 mov     0x3C, %o1 ! '<'
F00ADB64: d4068000                 ld      [%i2], %o2
F00ADB68: 111ffc00                 sethi   0x7FF00000, %o0
F00ADB6C: 94128008                 bset    %o0, %o2
F00ADB70: d4268000                 st      %o2, [%i2]
F00ADB74: 113ffc00                 sethi   -0x100000, %o0
F00ADB78: 940a8008                 and     %o2, %o0, %o2
F00ADB7C: d0066014                 ld      [%i1+0x14], %o0
F00ADB80: 133ffe00                 sethi   -0x80000, %o1
F00ADB84: 922a0009                 andn    %o0, %o1, %o1
F00ADB88: 11000200                 sethi   0x80000, %o0
F00ADB8C: 92124008                 bset    %o0, %o1
F00ADB90: 113ffc00                 sethi   -0x100000, %o0
F00ADB94: 902a4008                 andn    %o1, %o0, %o0
F00ADB98: 94128008                 bset    %o0, %o2
F00ADB9C: 1080007b                 ba      loc_F00ADD88
F00ADBA0: d4268000                 st      %o2, [%i2]
F00ADBA4: 90100019                 mov     %i1, %o0! jumptable F00ADAF8 case 1
F00ADBA8: 4000036e                 call    _fpu_rightshift
F00ADBAC: 9210203c                 mov     0x3C, %o1 ! '<'
F00ADBB0: d0066008                 ld      [%i1+8], %o0
F00ADBB4: 900223ff                 inc     0x3FF, %o0
F00ADBB8: 80a22000                 cmp     %o0, 0
F00ADBBC: 1480003a                 bg      loc_F00ADCA4
F00ADBC0: d0266008                 st      %o0, [%i1+8]
F00ADBC4: 90100019                 mov     %i1, %o0
F00ADBC8: 152003ff                 sethi   -0x7FF00400, %o2
F00ADBCC: d2068000                 ld      [%i2], %o1
F00ADBD0: a012a3ff                 or      %o2, 0x3FF, %l0
F00ADBD4: 920a4010                 and     %o1, %l0, %o1
F00ADBD8: d2268000                 st      %o1, [%i2]
F00ADBDC: d4066008                 ld      [%i1+8], %o2
F00ADBE0: 92102001                 mov     1, %o1
F00ADBE4: 4000035f                 call    _fpu_rightshift
F00ADBE8: 9222400a                 sub     %o1, %o2, %o1
F00ADBEC: 90100018                 mov     %i0, %o0
F00ADBF0: 7ffffe82                 call    sub_F00AD5F8
F00ADBF4: 92100019                 mov     %i1, %o1
F00ADBF8: d6066014                 ld      [%i1+0x14], %o3
F00ADBFC: 11000400                 sethi   0x100000, %o0
F00ADC00: 80a2c008                 cmp     %o3, %o0
F00ADC04: 3280000e                 bne,a   loc_F00ADC3C
F00ADC08: d2068000                 ld      [%i2], %o1
F00ADC0C: 90100018                 mov     %i0, %o0
F00ADC10: d4068000                 ld      [%i2], %o2
F00ADC14: 92102000                 mov     0, %o1
F00ADC18: 940a8010                 and     %o2, %l0, %o2
F00ADC1C: 9412800b                 bset    %o3, %o2
F00ADC20: 173ffc00                 sethi   -0x100000, %o3
F00ADC24: 940a800b                 and     %o2, %o3, %o2
F00ADC28: d4268000                 st      %o2, [%i2]
F00ADC2C: 400003a6                 call    _fpu_set_exception
F00ADC30: c026c000                 clr     [%i3]
F00ADC34: 1080000d                 ba      loc_F00ADC68
F00ADC38: d006200c                 ld      [%i0+0xC], %o0
F00ADC3C: 113ffc00                 sethi   -0x100000, %o0
F00ADC40: 920a4010                 and     %o1, %l0, %o1
F00ADC44: d2268000                 st      %o1, [%i2]
F00ADC48: 920a4008                 and     %o1, %o0, %o1
F00ADC4C: d4066014                 ld      [%i1+0x14], %o2
F00ADC50: 902a8008                 andn    %o2, %o0, %o0
F00ADC54: 92124008                 bset    %o0, %o1
F00ADC58: d2268000                 st      %o1, [%i2]
F00ADC5C: d0066018                 ld      [%i1+0x18], %o0
F00ADC60: d026c000                 st      %o0, [%i3]
F00ADC64: d006200c                 ld      [%i0+0xC], %o0
F00ADC68: 808a2001                 btst    1, %o0
F00ADC6C: 02800004                 be      loc_F00ADC7C
F00ADC70: 90100018                 mov     %i0, %o0
F00ADC74: 40000394                 call    _fpu_set_exception
F00ADC78: 92102002                 mov     2, %o1
F00ADC7C: d0060000                 ld      [%i0], %o0
F00ADC80: 808a2004                 btst    4, %o0
F00ADC84: 02800043                 be      def_F00ADAF8! jumptable F00ADAF8 default case, case 3
F00ADC88: 90100018                 mov     %i0, %o0
F00ADC8C: 4000038e                 call    _fpu_set_exception
F00ADC90: 92102002                 mov     2, %o1
F00ADC94: d006200c                 ld      [%i0+0xC], %o0
F00ADC98: 900a3ffe                 and     %o0, -2, %o0
F00ADC9C: 1080003d                 ba      def_F00ADAF8! jumptable F00ADAF8 default case, case 3
F00ADCA0: d026200c                 st      %o0, [%i0+0xC]
F00ADCA4: 90100018                 mov     %i0, %o0
F00ADCA8: 7ffffe54                 call    sub_F00AD5F8
F00ADCAC: 92100019                 mov     %i1, %o1
F00ADCB0: d2066014                 ld      [%i1+0x14], %o1
F00ADCB4: 11000800                 sethi   0x200000, %o0
F00ADCB8: 80a24008                 cmp     %o1, %o0
F00ADCBC: 32800008                 bne,a   loc_F00ADCDC
F00ADCC0: d4066008                 ld      [%i1+8], %o2
F00ADCC4: 13000400                 sethi   0x100000, %o1
F00ADCC8: d0066008                 ld      [%i1+8], %o0
F00ADCCC: d2266014                 st      %o1, [%i1+0x14]
F00ADCD0: 90022001                 inc     %o0
F00ADCD4: d0266008                 st      %o0, [%i1+8]
F00ADCD8: d4066008                 ld      [%i1+8], %o2
F00ADCDC: 80a2a7fe                 cmp     %o2, 0x7FE
F00ADCE0: 0480001d                 ble     loc_F00ADD54
F00ADCE4: 90100018                 mov     %i0, %o0
F00ADCE8: 40000377                 call    _fpu_set_exception
F00ADCEC: 92102003                 mov     3, %o1
F00ADCF0: 90100018                 mov     %i0, %o0
F00ADCF4: 40000374                 call    _fpu_set_exception
F00ADCF8: 92102000                 mov     0, %o1
F00ADCFC: d0060000                 ld      [%i0], %o0
F00ADD00: 808a2008                 btst    8, %o0
F00ADD04: 22800006                 be,a    loc_F00ADD1C
F00ADD08: d2064000                 ld      [%i1], %o1
F00ADD0C: d006200c                 ld      [%i0+0xC], %o0
F00ADD10: 900a3ffe                 and     %o0, -2, %o0
F00ADD14: d026200c                 st      %o0, [%i0+0xC]
F00ADD18: d2064000                 ld      [%i1], %o1
F00ADD1C: 7ffffe25                 call    sub_F00AD5B0
F00ADD20: 90100018                 mov     %i0, %o0
F00ADD24: 80a22000                 cmp     %o0, 0
F00ADD28: 12bfff85                 bne     loc_F00ADB3C
F00ADD2C: d0068000                 ld      [%i2], %o0
F00ADD30: 131ffc00                 sethi   0x7FF00000, %o1
F00ADD34: 922a0009                 andn    %o0, %o1, %o1
F00ADD38: 111ff800                 sethi   0x7FE00000, %o0
F00ADD3C: 92124008                 bset    %o0, %o1
F00ADD40: 113ffc00                 sethi   -0x100000, %o0
F00ADD44: 90324008                 orn     %o1, %o0, %o0
F00ADD48: d0268000                 st      %o0, [%i2]
F00ADD4C: 10800010                 ba      loc_F00ADD8C
F00ADD50: 90103fff                 mov     -1, %o0
F00ADD54: d0068000                 ld      [%i2], %o0
F00ADD58: 131ffc00                 sethi   0x7FF00000, %o1
F00ADD5C: 922a0009                 andn    %o0, %o1, %o1
F00ADD60: 900aa7ff                 and     %o2, 0x7FF, %o0
F00ADD64: 912a2014                 sll     %o0, 20, %o0
F00ADD68: 92124008                 bset    %o0, %o1
F00ADD6C: d2268000                 st      %o1, [%i2]
F00ADD70: 113ffc00                 sethi   -0x100000, %o0
F00ADD74: 920a4008                 and     %o1, %o0, %o1
F00ADD78: d4066014                 ld      [%i1+0x14], %o2
F00ADD7C: 902a8008                 andn    %o2, %o0, %o0
F00ADD80: 92124008                 bset    %o0, %o1
F00ADD84: d2268000                 st      %o1, [%i2]
F00ADD88: d0066018                 ld      [%i1+0x18], %o0
F00ADD8C: d026c000                 st      %o0, [%i3]
F00ADD90: 81c7e008                 ret! jumptable F00ADAF8 default case, case 3
F00ADD94: 81e80000                 restore
