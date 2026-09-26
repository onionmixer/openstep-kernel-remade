F00C0344: 9de3bf90                 save    %sp, -0x70, %sp
F00C0348: 113c0506                 sethi   %hi(paPcpointer), %o0
F00C034C: d00222a8                 ld      [%o0+%lo(paPcpointer)], %o0! id
F00C0350: 133c0504                 sethi   %hi(paActivepointerd), %o1! SEL
F00C0354: 4000c547                 call    _objc_msgSend
F00C0358: d20262dc                 ld      [%o1+%lo(paActivepointerd)], %o1
F00C035C: 80a22000                 cmp     %o0, 0
F00C0360: 12800005                 bne     loc_F00C0374
F00C0364: d0262128                 st      %o0, [%i0+0x128]
F00C0368: 113c0483                 sethi   %hi(aInitpointerCan), %o0! "initPointer: Can't find active pointer "...
F00C036C: 1080000e                 ba      loc_F00C03A4
F00C0370: 90122058                 bset    %lo(aInitpointerCan), %o0! "initPointer: Can't find active pointer "...
F00C0374: 133c0504                 sethi   %hi(paSeteventtarget), %o1
F00C0378: e00262e0                 ld      [%o1+%lo(paSeteventtarget)], %l0
F00C037C: 133c0504                 sethi   %hi(paRespondsto), %o1
F00C0380: d2026270                 ld      [%o1+%lo(paRespondsto)], %o1! SEL
F00C0384: 4000c53b                 call    _objc_msgSend
F00C0388: 94100010                 mov     %l0, %o2
F00C038C: 912a2018                 sll     %o0, 24, %o0
F00C0390: 80a22000                 cmp     %o0, 0
F00C0394: 12800007                 bne     loc_F00C03B0
F00C0398: 92100010                 mov     %l0, %o1! SEL
F00C039C: 113c048390122088         set     aInitpointerPcp, %o0! "initPointer: PCPointer0 does not respon"...
F00C03A4: 40001754                 call    _IOLog
F00C03A8: b0102000                 mov     0, %i0
F00C03AC: 30800008                 ba,a    locret_F00C03CC
F00C03B0: d0062128                 ld      [%i0+0x128], %o0! id
F00C03B4: 4000c52f                 call    _objc_msgSend
F00C03B8: 94100018                 mov     %i0, %o2
F00C03BC: 92100010                 mov     %l0, %o1! SEL
F00C03C0: d0062128                 ld      [%i0+0x128], %o0! id
F00C03C4: 4000c52b                 call    _objc_msgSend
F00C03C8: 94100018                 mov     %i0, %o2
F00C03CC: 81c7e008                 ret
F00C03D0: 81e80000                 restore
