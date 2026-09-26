F00C4FC4: 9de3bf88                 save    %sp, -0x78, %sp
F00C4FC8: 113c0504                 sethi   %hi(paConfigtable_0), %o0! id
F00C4FCC: d2022310                 ld      [%o0+%lo(paConfigtable_0)], %o1! SEL
F00C4FD0: e00fa067                 ldub    [%fp+arg_67], %l0
F00C4FD4: 4000b227                 call    _objc_msgSend
F00C4FD8: 9010001a                 mov     %i2, %o0! id
F00C4FDC: 133c0504                 sethi   %hi(paValueforstring), %o1
F00C4FE0: 153c03ea                 sethi   %hi(aBlockMajor), %o2! "Block Major"
F00C4FE4: d20260e8                 ld      [%o1+%lo(paValueforstring)], %o1! SEL
F00C4FE8: 4000b222                 call    _objc_msgSend
F00C4FEC: 9412a108                 bset    %lo(aBlockMajor), %o2! "Block Major"
F00C4FF0: 80a22000                 cmp     %o0, 0
F00C4FF4: 02800019                 be      loc_F00C5058
F00C4FF8: 98100008                 mov     %o0, %o4
F00C4FFC: d04b0000                 ldsb    [%o4], %o0
F00C5000: 96102000                 mov     0, %o3
F00C5004: 80a22000                 cmp     %o0, 0
F00C5008: 02800012                 be      loc_F00C5050
F00C500C: d20b0000                 ldub    [%o4], %o1
F00C5010: 90027fd0                 add     %o1, -0x30, %o0
F00C5014: 900a20ff                 and     %o0, 0xFF, %o0
F00C5018: 80a22009                 cmp     %o0, 9
F00C501C: 1880000d                 bgu     loc_F00C5050
F00C5020: 98032001                 inc     %o4
F00C5024: 912ae002                 sll     %o3, 2, %o0
F00C5028: 9002000b                 add     %o0, %o3, %o0
F00C502C: 912a2001                 sll     %o0, 1, %o0
F00C5030: 90023fd0                 inc     -0x30, %o0
F00C5034: 932a6018                 sll     %o1, 24, %o1
F00C5038: 933a6018                 sra     %o1, 24, %o1
F00C503C: d44b0000                 ldsb    [%o4], %o2
F00C5040: 96020009                 add     %o0, %o1, %o3
F00C5044: 80a2a000                 cmp     %o2, 0
F00C5048: 12bffff2                 bne     loc_F00C5010
F00C504C: d20b0000                 ldub    [%o4], %o1
F00C5050: 10800003                 ba      loc_F00C505C
F00C5054: b410000b                 mov     %o3, %i2
F00C5058: b4103fff                 mov     -1, %i2
F00C505C: 912c2018                 sll     %l0, 24, %o0
F00C5060: 913a2018                 sra     %o0, 24, %o0
F00C5064: d023a05c                 st      %o0, [%sp+0x78+var_1C]
F00C5068: 9010001a                 mov     %i2, %o0
F00C506C: 9210001b                 mov     %i3, %o1
F00C5070: d807a05c                 ld      [%fp+arg_5C], %o4
F00C5074: 9410001c                 mov     %i4, %o2
F00C5078: da07a060                 ld      [%fp+arg_60], %o5
F00C507C: 400016c3                 call    _IOAddToBdevswAt
F00C5080: 9610001d                 mov     %i5, %o3
F00C5084: 94920000                 orcc    %o0, %g0, %o2
F00C5088: 1680001a                 bge     loc_F00C50F0
F00C508C: 133c0506                 sethi   -0xFEBE800, %o1
F00C5090: 80a6a000                 cmp     %i2, 0
F00C5094: 1680000c                 bge     loc_F00C50C4
F00C5098: 90100018                 mov     %i0, %o0! id
F00C509C: 133c0504                 sethi   %hi(paName), %o1
F00C50A0: d2026008                 ld      [%o1+%lo(paName)], %o1! SEL
F00C50A4: 213c03ea                 sethi   %hi(aSCouldNotAddTo_1), %l0! "%s: could not add to bdevsw table at an"...
F00C50A8: 4000b1f2                 call    _objc_msgSend
F00C50AC: a0142118                 bset    %lo(aSCouldNotAddTo_1), %l0! "%s: could not add to bdevsw table at an"...
F00C50B0: 92100008                 mov     %o0, %o1
F00C50B4: 40000410                 call    _IOLog
F00C50B8: 90100010                 mov     %l0, %o0! id
F00C50BC: 10800011                 ba      locret_F00C5100
F00C50C0: b0102000                 mov     0, %i0
F00C50C4: 133c0504                 sethi   %hi(paName), %o1
F00C50C8: d2026008                 ld      [%o1+%lo(paName)], %o1! SEL
F00C50CC: 213c03ea                 sethi   %hi(aSCouldNotAddTo_2), %l0! "%s: could not add to bdevsw table at ma"...
F00C50D0: 4000b1e8                 call    _objc_msgSend
F00C50D4: a0142148                 bset    %lo(aSCouldNotAddTo_2), %l0! "%s: could not add to bdevsw table at ma"...
F00C50D8: 92100008                 mov     %o0, %o1
F00C50DC: 90100010                 mov     %l0, %o0! id
F00C50E0: 40000405                 call    _IOLog
F00C50E4: 9410001a                 mov     %i2, %o2
F00C50E8: 10800006                 ba      locret_F00C5100
F00C50EC: b0102000                 mov     0, %i0
F00C50F0: d20261e0                 ld      [%o1+0x1E0], %o1! SEL
F00C50F4: 4000b1df                 call    _objc_msgSend
F00C50F8: 90100018                 mov     %i0, %o0
F00C50FC: b0102001                 mov     1, %i0
F00C5100: 81c7e008                 ret
F00C5104: 81e80000                 restore
