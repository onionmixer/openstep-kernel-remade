F00A7754: 9de3bf98                 save    %sp, -0x68, %sp
F00A7758: 9136e002                 srl     %i3, 2, %o0
F00A775C: 900a2007                 and     %o0, 7, %o0
F00A7760: 92023fff                 add     %o0, -1, %o1
F00A7764: 80a26005                 cmp     %o1, 5! switch 6 cases
F00A7768: 1880000d                 bgu     def_F00A777C! jumptable F00A777C default case, cases 3-5
F00A776C: 113c029d                 sethi   %hi(jpt_F00A777C), %o0
F00A7770: 90122384                 bset    %lo(jpt_F00A777C), %o0
F00A7774: 932a6002                 sll     %o1, 2, %o1
F00A7778: d0024008                 ld      [%o1+%o0], %o0
F00A777C: 81c20000                 jmp     %o0! switch jump
F00A7780: 01000000                 nop
F00A779C: 113c046e90122118         set     aUnexpectedTrap, %o0! jumptable F00A777C default case, cases 3-5
F00A77A4: 92100018                 mov     %i0, %o1
F00A77A8: 9536e002                 srl     %i3, 2, %o2
F00A77AC: 7ffdb3ab                 call    _printf
F00A77B0: 940aa007                 and     %o2, 7, %o2
F00A77B4: 90100018                 mov     %i0, %o0
F00A77B8: 92100019                 mov     %i1, %o1
F00A77BC: 9410001a                 mov     %i2, %o2
F00A77C0: 9610001b                 mov     %i3, %o3
F00A77C4: 7fffff97                 call    _badtrap
F00A77C8: 9810001c                 mov     %i4, %o4
F00A77CC: 10800003                 ba      locret_F00A77D8! jumptable F00A777C case 0
F00A77D0: b0102000                 mov     0, %i0
F00A77D4: b0102001                 mov     1, %i0! jumptable F00A777C cases 1,2
F00A77D8: 81c7e008                 ret
F00A77DC: 81e80000                 restore
