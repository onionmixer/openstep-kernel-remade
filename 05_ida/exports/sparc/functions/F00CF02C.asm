F00CF02C: 9de3bf90                 save    %sp, -0x70, %sp
F00CF030: 90103fff                 mov     -1, %o0
F00CF034: d026a028                 st      %o0, [%i2+0x28]
F00CF038: d00621b8                 ld      [%i0+0x1B8], %o0! id
F00CF03C: 133c0504                 sethi   %hi(paLock), %o1! SEL
F00CF040: 40008a0c                 call    _objc_msgSend
F00CF044: d2026000                 ld      [%o1+%lo(paLock)], %o1
F00CF048: d006a020                 ld      [%i2+0x20], %o0
F00CF04C: 80a22000                 cmp     %o0, 0
F00CF050: 16800008                 bge     loc_F00CF070
F00CF054: 920621b0                 add     %i0, 0x1B0, %o1
F00CF058: 10800006                 ba      loc_F00CF070
F00CF05C: 920621a8                 add     %i0, 0x1A8, %o1! SEL
F00CF060: f4226004                 st      %i2, [%o1+4]
F00CF064: d226a02c                 st      %o1, [%i2+0x2C]
F00CF068: 1080000b                 ba      loc_F00CF094
F00CF06C: d226a030                 st      %o1, [%i2+0x30]
F00CF070: d0024000                 ld      [%o1], %o0
F00CF074: 80a24008                 cmp     %o1, %o0
F00CF078: 22bffffa                 be,a    loc_F00CF060
F00CF07C: f4224000                 st      %i2, [%o1]
F00CF080: d0026004                 ld      [%o1+4], %o0
F00CF084: d026a030                 st      %o0, [%i2+0x30]
F00CF088: d226a02c                 st      %o1, [%i2+0x2C]
F00CF08C: f4226004                 st      %i2, [%o1+4]
F00CF090: f422202c                 st      %i2, [%o0+0x2C]
F00CF094: 113c0504                 sethi   %hi(paUnlockwith), %o0
F00CF098: e0022004                 ld      [%o0+%lo(paUnlockwith)], %l0
F00CF09C: 94102001                 mov     1, %o2
F00CF0A0: d00621b8                 ld      [%i0+0x1B8], %o0! id
F00CF0A4: 400089f3                 call    _objc_msgSend
F00CF0A8: 92100010                 mov     %l0, %o1
F00CF0AC: d006a018                 ld      [%i2+0x18], %o0
F00CF0B0: 80a22000                 cmp     %o0, 0
F00CF0B4: 1280000c                 bne     locret_F00CF0E4
F00CF0B8: b0102000                 mov     0, %i0
F00CF0BC: d006a01c                 ld      [%i2+0x1C], %o0! id
F00CF0C0: 133c0503                 sethi   %hi(paLockwhen), %o1
F00CF0C4: d20263f8                 ld      [%o1+%lo(paLockwhen)], %o1! SEL
F00CF0C8: 400089ea                 call    _objc_msgSend
F00CF0CC: 94102001                 mov     1, %o2
F00CF0D0: 92100010                 mov     %l0, %o1! SEL
F00CF0D4: d006a01c                 ld      [%i2+0x1C], %o0! id
F00CF0D8: 400089e6                 call    _objc_msgSend
F00CF0DC: 94102000                 mov     0, %o2
F00CF0E0: f006a028                 ld      [%i2+0x28], %i0
F00CF0E4: 81c7e008                 ret
F00CF0E8: 81e80000                 restore
