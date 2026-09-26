F00287A8: 9de3bf90                 save    %sp, -0x70, %sp
F00287AC: 90100018                 mov     %i0, %o0
F00287B0: 92102000                 mov     0, %o1
F00287B4: 94100019                 mov     %i1, %o2
F00287B8: 96102000                 mov     0, %o3
F00287BC: 7ffff882                 call    _lookupname
F00287C0: 9807bff4                 add     %fp, var_C, %o4
F00287C4: b0920000                 orcc    %o0, %g0, %i0
F00287C8: 12800012                 bne     locret_F0028810
F00287CC: d607bff4                 ld      [%fp+var_C], %o3
F00287D0: d002e024                 ld      [%o3+0x24], %o0
F00287D4: d002200c                 ld      [%o0+0xC], %o0
F00287D8: 808a2001                 btst    1, %o0
F00287DC: 1280000b                 bne     loc_F0028808
F00287E0: b010201e                 mov     0x1E, %i0
F00287E4: 113c04cf                 sethi   %hi(_active_u), %o0
F00287E8: d00221d8                 ld      [%o0+%lo(_active_u)], %o0
F00287EC: d402201c                 ld      [%o0+0x1C], %o2
F00287F0: d202e01c                 ld      [%o3+0x1C], %o1
F00287F4: 9010000b                 mov     %o3, %o0
F00287F8: d6026018                 ld      [%o1+0x18], %o3
F00287FC: 9fc2c000                 call    %o3
F0028800: 9210001a                 mov     %i2, %o1
F0028804: b0100008                 mov     %o0, %i0
F0028808: 400000d7                 call    _vn_rele
F002880C: d007bff4                 ld      [%fp+var_C], %o0
F0028810: 81c7e008                 ret
F0028814: 81e80000                 restore
