F0083830: 9de3bf90                 save    %sp, -0x70, %sp
F0083834: 90100018                 mov     %i0, %o0
F0083838: 133c04d0                 sethi   %hi(_page_mask), %o1
F008383C: 9607bff4                 add     %fp, var_C, %o3
F0083840: d4022014                 ld      [%o0+0x14], %o2
F0083844: 9a102001                 mov     1, %o5
F0083848: d80260d8                 ld      [%o1+%lo(_page_mask)], %o4
F008384C: d427bff4                 st      %o2, [%fp+var_C]
F0083850: b406800c                 add     %i2, %o4, %i2
F0083854: 92102000                 mov     0, %o1
F0083858: 94102000                 mov     0, %o2
F008385C: 4000035d                 call    _vm_map_find
F0083860: 982e800c                 andn    %i2, %o4, %o4
F0083864: 80a22000                 cmp     %o0, 0
F0083868: 12800005                 bne     locret_F008387C
F008386C: b0100008                 mov     %o0, %i0
F0083870: d007bff4                 ld      [%fp+var_C], %o0
F0083874: b0102000                 mov     0, %i0
F0083878: d0264000                 st      %o0, [%i1]
F008387C: 81c7e008                 ret
F0083880: 81e80000                 restore
