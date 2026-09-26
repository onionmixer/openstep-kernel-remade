F00D6170: 9de3bf90                 save    %sp, -0x70, %sp
F00D6174: 9010001a                 mov     %i2, %o0! id
F00D6178: 133c0504                 sethi   %hi(paConformsto), %o1
F00D617C: d2026018                 ld      [%o1+%lo(paConformsto)], %o1! SEL
F00D6180: 153c0516                 sethi   %hi(stru_F0145ADC), %o2
F00D6184: 40006dbb                 call    _objc_msgSend
F00D6188: 9412a2dc                 bset    %lo(stru_F0145ADC), %o2
F00D618C: 912a2018                 sll     %o0, 24, %o0
F00D6190: 80a22000                 cmp     %o0, 0
F00D6194: 02800004                 be      loc_F00D61A4
F00D6198: 9010001a                 mov     %i2, %o0! id
F00D619C: 10800008                 ba      locret_F00D61BC
F00D61A0: f42624f8                 st      %i2, [%i0+0x4F8]
F00D61A4: 213c03f0                 sethi   %hi(aKeymapSetdeleg), %l0! "KeyMap setDelegate: new delegate [%s] d"...
F00D61A8: 400063f8                 call    _object_getClassName
F00D61AC: a01420a8                 bset    %lo(aKeymapSetdeleg), %l0! "KeyMap setDelegate: new delegate [%s] d"...
F00D61B0: 92100008                 mov     %o0, %o1
F00D61B4: 7fffbfd0                 call    _IOLog
F00D61B8: 90100010                 mov     %l0, %o0
F00D61BC: 81c7e008                 ret
F00D61C0: 81e80000                 restore
