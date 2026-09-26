F00CBBA8: 9de3bf88                 save    %sp, -0x78, %sp
F00CBBAC: d00e8000                 ldub    [%i2], %o0
F00CBBB0: d02e2150                 stb     %o0, [%i0+0x150]
F00CBBB4: d00ea001                 ldub    [%i2+1], %o0
F00CBBB8: d02e2151                 stb     %o0, [%i0+0x151]
F00CBBBC: d00ea002                 ldub    [%i2+2], %o0
F00CBBC0: d02e2152                 stb     %o0, [%i0+0x152]
F00CBBC4: d00ea003                 ldub    [%i2+3], %o0
F00CBBC8: d02e2153                 stb     %o0, [%i0+0x153]
F00CBBCC: d20ea004                 ldub    [%i2+4], %o1
F00CBBD0: 113c0506                 sethi   %hi(paIonetwork), %o0
F00CBBD4: d00222e8                 ld      [%o0+%lo(paIonetwork)], %o0! id
F00CBBD8: d22e2154                 stb     %o1, [%i0+0x154]
F00CBBDC: d40ea005                 ldub    [%i2+5], %o2
F00CBBE0: 133c0503                 sethi   %hi(paAlloc), %o1
F00CBBE4: d20263f0                 ld      [%o1+%lo(paAlloc)], %o1! SEL
F00CBBE8: 40009722                 call    _objc_msgSend
F00CBBEC: d42e2155                 stb     %o2, [%i0+0x155]
F00CBBF0: 133c0506                 sethi   %hi(paUnit_0), %o1
F00CBBF4: a0100008                 mov     %o0, %l0
F00CBBF8: d2026138                 ld      [%o1+%lo(paUnit_0)], %o1! SEL
F00CBBFC: 4000971d                 call    _objc_msgSend
F00CBC00: 90100018                 mov     %i0, %o0
F00CBC04: 921025dc                 mov     0x5DC, %o1
F00CBC08: d223a05c                 st      %o1, [%sp+0x78+var_1C]
F00CBC0C: c023a060                 clr     [%sp+0x78+var_18]
F00CBC10: 98100008                 mov     %o0, %o4
F00CBC14: 90100010                 mov     %l0, %o0! id
F00CBC18: 94100018                 mov     %i0, %o2
F00CBC1C: 173c04bb9612e0b8         set     unk_F012ECB8, %o3
F00CBC24: 133c0506                 sethi   %hi(paInitfornetwork), %o1
F00CBC28: 1b3c03ec                 sethi   %hi(a10mbEthernet), %o5! "10MB Ethernet"
F00CBC2C: d2026044                 ld      [%o1+%lo(paInitfornetwork)], %o1! SEL
F00CBC30: 40009710                 call    _objc_msgSend
F00CBC34: 9a1360b0                 bset    %lo(a10mbEthernet), %o5! "10MB Ethernet"
F00CBC38: d026214c                 st      %o0, [%i0+0x14C]
F00CBC3C: 113c0506                 sethi   %hi(paRegisterasdebu), %o0! id
F00CBC40: d2022040                 ld      [%o0+%lo(paRegisterasdebu)], %o1! SEL
F00CBC44: 4000970b                 call    _objc_msgSend
F00CBC48: 90100018                 mov     %i0, %o0
F00CBC4C: 113c0504                 sethi   %hi(paName), %o0! id
F00CBC50: d2022008                 ld      [%o0+%lo(paName)], %o1! SEL
F00CBC54: 40009707                 call    _objc_msgSend
F00CBC58: 90100018                 mov     %i0, %o0
F00CBC5C: d40e2150                 ldub    [%i0+0x150], %o2
F00CBC60: d60e2151                 ldub    [%i0+0x151], %o3
F00CBC64: d80e2152                 ldub    [%i0+0x152], %o4
F00CBC68: da0e2153                 ldub    [%i0+0x153], %o5
F00CBC6C: 92100008                 mov     %o0, %o1
F00CBC70: c40e2154                 ldub    [%i0+0x154], %g2
F00CBC74: 113c03ec                 sethi   %hi(aSEthernetAddre), %o0! "%s: Ethernet address %02x:%02x:%02x:%02"...
F00CBC78: c423a05c                 st      %g2, [%sp+0x78+var_1C]
F00CBC7C: c40e2155                 ldub    [%i0+0x155], %g2
F00CBC80: 901220c0                 bset    %lo(aSEthernetAddre), %o0! "%s: Ethernet address %02x:%02x:%02x:%02"...
F00CBC84: 7fffe91c                 call    _IOLog
F00CBC88: c423a060                 st      %g2, [%sp+0x78+var_18]
F00CBC8C: f006214c                 ld      [%i0+0x14C], %i0
F00CBC90: 81c7e008                 ret
F00CBC94: 81e80000                 restore
