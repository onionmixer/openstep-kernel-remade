F00E27D8: 9de3bf98                 save    %sp, -0x68, %sp
F00E27DC: 113c04bb                 sethi   %hi(dword_F012EF60), %o0
F00E27E0: d0022360                 ld      [%o0+%lo(dword_F012EF60)], %o0
F00E27E4: 80a22000                 cmp     %o0, 0
F00E27E8: 02800004                 be      locret_F00E27F8
F00E27EC: 01000000                 nop
F00E27F0: 7fff8dd5                 call    _IOFree
F00E27F4: 13000010                 sethi   0x4000, %o1
F00E27F8: 81c7e008                 ret
F00E27FC: 81e80000                 restore
