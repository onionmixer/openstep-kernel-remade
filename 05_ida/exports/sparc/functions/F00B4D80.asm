F00B4D80: 9de3bf70                 save    %sp, -0x90, %sp
F00B4D84: 113c02da90122050         set     _esp_finish_select, %o0
F00B4D8C: d027bfd0                 st      %o0, [%fp+var_30]
F00B4D90: 113c02da901223b4         set     _esp_reconnect, %o0
F00B4D98: d027bfd4                 st      %o0, [%fp+var_2C]
F00B4D9C: 113c02d3901223e8         set     _esp_phasemanage, %o0
F00B4DA4: d027bfd8                 st      %o0, [%fp+var_28]
F00B4DA8: 113c02d2901221fc         set     _esp_finish, %o0
F00B4DB0: d027bfdc                 st      %o0, [%fp+var_24]
F00B4DB4: 113c02dc9012221c         set     _esp_reset_recovery, %o0
F00B4DBC: d027bfe0                 st      %o0, [%fp+var_20]
F00B4DC0: 113c02dc90122080         set     _esp_istart, %o0
F00B4DC8: d027bfe4                 st      %o0, [%fp+var_1C]
F00B4DCC: 113c02de9012200c         set     _esp_abort_curcmd, %o0
F00B4DD4: d027bfe8                 st      %o0, [%fp+var_18]
F00B4DD8: 113c02de9012203c         set     _esp_abort_allcmds, %o0
F00B4DE0: d027bfec                 st      %o0, [%fp+var_14]
F00B4DE4: 113c02dc901221f4         set     _esp_reset_bus, %o0
F00B4DEC: d027bff0                 st      %o0, [%fp+var_10]
F00B4DF0: 113c02dc90122338         set     _esp_handle_selection, %o0
F00B4DF8: d027bff4                 st      %o0, [%fp+var_C]
F00B4DFC: e20620a0                 ld      [%i0+0xA0], %l1
F00B4E00: d4044000                 ld      [%l1], %o2
F00B4E04: 9132a01c                 srl     %o2, 28, %o0
F00B4E08: 80a22008                 cmp     %o0, 8
F00B4E0C: 12800004                 bne     loc_F00B4E1C
F00B4E10: d206209c                 ld      [%i0+0x9C], %o1
F00B4E14: 900abfef                 and     %o2, -0x11, %o0
F00B4E18: d0244000                 st      %o0, [%l1]
F00B4E1C: d00a6018                 ldub    [%o1+0x18], %o0
F00B4E20: 900a2007                 and     %o0, 7, %o0
F00B4E24: d02e2045                 stb     %o0, [%i0+0x45]
F00B4E28: d00a6010                 ldub    [%o1+0x10], %o0
F00B4E2C: d02e2043                 stb     %o0, [%i0+0x43]
F00B4E30: e00a6014                 ldub    [%o1+0x14], %l0
F00B4E34: d60e2043                 ldub    [%i0+0x43], %o3
F00B4E38: 808ae040                 btst    0x40, %o3 ! '@'
F00B4E3C: 02800015                 be      loc_F00B4E90
F00B4E40: e02e2044                 stb     %l0, [%i0+0x44]
F00B4E44: 90100018                 mov     %i0, %o0
F00B4E48: 92102003                 mov     3, %o1
F00B4E4C: 153c0479                 sethi   %hi(aGrossErrorInEs), %o2! "gross error in esp status (%x)"
F00B4E50: 40000b67                 call    _esplog
F00B4E54: 9412a0c0                 bset    %lo(aGrossErrorInEs), %o2! "gross error in esp status (%x)"
F00B4E58: d05620b2                 ldsh    [%i0+0xB2], %o0
F00B4E5C: 80a23fff                 cmp     %o0, -1
F00B4E60: 12800004                 bne     loc_F00B4E70
F00B4E64: 912a2002                 sll     %o0, 2, %o0
F00B4E68: 1080004c                 ba      loc_F00B4F98
F00B4E6C: 90102007                 mov     7, %o0
F00B4E70: 90020018                 add     %o0, %i0, %o0
F00B4E74: d20220b8                 ld      [%o0+0xB8], %o1
F00B4E78: d00a6028                 ldub    [%o1+0x28], %o0
F00B4E7C: 80a22000                 cmp     %o0, 0
F00B4E80: 32800005                 bne,a   loc_F00B4E94
F00B4E84: d00620a0                 ld      [%i0+0xA0], %o0
F00B4E88: 90102003                 mov     3, %o0
F00B4E8C: d02a6028                 stb     %o0, [%o1+0x28]
F00B4E90: d00620a0                 ld      [%i0+0xA0], %o0
F00B4E94: d0020000                 ld      [%o0], %o0
F00B4E98: 808a2002                 btst    2, %o0
F00B4E9C: 02800013                 be      loc_F00B4EE8
F00B4EA0: 90100018                 mov     %i0, %o0
F00B4EA4: 92102003                 mov     3, %o1
F00B4EA8: 153c0479                 sethi   %hi(aUnrecoverableD), %o2! "Unrecoverable DMA error on dma"
F00B4EAC: 40000b50                 call    _esplog
F00B4EB0: 9412a0e0                 bset    %lo(aUnrecoverableD), %o2! "Unrecoverable DMA error on dma"
F00B4EB4: d05620b2                 ldsh    [%i0+0xB2], %o0
F00B4EB8: 80a23fff                 cmp     %o0, -1
F00B4EBC: 0280000b                 be      loc_F00B4EE8
F00B4EC0: 912a2002                 sll     %o0, 2, %o0
F00B4EC4: 90020018                 add     %o0, %i0, %o0
F00B4EC8: d20220b8                 ld      [%o0+0xB8], %o1
F00B4ECC: d00a6028                 ldub    [%o1+0x28], %o0
F00B4ED0: 80a22000                 cmp     %o0, 0
F00B4ED4: 12800031                 bne     loc_F00B4F98
F00B4ED8: 90102008                 mov     8, %o0
F00B4EDC: 90102003                 mov     3, %o0
F00B4EE0: 10800022                 ba      loc_F00B4F68
F00B4EE4: d02a6028                 stb     %o0, [%o1+0x28]
F00B4EE8: d00e2031                 ldub    [%i0+0x31], %o0
F00B4EEC: 80a22002                 cmp     %o0, 2
F00B4EF0: 02800005                 be      loc_F00B4F04
F00B4EF4: 808c2080                 btst    0x80, %l0
F00B4EF8: d00e2043                 ldub    [%i0+0x43], %o0
F00B4EFC: 900a207f                 and     %o0, 0x7F, %o0
F00B4F00: d02e2043                 stb     %o0, [%i0+0x43]
F00B4F04: 12800025                 bne     loc_F00B4F98
F00B4F08: 90102004                 mov     4, %o0
F00B4F0C: 808c2040                 btst    0x40, %l0 ! '@'
F00B4F10: 02800007                 be      loc_F00B4F2C
F00B4F14: 90100018                 mov     %i0, %o0
F00B4F18: 133c0479                 sethi   %hi(aIllegalBitSet), %o1! "ILLEGAL bit set"
F00B4F1C: 40000b7e                 call    _esp_printstate
F00B4F20: 92126100                 bset    %lo(aIllegalBitSet), %o1! "ILLEGAL bit set"
F00B4F24: 1080001d                 ba      loc_F00B4F98
F00B4F28: 90102006                 mov     6, %o0
F00B4F2C: 808c2003                 btst    3, %l0
F00B4F30: 1280001a                 bne     loc_F00B4F98
F00B4F34: 90102009                 mov     9, %o0
F00B4F38: 808c2004                 btst    4, %l0
F00B4F3C: 0280000f                 be      loc_F00B4F78
F00B4F40: d00e2041                 ldub    [%i0+0x41], %o0
F00B4F44: 808a20e0                 btst    0xE0, %o0
F00B4F48: 32800014                 bne,a   loc_F00B4F98
F00B4F4C: 90102000                 mov     0, %o0
F00B4F50: 80a22000                 cmp     %o0, 0
F00B4F54: 02800007                 be      loc_F00B4F70
F00B4F58: 90100018                 mov     %i0, %o0
F00B4F5C: 133c0479                 sethi   %hi(aIllegalReselec), %o1! "illegal reselection"
F00B4F60: 40000b6d                 call    _esp_printstate
F00B4F64: 92126110                 bset    %lo(aIllegalReselec), %o1! "illegal reselection"
F00B4F68: 1080000c                 ba      loc_F00B4F98
F00B4F6C: 90102008                 mov     8, %o0
F00B4F70: 1080000a                 ba      loc_F00B4F98
F00B4F74: 90102001                 mov     1, %o0
F00B4F78: 808a20e0                 btst    0xE0, %o0
F00B4F7C: 02800004                 be      loc_F00B4F8C
F00B4F80: 808a201f                 btst    0x1F, %o0
F00B4F84: 10800005                 ba      loc_F00B4F98
F00B4F88: 90102000                 mov     0, %o0
F00B4F8C: 02800003                 be      loc_F00B4F98
F00B4F90: 90103fff                 mov     -1, %o0
F00B4F94: 90102002                 mov     2, %o0
F00B4F98: 80a23fff                 cmp     %o0, -1
F00B4F9C: 2280000c                 be,a    loc_F00B4FCC
F00B4FA0: d2044000                 ld      [%l1], %o1
F00B4FA4: a007bff8                 add     %fp, var_8, %l0
F00B4FA8: 912a2002                 sll     %o0, 2, %o0
F00B4FAC: 90020010                 add     %o0, %l0, %o0
F00B4FB0: d2023fd8                 ld      [%o0-0x28], %o1
F00B4FB4: 9fc24000                 call    %o1
F00B4FB8: 90100018                 mov     %i0, %o0
F00B4FBC: 80a23fff                 cmp     %o0, -1
F00B4FC0: 12bffffb                 bne     loc_F00B4FAC
F00B4FC4: 912a2002                 sll     %o0, 2, %o0
F00B4FC8: d2044000                 ld      [%l1], %o1
F00B4FCC: 9132601c                 srl     %o1, 28, %o0
F00B4FD0: 80a22008                 cmp     %o0, 8
F00B4FD4: 12800003                 bne     locret_F00B4FE0
F00B4FD8: 90126010                 or      %o1, 0x10, %o0
F00B4FDC: d0244000                 st      %o0, [%l1]
F00B4FE0: 81c7e008                 ret
F00B4FE4: 81e80000                 restore
