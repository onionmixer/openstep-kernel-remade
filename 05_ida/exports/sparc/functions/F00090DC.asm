F00090DC: 9de3bf98                 save    %sp, -0x68, %sp
F00090E0: 113c043c                 sethi   %hi(_mounttab), %o0
F00090E4: d20220ac                 ld      [%o0+%lo(_mounttab)], %o1
F00090E8: 80a26000                 cmp     %o1, 0
F00090EC: 0280001a                 be      locret_F0009154
F00090F0: b0102000                 mov     0, %i0
F00090F4: d2026020                 ld      [%o1+0x20], %o1
F00090F8: 80a26000                 cmp     %o1, 0
F00090FC: 32bfffff                 bne,a   loc_F00090F8
F0009100: d2026020                 ld      [%o1+0x20], %o1
F0009104: 80a26000                 cmp     %o1, 0
F0009108: 02800013                 be      locret_F0009154
F000910C: b0102000                 mov     0, %i0
F0009110: d002600c                 ld      [%o1+0xC], %o0
F0009114: d2022020                 ld      [%o0+0x20], %o1
F0009118: d00260c4                 ld      [%o1+0xC4], %o0
F000911C: d4026060                 ld      [%o1+0x60], %o2
F0009120: d60260cc                 ld      [%o1+0xCC], %o3
F0009124: 912a000a                 sll     %o0, %o2, %o0
F0009128: 9002000b                 add     %o0, %o3, %o0
F000912C: d0264000                 st      %o0, [%i1]
F0009130: d0026028                 ld      [%o1+0x28], %o0
F0009134: d0266008                 st      %o0, [%i1+8]
F0009138: d00260c8                 ld      [%o1+0xC8], %o0
F000913C: d0266004                 st      %o0, [%i1+4]
F0009140: d002602c                 ld      [%o1+0x2C], %o0
F0009144: 7ffff4ef                 call    _umul
F0009148: d20260b8                 ld      [%o1+0xB8], %o1
F000914C: d026600c                 st      %o0, [%i1+0xC]
F0009150: b0102001                 mov     1, %i0
F0009154: 81c7e008                 ret
F0009158: 81e80000                 restore
