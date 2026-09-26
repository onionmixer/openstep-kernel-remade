F00BCC84: 9de3bf98                 save    %sp, -0x68, %sp
F00BCC88: 133c04c8                 sethi   %hi(dword_F0132074), %o1
F00BCC8C: d0026074                 ld      [%o1+%lo(dword_F0132074)], %o0
F00BCC90: 80a22000                 cmp     %o0, 0
F00BCC94: 113c0485                 sethi   %hi(_static_KERNBOOTSTRUCT), %o0
F00BCC98: 12800006                 bne     loc_F00BCCB0
F00BCC9C: 94122050                 or      %o0, %lo(_static_KERNBOOTSTRUCT), %o2
F00BCCA0: 113c04c8                 sethi   %hi(dword_F0132070), %o0
F00BCCA4: c0222070                 clr     [%o0+%lo(dword_F0132070)]
F00BCCA8: 90102001                 mov     1, %o0
F00BCCAC: d0226074                 st      %o0, [%o1+%lo(dword_F0132074)]
F00BCCB0: d002a138                 ld      [%o2+0x138], %o0
F00BCCB4: 80a22000                 cmp     %o0, 0
F00BCCB8: 0280001e                 be      locret_F00BCD30
F00BCCBC: 113c04c8                 sethi   %hi(dword_F0132070), %o0
F00BCCC0: a0122070                 or      %o0, %lo(dword_F0132070), %l0
F00BCCC4: d0040000                 ld      [%l0], %o0
F00BCCC8: 80a22000                 cmp     %o0, 0
F00BCCCC: 12bffffe                 bne     loc_F00BCCC4
F00BCCD0: 01000000                 nop
F00BCCD4: 7fff6875                 call    _simple_lock_try
F00BCCD8: 90100010                 mov     %l0, %o0
F00BCCDC: 80a22000                 cmp     %o0, 0
F00BCCE0: 02bffff9                 be      loc_F00BCCC4
F00BCCE4: 133c047f                 sethi   %hi(dword_F011FEBC), %o1
F00BCCE8: 90102001                 mov     1, %o0
F00BCCEC: d02262bc                 st      %o0, [%o1+%lo(dword_F011FEBC)]
F00BCCF0: 113c04c8                 sethi   %hi(dword_F0132070), %o0
F00BCCF4: c0222070                 clr     [%o0+%lo(dword_F0132070)]
F00BCCF8: 4000a061                 call    _sparcfbConfigDisplay
F00BCCFC: 90102000                 mov     0, %o0
F00BCD00: 40000886                 call    _FBAllocateConsole
F00BCD04: 01000000                 nop
F00BCD08: 133c04fd                 sethi   %hi(_prettyp), %o1
F00BCD0C: d0226250                 st      %o0, [%o1+%lo(_prettyp)]
F00BCD10: da022004                 ld      [%o0+4], %o5
F00BCD14: 92102002                 mov     2, %o1
F00BCD18: 94102000                 mov     0, %o2
F00BCD1C: 96102000                 mov     0, %o3
F00BCD20: 9fc34000                 call    %o5
F00BCD24: 98102000                 mov     0, %o4
F00BCD28: 7fffff98                 call    sub_F00BCB88
F00BCD2C: 01000000                 nop
F00BCD30: 81c7e008                 ret
F00BCD34: 81e80000                 restore
