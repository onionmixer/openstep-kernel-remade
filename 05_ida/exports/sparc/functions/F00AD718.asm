F00AD718: 9de3bf98                 save    %sp, -0x68, %sp
F00AD71C: d2066004                 ld      [%i1+4], %o1
F00AD720: 80a26005                 cmp     %o1, 5! switch 6 cases
F00AD724: 18800039                 bgu     def_F00AD738! jumptable F00AD738 default case, case 3
F00AD728: 113c02b5                 sethi   %hi(jpt_F00AD738), %o0
F00AD72C: 90122340                 bset    %lo(jpt_F00AD738), %o0
F00AD730: 932a6002                 sll     %o1, 2, %o1
F00AD734: d0024008                 ld      [%o1+%o0], %o0
F00AD738: 81c20000                 jmp     %o0! switch jump
F00AD73C: 01000000                 nop
F00AD758: 1080002c                 ba      def_F00AD738! jumptable F00AD738 case 0
F00AD75C: c0268000                 clr     [%i2]
F00AD760: d4066008                 ld      [%i1+8], %o2! jumptable F00AD738 case 1
F00AD764: 80a2a01f                 cmp     %o2, 0x1F
F00AD768: 3480001c                 bg,a    loc_F00AD7D8
F00AD76C: d0064000                 ld      [%i1], %o0
F00AD770: 90100019                 mov     %i1, %o0
F00AD774: 92102070                 mov     0x70, %o1 ! 'p'
F00AD778: 4000047a                 call    _fpu_rightshift
F00AD77C: 9222400a                 sub     %o1, %o2, %o1
F00AD780: 90100018                 mov     %i0, %o0
F00AD784: 7fffff9d                 call    sub_F00AD5F8
F00AD788: 92100019                 mov     %i1, %o1
F00AD78C: d2066018                 ld      [%i1+0x18], %o1
F00AD790: 80a26000                 cmp     %o1, 0
F00AD794: 3680000a                 bge,a   loc_F00AD7BC
F00AD798: d2268000                 st      %o1, [%i2]
F00AD79C: d0064000                 ld      [%i1], %o0
F00AD7A0: 80a22000                 cmp     %o0, 0
F00AD7A4: 0280000c                 be      loc_F00AD7D4! jumptable F00AD738 cases 2,4,5
F00AD7A8: 11200000                 sethi   0x80000000, %o0
F00AD7AC: 80a24008                 cmp     %o1, %o0
F00AD7B0: 3880000a                 bgu,a   loc_F00AD7D8
F00AD7B4: d0064000                 ld      [%i1], %o0
F00AD7B8: d2268000                 st      %o1, [%i2]
F00AD7BC: d0064000                 ld      [%i1], %o0
F00AD7C0: 80a22000                 cmp     %o0, 0
F00AD7C4: 02800011                 be      def_F00AD738! jumptable F00AD738 default case, case 3
F00AD7C8: 90200009                 neg     %o1, %o0
F00AD7CC: 1080000f                 ba      def_F00AD738! jumptable F00AD738 default case, case 3
F00AD7D0: d0268000                 st      %o0, [%i2]
F00AD7D4: d0064000                 ld      [%i1], %o0! jumptable F00AD738 cases 2,4,5
F00AD7D8: 80a22000                 cmp     %o0, 0
F00AD7DC: 12800004                 bne     loc_F00AD7EC
F00AD7E0: 11200000                 sethi   0x80000000, %o0
F00AD7E4: 111fffff901223ff         set     0x7FFFFFFF, %o0
F00AD7EC: d0268000                 st      %o0, [%i2]
F00AD7F0: 90100018                 mov     %i0, %o0
F00AD7F4: d402200c                 ld      [%o0+0xC], %o2
F00AD7F8: 92102004                 mov     4, %o1
F00AD7FC: 940abffe                 and     %o2, -2, %o2
F00AD800: 400004b1                 call    _fpu_set_exception
F00AD804: d422200c                 st      %o2, [%o0+0xC]
F00AD808: 81c7e008                 ret! jumptable F00AD738 default case, case 3
F00AD80C: 81e80000                 restore
