F00B9C6C: 9de3bf98                 save    %sp, -0x68, %sp
F00B9C70: b00e201f                 and     %i0, 0x1F, %i0
F00B9C74: 932e2004                 sll     %i0, 4, %o1
F00B9C78: 92024018                 add     %o1, %i0, %o1
F00B9C7C: 932a6003                 sll     %o1, 3, %o1
F00B9C80: 113c04fb90122260         set     _zs_tty, %o0
F00B9C88: a0024008                 add     %o1, %o0, %l0
F00B9C8C: 90100010                 mov     %l0, %o0
F00B9C90: d84c2047                 ldsb    [%l0+0x47], %o4
F00B9C94: 92100019                 mov     %i1, %o1
F00B9C98: 972b2001                 sll     %o4, 1, %o3
F00B9C9C: 9602c00c                 add     %o3, %o4, %o3
F00B9CA0: 972ae004                 sll     %o3, 4, %o3
F00B9CA4: 193c042e981320cc         set     _linesw, %o4
F00B9CAC: 9602c00c                 add     %o3, %o4, %o3
F00B9CB0: d802e010                 ld      [%o3+0x10], %o4
F00B9CB4: 9410001a                 mov     %i2, %o2
F00B9CB8: e2042034                 ld      [%l0+0x34], %l1
F00B9CBC: 9fc30000                 call    %o4
F00B9CC0: 9610001b                 mov     %i3, %o3
F00B9CC4: b0920000                 orcc    %o0, %g0, %i0
F00B9CC8: 16800007                 bge     loc_F00B9CE4
F00B9CCC: 90100010                 mov     %l0, %o0
F00B9CD0: 92100019                 mov     %i1, %o1
F00B9CD4: 9410001a                 mov     %i2, %o2
F00B9CD8: 7ffd73bb                 call    _ttioctl
F00B9CDC: 9610001b                 mov     %i3, %o3
F00B9CE0: b0920000                 orcc    %o0, %g0, %i0
F00B9CE4: 0680001c                 bl      loc_F00B9D54
F00B9CE8: 1120019d                 sethi   -0x7FF98C00, %o0
F00B9CEC: 9012200a                 bset    0xA, %o0
F00B9CF0: 80a64008                 cmp     %i1, %o0
F00B9CF4: 1480000d                 bg      loc_F00B9D28
F00B9CF8: 1120091d                 sethi   -0x7FDB8C00, %o0
F00B9CFC: 1120019d90122009         set     -0x7FF98BF7, %o0
F00B9D04: 80a64008                 cmp     %i1, %o0
F00B9D08: 16800010                 bge     loc_F00B9D48
F00B9D0C: 1120011d                 sethi   -0x7FFB8C00, %o0
F00B9D10: 9012207f                 bset    0x7F, %o0
F00B9D14: 80a64008                 cmp     %i1, %o0
F00B9D18: 14800081                 bg      locret_F00B9F1C
F00B9D1C: 1120011d                 sethi   -0x7FFB8C00, %o0
F00B9D20: 10800007                 ba      loc_F00B9D3C
F00B9D24: 9012207d                 bset    0x7D, %o0 ! '}'
F00B9D28: 90122016                 bset    0x16, %o0
F00B9D2C: 80a64008                 cmp     %i1, %o0
F00B9D30: 1480007b                 bg      locret_F00B9F1C
F00B9D34: 1120091d                 sethi   -0x7FDB8C00, %o0
F00B9D38: 90122014                 bset    0x14, %o0
F00B9D3C: 80a64008                 cmp     %i1, %o0
F00B9D40: 06800077                 bl      locret_F00B9F1C
F00B9D44: 01000000                 nop
F00B9D48: 40000095                 call    _zsparam
F00B9D4C: 90100010                 mov     %l0, %o0
F00B9D50: 30800073                 ba,a    locret_F00B9F1C
F00B9D54: 1108001d90122079         set     0x20007479, %o0
F00B9D5C: 80a64008                 cmp     %i1, %o0
F00B9D60: 2280004b                 be,a    loc_F00B9E8C
F00B9D64: 90100010                 mov     %l0, %o0
F00B9D68: 1480001d                 bg      loc_F00B9DDC
F00B9D6C: 1110011d                 sethi   0x40047400, %o0
F00B9D70: 1120011d9012206d         set     -0x7FFB8B93, %o0
F00B9D78: 80a64008                 cmp     %i1, %o0
F00B9D7C: 02800048                 be      loc_F00B9E9C
F00B9D80: 01000000                 nop
F00B9D84: 1480000c                 bg      loc_F00B9DB4
F00B9D88: 1120011e                 sethi   -0x7FFB8800, %o0
F00B9D8C: 1120011d9012206b         set     -0x7FFB8B95, %o0
F00B9D94: 80a64008                 cmp     %i1, %o0
F00B9D98: 02800051                 be      loc_F00B9EDC
F00B9D9C: 1120011d                 sethi   -0x7FFB8C00, %o0
F00B9DA0: 9012206c                 bset    0x6C, %o0 ! 'l'
F00B9DA4: 80a64008                 cmp     %i1, %o0
F00B9DA8: 02800045                 be      loc_F00B9EBC
F00B9DAC: b0102019                 mov     0x19, %i0
F00B9DB0: 3080005b                 ba,a    locret_F00B9F1C
F00B9DB4: 90122201                 bset    0x201, %o0
F00B9DB8: 80a64008                 cmp     %i1, %o0
F00B9DBC: 02800057                 be      loc_F00B9F18
F00B9DC0: 1108001d                 sethi   0x20007400, %o0
F00B9DC4: 90122078                 bset    0x78, %o0 ! 'x'
F00B9DC8: 80a64008                 cmp     %i1, %o0
F00B9DCC: 02800032                 be      loc_F00B9E94
F00B9DD0: 90100010                 mov     %l0, %o0
F00B9DD4: 10800052                 ba      locret_F00B9F1C
F00B9DD8: b0102019                 mov     0x19, %i0
F00B9DDC: 9012206a                 bset    0x6A, %o0 ! 'j'
F00B9DE0: 80a64008                 cmp     %i1, %o0
F00B9DE4: 22800046                 be,a    loc_F00B9EFC
F00B9DE8: 90100010                 mov     %l0, %o0
F00B9DEC: 1480000c                 bg      loc_F00B9E1C
F00B9DF0: 1110011e                 sethi   0x40047800, %o0
F00B9DF4: 1108001d9012207a         set     0x2000747A, %o0
F00B9DFC: 80a64008                 cmp     %i1, %o0
F00B9E00: 02800018                 be      loc_F00B9E60
F00B9E04: 1108001d                 sethi   0x20007400, %o0
F00B9E08: 9012207b                 bset    0x7B, %o0 ! '{'
F00B9E0C: 80a64008                 cmp     %i1, %o0
F00B9E10: 0280000d                 be      loc_F00B9E44
F00B9E14: b0102019                 mov     0x19, %i0
F00B9E18: 30800041                 ba,a    locret_F00B9F1C
F00B9E1C: 90122200                 bset    0x200, %o0
F00B9E20: 80a64008                 cmp     %i1, %o0
F00B9E24: 0280003d                 be      loc_F00B9F18
F00B9E28: 1110011e                 sethi   0x40047800, %o0
F00B9E2C: 90122202                 bset    0x202, %o0
F00B9E30: 80a64008                 cmp     %i1, %o0
F00B9E34: 1280003a                 bne     locret_F00B9F1C
F00B9E38: b0102019                 mov     0x19, %i0
F00B9E3C: 10800038                 ba      locret_F00B9F1C
F00B9E40: b0102000                 mov     0, %i0
F00B9E44: 7fff734a                 call    _splzs
F00B9E48: 01000000                 nop
F00B9E4C: d40c6025                 ldub    [%l1+0x25], %o2
F00B9E50: 92102005                 mov     5, %o1
F00B9E54: d0046010                 ld      [%l1+0x10], %o0
F00B9E58: 10800008                 ba      loc_F00B9E78
F00B9E5C: 9412a010                 bset    0x10, %o2
F00B9E60: 7fff7343                 call    _splzs
F00B9E64: 01000000                 nop
F00B9E68: d40c6025                 ldub    [%l1+0x25], %o2
F00B9E6C: 92102005                 mov     5, %o1
F00B9E70: d0046010                 ld      [%l1+0x10], %o0
F00B9E74: 940aa0ef                 and     %o2, 0xEF, %o2
F00B9E78: 400005bb                 call    _zszwrite
F00B9E7C: d42c6025                 stb     %o2, [%l1+0x25]
F00B9E80: 7fff7398                 call    _spl0
F00B9E84: b0102000                 mov     0, %i0
F00B9E88: 30800025                 ba,a    locret_F00B9F1C
F00B9E8C: 10800010                 ba      loc_F00B9ECC
F00B9E90: 92102082                 mov     0x82, %o1
F00B9E94: 10800006                 ba      loc_F00B9EAC
F00B9E98: 92102000                 mov     0, %o1
F00B9E9C: 40000022                 call    _dmtozs
F00B9EA0: d0068000                 ld      [%i2], %o0
F00B9EA4: 92100008                 mov     %o0, %o1
F00B9EA8: 90100010                 mov     %l0, %o0
F00B9EAC: 40000184                 call    _zsmctl
F00B9EB0: 94102000                 mov     0, %o2
F00B9EB4: 1080001a                 ba      locret_F00B9F1C
F00B9EB8: b0102000                 mov     0, %i0
F00B9EBC: 4000001a                 call    _dmtozs
F00B9EC0: d0068000                 ld      [%i2], %o0
F00B9EC4: 92100008                 mov     %o0, %o1
F00B9EC8: 90100010                 mov     %l0, %o0
F00B9ECC: 4000017c                 call    _zsmctl
F00B9ED0: 94102001                 mov     1, %o2
F00B9ED4: 10800012                 ba      locret_F00B9F1C
F00B9ED8: b0102000                 mov     0, %i0
F00B9EDC: 40000012                 call    _dmtozs
F00B9EE0: d0068000                 ld      [%i2], %o0
F00B9EE4: 92100008                 mov     %o0, %o1
F00B9EE8: 90100010                 mov     %l0, %o0
F00B9EEC: 40000174                 call    _zsmctl
F00B9EF0: 94102002                 mov     2, %o2
F00B9EF4: 1080000a                 ba      locret_F00B9F1C
F00B9EF8: b0102000                 mov     0, %i0
F00B9EFC: 92102000                 mov     0, %o1
F00B9F00: 4000016f                 call    _zsmctl
F00B9F04: 94102003                 mov     3, %o2
F00B9F08: 40000016                 call    _zstodm
F00B9F0C: b0102000                 mov     0, %i0
F00B9F10: 10800003                 ba      locret_F00B9F1C
F00B9F14: d0268000                 st      %o0, [%i2]
F00B9F18: b0102000                 mov     0, %i0
F00B9F1C: 81c7e008                 ret
F00B9F20: 81e80000                 restore
