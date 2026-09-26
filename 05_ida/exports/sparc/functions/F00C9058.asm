F00C9058: 9de3bf90                 save    %sp, -0x70, %sp
F00C905C: 7ffff3b5                 call    _IOMalloc
F00C9060: 90102010                 mov     0x10, %o0! void *
F00C9064: d0262010                 st      %o0, [%i0+0x10]
F00C9068: 7fff2f7c                 call    _bzero
F00C906C: 92102010                 mov     0x10, %o1
F00C9070: f426200c                 st      %i2, [%i0+0xC]
F00C9074: 81c7e008                 ret
F00C9078: 81e80000                 restore
