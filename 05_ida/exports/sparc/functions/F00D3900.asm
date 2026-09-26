F00D3900: 9de3bf90                 save    %sp, -0x70, %sp
F00D3904: d006a008                 ld      [%i2+8], %o0
F00D3908: 80a22000                 cmp     %o0, 0
F00D390C: 32800002                 bne,a   loc_F00D3914
F00D3910: c0220000                 clr     [%o0]
F00D3914: d0068000                 ld      [%i2], %o0
F00D3918: 80a22001                 cmp     %o0, 1
F00D391C: 2280001d                 be,a    loc_F00D3990
F00D3920: d006a004                 ld      [%i2+4], %o0
F00D3924: 0a800006                 bcs     loc_F00D393C
F00D3928: 80a22002                 cmp     %o0, 2
F00D392C: 2280000c                 be,a    loc_F00D395C
F00D3930: 90100018                 mov     %i0, %o0
F00D3934: 10800014                 ba      loc_F00D3984
F00D3938: 113c03ef                 sethi   -0xFF04400, %o0
F00D393C: d006a004                 ld      [%i2+4], %o0! id
F00D3940: 133c0504                 sethi   %hi(paUnlockwith), %o1
F00D3944: d2026004                 ld      [%o1+%lo(paUnlockwith)], %o1! SEL
F00D3948: 400077ca                 call    _objc_msgSend
F00D394C: 94102002                 mov     2, %o2
F00D3950: 7fffda33                 call    _IOExitThread
F00D3954: 01000000                 nop
F00D3958: 90100018                 mov     %i0, %o0! id
F00D395C: 133c0505                 sethi   %hi(paDoperforminiot), %o1
F00D3960: d20262d0                 ld      [%o1+%lo(paDoperforminiot)], %o1! SEL
F00D3964: 400077c3                 call    _objc_msgSend
F00D3968: 9406a00c                 add     %i2, 0xC, %o2
F00D396C: d206a008                 ld      [%i2+8], %o1
F00D3970: 80a26000                 cmp     %o1, 0
F00D3974: 32800006                 bne,a   loc_F00D398C
F00D3978: d0224000                 st      %o0, [%o1]
F00D397C: 10800005                 ba      loc_F00D3990
F00D3980: d006a004                 ld      [%i2+4], %o0
F00D3984: 7fffc9e8                 call    _IOPanic
F00D3988: 901222e8                 bset    0x2E8, %o0
F00D398C: d006a004                 ld      [%i2+4], %o0! id
F00D3990: 80a22000                 cmp     %o0, 0
F00D3994: 02800005                 be      locret_F00D39A8
F00D3998: 133c0504                 sethi   %hi(paUnlockwith), %o1
F00D399C: d2026004                 ld      [%o1+%lo(paUnlockwith)], %o1! SEL
F00D39A0: 400077b4                 call    _objc_msgSend
F00D39A4: 94102002                 mov     2, %o2
F00D39A8: 81c7e008                 ret
F00D39AC: 81e80000                 restore
