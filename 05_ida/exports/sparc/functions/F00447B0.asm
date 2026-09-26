F00447B0: 9de3bf90                 save    %sp, -0x70, %sp
F00447B4: 90100018                 mov     %i0, %o0
F00447B8: 92100019                 mov     %i1, %o1
F00447BC: 40000013                 call    sub_F0044808
F00447C0: 9407bff4                 add     %fp, var_C, %o2
F00447C4: 94920000                 orcc    %o0, %g0, %o2
F00447C8: 0280000e                 be      locret_F0044800
F00447CC: d207bff4                 ld      [%fp+var_C], %o1
F00447D0: 80a26000                 cmp     %o1, 0
F00447D4: 32800006                 bne,a   loc_F00447EC
F00447D8: d0028000                 ld      [%o2], %o0
F00447DC: d2028000                 ld      [%o2], %o1
F00447E0: 113c04bd                 sethi   %hi(dword_F012F558), %o0
F00447E4: 10800003                 ba      loc_F00447F0
F00447E8: d2222158                 st      %o1, [%o0+%lo(dword_F012F558)]
F00447EC: d0224000                 st      %o0, [%o1]
F00447F0: c0228000                 clr     [%o2]
F00447F4: 9010000a                 mov     %o2, %o0
F00447F8: 40008e6a                 call    _kfree
F00447FC: 92102010                 mov     0x10, %o1
F0044800: 81c7e008                 ret
F0044804: 81e80000                 restore
