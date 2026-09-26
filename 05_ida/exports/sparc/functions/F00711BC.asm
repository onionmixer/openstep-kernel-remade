F00711BC: 9de3bf98                 save    %sp, -0x68, %sp
F00711C0: 90100018                 mov     %i0, %o0
F00711C4: 7ffffec4                 call    _assert_wait
F00711C8: 9210001a                 mov     %i2, %o1
F00711CC: c0264000                 clr     [%i1]
F00711D0: 4000015c                 call    _thread_block_with_continuation
F00711D4: 90102000                 mov     0, %o0
F00711D8: 81c7e008                 ret
F00711DC: 81e80000                 restore
