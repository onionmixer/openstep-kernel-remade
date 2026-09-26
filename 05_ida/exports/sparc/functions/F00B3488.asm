F00B3488: 9de3bf98                 save    %sp, -0x68, %sp
F00B348C: 113c0478                 sethi   %hi(_hex_unit_devices), %o0
F00B3490: d2022068                 ld      [%o0+%lo(_hex_unit_devices)], %o1
F00B3494: 80a26000                 cmp     %o1, 0
F00B3498: 02800017                 be      loc_F00B34F4
F00B349C: a0122068                 or      %o0, %lo(_hex_unit_devices), %l0
F00B34A0: 233c0477                 sethi   -0xFEE2400, %l1
F00B34A4: 253c0477                 sethi   -0xFEE2400, %l2
F00B34A8: d0040000                 ld      [%l0], %o0! __s1
F00B34AC: 92100018                 mov     %i0, %o1! __s2
F00B34B0: 7ffd540e                 call    _strncmp
F00B34B4: 94102002                 mov     2, %o2
F00B34B8: 80a22000                 cmp     %o0, 0
F00B34BC: 3280000a                 bne,a   loc_F00B34E4
F00B34C0: a0042004                 inc     4, %l0
F00B34C4: d00461a0                 ld      [%l1+0x1A0], %o0! char *
F00B34C8: 80a22000                 cmp     %o0, 0
F00B34CC: 02800013                 be      locret_F00B3518
F00B34D0: b0102001                 mov     1, %i0
F00B34D4: 7ffd8461                 call    _printf
F00B34D8: 9014a380                 or      %l2, 0x380, %o0
F00B34DC: 1080000f                 ba      locret_F00B3518
F00B34E0: b0102001                 mov     1, %i0
F00B34E4: d0040000                 ld      [%l0], %o0
F00B34E8: 80a22000                 cmp     %o0, 0
F00B34EC: 12bffff1                 bne     loc_F00B34B0
F00B34F0: 92100018                 mov     %i0, %o1
F00B34F4: 113c0477                 sethi   %hi(dword_F011DDA0), %o0
F00B34F8: d00221a0                 ld      [%o0+%lo(dword_F011DDA0)], %o0
F00B34FC: 80a22000                 cmp     %o0, 0
F00B3500: 02800006                 be      locret_F00B3518
F00B3504: b0102000                 mov     0, %i0
F00B3508: 113c0477                 sethi   %hi(aSUnitsAreNotIn), %o0! "%s units are not in hex.\n"
F00B350C: 7ffd8453                 call    _printf
F00B3510: 90122398                 bset    %lo(aSUnitsAreNotIn), %o0! "%s units are not in hex.\n"
F00B3514: b0102000                 mov     0, %i0
F00B3518: 81c7e008                 ret
F00B351C: 81e80000                 restore
