F00EE5B4: 9de3bf98                 save    %sp, -0x68, %sp
F00EE5B8: 40000008                 call    _NXResetMapTable
F00EE5BC: 90100018                 mov     %i0, %o0! void *
F00EE5C0: 7ffde750                 call    _free
F00EE5C4: d006200c                 ld      [%i0+0xC], %o0! void *
F00EE5C8: 7ffde74e                 call    _free
F00EE5CC: 90100018                 mov     %i0, %o0
F00EE5D0: 81c7e008                 ret
F00EE5D4: 81e80000                 restore
