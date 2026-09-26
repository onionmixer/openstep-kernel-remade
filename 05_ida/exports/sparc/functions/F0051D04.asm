F0051D04: 9de3bf90                 save    %sp, -0x70, %sp
F0051D08: 133c04cf                 sethi   %hi(_active_u), %o1
F0051D0C: d00261d8                 ld      [%o1+%lo(_active_u)], %o0
F0051D10: a4100018                 mov     %i0, %l2
F0051D14: d0020000                 ld      [%o0], %o0
F0051D18: a2102000                 mov     0, %l1
F0051D1C: d0522030                 ldsh    [%o0+0x30], %o0
F0051D20: 7ffef380                 call    _get_posix_proc
F0051D24: a61261d8                 or      %o1, %lo(_active_u), %l3
F0051D28: b0102000                 mov     0, %i0
F0051D2C: d2566014                 ldsh    [%i1+0x14], %o1
F0051D30: 80a27fff                 cmp     %o1, -1
F0051D34: 1280001a                 bne     loc_F0051D9C
F0051D38: a8100008                 mov     %o0, %l4
F0051D3C: d006601c                 ld      [%i1+0x1C], %o0
F0051D40: 80a23fff                 cmp     %o0, -1
F0051D44: 328000cd                 bne,a   locret_F0052078
F0051D48: b0102016                 mov     0x16, %i0
F0051D4C: d0566038                 ldsh    [%i1+0x38], %o0
F0051D50: 80a23fff                 cmp     %o0, -1
F0051D54: 328000c9                 bne,a   locret_F0052078
F0051D58: b0102016                 mov     0x16, %i0
F0051D5C: d006603c                 ld      [%i1+0x3C], %o0
F0051D60: 80a23fff                 cmp     %o0, -1
F0051D64: 328000c5                 bne,a   locret_F0052078
F0051D68: b0102016                 mov     0x16, %i0
F0051D6C: d006600c                 ld      [%i1+0xC], %o0
F0051D70: 80a23fff                 cmp     %o0, -1
F0051D74: 328000c1                 bne,a   locret_F0052078
F0051D78: b0102016                 mov     0x16, %i0
F0051D7C: d0066010                 ld      [%i1+0x10], %o0
F0051D80: 80a23fff                 cmp     %o0, -1
F0051D84: 328000bd                 bne,a   locret_F0052078
F0051D88: b0102016                 mov     0x16, %i0
F0051D8C: d0064000                 ld      [%i1], %o0
F0051D90: 80a23fff                 cmp     %o0, -1
F0051D94: 22800004                 be,a    loc_F0051DA4
F0051D98: e004a030                 ld      [%l2+0x30], %l0
F0051D9C: 108000b7                 ba      locret_F0052078
F0051DA0: b0102016                 mov     0x16, %i0
F0051DA4: 7ffff4b9                 call    _ilock
F0051DA8: 90100010                 mov     %l0, %o0
F0051DAC: 1100003f                 sethi   0xFC00, %o0
F0051DB0: d2166004                 lduh    [%i1+4], %o1
F0051DB4: 901223ff                 bset    0x3FF, %o0
F0051DB8: 80a24008                 cmp     %o1, %o0
F0051DBC: 22800030                 be,a    loc_F0051E7C
F0051DC0: d2566006                 ldsh    [%i1+6], %o1
F0051DC4: d256a002                 ldsh    [%i2+2], %o1
F0051DC8: d0542068                 ldsh    [%l0+0x68], %o0
F0051DCC: 80a24008                 cmp     %o1, %o0
F0051DD0: 0280000a                 be      loc_F0051DF8
F0051DD4: 80a62000                 cmp     %i0, 0
F0051DD8: 7ffef6e5                 call    _suser
F0051DDC: 01000000                 nop
F0051DE0: 80a22000                 cmp     %o0, 0
F0051DE4: 12800005                 bne     loc_F0051DF8
F0051DE8: 80a62000                 cmp     %i0, 0
F0051DEC: d004e004                 ld      [%l3+4], %o0
F0051DF0: f04a2038                 ldsb    [%o0+0x38], %i0
F0051DF4: 80a62000                 cmp     %i0, 0
F0051DF8: 1280009c                 bne     loc_F0052068
F0051DFC: 90100010                 mov     %l0, %o0
F0051E00: d0142064                 lduh    [%l0+0x64], %o0
F0051E04: 1700003c                 sethi   0xF000, %o3
F0051E08: 900a000b                 and     %o0, %o3, %o0
F0051E0C: d0342064                 sth     %o0, [%l0+0x64]
F0051E10: d2166004                 lduh    [%i1+4], %o1
F0051E14: 920a6fff                 and     %o1, 0xFFF, %o1
F0051E18: 94120009                 or      %o0, %o1, %o2
F0051E1C: d4342064                 sth     %o2, [%l0+0x64]
F0051E20: d056a002                 ldsh    [%i2+2], %o0
F0051E24: 80a22000                 cmp     %o0, 0
F0051E28: 02800011                 be      loc_F0051E6C
F0051E2C: 920a800b                 and     %o2, %o3, %o1
F0051E30: 11000010                 sethi   0x4000, %o0
F0051E34: 80a24008                 cmp     %o1, %o0
F0051E38: 02800005                 be      loc_F0051E4C
F0051E3C: 1100003f                 sethi   0xFC00, %o0
F0051E40: 901221ff                 bset    0x1FF, %o0
F0051E44: 900a8008                 and     %o2, %o0, %o0
F0051E48: d0342064                 sth     %o0, [%l0+0x64]
F0051E4C: 7ffef6ab                 call    _groupmember
F0051E50: d054206a                 ldsh    [%l0+0x6A], %o0
F0051E54: 80a22000                 cmp     %o0, 0
F0051E58: 32800006                 bne,a   loc_F0051E70
F0051E5C: d0142044                 lduh    [%l0+0x44], %o0
F0051E60: d0142064                 lduh    [%l0+0x64], %o0
F0051E64: 900a3bff                 and     %o0, -0x401, %o0
F0051E68: d0342064                 sth     %o0, [%l0+0x64]
F0051E6C: d0142044                 lduh    [%l0+0x44], %o0
F0051E70: 90122040                 bset    0x40, %o0 ! '@'
F0051E74: d0342044                 sth     %o0, [%l0+0x44]
F0051E78: d2566006                 ldsh    [%i1+6], %o1
F0051E7C: 80a27fff                 cmp     %o1, -1
F0051E80: 32800007                 bne,a   loc_F0051E9C
F0051E84: d4566008                 ldsh    [%i1+8], %o2
F0051E88: d0566008                 ldsh    [%i1+8], %o0
F0051E8C: 80a23fff                 cmp     %o0, -1
F0051E90: 22800009                 be,a    loc_F0051EB4
F0051E94: d0066018                 ld      [%i1+0x18], %o0
F0051E98: d4566008                 ldsh    [%i1+8], %o2
F0051E9C: 40000079                 call    sub_F0052080
F0051EA0: 90100010                 mov     %l0, %o0
F0051EA4: b0920000                 orcc    %o0, %g0, %i0
F0051EA8: 12800070                 bne     loc_F0052068
F0051EAC: 90100010                 mov     %l0, %o0
F0051EB0: d0066018                 ld      [%i1+0x18], %o0
F0051EB4: 80a23fff                 cmp     %o0, -1
F0051EB8: 02800015                 be      loc_F0051F0C
F0051EBC: 1300003c                 sethi   0xF000, %o1
F0051EC0: d0142064                 lduh    [%l0+0x64], %o0
F0051EC4: 900a0009                 and     %o0, %o1, %o0
F0051EC8: 13000010                 sethi   0x4000, %o1
F0051ECC: 80a20009                 cmp     %o0, %o1
F0051ED0: 32800004                 bne,a   loc_F0051EE0
F0051ED4: 90100010                 mov     %l0, %o0
F0051ED8: 10800063                 ba      loc_F0052064
F0051EDC: b0102015                 mov     0x15, %i0
F0051EE0: 7ffff48a                 call    _iaccess
F0051EE4: 92102080                 mov     0x80, %o1
F0051EE8: b0920000                 orcc    %o0, %g0, %i0
F0051EEC: 1280005f                 bne     loc_F0052068
F0051EF0: 90100010                 mov     %l0, %o0
F0051EF4: d2066018                 ld      [%i1+0x18], %o1
F0051EF8: 7ffff201                 call    _itrunc
F0051EFC: 90100010                 mov     %l0, %o0
F0051F00: b0920000                 orcc    %o0, %g0, %i0
F0051F04: 12800059                 bne     loc_F0052068
F0051F08: 90100010                 mov     %l0, %o0
F0051F0C: 7ffff46f                 call    _iunlock
F0051F10: 90100010                 mov     %l0, %o0
F0051F14: 40006c89                 call    _mfs_fsync
F0051F18: 90100012                 mov     %l2, %o0
F0051F1C: 7ffff45b                 call    _ilock
F0051F20: 90100010                 mov     %l0, %o0
F0051F24: d0066020                 ld      [%i1+0x20], %o0
F0051F28: 80a23fff                 cmp     %o0, -1
F0051F2C: 22800022                 be,a    loc_F0051FB4
F0051F30: d0066028                 ld      [%i1+0x28], %o0
F0051F34: d256a002                 ldsh    [%i2+2], %o1
F0051F38: d0542068                 ldsh    [%l0+0x68], %o0
F0051F3C: 80a24008                 cmp     %o1, %o0
F0051F40: 0280000a                 be      loc_F0051F68
F0051F44: b0102000                 mov     0, %i0
F0051F48: 7ffef689                 call    _suser
F0051F4C: 01000000                 nop
F0051F50: 80a22000                 cmp     %o0, 0
F0051F54: 12800006                 bne     loc_F0051F6C
F0051F58: 80a62000                 cmp     %i0, 0
F0051F5C: 113c04cf                 sethi   %hi(dword_F0133DDC), %o0
F0051F60: d00221dc                 ld      [%o0+%lo(dword_F0133DDC)], %o0
F0051F64: f04a2038                 ldsb    [%o0+0x38], %i0
F0051F68: 80a62000                 cmp     %i0, 0
F0051F6C: 2280000f                 be,a    loc_F0051FA8
F0051F70: d0066020                 ld      [%i1+0x20], %o0
F0051F74: d0052018                 ld      [%l4+0x18], %o0
F0051F78: 80a22000                 cmp     %o0, 0
F0051F7C: 1680003b                 bge     loc_F0052068
F0051F80: 90100010                 mov     %l0, %o0
F0051F84: 7ffff461                 call    _iaccess
F0051F88: 92102080                 mov     0x80, %o1
F0051F8C: b0920000                 orcc    %o0, %g0, %i0
F0051F90: 12800036                 bne     loc_F0052068
F0051F94: 90100010                 mov     %l0, %o0
F0051F98: 113c04cf                 sethi   %hi(dword_F0133DDC), %o0
F0051F9C: d00221dc                 ld      [%o0+%lo(dword_F0133DDC)], %o0
F0051FA0: c02a2038                 clrb    [%o0+0x38]
F0051FA4: d0066020                 ld      [%i1+0x20], %o0
F0051FA8: a2046001                 inc     %l1
F0051FAC: d0242074                 st      %o0, [%l0+0x74]
F0051FB0: d0066028                 ld      [%i1+0x28], %o0
F0051FB4: 80a23fff                 cmp     %o0, -1
F0051FB8: 02800022                 be      loc_F0052040
F0051FBC: 80a46000                 cmp     %l1, 0
F0051FC0: d256a002                 ldsh    [%i2+2], %o1
F0051FC4: d0542068                 ldsh    [%l0+0x68], %o0
F0051FC8: 80a24008                 cmp     %o1, %o0
F0051FCC: 0280000a                 be      loc_F0051FF4
F0051FD0: b0102000                 mov     0, %i0
F0051FD4: 7ffef666                 call    _suser
F0051FD8: 01000000                 nop
F0051FDC: 80a22000                 cmp     %o0, 0
F0051FE0: 12800006                 bne     loc_F0051FF8
F0051FE4: 80a62000                 cmp     %i0, 0
F0051FE8: 113c04cf                 sethi   %hi(dword_F0133DDC), %o0
F0051FEC: d00221dc                 ld      [%o0+%lo(dword_F0133DDC)], %o0
F0051FF0: f04a2038                 ldsb    [%o0+0x38], %i0
F0051FF4: 80a62000                 cmp     %i0, 0
F0051FF8: 2280000f                 be,a    loc_F0052034
F0051FFC: d0066028                 ld      [%i1+0x28], %o0
F0052000: d0052018                 ld      [%l4+0x18], %o0
F0052004: 80a22000                 cmp     %o0, 0
F0052008: 16800018                 bge     loc_F0052068
F005200C: 90100010                 mov     %l0, %o0
F0052010: 7ffff43e                 call    _iaccess
F0052014: 92102080                 mov     0x80, %o1
F0052018: b0920000                 orcc    %o0, %g0, %i0
F005201C: 12800013                 bne     loc_F0052068
F0052020: 90100010                 mov     %l0, %o0
F0052024: 113c04cf                 sethi   %hi(dword_F0133DDC), %o0
F0052028: d00221dc                 ld      [%o0+%lo(dword_F0133DDC)], %o0
F005202C: c02a2038                 clrb    [%o0+0x38]
F0052030: d0066028                 ld      [%i1+0x28], %o0
F0052034: a2046001                 inc     %l1
F0052038: d024207c                 st      %o0, [%l0+0x7C]
F005203C: 80a46000                 cmp     %l1, 0
F0052040: 2280000a                 be,a    loc_F0052068
F0052044: 90100010                 mov     %l0, %o0
F0052048: 7fff03d1                 call    _getthetime
F005204C: 9007bff0                 add     %fp, var_10, %o0
F0052050: d207bff0                 ld      [%fp+var_10], %o1
F0052054: d0142044                 lduh    [%l0+0x44], %o0
F0052058: d2242084                 st      %o1, [%l0+0x84]
F005205C: 90122008                 bset    8, %o0
F0052060: d0342044                 sth     %o0, [%l0+0x44]
F0052064: 90100010                 mov     %l0, %o0
F0052068: 7ffff137                 call    _iupdat
F005206C: 92102001                 mov     1, %o1
F0052070: 7ffff416                 call    _iunlock
F0052074: 90100010                 mov     %l0, %o0
F0052078: 81c7e008                 ret
F005207C: 81e80000                 restore
