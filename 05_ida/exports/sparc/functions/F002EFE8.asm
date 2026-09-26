F002EFE8: 9de3bf70                 save    %sp, -0x90, %sp
F002EFEC: 40019ef3                 call    _spltty
F002EFF0: e006a004                 ld      [%i2+4], %l0
F002EFF4: d2164000                 lduh    [%i1], %o1
F002EFF8: d237bfe8                 sth     %o1, [%fp+var_18]
F002EFFC: d2166002                 lduh    [%i1+2], %o1
F002F000: d237bfea                 sth     %o1, [%fp+var_16]
F002F004: d2166004                 lduh    [%i1+4], %o1
F002F008: d237bfec                 sth     %o1, [%fp+var_14]
F002F00C: d2166006                 lduh    [%i1+6], %o1
F002F010: d237bfee                 sth     %o1, [%fp+var_12]
F002F014: d2166008                 lduh    [%i1+8], %o1
F002F018: d237bff0                 sth     %o1, [%fp+var_10]
F002F01C: d216600a                 lduh    [%i1+0xA], %o1
F002F020: d237bff2                 sth     %o1, [%fp+var_E]
F002F024: d216600c                 lduh    [%i1+0xC], %o1
F002F028: d237bff4                 sth     %o1, [%fp+var_C]
F002F02C: d216600e                 lduh    [%i1+0xE], %o1
F002F030: d237bff6                 sth     %o1, [%fp+var_A]
F002F034: d2168000                 lduh    [%i2], %o1
F002F038: d2364000                 sth     %o1, [%i1]
F002F03C: d216a002                 lduh    [%i2+2], %o1
F002F040: d2366002                 sth     %o1, [%i1+2]
F002F044: d216a004                 lduh    [%i2+4], %o1
F002F048: d2366004                 sth     %o1, [%i1+4]
F002F04C: d216a006                 lduh    [%i2+6], %o1
F002F050: d2366006                 sth     %o1, [%i1+6]
F002F054: d216a008                 lduh    [%i2+8], %o1
F002F058: d2366008                 sth     %o1, [%i1+8]
F002F05C: d216a00a                 lduh    [%i2+0xA], %o1
F002F060: d236600a                 sth     %o1, [%i1+0xA]
F002F064: d216a00c                 lduh    [%i2+0xC], %o1
F002F068: d236600c                 sth     %o1, [%i1+0xC]
F002F06C: d216a00e                 lduh    [%i2+0xE], %o1
F002F070: a2100018                 mov     %i0, %l1
F002F074: d236600e                 sth     %o1, [%i1+0xE]
F002F078: d2046038                 ld      [%l1+0x38], %o1
F002F07C: 80a26000                 cmp     %o1, 0
F002F080: 0280001d                 be      loc_F002F0F4
F002F084: a4100008                 mov     %o0, %l2
F002F088: 90100011                 mov     %l1, %o0
F002F08C: 1320081a9212610c         set     -0x7FDF96F4, %o1! size_t
F002F094: 7ffff2ef                 call    _if_ioctl
F002F098: 94100019                 mov     %i1, %o2
F002F09C: b0920000                 orcc    %o0, %g0, %i0
F002F0A0: 02800016                 be      loc_F002F0F8
F002F0A4: b407bfd8                 add     %fp, var_28, %i2
F002F0A8: 40019f1f                 call    _splx
F002F0AC: 90100012                 mov     %l2, %o0
F002F0B0: d017bfe8                 lduh    [%fp+var_18], %o0
F002F0B4: d0364000                 sth     %o0, [%i1]
F002F0B8: d017bfea                 lduh    [%fp+var_16], %o0
F002F0BC: d0366002                 sth     %o0, [%i1+2]
F002F0C0: d017bfec                 lduh    [%fp+var_14], %o0
F002F0C4: d0366004                 sth     %o0, [%i1+4]
F002F0C8: d017bfee                 lduh    [%fp+var_12], %o0
F002F0CC: d0366006                 sth     %o0, [%i1+6]
F002F0D0: d017bff0                 lduh    [%fp+var_10], %o0
F002F0D4: d0366008                 sth     %o0, [%i1+8]
F002F0D8: d017bff2                 lduh    [%fp+var_E], %o0
F002F0DC: d036600a                 sth     %o0, [%i1+0xA]
F002F0E0: d017bff4                 lduh    [%fp+var_C], %o0
F002F0E4: d036600c                 sth     %o0, [%i1+0xC]
F002F0E8: d017bff6                 lduh    [%fp+var_A], %o0
F002F0EC: 10800073                 ba      locret_F002F2B8
F002F0F0: d036600e                 sth     %o0, [%i1+0xE]
F002F0F4: b407bfd8                 add     %fp, var_28, %i2
F002F0F8: 9010001a                 mov     %i2, %o0! void *
F002F0FC: 40019757                 call    _bzero
F002F100: 92102010                 mov     0x10, %o1
F002F104: 90102002                 mov     2, %o0
F002F108: d037bfd8                 sth     %o0, [%fp+var_28]
F002F10C: d006603c                 ld      [%i1+0x3C], %o0
F002F110: 808a2001                 btst    1, %o0
F002F114: 22800022                 be,a    loc_F002F19C
F002F118: 13200000                 sethi   0x80000000, %o1
F002F11C: d014600c                 lduh    [%l1+0xC], %o0
F002F120: 808a2008                 btst    8, %o0
F002F124: 02800007                 be      loc_F002F140
F002F128: 15200c1c                 sethi   -0x7FCF9000, %o2
F002F12C: 9007bfe8                 add     %fp, var_18, %o0
F002F130: 92100008                 mov     %o0, %o1
F002F134: 9412a20b                 bset    0x20B, %o2
F002F138: 10800013                 ba      loc_F002F184
F002F13C: 96102004                 mov     4, %o3
F002F140: 808a2010                 btst    0x10, %o0
F002F144: 02800007                 be      loc_F002F160
F002F148: 90066010                 add     %i1, 0x10, %o0
F002F14C: 9207bfe8                 add     %fp, var_18, %o1
F002F150: 15200c1c9412a20b         set     -0x7FCF8DF5, %o2
F002F158: 1080000b                 ba      loc_F002F184
F002F15C: 96102004                 mov     4, %o3
F002F160: d0066030                 ld      [%i1+0x30], %o0
F002F164: 7ffffd56                 call    _in_makeaddr
F002F168: 92102000                 mov     0, %o1
F002F16C: d027bfdc                 st      %o0, [%fp+var_24]
F002F170: 9010001a                 mov     %i2, %o0
F002F174: 9207bfe8                 add     %fp, var_18, %o1
F002F178: 15200c1c9412a20b         set     -0x7FCF8DF5, %o2
F002F180: 96102000                 mov     0, %o3
F002F184: 7ffff8a7                 call    _rtinit
F002F188: 01000000                 nop
F002F18C: d006603c                 ld      [%i1+0x3C], %o0
F002F190: 900a3ffe                 and     %o0, -2, %o0
F002F194: d026603c                 st      %o0, [%i1+0x3C]
F002F198: 13200000                 sethi   0x80000000, %o1
F002F19C: 808c0009                 btst    %o1, %l0
F002F1A0: 12800004                 bne     loc_F002F1B0
F002F1A4: 11300000                 sethi   -0x40000000, %o0
F002F1A8: 10800007                 ba      loc_F002F1C4
F002F1AC: 113fc000                 sethi   -0x1000000, %o0
F002F1B0: 900c0008                 and     %l0, %o0, %o0
F002F1B4: 80a20009                 cmp     %o0, %o1
F002F1B8: 12800003                 bne     loc_F002F1C4
F002F1BC: 90103f00                 mov     -0x100, %o0
F002F1C0: 113fffc0                 sethi   -0x10000, %o0
F002F1C4: d026602c                 st      %o0, [%i1+0x2C]
F002F1C8: d006602c                 ld      [%i1+0x2C], %o0
F002F1CC: d2066034                 ld      [%i1+0x34], %o1
F002F1D0: d406602c                 ld      [%i1+0x2C], %o2
F002F1D4: 900c0008                 and     %l0, %o0, %o0
F002F1D8: d0266028                 st      %o0, [%i1+0x28]
F002F1DC: 9212400a                 bset    %o2, %o1
F002F1E0: d2266034                 st      %o1, [%i1+0x34]
F002F1E4: 920c0009                 and     %l0, %o1, %o1
F002F1E8: d2266030                 st      %o1, [%i1+0x30]
F002F1EC: d014600c                 lduh    [%l1+0xC], %o0
F002F1F0: 808a2002                 btst    2, %o0
F002F1F4: 0280000b                 be      loc_F002F220
F002F1F8: 90102002                 mov     2, %o0
F002F1FC: d0366010                 sth     %o0, [%i1+0x10]
F002F200: d0066030                 ld      [%i1+0x30], %o0
F002F204: 7ffffd2e                 call    _in_makeaddr
F002F208: 92103fff                 mov     -1, %o1
F002F20C: d206602c                 ld      [%i1+0x2C], %o1
F002F210: d4066028                 ld      [%i1+0x28], %o2
F002F214: d0266014                 st      %o0, [%i1+0x14]
F002F218: 92328009                 orn     %o2, %o1, %o1
F002F21C: d2266038                 st      %o1, [%i1+0x38]
F002F220: d014600c                 lduh    [%l1+0xC], %o0
F002F224: 808a2008                 btst    8, %o0
F002F228: 02800007                 be      loc_F002F244
F002F22C: 92100019                 mov     %i1, %o1
F002F230: 90100019                 mov     %i1, %o0
F002F234: 15200c1c9412a20a         set     -0x7FCF8DF6, %o2
F002F23C: 10800012                 ba      loc_F002F284
F002F240: 96102005                 mov     5, %o3
F002F244: 808a2010                 btst    0x10, %o0
F002F248: 02800006                 be      loc_F002F260
F002F24C: 15200c1c                 sethi   -0x7FCF9000, %o2
F002F250: 90066010                 add     %i1, 0x10, %o0
F002F254: 9412a20a                 bset    0x20A, %o2
F002F258: 1080000b                 ba      loc_F002F284
F002F25C: 96102005                 mov     5, %o3
F002F260: d0066030                 ld      [%i1+0x30], %o0
F002F264: 7ffffd16                 call    _in_makeaddr
F002F268: 92102000                 mov     0, %o1
F002F26C: d027bfdc                 st      %o0, [%fp+var_24]
F002F270: 9007bfd8                 add     %fp, var_28, %o0
F002F274: 92100019                 mov     %i1, %o1
F002F278: 15200c1c9412a20a         set     -0x7FCF8DF6, %o2
F002F280: 96102001                 mov     1, %o3
F002F284: 7ffff867                 call    _rtinit
F002F288: b0102000                 mov     0, %i0
F002F28C: 9007bfd4                 add     %fp, var_2C, %o0
F002F290: d406603c                 ld      [%i1+0x3C], %o2
F002F294: 92100011                 mov     %l1, %o1
F002F298: 9412a001                 bset    1, %o2
F002F29C: d426603c                 st      %o2, [%i1+0x3C]
F002F2A0: 153800009412a001         set     -0x1FFFFFFF, %o2
F002F2A8: 400000d7                 call    _in_addmulti
F002F2AC: d427bfd4                 st      %o2, [%fp+var_2C]
F002F2B0: 40019e9d                 call    _splx
F002F2B4: 90100012                 mov     %l2, %o0
F002F2B8: 81c7e008                 ret
F002F2BC: 81e80000                 restore
