F008E2E4: 9de3bf90                 save    %sp, -0x70, %sp
F008E2E8: a0100018                 mov     %i0, %l0
F008E2EC: d0042024                 ld      [%l0+0x24], %o0! id
F008E2F0: 133c0504                 sethi   %hi(paAcquire), %o1! SEL
F008E2F4: 40018d5f                 call    _objc_msgSend
F008E2F8: d2026098                 ld      [%o1+%lo(paAcquire)], %o1
F008E2FC: d0042020                 ld      [%l0+0x20], %o0
F008E300: 80a22000                 cmp     %o0, 0
F008E304: 04800003                 ble     loc_F008E310
F008E308: 90023fff                 inc     -1, %o0
F008E30C: d0242020                 st      %o0, [%l0+0x20]
F008E310: d0042024                 ld      [%l0+0x24], %o0! id
F008E314: d4042020                 ld      [%l0+0x20], %o2
F008E318: 133c0504                 sethi   %hi(paRelease), %o1
F008E31C: d202609c                 ld      [%o1+%lo(paRelease)], %o1! SEL
F008E320: 80a0000a                 cmp     %g0, %o2
F008E324: b0403fff                 addc    %g0, -1, %i0
F008E328: 40018d52                 call    _objc_msgSend
F008E32C: b00c0018                 and     %l0, %i0, %i0
F008E330: 81c7e008                 ret
F008E334: 81e80000                 restore
