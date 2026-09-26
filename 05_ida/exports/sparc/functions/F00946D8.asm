F00946D8: 9de3bf98                 save    %sp, -0x68, %sp
F00946DC: 113c044a90122080         set     aKdpPanicS, %o0! "kdp panic: %s\n"
F00946E4: 7fff6645                 call    _safe_prf
F00946E8: 92100018                 mov     %i0, %o1
F00946EC: 90102001                 mov     1, %o0
F00946F0: 9210200c                 mov     0xC, %o1
F00946F4: 153c044a                 sethi   %hi(unk_F0112890), %o2
F00946F8: 7ffdef63                 call    _boot
F00946FC: 9412a090                 bset    %lo(unk_F0112890), %o2
F0094700: 81c7e008                 ret
F0094704: 81e80000                 restore
