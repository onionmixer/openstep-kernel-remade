F00AEAC4: 9de3bf98                 save    %sp, -0x68, %sp
F00AEAC8: 84102001                 mov     1, %g2
F00AEACC: c606200c                 ld      [%i0+0xC], %g3
F00AEAD0: 85288019                 sll     %g2, %i1, %g2
F00AEAD4: 8610c002                 bset    %g2, %g3
F00AEAD8: c626200c                 st      %g3, [%i0+0xC]
F00AEADC: 81c7e008                 ret
F00AEAE0: 81e80000                 restore
