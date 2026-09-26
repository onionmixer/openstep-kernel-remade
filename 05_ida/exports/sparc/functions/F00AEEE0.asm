F00AEEE0: 9de3bf98                 save    %sp, -0x68, %sp
F00AEEE4: 7ffd57ed                 call    _flush_windows
F00AEEE8: 01000000                 nop
F00AEEEC: 113c000c                 sethi   %hi(_romp), %o0
F00AEEF0: d0022030                 ld      [%o0+%lo(_romp)], %o0
F00AEEF4: d2022064                 ld      [%o0+0x64], %o1
F00AEEF8: 9fc24000                 call    %o1
F00AEEFC: 90100018                 mov     %i0, %o0
F00AEF00: 81c7e008                 ret
F00AEF04: 81e80000                 restore
