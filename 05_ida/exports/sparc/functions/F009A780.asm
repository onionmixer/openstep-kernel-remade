F009A780: 9de3bf98                 save    %sp, -0x68, %sp
F009A784: 113c045c901223e0         set     aMmuSfsrX, %o0! "MMU sfsr=%x:"
F009A78C: 7ffde7b3                 call    _printf
F009A790: 92100018                 mov     %i0, %o1
F009A794: 920e201c                 and     %i0, 0x1C, %o1
F009A798: 80a2601c                 cmp     %o1, 0x1C! switch 29 cases
F009A79C: 1880003c                 bgu     def_F009A7B0! jumptable F009A7B0 default case, cases 1-3,5-7,9-11,13-15,17-19,21-23,25-27
F009A7A0: 113c0269                 sethi   %hi(jpt_F009A7B0), %o0
F009A7A4: 901223b8                 bset    %lo(jpt_F009A7B0), %o0
F009A7A8: 932a6002                 sll     %o1, 2, %o1
F009A7AC: d0024008                 ld      [%o1+%o0], %o0
F009A7B0: 81c20000                 jmp     %o0! switch jump
F009A7B4: 01000000                 nop
F009A82C: 113c045c                 sethi   %hi(aNoError), %o0! jumptable F009A7B0 case 0
F009A830: 10800019                 ba      loc_F009A894
F009A834: 901223f0                 bset    %lo(aNoError), %o0! " No Error"
F009A838: 113c045d                 sethi   %hi(aInvalidAddress), %o0! jumptable F009A7B0 case 4
F009A83C: 10800016                 ba      loc_F009A894
F009A840: 90122000                 bset    %lo(aInvalidAddress), %o0! " Invalid Address"
F009A844: 113c045d                 sethi   %hi(aProtectionErro), %o0! jumptable F009A7B0 case 8
F009A848: 10800013                 ba      loc_F009A894
F009A84C: 90122018                 bset    %lo(aProtectionErro), %o0! " Protection Error"
F009A850: 113c045d                 sethi   %hi(aPrivilegeViola), %o0! jumptable F009A7B0 case 12
F009A854: 10800010                 ba      loc_F009A894
F009A858: 90122030                 bset    %lo(aPrivilegeViola), %o0! " Privilege Violation"
F009A85C: 113c045d                 sethi   %hi(aTranslationErr), %o0! jumptable F009A7B0 case 16
F009A860: 1080000d                 ba      loc_F009A894
F009A864: 90122048                 bset    %lo(aTranslationErr), %o0! " Translation Error"
F009A868: 113c045d                 sethi   %hi(aBusAccessError), %o0! jumptable F009A7B0 case 20
F009A86C: 1080000a                 ba      loc_F009A894
F009A870: 90122060                 bset    %lo(aBusAccessError), %o0! " Bus Access Error"
F009A874: 113c045d                 sethi   %hi(aInternalError), %o0! jumptable F009A7B0 case 24
F009A878: 10800007                 ba      loc_F009A894
F009A87C: 90122078                 bset    %lo(aInternalError), %o0! " Internal Error"
F009A880: 113c045d                 sethi   %hi(aReservedError), %o0! jumptable F009A7B0 case 28
F009A884: 10800004                 ba      loc_F009A894
F009A888: 90122088                 bset    %lo(aReservedError), %o0! " Reserved Error"
F009A88C: 113c045d90122098         set     aUnknownError, %o0! jumptable F009A7B0 default case, cases 1-3,5-7,9-11,13-15,17-19,21-23,25-27
F009A894: 7ffde771                 call    _printf
F009A898: 01000000                 nop
F009A89C: 80a62000                 cmp     %i0, 0
F009A8A0: 0280002e                 be      loc_F009A958
F009A8A4: 808e2020                 btst    0x20, %i0 ! ' '
F009A8A8: 113c045d                 sethi   %hi(aOnSSSAtLevelD), %o0! " on %s %s %s at level %d"
F009A8AC: 02800005                 be      loc_F009A8C0
F009A8B0: 981220a8                 or      %o0, %lo(aOnSSSAtLevelD), %o4! " on %s %s %s at level %d"
F009A8B4: 113c045d                 sethi   %hi(aSupv), %o0! "supv"
F009A8B8: 10800004                 ba      loc_F009A8C8
F009A8BC: 921220c8                 or      %o0, %lo(aSupv), %o1! "supv"
F009A8C0: 113c045d921220d0         set     aUser_0, %o1! "user"
F009A8C8: 808e2040                 btst    0x40, %i0 ! '@'
F009A8CC: 02800004                 be      loc_F009A8DC
F009A8D0: 113c045d                 sethi   %hi(aInstr), %o0! "instr"
F009A8D4: 10800004                 ba      loc_F009A8E4
F009A8D8: 941220d8                 or      %o0, %lo(aInstr), %o2! "instr"
F009A8DC: 113c045d941220e0         set     aData, %o2! "data"
F009A8E4: 808e2080                 btst    0x80, %i0
F009A8E8: 02800004                 be      loc_F009A8F8
F009A8EC: 113c045d                 sethi   %hi(aStore), %o0! "store"
F009A8F0: 10800004                 ba      loc_F009A900
F009A8F4: 961220e8                 or      %o0, %lo(aStore), %o3! "store"
F009A8F8: 113c045d961220f0         set     aFetch, %o3! "fetch"
F009A900: 9010000c                 mov     %o4, %o0! char *
F009A904: 980e2300                 and     %i0, 0x300, %o4
F009A908: 7ffde754                 call    _printf
F009A90C: 99332008                 srl     %o4, 8, %o4
F009A910: 808e2400                 btst    0x400, %i0
F009A914: 02800006                 be      loc_F009A92C
F009A918: 808e2800                 btst    0x800, %i0
F009A91C: 113c045d                 sethi   %hi(aMBusBusError_0), %o0! "\n\tM-Bus Bus Error"
F009A920: 7ffde74e                 call    _printf
F009A924: 901220f8                 bset    %lo(aMBusBusError_0), %o0! "\n\tM-Bus Bus Error"
F009A928: 808e2800                 btst    0x800, %i0
F009A92C: 02800004                 be      loc_F009A93C
F009A930: 113c045d                 sethi   %hi(aMBusTimeoutErr_0), %o0! "\n\tM-Bus Timeout Error"
F009A934: 7ffde749                 call    _printf
F009A938: 90122110                 bset    %lo(aMBusTimeoutErr_0), %o0! "\n\tM-Bus Timeout Error"
F009A93C: 11000004                 sethi   0x1000, %o0
F009A940: 808e0008                 btst    %o0, %i0
F009A944: 22800006                 be,a    loc_F009A95C
F009A948: 113c045d                 sethi   -0xFEE8C00, %o0
F009A94C: 113c045d                 sethi   %hi(aMBusUncorrecta_0), %o0! "\n\tM-Bus Uncorrectable Error"
F009A950: 7ffde742                 call    _printf
F009A954: 90122128                 bset    %lo(aMBusUncorrecta_0), %o0! "\n\tM-Bus Uncorrectable Error"
F009A958: 113c045d                 sethi   -0xFEE8C00, %o0! char *
F009A95C: 7ffde73f                 call    _printf
F009A960: 90122148                 bset    0x148, %o0
F009A964: 81c7e008                 ret
F009A968: 81e80000                 restore
