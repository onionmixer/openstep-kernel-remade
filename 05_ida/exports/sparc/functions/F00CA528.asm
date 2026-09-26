F00CA528: 9de3bf90                 save    %sp, -0x70, %sp
F00CA52C: 9410001a                 mov     %i2, %o2
F00CA530: 912aa001                 sll     %o2, 1, %o0
F00CA534: 9002000a                 add     %o0, %o2, %o0
F00CA538: 912a2003                 sll     %o0, 3, %o0
F00CA53C: 9022000a                 sub     %o0, %o2, %o0
F00CA540: 912a2002                 sll     %o0, 2, %o0
F00CA544: a0022128                 add     %o0, 0x128, %l0
F00CA548: d0060010                 ld      [%i0+%l0], %o0! id
F00CA54C: 80a22000                 cmp     %o0, 0
F00CA550: 0280000a                 be      loc_F00CA578
F00CA554: b4060010                 add     %i0, %l0, %i2
F00CA558: 133c0506                 sethi   %hi(paShutdownunit), %o1
F00CA55C: d202608c                 ld      [%o1+%lo(paShutdownunit)], %o1! SEL
F00CA560: 40009cc4                 call    _objc_msgSend
F00CA564: 90100018                 mov     %i0, %o0
F00CA568: c0260010                 clr     [%i0+%l0]
F00CA56C: c02ea008                 clrb    [%i2+8]
F00CA570: 10800003                 ba      locret_F00CA57C
F00CA574: b0102000                 mov     0, %i0
F00CA578: b0103cdf                 mov     -0x321, %i0
F00CA57C: 81c7e008                 ret
F00CA580: 81e80000                 restore
