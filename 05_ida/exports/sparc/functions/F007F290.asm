F007F290: 9de3bf98                 save    %sp, -0x68, %sp
F007F294: d4062004                 ld      [%i0+4], %o2! new_state
F007F298: 80a2a02b                 cmp     %o2, 0x2B ! '+'
F007F29C: 0880001d                 bleu    loc_F007F310
F007F2A0: 90103ed0                 mov     -0x130, %o0
F007F2A4: d0060000                 ld      [%i0], %o0
F007F2A8: 80a22000                 cmp     %o0, 0
F007F2AC: 06800018                 bl      loc_F007F30C
F007F2B0: 133c0444                 sethi   %hi(dword_F01113E4), %o1
F007F2B4: d0062018                 ld      [%i0+0x18], %o0
F007F2B8: d20263e4                 ld      [%o1+%lo(dword_F01113E4)], %o1
F007F2BC: 80a20009                 cmp     %o0, %o1
F007F2C0: 12800014                 bne     loc_F007F310
F007F2C4: 90103ed0                 mov     -0x130, %o0
F007F2C8: d0062020                 ld      [%i0+0x20], %o0
F007F2CC: 900a200c                 and     %o0, 0xC, %o0
F007F2D0: 80a2200c                 cmp     %o0, 0xC
F007F2D4: 1280000f                 bne     loc_F007F310
F007F2D8: 90103ed0                 mov     -0x130, %o0
F007F2DC: d2062024                 ld      [%i0+0x24], %o1
F007F2E0: 1100008090122020         set     0x20020, %o0
F007F2E8: 80a24008                 cmp     %o1, %o0
F007F2EC: 12800009                 bne     loc_F007F310
F007F2F0: 90103ed0                 mov     -0x130, %o0
F007F2F4: d0062028                 ld      [%i0+0x28], %o0
F007F2F8: 912a2002                 sll     %o0, 2, %o0
F007F2FC: 9002202c                 inc     0x2C, %o0 ! ','
F007F300: 80a28008                 cmp     %o2, %o0
F007F304: 02800005                 be      loc_F007F318
F007F308: 01000000                 nop
F007F30C: 90103ed0                 mov     -0x130, %o0
F007F310: 1080000c                 ba      locret_F007F340
F007F314: d026601c                 st      %o0, [%i1+0x1C]
F007F318: 7fffa1d9                 call    _convert_port_to_thread
F007F31C: d0062008                 ld      [%i0+8], %o0! target_act
F007F320: a0100008                 mov     %o0, %l0
F007F324: d206201c                 ld      [%i0+0x1C], %o1! flavor
F007F328: d6062028                 ld      [%i0+0x28], %o3! new_stateCnt
F007F32C: 7fffd8e5                 call    _thread_set_state
F007F330: 9406202c                 add     %i0, 0x2C, %o2 ! ','
F007F334: d026601c                 st      %o0, [%i1+0x1C]
F007F338: 7fffd41d                 call    _thread_deallocate
F007F33C: 90100010                 mov     %l0, %o0
F007F340: 81c7e008                 ret
F007F344: 81e80000                 restore
