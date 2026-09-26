F002638C: 9de3bf58                 save    %sp, -0xA8, %sp
F0026390: d206201c                 ld      [%i0+0x1C], %o1
F0026394: 113c04cf                 sethi   %hi(_active_u), %o0
F0026398: d40221d8                 ld      [%o0+%lo(_active_u)], %o2
F002639C: d6026014                 ld      [%o1+0x14], %o3
F00263A0: 90100018                 mov     %i0, %o0
F00263A4: d402a01c                 ld      [%o2+0x1C], %o2
F00263A8: 9fc2c000                 call    %o3
F00263AC: 9207bfb8                 add     %fp, var_48, %o1
F00263B0: 80a22000                 cmp     %o0, 0
F00263B4: 22800004                 be,a    loc_F00263C4
F00263B8: d017bfbc                 lduh    [%fp+var_44], %o0
F00263BC: 10800050                 ba      locret_F00264FC
F00263C0: b0100008                 mov     %o0, %i0
F00263C4: d0366008                 sth     %o0, [%i1+8]
F00263C8: d017bfbe                 lduh    [%fp+var_42], %o0
F00263CC: d036600c                 sth     %o0, [%i1+0xC]
F00263D0: d017bfc0                 lduh    [%fp+var_40], %o0
F00263D4: d036600e                 sth     %o0, [%i1+0xE]
F00263D8: d007bfc4                 ld      [%fp+var_3C], %o0
F00263DC: d0364000                 sth     %o0, [%i1]
F00263E0: d007bfc8                 ld      [%fp+var_38], %o0
F00263E4: d0266004                 st      %o0, [%i1+4]
F00263E8: d017bfcc                 lduh    [%fp+var_34], %o0
F00263EC: d036600a                 sth     %o0, [%i1+0xA]
F00263F0: d007bfd0                 ld      [%fp+var_30], %o0
F00263F4: d0266014                 st      %o0, [%i1+0x14]
F00263F8: d007bfd4                 ld      [%fp+var_2C], %o0
F00263FC: d0266030                 st      %o0, [%i1+0x30]
F0026400: d007bfd8                 ld      [%fp+var_28], %o0
F0026404: d0266018                 st      %o0, [%i1+0x18]
F0026408: c026601c                 clr     [%i1+0x1C]
F002640C: d4062014                 ld      [%i0+0x14], %o2
F0026410: 80a2a000                 cmp     %o2, 0
F0026414: 12800006                 bne     loc_F002642C
F0026418: d007bfe0                 ld      [%fp+var_20], %o0
F002641C: d0062018                 ld      [%i0+0x18], %o0
F0026420: 80a22000                 cmp     %o0, 0
F0026424: 0280000f                 be      loc_F0026460
F0026428: d007bfe0                 ld      [%fp+var_20], %o0
F002642C: 80a28008                 cmp     %o2, %o0
F0026430: 3480000d                 bg,a    loc_F0026464
F0026434: d4266020                 st      %o2, [%i1+0x20]
F0026438: 80a28008                 cmp     %o2, %o0
F002643C: 12800009                 bne     loc_F0026460
F0026440: d007bfe0                 ld      [%fp+var_20], %o0
F0026444: d2062018                 ld      [%i0+0x18], %o1
F0026448: d007bfe4                 ld      [%fp+var_1C], %o0
F002644C: 80a24008                 cmp     %o1, %o0
F0026450: 04800004                 ble     loc_F0026460
F0026454: d007bfe0                 ld      [%fp+var_20], %o0
F0026458: 10800003                 ba      loc_F0026464
F002645C: d4266020                 st      %o2, [%i1+0x20]
F0026460: d0266020                 st      %o0, [%i1+0x20]
F0026464: c0266024                 clr     [%i1+0x24]
F0026468: d007bfe8                 ld      [%fp+var_18], %o0
F002646C: d0266028                 st      %o0, [%i1+0x28]
F0026470: c026602c                 clr     [%i1+0x2C]
F0026474: d017bff0                 lduh    [%fp+var_10], %o0
F0026478: d0366010                 sth     %o0, [%i1+0x10]
F002647C: d007bff4                 ld      [%fp+var_C], %o0
F0026480: d0266034                 st      %o0, [%i1+0x34]
F0026484: c026603c                 clr     [%i1+0x3C]
F0026488: c0266038                 clr     [%i1+0x38]
F002648C: 113c043c                 sethi   %hi(_ufs_vnodeops), %o0
F0026490: d206201c                 ld      [%i0+0x1C], %o1
F0026494: 90122160                 bset    %lo(_ufs_vnodeops), %o0
F0026498: 80a24008                 cmp     %o1, %o0
F002649C: 32800008                 bne,a   loc_F00264BC
F00264A0: 113c0435                 sethi   -0xFEF2C00, %o0
F00264A4: 113fbb7e901222ce         set     -0x1120532, %o0
F00264AC: d0266038                 st      %o0, [%i1+0x38]
F00264B0: d0062030                 ld      [%i0+0x30], %o0
F00264B4: 10800010                 ba      loc_F00264F4
F00264B8: d00220d0                 ld      [%o0+0xD0], %o0
F00264BC: 901221cc                 bset    0x1CC, %o0
F00264C0: 80a24008                 cmp     %o1, %o0
F00264C4: 3280000e                 bne,a   locret_F00264FC
F00264C8: b0102000                 mov     0, %i0
F00264CC: f0062030                 ld      [%i0+0x30], %i0
F00264D0: d0066004                 ld      [%i1+4], %o0
F00264D4: d206204c                 ld      [%i0+0x4C], %o1
F00264D8: 80a24008                 cmp     %o1, %o0
F00264DC: 32800008                 bne,a   locret_F00264FC
F00264E0: b0102000                 mov     0, %i0
F00264E4: 113fbb7e901222ce         set     -0x1120532, %o0
F00264EC: d0266038                 st      %o0, [%i1+0x38]
F00264F0: d0062050                 ld      [%i0+0x50], %o0
F00264F4: d026603c                 st      %o0, [%i1+0x3C]
F00264F8: b0102000                 mov     0, %i0
F00264FC: 81c7e008                 ret
F0026500: 81e80000                 restore
