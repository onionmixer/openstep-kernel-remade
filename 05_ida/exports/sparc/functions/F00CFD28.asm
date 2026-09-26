F00CFD28: 9de3bf18                 save    %sp, -0xE8, %sp
F00CFD2C: c02fbf78                 clrb    [%fp+var_88]
F00CFD30: d2068000                 ld      [%i2], %o1
F00CFD34: 80a26004                 cmp     %o1, 4! switch 5 cases
F00CFD38: 18800043                 bgu     def_F00CFD4C! jumptable F00CFD4C default case
F00CFD3C: 932a6002                 sll     %o1, 2, %o1
F00CFD40: 113c033f90122154         set     jpt_F00CFD4C, %o0
F00CFD48: d0024008                 ld      [%o1+%o0], %o0
F00CFD4C: 81c20000                 jmp     %o0! switch jump
F00CFD50: 01000000                 nop
F00CFD68: 113c03ed                 sethi   %hi(aRead), %o0! jumptable F00CFD4C case 0
F00CFD6C: d20221e0                 ld      [%o0+%lo(aRead)], %o1! "Read"
F00CFD70: 901221e0                 bset    %lo(aRead), %o0! "Read"
F00CFD74: d00a2004                 ldub    [%o0+4], %o0
F00CFD78: d227bfc8                 st      %o1, [%fp+var_38]
F00CFD7C: 10800008                 ba      loc_F00CFD9C
F00CFD80: d02fbfcc                 stb     %o0, [%fp+var_34]
F00CFD84: 113c03ed                 sethi   %hi(aWrite), %o0! jumptable F00CFD4C case 1
F00CFD88: d20221e8                 ld      [%o0+%lo(aWrite)], %o1! "Write"
F00CFD8C: 901221e8                 bset    %lo(aWrite), %o0! "Write"
F00CFD90: d0122004                 lduh    [%o0+4], %o0
F00CFD94: d227bfc8                 st      %o1, [%fp+var_38]
F00CFD98: d037bfcc                 sth     %o0, [%fp+var_34]
F00CFD9C: 80a6e000                 cmp     %i3, 0
F00CFDA0: 02800010                 be      loc_F00CFDE0
F00CFDA4: 9007bf78                 add     %fp, var_88, %o0
F00CFDA8: d006c000                 ld      [%i3], %o0
F00CFDAC: 80a22000                 cmp     %o0, 0
F00CFDB0: 1680000c                 bge     loc_F00CFDE0
F00CFDB4: 9007bf78                 add     %fp, var_88, %o0! char *
F00CFDB8: 133c03ed                 sethi   %hi(aBlockD), %o1! "block:%d"
F00CFDBC: d60ee003                 ldub    [%i3+3], %o3
F00CFDC0: 921261f0                 bset    %lo(aBlockD), %o1! "block:%d"
F00CFDC4: d406e004                 ld      [%i3+4], %o2
F00CFDC8: 972ae018                 sll     %o3, 24, %o3
F00CFDCC: 9532a008                 srl     %o2, 8, %o2
F00CFDD0: 7ffd1266                 call    _sprintf
F00CFDD4: 9412c00a                 bset    %o3, %o2
F00CFDD8: 1080001f                 ba      loc_F00CFE54
F00CFDDC: 113c03ed                 sethi   -0xFF04C00, %o0! char *
F00CFDE0: d406a004                 ld      [%i2+4], %o2
F00CFDE4: 133c03ed                 sethi   %hi(aBlockDBlockcou), %o1! "block:%d blockCount:%d"
F00CFDE8: d606a008                 ld      [%i2+8], %o3
F00CFDEC: 7ffd125f                 call    _sprintf
F00CFDF0: 92126200                 bset    %lo(aBlockDBlockcou), %o1! "block:%d blockCount:%d"
F00CFDF4: 10800018                 ba      loc_F00CFE54
F00CFDF8: 113c03ed                 sethi   -0xFF04C00, %o0
F00CFDFC: 133c04bb                 sethi   %hi(_IOSCSIOpcodeStrings), %o1! jumptable F00CFD4C cases 2,3
F00CFE00: d006a014                 ld      [%i2+0x14], %o0
F00CFE04: 92126230                 bset    %lo(_IOSCSIOpcodeStrings), %o1
F00CFE08: d00a2004                 ldub    [%o0+4], %o0! __dst
F00CFE0C: 7fffd8cb                 call    _IOFindNameForValue
F00CFE10: a007bfc8                 add     %fp, var_38, %l0
F00CFE14: 92100008                 mov     %o0, %o1! __src
F00CFE18: 7ffcddc4                 call    _strcpy
F00CFE1C: 90100010                 mov     %l0, %o0
F00CFE20: 1080000d                 ba      loc_F00CFE54
F00CFE24: 113c03ed                 sethi   -0xFF04C00, %o0
F00CFE28: 113c03ed                 sethi   %hi(aEject_0), %o0! jumptable F00CFD4C case 4
F00CFE2C: d2022218                 ld      [%o0+%lo(aEject_0)], %o1! "Eject"
F00CFE30: 90122218                 bset    %lo(aEject_0), %o0! "Eject"
F00CFE34: d0122004                 lduh    [%o0+4], %o0
F00CFE38: d227bfc8                 st      %o1, [%fp+var_38]
F00CFE3C: 10800005                 ba      loc_F00CFE50
F00CFE40: d037bfcc                 sth     %o0, [%fp+var_34]
F00CFE44: 113c03ed                 sethi   %hi(aBogusOpInLogop), %o0! jumptable F00CFD4C default case
F00CFE48: 7ffd14ca                 call    _panic
F00CFE4C: 90122220                 bset    %lo(aBogusOpInLogop), %o0! "Bogus op in logOpInfo"
F00CFE50: 113c03ed                 sethi   -0xFF04C00, %o0
F00CFE54: 90122238                 bset    0x238, %o0
F00CFE58: d20e2188                 ldub    [%i0+0x188], %o1
F00CFE5C: 9607bfc8                 add     %fp, var_38, %o3
F00CFE60: d40e2189                 ldub    [%i0+0x189], %o2
F00CFE64: 7fffd8a4                 call    _IOLog
F00CFE68: 9807bf78                 add     %fp, var_88, %o4
F00CFE6C: 81c7e008                 ret
F00CFE70: 81e80000                 restore
