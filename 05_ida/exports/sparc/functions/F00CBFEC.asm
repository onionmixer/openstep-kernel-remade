F00CBFEC: 9de3bf90                 save    %sp, -0x70, %sp
F00CBFF0: d0062138                 ld      [%i0+0x138], %o0! id
F00CBFF4: 133c0504                 sethi   %hi(paLock), %o1! SEL
F00CBFF8: 4000961e                 call    _objc_msgSend
F00CBFFC: d2026000                 ld      [%o1+%lo(paLock)], %o1
F00CC000: 90100018                 mov     %i0, %o0! id
F00CC004: 133c0506                 sethi   %hi(paSearchmulti), %o1
F00CC008: d202605c                 ld      [%o1+%lo(paSearchmulti)], %o1! SEL
F00CC00C: 40009619                 call    _objc_msgSend
F00CC010: 9410001a                 mov     %i2, %o2
F00CC014: 96920000                 orcc    %o0, %g0, %o3
F00CC018: 2280002f                 be,a    loc_F00CC0D4
F00CC01C: d0062138                 ld      [%i0+0x138], %o0
F00CC020: d002e010                 ld      [%o3+0x10], %o0
F00CC024: 80a22000                 cmp     %o0, 0
F00CC028: 04800003                 ble     loc_F00CC034
F00CC02C: 90023fff                 inc     -1, %o0
F00CC030: d022e010                 st      %o0, [%o3+0x10]
F00CC034: d002e010                 ld      [%o3+0x10], %o0
F00CC038: 80a22000                 cmp     %o0, 0
F00CC03C: 34800026                 bg,a    loc_F00CC0D4
F00CC040: d0062138                 ld      [%i0+0x138], %o0
F00CC044: d402e008                 ld      [%o3+8], %o2
F00CC048: 90062144                 add     %i0, 0x144, %o0
F00CC04C: 80a2000a                 cmp     %o0, %o2
F00CC050: 12800004                 bne     loc_F00CC060
F00CC054: d202e00c                 ld      [%o3+0xC], %o1
F00CC058: 10800003                 ba      loc_F00CC064
F00CC05C: 9010000a                 mov     %o2, %o0
F00CC060: 9002a008                 add     %o2, 8, %o0
F00CC064: d2222004                 st      %o1, [%o0+4]
F00CC068: 90062144                 add     %i0, 0x144, %o0
F00CC06C: 80a20009                 cmp     %o0, %o1
F00CC070: 12800003                 bne     loc_F00CC07C
F00CC074: 90026008                 add     %o1, 8, %o0
F00CC078: 90100009                 mov     %o1, %o0
F00CC07C: d4220000                 st      %o2, [%o0]
F00CC080: 9010000b                 mov     %o3, %o0
F00CC084: 7fffe7b0                 call    _IOFree
F00CC088: 92102014                 mov     0x14, %o1
F00CC08C: d00e8000                 ldub    [%i2], %o0
F00CC090: d02e213c                 stb     %o0, [%i0+0x13C]
F00CC094: d00ea001                 ldub    [%i2+1], %o0
F00CC098: d02e213d                 stb     %o0, [%i0+0x13D]
F00CC09C: d00ea002                 ldub    [%i2+2], %o0
F00CC0A0: d02e213e                 stb     %o0, [%i0+0x13E]
F00CC0A4: d00ea003                 ldub    [%i2+3], %o0
F00CC0A8: d02e213f                 stb     %o0, [%i0+0x13F]
F00CC0AC: d20ea004                 ldub    [%i2+4], %o1
F00CC0B0: 94102008                 mov     8, %o2
F00CC0B4: d006212c                 ld      [%i0+0x12C], %o0! id
F00CC0B8: d22e2140                 stb     %o1, [%i0+0x140]
F00CC0BC: d60ea005                 ldub    [%i2+5], %o3
F00CC0C0: 133c0506                 sethi   %hi(paSend), %o1
F00CC0C4: d2026060                 ld      [%o1+%lo(paSend)], %o1! SEL
F00CC0C8: 400095ea                 call    _objc_msgSend
F00CC0CC: d62e2141                 stb     %o3, [%i0+0x141]
F00CC0D0: d0062138                 ld      [%i0+0x138], %o0! id
F00CC0D4: 133c0504                 sethi   %hi(paUnlock), %o1! SEL
F00CC0D8: 400095e6                 call    _objc_msgSend
F00CC0DC: d2026244                 ld      [%o1+%lo(paUnlock)], %o1
F00CC0E0: 81c7e008                 ret
F00CC0E4: 81e80000                 restore
