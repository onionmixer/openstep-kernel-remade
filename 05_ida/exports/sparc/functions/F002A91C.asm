F002A91C: 9de3bf98                 save    %sp, -0x68, %sp
F002A920: d2064000                 ld      [%i1], %o1! data
F002A924: 40030d5e                 call    _NXPtrHash
F002A928: 90100018                 mov     %i0, %o0! info
F002A92C: a0100008                 mov     %o0, %l0
F002A930: d2166004                 lduh    [%i1+4], %o1! data
F002A934: 40030d5a                 call    _NXPtrHash
F002A938: 90100018                 mov     %i0, %o0
F002A93C: b01c0008                 xor     %l0, %o0, %i0
F002A940: 81c7e008                 ret
F002A944: 81e80000                 restore
