F00696F0: 9de3bf98                 save    %sp, -0x68, %sp
F00696F4: a0062008                 add     %i0, 8, %l0
F00696F8: d0040000                 ld      [%l0], %o0
F00696FC: 80a22000                 cmp     %o0, 0
F0069700: 12bffffe                 bne     loc_F00696F8
F0069704: 01000000                 nop
F0069708: 4000b5e8                 call    _simple_lock_try
F006970C: 90100010                 mov     %l0, %o0
F0069710: 80a22000                 cmp     %o0, 0
F0069714: 02bffff9                 be      loc_F00696F8
F0069718: 11000010                 sethi   0x4000, %o0
F006971C: d2062004                 ld      [%i0+4], %o1
F0069720: 808a4008                 btst    %o0, %o1
F0069724: 32800006                 bne,a   loc_F006973C
F0069728: 113c04d0                 sethi   -0xFECC000, %o0
F006972C: 113c043e                 sethi   %hi(aLockSetRecursi), %o0! "lock_set_recursive: don't have write lo"...
F0069730: 7ffeae90                 call    _panic
F0069734: 90122388                 bset    %lo(aLockSetRecursi), %o0! "lock_set_recursive: don't have write lo"...
F0069738: 113c04d0                 sethi   -0xFECC000, %o0
F006973C: d0022260                 ld      [%o0+0x260], %o0
F0069740: d0260000                 st      %o0, [%i0]
F0069744: c0262008                 clr     [%i0+8]
F0069748: 81c7e008                 ret
F006974C: 81e80000                 restore
