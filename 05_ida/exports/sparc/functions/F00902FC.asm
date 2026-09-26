F00902FC: 9de3bf98                 save    %sp, -0x68, %sp
F0090300: 113c04ef                 sethi   %hi(_ipc_space_kernel), %o0
F0090304: 7fff2c02                 call    _ipc_port_alloc_special
F0090308: d0022330                 ld      [%o0+%lo(_ipc_space_kernel)], %o0
F009030C: a0920000                 orcc    %o0, %g0, %l0
F0090310: 0280000a                 be      loc_F0090338
F0090314: 92100018                 mov     %i0, %o1
F0090318: 7fff5542                 call    _ipc_kobject_set
F009031C: 9410200c                 mov     0xC, %o2
F0090320: 90100010                 mov     %l0, %o0
F0090324: 92102000                 mov     0, %o1
F0090328: 4000e7e0                 call    _IOConvertPort
F009032C: 94102001                 mov     1, %o2
F0090330: 10800003                 ba      locret_F009033C
F0090334: b0100008                 mov     %o0, %i0
F0090338: b0102000                 mov     0, %i0
F009033C: 81c7e008                 ret
F0090340: 81e80000                 restore
