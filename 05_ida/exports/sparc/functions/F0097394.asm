F0097394: 113c044a901220d4         set     _v_get_sysctl, %o0
F009739C: 193c025d981320d4         set     _p4m35_stub, %o4
F00973A4: 1b3c025d9a13602c         set     _p4m35_get_sysctl, %o5
F00973AC: da222000                 st      %o5, [%o0]
F00973B0: 1b3c025d9a136038         set     _p4m35_set_sysctl, %o5
F00973B8: da222004                 st      %o5, [%o0+4]
F00973BC: d822200c                 st      %o4, [%o0+0xC]
F00973C0: d8222010                 st      %o4, [%o0+0x10]
F00973C4: d8222008                 st      %o4, [%o0+8]
F00973C8: 1b3c025d9a136044         set     _p4m35_enable_dvma, %o5
F00973D0: da222014                 st      %o5, [%o0+0x14]
F00973D4: 1b3c025d9a13605c         set     _p4m35_disable_dvma, %o5
F00973DC: da222018                 st      %o5, [%o0+0x18]
F00973E0: 1b3c02989a136108         set     _p4m35_l15_async_fault, %o5
F00973E8: da22201c                 st      %o5, [%o0+0x1C]
F00973EC: 1b3c029a9a1363ec         set     _p4m35_memerr_init, %o5
F00973F4: da222020                 st      %o5, [%o0+0x20]
F00973F8: 1b3c029b9a13601c         set     _p4m35_memerr_disable, %o5
F0097400: da222024                 st      %o5, [%o0+0x24]
F0097404: 1b3c029b9a136030         set     _p4m35_ebe_handler, %o5
F009740C: da222028                 st      %o5, [%o0+0x28]
F0097410: d822202c                 st      %o4, [%o0+0x2C]
F0097414: d8222030                 st      %o4, [%o0+0x30]
F0097418: 1b3c025d9a1360a4         set     _p4m35_init_all_fsr, %o5
F0097420: da222034                 st      %o5, [%o0+0x34]
F0097424: 81c3e008                 retl
F0097428: 01000000                 nop
