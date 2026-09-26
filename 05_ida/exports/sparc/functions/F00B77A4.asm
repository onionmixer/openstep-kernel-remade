F00B77A4: 9de3bf98                 save    %sp, -0x68, %sp
F00B77A8: 90100018                 mov     %i0, %o0
F00B77AC: b32e6010                 sll     %i1, 16, %i1
F00B77B0: b33e600e                 sra     %i1, 14, %i1
F00B77B4: b2064018                 add     %i1, %i0, %i1
F00B77B8: e00660b8                 ld      [%i1+0xB8], %l0
F00B77BC: 153c047b                 sethi   %hi(aDisconnectedCo), %o2! "Disconnected command timeout for Target"...
F00B77C0: d6142008                 lduh    [%l0+8], %o3
F00B77C4: 92102003                 mov     3, %o1
F00B77C8: d80c200a                 ldub    [%l0+0xA], %o4
F00B77CC: 40000108                 call    _esplog
F00B77D0: 9412a008                 bset    %lo(aDisconnectedCo), %o2! "Disconnected command timeout for Target"...
F00B77D4: 90102006                 mov     6, %o0
F00B77D8: d02c2028                 stb     %o0, [%l0+0x28]
F00B77DC: c02660b8                 clr     [%i1+0xB8]
F00B77E0: d0062088                 ld      [%i0+0x88], %o0
F00B77E4: d2062084                 ld      [%i0+0x84], %o1
F00B77E8: 90023fff                 inc     -1, %o0
F00B77EC: d0262088                 st      %o0, [%i0+0x88]
F00B77F0: 92027fff                 inc     -1, %o1
F00B77F4: d2262084                 st      %o1, [%i0+0x84]
F00B77F8: d2042010                 ld      [%l0+0x10], %o1
F00B77FC: 9fc24000                 call    %o1
F00B7800: 90100010                 mov     %l0, %o0
F00B7804: 81c7e008                 ret
F00B7808: 81e80000                 restore
