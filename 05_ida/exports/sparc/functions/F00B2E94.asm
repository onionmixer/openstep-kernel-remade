F00B2E94: 9de3bf88                 save    %sp, -0x78, %sp
F00B2E98: 96100018                 mov     %i0, %o3
F00B2E9C: 98100019                 mov     %i1, %o4
F00B2EA0: d627bfe8                 st      %o3, [%fp+var_18]
F00B2EA4: d827bfec                 st      %o4, [%fp+var_14]
F00B2EA8: 113c0477                 sethi   %hi(dword_F011DDA0), %o0
F00B2EAC: d00221a0                 ld      [%o0+%lo(dword_F011DDA0)], %o0
F00B2EB0: 80a22000                 cmp     %o0, 0
F00B2EB4: 02800007                 be      loc_F00B2ED0
F00B2EB8: c027bff4                 clr     [%fp+var_C]
F00B2EBC: 113c0477901221f0         set     aWalkLayerAtXSL, %o0! "walk layer at %x (%s); looking for '%s'"...
F00B2EC4: d406a00c                 ld      [%i2+0xC], %o2
F00B2EC8: 7ffd85e4                 call    _printf
F00B2ECC: 9210001a                 mov     %i2, %o1
F00B2ED0: 133c02cb921261b8         set     sub_F00B2DB8, %o1
F00B2ED8: d006a008                 ld      [%i2+8], %o0
F00B2EDC: 7ffff78e                 call    _walk_layer
F00B2EE0: 9407bfe8                 add     %fp, var_18, %o2
F00B2EE4: f007bff4                 ld      [%fp+var_C], %i0
F00B2EE8: 81c7e008                 ret
F00B2EEC: 81e80000                 restore
