F003C020: 9de3bf90                 save    %sp, -0x70, %sp
F003C024: 80a66000                 cmp     %i1, 0
F003C028: 22800013                 be,a    locret_F003C074
F003C02C: b0102000                 mov     0, %i0
F003C030: 7fffa07a                 call    _getvfs
F003C034: 90100018                 mov     %i0, %o0
F003C038: 80a22000                 cmp     %o0, 0
F003C03C: 0280000d                 be      loc_F003C070
F003C040: 9207bff4                 add     %fp, var_C, %o1
F003C044: d4022004                 ld      [%o0+4], %o2
F003C048: d602a014                 ld      [%o2+0x14], %o3
F003C04C: 9fc2c000                 call    %o3
F003C050: 94062008                 add     %i0, 8, %o2
F003C054: 80a22000                 cmp     %o0, 0
F003C058: 12800007                 bne     locret_F003C074
F003C05C: b0102000                 mov     0, %i0
F003C060: f007bff4                 ld      [%fp+var_C], %i0
F003C064: 80a62000                 cmp     %i0, 0
F003C068: 12800003                 bne     locret_F003C074
F003C06C: 01000000                 nop
F003C070: b0102000                 mov     0, %i0
F003C074: 81c7e008                 ret
F003C078: 81e80000                 restore
