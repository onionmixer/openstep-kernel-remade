F0076E40: 9de3bf98                 save    %sp, -0x68, %sp
F0076E44: 7fffc48b                 call    _kalloc
F0076E48: 90102028                 mov     0x28, %o0 ! '('
F0076E4C: f0222008                 st      %i0, [%o0+8]
F0076E50: c022200c                 clr     [%o0+0xC]
F0076E54: f2222010                 st      %i1, [%o0+0x10]
F0076E58: 94102000                 mov     0, %o2
F0076E5C: 96102000                 mov     0, %o3
F0076E60: d43a2018                 std     %o2, [%o0+0x18]
F0076E64: c0222020                 clr     [%o0+0x20]
F0076E68: 81c7e008                 ret
F0076E6C: 91e80008                 restore %g0, %o0, %o0
