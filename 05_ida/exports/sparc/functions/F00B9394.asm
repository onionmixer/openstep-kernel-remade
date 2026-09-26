F00B9394: 9de3bf98                 save    %sp, -0x68, %sp
F00B9398: 940e20ff                 and     %i0, 0xFF, %o2
F00B939C: 80a2a014                 cmp     %o2, 0x14
F00B93A0: 18800006                 bgu     loc_F00B93B8
F00B93A4: 113c047d                 sethi   %hi(unk_F011F5DC), %o0
F00B93A8: 901221dc                 bset    %lo(unk_F011F5DC), %o0
F00B93AC: 932aa002                 sll     %o2, 2, %o1
F00B93B0: 10800008                 ba      locret_F00B93D0
F00B93B4: f0024008                 ld      [%o1+%o0], %i0
F00B93B8: 313c04c6b0162008         set     unk_F0131808, %i0
F00B93C0: 90100018                 mov     %i0, %o0! char *
F00B93C4: 133c047d                 sethi   %hi(aUnkownReason0x), %o1! "<unkown reason 0x%x>"
F00B93C8: 7ffd6ce8                 call    _sprintf
F00B93CC: 92126348                 bset    %lo(aUnkownReason0x), %o1! "<unkown reason 0x%x>"
F00B93D0: 81c7e008                 ret
F00B93D4: 81e80000                 restore
