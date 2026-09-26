F00C186C: 9de3bf80                 save    %sp, -0x80, %sp
F00C1870: 90100018                 mov     %i0, %o0! id
F00C1874: 133c0504                 sethi   %hi(paInterruptport_0), %o1
F00C1878: d2026308                 ld      [%o1+%lo(paInterruptport_0)], %o1! SEL
F00C187C: aa102018                 mov     0x18, %l5
F00C1880: 293c0483                 sethi   -0xFEDF400, %l4
F00C1884: 233c0504                 sethi   -0xFEBF000, %l1
F00C1888: 4000bffa                 call    _objc_msgSend
F00C188C: a007bfe0                 add     %fp, var_20, %l0
F00C1890: a4100008                 mov     %o0, %l2
F00C1894: 110008c8a6122325         set     0x232325, %l3
F00C189C: ea242004                 st      %l5, [%l0+4]
F00C18A0: 90100010                 mov     %l0, %o0
F00C18A4: d4062128                 ld      [%i0+0x128], %o2
F00C18A8: 92102000                 mov     0, %o1
F00C18AC: d424200c                 st      %o2, [%l0+0xC]
F00C18B0: 7ffe916b                 call    _msg_receive
F00C18B4: 94102000                 mov     0, %o2
F00C18B8: 92920000                 orcc    %o0, %g0, %o1
F00C18BC: 22800006                 be,a    loc_F00C18D4
F00C18C0: d0042014                 ld      [%l0+0x14], %o0
F00C18C4: 4000120c                 call    _IOLog
F00C18C8: 901522a8                 or      %l4, 0x2A8, %o0
F00C18CC: 10bffff5                 ba      loc_F00C18A0
F00C18D0: ea242004                 st      %l5, [%l0+4]
F00C18D4: 80a20013                 cmp     %o0, %l3
F00C18D8: 32800017                 bne,a   loc_F00C1934
F00C18DC: 113c0483                 sethi   -0xFEDF400, %o0
F00C18E0: d204200c                 ld      [%l0+0xC], %o1
F00C18E4: 80a24012                 cmp     %o1, %l2
F00C18E8: 32800007                 bne,a   loc_F00C1904
F00C18EC: d006213c                 ld      [%i0+0x13C], %o0! id
F00C18F0: d204630c                 ld      [%l1+0x30C], %o1! SEL
F00C18F4: 4000bfdf                 call    _objc_msgSend
F00C18F8: 90100018                 mov     %i0, %o0
F00C18FC: 10bfffe9                 ba      loc_F00C18A0
F00C1900: ea242004                 st      %l5, [%l0+4]
F00C1904: 80a24008                 cmp     %o1, %o0
F00C1908: 12800007                 bne     loc_F00C1924
F00C190C: 113c0483                 sethi   -0xFEDF400, %o0
F00C1910: d0062138                 ld      [%i0+0x138], %o0! id
F00C1914: 4000bfd7                 call    _objc_msgSend
F00C1918: d204630c                 ld      [%l1+0x30C], %o1
F00C191C: 10bfffe1                 ba      loc_F00C18A0
F00C1920: ea242004                 st      %l5, [%l0+4]
F00C1924: 400011f4                 call    _IOLog
F00C1928: 901222d0                 bset    0x2D0, %o0
F00C192C: 10bfffdd                 ba      loc_F00C18A0
F00C1930: ea242004                 st      %l5, [%l0+4]
F00C1934: 901222f8                 bset    0x2F8, %o0
F00C1938: 400011ef                 call    _IOLog
F00C193C: 92102000                 mov     0, %o1
F00C1940: 10bfffd8                 ba      loc_F00C18A0
F00C1944: ea242004                 st      %l5, [%l0+4]
