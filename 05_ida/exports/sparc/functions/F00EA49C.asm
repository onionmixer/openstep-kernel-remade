F00EA49C: 9de3bf90                 save    %sp, -0x70, %sp
F00EA4A0: 133c0504                 sethi   %hi(paInitkeydescVal), %o1
F00EA4A4: 90100018                 mov     %i0, %o0! id
F00EA4A8: d20260e4                 ld      [%o1+%lo(paInitkeydescVal)], %o1! SEL
F00EA4AC: 9410001a                 mov     %i2, %o2
F00EA4B0: 40001cf0                 call    _objc_msgSend
F00EA4B4: 96102000                 mov     0, %o3
F00EA4B8: 81c7e008                 ret
F00EA4BC: 91e80008                 restore %g0, %o0, %o0
