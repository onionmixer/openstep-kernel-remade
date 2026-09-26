F009B498: 9de3bf98                 save    %sp, -0x68, %sp
F009B49C: 11000020                 sethi   0x8000, %o0
F009B4A0: 808e0008                 btst    %o0, %i0
F009B4A4: 02800004                 be      loc_F009B4B4
F009B4A8: 113c045d                 sethi   %hi(aStoreBufferErr), %o0! "Store Buffer Error"
F009B4AC: 7ffde46b                 call    _printf
F009B4B0: 90122318                 bset    %lo(aStoreBufferErr), %o0! "Store Buffer Error"
F009B4B4: 113c045d90122330         set     aMfsr0xX, %o0! "mfsr 0x%x\n"
F009B4BC: 7ffde467                 call    _printf
F009B4C0: 92100018                 mov     %i0, %o1
F009B4C4: 808e2002                 btst    2, %i0
F009B4C8: 02800005                 be      locret_F009B4DC
F009B4CC: 113c045d                 sethi   %hi(aFaultVirtualAd), %o0! "\tFault Virtual Address = 0x%x\n"
F009B4D0: 90122340                 bset    %lo(aFaultVirtualAd), %o0! "\tFault Virtual Address = 0x%x\n"
F009B4D4: 7ffde461                 call    _printf
F009B4D8: 92100019                 mov     %i1, %o1
F009B4DC: 81c7e008                 ret
F009B4E0: 81e80000                 restore
