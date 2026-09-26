F00AEE64: 9de3bf18                 save    %sp, -0xE8, %sp
F00AEE68: 90100018                 mov     %i0, %o0
F00AEE6C: 133c0470                 sethi   %hi(aDeviceType), %o1! "device_type"
F00AEE70: 4000005b                 call    _prom_getproplen
F00AEE74: 92126158                 bset    %lo(aDeviceType), %o1! "device_type"
F00AEE78: 80a22000                 cmp     %o0, 0
F00AEE7C: 04800004                 ble     loc_F00AEE8C
F00AEE80: 80a2207f                 cmp     %o0, 0x7F
F00AEE84: 08800004                 bleu    loc_F00AEE94
F00AEE88: 90100018                 mov     %i0, %o0
F00AEE8C: 1080000c                 ba      locret_F00AEEBC
F00AEE90: b0102000                 mov     0, %i0
F00AEE94: 133c047092126168         set     aDeviceType_0, %o1! "device_type"
F00AEE9C: a007bf78                 add     %fp, var_88, %l0
F00AEEA0: 40000059                 call    _prom_getprop
F00AEEA4: 94100010                 mov     %l0, %o2
F00AEEA8: 90100019                 mov     %i1, %o0! __s1
F00AEEAC: 7ffd64c0                 call    _strcmp
F00AEEB0: 92100010                 mov     %l0, %o1
F00AEEB4: 80a00008                 cmp     %g0, %o0
F00AEEB8: b0603fff                 subc    %g0, -1, %i0
F00AEEBC: 81c7e008                 ret
F00AEEC0: 81e80000                 restore
