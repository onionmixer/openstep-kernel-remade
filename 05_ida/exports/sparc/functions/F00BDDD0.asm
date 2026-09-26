F00BDDD0: 9de3bf98                 save    %sp, -0x68, %sp
F00BDDD4: 7fff635a                 call    _splaudio
F00BDDD8: b32e6018                 sll     %i1, 24, %i1
F00BDDDC: a0100008                 mov     %o0, %l0
F00BDDE0: 7fffc747                 call    _prom_putchar
F00BDDE4: 913e6018                 sra     %i1, 24, %o0
F00BDDE8: 7fff63cf                 call    _splx
F00BDDEC: 90100010                 mov     %l0, %o0
F00BDDF0: 81c7e008                 ret
F00BDDF4: 81e80000                 restore
