F0040740: 9de3bf40                 save    %sp, -0xC0, %sp
F0040744: a2100018                 mov     %i0, %l1
F0040748: a007bfb0                 add     %fp, var_50, %l0
F004074C: 90100010                 mov     %l0, %o0
F0040750: 92100019                 mov     %i1, %o1
F0040754: 7ffff124                 call    _setdiropargs
F0040758: 94100011                 mov     %l1, %o2
F004075C: 9010001a                 mov     %i2, %o0
F0040760: 7ffff108                 call    _vattr_to_sattr
F0040764: 9207bfd8                 add     %fp, var_28, %o1
F0040768: f627bfd4                 st      %i3, [%fp+var_2C]
F004076C: 9210200d                 mov     0xD, %o1
F0040770: 153c01089412a3e4         set     _xdr_slargs, %o2
F0040778: 193c0115                 sethi   %hi(_xdr_enum), %o4
F004077C: 96100010                 mov     %l0, %o3
F0040780: d0046024                 ld      [%l1+0x24], %o0
F0040784: 98132348                 bset    %lo(_xdr_enum), %o4
F0040788: d0022128                 ld      [%o0+0x128], %o0
F004078C: 9a07bfac                 add     %fp, var_54, %o5
F0040790: 7fffeff9                 call    _rfscall
F0040794: f823a05c                 st      %i4, [%sp+0xC0+var_64]
F0040798: b0100008                 mov     %o0, %i0
F004079C: d0046030                 ld      [%l1+0x30], %o0
F00407A0: 80a62000                 cmp     %i0, 0
F00407A4: 1280000a                 bne     locret_F00407CC
F00407A8: c02220c0                 clr     [%o0+0xC0]
F00407AC: f007bfac                 ld      [%fp+var_54], %i0
F00407B0: 80a62046                 cmp     %i0, 0x46 ! 'F'
F00407B4: 12800006                 bne     locret_F00407CC
F00407B8: 01000000                 nop
F00407BC: 7fff9350                 call    _btrash
F00407C0: 90100011                 mov     %l1, %o0
F00407C4: 7fffe399                 call    _nfs_invalidate_caches
F00407C8: 90100011                 mov     %l1, %o0
F00407CC: 81c7e008                 ret
F00407D0: 81e80000                 restore
