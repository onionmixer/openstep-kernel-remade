F00C68BC: 9de3bf90                 save    %sp, -0x70, %sp
F00C68C0: 96100018                 mov     %i0, %o3
F00C68C4: 113c04bb92122034         set     unk_F012EC34, %o1
F00C68CC: d0026004                 ld      [%o1+4], %o0
F00C68D0: 80a22000                 cmp     %o0, 0
F00C68D4: 0280000d                 be      loc_F00C6908
F00C68D8: 9410001a                 mov     %i2, %o2
F00C68DC: b0026004                 add     %o1, 4, %i0
F00C68E0: d0024000                 ld      [%o1], %o0
F00C68E4: 80a2000a                 cmp     %o0, %o2
F00C68E8: 32800004                 bne,a   loc_F00C68F8
F00C68EC: b0062008                 inc     8, %i0
F00C68F0: 1080000f                 ba      locret_F00C692C
F00C68F4: f0060000                 ld      [%i0], %i0
F00C68F8: d0060000                 ld      [%i0], %o0
F00C68FC: 80a22000                 cmp     %o0, 0
F00C6900: 12bffff8                 bne     loc_F00C68E0
F00C6904: 92026008                 inc     8, %o1
F00C6908: 113c0507                 sethi   %hi(stru_F0141EBC.ext), %o0! objc_super *
F00C690C: d20222e8                 ld      [%o0+%lo(stru_F0141EBC.ext)], %o1
F00C6910: d627bff0                 st      %o3, [%fp+var_10]
F00C6914: d227bff4                 st      %o1, [%fp+var_C]
F00C6918: 133c0504                 sethi   %hi(paStringfromretu), %o1
F00C691C: d2026260                 ld      [%o1+%lo(paStringfromretu)], %o1! SEL
F00C6920: 4000ac17                 call    _objc_msgSendSuper
F00C6924: 9007bff0                 add     %fp, var_10, %o0
F00C6928: b0100008                 mov     %o0, %i0
F00C692C: 81c7e008                 ret
F00C6930: 81e80000                 restore
