F00ADFF0: 9de3bf40                 save    %sp, -0xC0, %sp
F00ADFF4: 80a6e001                 cmp     %i3, 1
F00ADFF8: 02800014                 be      loc_F00AE048
F00ADFFC: 90100018                 mov     %i0, %o0
F00AE000: 0a800007                 bcs     loc_F00AE01C
F00AE004: 80a6e002                 cmp     %i3, 2
F00AE008: 0280001b                 be      loc_F00AE074
F00AE00C: 80a6e003                 cmp     %i3, 3
F00AE010: 2280002e                 be,a    loc_F00AE0C8
F00AE014: d0062008                 ld      [%i0+8], %o0
F00AE018: 3080008f                 ba,a    locret_F00AE254
F00AE01C: 92100019                 mov     %i1, %o1
F00AE020: a007bff4                 add     %fp, var_C, %l0
F00AE024: 7ffffdbd                 call    sub_F00AD718
F00AE028: 94100010                 mov     %l0, %o2
F00AE02C: d206200c                 ld      [%i0+0xC], %o1
F00AE030: d0060000                 ld      [%i0], %o0
F00AE034: 808a4008                 btst    %o0, %o1
F00AE038: 12800087                 bne     locret_F00AE254
F00AE03C: 90100010                 mov     %l0, %o0
F00AE040: 10800082                 ba      loc_F00AE248
F00AE044: 9210001a                 mov     %i2, %o1
F00AE048: 92100019                 mov     %i1, %o1
F00AE04C: a007bff0                 add     %fp, var_10, %l0
F00AE050: 7ffffdf0                 call    sub_F00AD810
F00AE054: 94100010                 mov     %l0, %o2
F00AE058: d206200c                 ld      [%i0+0xC], %o1
F00AE05C: d0060000                 ld      [%i0], %o0
F00AE060: 808a4008                 btst    %o0, %o1
F00AE064: 1280007c                 bne     locret_F00AE254
F00AE068: 90100010                 mov     %l0, %o0
F00AE06C: 10800077                 ba      loc_F00AE248
F00AE070: 9210001a                 mov     %i2, %o1
F00AE074: 92100019                 mov     %i1, %o1
F00AE078: a007bfec                 add     %fp, var_14, %l0
F00AE07C: 94100010                 mov     %l0, %o2
F00AE080: b207bfe8                 add     %fp, var_18, %i1
F00AE084: 7ffffe8e                 call    sub_F00ADABC
F00AE088: 96100019                 mov     %i1, %o3
F00AE08C: d206200c                 ld      [%i0+0xC], %o1
F00AE090: d0060000                 ld      [%i0], %o0
F00AE094: 808a4008                 btst    %o0, %o1
F00AE098: 1280006f                 bne     locret_F00AE254
F00AE09C: 90100010                 mov     %l0, %o0
F00AE0A0: 2100003fa01423fe         set     0xFFFE, %l0
F00AE0A8: a00e8010                 and     %i2, %l0, %l0
F00AE0AC: 92100010                 mov     %l0, %o1
F00AE0B0: d6062018                 ld      [%i0+0x18], %o3
F00AE0B4: 9fc2c000                 call    %o3
F00AE0B8: 94100018                 mov     %i0, %o2
F00AE0BC: 90100019                 mov     %i1, %o0
F00AE0C0: 10800062                 ba      loc_F00AE248
F00AE0C4: 92042001                 add     %l0, 1, %o1
F00AE0C8: 80a22002                 cmp     %o0, 2
F00AE0CC: 22800019                 be,a    loc_F00AE130
F00AE0D0: 90100018                 mov     %i0, %o0
F00AE0D4: 18800006                 bgu     loc_F00AE0EC
F00AE0D8: 80a22001                 cmp     %o0, 1
F00AE0DC: 02800009                 be      loc_F00AE100
F00AE0E0: 90100018                 mov     %i0, %o0
F00AE0E4: 10800038                 ba      loc_F00AE1C4
F00AE0E8: 92100019                 mov     %i1, %o1
F00AE0EC: 80a22003                 cmp     %o0, 3
F00AE0F0: 2280001e                 be,a    loc_F00AE168
F00AE0F4: d2066008                 ld      [%i1+8], %o1
F00AE0F8: 10800032                 ba      loc_F00AE1C0
F00AE0FC: 90100018                 mov     %i0, %o0
F00AE100: 92100019                 mov     %i1, %o1
F00AE104: 7ffffdc3                 call    sub_F00AD810
F00AE108: 9407bfbc                 add     %fp, var_44, %o2
F00AE10C: b207bfc0                 add     %fp, var_40, %i1
F00AE110: 90100018                 mov     %i0, %o0
F00AE114: 92100019                 mov     %i1, %o1
F00AE118: d607bfbc                 ld      [%fp+var_44], %o3
F00AE11C: 9407bfb8                 add     %fp, var_48, %o2
F00AE120: 40000072                 call    _unpacksingle
F00AE124: d627bfb8                 st      %o3, [%fp+var_48]
F00AE128: 10800026                 ba      loc_F00AE1C0
F00AE12C: 90100018                 mov     %i0, %o0
F00AE130: 92100019                 mov     %i1, %o1
F00AE134: 9407bfb4                 add     %fp, var_4C, %o2
F00AE138: 7ffffe61                 call    sub_F00ADABC
F00AE13C: 9607bfb0                 add     %fp, var_50, %o3
F00AE140: b207bfc0                 add     %fp, var_40, %i1
F00AE144: 90100018                 mov     %i0, %o0
F00AE148: 92100019                 mov     %i1, %o1
F00AE14C: d807bfb4                 ld      [%fp+var_4C], %o4
F00AE150: 9407bfb8                 add     %fp, var_48, %o2
F00AE154: d607bfb0                 ld      [%fp+var_50], %o3
F00AE158: 400000a4                 call    _unpackdouble
F00AE15C: d827bfb8                 st      %o4, [%fp+var_48]
F00AE160: 10800018                 ba      loc_F00AE1C0
F00AE164: 90100018                 mov     %i0, %o0
F00AE168: 1100000f901223ff         set     0x3FFF, %o0
F00AE170: a0824008                 addcc   %o1, %o0, %l0
F00AE174: 0c800004                 bneg    loc_F00AE184
F00AE178: 90102031                 mov     0x31, %o0 ! '1'
F00AE17C: 10800003                 ba      loc_F00AE188
F00AE180: a0102031                 mov     0x31, %l0 ! '1'
F00AE184: a0220010                 sub     %o0, %l0, %l0
F00AE188: 90100019                 mov     %i1, %o0
F00AE18C: 400001f5                 call    _fpu_rightshift
F00AE190: 92102031                 mov     0x31, %o1 ! '1'
F00AE194: 90100018                 mov     %i0, %o0
F00AE198: 7ffffd18                 call    sub_F00AD5F8
F00AE19C: 92100019                 mov     %i1, %o1
F00AE1A0: c026601c                 clr     [%i1+0x1C]
F00AE1A4: c0266020                 clr     [%i1+0x20]
F00AE1A8: d2066008                 ld      [%i1+8], %o1
F00AE1AC: 90100019                 mov     %i1, %o0
F00AE1B0: 92024010                 add     %o1, %l0, %o1
F00AE1B4: 40000189                 call    _fpu_normalize
F00AE1B8: d2266008                 st      %o1, [%i1+8]
F00AE1BC: 90100018                 mov     %i0, %o0
F00AE1C0: 92100019                 mov     %i1, %o1
F00AE1C4: a007bfac                 add     %fp, var_54, %l0
F00AE1C8: 94100010                 mov     %l0, %o2
F00AE1CC: b207bfa8                 add     %fp, var_58, %i1
F00AE1D0: 96100019                 mov     %i1, %o3
F00AE1D4: b607bfa4                 add     %fp, var_5C, %i3
F00AE1D8: a207bfa0                 add     %fp, var_60, %l1
F00AE1DC: 9810001b                 mov     %i3, %o4
F00AE1E0: 7ffffeee                 call    sub_F00ADD98
F00AE1E4: 9a100011                 mov     %l1, %o5
F00AE1E8: d206200c                 ld      [%i0+0xC], %o1
F00AE1EC: d0060000                 ld      [%i0], %o0
F00AE1F0: 808a4008                 btst    %o0, %o1
F00AE1F4: 12800018                 bne     locret_F00AE254
F00AE1F8: 90100010                 mov     %l0, %o0
F00AE1FC: 2100003fa01423fc         set     0xFFFC, %l0
F00AE204: a00e8010                 and     %i2, %l0, %l0
F00AE208: 92100010                 mov     %l0, %o1
F00AE20C: d6062018                 ld      [%i0+0x18], %o3
F00AE210: 9fc2c000                 call    %o3
F00AE214: 94100018                 mov     %i0, %o2
F00AE218: 90100019                 mov     %i1, %o0
F00AE21C: 92042001                 add     %l0, 1, %o1
F00AE220: d6062018                 ld      [%i0+0x18], %o3
F00AE224: 9fc2c000                 call    %o3
F00AE228: 94100018                 mov     %i0, %o2
F00AE22C: 9010001b                 mov     %i3, %o0
F00AE230: 92042002                 add     %l0, 2, %o1
F00AE234: d6062018                 ld      [%i0+0x18], %o3
F00AE238: 9fc2c000                 call    %o3
F00AE23C: 94100018                 mov     %i0, %o2
F00AE240: 90100011                 mov     %l1, %o0
F00AE244: 92042003                 add     %l0, 3, %o1
F00AE248: d6062018                 ld      [%i0+0x18], %o3
F00AE24C: 9fc2c000                 call    %o3
F00AE250: 94100018                 mov     %i0, %o2
F00AE254: 81c7e008                 ret
F00AE258: 81e80000                 restore
