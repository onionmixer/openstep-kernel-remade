F00D7F58: 9de3bf90                 save    %sp, -0x70, %sp
F00D7F5C: a2102000                 mov     0, %l1
F00D7F60: a4102000                 mov     0, %l2
F00D7F64: 80a6e00a                 cmp     %i3, 0xA
F00D7F68: 1280007b                 bne     locret_F00D8154
F00D7F6C: 92102000                 mov     0, %o1
F00D7F70: 80a6a000                 cmp     %i2, 0
F00D7F74: 12800008                 bne     loc_F00D7F94
F00D7F78: 80a6a001                 cmp     %i2, 1
F00D7F7C: 11000400                 sethi   0x100000, %o0
F00D7F80: 900f0008                 and     %i4, %o0, %o0
F00D7F84: 80a00008                 cmp     %g0, %o0
F00D7F88: 90603fff                 subc    %g0, -1, %o0
F00D7F8C: 10800009                 ba      loc_F00D7FB0
F00D7F90: a2100008                 mov     %o0, %l1
F00D7F94: 12800008                 bne     loc_F00D7FB4
F00D7F98: 11000080                 sethi   0x20000, %o0
F00D7F9C: 11000400                 sethi   0x100000, %o0
F00D7FA0: 808f0008                 btst    %o0, %i4
F00D7FA4: 22800003                 be,a    loc_F00D7FB0
F00D7FA8: a4102001                 mov     1, %l2
F00D7FAC: 92102001                 mov     1, %o1
F00D7FB0: 11000080                 sethi   0x20000, %o0
F00D7FB4: 808f0008                 btst    %o0, %i4
F00D7FB8: 3280003a                 bne,a   loc_F00D80A0
F00D7FBC: 113c0505                 sethi   -0xFEBEC00, %o0
F00D7FC0: 80a26000                 cmp     %o1, 0
F00D7FC4: 2280000e                 be,a    loc_F00D7FFC
F00D7FC8: 113c0505                 sethi   -0xFEBEC00, %o0
F00D7FCC: 113c0505                 sethi   %hi(paIsoutputmuted_0), %o0
F00D7FD0: d202217c                 ld      [%o0+%lo(paIsoutputmuted_0)], %o1! SEL
F00D7FD4: 113c0505                 sethi   %hi(paSetoutputmute), %o0! id
F00D7FD8: e0022178                 ld      [%o0+%lo(paSetoutputmute)], %l0
F00D7FDC: 40006625                 call    _objc_msgSend
F00D7FE0: 90100018                 mov     %i0, %o0
F00D7FE4: 952a2018                 sll     %o0, 24, %o2
F00D7FE8: 90100018                 mov     %i0, %o0! id
F00D7FEC: 92100010                 mov     %l0, %o1
F00D7FF0: 80a0000a                 cmp     %g0, %o2
F00D7FF4: 10800056                 ba      loc_F00D814C
F00D7FF8: 94603fff                 subc    %g0, -1, %o2
F00D7FFC: d2022174                 ld      [%o0+0x174], %o1! SEL
F00D8000: 4000661c                 call    _objc_msgSend
F00D8004: 90100018                 mov     %i0, %o0
F00D8008: a0100008                 mov     %o0, %l0
F00D800C: 113c0505                 sethi   %hi(paOutputattenuat_1), %o0! id
F00D8010: d2022170                 ld      [%o0+%lo(paOutputattenuat_1)], %o1! SEL
F00D8014: 40006617                 call    _objc_msgSend
F00D8018: 90100018                 mov     %i0, %o0
F00D801C: 80a46000                 cmp     %l1, 0
F00D8020: 0280000c                 be      loc_F00D8050
F00D8024: b4100008                 mov     %o0, %i2
F00D8028: a0042001                 inc     %l0
F00D802C: 80a42000                 cmp     %l0, 0
F00D8030: 34800002                 bg,a    loc_F00D8038
F00D8034: a0102000                 mov     0, %l0
F00D8038: b406a001                 inc     %i2
F00D803C: 80a6a000                 cmp     %i2, 0
F00D8040: 3480000f                 bg,a    loc_F00D807C
F00D8044: b4102000                 mov     0, %i2
F00D8048: 1080000e                 ba      loc_F00D8080
F00D804C: 90100018                 mov     %i0, %o0
F00D8050: 80a4a000                 cmp     %l2, 0
F00D8054: 0280000b                 be      loc_F00D8080
F00D8058: 90100018                 mov     %i0, %o0
F00D805C: a0043fff                 inc     -1, %l0
F00D8060: 80a43fac                 cmp     %l0, -0x54
F00D8064: 26800002                 bl,a    loc_F00D806C
F00D8068: a0103fac                 mov     -0x54, %l0
F00D806C: b406bfff                 inc     -1, %i2
F00D8070: 80a6bfac                 cmp     %i2, -0x54
F00D8074: 26800002                 bl,a    loc_F00D807C
F00D8078: b4103fac                 mov     -0x54, %i2
F00D807C: 90100018                 mov     %i0, %o0! id
F00D8080: 133c0505                 sethi   %hi(paSetoutputatten_0), %o1
F00D8084: d202616c                 ld      [%o1+%lo(paSetoutputatten_0)], %o1! SEL
F00D8088: 400065fa                 call    _objc_msgSend
F00D808C: 94100010                 mov     %l0, %o2
F00D8090: 90100018                 mov     %i0, %o0! id
F00D8094: 133c0505                 sethi   %hi(paSetoutputatten), %o1
F00D8098: 1080002c                 ba      loc_F00D8148
F00D809C: d2026168                 ld      [%o1+%lo(paSetoutputatten)], %o1
F00D80A0: d2022164                 ld      [%o0+0x164], %o1! SEL
F00D80A4: 400065f3                 call    _objc_msgSend
F00D80A8: 90100018                 mov     %i0, %o0
F00D80AC: a0100008                 mov     %o0, %l0
F00D80B0: 113c0505                 sethi   %hi(paInputgainright_0), %o0! id
F00D80B4: d2022160                 ld      [%o0+%lo(paInputgainright_0)], %o1! SEL
F00D80B8: 400065ee                 call    _objc_msgSend
F00D80BC: 90100018                 mov     %i0, %o0
F00D80C0: 80a46000                 cmp     %l1, 0
F00D80C4: 0280000e                 be      loc_F00D80FC
F00D80C8: b4100008                 mov     %o0, %i2
F00D80CC: a0042666                 inc     0x666, %l0
F00D80D0: 1100001f901223ff         set     0x7FFF, %o0
F00D80D8: 80a40008                 cmp     %l0, %o0
F00D80DC: 34800002                 bg,a    loc_F00D80E4
F00D80E0: 21000020                 sethi   0x8000, %l0
F00D80E4: b406a666                 inc     0x666, %i2
F00D80E8: 80a68008                 cmp     %i2, %o0
F00D80EC: 3480000f                 bg,a    loc_F00D8128
F00D80F0: 35000020                 sethi   0x8000, %i2
F00D80F4: 1080000e                 ba      loc_F00D812C
F00D80F8: 90100018                 mov     %i0, %o0
F00D80FC: 80a4a000                 cmp     %l2, 0
F00D8100: 0280000b                 be      loc_F00D812C
F00D8104: 90100018                 mov     %i0, %o0
F00D8108: a004399a                 inc     -0x666, %l0
F00D810C: 80a42000                 cmp     %l0, 0
F00D8110: 24800002                 ble,a   loc_F00D8118
F00D8114: a0102000                 mov     0, %l0
F00D8118: b406b99a                 inc     -0x666, %i2
F00D811C: 80a6a000                 cmp     %i2, 0
F00D8120: 24800002                 ble,a   loc_F00D8128
F00D8124: b4102000                 mov     0, %i2
F00D8128: 90100018                 mov     %i0, %o0! id
F00D812C: 133c0505                 sethi   %hi(paSetinputgainle), %o1
F00D8130: d202615c                 ld      [%o1+%lo(paSetinputgainle)], %o1! SEL
F00D8134: 400065cf                 call    _objc_msgSend
F00D8138: 94100010                 mov     %l0, %o2
F00D813C: 90100018                 mov     %i0, %o0! id
F00D8140: 133c0505                 sethi   %hi(paSetinputgainri), %o1
F00D8144: d2026158                 ld      [%o1+%lo(paSetinputgainri)], %o1! SEL
F00D8148: 9410001a                 mov     %i2, %o2
F00D814C: 400065c9                 call    _objc_msgSend
F00D8150: 01000000                 nop
F00D8154: 81c7e008                 ret
F00D8158: 81e80000                 restore
