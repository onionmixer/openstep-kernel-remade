F006E688: 9de3bf98                 save    %sp, -0x68, %sp
F006E68C: 4000a49f                 call    _clock_value
F006E690: 90102001                 mov     1, %o0
F006E694: 7ffffed0                 call    _ns_time_to_timeval
F006E698: 94100018                 mov     %i0, %o2
F006E69C: 81c7e008                 ret
F006E6A0: 81e80000                 restore
