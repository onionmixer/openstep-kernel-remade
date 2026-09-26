F00AEB8C: 9de3bf98                 save    %sp, -0x68, %sp
F00AEB90: 80a6a000                 cmp     %i2, 0
F00AEB94: 02800005                 be      loc_F00AEBA8
F00AEB98: 84380019                 xnor    %g0, %i1, %g2
F00AEB9C: c4260000                 st      %g2, [%i0]
F00AEBA0: 10800006                 ba      locret_F00AEBB8
F00AEBA4: b0102001                 mov     1, %i0
F00AEBA8: 84200019                 neg     %i1, %g2
F00AEBAC: c4260000                 st      %g2, [%i0]
F00AEBB0: 80a00002                 cmp     %g0, %g2
F00AEBB4: b0402000                 addc    %g0, 0, %i0
F00AEBB8: 81c7e008                 ret
F00AEBBC: 81e80000                 restore
