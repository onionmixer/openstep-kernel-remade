F0013070: 9de3bf90                 save    %sp, -0x70, %sp
F0013074: 1107fd1a9012237f         set     0x1FF46B7F, %o0
F001307C: 80a60008                 cmp     %i0, %o0
F0013080: 08800004                 bleu    loc_F0013090
F0013084: 80a62000                 cmp     %i0, 0
F0013088: 16800007                 bge     loc_F00130A4
F001308C: a007bff0                 add     %fp, var_10, %l0
F0013090: 113c042c                 sethi   %hi(aWarningPrepost), %o0! "WARNING: preposterous time in file syst"...
F0013094: 40000571                 call    _printf
F0013098: 90122358                 bset    %lo(aWarningPrepost), %o0! "WARNING: preposterous time in file syst"...
F001309C: 10800034                 ba      loc_F001316C
F00130A0: 113c042c                 sethi   -0xFEF5000, %o0
F00130A4: 40016d4b                 call    _microtime
F00130A8: 90100010                 mov     %l0, %o0
F00130AC: 233c04d4                 sethi   %hi(_boottime), %l1
F00130B0: d407bff0                 ld      [%fp+var_10], %o2
F00130B4: a4146168                 or      %l1, %lo(_boottime), %l2
F00130B8: c024a004                 clr     [%l2+4]
F00130BC: 92a28018                 subcc   %o2, %i0, %o1
F00130C0: 1c800003                 bpos    loc_F00130CC
F00130C4: d4246168                 st      %o2, [%l1+%lo(_boottime)]
F00130C8: 92200009                 neg     %o1
F00130CC: 110000a8901222ff         set     0x2A2FF, %o0
F00130D4: 80a24008                 cmp     %o1, %o0
F00130D8: 18800004                 bgu     loc_F00130E8
F00130DC: 80a28018                 cmp     %o2, %i0
F00130E0: 14800025                 bg      locret_F0013174
F00130E4: 01000000                 nop
F00130E8: 1100784c9012237f         set     0x1E1337F, %o0
F00130F0: 80a28008                 cmp     %o2, %o0
F00130F4: 18800004                 bgu     loc_F0013104
F00130F8: 113c042c                 sethi   %hi(aWarningClockNo), %o0! "WARNING: clock not set properly"
F00130FC: 10800009                 ba      loc_F0013120
F0013100: 90122388                 bset    %lo(aWarningClockNo), %o0! "WARNING: clock not set properly"
F0013104: 11001da990122300         set     0x76A700, %o0
F001310C: 80a24008                 cmp     %o1, %o0
F0013110: 2880000e                 bleu,a  loc_F0013148
F0013114: 90100009                 mov     %o1, %o0
F0013118: 113c042c901223a8         set     aWarningPrepost_0, %o0! "WARNING: preposterous time in Real Time"...
F0013120: 4000054e                 call    _printf
F0013124: 01000000                 nop
F0013128: f027bff0                 st      %i0, [%fp+var_10]
F001312C: c027bff4                 clr     [%fp+var_10+4]
F0013130: 7fffff7a                 call    _setthetime
F0013134: 90100010                 mov     %l0, %o0
F0013138: d01fbff0                 ldd     [%fp+var_10], %o0! char *
F001313C: d0246168                 st      %o0, [%l1+0x168]
F0013140: 1080000a                 ba      loc_F0013168
F0013144: d224a004                 st      %o1, [%l2+4]
F0013148: 1300005492126180         set     0x15180, %o1
F0013150: 213c042c                 sethi   %hi(aWarningClockLo), %l0! "WARNING: clock lost %d days"
F0013154: 7fffcd2b                 call    _udiv
F0013158: a01423d8                 bset    %lo(aWarningClockLo), %l0! "WARNING: clock lost %d days"
F001315C: 92100008                 mov     %o0, %o1
F0013160: 4000053e                 call    _printf
F0013164: 90100010                 mov     %l0, %o0
F0013168: 113c042c                 sethi   -0xFEF5000, %o0! char *
F001316C: 4000053b                 call    _printf
F0013170: 901223f8                 bset    0x3F8, %o0
F0013174: 81c7e008                 ret
F0013178: 81e80000                 restore
