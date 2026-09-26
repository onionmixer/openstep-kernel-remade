F00A14A8: 9de3bf98                 save    %sp, -0x68, %sp
F00A14AC: 133c04f792126270         set     _pmap_info, %o1
F00A14B4: d00260c0                 ld      [%o1+0xC0], %o0
F00A14B8: 80a66000                 cmp     %i1, 0
F00A14BC: 90022001                 inc     %o0
F00A14C0: 12800005                 bne     loc_F00A14D4
F00A14C4: d02260c0                 st      %o0, [%o1+0xC0]
F00A14C8: 113c0463                 sethi   %hi(aVmToSrmmuProtV), %o0! "vm_to_srmmu_prot: VM_PROT_NONE"
F00A14CC: 7ffdcf29                 call    _panic
F00A14D0: 901221d8                 bset    %lo(aVmToSrmmuProtV), %o0! "vm_to_srmmu_prot: VM_PROT_NONE"
F00A14D4: 113c04f0                 sethi   %hi(_kernel_pmap), %o0
F00A14D8: d0022100                 ld      [%o0+%lo(_kernel_pmap)], %o0
F00A14DC: 80a60008                 cmp     %i0, %o0
F00A14E0: 32800005                 bne,a   loc_F00A14F4
F00A14E4: 113c0463                 sethi   -0xFEE7400, %o0
F00A14E8: 113c0463                 sethi   %hi(unk_F0118DB4), %o0
F00A14EC: 10800003                 ba      loc_F00A14F8
F00A14F0: 901221b4                 bset    %lo(unk_F0118DB4), %o0
F00A14F4: 90122194                 bset    0x194, %o0
F00A14F8: 932e6002                 sll     %i1, 2, %o1
F00A14FC: f0024008                 ld      [%o1+%o0], %i0
F00A1500: 81c7e008                 ret
F00A1504: 81e80000                 restore
