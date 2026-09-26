F00EA3AC: 9de3bf98                 save    %sp, -0x68, %sp
F00EA3B0: 133c0503                 sethi   %hi(paFree), %o1! SEL
F00EA3B4: 90100018                 mov     %i0, %o0! id
F00EA3B8: 40001d2e                 call    _objc_msgSend
F00EA3BC: d20263fc                 ld      [%o1+%lo(paFree)], %o1
F00EA3C0: 81c7e008                 ret
F00EA3C4: 81e80000                 restore
