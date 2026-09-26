F00F38F0: 9de3bf98                 save    %sp, -0x68, %sp
F00F38F4: 4000002b                 call    _sel_getUid
F00F38F8: 90100018                 mov     %i0, %o0! buffer
F00F38FC: 80a22000                 cmp     %o0, 0
F00F3900: 12800006                 bne     locret_F00F3918
F00F3904: 01000000                 nop
F00F3908: 7fffea0e                 call    _NXUniqueString
F00F390C: 90100018                 mov     %i0, %o0
F00F3910: 7fffff75                 call    __sel_registerName
F00F3914: 01000000                 nop
F00F3918: 81c7e008                 ret
F00F391C: 91e80008                 restore %g0, %o0, %o0
