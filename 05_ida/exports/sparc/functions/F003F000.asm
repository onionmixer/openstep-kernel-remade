F003F000: 9de3bf40                 save    %sp, -0xC0, %sp
F003F004: ac102000                 mov     0, %l6
F003F008: d2066014                 ld      [%i1+0x14], %o1
F003F00C: 80a26000                 cmp     %o1, 0
F003F010: 12800004                 bne     loc_F003F020
F003F014: b6102000                 mov     0, %i3
F003F018: 108000f0                 ba      locret_F003F3D8
F003F01C: b0102000                 mov     0, %i0
F003F020: d0066008                 ld      [%i1+8], %o0
F003F024: 80a22000                 cmp     %o0, 0
F003F028: 06800004                 bl      loc_F003F038
F003F02C: 94820009                 addcc   %o0, %o1, %o2
F003F030: 1c800004                 bpos    loc_F003F040
F003F034: 80a6a001                 cmp     %i2, 1
F003F038: 108000e8                 ba      locret_F003F3D8
F003F03C: b0102016                 mov     0x16, %i0
F003F040: 3280001b                 bne,a   loc_F003F0AC
F003F044: e6062030                 ld      [%i0+0x30], %l3
F003F048: d0062028                 ld      [%i0+0x28], %o0
F003F04C: 80a22001                 cmp     %o0, 1
F003F050: 32800017                 bne,a   loc_F003F0AC
F003F054: e6062030                 ld      [%i0+0x30], %l3
F003F058: 113c04cf                 sethi   %hi(_active_u), %o0
F003F05C: d20221d8                 ld      [%o0+%lo(_active_u)], %o1! char *
F003F060: d0026268                 ld      [%o1+0x268], %o0
F003F064: 80a28008                 cmp     %o2, %o0
F003F068: 28800011                 bleu,a  loc_F003F0AC
F003F06C: e6062030                 ld      [%i0+0x30], %l3
F003F070: d0024000                 ld      [%o1], %o0! unsigned int
F003F074: 7fff4940                 call    _psignal
F003F078: 92102019                 mov     0x19, %o1
F003F07C: 108000d7                 ba      locret_F003F3D8
F003F080: b010201b                 mov     0x1B, %i0
F003F084: 108000d2                 ba      loc_F003F3CC
F003F088: ac100008                 mov     %o0, %l6
F003F08C: 7fff9945                 call    _geterror
F003F090: 90100010                 mov     %l0, %o0
F003F094: 1080003f                 ba      loc_F003F190
F003F098: ac100008                 mov     %o0, %l6
F003F09C: 7fff95f3                 call    _brelse
F003F0A0: 90100010                 mov     %l0, %o0
F003F0A4: 108000ca                 ba      loc_F003F3CC
F003F0A8: ac102000                 mov     0, %l6
F003F0AC: 7ffff95e                 call    _rlock
F003F0B0: 90100013                 mov     %l3, %o0
F003F0B4: d0062024                 ld      [%i0+0x24], %o0
F003F0B8: d0022128                 ld      [%o0+0x128], %o0
F003F0BC: e2022024                 ld      [%o0+0x24], %l1
F003F0C0: a28c7c00                 andcc   %l1, -0x400, %l1
F003F0C4: 14800006                 bg      loc_F003F0DC
F003F0C8: ae07bfb4                 add     %fp, var_4C, %l7
F003F0CC: 113c0435                 sethi   %hi(aRwvpZeroSize), %o0! "rwvp: zero size"
F003F0D0: 7fff5828                 call    _panic
F003F0D4: 90122258                 bset    %lo(aRwvpZeroSize), %o0! "rwvp: zero size"
F003F0D8: ae07bfb4                 add     %fp, var_4C, %l7
F003F0DC: 3b3c04cf                 sethi   -0xFECC400, %i5
F003F0E0: e0066008                 ld      [%i1+8], %l0
F003F0E4: 92100011                 mov     %l1, %o1
F003F0E8: 7fff1d46                 call    _udiv
F003F0EC: 90100010                 mov     %l0, %o0
F003F0F0: a8100008                 mov     %o0, %l4
F003F0F4: 90100010                 mov     %l0, %o0
F003F0F8: 7fff1dea                 call    _urem
F003F0FC: 92100011                 mov     %l1, %o1
F003F100: aa100008                 mov     %o0, %l5
F003F104: d0066014                 ld      [%i1+0x14], %o0
F003F108: 92244015                 sub     %l1, %l5, %o1
F003F10C: 80a24008                 cmp     %o1, %o0
F003F110: 1a800003                 bcc     loc_F003F11C
F003F114: a4100008                 mov     %o0, %l2
F003F118: a4100009                 mov     %o1, %l2
F003F11C: 90100018                 mov     %i0, %o0
F003F120: d606201c                 ld      [%i0+0x1C], %o3
F003F124: 92100014                 mov     %l4, %o1
F003F128: d802e050                 ld      [%o3+0x50], %o4
F003F12C: 94100017                 mov     %l7, %o2
F003F130: 9fc30000                 call    %o4
F003F134: 9607bfb0                 add     %fp, var_50, %o3
F003F138: d0162004                 lduh    [%i0+4], %o0
F003F13C: 808a2040                 btst    0x40, %o0 ! '@'
F003F140: 02800017                 be      loc_F003F19C
F003F144: 80a6a000                 cmp     %i2, 0
F003F148: 7fff96c0                 call    _geteblk
F003F14C: 90100011                 mov     %l1, %o0
F003F150: 80a6a000                 cmp     %i2, 0
F003F154: 12800049                 bne     loc_F003F278
F003F158: a0100008                 mov     %o0, %l0
F003F15C: 90100018                 mov     %i0, %o0
F003F160: 96100012                 mov     %l2, %o3
F003F164: d2042020                 ld      [%l0+0x20], %o1
F003F168: 98042028                 add     %l0, 0x28, %o4 ! '('
F003F16C: d4066008                 ld      [%i1+8], %o2
F003F170: 9a07bfb8                 add     %fp, var_48, %o5
F003F174: da23a05c                 st      %o5, [%sp+0xC0+var_64]
F003F178: 92024015                 add     %o1, %l5, %o1! size_t
F003F17C: 4000010e                 call    sub_F003F5B4
F003F180: 9a10001c                 mov     %i4, %o5
F003F184: ac920000                 orcc    %o0, %g0, %l6
F003F188: 2280003d                 be,a    loc_F003F27C
F003F18C: d0040000                 ld      [%l0], %o0
F003F190: 7fff95b6                 call    _brelse
F003F194: 90100010                 mov     %l0, %o0
F003F198: 3080008d                 ba,a    loc_F003F3CC
F003F19C: 32800029                 bne,a   loc_F003F240
F003F1A0: d054e062                 ldsh    [%l3+0x62], %o0
F003F1A4: 80a52000                 cmp     %l4, 0
F003F1A8: 1680000a                 bge     loc_F003F1D0
F003F1AC: d007bfb4                 ld      [%fp+var_4C], %o0
F003F1B0: 7fff96a6                 call    _geteblk
F003F1B4: 90100011                 mov     %l1, %o0
F003F1B8: a0100008                 mov     %o0, %l0
F003F1BC: d0042020                 ld      [%l0+0x20], %o0! void *
F003F1C0: 40015726                 call    _bzero
F003F1C4: d2042014                 ld      [%l0+0x14], %o1
F003F1C8: 1080002c                 ba      loc_F003F278
F003F1CC: c0242028                 clr     [%l0+0x28]
F003F1D0: 7fff95ff                 call    _incore
F003F1D4: d207bfb0                 ld      [%fp+var_50], %o1
F003F1D8: 80a22000                 cmp     %o0, 0
F003F1DC: 02800005                 be      loc_F003F1F0
F003F1E0: d007bfb4                 ld      [%fp+var_4C], %o0
F003F1E4: 9210001c                 mov     %i4, %o1
F003F1E8: 7fffe908                 call    _nfs_validate_caches
F003F1EC: 94102000                 mov     0, %o2
F003F1F0: d204e064                 ld      [%l3+0x64], %o1
F003F1F4: 90026001                 add     %o1, 1, %o0
F003F1F8: 80a20014                 cmp     %o0, %l4
F003F1FC: 1280001b                 bne     loc_F003F268
F003F200: d007bfb4                 ld      [%fp+var_4C], %o0
F003F204: 90100018                 mov     %i0, %o0
F003F208: d606201c                 ld      [%i0+0x1C], %o3
F003F20C: 92026002                 inc     2, %o1
F003F210: d802e050                 ld      [%o3+0x50], %o4
F003F214: 94100017                 mov     %l7, %o2
F003F218: 9fc30000                 call    %o4
F003F21C: 9607bfac                 add     %fp, var_54, %o3
F003F220: d007bfb4                 ld      [%fp+var_4C], %o0
F003F224: d207bfb0                 ld      [%fp+var_50], %o1
F003F228: 94100011                 mov     %l1, %o2
F003F22C: d607bfac                 ld      [%fp+var_54], %o3
F003F230: 7fff94ea                 call    _breada
F003F234: 98100011                 mov     %l1, %o4
F003F238: 10800010                 ba      loc_F003F278
F003F23C: a0100008                 mov     %o0, %l0
F003F240: 80a22000                 cmp     %o0, 0
F003F244: 12bfff90                 bne     loc_F003F084
F003F248: 80a48011                 cmp     %l2, %l1
F003F24C: 12800007                 bne     loc_F003F268
F003F250: d007bfb4                 ld      [%fp+var_4C], %o0
F003F254: d207bfb0                 ld      [%fp+var_50], %o1
F003F258: 7fff9604                 call    _getblk
F003F25C: 94100011                 mov     %l1, %o2
F003F260: 10800006                 ba      loc_F003F278
F003F264: a0100008                 mov     %o0, %l0
F003F268: d207bfb0                 ld      [%fp+var_50], %o1
F003F26C: 7fff94ad                 call    _bread
F003F270: 94100011                 mov     %l1, %o2
F003F274: a0100008                 mov     %o0, %l0
F003F278: d0040000                 ld      [%l0], %o0
F003F27C: 808a2004                 btst    4, %o0
F003F280: 12bfff83                 bne     loc_F003F08C
F003F284: 80a6a000                 cmp     %i2, 0
F003F288: 1280000e                 bne     loc_F003F2C0
F003F28C: 92100012                 mov     %l2, %o1
F003F290: d204e098                 ld      [%l3+0x98], %o1
F003F294: e824e064                 st      %l4, [%l3+0x64]
F003F298: d0066008                 ld      [%i1+8], %o0
F003F29C: 92224008                 sub     %o1, %o0, %o1
F003F2A0: 80a26000                 cmp     %o1, 0
F003F2A4: 04bfff7e                 ble     loc_F003F09C
F003F2A8: 80a24012                 cmp     %o1, %l2
F003F2AC: 36800005                 bge,a   loc_F003F2C0
F003F2B0: 92100012                 mov     %l2, %o1
F003F2B4: a4100009                 mov     %o1, %l2
F003F2B8: b6102001                 mov     1, %i3
F003F2BC: 92100012                 mov     %l2, %o1
F003F2C0: 9410001a                 mov     %i2, %o2
F003F2C4: d0042020                 ld      [%l0+0x20], %o0
F003F2C8: 96100019                 mov     %i1, %o3
F003F2CC: 7fff4c13                 call    _uiomove
F003F2D0: 90020015                 add     %o0, %l5, %o0
F003F2D4: d20761dc                 ld      [%i5+0x1DC], %o1
F003F2D8: 80a6a000                 cmp     %i2, 0
F003F2DC: 02800019                 be      loc_F003F340
F003F2E0: d02a6038                 stb     %o0, [%o1+0x38]
F003F2E4: d004e098                 ld      [%l3+0x98], %o0
F003F2E8: d2066008                 ld      [%i1+8], %o1
F003F2EC: 80a20009                 cmp     %o0, %o1
F003F2F0: 3a800009                 bcc,a   loc_F003F314
F003F2F4: d0162004                 lduh    [%i0+4], %o0
F003F2F8: d224e098                 st      %o1, [%l3+0x98]
F003F2FC: d4060000                 ld      [%i0], %o2
F003F300: d002a014                 ld      [%o2+0x14], %o0
F003F304: 80a24008                 cmp     %o1, %o0
F003F308: 38800002                 bgu,a   loc_F003F310
F003F30C: d222a014                 st      %o1, [%o2+0x14]
F003F310: d0162004                 lduh    [%i0+4], %o0
F003F314: 808a2040                 btst    0x40, %o0 ! '@'
F003F318: 0280000e                 be      loc_F003F350
F003F31C: 90100018                 mov     %i0, %o0
F003F320: 96100012                 mov     %l2, %o3
F003F324: d2042020                 ld      [%l0+0x20], %o1
F003F328: 9810001c                 mov     %i4, %o4
F003F32C: d4066008                 ld      [%i1+8], %o2
F003F330: 92024015                 add     %o1, %l5, %o1
F003F334: 4000002b                 call    _nfswrite
F003F338: 9422800b                 sub     %o2, %o3, %o2
F003F33C: ac100008                 mov     %o0, %l6
F003F340: 7fff954a                 call    _brelse
F003F344: 90100010                 mov     %l0, %o0
F003F348: 10800012                 ba      loc_F003F390
F003F34C: d00761dc                 ld      [%i5+0x1DC], %o0
F003F350: d214e060                 lduh    [%l3+0x60], %o1
F003F354: 90048015                 add     %l2, %l5, %o0
F003F358: 80a20011                 cmp     %o0, %l1
F003F35C: 92126010                 bset    0x10, %o1
F003F360: 12800009                 bne     loc_F003F384
F003F364: d234e060                 sth     %o1, [%l3+0x60]
F003F368: d2040000                 ld      [%l0], %o1
F003F36C: 90100010                 mov     %l0, %o0
F003F370: 92126080                 bset    0x80, %o1
F003F374: 7fff9535                 call    _bawrite
F003F378: d2220000                 st      %o1, [%o0]
F003F37C: 10800005                 ba      loc_F003F390
F003F380: d00761dc                 ld      [%i5+0x1DC], %o0
F003F384: 7fff9520                 call    _bdwrite
F003F388: 90100010                 mov     %l0, %o0
F003F38C: d00761dc                 ld      [%i5+0x1DC], %o0
F003F390: d04a2038                 ldsb    [%o0+0x38], %o0
F003F394: 80a22000                 cmp     %o0, 0
F003F398: 12800009                 bne     loc_F003F3BC
F003F39C: 80a5a000                 cmp     %l6, 0
F003F3A0: d0066014                 ld      [%i1+0x14], %o0
F003F3A4: 80a22000                 cmp     %o0, 0
F003F3A8: 04800004                 ble     loc_F003F3B8
F003F3AC: 80a6e000                 cmp     %i3, 0
F003F3B0: 22bfff4d                 be,a    loc_F003F0E4
F003F3B4: e0066008                 ld      [%i1+8], %l0
F003F3B8: 80a5a000                 cmp     %l6, 0
F003F3BC: 12800004                 bne     loc_F003F3CC
F003F3C0: 113c04cf                 sethi   %hi(dword_F0133DDC), %o0
F003F3C4: d00221dc                 ld      [%o0+%lo(dword_F0133DDC)], %o0
F003F3C8: ec4a2038                 ldsb    [%o0+0x38], %l6
F003F3CC: 7ffff8b4                 call    _runlock
F003F3D0: 90100013                 mov     %l3, %o0
F003F3D4: b0100016                 mov     %l6, %i0
F003F3D8: 81c7e008                 ret
F003F3DC: 81e80000                 restore
