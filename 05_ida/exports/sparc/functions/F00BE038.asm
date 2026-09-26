F00BE038: 9de3bf98                 save    %sp, -0x68, %sp
F00BE03C: d6062028                 ld      [%i0+0x28], %o3
F00BE040: d0062024                 ld      [%i0+0x24], %o0
F00BE044: d8062010                 ld      [%i0+0x10], %o4
F00BE048: d4062018                 ld      [%i0+0x18], %o2
F00BE04C: 972ae003                 sll     %o3, 3, %o3
F00BE050: 932a2001                 sll     %o0, 1, %o1
F00BE054: 92024008                 add     %o1, %o0, %o1
F00BE058: 932a6002                 sll     %o1, 2, %o1
F00BE05C: 92030009                 add     %o4, %o1, %o1
F00BE060: d006200c                 ld      [%i0+0xC], %o0
F00BE064: 9422800b                 sub     %o2, %o3, %o2
F00BE068: d8062030                 ld      [%i0+0x30], %o4
F00BE06C: 9002000b                 add     %o0, %o3, %o0
F00BE070: 7fffffa0                 call    sub_F00BDEF0
F00BE074: 9610200c                 mov     0xC, %o3
F00BE078: 81c7e008                 ret
F00BE07C: 81e80000                 restore
