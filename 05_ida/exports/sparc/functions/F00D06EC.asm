F00D06EC: 9de3bf78                 save    %sp, -0x88, %sp
F00D06F0: a2100018                 mov     %i0, %l1
F00D06F4: d0046118                 ld      [%l1+0x118], %o0
F00D06F8: 80a68008                 cmp     %i2, %o0
F00D06FC: 12800004                 bne     loc_F00D070C
F00D0700: 113c0505                 sethi   -0xFEBEC00, %o0! id
F00D0704: 10800019                 ba      locret_F00D0768
F00D0708: b0102000                 mov     0, %i0
F00D070C: d2022368                 ld      [%o0+0x368], %o1! SEL
F00D0710: 40008458                 call    _objc_msgSend
F00D0714: 90100011                 mov     %l1, %o0
F00D0718: a007bfe0                 add     %fp, var_20, %l0
F00D071C: 90100010                 mov     %l0, %o0! char *
F00D0720: 133c03ec92126228         set     aScD, %o1! "sc%d"
F00D0728: 7ffd1010                 call    _sprintf
F00D072C: 9410001a                 mov     %i2, %o2
F00D0730: 90100010                 mov     %l0, %o0
F00D0734: 7fffcfbb                 call    _IOGetObjectForDeviceName
F00D0738: 9207bfdc                 add     %fp, var_24, %o1
F00D073C: 80a22000                 cmp     %o0, 0
F00D0740: 1280000a                 bne     locret_F00D0768
F00D0744: b0103d40                 mov     -0x2C0, %i0
F00D0748: f4246118                 st      %i2, [%l1+0x118]
F00D074C: d007bfdc                 ld      [%fp+var_24], %o0
F00D0750: b0102000                 mov     0, %i0
F00D0754: d2046124                 ld      [%l1+0x124], %o1
F00D0758: d0246128                 st      %o0, [%l1+0x128]
F00D075C: 11200000                 sethi   0x80000000, %o0
F00D0760: 902a4008                 andn    %o1, %o0, %o0
F00D0764: d0246124                 st      %o0, [%l1+0x124]
F00D0768: 81c7e008                 ret
F00D076C: 81e80000                 restore
