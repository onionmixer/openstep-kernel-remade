F003838C: 9de3bf98                 save    %sp, -0x68, %sp
F0038390: d2562008                 ldsh    [%i0+8], %o1
F0038394: 80a26005                 cmp     %o1, 5! switch 6 cases
F0038398: 18800016                 bgu     def_F00383AC! jumptable F00383AC default case
F003839C: 113c00e0                 sethi   %hi(jpt_F00383AC), %o0
F00383A0: 901223b4                 bset    %lo(jpt_F00383AC), %o0
F00383A4: 932a6002                 sll     %o1, 2, %o1
F00383A8: d0024008                 ld      [%o1+%o0], %o0
F00383AC: 81c20000                 jmp     %o0! switch jump
F00383B0: 01000000                 nop
F00383CC: c0362008                 clrh    [%i0+8]! jumptable F00383AC cases 0-2
F00383D0: 7ffffc77                 call    _tcp_close
F00383D4: 90100018                 mov     %i0, %o0
F00383D8: 10800006                 ba      def_F00383AC! jumptable F00383AC default case
F00383DC: b0100008                 mov     %o0, %i0
F00383E0: 10800003                 ba      loc_F00383EC! jumptable F00383AC cases 3,4
F00383E4: 90102006                 mov     6, %o0
F00383E8: 90102008                 mov     8, %o0! jumptable F00383AC case 5
F00383EC: d0362008                 sth     %o0, [%i0+8]
F00383F0: 80a62000                 cmp     %i0, 0! jumptable F00383AC default case
F00383F4: 02800009                 be      locret_F0038418
F00383F8: 01000000                 nop
F00383FC: d0562008                 ldsh    [%i0+8], %o0
F0038400: 80a22008                 cmp     %o0, 8
F0038404: 04800005                 ble     locret_F0038418
F0038408: 01000000                 nop
F003840C: d0062020                 ld      [%i0+0x20], %o0
F0038410: 7fff9f22                 call    _soisdisconnected
F0038414: d002201c                 ld      [%o0+0x1C], %o0
F0038418: 81c7e008                 ret
F003841C: 81e80000                 restore
