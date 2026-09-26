F00B0124: 9de3bf98                 save    %sp, -0x68, %sp
F00B0128: 7ffffc3e                 call    _prom_stdinpath
F00B012C: 01000000                 nop
F00B0130: 80a22000                 cmp     %o0, 0
F00B0134: 22800006                 be,a    loc_F00B014C
F00B0138: 113c0470                 sethi   -0xFEE4000, %o0
F00B013C: 7fffff35                 call    _prom_get_path_option
F00B0140: 01000000                 nop
F00B0144: 10800020                 ba      locret_F00B01C4
F00B0148: b0100008                 mov     %o0, %i0
F00B014C: d0022278                 ld      [%o0+0x278], %o0
F00B0150: 80a22000                 cmp     %o0, 0
F00B0154: 02800004                 be      loc_F00B0164
F00B0158: 80a22002                 cmp     %o0, 2
F00B015C: 1280001a                 bne     locret_F00B01C4
F00B0160: b0102000                 mov     0, %i0
F00B0164: 113c000c                 sethi   %hi(_romp), %o0
F00B0168: d0022030                 ld      [%o0+%lo(_romp)], %o0
F00B016C: d0022048                 ld      [%o0+0x48], %o0
F00B0170: d20a0000                 ldub    [%o0], %o1
F00B0174: 80a26004                 cmp     %o1, 4! switch 5 cases
F00B0178: 18800012                 bgu     def_F00B018C! jumptable F00B018C default case
F00B017C: 113c02c0                 sethi   %hi(jpt_F00B018C), %o0
F00B0180: 90122194                 bset    %lo(jpt_F00B018C), %o0
F00B0184: 932a6002                 sll     %o1, 2, %o1
F00B0188: d0024008                 ld      [%o1+%o0], %o0
F00B018C: 81c20000                 jmp     %o0! switch jump
F00B0190: 01000000                 nop
F00B01A8: 313c0470                 sethi   %hi(aA), %i0! jumptable F00B018C cases 0,1,3
F00B01AC: 10800006                 ba      locret_F00B01C4
F00B01B0: b0162360                 bset    %lo(aA), %i0! "a"
F00B01B4: 313c0470                 sethi   %hi(aB), %i0! jumptable F00B018C cases 2,4
F00B01B8: 10800003                 ba      locret_F00B01C4
F00B01BC: b0162368                 bset    %lo(aB), %i0! "b"
F00B01C0: b0102000                 mov     0, %i0! jumptable F00B018C default case
F00B01C4: 81c7e008                 ret
F00B01C8: 81e80000                 restore
