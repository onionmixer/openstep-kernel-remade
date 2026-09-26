F00AFFC4: 9de3bf98                 save    %sp, -0x68, %sp
F00AFFC8: 7ffffc96                 call    _prom_stdinpath
F00AFFCC: 01000000                 nop
F00AFFD0: 80a22000                 cmp     %o0, 0
F00AFFD4: 22800009                 be,a    loc_F00AFFF8
F00AFFD8: 113c0470                 sethi   -0xFEE4000, %o0
F00AFFDC: 40000bc5                 call    _path_to_devi
F00AFFE0: 01000000                 nop
F00AFFE4: 80a22000                 cmp     %o0, 0
F00AFFE8: 22800004                 be,a    loc_F00AFFF8
F00AFFEC: 113c0470                 sethi   -0xFEE4000, %o0
F00AFFF0: 10800020                 ba      locret_F00B0070
F00AFFF4: f002202c                 ld      [%o0+0x2C], %i0
F00AFFF8: d0022278                 ld      [%o0+0x278], %o0
F00AFFFC: 80a22000                 cmp     %o0, 0
F00B0000: 02800004                 be      loc_F00B0010
F00B0004: 80a22002                 cmp     %o0, 2
F00B0008: 1280001a                 bne     locret_F00B0070
F00B000C: b0103fff                 mov     -1, %i0
F00B0010: 113c000c                 sethi   %hi(_romp), %o0
F00B0014: d0022030                 ld      [%o0+%lo(_romp)], %o0
F00B0018: d0022048                 ld      [%o0+0x48], %o0
F00B001C: d20a0000                 ldub    [%o0], %o1
F00B0020: 80a26004                 cmp     %o1, 4! switch 5 cases
F00B0024: 18800012                 bgu     def_F00B0038! jumptable F00B0038 default case
F00B0028: 113c02c0                 sethi   %hi(jpt_F00B0038), %o0
F00B002C: 90122040                 bset    %lo(jpt_F00B0038), %o0
F00B0030: 932a6002                 sll     %o1, 2, %o1
F00B0034: d0024008                 ld      [%o1+%o0], %o0
F00B0038: 81c20000                 jmp     %o0! switch jump
F00B003C: 01000000                 nop
F00B0054: 10800007                 ba      locret_F00B0070! jumptable F00B0038 case 0
F00B0058: b0102001                 mov     1, %i0
F00B005C: 10800005                 ba      locret_F00B0070! jumptable F00B0038 cases 1,2
F00B0060: b0102000                 mov     0, %i0
F00B0064: 10800003                 ba      locret_F00B0070! jumptable F00B0038 cases 3,4
F00B0068: b0102002                 mov     2, %i0
F00B006C: b0103fff                 mov     -1, %i0! jumptable F00B0038 default case
F00B0070: 81c7e008                 ret
F00B0074: 81e80000                 restore
