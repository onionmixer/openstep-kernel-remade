F00599BC: 9de3bf98                 save    %sp, -0x68, %sp
F00599C0: 80a62015                 cmp     %i0, 0x15! switch 22 cases
F00599C4: 18800023                 bgu     def_F00599D8! jumptable F00599D8 default case, cases 1-4,7-15
F00599C8: 932e2002                 sll     %i0, 2, %o1
F00599CC: 113c0166901221e0         set     jpt_F00599D8, %o0
F00599D4: d0024008                 ld      [%o1+%o0], %o0
F00599D8: 81c20000                 jmp     %o0! switch jump
F00599DC: 01000000                 nop
F0059A38: 1080000a                 ba      locret_F0059A60! jumptable F00599D8 cases 18,21
F0059A3C: b0102012                 mov     0x12, %i0
F0059A40: 10800008                 ba      locret_F0059A60! jumptable F00599D8 cases 6,17,19,20
F0059A44: b0102011                 mov     0x11, %i0
F0059A48: 10800006                 ba      locret_F0059A60! jumptable F00599D8 cases 5,16
F0059A4C: b0102010                 mov     0x10, %i0
F0059A50: 113c043d                 sethi   %hi(aIpcObjectCopyi), %o0! jumptable F00599D8 default case, cases 1-4,7-15
F0059A54: 7ffeedc7                 call    _panic
F0059A58: 901221e8                 bset    %lo(aIpcObjectCopyi), %o0! "ipc_object_copyin_type: strange rights"
F0059A5C: b0102000                 mov     0, %i0! jumptable F00599D8 case 0
F0059A60: 81c7e008                 ret
F0059A64: 81e80000                 restore
