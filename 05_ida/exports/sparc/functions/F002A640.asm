F002A640: 9de3bf88                 save    %sp, -0x78, %sp
F002A644: 400005e8                 call    _if_private
F002A648: 90100018                 mov     %i0, %o0
F002A64C: d002200c                 ld      [%o0+0xC], %o0
F002A650: 80a20019                 cmp     %o0, %i1
F002A654: 3280006d                 bne,a   locret_F002A808
F002A658: b010202f                 mov     0x2F, %i0 ! '/'
F002A65C: 9010001a                 mov     %i2, %o0
F002A660: 9210200c                 mov     0xC, %o1
F002A664: 94102002                 mov     2, %o2
F002A668: 40000520                 call    _nb_read
F002A66C: 9607bfee                 add     %fp, var_12, %o3
F002A670: d217bfee                 lduh    [%fp+var_12], %o1
F002A674: 90027000                 add     %o1, -0x1000, %o0
F002A678: 912a2010                 sll     %o0, 16, %o0
F002A67C: 91322010                 srl     %o0, 16, %o0
F002A680: 80a2200f                 cmp     %o0, 0xF
F002A684: 1880002d                 bgu     loc_F002A738
F002A688: 912a6010                 sll     %o1, 16, %o0
F002A68C: 913a2010                 sra     %o0, 16, %o0
F002A690: 90023000                 inc     -0x1000, %o0
F002A694: a32a2009                 sll     %o0, 9, %l1
F002A698: 912a2019                 sll     %o0, 25, %o0
F002A69C: a13a2010                 sra     %o0, 16, %l0
F002A6A0: 80a42000                 cmp     %l0, 0
F002A6A4: 22800059                 be,a    locret_F002A808
F002A6A8: b010202f                 mov     0x2F, %i0 ! '/'
F002A6AC: 4000050b                 call    _nb_size
F002A6B0: 9010001a                 mov     %i2, %o0
F002A6B4: 92042012                 add     %l0, 0x12, %o1
F002A6B8: 80a24008                 cmp     %o1, %o0
F002A6BC: 1a800052                 bcc     loc_F002A804
F002A6C0: 9010001a                 mov     %i2, %o0
F002A6C4: 9214200e                 or      %l0, 0xE, %o1
F002A6C8: 94102004                 mov     4, %o2
F002A6CC: 40000507                 call    _nb_read
F002A6D0: 9607bff0                 add     %fp, var_10, %o3
F002A6D4: d017bff0                 lduh    [%fp+var_10], %o0
F002A6D8: d037bfee                 sth     %o0, [%fp+var_12]
F002A6DC: 912a2010                 sll     %o0, 16, %o0
F002A6E0: 913a2010                 sra     %o0, 16, %o0
F002A6E4: 80a22800                 cmp     %o0, 0x800
F002A6E8: 02800004                 be      loc_F002A6F8
F002A6EC: 80a22806                 cmp     %o0, 0x806
F002A6F0: 32800046                 bne,a   locret_F002A808
F002A6F4: b010202f                 mov     0x2F, %i0 ! '/'
F002A6F8: 9010001a                 mov     %i2, %o0
F002A6FC: 932c6010                 sll     %l1, 16, %o1
F002A700: e057bff2                 ldsh    [%fp+var_E], %l0
F002A704: a33a6010                 sra     %o1, 16, %l1
F002A708: b2100010                 mov     %l0, %i1
F002A70C: a004200e                 inc     0xE, %l0
F002A710: 400004f2                 call    _nb_size
F002A714: a0044010                 add     %l1, %l0, %l0
F002A718: 80a40008                 cmp     %l0, %o0
F002A71C: 1880003a                 bgu     loc_F002A804
F002A720: 9010001a                 mov     %i2, %o0
F002A724: 92100011                 mov     %l1, %o1
F002A728: 94067ffc                 add     %i1, -4, %o2
F002A72C: 952aa010                 sll     %o2, 16, %o2
F002A730: 7fffff86                 call    sub_F002A548
F002A734: 953aa010                 sra     %o2, 16, %o2
F002A738: d057bfee                 ldsh    [%fp+var_12], %o0
F002A73C: 80a22800                 cmp     %o0, 0x800
F002A740: 02800006                 be      loc_F002A758
F002A744: 80a22806                 cmp     %o0, 0x806
F002A748: 02800011                 be      loc_F002A78C
F002A74C: 01000000                 nop
F002A750: 1080002e                 ba      locret_F002A808
F002A754: b010202f                 mov     0x2F, %i0 ! '/'
F002A758: 9010001a                 mov     %i2, %o0
F002A75C: 40000503                 call    _nb_shrink_top
F002A760: 9210200e                 mov     0xE, %o1
F002A764: 400005c0                 call    _if_ipackets
F002A768: 90100018                 mov     %i0, %o0
F002A76C: 92022001                 add     %o0, 1, %o1
F002A770: 400005d5                 call    _if_ipackets_set
F002A774: 90100018                 mov     %i0, %o0
F002A778: 90100018                 mov     %i0, %o0
F002A77C: 40001345                 call    _inet_queue
F002A780: 9210001a                 mov     %i2, %o1
F002A784: 10800021                 ba      locret_F002A808
F002A788: b0102000                 mov     0, %i0
F002A78C: 400005b6                 call    _if_ipackets
F002A790: 90100018                 mov     %i0, %o0
F002A794: 92022001                 add     %o0, 1, %o1
F002A798: 400005cb                 call    _if_ipackets_set
F002A79C: 90100018                 mov     %i0, %o0
F002A7A0: 400005a9                 call    _if_flags
F002A7A4: 90100018                 mov     %i0, %o0
F002A7A8: 13000010                 sethi   0x4000, %o1
F002A7AC: 808a0009                 btst    %o1, %o0
F002A7B0: 12800011                 bne     loc_F002A7F4
F002A7B4: 9010001a                 mov     %i2, %o0
F002A7B8: 400004ec                 call    _nb_shrink_top
F002A7BC: 9210200e                 mov     0xE, %o1
F002A7C0: 40000589                 call    _if_private
F002A7C4: 90100018                 mov     %i0, %o0
F002A7C8: d0022008                 ld      [%o0+8], %o0
F002A7CC: d027bfe8                 st      %o0, [%fp+var_18]
F002A7D0: 40000585                 call    _if_private
F002A7D4: 90100018                 mov     %i0, %o0
F002A7D8: 92100008                 mov     %o0, %o1
F002A7DC: 90100018                 mov     %i0, %o0
F002A7E0: 9407bfe8                 add     %fp, var_18, %o2
F002A7E4: 40000c4d                 call    _arpinput
F002A7E8: 9610001a                 mov     %i2, %o3
F002A7EC: 10800007                 ba      locret_F002A808
F002A7F0: b0102000                 mov     0, %i0
F002A7F4: 400004ac                 call    _nb_free
F002A7F8: 9010001a                 mov     %i2, %o0
F002A7FC: 10800003                 ba      locret_F002A808
F002A800: b0102000                 mov     0, %i0
F002A804: b010202f                 mov     0x2F, %i0 ! '/'
F002A808: 81c7e008                 ret
F002A80C: 81e80000                 restore
