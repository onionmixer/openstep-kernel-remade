F00C2154: 9de3bf80                 save    %sp, -0x80, %sp
F00C2158: 90100018                 mov     %i0, %o0! id
F00C215C: 133c0504                 sethi   %hi(paInterruptport_0), %o1
F00C2160: d2026308                 ld      [%o1+%lo(paInterruptport_0)], %o1! SEL
F00C2164: aa102018                 mov     0x18, %l5
F00C2168: 293c0484                 sethi   -0xFEDF000, %l4
F00C216C: 273c0504                 sethi   -0xFEBF000, %l3
F00C2170: 253c0484                 sethi   -0xFEDF000, %l2
F00C2174: 4000bdbf                 call    _objc_msgSend
F00C2178: a007bfe0                 add     %fp, var_20, %l0
F00C217C: 110008c8a2122325         set     0x232325, %l1
F00C2184: ea242004                 st      %l5, [%l0+4]
F00C2188: 90100010                 mov     %l0, %o0
F00C218C: d4062130                 ld      [%i0+0x130], %o2
F00C2190: 92102000                 mov     0, %o1
F00C2194: d424200c                 st      %o2, [%l0+0xC]
F00C2198: 7ffe8f31                 call    _msg_receive
F00C219C: 94102000                 mov     0, %o2
F00C21A0: 92920000                 orcc    %o0, %g0, %o1
F00C21A4: 22800006                 be,a    loc_F00C21BC
F00C21A8: d0042014                 ld      [%l0+0x14], %o0
F00C21AC: 40000fd2                 call    _IOLog
F00C21B0: 90152138                 or      %l4, 0x138, %o0
F00C21B4: 10bffff5                 ba      loc_F00C2188
F00C21B8: ea242004                 st      %l5, [%l0+4]
F00C21BC: 80a20011                 cmp     %o0, %l1
F00C21C0: 12800007                 bne     loc_F00C21DC
F00C21C4: 9014a160                 or      %l2, 0x160, %o0! id
F00C21C8: d204e30c                 ld      [%l3+0x30C], %o1! SEL
F00C21CC: 4000bda9                 call    _objc_msgSend
F00C21D0: 90100018                 mov     %i0, %o0
F00C21D4: 10bfffed                 ba      loc_F00C2188
F00C21D8: ea242004                 st      %l5, [%l0+4]
F00C21DC: 40000fc6                 call    _IOLog
F00C21E0: 92102000                 mov     0, %o1
F00C21E4: 10bfffe9                 ba      loc_F00C2188
F00C21E8: ea242004                 st      %l5, [%l0+4]
