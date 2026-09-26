F0025148: 9de3bf98                 save    %sp, -0x68, %sp
F002514C: d006201c                 ld      [%i0+0x1C], %o0
F0025150: d2022080                 ld      [%o0+0x80], %o1
F0025154: 9fc24000                 call    %o1
F0025158: 90100018                 mov     %i0, %o0
F002515C: a4920000                 orcc    %o0, %g0, %l2
F0025160: 36800006                 bge,a   loc_F0025178
F0025164: 9010001a                 mov     %i2, %o0
F0025168: 113c042f                 sethi   %hi(aCouldnTDetermi_0), %o0! "Couldn't determine device blocksize!\n"
F002516C: 7fffc001                 call    _panic
F0025170: 901223b0                 bset    %lo(aCouldnTDetermi_0), %o0! "Couldn't determine device blocksize!\n"
F0025174: 9010001a                 mov     %i2, %o0
F0025178: 7fff8522                 call    _udiv
F002517C: 92100012                 mov     %l2, %o1
F0025180: 92964000                 orcc    %i1, %g0, %o1
F0025184: 90064008                 add     %i1, %o0, %o0
F0025188: 16800003                 bge     loc_F0025194
F002518C: a6023fff                 add     %o0, -1, %l3
F0025190: 92066007                 add     %i1, 7, %o1
F0025194: 913a6003                 sra     %o1, 3, %o0
F0025198: 90060008                 add     %i0, %o0, %o0
F002519C: 900a200f                 and     %o0, 0xF, %o0
F00251A0: 932a2001                 sll     %o0, 1, %o1
F00251A4: 92024008                 add     %o1, %o0, %o1
F00251A8: 932a6002                 sll     %o1, 2, %o1
F00251AC: 113c04cf90122300         set     _bufhash, %o0
F00251B4: a2024008                 add     %o1, %o0, %l1
F00251B8: f4046004                 ld      [%l1+4], %i2
F00251BC: 80a68011                 cmp     %i2, %l1
F00251C0: 02800043                 be      locret_F00252CC
F00251C4: 01000000                 nop
F00251C8: d006a040                 ld      [%i2+0x40], %o0
F00251CC: 80a20018                 cmp     %o0, %i0
F00251D0: 3280003c                 bne,a   loc_F00252C0
F00251D4: f406a004                 ld      [%i2+4], %i2
F00251D8: d2068000                 ld      [%i2], %o1! int
F00251DC: 11000040                 sethi   0x10000, %o0
F00251E0: 808a4008                 btst    %o0, %o1
F00251E4: 32800037                 bne,a   loc_F00252C0
F00251E8: f406a004                 ld      [%i2+4], %i2
F00251EC: d006a014                 ld      [%i2+0x14], %o0! int
F00251F0: 80a22000                 cmp     %o0, 0
F00251F4: 22800033                 be,a    loc_F00252C0
F00251F8: f406a004                 ld      [%i2+4], %i2
F00251FC: e006a024                 ld      [%i2+0x24], %l0
F0025200: 80a40013                 cmp     %l0, %l3
F0025204: 3480002f                 bg,a    loc_F00252C0
F0025208: f406a004                 ld      [%i2+4], %i2
F002520C: 7fff84ff                 call    _div
F0025210: 92100012                 mov     %l2, %o1
F0025214: 90040008                 add     %l0, %o0, %o0
F0025218: 80a20019                 cmp     %o0, %i1
F002521C: 24800029                 ble,a   loc_F00252C0
F0025220: f406a004                 ld      [%i2+4], %i2
F0025224: 4001c659                 call    _splusclock
F0025228: 01000000                 nop
F002522C: d2068000                 ld      [%i2], %o1
F0025230: 808a6008                 btst    8, %o1
F0025234: 0280000b                 be      loc_F0025260
F0025238: a0100008                 mov     %o0, %l0
F002523C: 90126040                 or      %o1, 0x40, %o0
F0025240: d0268000                 st      %o0, [%i2]
F0025244: 9010001a                 mov     %i2, %o0! unsigned int
F0025248: 7fffb50c                 call    _sleep
F002524C: 92102015                 mov     0x15, %o1
F0025250: 4001c6b5                 call    _splx
F0025254: 90100010                 mov     %l0, %o0
F0025258: 10bfffd9                 ba      loc_F00251BC
F002525C: f4046004                 ld      [%l1+4], %i2
F0025260: 808a6200                 btst    0x200, %o1
F0025264: 02800014                 be      loc_F00252B4
F0025268: 01000000                 nop
F002526C: 4001c6ae                 call    _splx
F0025270: 90100010                 mov     %l0, %o0
F0025274: 4001c651                 call    _spltty
F0025278: 01000000                 nop
F002527C: d406a010                 ld      [%i2+0x10], %o2
F0025280: d206a00c                 ld      [%i2+0xC], %o1
F0025284: d222a00c                 st      %o1, [%o2+0xC]
F0025288: d406a00c                 ld      [%i2+0xC], %o2
F002528C: d206a010                 ld      [%i2+0x10], %o1
F0025290: d222a010                 st      %o1, [%o2+0x10]
F0025294: d2068000                 ld      [%i2], %o1
F0025298: 92126008                 bset    8, %o1
F002529C: 4001c6a2                 call    _splx
F00252A0: d2268000                 st      %o1, [%i2]
F00252A4: 7ffffd31                 call    _bwrite
F00252A8: 9010001a                 mov     %i2, %o0
F00252AC: 10bfffc4                 ba      loc_F00251BC
F00252B0: f4046004                 ld      [%l1+4], %i2
F00252B4: 4001c69c                 call    _splx
F00252B8: 90100010                 mov     %l0, %o0
F00252BC: f406a004                 ld      [%i2+4], %i2
F00252C0: 80a68011                 cmp     %i2, %l1
F00252C4: 32bfffc2                 bne,a   loc_F00251CC
F00252C8: d006a040                 ld      [%i2+0x40], %o0
F00252CC: 81c7e008                 ret
F00252D0: 81e80000                 restore
