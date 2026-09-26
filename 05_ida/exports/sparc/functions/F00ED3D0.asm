F00ED3D0: 9de3bf98                 save    %sp, -0x68, %sp
F00ED3D4: 90100018                 mov     %i0, %o0! void *
F00ED3D8: 7fffffe0                 call    sub_F00ED358
F00ED3DC: 92102001                 mov     1, %o1
F00ED3E0: 7ffdebc8                 call    _free
F00ED3E4: d006200c                 ld      [%i0+0xC], %o0! void *
F00ED3E8: 7ffdebc6                 call    _free
F00ED3EC: 90100018                 mov     %i0, %o0
F00ED3F0: 81c7e008                 ret
F00ED3F4: 81e80000                 restore
