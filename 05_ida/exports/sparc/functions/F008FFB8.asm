F008FFB8: 9de3bf90                 save    %sp, -0x70, %sp
F008FFBC: f027bff0                 st      %i0, [%fp+var_10]
F008FFC0: 133c0507                 sethi   %hi(stru_F0141CDC.ext), %o1
F008FFC4: d4026108                 ld      [%o1+%lo(stru_F0141CDC.ext)], %o2
F008FFC8: 9007bff0                 add     %fp, var_10, %o0! objc_super *
F008FFCC: 133c0504                 sethi   %hi(paInit), %o1
F008FFD0: d202602c                 ld      [%o1+%lo(paInit)], %o1! SEL
F008FFD4: 4001866a                 call    _objc_msgSendSuper
F008FFD8: d427bff4                 st      %o2, [%fp+var_C]
F008FFDC: 1080000b                 ba      loc_F0090008
F008FFE0: d04e8000                 ldsb    [%i2], %o0
F008FFE4: 80a26020                 cmp     %o1, 0x20 ! ' '
F008FFE8: 02800006                 be      loc_F0090000
F008FFEC: 90027ff7                 add     %o1, -9, %o0
F008FFF0: 900a20ff                 and     %o0, 0xFF, %o0
F008FFF4: 80a22001                 cmp     %o0, 1
F008FFF8: 38800008                 bgu,a   loc_F0090018
F008FFFC: d04e8000                 ldsb    [%i2], %o0
F0090000: b406a001                 inc     %i2
F0090004: d04e8000                 ldsb    [%i2], %o0
F0090008: 80a22000                 cmp     %o0, 0
F009000C: 12bffff6                 bne     loc_F008FFE4
F0090010: d20e8000                 ldub    [%i2], %o1
F0090014: d04e8000                 ldsb    [%i2], %o0
F0090018: 80a22000                 cmp     %o0, 0
F009001C: 02800028                 be      loc_F00900BC
F0090020: a610001a                 mov     %i2, %l3
F0090024: 1080000b                 ba      loc_F0090050
F0090028: d04cc000                 ldsb    [%l3], %o0
F009002C: 80a26020                 cmp     %o1, 0x20 ! ' '
F0090030: 02800006                 be      loc_F0090048
F0090034: 90027ff7                 add     %o1, -9, %o0
F0090038: 900a20ff                 and     %o0, 0xFF, %o0
F009003C: 80a22001                 cmp     %o0, 1
F0090040: 38800008                 bgu,a   loc_F0090060
F0090044: d04cc000                 ldsb    [%l3], %o0
F0090048: a604e001                 inc     %l3
F009004C: d04cc000                 ldsb    [%l3], %o0
F0090050: 80a22000                 cmp     %o0, 0
F0090054: 12bffff6                 bne     loc_F009002C
F0090058: d20cc000                 ldub    [%l3], %o1
F009005C: d04cc000                 ldsb    [%l3], %o0
F0090060: 80a22000                 cmp     %o0, 0
F0090064: 2280000c                 be,a    loc_F0090094
F0090068: d24cc000                 ldsb    [%l3], %o1
F009006C: d0062008                 ld      [%i0+8], %o0
F0090070: 90022001                 inc     %o0
F0090074: 10800007                 ba      loc_F0090090
F0090078: d0262008                 st      %o0, [%i0+8]
F009007C: 900a20ff                 and     %o0, 0xFF, %o0
F0090080: 80a22001                 cmp     %o0, 1
F0090084: 2880000b                 bleu,a  loc_F00900B0
F0090088: d04cc000                 ldsb    [%l3], %o0
F009008C: a604e001                 inc     %l3
F0090090: d24cc000                 ldsb    [%l3], %o1
F0090094: 80a26000                 cmp     %o1, 0
F0090098: 02800005                 be      loc_F00900AC
F009009C: d00cc000                 ldub    [%l3], %o0
F00900A0: 80a26020                 cmp     %o1, 0x20 ! ' '
F00900A4: 12bffff6                 bne     loc_F009007C
F00900A8: 90023ff7                 inc     -9, %o0
F00900AC: d04cc000                 ldsb    [%l3], %o0
F00900B0: 80a22000                 cmp     %o0, 0
F00900B4: 32bfffe7                 bne,a   loc_F0090050
F00900B8: d04cc000                 ldsb    [%l3], %o0
F00900BC: d0062008                 ld      [%i0+8], %o0
F00900C0: a8102000                 mov     0, %l4
F00900C4: 7fffffaa                 call    sub_F008FF6C
F00900C8: 912a2002                 sll     %o0, 2, %o0
F00900CC: 80a6a000                 cmp     %i2, 0
F00900D0: 02800035                 be      locret_F00901A4
F00900D4: d0262004                 st      %o0, [%i0+4]
F00900D8: d04e8000                 ldsb    [%i2], %o0
F00900DC: 80a22000                 cmp     %o0, 0
F00900E0: 02800031                 be      locret_F00901A4
F00900E4: 80a22020                 cmp     %o0, 0x20 ! ' '
F00900E8: 0280000f                 be      loc_F0090124
F00900EC: a610001a                 mov     %i2, %l3
F00900F0: d00cc000                 ldub    [%l3], %o0
F00900F4: 90023ff7                 inc     -9, %o0
F00900F8: 900a20ff                 and     %o0, 0xFF, %o0
F00900FC: 80a22001                 cmp     %o0, 1
F0090100: 0880000a                 bleu    loc_F0090128
F0090104: a424c01a                 sub     %l3, %i2, %l2
F0090108: a604e001                 inc     %l3
F009010C: d04cc000                 ldsb    [%l3], %o0
F0090110: 80a22000                 cmp     %o0, 0
F0090114: 02800004                 be      loc_F0090124
F0090118: 80a22020                 cmp     %o0, 0x20 ! ' '
F009011C: 32bffff6                 bne,a   loc_F00900F4
F0090120: d00cc000                 ldub    [%l3], %o0
F0090124: a424c01a                 sub     %l3, %i2, %l2
F0090128: a204a001                 add     %l2, 1, %l1
F009012C: 7fffff90                 call    sub_F008FF6C
F0090130: 90100011                 mov     %l1, %o0! __dst
F0090134: a0100008                 mov     %o0, %l0
F0090138: 9210001a                 mov     %i2, %o1! __src
F009013C: b4100013                 mov     %l3, %i2
F0090140: d6062004                 ld      [%i0+4], %o3
F0090144: 952d2002                 sll     %l4, 2, %o2! __n
F0090148: e022c00a                 st      %l0, [%o3+%o2]
F009014C: 7ffdddf4                 call    _strncpy
F0090150: 94100012                 mov     %l2, %o2
F0090154: a2044010                 add     %l1, %l0, %l1
F0090158: c02c7fff                 clrb    [%l1-1]
F009015C: 1080000c                 ba      loc_F009018C
F0090160: d04e8000                 ldsb    [%i2], %o0
F0090164: 80a26020                 cmp     %o1, 0x20 ! ' '
F0090168: 22800008                 be,a    loc_F0090188
F009016C: b406a001                 inc     %i2
F0090170: 90027ff7                 add     %o1, -9, %o0
F0090174: 900a20ff                 and     %o0, 0xFF, %o0
F0090178: 80a22001                 cmp     %o0, 1
F009017C: 18800008                 bgu     loc_F009019C
F0090180: 80a6a000                 cmp     %i2, 0
F0090184: b406a001                 inc     %i2
F0090188: d04e8000                 ldsb    [%i2], %o0
F009018C: 80a22000                 cmp     %o0, 0
F0090190: 12bffff5                 bne     loc_F0090164
F0090194: d20e8000                 ldub    [%i2], %o1
F0090198: 80a6a000                 cmp     %i2, 0
F009019C: 12bfffcf                 bne     loc_F00900D8
F00901A0: a8052001                 inc     %l4
F00901A4: 81c7e008                 ret
F00901A8: 81e80000                 restore
