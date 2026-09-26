F00BB6E0: 9de3bf98                 save    %sp, -0x68, %sp
F00BB6E4: 90100018                 mov     %i0, %o0
F00BB6E8: 133c04fd                 sethi   %hi(_s24_devinfo_p), %o1
F00BB6EC: 7fffd5d3                 call    _report_dev
F00BB6F0: d0226220                 st      %o0, [%o1+%lo(_s24_devinfo_p)]
F00BB6F4: 81c7e008                 ret
F00BB6F8: 91e82000                 restore %g0, 0, %o0
