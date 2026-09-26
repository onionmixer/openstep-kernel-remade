F00C1030: 9de3bf98                 save    %sp, -0x68, %sp
F00C1034: f027a044                 st      %i0, [%fp+arg_44]
F00C1038: 7fffffaf                 call    sub_F00C0EF4
F00C103C: 9007a044                 add     %fp, arg_44, %o0
F00C1040: d207a044                 ld      [%fp+arg_44], %o1
F00C1044: b0100008                 mov     %o0, %i0
F00C1048: 113c0304                 sethi   %hi(_kbdidletimeout), %o0
F00C104C: 7ffd2402                 call    _untimeout
F00C1050: 90122030                 bset    %lo(_kbdidletimeout), %o0
F00C1054: 80a62000                 cmp     %i0, 0
F00C1058: 02800008                 be      locret_F00C1078
F00C105C: 01000000                 nop
F00C1060: d00e2001                 ldub    [%i0+1], %o0
F00C1064: 80a22001                 cmp     %o0, 1
F00C1068: 12800004                 bne     locret_F00C1078
F00C106C: d207a044                 ld      [%fp+arg_44], %o1
F00C1070: 40000004                 call    sub_F00C1080
F00C1074: 9010207f                 mov     0x7F, %o0
F00C1078: 81c7e008                 ret
F00C107C: 81e80000                 restore
