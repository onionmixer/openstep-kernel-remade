F00CAAE8: 9de3bf90                 save    %sp, -0x70, %sp
F00CAAEC: d206200c                 ld      [%i0+0xC], %o1
F00CAAF0: d0062010                 ld      [%i0+0x10], %o0
F00CAAF4: 80a24008                 cmp     %o1, %o0
F00CAAF8: 1a80000e                 bcc     loc_F00CAB30
F00CAAFC: 9410001a                 mov     %i2, %o2
F00CAB00: 90026001                 add     %o1, 1, %o0
F00CAB04: 80a26000                 cmp     %o1, 0
F00CAB08: 02800006                 be      loc_F00CAB20
F00CAB0C: d026200c                 st      %o0, [%i0+0xC]
F00CAB10: d0062008                 ld      [%i0+8], %o0
F00CAB14: f4220000                 st      %i2, [%o0]
F00CAB18: 10800004                 ba      loc_F00CAB28
F00CAB1C: f4262008                 st      %i2, [%i0+8]
F00CAB20: f4262008                 st      %i2, [%i0+8]
F00CAB24: f4262004                 st      %i2, [%i0+4]
F00CAB28: 10800004                 ba      locret_F00CAB38
F00CAB2C: c0228000                 clr     [%o2]
F00CAB30: 7ffd83dd                 call    _nb_free
F00CAB34: 9010001a                 mov     %i2, %o0
F00CAB38: 81c7e008                 ret
F00CAB3C: 81e80000                 restore
