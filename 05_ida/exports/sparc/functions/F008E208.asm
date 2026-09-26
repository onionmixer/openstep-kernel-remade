F008E208: 9de3bf90                 save    %sp, -0x70, %sp
F008E20C: 113c0504                 sethi   %hi(paAcquire), %o0
F008E210: e0022098                 ld      [%o0+%lo(paAcquire)], %l0
F008E214: d006201c                 ld      [%i0+0x1C], %o0! id
F008E218: 40018d96                 call    _objc_msgSend
F008E21C: 92100010                 mov     %l0, %o1
F008E220: d0062014                 ld      [%i0+0x14], %o0! id
F008E224: 133c0504                 sethi   %hi(paRemoveobject), %o1
F008E228: d20260ac                 ld      [%o1+%lo(paRemoveobject)], %o1! SEL
F008E22C: 40018d91                 call    _objc_msgSend
F008E230: 9410001a                 mov     %i2, %o2
F008E234: 80a22000                 cmp     %o0, 0
F008E238: 22800006                 be,a    loc_F008E250
F008E23C: d0062024                 ld      [%i0+0x24], %o0
F008E240: d0062018                 ld      [%i0+0x18], %o0
F008E244: 90023fff                 inc     -1, %o0
F008E248: d0262018                 st      %o0, [%i0+0x18]
F008E24C: d0062024                 ld      [%i0+0x24], %o0! id
F008E250: 40018d88                 call    _objc_msgSend
F008E254: 92100010                 mov     %l0, %o1! SEL
F008E258: d0062018                 ld      [%i0+0x18], %o0
F008E25C: 80a22000                 cmp     %o0, 0
F008E260: 04800006                 ble     loc_F008E278
F008E264: b4102000                 mov     0, %i2
F008E268: d0062020                 ld      [%i0+0x20], %o0
F008E26C: 80a00008                 cmp     %g0, %o0
F008E270: 90403fff                 addc    %g0, -1, %o0
F008E274: b40e0008                 and     %i0, %o0, %i2
F008E278: 113c0504                 sethi   %hi(paRelease), %o0
F008E27C: e002209c                 ld      [%o0+%lo(paRelease)], %l0
F008E280: d0062024                 ld      [%i0+0x24], %o0! id
F008E284: 40018d7b                 call    _objc_msgSend
F008E288: 92100010                 mov     %l0, %o1! SEL
F008E28C: d006201c                 ld      [%i0+0x1C], %o0! id
F008E290: 40018d78                 call    _objc_msgSend
F008E294: 92100010                 mov     %l0, %o1
F008E298: 81c7e008                 ret
F008E29C: 91e8001a                 restore %g0, %i2, %o0
