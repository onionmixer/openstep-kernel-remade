F00BF31C: 9de3bf88                 save    %sp, -0x78, %sp
F00BF320: 40001b6f                 call    _IOGetTimestamp
F00BF324: 9007bfe8                 add     %fp, var_18, %o0
F00BF328: d0062124                 ld      [%i0+0x124], %o0! id
F00BF32C: 133c0504                 sethi   %hi(paLock), %o1! SEL
F00BF330: 4000c950                 call    _objc_msgSend
F00BF334: d2026000                 ld      [%o1+%lo(paLock)], %o1
F00BF338: d04e2154                 ldsb    [%i0+0x154], %o0
F00BF33C: 80a22000                 cmp     %o0, 0
F00BF340: 02800029                 be      loc_F00BF3E4
F00BF344: 90102001                 mov     1, %o0
F00BF348: c02e2154                 clrb    [%i0+0x154]
F00BF34C: d2062160                 ld      [%i0+0x160], %o1
F00BF350: 80a26000                 cmp     %o1, 0
F00BF354: 12800006                 bne     loc_F00BF36C
F00BF358: d02e214e                 stb     %o0, [%i0+0x14E]
F00BF35C: d0062164                 ld      [%i0+0x164], %o0
F00BF360: 80a22000                 cmp     %o0, 0
F00BF364: 0280001c                 be      loc_F00BF3D4
F00BF368: 113c0504                 sethi   -0xFEBF000, %o0
F00BF36C: d007bfe8                 ld      [%fp+var_18], %o0
F00BF370: 80a24008                 cmp     %o1, %o0
F00BF374: 38800018                 bgu,a   loc_F00BF3D4
F00BF378: 113c0504                 sethi   -0xFEBF000, %o0
F00BF37C: 32800008                 bne,a   loc_F00BF39C
F00BF380: d0062128                 ld      [%i0+0x128], %o0
F00BF384: d2062164                 ld      [%i0+0x164], %o1
F00BF388: d007bfec                 ld      [%fp+var_18+4], %o0
F00BF38C: 80a24008                 cmp     %o1, %o0
F00BF390: 38800011                 bgu,a   loc_F00BF3D4
F00BF394: 113c0504                 sethi   -0xFEBF000, %o0
F00BF398: d0062128                 ld      [%i0+0x128], %o0! id
F00BF39C: 133c0504                 sethi   %hi(paDokeyboardeven), %o1
F00BF3A0: d41fbfe8                 ldd     [%fp+var_18], %o2
F00BF3A4: 98062134                 add     %i0, 0x134, %o4
F00BF3A8: d202628c                 ld      [%o1+%lo(paDokeyboardeven)], %o1! SEL
F00BF3AC: d43e2158                 std     %o2, [%i0+0x158]
F00BF3B0: d4062150                 ld      [%i0+0x150], %o2
F00BF3B4: 4000c92f                 call    _objc_msgSend
F00BF3B8: 96102001                 mov     1, %o3
F00BF3BC: d01e2160                 ldd     [%i0+0x160], %o0
F00BF3C0: d41e2168                 ldd     [%i0+0x168], %o2
F00BF3C4: 9282400b                 addcc   %o1, %o3, %o1
F00BF3C8: 9042000a                 addc    %o0, %o2, %o0
F00BF3CC: d03e2160                 std     %o0, [%i0+0x160]
F00BF3D0: 113c0504                 sethi   -0xFEBF000, %o0! id
F00BF3D4: d2022290                 ld      [%o0+0x290], %o1! SEL
F00BF3D8: c02e214e                 clrb    [%i0+0x14E]
F00BF3DC: 4000c925                 call    _objc_msgSend
F00BF3E0: 90100018                 mov     %i0, %o0
F00BF3E4: d0062124                 ld      [%i0+0x124], %o0! id
F00BF3E8: 133c0504                 sethi   %hi(paUnlock), %o1! SEL
F00BF3EC: 4000c921                 call    _objc_msgSend
F00BF3F0: d2026244                 ld      [%o1+%lo(paUnlock)], %o1
F00BF3F4: 81c7e008                 ret
F00BF3F8: 81e80000                 restore
