F00B1F44: 9de3bf98                 save    %sp, -0x68, %sp
F00B1F48: d006200c                 ld      [%i0+0xC], %o0! __s1
F00B1F4C: 133c0474                 sethi   %hi(aOptions), %o1! "options"
F00B1F50: 7ffd5897                 call    _strcmp
F00B1F54: 92126180                 bset    %lo(aOptions), %o1! "options"
F00B1F58: 80a22000                 cmp     %o0, 0
F00B1F5C: 32800004                 bne,a   loc_F00B1F6C
F00B1F60: d0062020                 ld      [%i0+0x20], %o0
F00B1F64: 10800037                 ba      locret_F00B2040
F00B1F68: f0266008                 st      %i0, [%i1+8]
F00B1F6C: 80a22000                 cmp     %o0, 0
F00B1F70: 02800034                 be      locret_F00B2040
F00B1F74: 133c0474                 sethi   %hi(aZs_2), %o1! "zs"
F00B1F78: d006200c                 ld      [%i0+0xC], %o0! __s1
F00B1F7C: 92126188                 bset    %lo(aZs_2), %o1! "zs"
F00B1F80: 7ffd595a                 call    _strncmp
F00B1F84: 94102002                 mov     2, %o2
F00B1F88: 80a22000                 cmp     %o0, 0
F00B1F8C: 32800015                 bne,a   loc_F00B1FE0
F00B1F90: 313c0474                 sethi   -0xFEE3000, %i0
F00B1F94: d0062028                 ld      [%i0+0x28], %o0
F00B1F98: 133c047492126190         set     aKeyboard_0, %o1! "keyboard"
F00B1FA0: 7ffffc43                 call    _getprop
F00B1FA4: 94102000                 mov     0, %o2
F00B1FA8: 80a22000                 cmp     %o0, 0
F00B1FAC: 3280000b                 bne,a   loc_F00B1FD8
F00B1FB0: d006202c                 ld      [%i0+0x2C], %o0
F00B1FB4: d0062028                 ld      [%i0+0x28], %o0
F00B1FB8: 133c0474921261a0         set     aFlags_0, %o1! "flags"
F00B1FC0: 7ffffc3b                 call    _getprop
F00B1FC4: 94102000                 mov     0, %o2
F00B1FC8: 808a2100                 btst    0x100, %o0
F00B1FCC: 0280001d                 be      locret_F00B2040
F00B1FD0: 01000000                 nop
F00B1FD4: d006202c                 ld      [%i0+0x2C], %o0
F00B1FD8: 1080001a                 ba      locret_F00B2040
F00B1FDC: d0264000                 st      %o0, [%i1]
F00B1FE0: d056217a                 ldsh    [%i0+0x17A], %o0
F00B1FE4: 80a23fff                 cmp     %o0, -1
F00B1FE8: 12800012                 bne     loc_F00B2030
F00B1FEC: 113c0474                 sethi   -0xFEE3000, %o0
F00B1FF0: 7ffff3cd                 call    _prom_stdout_is_framebuffer
F00B1FF4: 01000000                 nop
F00B1FF8: 80a22000                 cmp     %o0, 0
F00B1FFC: 0280000d                 be      loc_F00B2030
F00B2000: 113c0474                 sethi   -0xFEE3000, %o0
F00B2004: 7ffff5b8                 call    _prom_stdoutpath
F00B2008: 01000000                 nop
F00B200C: 400003b9                 call    _path_to_devi
F00B2010: 01000000                 nop
F00B2014: 92920000                 orcc    %o0, %g0, %o1
F00B2018: 02800006                 be      loc_F00B2030
F00B201C: 113c0474                 sethi   -0xFEE3000, %o0
F00B2020: 7ffffcb5                 call    _finddev
F00B2024: 90102063                 mov     0x63, %o0 ! 'c'
F00B2028: d036217a                 sth     %o0, [%i0+0x17A]
F00B202C: 113c0474                 sethi   -0xFEE3000, %o0
F00B2030: d052217a                 ldsh    [%o0+0x17A], %o0
F00B2034: 80a23fff                 cmp     %o0, -1
F00B2038: 32800002                 bne,a   locret_F00B2040
F00B203C: d0366004                 sth     %o0, [%i1+4]
F00B2040: 81c7e008                 ret
F00B2044: 81e80000                 restore
