F000FAA4: 9de3bf98                 save    %sp, -0x68, %sp
F000FAA8: 7fffffcd                 call    _crget
F000FAAC: a0100018                 mov     %i0, %l0
F000FAB0: b0100008                 mov     %o0, %i0
F000FAB4: 92100010                 mov     %l0, %o1! __src
F000FAB8: 7fffddfa                 call    _memcpy
F000FABC: 9410202a                 mov     0x2A, %o2 ! '*'
F000FAC0: 90102001                 mov     1, %o0
F000FAC4: d0360000                 sth     %o0, [%i0]
F000FAC8: 81c7e008                 ret
F000FACC: 81e80000                 restore
