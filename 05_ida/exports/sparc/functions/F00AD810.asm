F00AD810: 9de3bf98                 save    %sp, -0x68, %sp
F00AD814: d4068000                 ld      [%i2], %o2
F00AD818: 13200000                 sethi   0x80000000, %o1
F00AD81C: d0064000                 ld      [%i1], %o0
F00AD820: 922a8009                 andn    %o2, %o1, %o1
F00AD824: 912a201f                 sll     %o0, 31, %o0
F00AD828: 92124008                 bset    %o0, %o1
F00AD82C: d2268000                 st      %o1, [%i2]
F00AD830: d2066004                 ld      [%i1+4], %o1
F00AD834: 80a26005                 cmp     %o1, 5! switch 6 cases
F00AD838: 1880009f                 bgu     def_F00AD84C! jumptable F00AD84C default case, case 3
F00AD83C: 113c02b6                 sethi   %hi(jpt_F00AD84C), %o0
F00AD840: 90122054                 bset    %lo(jpt_F00AD84C), %o0
F00AD844: 932a6002                 sll     %o1, 2, %o1
F00AD848: d0024008                 ld      [%o1+%o0], %o0
F00AD84C: 81c20000                 jmp     %o0! switch jump
F00AD850: 01000000                 nop
F00AD86C: d0068000                 ld      [%i2], %o0! jumptable F00AD84C case 0
F00AD870: 131fe000                 sethi   0x7F800000, %o1
F00AD874: 922a0009                 andn    %o0, %o1, %o1
F00AD878: 113fe000                 sethi   -0x800000, %o0
F00AD87C: 1080008d                 ba      loc_F00ADAB0
F00AD880: 920a4008                 and     %o1, %o0, %o1
F00AD884: d0068000                 ld      [%i2], %o0! jumptable F00AD84C case 2
F00AD888: 131fe000                 sethi   0x7F800000, %o1
F00AD88C: 90120009                 bset    %o1, %o0
F00AD890: 133fe000                 sethi   -0x800000, %o1
F00AD894: 900a0009                 and     %o0, %o1, %o0
F00AD898: 10800087                 ba      def_F00AD84C! jumptable F00AD84C default case, case 3
F00AD89C: d0268000                 st      %o0, [%i2]
F00AD8A0: 90100019                 mov     %i1, %o0! jumptable F00AD84C cases 4,5
F00AD8A4: 4000042f                 call    _fpu_rightshift
F00AD8A8: 92102059                 mov     0x59, %o1 ! 'Y'
F00AD8AC: d4068000                 ld      [%i2], %o2
F00AD8B0: 111fe000                 sethi   0x7F800000, %o0
F00AD8B4: 94128008                 bset    %o0, %o2
F00AD8B8: d4268000                 st      %o2, [%i2]
F00AD8BC: 113fe000                 sethi   -0x800000, %o0
F00AD8C0: 940a8008                 and     %o2, %o0, %o2
F00AD8C4: d0066018                 ld      [%i1+0x18], %o0
F00AD8C8: 133ff000                 sethi   -0x400000, %o1
F00AD8CC: 922a0009                 andn    %o0, %o1, %o1
F00AD8D0: 11001000                 sethi   0x400000, %o0
F00AD8D4: 92124008                 bset    %o0, %o1
F00AD8D8: 113fe000                 sethi   -0x800000, %o0
F00AD8DC: 902a4008                 andn    %o1, %o0, %o0
F00AD8E0: 94128008                 bset    %o0, %o2
F00AD8E4: 10800074                 ba      def_F00AD84C! jumptable F00AD84C default case, case 3
F00AD8E8: d4268000                 st      %o2, [%i2]
F00AD8EC: 90100019                 mov     %i1, %o0! jumptable F00AD84C case 1
F00AD8F0: 4000041c                 call    _fpu_rightshift
F00AD8F4: 92102059                 mov     0x59, %o1 ! 'Y'
F00AD8F8: d0066008                 ld      [%i1+8], %o0
F00AD8FC: 9002207f                 inc     0x7F, %o0
F00AD900: 80a22000                 cmp     %o0, 0
F00AD904: 14800034                 bg      loc_F00AD9D4
F00AD908: d0266008                 st      %o0, [%i1+8]
F00AD90C: 90100019                 mov     %i1, %o0
F00AD910: 15201fff                 sethi   -0x7F800400, %o2
F00AD914: d2068000                 ld      [%i2], %o1
F00AD918: a012a3ff                 or      %o2, 0x3FF, %l0
F00AD91C: 920a4010                 and     %o1, %l0, %o1
F00AD920: d2268000                 st      %o1, [%i2]
F00AD924: d4066008                 ld      [%i1+8], %o2
F00AD928: 92102001                 mov     1, %o1
F00AD92C: 4000040d                 call    _fpu_rightshift
F00AD930: 9222400a                 sub     %o1, %o2, %o1
F00AD934: 90100018                 mov     %i0, %o0
F00AD938: 7fffff30                 call    sub_F00AD5F8
F00AD93C: 92100019                 mov     %i1, %o1
F00AD940: f2066018                 ld      [%i1+0x18], %i1
F00AD944: 11002000                 sethi   0x800000, %o0
F00AD948: 80a64008                 cmp     %i1, %o0
F00AD94C: 3280000d                 bne,a   loc_F00AD980
F00AD950: d0068000                 ld      [%i2], %o0
F00AD954: 90100018                 mov     %i0, %o0
F00AD958: d4068000                 ld      [%i2], %o2
F00AD95C: 92102000                 mov     0, %o1
F00AD960: 173fe000                 sethi   -0x800000, %o3
F00AD964: 940a8010                 and     %o2, %l0, %o2
F00AD968: 94128019                 bset    %i1, %o2
F00AD96C: 940a800b                 and     %o2, %o3, %o2
F00AD970: 40000455                 call    _fpu_set_exception
F00AD974: d4268000                 st      %o2, [%i2]
F00AD978: 10800008                 ba      loc_F00AD998
F00AD97C: d006200c                 ld      [%i0+0xC], %o0
F00AD980: 133fe000                 sethi   -0x800000, %o1
F00AD984: 900a0009                 and     %o0, %o1, %o0
F00AD988: 922e4009                 andn    %i1, %o1, %o1
F00AD98C: 90120009                 bset    %o1, %o0
F00AD990: d0268000                 st      %o0, [%i2]
F00AD994: d006200c                 ld      [%i0+0xC], %o0
F00AD998: 808a2001                 btst    1, %o0
F00AD99C: 02800004                 be      loc_F00AD9AC
F00AD9A0: 90100018                 mov     %i0, %o0
F00AD9A4: 40000448                 call    _fpu_set_exception
F00AD9A8: 92102002                 mov     2, %o1
F00AD9AC: d0060000                 ld      [%i0], %o0
F00AD9B0: 808a2004                 btst    4, %o0
F00AD9B4: 02800040                 be      def_F00AD84C! jumptable F00AD84C default case, case 3
F00AD9B8: 90100018                 mov     %i0, %o0
F00AD9BC: 40000442                 call    _fpu_set_exception
F00AD9C0: 92102002                 mov     2, %o1
F00AD9C4: d006200c                 ld      [%i0+0xC], %o0
F00AD9C8: 900a3ffe                 and     %o0, -2, %o0
F00AD9CC: 1080003a                 ba      def_F00AD84C! jumptable F00AD84C default case, case 3
F00AD9D0: d026200c                 st      %o0, [%i0+0xC]
F00AD9D4: 90100018                 mov     %i0, %o0
F00AD9D8: 7fffff08                 call    sub_F00AD5F8
F00AD9DC: 92100019                 mov     %i1, %o1
F00AD9E0: d2066018                 ld      [%i1+0x18], %o1
F00AD9E4: 11004000                 sethi   0x1000000, %o0
F00AD9E8: 80a24008                 cmp     %o1, %o0
F00AD9EC: 32800008                 bne,a   loc_F00ADA0C
F00AD9F0: d4066008                 ld      [%i1+8], %o2
F00AD9F4: 13002000                 sethi   0x800000, %o1
F00AD9F8: d0066008                 ld      [%i1+8], %o0
F00AD9FC: d2266018                 st      %o1, [%i1+0x18]
F00ADA00: 90022001                 inc     %o0
F00ADA04: d0266008                 st      %o0, [%i1+8]
F00ADA08: d4066008                 ld      [%i1+8], %o2
F00ADA0C: 80a2a0fe                 cmp     %o2, 0xFE
F00ADA10: 0480001c                 ble     loc_F00ADA80
F00ADA14: 90100018                 mov     %i0, %o0
F00ADA18: 4000042b                 call    _fpu_set_exception
F00ADA1C: 92102003                 mov     3, %o1
F00ADA20: 90100018                 mov     %i0, %o0
F00ADA24: 40000428                 call    _fpu_set_exception
F00ADA28: 92102000                 mov     0, %o1
F00ADA2C: d0060000                 ld      [%i0], %o0
F00ADA30: 808a2008                 btst    8, %o0
F00ADA34: 22800006                 be,a    loc_F00ADA4C
F00ADA38: d2064000                 ld      [%i1], %o1
F00ADA3C: d006200c                 ld      [%i0+0xC], %o0
F00ADA40: 900a3ffe                 and     %o0, -2, %o0
F00ADA44: d026200c                 st      %o0, [%i0+0xC]
F00ADA48: d2064000                 ld      [%i1], %o1
F00ADA4C: 7ffffed9                 call    sub_F00AD5B0
F00ADA50: 90100018                 mov     %i0, %o0
F00ADA54: 80a22000                 cmp     %o0, 0
F00ADA58: 12bfff8c                 bne     loc_F00AD888
F00ADA5C: d0068000                 ld      [%i2], %o0
F00ADA60: 131fe000                 sethi   0x7F800000, %o1
F00ADA64: 922a0009                 andn    %o0, %o1, %o1
F00ADA68: 111fc000                 sethi   0x7F000000, %o0
F00ADA6C: 92124008                 bset    %o0, %o1
F00ADA70: 113fe000                 sethi   -0x800000, %o0
F00ADA74: 90324008                 orn     %o1, %o0, %o0
F00ADA78: 1080000f                 ba      def_F00AD84C! jumptable F00AD84C default case, case 3
F00ADA7C: d0268000                 st      %o0, [%i2]
F00ADA80: d0068000                 ld      [%i2], %o0
F00ADA84: 131fe000                 sethi   0x7F800000, %o1
F00ADA88: 922a0009                 andn    %o0, %o1, %o1
F00ADA8C: 900aa0ff                 and     %o2, 0xFF, %o0
F00ADA90: 912a2017                 sll     %o0, 23, %o0
F00ADA94: 92124008                 bset    %o0, %o1
F00ADA98: d2268000                 st      %o1, [%i2]
F00ADA9C: 113fe000                 sethi   -0x800000, %o0
F00ADAA0: 920a4008                 and     %o1, %o0, %o1
F00ADAA4: d4066018                 ld      [%i1+0x18], %o2
F00ADAA8: 902a8008                 andn    %o2, %o0, %o0
F00ADAAC: 92124008                 bset    %o0, %o1
F00ADAB0: d2268000                 st      %o1, [%i2]
F00ADAB4: 81c7e008                 ret! jumptable F00AD84C default case, case 3
F00ADAB8: 81e80000                 restore
