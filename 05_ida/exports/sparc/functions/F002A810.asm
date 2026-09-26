F002A810: 9de3bf80                 save    %sp, -0x80, %sp
F002A814: 40000580                 call    _if_type
F002A818: 90100019                 mov     %i1, %o0! __s1
F002A81C: 133c0430                 sethi   %hi(a10mbEthernet_0), %o1! "10MB Ethernet"
F002A820: 7fff7663                 call    _strcmp
F002A824: 921261e8                 bset    %lo(a10mbEthernet_0), %o1! "10MB Ethernet"
F002A828: 80a22000                 cmp     %o0, 0
F002A82C: 12800033                 bne     locret_F002A8F8
F002A830: 01000000                 nop
F002A834: 4000f60f                 call    _kalloc
F002A838: 90102010                 mov     0x10, %o0
F002A83C: a0100008                 mov     %o0, %l0
F002A840: 40000571                 call    _if_name
F002A844: 90100019                 mov     %i1, %o0
F002A848: a4100008                 mov     %o0, %l2
F002A84C: 4000056a                 call    _if_unit
F002A850: 90100019                 mov     %i1, %o0
F002A854: a2100008                 mov     %o0, %l1
F002A858: e223a05c                 st      %l1, [%sp+0x80+var_24]
F002A85C: 113c03d390122080         set     aInternetProtoc_0, %o0! "Internet Protocol"
F002A864: d023a060                 st      %o0, [%sp+0x80+var_20]
F002A868: 901025dc                 mov     0x5DC, %o0
F002A86C: d023a064                 st      %o0, [%sp+0x80+var_1C]
F002A870: 90102002                 mov     2, %o0
F002A874: d023a068                 st      %o0, [%sp+0x80+var_18]
F002A878: 11000004                 sethi   0x1000, %o0
F002A87C: d023a06c                 st      %o0, [%sp+0x80+var_14]
F002A880: e023a070                 st      %l0, [%sp+0x80+var_10]
F002A884: 90102000                 mov     0, %o0
F002A888: 133c00a992126240         set     sub_F002A640, %o1
F002A890: 153c00a89412a26c         set     sub_F002A26C, %o2
F002A898: 173c00a99612e210         set     sub_F002A610, %o3
F002A8A0: 193c00a89813239c         set     sub_F002A39C, %o4
F002A8A8: 400005cb                 call    _if_attach
F002A8AC: 9a100012                 mov     %l2, %o5
F002A8B0: 4000054d                 call    _if_private
F002A8B4: a0100008                 mov     %o0, %l0
F002A8B8: f222200c                 st      %i1, [%o0+0xC]
F002A8BC: 90100010                 mov     %l0, %o0
F002A8C0: 213c03d3                 sethi   %hi(_IFCONTROL_GETADDR), %l0! "getaddr"
F002A8C4: 40000548                 call    _if_private
F002A8C8: a01420e8                 bset    %lo(_IFCONTROL_GETADDR), %l0! "getaddr"
F002A8CC: 94100008                 mov     %o0, %o2
F002A8D0: 90100019                 mov     %i1, %o0
F002A8D4: 400004d1                 call    _if_control
F002A8D8: 92100010                 mov     %l0, %o1
F002A8DC: 113c0430901221f8         set     aIpProtocolEnab, %o0! "IP protocol enabled for interface %s%d,"...
F002A8E4: 92100012                 mov     %l2, %o1
F002A8E8: 94100011                 mov     %l1, %o2
F002A8EC: 173c0430                 sethi   %hi(a10mbEthernet_1), %o3! "10MB Ethernet"
F002A8F0: 7fffa75a                 call    _printf
F002A8F4: 9612e230                 bset    %lo(a10mbEthernet_1), %o3! "10MB Ethernet"
F002A8F8: 81c7e008                 ret
F002A8FC: 81e80000                 restore
