F0023F94: 9de3bf98                 save    %sp, -0x68, %sp
F0023F98: 40000083                 call    _vfs_lock
F0023F9C: 90100019                 mov     %i1, %o0
F0023FA0: 80a22000                 cmp     %o0, 0
F0023FA4: 02800004                 be      loc_F0023FB4
F0023FA8: 80a62000                 cmp     %i0, 0
F0023FAC: 10800043                 ba      locret_F00240B8
F0023FB0: b0100008                 mov     %o0, %i0
F0023FB4: 0280001a                 be      loc_F002401C
F0023FB8: 113c04d4                 sethi   -0xFECB000, %o0
F0023FBC: d006200c                 ld      [%i0+0xC], %o0
F0023FC0: 80a22000                 cmp     %o0, 0
F0023FC4: 02800006                 be      loc_F0023FDC
F0023FC8: 11000020                 sethi   0x8000, %o0
F0023FCC: 40000080                 call    _vfs_unlock
F0023FD0: 90100019                 mov     %i1, %o0
F0023FD4: 10800039                 ba      locret_F00240B8
F0023FD8: b0102010                 mov     0x10, %i0
F0023FDC: 808e8008                 btst    %o0, %i2
F0023FE0: 02800008                 be      loc_F0024000
F0023FE4: 90062014                 add     %i0, 0x14, %o0
F0023FE8: d2062010                 ld      [%i0+0x10], %o1
F0023FEC: d2266120                 st      %o1, [%i1+0x120]
F0023FF0: 40012978                 call    _microtime
F0023FF4: f2262010                 st      %i1, [%i0+0x10]
F0023FF8: 10800004                 ba      loc_F0024008
F0023FFC: 113c04d4                 sethi   -0xFECB000, %o0
F0024000: f226200c                 st      %i1, [%i0+0xC]
F0024004: 113c04d4                 sethi   -0xFECB000, %o0
F0024008: d2022160                 ld      [%o0+0x160], %o1
F002400C: d0024000                 ld      [%o1], %o0
F0024010: d0264000                 st      %o0, [%i1]
F0024014: 10800004                 ba      loc_F0024024
F0024018: f2224000                 st      %i1, [%o1]
F002401C: f2222160                 st      %i1, [%o0+0x160]
F0024020: c0264000                 clr     [%i1]
F0024024: 808ea001                 btst    1, %i2
F0024028: 02800005                 be      loc_F002403C
F002402C: f0266008                 st      %i0, [%i1+8]
F0024030: d006600c                 ld      [%i1+0xC], %o0
F0024034: 10800004                 ba      loc_F0024044
F0024038: 90122001                 bset    1, %o0
F002403C: d006600c                 ld      [%i1+0xC], %o0
F0024040: 900a3ffe                 and     %o0, -2, %o0
F0024044: 808ea002                 btst    2, %i2
F0024048: 02800005                 be      loc_F002405C
F002404C: d026600c                 st      %o0, [%i1+0xC]
F0024050: d006600c                 ld      [%i1+0xC], %o0
F0024054: 10800004                 ba      loc_F0024064
F0024058: 90122008                 bset    8, %o0
F002405C: d006600c                 ld      [%i1+0xC], %o0
F0024060: 900a3ff7                 and     %o0, -9, %o0
F0024064: 808ea008                 btst    8, %i2
F0024068: 02800005                 be      loc_F002407C
F002406C: d026600c                 st      %o0, [%i1+0xC]
F0024070: d006600c                 ld      [%i1+0xC], %o0
F0024074: 10800004                 ba      loc_F0024084
F0024078: 90122010                 bset    0x10, %o0
F002407C: d006600c                 ld      [%i1+0xC], %o0
F0024080: 900a3fef                 and     %o0, -0x11, %o0
F0024084: 808ea020                 btst    0x20, %i2 ! ' '
F0024088: 02800005                 be      loc_F002409C
F002408C: d026600c                 st      %o0, [%i1+0xC]
F0024090: d006600c                 ld      [%i1+0xC], %o0
F0024094: 10800004                 ba      loc_F00240A4
F0024098: 90122020                 bset    0x20, %o0 ! ' '
F002409C: d006600c                 ld      [%i1+0xC], %o0
F00240A0: 900a3fdf                 and     %o0, -0x21, %o0
F00240A4: d026600c                 st      %o0, [%i1+0xC]
F00240A8: d006600c                 ld      [%i1+0xC], %o0
F00240AC: b0102000                 mov     0, %i0
F00240B0: 900a3f7f                 and     %o0, -0x81, %o0
F00240B4: d026600c                 st      %o0, [%i1+0xC]
F00240B8: 81c7e008                 ret
F00240BC: 81e80000                 restore
