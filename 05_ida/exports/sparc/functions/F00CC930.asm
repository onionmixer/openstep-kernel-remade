F00CC930: 9de3bf88                 save    %sp, -0x78, %sp
F00CC934: 113c0504                 sethi   %hi(paRegisterdevice), %o0! id
F00CC938: d202225c                 ld      [%o0+%lo(paRegisterdevice)], %o1! SEL
F00CC93C: 400093cd                 call    _objc_msgSend
F00CC940: 90100018                 mov     %i0, %o0
F00CC944: d00e8000                 ldub    [%i2], %o0
F00CC948: d02e213c                 stb     %o0, [%i0+0x13C]
F00CC94C: d00ea001                 ldub    [%i2+1], %o0
F00CC950: d02e213d                 stb     %o0, [%i0+0x13D]
F00CC954: d00ea002                 ldub    [%i2+2], %o0
F00CC958: d02e213e                 stb     %o0, [%i0+0x13E]
F00CC95C: d00ea003                 ldub    [%i2+3], %o0
F00CC960: d02e213f                 stb     %o0, [%i0+0x13F]
F00CC964: d20ea004                 ldub    [%i2+4], %o1
F00CC968: 113c0506                 sethi   %hi(paIonetwork), %o0
F00CC96C: d00222e8                 ld      [%o0+%lo(paIonetwork)], %o0! id
F00CC970: d22e2140                 stb     %o1, [%i0+0x140]
F00CC974: d40ea005                 ldub    [%i2+5], %o2
F00CC978: 133c0503                 sethi   %hi(paAlloc), %o1
F00CC97C: d20263f0                 ld      [%o1+%lo(paAlloc)], %o1! SEL
F00CC980: 400093bc                 call    _objc_msgSend
F00CC984: d42e2141                 stb     %o2, [%i0+0x141]
F00CC988: a0100008                 mov     %o0, %l0
F00CC98C: 113c0506                 sethi   %hi(paUnit_0), %o0
F00CC990: f4022138                 ld      [%o0+%lo(paUnit_0)], %i2
F00CC994: 90100018                 mov     %i0, %o0! id
F00CC998: 400093b6                 call    _objc_msgSend
F00CC99C: 9210001a                 mov     %i2, %o1
F00CC9A0: 98100008                 mov     %o0, %o4
F00CC9A4: 90100010                 mov     %l0, %o0! id
F00CC9A8: 94100018                 mov     %i0, %o2
F00CC9AC: 173c04bb9612e0d0         set     aTr, %o3! "tr"
F00CC9B4: 1b3c03ec                 sethi   %hi(a416mbTokenRing), %o5! "4/16Mb Token-Ring"
F00CC9B8: d2062138                 ld      [%i0+0x138], %o1
F00CC9BC: 9a136190                 bset    %lo(a416mbTokenRing), %o5! "4/16Mb Token-Ring"
F00CC9C0: d223a05c                 st      %o1, [%sp+0x78+var_1C]
F00CC9C4: 133c0506                 sethi   %hi(paInitfornetwork), %o1
F00CC9C8: d2026044                 ld      [%o1+%lo(paInitfornetwork)], %o1! SEL
F00CC9CC: 400093a9                 call    _objc_msgSend
F00CC9D0: c023a060                 clr     [%sp+0x78+var_18]
F00CC9D4: d0262150                 st      %o0, [%i0+0x150]
F00CC9D8: e0062128                 ld      [%i0+0x128], %l0
F00CC9DC: 11040000                 sethi   0x10000000, %o0
F00CC9E0: 808c0008                 btst    %o0, %l0
F00CC9E4: 0280000a                 be      loc_F00CCA0C
F00CC9E8: 9210001a                 mov     %i2, %o1! SEL
F00CC9EC: 90100018                 mov     %i0, %o0! id
F00CC9F0: a134201a                 srl     %l0, 26, %l0
F00CC9F4: 4000939f                 call    _objc_msgSend
F00CC9F8: a00c2001                 and     %l0, 1, %l0
F00CC9FC: d4062134                 ld      [%i0+0x134], %o2
F00CCA00: d6062130                 ld      [%i0+0x130], %o3
F00CCA04: 7ffd7b45                 call    _vtrip_config
F00CCA08: 92100010                 mov     %l0, %o1
F00CCA0C: 113c0504                 sethi   %hi(paName), %o0! id
F00CCA10: d2022008                 ld      [%o0+%lo(paName)], %o1! SEL
F00CCA14: 40009397                 call    _objc_msgSend
F00CCA18: 90100018                 mov     %i0, %o0
F00CCA1C: d40e213c                 ldub    [%i0+0x13C], %o2
F00CCA20: d60e213d                 ldub    [%i0+0x13D], %o3
F00CCA24: d80e213e                 ldub    [%i0+0x13E], %o4
F00CCA28: da0e213f                 ldub    [%i0+0x13F], %o5
F00CCA2C: 92100008                 mov     %o0, %o1
F00CCA30: c40e2140                 ldub    [%i0+0x140], %g2
F00CCA34: 113c03ec                 sethi   %hi(aSTokenRingNode), %o0! "%s: Token Ring Node address %02x:%02x:%"...
F00CCA38: c423a05c                 st      %g2, [%sp+0x78+var_1C]
F00CCA3C: c40e2141                 ldub    [%i0+0x141], %g2
F00CCA40: 901221a8                 bset    %lo(aSTokenRingNode), %o0! "%s: Token Ring Node address %02x:%02x:%"...
F00CCA44: 7fffe5ac                 call    _IOLog
F00CCA48: c423a060                 st      %g2, [%sp+0x78+var_18]
F00CCA4C: f0062150                 ld      [%i0+0x150], %i0
F00CCA50: 81c7e008                 ret
F00CCA54: 81e80000                 restore
