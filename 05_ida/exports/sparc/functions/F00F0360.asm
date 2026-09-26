F00F0360: 9de3bf98                 save    %sp, -0x68, %sp
F00F0364: 94102000                 mov     0, %o2
F00F0368: 98100018                 mov     %i0, %o4
F00F036C: d00e0000                 ldub    [%i0], %o0
F00F0370: 80a22000                 cmp     %o0, 0
F00F0374: 0280002f                 be      loc_F00F0430
F00F0378: 92100008                 mov     %o0, %o1
F00F037C: 912e6018                 sll     %i1, 24, %o0
F00F0380: 973a2018                 sra     %o0, 24, %o3
F00F0384: 912a6018                 sll     %o1, 24, %o0
F00F0388: 913a2018                 sra     %o0, 24, %o0
F00F038C: 80a22000                 cmp     %o0, 0
F00F0390: 02800007                 be      loc_F00F03AC
F00F0394: 80a2a000                 cmp     %o2, 0
F00F0398: 32800007                 bne,a   loc_F00F03B4
F00F039C: d04e0000                 ldsb    [%i0], %o0
F00F03A0: 80a2000b                 cmp     %o0, %o3
F00F03A4: 32800004                 bne,a   loc_F00F03B4
F00F03A8: d04e0000                 ldsb    [%i0], %o0
F00F03AC: 10800025                 ba      locret_F00F0440
F00F03B0: b026000c                 sub     %i0, %o4, %i0
F00F03B4: 80a2205b                 cmp     %o0, 0x5B ! '['
F00F03B8: 22800019                 be,a    loc_F00F041C
F00F03BC: 9402a001                 inc     %o2
F00F03C0: 14800009                 bg      loc_F00F03E4
F00F03C4: 80a2207b                 cmp     %o0, 0x7B ! '{'
F00F03C8: 80a22028                 cmp     %o0, 0x28 ! '('
F00F03CC: 02800013                 be      loc_F00F0418
F00F03D0: 80a22029                 cmp     %o0, 0x29 ! ')'
F00F03D4: 22800012                 be,a    loc_F00F041C
F00F03D8: 9402bfff                 inc     -1, %o2
F00F03DC: 10800011                 ba      loc_F00F0420
F00F03E0: b0062001                 inc     %i0
F00F03E4: 0280000d                 be      loc_F00F0418
F00F03E8: 80a2207b                 cmp     %o0, 0x7B ! '{'
F00F03EC: 14800007                 bg      loc_F00F0408
F00F03F0: 80a2207d                 cmp     %o0, 0x7D ! '}'
F00F03F4: 80a2205d                 cmp     %o0, 0x5D ! ']'
F00F03F8: 22800009                 be,a    loc_F00F041C
F00F03FC: 9402bfff                 inc     -1, %o2
F00F0400: 10800008                 ba      loc_F00F0420
F00F0404: b0062001                 inc     %i0
F00F0408: 32800006                 bne,a   loc_F00F0420
F00F040C: b0062001                 inc     %i0
F00F0410: 10800003                 ba      loc_F00F041C
F00F0414: 9402bfff                 inc     -1, %o2
F00F0418: 9402a001                 inc     %o2
F00F041C: b0062001                 inc     %i0
F00F0420: d04e0000                 ldsb    [%i0], %o0
F00F0424: 80a22000                 cmp     %o0, 0
F00F0428: 12bfffd7                 bne     loc_F00F0384
F00F042C: d20e0000                 ldub    [%i0], %o1
F00F0430: 113c03f4                 sethi   %hi(aObjectSubtypeu), %o0! "Object: SubTypeUntil: end of type encou"...
F00F0434: 40000145                 call    __NXLogError
F00F0438: 90122130                 bset    %lo(aObjectSubtypeu), %o0! "Object: SubTypeUntil: end of type encou"...
F00F043C: b0102000                 mov     0, %i0
F00F0440: 81c7e008                 ret
F00F0444: 81e80000                 restore
