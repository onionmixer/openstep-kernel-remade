F00EA000: 9de3bf90                 save    %sp, -0x70, %sp
F00EA004: 133c0504                 sethi   %hi(paDisplayinfo), %o1
F00EA008: d20263ac                 ld      [%o1+%lo(paDisplayinfo)], %o1! SEL
F00EA00C: 40001e19                 call    _objc_msgSend
F00EA010: 90100018                 mov     %i0, %o0! __s
F00EA014: 113c03f3a01220c0         set     aColorspace, %l0! "ColorSpace:"
F00EA01C: 7ffc7507                 call    _strlen
F00EA020: 90100010                 mov     %l0, %o0
F00EA024: d24e8000                 ldsb    [%i2], %o1
F00EA028: 80a26000                 cmp     %o1, 0
F00EA02C: 0280001c                 be      loc_F00EA09C
F00EA030: b0100008                 mov     %o0, %i0
F00EA034: 9010001a                 mov     %i2, %o0! __s1
F00EA038: 92100010                 mov     %l0, %o1! __s2
F00EA03C: 7ffc792b                 call    _strncmp
F00EA040: 94100018                 mov     %i0, %o2! __n
F00EA044: 80a22000                 cmp     %o0, 0
F00EA048: 32800011                 bne,a   loc_F00EA08C
F00EA04C: b406a001                 inc     %i2
F00EA050: 10800007                 ba      loc_F00EA06C
F00EA054: b4068018                 add     %i2, %i0, %i2
F00EA058: 02800004                 be      loc_F00EA068
F00EA05C: 80a22009                 cmp     %o0, 9
F00EA060: 12800008                 bne     loc_F00EA080
F00EA064: 80a00008                 cmp     %g0, %o0
F00EA068: b406a001                 inc     %i2
F00EA06C: d04e8000                 ldsb    [%i2], %o0
F00EA070: 80a22000                 cmp     %o0, 0
F00EA074: 12bffff9                 bne     loc_F00EA058
F00EA078: 80a22020                 cmp     %o0, 0x20 ! ' '
F00EA07C: 80a00008                 cmp     %g0, %o0
F00EA080: 90602000                 subc    %g0, 0, %o0
F00EA084: 10800007                 ba      loc_F00EA0A0
F00EA088: b40e8008                 and     %i2, %o0, %i2
F00EA08C: d04e8000                 ldsb    [%i2], %o0
F00EA090: 80a22000                 cmp     %o0, 0
F00EA094: 12bfffe9                 bne     loc_F00EA038
F00EA098: 9010001a                 mov     %i2, %o0
F00EA09C: b4102000                 mov     0, %i2
F00EA0A0: 80a6a000                 cmp     %i2, 0
F00EA0A4: 02800024                 be      loc_F00EA134
F00EA0A8: 9010001a                 mov     %i2, %o0! __s1
F00EA0AC: 133c03f3921260d0         set     aBw8, %o1! "BW:8"
F00EA0B4: 7ffc790d                 call    _strncmp
F00EA0B8: 94102004                 mov     4, %o2! __n
F00EA0BC: 80a22000                 cmp     %o0, 0
F00EA0C0: 12800004                 bne     loc_F00EA0D0
F00EA0C4: 9010001a                 mov     %i2, %o0! __s1
F00EA0C8: 1080001c                 ba      locret_F00EA138
F00EA0CC: b0102008                 mov     8, %i0
F00EA0D0: 133c03f3921260d8         set     aRgb2568, %o1! "RGB:256/8"
F00EA0D8: 7ffc7904                 call    _strncmp
F00EA0DC: 94102009                 mov     9, %o2! __n
F00EA0E0: 80a22000                 cmp     %o0, 0
F00EA0E4: 12800004                 bne     loc_F00EA0F4
F00EA0E8: 9010001a                 mov     %i2, %o0! __s1
F00EA0EC: 10800013                 ba      locret_F00EA138
F00EA0F0: b0102100                 mov     0x100, %i0
F00EA0F4: 133c03f3921260e8         set     aRgb88824, %o1! "RGB:888/24"
F00EA0FC: 7ffc78fb                 call    _strncmp
F00EA100: 94102009                 mov     9, %o2! __n
F00EA104: 80a22000                 cmp     %o0, 0
F00EA108: 02800009                 be      loc_F00EA12C
F00EA10C: 9010001a                 mov     %i2, %o0! __s1
F00EA110: 133c03f3921260f8         set     aRgb88832, %o1! "RGB:888/32"
F00EA118: 7ffc78f4                 call    _strncmp
F00EA11C: 94102009                 mov     9, %o2
F00EA120: 80a22000                 cmp     %o0, 0
F00EA124: 12800005                 bne     locret_F00EA138
F00EA128: b0102000                 mov     0, %i0
F00EA12C: 10800003                 ba      locret_F00EA138
F00EA130: b0102378                 mov     0x378, %i0
F00EA134: b0102000                 mov     0, %i0
F00EA138: 81c7e008                 ret
F00EA13C: 81e80000                 restore
