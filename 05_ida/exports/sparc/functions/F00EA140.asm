F00EA140: 9de3bf90                 save    %sp, -0x70, %sp
F00EA144: 113c0504                 sethi   %hi(paDevicedescript_1), %o0! id
F00EA148: d2022158                 ld      [%o0+%lo(paDevicedescript_1)], %o1! SEL
F00EA14C: 40001dc9                 call    _objc_msgSend
F00EA150: 90100018                 mov     %i0, %o0! id
F00EA154: 133c0504                 sethi   %hi(paConfigtable_0), %o1! SEL
F00EA158: 40001dc6                 call    _objc_msgSend
F00EA15C: d2026310                 ld      [%o1+%lo(paConfigtable_0)], %o1
F00EA160: 80a22000                 cmp     %o0, 0
F00EA164: 0280000e                 be      loc_F00EA19C
F00EA168: 133c0504                 sethi   %hi(paValueforstring), %o1
F00EA16C: d20260e8                 ld      [%o1+%lo(paValueforstring)], %o1! SEL
F00EA170: 153c03f3                 sethi   %hi(aDisplayMode), %o2! "Display Mode"
F00EA174: 40001dbf                 call    _objc_msgSend
F00EA178: 9412a108                 bset    %lo(aDisplayMode), %o2! "Display Mode"
F00EA17C: 94920000                 orcc    %o0, %g0, %o2
F00EA180: 02800007                 be      loc_F00EA19C
F00EA184: 133c0504                 sethi   %hi(paValidmode), %o1
F00EA188: d2026398                 ld      [%o1+%lo(paValidmode)], %o1! SEL
F00EA18C: 40001db9                 call    _objc_msgSend
F00EA190: 90100018                 mov     %i0, %o0
F00EA194: 10800003                 ba      locret_F00EA1A0
F00EA198: b0100008                 mov     %o0, %i0
F00EA19C: b0102000                 mov     0, %i0
F00EA1A0: 81c7e008                 ret
F00EA1A4: 81e80000                 restore
