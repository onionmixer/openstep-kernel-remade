F00D4200: 9de3bf90                 save    %sp, -0x70, %sp
F00D4204: 90100018                 mov     %i0, %o0! id
F00D4208: 133c0505                 sethi   %hi(paSetaudiovolume), %o1
F00D420C: d2026298                 ld      [%o1+%lo(paSetaudiovolume)], %o1! SEL
F00D4210: 40007598                 call    _objc_msgSend
F00D4214: 9410001a                 mov     %i2, %o2
F00D4218: 90100018                 mov     %i0, %o0! id
F00D421C: 94102000                 mov     0, %o2
F00D4220: 133c0505                 sethi   %hi(paEvspecialkeyms), %o1
F00D4224: d2026294                 ld      [%o1+%lo(paEvspecialkeyms)], %o1! SEL
F00D4228: 9610200a                 mov     0xA, %o3
F00D422C: da0221c4                 ld      [%o0+0x1C4], %o5
F00D4230: 40007590                 call    _objc_msgSend
F00D4234: 98102000                 mov     0, %o4
F00D4238: 81c7e008                 ret
F00D423C: 81e80000                 restore
