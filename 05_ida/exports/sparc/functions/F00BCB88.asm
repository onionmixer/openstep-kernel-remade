F00BCB88: 9de3bf98                 save    %sp, -0x68, %sp
F00BCB8C: 113c0485a2122050         set     _static_KERNBOOTSTRUCT, %l1
F00BCB94: 113c04c8a0122070         set     dword_F0132070, %l0
F00BCB9C: d0040000                 ld      [%l0], %o0
F00BCBA0: 80a22000                 cmp     %o0, 0
F00BCBA4: 12bffffe                 bne     loc_F00BCB9C
F00BCBA8: 01000000                 nop
F00BCBAC: 7fff68bf                 call    _simple_lock_try
F00BCBB0: 90100010                 mov     %l0, %o0
F00BCBB4: 80a22000                 cmp     %o0, 0
F00BCBB8: 02bffff9                 be      loc_F00BCB9C
F00BCBBC: 96102001                 mov     1, %o3
F00BCBC0: d2046138                 ld      [%l1+0x138], %o1
F00BCBC4: 113c04fd                 sethi   %hi(_basicConsole), %o0
F00BCBC8: 80a26000                 cmp     %o1, 0
F00BCBCC: 02800003                 be      loc_F00BCBD8
F00BCBD0: d0022228                 ld      [%o0+%lo(_basicConsole)], %o0
F00BCBD4: 96102002                 mov     2, %o3
F00BCBD8: 80a2e002                 cmp     %o3, 2
F00BCBDC: 12800004                 bne     loc_F00BCBEC
F00BCBE0: 213c047f                 sethi   -0xFEE0400, %l0
F00BCBE4: 113c04fd                 sethi   %hi(_prettyp), %o0
F00BCBE8: d0022250                 ld      [%o0+%lo(_prettyp)], %o0
F00BCBEC: d40422bc                 ld      [%l0+0x2BC], %o2
F00BCBF0: 80a2a000                 cmp     %o2, 0
F00BCBF4: 04800020                 ble     loc_F00BCC74
F00BCBF8: 80a2e002                 cmp     %o3, 2
F00BCBFC: 02800005                 be      loc_F00BCC10
F00BCC00: 80a22000                 cmp     %o0, 0
F00BCC04: 9020000a                 neg     %o2, %o0
F00BCC08: 1080001b                 ba      loc_F00BCC74
F00BCC0C: d02422bc                 st      %o0, [%l0+0x2BC]
F00BCC10: 2280000b                 be,a    loc_F00BCC3C
F00BCC14: d00422bc                 ld      [%l0+0x2BC], %o0
F00BCC18: 932aa001                 sll     %o2, 1, %o1
F00BCC1C: 9202400a                 add     %o1, %o2, %o1
F00BCC20: 932a6002                 sll     %o1, 2, %o1
F00BCC24: 153c047f9412a21c         set     unk_F011FE1C, %o2
F00BCC2C: d602200c                 ld      [%o0+0xC], %o3
F00BCC30: 9fc2c000                 call    %o3
F00BCC34: 9202400a                 add     %o1, %o2, %o1
F00BCC38: d00422bc                 ld      [%l0+0x2BC], %o0
F00BCC3C: 90022001                 inc     %o0
F00BCC40: 80a22003                 cmp     %o0, 3
F00BCC44: 04800004                 ble     loc_F00BCC54
F00BCC48: d02422bc                 st      %o0, [%l0+0x2BC]
F00BCC4C: 90102001                 mov     1, %o0
F00BCC50: d02422bc                 st      %o0, [%l0+0x2BC]
F00BCC54: 113c02f290122388         set     sub_F00BCB88, %o0
F00BCC5C: 92102000                 mov     0, %o1
F00BCC60: 94102000                 mov     0, %o2
F00BCC64: 1701a7da9612e3c7         set     0x69F6BC7, %o3
F00BCC6C: 7ffec52e                 call    _ns_timeout
F00BCC70: 98102004                 mov     4, %o4
F00BCC74: 113c04c8                 sethi   %hi(dword_F0132070), %o0
F00BCC78: c0222070                 clr     [%o0+%lo(dword_F0132070)]
F00BCC7C: 81c7e008                 ret
F00BCC80: 81e80000                 restore
