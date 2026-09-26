F00BC5A0: 9de3bf90                 save    %sp, -0x70, %sp
F00BC5A4: 113c047f90122300         set     aType5keyboard0, %o0! "TYPE5Keyboard0"
F00BC5AC: 4000201d                 call    _IOGetObjectForDeviceName
F00BC5B0: 92062120                 add     %i0, 0x120, %o1
F00BC5B4: 94920000                 orcc    %o0, %g0, %o2
F00BC5B8: 02800007                 be      loc_F00BC5D4
F00BC5BC: 90100018                 mov     %i0, %o0
F00BC5C0: 133c0504                 sethi   %hi(paStringfromretu), %o1
F00BC5C4: d2026260                 ld      [%o1+%lo(paStringfromretu)], %o1
F00BC5C8: 213c047f                 sethi   %hi(aKmInitCanTFind), %l0! "km init: Can't find TYPE5Keyboard0 (%s)"...
F00BC5CC: 1080001b                 ba      loc_F00BC638
F00BC5D0: a0142310                 bset    %lo(aKmInitCanTFind), %l0! "km init: Can't find TYPE5Keyboard0 (%s)"...
F00BC5D4: d0062120                 ld      [%i0+0x120], %o0! id
F00BC5D8: 133c0504                 sethi   %hi(paBecomeowner), %o1
F00BC5DC: d2026264                 ld      [%o1+%lo(paBecomeowner)], %o1! SEL
F00BC5E0: 4000d4a4                 call    _objc_msgSend
F00BC5E4: 94100018                 mov     %i0, %o2
F00BC5E8: 94920000                 orcc    %o0, %g0, %o2
F00BC5EC: 02800007                 be      loc_F00BC608
F00BC5F0: 90100018                 mov     %i0, %o0
F00BC5F4: 133c0504                 sethi   %hi(paStringfromretu), %o1
F00BC5F8: d2026260                 ld      [%o1+%lo(paStringfromretu)], %o1
F00BC5FC: 213c047f                 sethi   %hi(aKmInitBecomeow), %l0! "km init: becomeOwner failed (%s)\n"
F00BC600: 1080000e                 ba      loc_F00BC638
F00BC604: a0142340                 bset    %lo(aKmInitBecomeow), %l0! "km init: becomeOwner failed (%s)\n"
F00BC608: d0062120                 ld      [%i0+0x120], %o0! id
F00BC60C: 133c0504                 sethi   %hi(paDesireownershi), %o1
F00BC610: d2026268                 ld      [%o1+%lo(paDesireownershi)], %o1! SEL
F00BC614: 4000d497                 call    _objc_msgSend
F00BC618: 94100018                 mov     %i0, %o2
F00BC61C: 94920000                 orcc    %o0, %g0, %o2
F00BC620: 0280000b                 be      locret_F00BC64C
F00BC624: 90100018                 mov     %i0, %o0! id
F00BC628: 133c0504                 sethi   %hi(paStringfromretu), %o1
F00BC62C: d2026260                 ld      [%o1+%lo(paStringfromretu)], %o1! SEL
F00BC630: 213c047fa0142368         set     aKmInitDesireow, %l0! "km init: desireOwnership failed (%s)\n"
F00BC638: 4000d48e                 call    _objc_msgSend
F00BC63C: b0102000                 mov     0, %i0
F00BC640: 92100008                 mov     %o0, %o1
F00BC644: 400026ac                 call    _IOLog
F00BC648: 90100010                 mov     %l0, %o0
F00BC64C: 81c7e008                 ret
F00BC650: 81e80000                 restore
