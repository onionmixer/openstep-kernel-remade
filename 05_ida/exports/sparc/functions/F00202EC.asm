F00202EC: 9de3bf98                 save    %sp, -0x68, %sp
F00202F0: 90100018                 mov     %i0, %o0
F00202F4: d2122006                 lduh    [%o0+6], %o1
F00202F8: 92126010                 bset    0x10, %o1
F00202FC: d2322006                 sth     %o1, [%o0+6]
F0020300: 40000043                 call    _sowakeup
F0020304: 9202203c                 add     %o0, 0x3C, %o1 ! '<'
F0020308: 81c7e008                 ret
F002030C: 81e80000                 restore
