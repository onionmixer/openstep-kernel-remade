F007AE28: 9de3bf98                 save    %sp, -0x68, %sp
F007AE2C: d006200c                 ld      [%i0+0xC], %o0
F007AE30: 92102042                 mov     0x42, %o1 ! 'B'
F007AE34: 7fffb42e                 call    _send_notification
F007AE38: 94102000                 mov     0, %o2
F007AE3C: 81c7e008                 ret
F007AE40: 81e80000                 restore
