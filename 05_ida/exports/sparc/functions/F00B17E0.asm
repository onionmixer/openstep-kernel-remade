F00B17E0: 9de3bf98                 save    %sp, -0x68, %sp
F00B17E4: 90100018                 mov     %i0, %o0
F00B17E8: 92100019                 mov     %i1, %o1
F00B17EC: 7fffffe6                 call    _find_slave_devinfo
F00B17F0: 9410001a                 mov     %i2, %o2
F00B17F4: 80a22000                 cmp     %o0, 0
F00B17F8: 0280000f                 be      loc_F00B1834
F00B17FC: 80a62000                 cmp     %i0, 0
F00B1800: 10800010                 ba      locret_F00B1840
F00B1804: b0100008                 mov     %o0, %i0
F00B1808: 80a22000                 cmp     %o0, 0
F00B180C: 22800009                 be,a    loc_F00B1830
F00B1810: f0062004                 ld      [%i0+4], %i0
F00B1814: 92100019                 mov     %i1, %o1
F00B1818: 7ffffff2                 call    _find_devinfo
F00B181C: 9410001a                 mov     %i2, %o2
F00B1820: 80a22000                 cmp     %o0, 0
F00B1824: 32800007                 bne,a   locret_F00B1840
F00B1828: b0100008                 mov     %o0, %i0
F00B182C: f0062004                 ld      [%i0+4], %i0
F00B1830: 80a62000                 cmp     %i0, 0
F00B1834: 32bffff5                 bne,a   loc_F00B1808
F00B1838: d0062008                 ld      [%i0+8], %o0
F00B183C: b0102000                 mov     0, %i0
F00B1840: 81c7e008                 ret
F00B1844: 81e80000                 restore
