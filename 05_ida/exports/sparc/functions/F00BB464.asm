F00BB464: 9de3bf98                 save    %sp, -0x68, %sp
F00BB468: 113c047f                 sethi   %hi(aZsDUnexpectedS), %o0! "zs%d: unexpected soft int\n"
F00BB46C: d2562014                 ldsh    [%i0+0x14], %o1
F00BB470: 7ffd647a                 call    _printf
F00BB474: 90122018                 bset    %lo(aZsDUnexpectedS), %o0! "zs%d: unexpected soft int\n"
F00BB478: 81c7e008                 ret
F00BB47C: 81e80000                 restore
