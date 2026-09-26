F0011F1C: 9de3bf98                 save    %sp, -0x68, %sp
F0011F20: 400187b0                 call    _task_suspend_nowait
F0011F24: d0062068                 ld      [%i0+0x68], %o0
F0011F28: 90102006                 mov     6, %o0
F0011F2C: d2062028                 ld      [%i0+0x28], %o1
F0011F30: d02e2013                 stb     %o0, [%i0+0x13]
F0011F34: d0062044                 ld      [%i0+0x44], %o0
F0011F38: 920a7fdf                 and     %o1, -0x21, %o1
F0011F3C: 400003ab                 call    _wakeup
F0011F40: d2262028                 st      %o1, [%i0+0x28]
F0011F44: 81c7e008                 ret
F0011F48: 81e80000                 restore
