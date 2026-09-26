F00A6E5C: 9de3bf80                 save    %sp, -0x80, %sp
F00A6E60: c027bfe4                 clr     [%fp+var_1C]
F00A6E64: 113c0485a0122050         set     _static_KERNBOOTSTRUCT, %l0
F00A6E6C: d20420a4                 ld      [%l0+0xA4], %o1
F00A6E70: 1129e9e9901223a7         set     -0x58585859, %o0
F00A6E78: 80a24008                 cmp     %o1, %o0
F00A6E7C: 02800004                 be      loc_F00A6E8C
F00A6E80: 113c046c                 sethi   %hi(aGetdefaultroot), %o0! "getDefaultRoot: invalid boot struct"
F00A6E84: 7ffdb8bb                 call    _panic
F00A6E88: 90122130                 bset    %lo(aGetdefaultroot), %o0! "getDefaultRoot: invalid boot struct"
F00A6E8C: b007bfe8                 add     %fp, var_18, %i0
F00A6E90: 2d3c046c                 sethi   -0xFEE5000, %l6
F00A6E94: 2b3c0504                 sethi   -0xFEBF000, %l5
F00A6E98: 293c0504                 sethi   -0xFEBF000, %l4
F00A6E9C: e60c20af                 ldub    [%l0+0xAF], %l3
F00A6EA0: a0102000                 mov     0, %l0
F00A6EA4: 90100018                 mov     %i0, %o0! char *
F00A6EA8: 9215a158                 or      %l6, 0x158, %o1! char *
F00A6EAC: 7ffdb62f                 call    _sprintf
F00A6EB0: 94100010                 mov     %l0, %o2
F00A6EB4: 90100018                 mov     %i0, %o0
F00A6EB8: 400075da                 call    _IOGetObjectForDeviceName
F00A6EBC: 9207bfe4                 add     %fp, var_1C, %o1! SEL
F00A6EC0: a2920000                 orcc    %o0, %g0, %l1
F00A6EC4: 12800015                 bne     loc_F00A6F18
F00A6EC8: d007bfe4                 ld      [%fp+var_1C], %o0! id
F00A6ECC: 40012a69                 call    _objc_msgSend
F00A6ED0: d20561b4                 ld      [%l5+0x1B4], %o1! SEL
F00A6ED4: a4100008                 mov     %o0, %l2
F00A6ED8: d007bfe4                 ld      [%fp+var_1C], %o0! id
F00A6EDC: 40012a65                 call    _objc_msgSend
F00A6EE0: d2052200                 ld      [%l4+0x200], %o1
F00A6EE4: 920ca0ff                 and     %l2, 0xFF, %o1
F00A6EE8: 80a4c009                 cmp     %l3, %o1
F00A6EEC: 32800008                 bne,a   loc_F00A6F0C
F00A6EF0: a0042001                 inc     %l0
F00A6EF4: 900a20ff                 and     %o0, 0xFF, %o0
F00A6EF8: 80a22005                 cmp     %o0, 5
F00A6EFC: 0280000f                 be      locret_F00A6F38
F00A6F00: 80a22000                 cmp     %o0, 0
F00A6F04: 0280000d                 be      locret_F00A6F38
F00A6F08: a0042001                 inc     %l0
F00A6F0C: 80a4200f                 cmp     %l0, 0xF
F00A6F10: 04bfffe6                 ble     loc_F00A6EA8
F00A6F14: 90100018                 mov     %i0, %o0
F00A6F18: 900ca0ff                 and     %l2, 0xFF, %o0
F00A6F1C: 80a20013                 cmp     %o0, %l3
F00A6F20: 32bfffe1                 bne,a   loc_F00A6EA4
F00A6F24: a0102000                 mov     0, %l0
F00A6F28: 80a46000                 cmp     %l1, 0
F00A6F2C: 22bfffde                 be,a    loc_F00A6EA4
F00A6F30: a0102000                 mov     0, %l0
F00A6F34: b0102000                 mov     0, %i0
F00A6F38: 81c7e008                 ret
F00A6F3C: 81e80000                 restore
