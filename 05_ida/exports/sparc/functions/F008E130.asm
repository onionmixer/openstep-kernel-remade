F008E130: 9de3bf90                 save    %sp, -0x70, %sp
F008E134: d006201c                 ld      [%i0+0x1C], %o0! id
F008E138: 133c0504                 sethi   %hi(paAcquire), %o1! SEL
F008E13C: 40018dcd                 call    _objc_msgSend
F008E140: d2026098                 ld      [%o1+%lo(paAcquire)], %o1
F008E144: d0062014                 ld      [%i0+0x14], %o0! id
F008E148: 133c0504                 sethi   %hi(paIndexof), %o1
F008E14C: d20260a0                 ld      [%o1+%lo(paIndexof)], %o1! SEL
F008E150: 40018dc8                 call    _objc_msgSend
F008E154: 9410001a                 mov     %i2, %o2
F008E158: 80a23fff                 cmp     %o0, -1
F008E15C: 3280000e                 bne,a   loc_F008E194
F008E160: d0062024                 ld      [%i0+0x24], %o0
F008E164: d0062014                 ld      [%i0+0x14], %o0! id
F008E168: 133c0504                 sethi   %hi(paAddobject), %o1
F008E16C: d20260a4                 ld      [%o1+%lo(paAddobject)], %o1! SEL
F008E170: 40018dc0                 call    _objc_msgSend
F008E174: 9410001a                 mov     %i2, %o2
F008E178: 80a22000                 cmp     %o0, 0
F008E17C: 22800006                 be,a    loc_F008E194
F008E180: d0062024                 ld      [%i0+0x24], %o0
F008E184: d0062018                 ld      [%i0+0x18], %o0
F008E188: 90022001                 inc     %o0
F008E18C: d0262018                 st      %o0, [%i0+0x18]
F008E190: d0062024                 ld      [%i0+0x24], %o0! id
F008E194: 133c0504                 sethi   %hi(paAcquire), %o1! SEL
F008E198: 40018db6                 call    _objc_msgSend
F008E19C: d2026098                 ld      [%o1+%lo(paAcquire)], %o1! SEL
F008E1A0: d0062018                 ld      [%i0+0x18], %o0
F008E1A4: 80a22000                 cmp     %o0, 0
F008E1A8: 04800006                 ble     loc_F008E1C0
F008E1AC: b4102000                 mov     0, %i2
F008E1B0: d0062020                 ld      [%i0+0x20], %o0
F008E1B4: 80a00008                 cmp     %g0, %o0
F008E1B8: 90403fff                 addc    %g0, -1, %o0
F008E1BC: b40e0008                 and     %i0, %o0, %i2
F008E1C0: 113c0504                 sethi   %hi(paRelease), %o0
F008E1C4: e002209c                 ld      [%o0+%lo(paRelease)], %l0
F008E1C8: d0062024                 ld      [%i0+0x24], %o0! id
F008E1CC: 40018da9                 call    _objc_msgSend
F008E1D0: 92100010                 mov     %l0, %o1! SEL
F008E1D4: d006201c                 ld      [%i0+0x1C], %o0! id
F008E1D8: 40018da6                 call    _objc_msgSend
F008E1DC: 92100010                 mov     %l0, %o1
F008E1E0: 81c7e008                 ret
F008E1E4: 91e8001a                 restore %g0, %i2, %o0
