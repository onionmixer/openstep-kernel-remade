F0027010: 9de3be68                 save    %sp, -0x198, %sp
F0027014: a2100018                 mov     %i0, %l1
F0027018: b0102000                 mov     0, %i0
F002701C: 4000009f                 call    _pn_alloc
F0027020: 9010001b                 mov     %i3, %o0
F0027024: 90100019                 mov     %i1, %o0
F0027028: 7ffffa60                 call    _dnlc_lookupSymLink
F002702C: 9210001a                 mov     %i2, %o1
F0027030: a0920000                 orcc    %o0, %g0, %l0
F0027034: 2280000d                 be,a    loc_F0027068
F0027038: d006c000                 ld      [%i3], %o0
F002703C: d04c2044                 ldsb    [%l0+0x44], %o0
F0027040: 80a22000                 cmp     %o0, 0
F0027044: 22800009                 be,a    loc_F0027068
F0027048: d006c000                 ld      [%i3], %o0
F002704C: d0042040                 ld      [%l0+0x40], %o0! void *
F0027050: d206c000                 ld      [%i3], %o1! void *
F0027054: 4001b6af                 call    _bcopy
F0027058: d4542046                 ldsh    [%l0+0x46], %o2
F002705C: d0542046                 ldsh    [%l0+0x46], %o0
F0027060: 1080001e                 ba      loc_F00270D8
F0027064: d026e008                 st      %o0, [%i3+8]
F0027068: a0102400                 mov     0x400, %l0
F002706C: d027bff0                 st      %o0, [%fp+var_10]
F0027070: e027bff4                 st      %l0, [%fp+var_C]
F0027074: 9007bff0                 add     %fp, var_10, %o0
F0027078: d027bfd8                 st      %o0, [%fp+var_28]
F002707C: 90102001                 mov     1, %o0
F0027080: d027bfdc                 st      %o0, [%fp+var_24]
F0027084: c027bfe0                 clr     [%fp+var_20]
F0027088: d027bfe4                 st      %o0, [%fp+var_1C]
F002708C: 113c04cf                 sethi   %hi(_active_u), %o0
F0027090: d00221d8                 ld      [%o0+%lo(_active_u)], %o0
F0027094: e027bfec                 st      %l0, [%fp+var_14]
F0027098: d204601c                 ld      [%l1+0x1C], %o1
F002709C: d402201c                 ld      [%o0+0x1C], %o2
F00270A0: d6026044                 ld      [%o1+0x44], %o3
F00270A4: 90100011                 mov     %l1, %o0
F00270A8: 9fc2c000                 call    %o3
F00270AC: 9207bfd8                 add     %fp, var_28, %o1
F00270B0: b0100008                 mov     %o0, %i0
F00270B4: d007bfec                 ld      [%fp+var_14], %o0
F00270B8: 80a62000                 cmp     %i0, 0
F00270BC: a0240008                 sub     %l0, %o0, %l0
F00270C0: 12800072                 bne     loc_F0027288
F00270C4: e026e008                 st      %l0, [%i3+8]
F00270C8: 90100019                 mov     %i1, %o0
F00270CC: 9210001a                 mov     %i2, %o1
F00270D0: 7ffffa4c                 call    _dnlc_enterSymLink
F00270D4: 9410001b                 mov     %i3, %o2
F00270D8: d206c000                 ld      [%i3], %o1
F00270DC: d006e008                 ld      [%i3+8], %o0
F00270E0: c02a4008                 clrb    [%o1+%o0]
F00270E4: d206c000                 ld      [%i3], %o1! int
F00270E8: 90100009                 mov     %o1, %o0! char *
F00270EC: 7fff7857                 call    _index
F00270F0: 92102024                 mov     0x24, %o1 ! '$'
F00270F4: 92920000                 orcc    %o0, %g0, %o1
F00270F8: 02800062                 be      loc_F0027280
F00270FC: 80a62000                 cmp     %i0, 0
F0027100: d006c000                 ld      [%i3], %o0
F0027104: 80a24008                 cmp     %o1, %o0
F0027108: 02800008                 be      loc_F0027128
F002710C: 80a26000                 cmp     %o1, 0
F0027110: d04a7fff                 ldsb    [%o1-1], %o0
F0027114: 80a2202f                 cmp     %o0, 0x2F ! '/'
F0027118: 02800004                 be      loc_F0027128
F002711C: 80a26000                 cmp     %o1, 0
F0027120: 10bffff2                 ba      loc_F00270E8
F0027124: 92026001                 inc     %o1
F0027128: 02800056                 be      loc_F0027280
F002712C: 80a62000                 cmp     %i0, 0
F0027130: 4000005a                 call    _pn_alloc
F0027134: 9007bfc8                 add     %fp, var_38, %o0
F0027138: d006e008                 ld      [%i3+8], %o0
F002713C: 80a22000                 cmp     %o0, 0
F0027140: 02800048                 be      loc_F0027260
F0027144: 80a62000                 cmp     %i0, 0
F0027148: b207bec8                 add     %fp, var_138, %i1
F002714C: 233c0430                 sethi   -0xFEF4000, %l1
F0027150: d006e008                 ld      [%i3+8], %o0
F0027154: 80a22000                 cmp     %o0, 0
F0027158: 02800011                 be      loc_F002719C
F002715C: 9010001b                 mov     %i3, %o0
F0027160: d006e004                 ld      [%i3+4], %o0
F0027164: d04a0000                 ldsb    [%o0], %o0
F0027168: 80a2202f                 cmp     %o0, 0x2F ! '/'
F002716C: 1280000c                 bne     loc_F002719C
F0027170: 9010001b                 mov     %i3, %o0
F0027174: 9007bfc8                 add     %fp, var_38, %o0
F0027178: 133c0430                 sethi   %hi(unk_F010C140), %o1
F002717C: 40000099                 call    _pn_append
F0027180: 92126140                 bset    %lo(unk_F010C140), %o1
F0027184: b0920000                 orcc    %o0, %g0, %i0
F0027188: 1280003b                 bne     loc_F0027274
F002718C: d207bfc8                 ld      [%fp+var_38], %o1
F0027190: 400000c4                 call    _pn_skipslash
F0027194: 9010001b                 mov     %i3, %o0
F0027198: 9010001b                 mov     %i3, %o0
F002719C: 400000a7                 call    _pn_getcomponent
F00271A0: 92100019                 mov     %i1, %o1
F00271A4: b0920000                 orcc    %o0, %g0, %i0
F00271A8: 1280002e                 bne     loc_F0027260
F00271AC: d04fbec8                 ldsb    [%fp+var_138], %o0
F00271B0: 80a22024                 cmp     %o0, 0x24 ! '$'
F00271B4: 1280001f                 bne     loc_F0027230
F00271B8: 9007bfc8                 add     %fp, var_38, %o0
F00271BC: d0046100                 ld      [%l1+0x100], %o0! __s1
F00271C0: 80a22000                 cmp     %o0, 0
F00271C4: 0280000d                 be      loc_F00271F8
F00271C8: a0146100                 or      %l1, 0x100, %l0
F00271CC: d2040000                 ld      [%l0], %o1! __s2
F00271D0: 7fff83f7                 call    _strcmp
F00271D4: 9007bec9                 add     %fp, var_137, %o0
F00271D8: 80a22000                 cmp     %o0, 0
F00271DC: 22800008                 be,a    loc_F00271FC
F00271E0: d0040000                 ld      [%l0], %o0
F00271E4: a004200c                 inc     0xC, %l0
F00271E8: d0040000                 ld      [%l0], %o0
F00271EC: 80a22000                 cmp     %o0, 0
F00271F0: 32bffff8                 bne,a   loc_F00271D0
F00271F4: d2040000                 ld      [%l0], %o1
F00271F8: d0040000                 ld      [%l0], %o0
F00271FC: 80a22000                 cmp     %o0, 0
F0027200: 22800017                 be,a    loc_F002725C
F0027204: b0102002                 mov     2, %i0
F0027208: d2042004                 ld      [%l0+4], %o1
F002720C: d04a4000                 ldsb    [%o1], %o0
F0027210: 80a22000                 cmp     %o0, 0
F0027214: 12800008                 bne     loc_F0027234
F0027218: 9007bfc8                 add     %fp, var_38, %o0
F002721C: d2042008                 ld      [%l0+8], %o1
F0027220: 80a26000                 cmp     %o1, 0
F0027224: 12800004                 bne     loc_F0027234
F0027228: b0102002                 mov     2, %i0
F002722C: 30800005                 ba,a    loc_F0027240
F0027230: 92100019                 mov     %i1, %o1
F0027234: 4000006b                 call    _pn_append
F0027238: 01000000                 nop
F002723C: b0100008                 mov     %o0, %i0
F0027240: 80a62000                 cmp     %i0, 0
F0027244: 1280000c                 bne     loc_F0027274
F0027248: d207bfc8                 ld      [%fp+var_38], %o1
F002724C: d006e008                 ld      [%i3+8], %o0
F0027250: 80a22000                 cmp     %o0, 0
F0027254: 12bfffbf                 bne     loc_F0027150
F0027258: 01000000                 nop
F002725C: 80a62000                 cmp     %i0, 0
F0027260: 12800005                 bne     loc_F0027274
F0027264: d207bfc8                 ld      [%fp+var_38], %o1
F0027268: 40000039                 call    _pn_set
F002726C: 9010001b                 mov     %i3, %o0
F0027270: b0100008                 mov     %o0, %i0
F0027274: 4000009d                 call    _pn_free
F0027278: 9007bfc8                 add     %fp, var_38, %o0
F002727C: 80a62000                 cmp     %i0, 0
F0027280: 02800004                 be      locret_F0027290
F0027284: 01000000                 nop
F0027288: 40000098                 call    _pn_free
F002728C: 9010001b                 mov     %i3, %o0
F0027290: 81c7e008                 ret
F0027294: 81e80000                 restore
