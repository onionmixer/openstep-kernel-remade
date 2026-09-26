F00D64EC: 9de3bf80                 save    %sp, -0x80, %sp
F00D64F0: 9006001a                 add     %i0, %i2, %o0
F00D64F4: e04a2006                 ldsb    [%o0+6], %l0
F00D64F8: 808c2010                 btst    0x10, %l0
F00D64FC: 02800024                 be      locret_F00D658C
F00D6500: 9610001b                 mov     %i3, %o3
F00D6504: 90100018                 mov     %i0, %o0! id
F00D6508: 133c0505                 sethi   %hi(paCalcmodbitKeyb), %o1
F00D650C: d202623c                 ld      [%o1+%lo(paCalcmodbitKeyb)], %o1! SEL
F00D6510: 40006cd8                 call    _objc_msgSend
F00D6514: 940c200f                 and     %l0, 0xF, %o2
F00D6518: 808c2020                 btst    0x20, %l0 ! ' '
F00D651C: 12800012                 bne     loc_F00D6564
F00D6520: 113c0505                 sethi   -0xFEBEC00, %o0
F00D6524: d00624f8                 ld      [%i0+0x4F8], %o0! id
F00D6528: 133c0505                 sethi   %hi(paEventflags), %o1! SEL
F00D652C: 40006cd1                 call    _objc_msgSend
F00D6530: d2026238                 ld      [%o1+%lo(paEventflags)], %o1
F00D6534: 9410200c                 mov     0xC, %o2
F00D6538: 96100008                 mov     %o0, %o3
F00D653C: 133c0505                 sethi   %hi(paKeyboardeventF), %o1
F00D6540: 9810001a                 mov     %i2, %o4
F00D6544: d00624f8                 ld      [%i0+0x4F8], %o0! id
F00D6548: 9a102000                 mov     0, %o5
F00D654C: d2026234                 ld      [%o1+%lo(paKeyboardeventF)], %o1! SEL
F00D6550: c023a05c                 clr     [%sp+0x80+var_24]
F00D6554: c023a060                 clr     [%sp+0x80+var_20]
F00D6558: 40006cc6                 call    _objc_msgSend
F00D655C: c023a064                 clr     [%sp+0x80+var_1C]
F00D6560: 3080000b                 ba,a    locret_F00D658C
F00D6564: d2022238                 ld      [%o0+0x238], %o1! SEL
F00D6568: e00624f8                 ld      [%i0+0x4F8], %l0
F00D656C: 113c0504                 sethi   %hi(paUpdateeventfla), %o0! id
F00D6570: e20222a8                 ld      [%o0+%lo(paUpdateeventfla)], %l1
F00D6574: 40006cbf                 call    _objc_msgSend
F00D6578: 90100010                 mov     %l0, %o0
F00D657C: 94100008                 mov     %o0, %o2
F00D6580: 90100010                 mov     %l0, %o0! id
F00D6584: 40006cbb                 call    _objc_msgSend
F00D6588: 92100011                 mov     %l1, %o1
F00D658C: 81c7e008                 ret
F00D6590: 81e80000                 restore
