F00C26E8: 9de3bf98                 save    %sp, -0x68, %sp
F00C26EC: 40000136                 call    sub_F00C2BC4
F00C26F0: 90100019                 mov     %i1, %o0
F00C26F4: a0920000                 orcc    %o0, %g0, %l0
F00C26F8: 028000a5                 be      locret_F00C298C
F00C26FC: 01000000                 nop
F00C2700: d4040000                 ld      [%l0], %o2
F00C2704: 80a2a000                 cmp     %o2, 0
F00C2708: 028000a1                 be      locret_F00C298C
F00C270C: 01000000                 nop
F00C2710: d6542020                 ldsh    [%l0+0x20], %o3
F00C2714: d252a002                 ldsh    [%o2+2], %o1
F00C2718: 80a2e004                 cmp     %o3, 4! switch 5 cases
F00C271C: 912a6001                 sll     %o1, 1, %o0
F00C2720: 90020009                 add     %o0, %o1, %o0
F00C2724: 912a2002                 sll     %o0, 2, %o0
F00C2728: 90022004                 inc     4, %o0
F00C272C: 1880004d                 bgu     def_F00C2744! jumptable F00C2744 default case
F00C2730: b2028008                 add     %o2, %o0, %i1
F00C2734: 113c03099012234c         set     jpt_F00C2744, %o0
F00C273C: 932ae002                 sll     %o3, 2, %o1
F00C2740: d0024008                 ld      [%o1+%o0], %o0
F00C2744: 81c20000                 jmp     %o0! switch jump
F00C2748: 01000000                 nop
F00C2760: 900e20f0                 and     %i0, 0xF0, %o0! jumptable F00C2744 case 0
F00C2764: 80a22080                 cmp     %o0, 0x80
F00C2768: 12800089                 bne     locret_F00C298C
F00C276C: 900e2007                 and     %i0, 7, %o0
F00C2770: d02e6002                 stb     %o0, [%i1+2]
F00C2774: 920e2008                 and     %i0, 8, %o1
F00C2778: d004202c                 ld      [%l0+0x2C], %o0
F00C277C: d234201c                 sth     %o1, [%l0+0x1C]
F00C2780: 90022001                 inc     %o0
F00C2784: 10800037                 ba      def_F00C2744! jumptable F00C2744 default case
F00C2788: d024202c                 st      %o0, [%l0+0x2C]
F00C278C: d24e4000                 ldsb    [%i1], %o1! jumptable F00C2744 case 1
F00C2790: 912e2018                 sll     %i0, 24, %o0
F00C2794: 913a2018                 sra     %o0, 24, %o0
F00C2798: 92024008                 add     %o1, %o0, %o1
F00C279C: 80a2607f                 cmp     %o1, 0x7F
F00C27A0: 34800021                 bg,a    loc_F00C2824
F00C27A4: 9010207f                 mov     0x7F, %o0
F00C27A8: 80a27f80                 cmp     %o1, -0x80
F00C27AC: 3680002d                 bge,a   def_F00C2744! jumptable F00C2744 default case
F00C27B0: d22e4000                 stb     %o1, [%i1]
F00C27B4: 1080001a                 ba      loc_F00C281C
F00C27B8: 90103f80                 mov     -0x80, %o0
F00C27BC: d24e6001                 ldsb    [%i1+1], %o1! jumptable F00C2744 case 2
F00C27C0: 912e2018                 sll     %i0, 24, %o0
F00C27C4: 913a2018                 sra     %o0, 24, %o0
F00C27C8: 92224008                 sub     %o1, %o0, %o1
F00C27CC: 80a2607f                 cmp     %o1, 0x7F
F00C27D0: 34800023                 bg,a    loc_F00C285C
F00C27D4: 9010207f                 mov     0x7F, %o0
F00C27D8: 80a27f80                 cmp     %o1, -0x80
F00C27DC: 36800021                 bge,a   def_F00C2744! jumptable F00C2744 default case
F00C27E0: d22e6001                 stb     %o1, [%i1+1]
F00C27E4: 1080001e                 ba      loc_F00C285C
F00C27E8: 90103f80                 mov     -0x80, %o0
F00C27EC: d24e4000                 ldsb    [%i1], %o1! jumptable F00C2744 case 3
F00C27F0: 912e2018                 sll     %i0, 24, %o0
F00C27F4: 913a2018                 sra     %o0, 24, %o0
F00C27F8: 92024008                 add     %o1, %o0, %o1
F00C27FC: 80a2607f                 cmp     %o1, 0x7F
F00C2800: 34800009                 bg,a    loc_F00C2824
F00C2804: 9010207f                 mov     0x7F, %o0
F00C2808: 80a27f80                 cmp     %o1, -0x80
F00C280C: 06800004                 bl      loc_F00C281C
F00C2810: 90103f80                 mov     -0x80, %o0
F00C2814: 10800013                 ba      def_F00C2744! jumptable F00C2744 default case
F00C2818: d22e4000                 stb     %o1, [%i1]
F00C281C: 10800011                 ba      def_F00C2744! jumptable F00C2744 default case
F00C2820: d02e4000                 stb     %o0, [%i1]
F00C2824: 1080000f                 ba      def_F00C2744! jumptable F00C2744 default case
F00C2828: d02e4000                 stb     %o0, [%i1]
F00C282C: d24e6001                 ldsb    [%i1+1], %o1! jumptable F00C2744 case 4
F00C2830: 912e2018                 sll     %i0, 24, %o0
F00C2834: 913a2018                 sra     %o0, 24, %o0
F00C2838: 92224008                 sub     %o1, %o0, %o1
F00C283C: 80a2607f                 cmp     %o1, 0x7F
F00C2840: 34800007                 bg,a    loc_F00C285C
F00C2844: 9010207f                 mov     0x7F, %o0
F00C2848: 80a27f80                 cmp     %o1, -0x80
F00C284C: 06800004                 bl      loc_F00C285C
F00C2850: 90103f80                 mov     -0x80, %o0
F00C2854: 10800003                 ba      def_F00C2744! jumptable F00C2744 default case
F00C2858: d22e6001                 stb     %o1, [%i1+1]
F00C285C: d02e6001                 stb     %o0, [%i1+1]
F00C2860: d2542020                 ldsh    [%l0+0x20], %o1! jumptable F00C2744 default case
F00C2864: 80a26004                 cmp     %o1, 4
F00C2868: 2280000e                 be,a    loc_F00C28A0
F00C286C: c0342020                 clrh    [%l0+0x20]
F00C2870: d054201c                 ldsh    [%l0+0x1C], %o0
F00C2874: 80a22000                 cmp     %o0, 0
F00C2878: 02800006                 be      loc_F00C2890
F00C287C: 80a26002                 cmp     %o1, 2
F00C2880: 32800005                 bne,a   loc_F00C2894
F00C2884: d0142020                 lduh    [%l0+0x20], %o0
F00C2888: 10800006                 ba      loc_F00C28A0
F00C288C: c0342020                 clrh    [%l0+0x20]
F00C2890: d0142020                 lduh    [%l0+0x20], %o0
F00C2894: 90022001                 inc     %o0
F00C2898: 1080003d                 ba      locret_F00C298C
F00C289C: d0342020                 sth     %o0, [%l0+0x20]
F00C28A0: d0542022                 ldsh    [%l0+0x22], %o0
F00C28A4: 80a22000                 cmp     %o0, 0
F00C28A8: 02800006                 be      loc_F00C28C0
F00C28AC: 113c030a                 sethi   %hi(sub_F00C2994), %o0
F00C28B0: 90122194                 bset    %lo(sub_F00C2994), %o0
F00C28B4: 7ffd1de8                 call    _untimeout
F00C28B8: 92100010                 mov     %l0, %o1
F00C28BC: c0342022                 clrh    [%l0+0x22]
F00C28C0: d24e6002                 ldsb    [%i1+2], %o1
F00C28C4: d04c201e                 ldsb    [%l0+0x1E], %o0
F00C28C8: 80a24008                 cmp     %o1, %o0
F00C28CC: 3280002d                 bne,a   loc_F00C2980
F00C28D0: d20e6002                 ldub    [%i1+2], %o1
F00C28D4: d2064000                 ld      [%i1], %o1
F00C28D8: 113fffc0                 sethi   -0x10000, %o0
F00C28DC: 808a4008                 btst    %o0, %o1
F00C28E0: 0280002b                 be      locret_F00C298C
F00C28E4: 113c0484                 sethi   %hi(_ms_jitter_thresh), %o0
F00C28E8: d254201c                 ldsh    [%l0+0x1C], %o1
F00C28EC: 80a26000                 cmp     %o1, 0
F00C28F0: 02800003                 be      loc_F00C28FC
F00C28F4: d4022118                 ld      [%o0+%lo(_ms_jitter_thresh)], %o2
F00C28F8: 952aa001                 sll     %o2, 1, %o2
F00C28FC: d04e4000                 ldsb    [%i1], %o0
F00C2900: 80a22000                 cmp     %o0, 0
F00C2904: 06800006                 bl      loc_F00C291C
F00C2908: 80a2000a                 cmp     %o0, %o2
F00C290C: 24800009                 ble,a   loc_F00C2930
F00C2910: d04e6001                 ldsb    [%i1+1], %o0
F00C2914: 1080001b                 ba      loc_F00C2980
F00C2918: d20e6002                 ldub    [%i1+2], %o1
F00C291C: 90200008                 neg     %o0
F00C2920: 80a2000a                 cmp     %o0, %o2
F00C2924: 34800017                 bg,a    loc_F00C2980
F00C2928: d20e6002                 ldub    [%i1+2], %o1
F00C292C: d04e6001                 ldsb    [%i1+1], %o0
F00C2930: 80a22000                 cmp     %o0, 0
F00C2934: 06800006                 bl      loc_F00C294C
F00C2938: 80a2000a                 cmp     %o0, %o2
F00C293C: 04800009                 ble     loc_F00C2960
F00C2940: 90102001                 mov     1, %o0
F00C2944: 1080000f                 ba      loc_F00C2980
F00C2948: d20e6002                 ldub    [%i1+2], %o1
F00C294C: 90200008                 neg     %o0
F00C2950: 80a2000a                 cmp     %o0, %o2
F00C2954: 3480000b                 bg,a    loc_F00C2980
F00C2958: d20e6002                 ldub    [%i1+2], %o1
F00C295C: 90102001                 mov     1, %o0
F00C2960: d0342022                 sth     %o0, [%l0+0x22]
F00C2964: 113c030a                 sethi   %hi(sub_F00C2994), %o0
F00C2968: 133c04fd                 sethi   %hi(_msjittertimeout), %o1
F00C296C: d4026388                 ld      [%o1+%lo(_msjittertimeout)], %o2
F00C2970: 90122194                 bset    %lo(sub_F00C2994), %o0! int
F00C2974: 7ffd1dad                 call    _timeout
F00C2978: 92100010                 mov     %l0, %o1
F00C297C: 30800004                 ba,a    locret_F00C298C
F00C2980: 90100010                 mov     %l0, %o0
F00C2984: 40000004                 call    sub_F00C2994
F00C2988: d22a201e                 stb     %o1, [%o0+0x1E]
F00C298C: 81c7e008                 ret
F00C2990: 81e80000                 restore
