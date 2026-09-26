F0027298: 9de3bf98                 save    %sp, -0x68, %sp
F002729C: 40010375                 call    _kalloc
F00272A0: 90102400                 mov     0x400, %o0
F00272A4: d0260000                 st      %o0, [%i0]
F00272A8: d0262004                 st      %o0, [%i0+4]
F00272AC: c0262008                 clr     [%i0+8]
F00272B0: 81c7e008                 ret
F00272B4: 81e80000                 restore
