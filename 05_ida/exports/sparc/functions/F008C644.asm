F008C644: 9de3bf98                 save    %sp, -0x68, %sp
F008C648: 113c04d4                 sethi   %hi(dword_F0135174), %o0
F008C64C: 7ffffff1                 call    __io_convert_port_out
F008C650: d0022174                 ld      [%o0+%lo(dword_F0135174)], %o0
F008C654: 81c7e008                 ret
F008C658: 91e80008                 restore %g0, %o0, %o0
