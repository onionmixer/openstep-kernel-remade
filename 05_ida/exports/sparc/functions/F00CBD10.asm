F00CBD10: 9de3bf90                 save    %sp, -0x70, %sp
F00CBD14: d006212c                 ld      [%i0+0x12C], %o0! id
F00CBD18: 133c0506                 sethi   %hi(paOper_0), %o1
F00CBD1C: d202603c                 ld      [%o1+%lo(paOper_0)], %o1! SEL
F00CBD20: 400096d4                 call    _objc_msgSend
F00CBD24: a0102000                 mov     0, %l0
F00CBD28: 92023fff                 add     %o0, -1, %o1
F00CBD2C: 80a26007                 cmp     %o1, 7! switch 8 cases
F00CBD30: 1880005d                 bgu     def_F00CBD44! jumptable F00CBD44 default case, case 2
F00CBD34: 113c032f                 sethi   %hi(jpt_F00CBD44), %o0
F00CBD38: 9012214c                 bset    %lo(jpt_F00CBD44), %o0
F00CBD3C: 932a6002                 sll     %o1, 2, %o1
F00CBD40: d0024008                 ld      [%o1+%o0], %o0
F00CBD44: 81c20000                 jmp     %o0! switch jump
F00CBD48: 01000000                 nop
F00CBD6C: d04e2128                 ldsb    [%i0+0x128], %o0! jumptable F00CBD44 case 0
F00CBD70: 80a22000                 cmp     %o0, 0
F00CBD74: 32800048                 bne,a   loc_F00CBE94
F00CBD78: d006212c                 ld      [%i0+0x12C], %o0
F00CBD7C: 90100018                 mov     %i0, %o0! id
F00CBD80: 133c0506                 sethi   %hi(paResetandenable), %o1
F00CBD84: d2026038                 ld      [%o1+%lo(paResetandenable)], %o1! SEL
F00CBD88: 400096ba                 call    _objc_msgSend
F00CBD8C: 94102001                 mov     1, %o2
F00CBD90: 912a2018                 sll     %o0, 24, %o0
F00CBD94: 80a22000                 cmp     %o0, 0
F00CBD98: 2280003e                 be,a    loc_F00CBE90
F00CBD9C: a0102005                 mov     5, %l0
F00CBDA0: 1080003d                 ba      loc_F00CBE94
F00CBDA4: d006212c                 ld      [%i0+0x12C], %o0
F00CBDA8: 90100018                 mov     %i0, %o0! jumptable F00CBD44 case 1
F00CBDAC: 133c0506                 sethi   %hi(paResetandenable), %o1
F00CBDB0: d2026038                 ld      [%o1+%lo(paResetandenable)], %o1! SEL
F00CBDB4: 400096af                 call    _objc_msgSend
F00CBDB8: 94102000                 mov     0, %o2
F00CBDBC: 10800036                 ba      loc_F00CBE94
F00CBDC0: d006212c                 ld      [%i0+0x12C], %o0
F00CBDC4: d006212c                 ld      [%i0+0x12C], %o0! jumptable F00CBD44 case 3
F00CBDC8: 133c0506                 sethi   %hi(paDone), %o1
F00CBDCC: d2026034                 ld      [%o1+%lo(paDone)], %o1! SEL
F00CBDD0: 400096a8                 call    _objc_msgSend
F00CBDD4: 94100010                 mov     %l0, %o2
F00CBDD8: 7ffff911                 call    _IOExitThread
F00CBDDC: 9e03e0c4                 inc     0xC4, %o7
F00CBDE0: 113c0506                 sethi   %hi(paEnablepromiscu), %o0! jumptable F00CBD44 case 4
F00CBDE4: d2022030                 ld      [%o0+%lo(paEnablepromiscu)], %o1! SEL
F00CBDE8: 400096a2                 call    _objc_msgSend
F00CBDEC: 90100018                 mov     %i0, %o0
F00CBDF0: 912a2018                 sll     %o0, 24, %o0
F00CBDF4: 80a22000                 cmp     %o0, 0
F00CBDF8: 02800004                 be      loc_F00CBE08
F00CBDFC: 90102001                 mov     1, %o0
F00CBE00: 10800024                 ba      loc_F00CBE90
F00CBE04: d02e2129                 stb     %o0, [%i0+0x129]
F00CBE08: c02e2129                 clrb    [%i0+0x129]
F00CBE0C: 10800021                 ba      loc_F00CBE90
F00CBE10: a0102001                 mov     1, %l0
F00CBE14: 113c0506                 sethi   %hi(paDisablepromisc), %o0! jumptable F00CBD44 case 5
F00CBE18: d202202c                 ld      [%o0+%lo(paDisablepromisc)], %o1! SEL
F00CBE1C: 40009695                 call    _objc_msgSend
F00CBE20: 90100018                 mov     %i0, %o0
F00CBE24: 1080001b                 ba      loc_F00CBE90
F00CBE28: c02e2129                 clrb    [%i0+0x129]
F00CBE2C: 90100018                 mov     %i0, %o0! jumptable F00CBD44 case 6
F00CBE30: 133c0506                 sethi   %hi(paAddmulticastad), %o1
F00CBE34: d2026028                 ld      [%o1+%lo(paAddmulticastad)], %o1! SEL
F00CBE38: 4000968e                 call    _objc_msgSend
F00CBE3C: 9406213c                 add     %i0, 0x13C, %o2
F00CBE40: 113c0506                 sethi   %hi(paEnablemulticas_0), %o0! id
F00CBE44: d2022024                 ld      [%o0+%lo(paEnablemulticas_0)], %o1! SEL
F00CBE48: 4000968a                 call    _objc_msgSend
F00CBE4C: 90100018                 mov     %i0, %o0
F00CBE50: 10800011                 ba      loc_F00CBE94
F00CBE54: d006212c                 ld      [%i0+0x12C], %o0
F00CBE58: 90100018                 mov     %i0, %o0! jumptable F00CBD44 case 7
F00CBE5C: 133c0506                 sethi   %hi(paRemovemulticas), %o1
F00CBE60: d2026020                 ld      [%o1+%lo(paRemovemulticas)], %o1! SEL
F00CBE64: 40009683                 call    _objc_msgSend
F00CBE68: 9406213c                 add     %i0, 0x13C, %o2
F00CBE6C: d2062144                 ld      [%i0+0x144], %o1
F00CBE70: 90062144                 add     %i0, 0x144, %o0
F00CBE74: 80a20009                 cmp     %o0, %o1
F00CBE78: 32800007                 bne,a   loc_F00CBE94
F00CBE7C: d006212c                 ld      [%i0+0x12C], %o0
F00CBE80: 113c0506                 sethi   %hi(paDisablemultica_0), %o0! id
F00CBE84: d202201c                 ld      [%o0+%lo(paDisablemultica_0)], %o1! SEL
F00CBE88: 4000967a                 call    _objc_msgSend
F00CBE8C: 90100018                 mov     %i0, %o0
F00CBE90: d006212c                 ld      [%i0+0x12C], %o0! id
F00CBE94: 133c0506                 sethi   %hi(paDone), %o1
F00CBE98: d2026034                 ld      [%o1+%lo(paDone)], %o1! SEL
F00CBE9C: 40009675                 call    _objc_msgSend
F00CBEA0: 94100010                 mov     %l0, %o2
F00CBEA4: 81c7e008                 ret! jumptable F00CBD44 default case, case 2
F00CBEA8: 81e80000                 restore
