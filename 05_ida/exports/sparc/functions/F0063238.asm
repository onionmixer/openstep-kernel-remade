F0063238: 9de3bf90                 save    %sp, -0x70, %sp
F006323C: 80a62000                 cmp     %i0, 0
F0063240: 02800006                 be      loc_F0063258
F0063244: 92100019                 mov     %i1, %o1
F0063248: 9006bfff                 add     %i2, -1, %o0
F006324C: 80a2200f                 cmp     %o0, 0xF
F0063250: 08800004                 bleu    loc_F0063260
F0063254: 90100018                 mov     %i0, %o0
F0063258: 1080000d                 ba      locret_F006328C
F006325C: b0102004                 mov     4, %i0
F0063260: 7fffff08                 call    _port_translate_compat
F0063264: 9407bff4                 add     %fp, var_C, %o2
F0063268: 80a22000                 cmp     %o0, 0
F006326C: 12800008                 bne     locret_F006328C
F0063270: b0100008                 mov     %o0, %i0
F0063274: d007bff4                 ld      [%fp+var_C], %o0
F0063278: 7fffdd4f                 call    _ipc_port_set_qlimit
F006327C: 9210001a                 mov     %i2, %o1
F0063280: d007bff4                 ld      [%fp+var_C], %o0
F0063284: b0102000                 mov     0, %i0
F0063288: c0220000                 clr     [%o0]
F006328C: 81c7e008                 ret
F0063290: 81e80000                 restore
