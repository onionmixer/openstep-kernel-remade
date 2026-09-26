F00B20D4: 9de3bf98                 save    %sp, -0x68, %sp
F00B20D8: 90100018                 mov     %i0, %o0! __s1
F00B20DC: 133c0474                 sethi   %hi(unk_F011D210), %o1! __s2
F00B20E0: 7ffd5833                 call    _strcmp
F00B20E4: 92126210                 bset    %lo(unk_F011D210), %o1
F00B20E8: 80a22000                 cmp     %o0, 0
F00B20EC: 12800007                 bne     locret_F00B2108
F00B20F0: b0102000                 mov     0, %i0
F00B20F4: 133c0474                 sethi   %hi(_ndma_map), %o1
F00B20F8: d00261d8                 ld      [%o1+%lo(_ndma_map)], %o0
F00B20FC: b0102001                 mov     1, %i0
F00B2100: 90022001                 inc     %o0
F00B2104: d02261d8                 st      %o0, [%o1+%lo(_ndma_map)]
F00B2108: 81c7e008                 ret
F00B210C: 81e80000                 restore
