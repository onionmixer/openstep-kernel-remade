F003930C: 9de3bf98                 save    %sp, -0x68, %sp
F0039310: 90100018                 mov     %i0, %o0
F0039314: 133c04d9                 sethi   %hi(_in_ifaddr), %o1
F0039318: d2026070                 ld      [%o1+%lo(_in_ifaddr)], %o1
F003931C: c0222004                 clr     [%o0+4]
F0039320: 7fffffe5                 call    sub_F00392B4
F0039324: d2220000                 st      %o1, [%o0]
F0039328: 81c7e008                 ret
F003932C: 91e80008                 restore %g0, %o0, %o0
