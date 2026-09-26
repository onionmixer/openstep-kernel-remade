F00F0448: 9de3bf98                 save    %sp, -0x68, %sp
F00F044C: 113c03c192122080         set     jpt_F00F0478, %o1
F00F0454: d00e0000                 ldub    [%i0], %o0! jumptable F00F0478 cases 38,39,46,54,70,71,74
F00F0458: 90023fd8                 inc     -0x28, %o0
F00F045C: 912a2018                 sll     %o0, 24, %o0
F00F0460: 913a2018                 sra     %o0, 24, %o0
F00F0464: 80a22053                 cmp     %o0, 0x53 ! 'S'! switch 84 cases
F00F0468: 1880006c                 bgu     def_F00F0478! jumptable F00F0478 default case, cases 1-37,40-45,47-50,52,53,55-69,72,73,75-82
F00F046C: b0062001                 inc     %i0
F00F0470: 912a2002                 sll     %o0, 2, %o0
F00F0474: d0020009                 ld      [%o0+%o1], %o0
F00F0478: 81c20000                 jmp     %o0! switch jump
F00F047C: 01000000                 nop
F00F05D0: d00e0000                 ldub    [%i0], %o0! jumptable F00F0478 case 51
F00F05D4: 90023fd0                 inc     -0x30, %o0
F00F05D8: 900a20ff                 and     %o0, 0xFF, %o0
F00F05DC: 80a22009                 cmp     %o0, 9
F00F05E0: 28bffffc                 bleu,a  loc_F00F05D0! jumptable F00F0478 case 51
F00F05E4: b0062001                 inc     %i0
F00F05E8: 90100018                 mov     %i0, %o0
F00F05EC: 10800007                 ba      loc_F00F0608
F00F05F0: 9210205d                 mov     0x5D, %o1 ! ']'
F00F05F4: 90100018                 mov     %i0, %o0! jumptable F00F0478 case 83
F00F05F8: 10800004                 ba      loc_F00F0608
F00F05FC: 9210207d                 mov     0x7D, %o1 ! '}'
F00F0600: 90100018                 mov     %i0, %o0! jumptable F00F0478 case 0
F00F0604: 92102029                 mov     0x29, %o1 ! ')'
F00F0608: 7fffff56                 call    sub_F00F0360
F00F060C: 01000000                 nop
F00F0610: 90060008                 add     %i0, %o0, %o0
F00F0614: b0022001                 add     %o0, 1, %i0
F00F0618: 81c7e008                 ret! jumptable F00F0478 default case, cases 1-37,40-45,47-50,52,53,55-69,72,73,75-82
F00F061C: 81e80000                 restore
