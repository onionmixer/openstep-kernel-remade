F0099FC8: 9de3bf98                 save    %sp, -0x68, %sp
F0099FCC: 7ffde9a3                 call    _printf
F0099FD0: 90100018                 mov     %i0, %o0
F0099FD4: 113c04f7                 sethi   %hi(_prettyShutdown), %o0
F0099FD8: d05221e8                 ldsh    [%o0+%lo(_prettyShutdown)], %o0
F0099FDC: 80a22000                 cmp     %o0, 0
F0099FE0: 02800004                 be      locret_F0099FF0
F0099FE4: 01000000                 nop
F0099FE8: 400088aa                 call    _kmGraphicPanelString
F0099FEC: 90100018                 mov     %i0, %o0
F0099FF0: 81c7e008                 ret
F0099FF4: 81e80000                 restore
