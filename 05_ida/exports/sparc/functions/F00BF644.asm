F00BF644: 9de3bf90                 save    %sp, -0x70, %sp
F00BF648: f42e214c                 stb     %i2, [%i0+0x14C]
F00BF64C: 133c0504                 sethi   %hi(paSetalphalockfe), %o1
F00BF650: d006212c                 ld      [%i0+0x12C], %o0! id
F00BF654: b52ea018                 sll     %i2, 24, %i2
F00BF658: d20262ac                 ld      [%o1+%lo(paSetalphalockfe)], %o1! SEL
F00BF65C: 4000c885                 call    _objc_msgSend
F00BF660: 953ea018                 sra     %i2, 24, %o2
F00BF664: 81c7e008                 ret
F00BF668: 81e80000                 restore
