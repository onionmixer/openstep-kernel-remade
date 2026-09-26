F0096DA8: 80920000                 tst     %o0
F0096DAC: 0480000d                 ble     locret_F0096DE0
F0096DB0: 98100000                 clr     %o4
F0096DB4: c20a400c                 ldub    [%o1+%o4], %g1
F0096DB8: c20ac001                 ldub    [%o3+%g1], %g1
F0096DBC: 80904000                 tst     %g1
F0096DC0: 12800004                 bne     loc_F0096DD0
F0096DC4: c22a800c                 stb     %g1, [%o2+%o4]
F0096DC8: 81c3e008                 retl
F0096DCC: 9010000c                 mov     %o4, %o0
F0096DD0: 98032001                 inc     %o4
F0096DD4: 80a30008                 cmp     %o4, %o0
F0096DD8: 26bffff8                 bl,a    loc_F0096DB8
F0096DDC: c20a400c                 ldub    [%o1+%o4], %g1
F0096DE0: 81c3e008                 retl
F0096DE4: 9010000c                 mov     %o4, %o0
