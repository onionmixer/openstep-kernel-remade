F0045018: 9de3bf98                 save    %sp, -0x68, %sp
F004501C: d2060000                 ld      [%i0], %o1
F0045020: 900a7ffe                 and     %o1, -2, %o0
F0045024: 808a6002                 btst    2, %o1
F0045028: 02800006                 be      locret_F0045040
F004502C: d0260000                 st      %o0, [%i0]
F0045030: 900a7ffc                 and     %o1, -4, %o0
F0045034: d0260000                 st      %o0, [%i0]
F0045038: 7fff376c                 call    _wakeup
F004503C: 90100018                 mov     %i0, %o0
F0045040: 81c7e008                 ret
F0045044: 81e80000                 restore
