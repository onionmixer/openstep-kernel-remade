F001FA78: 9de3bf98                 save    %sp, -0x68, %sp
F001FA7C: 94100019                 mov     %i1, %o2
F001FA80: 9610001a                 mov     %i2, %o3
F001FA84: f627a050                 st      %i3, [%fp+arg_50]
F001FA88: 1100003f901223ff         set     0xFFFF, %o0
F001FA90: 80a28008                 cmp     %o2, %o0
F001FA94: 0280000f                 be      loc_F001FAD0
F001FA98: b4102000                 mov     0, %i2
F001FA9C: d006200c                 ld      [%i0+0xC], %o0
F001FAA0: 80a22000                 cmp     %o0, 0
F001FAA4: 22800089                 be,a    def_F001FC28! jumptable F001FC28 default case
F001FAA8: b410202a                 mov     0x2A, %i2 ! '*'
F001FAAC: da022018                 ld      [%o0+0x18], %o5
F001FAB0: 80a36000                 cmp     %o5, 0
F001FAB4: 02800084                 be      loc_F001FCC4
F001FAB8: 90102001                 mov     1, %o0
F001FABC: 92100018                 mov     %i0, %o1
F001FAC0: 9fc34000                 call    %o5
F001FAC4: 9807a050                 add     %fp, arg_50, %o4
F001FAC8: 10800086                 ba      locret_F001FCE0
F001FACC: b0100008                 mov     %o0, %i0
F001FAD0: 80a2e020                 cmp     %o3, 0x20 ! ' '
F001FAD4: 22800034                 be,a    loc_F001FBA4
F001FAD8: 80a6e000                 cmp     %i3, 0
F001FADC: 14800012                 bg      loc_F001FB24
F001FAE0: 80a2e100                 cmp     %o3, 0x100
F001FAE4: 80a2e004                 cmp     %o3, 4
F001FAE8: 2280002f                 be,a    loc_F001FBA4
F001FAEC: 80a6e000                 cmp     %i3, 0
F001FAF0: 14800007                 bg      loc_F001FB0C
F001FAF4: 80a2e008                 cmp     %o3, 8
F001FAF8: 80a2e001                 cmp     %o3, 1
F001FAFC: 0280002a                 be      loc_F001FBA4
F001FB00: 80a6e000                 cmp     %i3, 0
F001FB04: 10800072                 ba      loc_F001FCCC
F001FB08: b410202a                 mov     0x2A, %i2 ! '*'
F001FB0C: 02800025                 be      loc_F001FBA0
F001FB10: 80a2e010                 cmp     %o3, 0x10
F001FB14: 02800024                 be      loc_F001FBA4
F001FB18: 80a6e000                 cmp     %i3, 0
F001FB1C: 1080006c                 ba      loc_F001FCCC
F001FB20: b410202a                 mov     0x2A, %i2 ! '*'
F001FB24: 0280001f                 be      loc_F001FBA0
F001FB28: 80a2e100                 cmp     %o3, 0x100
F001FB2C: 14800009                 bg      loc_F001FB50
F001FB30: 11000004                 sethi   0x1000, %o0
F001FB34: 80a2e040                 cmp     %o3, 0x40 ! '@'
F001FB38: 0280001a                 be      loc_F001FBA0
F001FB3C: 80a2e080                 cmp     %o3, 0x80
F001FB40: 0280000e                 be      loc_F001FB78
F001FB44: 80a6e000                 cmp     %i3, 0
F001FB48: 10800061                 ba      loc_F001FCCC
F001FB4C: b410202a                 mov     0x2A, %i2 ! '*'
F001FB50: 90122006                 bset    6, %o0
F001FB54: 80a2c008                 cmp     %o3, %o0
F001FB58: 3480005c                 bg,a    def_F001FC28! jumptable F001FC28 default case
F001FB5C: b410202a                 mov     0x2A, %i2 ! '*'
F001FB60: 11000004                 sethi   0x1000, %o0
F001FB64: 80a2c008                 cmp     %o3, %o0
F001FB68: 24800058                 ble,a   def_F001FC28! jumptable F001FC28 default case
F001FB6C: b410202a                 mov     0x2A, %i2 ! '*'
F001FB70: 1080001e                 ba      loc_F001FBE8
F001FB74: 80a6e000                 cmp     %i3, 0
F001FB78: 22800054                 be,a    def_F001FC28! jumptable F001FC28 default case
F001FB7C: b4102016                 mov     0x16, %i2
F001FB80: d016e008                 lduh    [%i3+8], %o0
F001FB84: 80a22008                 cmp     %o0, 8
F001FB88: 32800050                 bne,a   def_F001FC28! jumptable F001FC28 default case
F001FB8C: b4102016                 mov     0x16, %i2
F001FB90: d006e004                 ld      [%i3+4], %o0
F001FB94: 9006c008                 add     %i3, %o0, %o0
F001FB98: d0022004                 ld      [%o0+4], %o0
F001FB9C: d0362004                 sth     %o0, [%i0+4]
F001FBA0: 80a6e000                 cmp     %i3, 0
F001FBA4: 22800049                 be,a    def_F001FC28! jumptable F001FC28 default case
F001FBA8: b4102016                 mov     0x16, %i2
F001FBAC: d016e008                 lduh    [%i3+8], %o0
F001FBB0: 80a22003                 cmp     %o0, 3
F001FBB4: 28800045                 bleu,a  def_F001FC28! jumptable F001FC28 default case
F001FBB8: b4102016                 mov     0x16, %i2
F001FBBC: d006e004                 ld      [%i3+4], %o0
F001FBC0: d006c008                 ld      [%i3+%o0], %o0
F001FBC4: 80a22000                 cmp     %o0, 0
F001FBC8: 02800005                 be      loc_F001FBDC
F001FBCC: d0162002                 lduh    [%i0+2], %o0
F001FBD0: 9012000b                 bset    %o3, %o0
F001FBD4: 1080003d                 ba      def_F001FC28! jumptable F001FC28 default case
F001FBD8: d0362002                 sth     %o0, [%i0+2]
F001FBDC: 902a000b                 bclr    %o3, %o0
F001FBE0: 1080003a                 ba      def_F001FC28! jumptable F001FC28 default case
F001FBE4: d0362002                 sth     %o0, [%i0+2]
F001FBE8: 22800038                 be,a    def_F001FC28! jumptable F001FC28 default case
F001FBEC: b4102016                 mov     0x16, %i2
F001FBF0: d016e008                 lduh    [%i3+8], %o0
F001FBF4: 80a22003                 cmp     %o0, 3
F001FBF8: 18800004                 bgu     loc_F001FC08
F001FBFC: 113ffffb                 sethi   -0x1400, %o0
F001FC00: 10800032                 ba      def_F001FC28! jumptable F001FC28 default case
F001FC04: b4102016                 mov     0x16, %i2
F001FC08: 901223ff                 bset    0x3FF, %o0
F001FC0C: 9202c008                 add     %o3, %o0, %o1
F001FC10: 80a26005                 cmp     %o1, 5! switch 6 cases
F001FC14: 1880002d                 bgu     def_F001FC28! jumptable F001FC28 default case
F001FC18: 113c007f                 sethi   %hi(jpt_F001FC28), %o0
F001FC1C: 90122030                 bset    %lo(jpt_F001FC28), %o0
F001FC20: 932a6002                 sll     %o1, 2, %o1
F001FC24: d0024008                 ld      [%o1+%o0], %o0
F001FC28: 81c20000                 jmp     %o0! switch jump
F001FC2C: 01000000                 nop
F001FC48: 1100000490122001         set     0x1001, %o0! jumptable F001FC28 cases 0,1
F001FC50: 80a2c008                 cmp     %o3, %o0
F001FC54: 32800003                 bne,a   loc_F001FC60
F001FC58: b0062024                 inc     0x24, %i0 ! '$'
F001FC5C: b006203c                 inc     0x3C, %i0 ! '<'
F001FC60: d006e004                 ld      [%i3+4], %o0
F001FC64: d206c008                 ld      [%i3+%o0], %o1
F001FC68: 40000216                 call    _sbreserve
F001FC6C: 90100018                 mov     %i0, %o0
F001FC70: 80a22000                 cmp     %o0, 0
F001FC74: 22800015                 be,a    def_F001FC28! jumptable F001FC28 default case
F001FC78: b4102037                 mov     0x37, %i2 ! '7'
F001FC7C: 10800014                 ba      loc_F001FCCC
F001FC80: 80a6e000                 cmp     %i3, 0
F001FC84: d006e004                 ld      [%i3+4], %o0! jumptable F001FC28 case 2
F001FC88: d006c008                 ld      [%i3+%o0], %o0
F001FC8C: 1080000f                 ba      def_F001FC28! jumptable F001FC28 default case
F001FC90: d0362044                 sth     %o0, [%i0+0x44]
F001FC94: d006e004                 ld      [%i3+4], %o0! jumptable F001FC28 case 3
F001FC98: d006c008                 ld      [%i3+%o0], %o0
F001FC9C: 1080000b                 ba      def_F001FC28! jumptable F001FC28 default case
F001FCA0: d036202c                 sth     %o0, [%i0+0x2C]
F001FCA4: d006e004                 ld      [%i3+4], %o0! jumptable F001FC28 case 4
F001FCA8: d006c008                 ld      [%i3+%o0], %o0
F001FCAC: 10800007                 ba      def_F001FC28! jumptable F001FC28 default case
F001FCB0: d0362046                 sth     %o0, [%i0+0x46]
F001FCB4: d006e004                 ld      [%i3+4], %o0! jumptable F001FC28 case 5
F001FCB8: d006c008                 ld      [%i3+%o0], %o0
F001FCBC: 10800003                 ba      def_F001FC28! jumptable F001FC28 default case
F001FCC0: d036202e                 sth     %o0, [%i0+0x2E]
F001FCC4: b410202a                 mov     0x2A, %i2 ! '*'
F001FCC8: 80a6e000                 cmp     %i3, 0! jumptable F001FC28 default case
F001FCCC: 02800005                 be      locret_F001FCE0
F001FCD0: b010001a                 mov     %i2, %i0
F001FCD4: 7ffff778                 call    _m_free
F001FCD8: 9010001b                 mov     %i3, %o0
F001FCDC: b010001a                 mov     %i2, %i0
F001FCE0: 81c7e008                 ret
F001FCE4: 81e80000                 restore
