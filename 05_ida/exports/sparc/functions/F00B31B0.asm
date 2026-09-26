F00B31B0: 9de3bf88                 save    %sp, -0x78, %sp
F00B31B4: 96100018                 mov     %i0, %o3
F00B31B8: 98100019                 mov     %i1, %o4
F00B31BC: d627bfe8                 st      %o3, [%fp+var_18]
F00B31C0: d827bff0                 st      %o4, [%fp+var_10]
F00B31C4: 113c0477                 sethi   %hi(dword_F011DDA0), %o0
F00B31C8: d00221a0                 ld      [%o0+%lo(dword_F011DDA0)], %o0
F00B31CC: 80a22000                 cmp     %o0, 0
F00B31D0: 02800007                 be      loc_F00B31EC
F00B31D4: c027bff4                 clr     [%fp+var_C]
F00B31D8: 113c0477901222a0         set     aWalkTreeAtXSLo, %o0! "walk tree at %x (%s); looking for '%s' "...
F00B31E0: d406a00c                 ld      [%i2+0xC], %o2
F00B31E4: 7ffd851d                 call    _printf
F00B31E8: 9210001a                 mov     %i2, %o1
F00B31EC: 9010001a                 mov     %i2, %o0
F00B31F0: 133c02cc92126124         set     sub_F00B3124, %o1
F00B31F8: 7ffff6b2                 call    _walk_devs
F00B31FC: 9407bfe8                 add     %fp, var_18, %o2
F00B3200: f007bff4                 ld      [%fp+var_C], %i0
F00B3204: 81c7e008                 ret
F00B3208: 81e80000                 restore
