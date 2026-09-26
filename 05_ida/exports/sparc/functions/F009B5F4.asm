F009B5F4: 9de3bf98                 save    %sp, -0x68, %sp
F009B5F8: 113c045e90122108         set     aMmuSfsrX_1, %o0! "MMU sfsr=%x:"
F009B600: 7ffde416                 call    _printf
F009B604: 92100018                 mov     %i0, %o1
F009B608: 920e201c                 and     %i0, 0x1C, %o1
F009B60C: 80a2601c                 cmp     %o1, 0x1C! switch 29 cases
F009B610: 1880003c                 bgu     def_F009B624! jumptable F009B624 default case, cases 1-3,5-7,9-11,13-15,17-19,21-23,25-27
F009B614: 113c026d                 sethi   %hi(jpt_F009B624), %o0
F009B618: 9012222c                 bset    %lo(jpt_F009B624), %o0
F009B61C: 932a6002                 sll     %o1, 2, %o1
F009B620: d0024008                 ld      [%o1+%o0], %o0
F009B624: 81c20000                 jmp     %o0! switch jump
F009B628: 01000000                 nop
F009B6A0: 113c045e                 sethi   %hi(aNoError_1), %o0! jumptable F009B624 case 0
F009B6A4: 10800019                 ba      loc_F009B708
F009B6A8: 90122118                 bset    %lo(aNoError_1), %o0! " No Error"
F009B6AC: 113c045e                 sethi   %hi(aInvalidAddress_1), %o0! jumptable F009B624 case 4
F009B6B0: 10800016                 ba      loc_F009B708
F009B6B4: 90122128                 bset    %lo(aInvalidAddress_1), %o0! " Invalid Address"
F009B6B8: 113c045e                 sethi   %hi(aProtectionErro_1), %o0! jumptable F009B624 case 8
F009B6BC: 10800013                 ba      loc_F009B708
F009B6C0: 90122140                 bset    %lo(aProtectionErro_1), %o0! " Protection Error"
F009B6C4: 113c045e                 sethi   %hi(aPrivilegeViola_1), %o0! jumptable F009B624 case 12
F009B6C8: 10800010                 ba      loc_F009B708
F009B6CC: 90122158                 bset    %lo(aPrivilegeViola_1), %o0! " Privilege Violation"
F009B6D0: 113c045e                 sethi   %hi(aTranslationErr_1), %o0! jumptable F009B624 case 16
F009B6D4: 1080000d                 ba      loc_F009B708
F009B6D8: 90122170                 bset    %lo(aTranslationErr_1), %o0! " Translation Error"
F009B6DC: 113c045e                 sethi   %hi(aBusAccessError_1), %o0! jumptable F009B624 case 20
F009B6E0: 1080000a                 ba      loc_F009B708
F009B6E4: 90122188                 bset    %lo(aBusAccessError_1), %o0! " Bus Access Error"
F009B6E8: 113c045e                 sethi   %hi(aInternalError_1), %o0! jumptable F009B624 case 24
F009B6EC: 10800007                 ba      loc_F009B708
F009B6F0: 901221a0                 bset    %lo(aInternalError_1), %o0! " Internal Error"
F009B6F4: 113c045e                 sethi   %hi(aReservedError_1), %o0! jumptable F009B624 case 28
F009B6F8: 10800004                 ba      loc_F009B708
F009B6FC: 901221b0                 bset    %lo(aReservedError_1), %o0! " Reserved Error"
F009B700: 113c045e901221c0         set     aUnknownError_1, %o0! jumptable F009B624 default case, cases 1-3,5-7,9-11,13-15,17-19,21-23,25-27
F009B708: 7ffde3d4                 call    _printf
F009B70C: 01000000                 nop
F009B710: 80a62000                 cmp     %i0, 0
F009B714: 02800046                 be      loc_F009B82C
F009B718: 808e2020                 btst    0x20, %i0 ! ' '
F009B71C: 113c045e                 sethi   %hi(aOnSSSAtLevelD_1), %o0! " on %s %s %s at level %d"
F009B720: 02800005                 be      loc_F009B734
F009B724: 981221d0                 or      %o0, %lo(aOnSSSAtLevelD_1), %o4! " on %s %s %s at level %d"
F009B728: 113c045e                 sethi   %hi(aSupv_2), %o0! "supv"
F009B72C: 10800004                 ba      loc_F009B73C
F009B730: 921221f0                 or      %o0, %lo(aSupv_2), %o1! "supv"
F009B734: 113c045e921221f8         set     aUser_3, %o1! "user"
F009B73C: 808e2040                 btst    0x40, %i0 ! '@'
F009B740: 02800004                 be      loc_F009B750
F009B744: 113c045e                 sethi   %hi(aInstr_1), %o0! "instr"
F009B748: 10800004                 ba      loc_F009B758
F009B74C: 94122200                 or      %o0, %lo(aInstr_1), %o2! "instr"
F009B750: 113c045e94122208         set     aData_1, %o2! "data"
F009B758: 808e2080                 btst    0x80, %i0
F009B75C: 02800004                 be      loc_F009B76C
F009B760: 113c045e                 sethi   %hi(aStore_1), %o0! "store"
F009B764: 10800004                 ba      loc_F009B774
F009B768: 96122210                 or      %o0, %lo(aStore_1), %o3! "store"
F009B76C: 113c045e96122218         set     aFetch_1, %o3! "fetch"
F009B774: 9010000c                 mov     %o4, %o0! char *
F009B778: 980e2300                 and     %i0, 0x300, %o4
F009B77C: 7ffde3b7                 call    _printf
F009B780: 99332008                 srl     %o4, 8, %o4
F009B784: 808e2400                 btst    0x400, %i0
F009B788: 02800006                 be      loc_F009B7A0
F009B78C: 808e2800                 btst    0x800, %i0
F009B790: 113c045e                 sethi   %hi(aMBusBusError_1), %o0! "\n\tM-Bus Bus Error"
F009B794: 7ffde3b1                 call    _printf
F009B798: 90122220                 bset    %lo(aMBusBusError_1), %o0! "\n\tM-Bus Bus Error"
F009B79C: 808e2800                 btst    0x800, %i0
F009B7A0: 02800004                 be      loc_F009B7B0
F009B7A4: 113c045e                 sethi   %hi(aMBusTimeoutErr_1), %o0! "\n\tM-Bus Timeout Error"
F009B7A8: 7ffde3ac                 call    _printf
F009B7AC: 90122238                 bset    %lo(aMBusTimeoutErr_1), %o0! "\n\tM-Bus Timeout Error"
F009B7B0: 11000004                 sethi   0x1000, %o0
F009B7B4: 808e0008                 btst    %o0, %i0
F009B7B8: 02800004                 be      loc_F009B7C8
F009B7BC: 113c045e                 sethi   %hi(aMBusUncorrecta_1), %o0! "\n\tM-Bus Uncorrectable Error"
F009B7C0: 7ffde3a6                 call    _printf
F009B7C4: 90122250                 bset    %lo(aMBusUncorrecta_1), %o0! "\n\tM-Bus Uncorrectable Error"
F009B7C8: 11000008                 sethi   0x2000, %o0
F009B7CC: 808e0008                 btst    %o0, %i0
F009B7D0: 02800004                 be      loc_F009B7E0
F009B7D4: 113c045e                 sethi   %hi(aMBusUndefinedE), %o0! "\n\tM-Bus Undefined Error"
F009B7D8: 7ffde3a0                 call    _printf
F009B7DC: 90122270                 bset    %lo(aMBusUndefinedE), %o0! "\n\tM-Bus Undefined Error"
F009B7E0: 11000010                 sethi   0x4000, %o0
F009B7E4: 808e0008                 btst    %o0, %i0
F009B7E8: 02800004                 be      loc_F009B7F8
F009B7EC: 113c045e                 sethi   %hi(aParityError_0), %o0! "\n\tParity Error"
F009B7F0: 7ffde39a                 call    _printf
F009B7F4: 90122288                 bset    %lo(aParityError_0), %o0! "\n\tParity Error"
F009B7F8: 11000040                 sethi   0x10000, %o0
F009B7FC: 808e0008                 btst    %o0, %i0
F009B800: 02800004                 be      loc_F009B810
F009B804: 113c045e                 sethi   %hi(aControlSpaceSc), %o0! "\n\tControl Space Sccess Error"
F009B808: 7ffde394                 call    _printf
F009B80C: 90122298                 bset    %lo(aControlSpaceSc), %o0! "\n\tControl Space Sccess Error"
F009B810: 11000020                 sethi   0x8000, %o0
F009B814: 808e0008                 btst    %o0, %i0
F009B818: 22800006                 be,a    loc_F009B830
F009B81C: 113c045e                 sethi   -0xFEE8800, %o0
F009B820: 113c045e                 sethi   %hi(aStoreBufferErr_0), %o0! "\n\tStore Buffer Error"
F009B824: 7ffde38d                 call    _printf
F009B828: 901222b8                 bset    %lo(aStoreBufferErr_0), %o0! "\n\tStore Buffer Error"
F009B82C: 113c045e                 sethi   -0xFEE8800, %o0! char *
F009B830: 7ffde38a                 call    _printf
F009B834: 901222d0                 bset    0x2D0, %o0
F009B838: 81c7e008                 ret
F009B83C: 81e80000                 restore
