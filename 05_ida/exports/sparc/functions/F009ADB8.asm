F009ADB8: 9de3bf98                 save    %sp, -0x68, %sp
F009ADBC: 113c045d90122180         set     aMmuSfsrX_0, %o0! "MMU sfsr=%x:"
F009ADC4: 7ffde625                 call    _printf
F009ADC8: 92100018                 mov     %i0, %o1
F009ADCC: 920e201c                 and     %i0, 0x1C, %o1
F009ADD0: 80a2601c                 cmp     %o1, 0x1C! switch 29 cases
F009ADD4: 1880003c                 bgu     def_F009ADE8! jumptable F009ADE8 default case, cases 1-3,5-7,9-11,13-15,17-19,21-23,25-27
F009ADD8: 113c026b                 sethi   %hi(jpt_F009ADE8), %o0
F009ADDC: 901221f0                 bset    %lo(jpt_F009ADE8), %o0
F009ADE0: 932a6002                 sll     %o1, 2, %o1
F009ADE4: d0024008                 ld      [%o1+%o0], %o0
F009ADE8: 81c20000                 jmp     %o0! switch jump
F009ADEC: 01000000                 nop
F009AE64: 113c045d                 sethi   %hi(aNoError_0), %o0! jumptable F009ADE8 case 0
F009AE68: 10800019                 ba      loc_F009AECC
F009AE6C: 90122190                 bset    %lo(aNoError_0), %o0! " No Error"
F009AE70: 113c045d                 sethi   %hi(aInvalidAddress_0), %o0! jumptable F009ADE8 case 4
F009AE74: 10800016                 ba      loc_F009AECC
F009AE78: 901221a0                 bset    %lo(aInvalidAddress_0), %o0! " Invalid Address"
F009AE7C: 113c045d                 sethi   %hi(aProtectionErro_0), %o0! jumptable F009ADE8 case 8
F009AE80: 10800013                 ba      loc_F009AECC
F009AE84: 901221b8                 bset    %lo(aProtectionErro_0), %o0! " Protection Error"
F009AE88: 113c045d                 sethi   %hi(aPrivilegeViola_0), %o0! jumptable F009ADE8 case 12
F009AE8C: 10800010                 ba      loc_F009AECC
F009AE90: 901221d0                 bset    %lo(aPrivilegeViola_0), %o0! " Privilege Violation"
F009AE94: 113c045d                 sethi   %hi(aTranslationErr_0), %o0! jumptable F009ADE8 case 16
F009AE98: 1080000d                 ba      loc_F009AECC
F009AE9C: 901221e8                 bset    %lo(aTranslationErr_0), %o0! " Translation Error"
F009AEA0: 113c045d                 sethi   %hi(aBusAccessError_0), %o0! jumptable F009ADE8 case 20
F009AEA4: 1080000a                 ba      loc_F009AECC
F009AEA8: 90122200                 bset    %lo(aBusAccessError_0), %o0! " Bus Access Error"
F009AEAC: 113c045d                 sethi   %hi(aInternalError_0), %o0! jumptable F009ADE8 case 24
F009AEB0: 10800007                 ba      loc_F009AECC
F009AEB4: 90122218                 bset    %lo(aInternalError_0), %o0! " Internal Error"
F009AEB8: 113c045d                 sethi   %hi(aReservedError_0), %o0! jumptable F009ADE8 case 28
F009AEBC: 10800004                 ba      loc_F009AECC
F009AEC0: 90122228                 bset    %lo(aReservedError_0), %o0! " Reserved Error"
F009AEC4: 113c045d90122238         set     aUnknownError_0, %o0! jumptable F009ADE8 default case, cases 1-3,5-7,9-11,13-15,17-19,21-23,25-27
F009AECC: 7ffde5e3                 call    _printf
F009AED0: 01000000                 nop
F009AED4: 80a62000                 cmp     %i0, 0
F009AED8: 0280002e                 be      loc_F009AF90
F009AEDC: 808e2020                 btst    0x20, %i0 ! ' '
F009AEE0: 113c045d                 sethi   %hi(aOnSSSAtLevelD_0), %o0! " on %s %s %s at level %d"
F009AEE4: 02800005                 be      loc_F009AEF8
F009AEE8: 98122248                 or      %o0, %lo(aOnSSSAtLevelD_0), %o4! " on %s %s %s at level %d"
F009AEEC: 113c045d                 sethi   %hi(aSupv_0), %o0! "supv"
F009AEF0: 10800004                 ba      loc_F009AF00
F009AEF4: 92122268                 or      %o0, %lo(aSupv_0), %o1! "supv"
F009AEF8: 113c045d92122270         set     aUser_1, %o1! "user"
F009AF00: 808e2040                 btst    0x40, %i0 ! '@'
F009AF04: 02800004                 be      loc_F009AF14
F009AF08: 113c045d                 sethi   %hi(aInstr_0), %o0! "instr"
F009AF0C: 10800004                 ba      loc_F009AF1C
F009AF10: 94122278                 or      %o0, %lo(aInstr_0), %o2! "instr"
F009AF14: 113c045d94122280         set     aData_0, %o2! "data"
F009AF1C: 808e2080                 btst    0x80, %i0
F009AF20: 02800004                 be      loc_F009AF30
F009AF24: 113c045d                 sethi   %hi(aStore_0), %o0! "store"
F009AF28: 10800004                 ba      loc_F009AF38
F009AF2C: 96122288                 or      %o0, %lo(aStore_0), %o3! "store"
F009AF30: 113c045d96122290         set     aFetch_0, %o3! "fetch"
F009AF38: 9010000c                 mov     %o4, %o0! char *
F009AF3C: 980e2300                 and     %i0, 0x300, %o4
F009AF40: 7ffde5c6                 call    _printf
F009AF44: 99332008                 srl     %o4, 8, %o4
F009AF48: 808e2400                 btst    0x400, %i0
F009AF4C: 02800006                 be      loc_F009AF64
F009AF50: 808e2800                 btst    0x800, %i0
F009AF54: 113c045d                 sethi   %hi(aBusError), %o0! "\n\tBus Error"
F009AF58: 7ffde5c0                 call    _printf
F009AF5C: 90122298                 bset    %lo(aBusError), %o0! "\n\tBus Error"
F009AF60: 808e2800                 btst    0x800, %i0
F009AF64: 02800004                 be      loc_F009AF74
F009AF68: 113c045d                 sethi   %hi(aTimeoutError), %o0! "\n\tTimeout Error"
F009AF6C: 7ffde5bb                 call    _printf
F009AF70: 901222a8                 bset    %lo(aTimeoutError), %o0! "\n\tTimeout Error"
F009AF74: 11000018                 sethi   0x6000, %o0
F009AF78: 808e0008                 btst    %o0, %i0
F009AF7C: 22800006                 be,a    loc_F009AF94
F009AF80: 113c045d                 sethi   -0xFEE8C00, %o0
F009AF84: 113c045d                 sethi   %hi(aParityError), %o0! "\n\tParity Error"
F009AF88: 7ffde5b4                 call    _printf
F009AF8C: 901222b8                 bset    %lo(aParityError), %o0! "\n\tParity Error"
F009AF90: 113c045d                 sethi   -0xFEE8C00, %o0! char *
F009AF94: 7ffde5b1                 call    _printf
F009AF98: 901222c8                 bset    0x2C8, %o0
F009AF9C: 81c7e008                 ret
F009AFA0: 81e80000                 restore
