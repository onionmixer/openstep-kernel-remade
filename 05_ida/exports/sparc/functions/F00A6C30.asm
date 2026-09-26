F00A6C30: 9de3bf90                 save    %sp, -0x70, %sp
F00A6C34: 80a62000                 cmp     %i0, 0
F00A6C38: 02800006                 be      loc_F00A6C50
F00A6C3C: a207bff4                 add     %fp, var_C, %l1
F00A6C40: 80a62001                 cmp     %i0, 1
F00A6C44: 02800047                 be      loc_F00A6D60
F00A6C48: 113c046b                 sethi   -0xFEE5400, %o0
F00A6C4C: 30800050                 ba,a    locret_F00A6D8C
F00A6C50: 11000018                 sethi   0x6000, %o0
F00A6C54: 808e4008                 btst    %o0, %i1
F00A6C58: 0280002f                 be      loc_F00A6D14
F00A6C5C: 01000000                 nop
F00A6C60: 113c046b                 sethi   %hi(aSynchronousPar), %o0! "Synchronous parity error\n"
F00A6C64: 7ffdb67d                 call    _printf
F00A6C68: 901222c8                 bset    %lo(aSynchronousPar), %o0! "Synchronous parity error\n"
F00A6C6C: 91366002                 srl     %i1, 2, %o0
F00A6C70: 900a2007                 and     %o0, 7, %o0
F00A6C74: 80a22004                 cmp     %o0, 4
F00A6C78: 32800005                 bne,a   loc_F00A6C8C
F00A6C7C: 113c046b                 sethi   -0xFEE5400, %o0
F00A6C80: 113c046b                 sethi   %hi(aParityErrorDur), %o0! "parity error during table walk"
F00A6C84: 1080001e                 ba      loc_F00A6CFC
F00A6C88: 901222e8                 bset    %lo(aParityErrorDur), %o0! "parity error during table walk"
F00A6C8C: 7ffdb673                 call    _printf
F00A6C90: 90122308                 bset    0x308, %o0
F00A6C94: 40000040                 call    _p4m35_parerr_reset
F00A6C98: 9010001a                 mov     %i2, %o0
F00A6C9C: 90380008                 xnor    %g0, %o0, %o0
F00A6CA0: 80a00008                 cmp     %g0, %o0
F00A6CA4: 7fffba56                 call    _mmu_getctx
F00A6CA8: a0402000                 addc    %g0, 0, %l0
F00A6CAC: b0100008                 mov     %o0, %i0
F00A6CB0: 7fffba57                 call    _mmu_probe
F00A6CB4: 9010001a                 mov     %i2, %o0
F00A6CB8: 96100008                 mov     %o0, %o3
F00A6CBC: d627bff4                 st      %o3, [%fp+var_C]
F00A6CC0: 113c046b90122320         set     aCtx0xXVaddr0xX, %o0! " ctx=0x%x vaddr=0x%x pte=0x%x transient"...
F00A6CC8: 92100018                 mov     %i0, %o1
F00A6CCC: 9410001a                 mov     %i2, %o2
F00A6CD0: 7ffdb662                 call    _printf
F00A6CD4: 98100010                 mov     %l0, %o4
F00A6CD8: 9010001a                 mov     %i2, %o0
F00A6CDC: 92100011                 mov     %l1, %o1
F00A6CE0: 4000005c                 call    _p4m35_parerr_recover
F00A6CE4: 94100010                 mov     %l0, %o2
F00A6CE8: 80a23fff                 cmp     %o0, -1
F00A6CEC: 12800007                 bne     loc_F00A6D08
F00A6CF0: 113c046b                 sethi   -0xFEE5400, %o0
F00A6CF4: 113c046b90122350         set     aUnrecoverableP, %o0! "unrecoverable parity error"
F00A6CFC: 7ffdb91d                 call    _panic
F00A6D00: 01000000                 nop
F00A6D04: 113c046b                 sethi   -0xFEE5400, %o0! char *
F00A6D08: 7ffdb654                 call    _printf
F00A6D0C: 90122370                 bset    0x370, %o0
F00A6D10: 3080001f                 ba,a    locret_F00A6D8C
F00A6D14: 7fffba3a                 call    _mmu_getctx
F00A6D18: 01000000                 nop
F00A6D1C: b0100008                 mov     %o0, %i0
F00A6D20: 7fffba3b                 call    _mmu_probe
F00A6D24: 9010001a                 mov     %i2, %o0
F00A6D28: d027bff4                 st      %o0, [%fp+var_C]
F00A6D2C: 113c046b                 sethi   %hi(aNonParitySynch), %o0! "Non-parity Synchronous memory error\n"
F00A6D30: 7ffdb64a                 call    _printf
F00A6D34: 90122390                 bset    %lo(aNonParitySynch), %o0! "Non-parity Synchronous memory error\n"
F00A6D38: 113c046b901223b8         set     aCtx0xXVaddr0xX_0, %o0! " ctx=0x%x vaddr=0x%x pte=0x%x fsr=0x%x"...
F00A6D40: 92100018                 mov     %i0, %o1
F00A6D44: 9410001a                 mov     %i2, %o2
F00A6D48: d607bff4                 ld      [%fp+var_C], %o3
F00A6D4C: 7ffdb643                 call    _printf
F00A6D50: 98100019                 mov     %i1, %o4
F00A6D54: 113c046b                 sethi   %hi(aSyncMemoryErro), %o0! "sync memory error"
F00A6D58: 1080000b                 ba      loc_F00A6D84
F00A6D5C: 901223e0                 bset    %lo(aSyncMemoryErro), %o0! "sync memory error"
F00A6D60: 7ffdb63e                 call    _printf
F00A6D64: 901223f8                 bset    0x3F8, %o0
F00A6D68: 113c046c90122018         set     aAddr0xXReg0xX, %o0! "addr=0x%x reg=0x%x\n"
F00A6D70: 9210001a                 mov     %i2, %o1
F00A6D74: 7ffdb639                 call    _printf
F00A6D78: 94100019                 mov     %i1, %o2
F00A6D7C: 113c046c90122030         set     aAsyncMemoryErr, %o0! "async memory error"
F00A6D84: 7ffdb8fb                 call    _panic
F00A6D88: 01000000                 nop
F00A6D8C: 81c7e008                 ret
F00A6D90: 81e80000                 restore
