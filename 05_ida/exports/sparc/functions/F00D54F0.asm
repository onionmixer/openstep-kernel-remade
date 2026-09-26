F00D54F0: 9de3bf98                 save    %sp, -0x68, %sp
F00D54F4: 113c0506                 sethi   %hi(paEventdriver_0), %o0
F00D54F8: d00222e0                 ld      [%o0+%lo(paEventdriver_0)], %o0! id
F00D54FC: 133c0505                 sethi   %hi(paInstance), %o1! SEL
F00D5500: 400070dc                 call    _objc_msgSend
F00D5504: d2026278                 ld      [%o1+%lo(paInstance)], %o1
F00D5508: 133c0505                 sethi   %hi(paEvopenToken), %o1
F00D550C: 94100018                 mov     %i0, %o2
F00D5510: d2026270                 ld      [%o1+%lo(paEvopenToken)], %o1! SEL
F00D5514: 400070d7                 call    _objc_msgSend
F00D5518: 96100019                 mov     %i1, %o3
F00D551C: 81c7e008                 ret
F00D5520: 91e80008                 restore %g0, %o0, %o0
