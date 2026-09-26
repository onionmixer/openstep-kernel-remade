F001DFE0: 9de3bf98                 save    %sp, -0x68, %sp
F001DFE4: b4960000                 orcc    %i0, %g0, %i2
F001DFE8: 02800039                 be      locret_F001E0CC
F001DFEC: 80a66000                 cmp     %i1, 0
F001DFF0: 26800010                 bl,a    loc_F001E030
F001DFF4: c4068000                 ld      [%i2], %g2
F001DFF8: 80a66000                 cmp     %i1, 0
F001DFFC: 04800034                 ble     locret_F001E0CC
F001E000: 01000000                 nop
F001E004: c456a008                 ldsh    [%i2+8], %g2
F001E008: 80a08019                 cmp     %g2, %i1
F001E00C: 14800019                 bg      loc_F001E070
F001E010: 86100002                 mov     %g2, %g3
F001E014: c036a008                 clrh    [%i2+8]
F001E018: f4068000                 ld      [%i2], %i2
F001E01C: 80a6a000                 cmp     %i2, 0
F001E020: 0280002b                 be      locret_F001E0CC
F001E024: b2264002                 sub     %i1, %g2, %i1
F001E028: 10bffff5                 ba      loc_F001DFFC
F001E02C: 80a66000                 cmp     %i1, 0
F001E030: b2200019                 neg     %i1
F001E034: 80a0a000                 cmp     %g2, 0
F001E038: 02800008                 be      loc_F001E058
F001E03C: f656a008                 ldsh    [%i2+8], %i3
F001E040: f4068000                 ld      [%i2], %i2
F001E044: c456a008                 ldsh    [%i2+8], %g2
F001E048: c6068000                 ld      [%i2], %g3
F001E04C: 80a0e000                 cmp     %g3, 0
F001E050: 12bffffc                 bne     loc_F001E040
F001E054: b606c002                 add     %i3, %g2, %i3
F001E058: c456a008                 ldsh    [%i2+8], %g2
F001E05C: 80a08019                 cmp     %g2, %i1
F001E060: 0680000a                 bl      loc_F001E088
F001E064: 84208019                 sub     %g2, %i1, %g2
F001E068: 10800019                 ba      locret_F001E0CC
F001E06C: c436a008                 sth     %g2, [%i2+8]
F001E070: 8620c019                 sub     %g3, %i1, %g3
F001E074: c406a004                 ld      [%i2+4], %g2
F001E078: c636a008                 sth     %g3, [%i2+8]
F001E07C: 84008019                 add     %g2, %i1, %g2
F001E080: 10800013                 ba      locret_F001E0CC
F001E084: c426a004                 st      %g2, [%i2+4]
F001E088: b4960000                 orcc    %i0, %g0, %i2
F001E08C: 0280000c                 be      loc_F001E0BC
F001E090: b626c019                 sub     %i3, %i1, %i3
F001E094: c456a008                 ldsh    [%i2+8], %g2
F001E098: 80a0801b                 cmp     %g2, %i3
F001E09C: 36800008                 bge,a   loc_F001E0BC
F001E0A0: f636a008                 sth     %i3, [%i2+8]
F001E0A4: f4068000                 ld      [%i2], %i2
F001E0A8: 80a6a000                 cmp     %i2, 0
F001E0AC: 12bffffa                 bne     loc_F001E094
F001E0B0: b626c002                 sub     %i3, %g2, %i3
F001E0B4: 10800003                 ba      loc_F001E0C0
F001E0B8: f4068000                 ld      [%i2], %i2
F001E0BC: f4068000                 ld      [%i2], %i2
F001E0C0: 80a6a000                 cmp     %i2, 0
F001E0C4: 32bffffe                 bne,a   loc_F001E0BC
F001E0C8: c036a008                 clrh    [%i2+8]
F001E0CC: 81c7e008                 ret
F001E0D0: 81e80000                 restore
