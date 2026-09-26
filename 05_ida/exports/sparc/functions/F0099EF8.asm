F0099EF8: 9de3bf98                 save    %sp, -0x68, %sp
F0099EFC: 113c04c5                 sethi   %hi(dword_F0131498), %o0
F0099F00: d0022098                 ld      [%o0+%lo(dword_F0131498)], %o0
F0099F04: 80a22000                 cmp     %o0, 0
F0099F08: 02800019                 be      locret_F0099F6C
F0099F0C: 80a62005                 cmp     %i0, 5! switch 6 cases
F0099F10: 18800014                 bgu     def_F0099F24! jumptable F0099F24 default case, cases 2,3
F0099F14: 932e2002                 sll     %i0, 2, %o1
F0099F18: 113c02679012232c         set     jpt_F0099F24, %o0
F0099F20: d0024008                 ld      [%o1+%o0], %o0
F0099F24: 81c20000                 jmp     %o0! switch jump
F0099F28: 01000000                 nop
F0099F44: 90100019                 mov     %i1, %o0! jumptable F0099F24 cases 0,1,4
F0099F48: 7fff72cd                 call    _calloutDispatchUnique
F0099F4C: 9210001a                 mov     %i2, %o1
F0099F50: 30800007                 ba,a    locret_F0099F6C
F0099F54: 9fc64000                 call    %i1! jumptable F0099F24 case 5
F0099F58: 9010001a                 mov     %i2, %o0
F0099F5C: 30800004                 ba,a    locret_F0099F6C
F0099F60: 113c045c                 sethi   %hi(aCalloutDispatc), %o0! jumptable F0099F24 default case, cases 2,3
F0099F64: 7ffdec83                 call    _panic
F0099F68: 90122128                 bset    %lo(aCalloutDispatc), %o0! "callout_dispatch"
F0099F6C: 81c7e008                 ret
F0099F70: 81e80000                 restore
