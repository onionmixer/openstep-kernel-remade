F0032FA0: 9de3bf88                 save    %sp, -0x78, %sp
F0032FA4: a4102000                 mov     0, %l2
F0032FA8: 113c0432                 sethi   %hi(_ipprintfs), %o0
F0032FAC: d0022028                 ld      [%o0+%lo(_ipprintfs)], %o0
F0032FB0: 80a22000                 cmp     %o0, 0
F0032FB4: 0280000c                 be      loc_F0032FE4
F0032FB8: c027bfec                 clr     [%fp+var_14]
F0032FBC: 113c0432                 sethi   %hi(aForwardSrcXDst), %o0! "forward: src %x dst %x ttl %x\n"
F0032FC0: d206200c                 ld      [%i0+0xC], %o1
F0032FC4: 90122038                 bset    %lo(aForwardSrcXDst), %o0! "forward: src %x dst %x ttl %x\n"
F0032FC8: d227bff4                 st      %o1, [%fp+var_C]
F0032FCC: d4062010                 ld      [%i0+0x10], %o2
F0032FD0: 9207bff4                 add     %fp, var_C, %o1
F0032FD4: d427bff0                 st      %o2, [%fp+var_10]
F0032FD8: d60e2008                 ldub    [%i0+8], %o3
F0032FDC: 7fff859f                 call    _printf
F0032FE0: 9407bff0                 add     %fp, var_10, %o2
F0032FE4: d0162004                 lduh    [%i0+4], %o0
F0032FE8: 133c0432                 sethi   %hi(_ipforwarding), %o1
F0032FEC: d202602c                 ld      [%o1+%lo(_ipforwarding)], %o1
F0032FF0: 80a26000                 cmp     %o1, 0
F0032FF4: 02800007                 be      loc_F0033010
F0032FF8: d0362004                 sth     %o0, [%i0+4]
F0032FFC: 113c04d9                 sethi   %hi(_in_interfaces), %o0
F0033000: d0022098                 ld      [%o0+%lo(_in_interfaces)], %o0
F0033004: 80a22001                 cmp     %o0, 1
F0033008: 3480000a                 bg,a    loc_F0033030
F003300C: d2062010                 ld      [%i0+0x10], %o1
F0033010: 153c04d99412a0d0         set     _ipstat, %o2
F0033018: d202a028                 ld      [%o2+0x28], %o1
F003301C: 900e3f80                 and     %i0, -0x80, %o0
F0033020: 92026001                 inc     %o1
F0033024: 7fffab10                 call    _m_freem
F0033028: d222a028                 st      %o1, [%o2+0x28]
F003302C: 30800113                 ba,a    locret_F0033478
F0033030: 9007bff0                 add     %fp, var_10, %o0
F0033034: 7fffee53                 call    _in_canforward
F0033038: d227bff0                 st      %o1, [%fp+var_10]
F003303C: 80a22000                 cmp     %o0, 0
F0033040: 32800005                 bne,a   loc_F0033054
F0033044: d00e2008                 ldub    [%i0+8], %o0
F0033048: 7fffab07                 call    _m_freem
F003304C: 900e3f80                 and     %i0, -0x80, %o0
F0033050: 3080010a                 ba,a    locret_F0033478
F0033054: 80a22001                 cmp     %o0, 1
F0033058: 18800005                 bgu     loc_F003306C
F003305C: 90023fff                 inc     -1, %o0
F0033060: a410200b                 mov     0xB, %l2
F0033064: 108000ff                 ba      def_F0033310! jumptable F0033310 default case, cases 2-39,41-49,52-54,56-63
F0033068: a2102000                 mov     0, %l1
F003306C: d02e2008                 stb     %o0, [%i0+8]
F0033070: d0562002                 ldsh    [%i0+2], %o0
F0033074: 7fff8916                 call    _imin
F0033078: 92102040                 mov     0x40, %o1 ! '@'
F003307C: 920e3f80                 and     %i0, -0x80, %o1
F0033080: 94100008                 mov     %o0, %o2
F0033084: 90100009                 mov     %o1, %o0
F0033088: 7fffab2f                 call    _m_copy
F003308C: 92102000                 mov     0, %o1
F0033090: 133c04d9a0126324         set     unk_F0136724, %l0
F0033098: d4043ffc                 ld      [%l0-4], %o2
F003309C: 80a2a000                 cmp     %o2, 0
F00330A0: 02800008                 be      loc_F00330C0
F00330A4: a6100008                 mov     %o0, %l3
F00330A8: d2062010                 ld      [%i0+0x10], %o1
F00330AC: d0042004                 ld      [%l0+4], %o0
F00330B0: 80a24008                 cmp     %o1, %o0
F00330B4: 02800018                 be      loc_F0033114
F00330B8: 2b3c04d9                 sethi   -0xFEC9C00, %l5
F00330BC: 80a2a000                 cmp     %o2, 0
F00330C0: 0280000e                 be      loc_F00330F8
F00330C4: 90102002                 mov     2, %o0
F00330C8: d052a026                 ldsh    [%o2+0x26], %o0
F00330CC: 80a22001                 cmp     %o0, 1
F00330D0: 12800006                 bne     loc_F00330E8
F00330D4: 90023fff                 inc     -1, %o0
F00330D8: 7fffe753                 call    _rtfree
F00330DC: 9010000a                 mov     %o2, %o0
F00330E0: 10800004                 ba      loc_F00330F0
F00330E4: 113c04d9                 sethi   -0xFEC9C00, %o0
F00330E8: d032a026                 sth     %o0, [%o2+0x26]
F00330EC: 113c04d9                 sethi   -0xFEC9C00, %o0
F00330F0: c0222320                 clr     [%o0+0x320]
F00330F4: 90102002                 mov     2, %o0
F00330F8: d0340000                 sth     %o0, [%l0]
F00330FC: d2062010                 ld      [%i0+0x10], %o1
F0033100: 113c04d990122320         set     _ipforward_rt, %o0
F0033108: 7fffe6d4                 call    _rtalloc
F003310C: d2242004                 st      %o1, [%l0+4]
F0033110: 2b3c04d9                 sethi   -0xFEC9C00, %l5
F0033114: d2056320                 ld      [%l5+0x320], %o1
F0033118: 80a26000                 cmp     %o1, 0
F003311C: 02800053                 be      loc_F0033268
F0033120: 900e3f80                 and     %i0, -0x80, %o0
F0033124: d002602c                 ld      [%o1+0x2C], %o0
F0033128: 80a20019                 cmp     %o0, %i1
F003312C: 1280004f                 bne     loc_F0033268
F0033130: 900e3f80                 and     %i0, -0x80, %o0
F0033134: d0126024                 lduh    [%o1+0x24], %o0
F0033138: 808a2030                 btst    0x30, %o0 ! '0'
F003313C: 1280004b                 bne     loc_F0033268
F0033140: 900e3f80                 and     %i0, -0x80, %o0
F0033144: d0026008                 ld      [%o1+8], %o0
F0033148: 80a22000                 cmp     %o0, 0
F003314C: 02800046                 be      loc_F0033264
F0033150: 113c0432                 sethi   %hi(_ipsendredirects), %o0
F0033154: d0022030                 ld      [%o0+%lo(_ipsendredirects)], %o0
F0033158: 80a22000                 cmp     %o0, 0
F003315C: 02800043                 be      loc_F0033268
F0033160: 900e3f80                 and     %i0, -0x80, %o0
F0033164: d00e0000                 ldub    [%i0], %o0
F0033168: 900a200f                 and     %o0, 0xF, %o0
F003316C: 80a22005                 cmp     %o0, 5
F0033170: 1280003e                 bne     loc_F0033268
F0033174: 900e3f80                 and     %i0, -0x80, %o0
F0033178: e006200c                 ld      [%i0+0xC], %l0
F003317C: e8062010                 ld      [%i0+0x10], %l4
F0033180: 7ffffa0a                 call    _ifptoia
F0033184: 90100019                 mov     %i1, %o0
F0033188: 94920000                 orcc    %o0, %g0, %o2
F003318C: 02800037                 be      loc_F0033268
F0033190: 900e3f80                 and     %i0, -0x80, %o0
F0033194: d002a034                 ld      [%o2+0x34], %o0
F0033198: d202a030                 ld      [%o2+0x30], %o1
F003319C: 900c0008                 and     %l0, %o0, %o0
F00331A0: 80a20009                 cmp     %o0, %o1
F00331A4: 12800031                 bne     loc_F0033268
F00331A8: 900e3f80                 and     %i0, -0x80, %o0
F00331AC: d2056320                 ld      [%l5+0x320], %o1
F00331B0: d0126024                 lduh    [%o1+0x24], %o0
F00331B4: 808a2002                 btst    2, %o0
F00331B8: 22800003                 be,a    loc_F00331C4
F00331BC: d0062010                 ld      [%i0+0x10], %o0
F00331C0: d0026018                 ld      [%o1+0x18], %o0
F00331C4: d027bfec                 st      %o0, [%fp+var_14]
F00331C8: a4102005                 mov     5, %l2
F00331CC: 113c04d9                 sethi   %hi(_ipforward_rt), %o0
F00331D0: d0022320                 ld      [%o0+%lo(_ipforward_rt)], %o0
F00331D4: d0022024                 ld      [%o0+0x24], %o0
F00331D8: 13000180                 sethi   0x60000, %o1
F00331DC: 900a0009                 and     %o0, %o1, %o0
F00331E0: 13000080                 sethi   0x20000, %o1
F00331E4: 80a20009                 cmp     %o0, %o1
F00331E8: 1280000e                 bne     loc_F0033220
F00331EC: a2102000                 mov     0, %l1
F00331F0: 113c04d9                 sethi   %hi(_in_ifaddr), %o0
F00331F4: 1080000d                 ba      loc_F0033228
F00331F8: d4022070                 ld      [%o0+%lo(_in_ifaddr)], %o2
F00331FC: d202a028                 ld      [%o2+0x28], %o1
F0033200: 900d000b                 and     %l4, %o3, %o0
F0033204: 80a20009                 cmp     %o0, %o1
F0033208: 32800009                 bne,a   loc_F003322C
F003320C: d402a040                 ld      [%o2+0x40], %o2
F0033210: d002a034                 ld      [%o2+0x34], %o0
F0033214: 80a2000b                 cmp     %o0, %o3
F0033218: 02800009                 be      loc_F003323C
F003321C: 113c0432                 sethi   -0xFEF3800, %o0
F0033220: 10800006                 ba      loc_F0033238
F0033224: a2102001                 mov     1, %l1
F0033228: d402a040                 ld      [%o2+0x40], %o2
F003322C: 80a2a000                 cmp     %o2, 0
F0033230: 32bffff3                 bne,a   loc_F00331FC
F0033234: d602a02c                 ld      [%o2+0x2C], %o3
F0033238: 113c0432                 sethi   -0xFEF3800, %o0
F003323C: d0022028                 ld      [%o0+0x28], %o0
F0033240: 80a22000                 cmp     %o0, 0
F0033244: 02800008                 be      loc_F0033264
F0033248: 113c0432                 sethi   %hi(aRedirectDToX), %o0! "redirect (%d) to %x\n"
F003324C: 90122058                 bset    %lo(aRedirectDToX), %o0! "redirect (%d) to %x\n"
F0033250: 92100011                 mov     %l1, %o1
F0033254: d607bfec                 ld      [%fp+var_14], %o3
F0033258: 9407bff0                 add     %fp, var_10, %o2
F003325C: 7fff84ff                 call    _printf
F0033260: d627bff0                 st      %o3, [%fp+var_10]
F0033264: 900e3f80                 and     %i0, -0x80, %o0
F0033268: 92102000                 mov     0, %o1
F003326C: 153c04d99412a320         set     _ipforward_rt, %o2
F0033274: 40000083                 call    _ip_output
F0033278: 96102001                 mov     1, %o3
F003327C: 94920000                 orcc    %o0, %g0, %o2
F0033280: 02800007                 be      loc_F003329C
F0033284: 133c04d9                 sethi   %hi(_ipstat), %o1
F0033288: 921260d0                 bset    %lo(_ipstat), %o1
F003328C: d0026028                 ld      [%o1+0x28], %o0
F0033290: 90022001                 inc     %o0
F0033294: 10800014                 ba      loc_F00332E4
F0033298: d0226028                 st      %o0, [%o1+0x28]
F003329C: 80a4a000                 cmp     %l2, 0
F00332A0: 02800006                 be      loc_F00332B8
F00332A4: 921260d0                 bset    0xD0, %o1
F00332A8: d002602c                 ld      [%o1+0x2C], %o0
F00332AC: 90022001                 inc     %o0
F00332B0: 1080000d                 ba      loc_F00332E4
F00332B4: d022602c                 st      %o0, [%o1+0x2C]
F00332B8: 80a4e000                 cmp     %l3, 0
F00332BC: 02800005                 be      loc_F00332D0
F00332C0: 133c04d9                 sethi   -0xFEC9C00, %o1
F00332C4: 7fffaa68                 call    _m_freem
F00332C8: 90100013                 mov     %l3, %o0
F00332CC: 133c04d9                 sethi   -0xFEC9C00, %o1
F00332D0: 921260d0                 bset    0xD0, %o1
F00332D4: d0026024                 ld      [%o1+0x24], %o0
F00332D8: 90022001                 inc     %o0
F00332DC: 10800067                 ba      locret_F0033478
F00332E0: d0226024                 st      %o0, [%o1+0x24]
F00332E4: 80a4e000                 cmp     %l3, 0
F00332E8: 02800064                 be      locret_F0033478
F00332EC: a4102003                 mov     3, %l2
F00332F0: d004e004                 ld      [%l3+4], %o0
F00332F4: 80a2a041                 cmp     %o2, 0x41 ! 'A'! switch 66 cases
F00332F8: 1880005a                 bgu     def_F0033310! jumptable F0033310 default case, cases 2-39,41-49,52-54,56-63
F00332FC: b004c008                 add     %l3, %o0, %i0
F0033300: 113c00cc90122318         set     jpt_F0033310, %o0
F0033308: 932aa002                 sll     %o2, 2, %o1
F003330C: d0024008                 ld      [%o1+%o0], %o0
F0033310: 81c20000                 jmp     %o0! switch jump
F0033314: 01000000                 nop
F0033420: 10800010                 ba      def_F0033310! jumptable F0033310 case 0
F0033424: a4102005                 mov     5, %l2
F0033428: d2062010                 ld      [%i0+0x10], %o1! jumptable F0033310 cases 50,51
F003342C: 9007bff0                 add     %fp, var_10, %o0
F0033430: 7fffed2b                 call    _in_localaddr
F0033434: d227bff0                 st      %o1, [%fp+var_10]
F0033438: 80a00008                 cmp     %g0, %o0
F003343C: 10800009                 ba      def_F0033310! jumptable F0033310 default case, cases 2-39,41-49,52-54,56-63
F0033440: a2402000                 addc    %g0, 0, %l1
F0033444: 10800007                 ba      def_F0033310! jumptable F0033310 case 40
F0033448: a2102004                 mov     4, %l1
F003344C: 10800005                 ba      def_F0033310! jumptable F0033310 case 1
F0033450: a2102003                 mov     3, %l1
F0033454: 10800003                 ba      def_F0033310! jumptable F0033310 case 55
F0033458: a4102004                 mov     4, %l2
F003345C: a2102001                 mov     1, %l1! jumptable F0033310 cases 64,65
F0033460: 90100018                 mov     %i0, %o0! jumptable F0033310 default case, cases 2-39,41-49,52-54,56-63
F0033464: 92100012                 mov     %l2, %o1
F0033468: 94100011                 mov     %l1, %o2
F003346C: 96100019                 mov     %i1, %o3
F0033470: 7ffff6ff                 call    _icmp_error
F0033474: 9807bfec                 add     %fp, var_14, %o4
F0033478: 81c7e008                 ret
F003347C: 81e80000                 restore
