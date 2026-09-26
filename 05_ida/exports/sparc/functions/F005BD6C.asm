F005BD6C: 9de3bf98                 save    %sp, -0x68, %sp
F005BD70: a0100018                 mov     %i0, %l0
F005BD74: 90100019                 mov     %i1, %o0
F005BD78: d406e008                 ld      [%i3+8], %o2
F005BD7C: 7ffffa66                 call    _ipc_port_dncancel
F005BD80: 9210001a                 mov     %i2, %o1
F005BD84: b0100008                 mov     %o0, %i0
F005BD88: c026e008                 clr     [%i3+8]
F005BD8C: d206c000                 ld      [%i3], %o1
F005BD90: 11001000                 sethi   0x400000, %o0
F005BD94: 808a4008                 btst    %o0, %o1
F005BD98: 02800005                 be      locret_F005BDAC
F005BD9C: 01000000                 nop
F005BDA0: 4000082a                 call    _ipc_space_release
F005BDA4: 90100010                 mov     %l0, %o0
F005BDA8: b0102000                 mov     0, %i0
F005BDAC: 81c7e008                 ret
F005BDB0: 81e80000                 restore
