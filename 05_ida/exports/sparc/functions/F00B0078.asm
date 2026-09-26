F00B0078: 9de3bf98                 save    %sp, -0x68, %sp
F00B007C: 7ffffd9a                 call    _prom_stdoutpath
F00B0080: 01000000                 nop
F00B0084: 80a22000                 cmp     %o0, 0
F00B0088: 22800009                 be,a    loc_F00B00AC
F00B008C: 113c0470                 sethi   -0xFEE4000, %o0
F00B0090: 40000b98                 call    _path_to_devi
F00B0094: 01000000                 nop
F00B0098: 80a22000                 cmp     %o0, 0
F00B009C: 22800004                 be,a    loc_F00B00AC
F00B00A0: 113c0470                 sethi   -0xFEE4000, %o0
F00B00A4: 1080001e                 ba      locret_F00B011C
F00B00A8: f002202c                 ld      [%o0+0x2C], %i0
F00B00AC: d0022278                 ld      [%o0+0x278], %o0
F00B00B0: 80a22000                 cmp     %o0, 0
F00B00B4: 02800004                 be      loc_F00B00C4
F00B00B8: 80a22002                 cmp     %o0, 2
F00B00BC: 12800018                 bne     locret_F00B011C
F00B00C0: b0103fff                 mov     -1, %i0
F00B00C4: 113c000c                 sethi   %hi(_romp), %o0
F00B00C8: d0022030                 ld      [%o0+%lo(_romp)], %o0
F00B00CC: d0022048                 ld      [%o0+0x48], %o0
F00B00D0: d20a0000                 ldub    [%o0], %o1
F00B00D4: 80a26004                 cmp     %o1, 4! switch 5 cases
F00B00D8: 18800010                 bgu     def_F00B00EC! jumptable F00B00EC default case, case 0
F00B00DC: 113c02c0                 sethi   %hi(jpt_F00B00EC), %o0
F00B00E0: 901220f4                 bset    %lo(jpt_F00B00EC), %o0
F00B00E4: 932a6002                 sll     %o1, 2, %o1
F00B00E8: d0024008                 ld      [%o1+%o0], %o0
F00B00EC: 81c20000                 jmp     %o0! switch jump
F00B00F0: 01000000                 nop
F00B0108: 10800005                 ba      locret_F00B011C! jumptable F00B00EC cases 1,2
F00B010C: b0102000                 mov     0, %i0
F00B0110: 10800003                 ba      locret_F00B011C! jumptable F00B00EC cases 3,4
F00B0114: b0102002                 mov     2, %i0
F00B0118: b0103fff                 mov     -1, %i0! jumptable F00B00EC default case, case 0
F00B011C: 81c7e008                 ret
F00B0120: 81e80000                 restore
