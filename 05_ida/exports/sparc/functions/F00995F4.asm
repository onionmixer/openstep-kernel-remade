F00995F4: 9de3bf90                 save    %sp, -0x70, %sp
F00995F8: 13000010                 sethi   0x4000, %o1! size_t
F00995FC: ac102000                 mov     0, %l6
F0099600: 113c04f6                 sethi   -0xFEC2800, %o0
F0099604: b0100008                 mov     %o0, %i0
F0099608: 113c04f6                 sethi   %hi(_ioptes), %o0
F009960C: d0022308                 ld      [%o0+%lo(_ioptes)], %o0! void *
F0099610: 7fffee12                 call    _bzero
F0099614: 2f3ffc00                 sethi   -0x100000, %l7
F0099618: 90102001                 mov     1, %o0
F009961C: d023a05c                 st      %o0, [%sp+0x70+var_14]
F0099620: 233ffc00a2146000         set     -0x100000, %l1
F0099628: 92100011                 mov     %l1, %o1! size_t
F009962C: 96102000                 mov     0, %o3
F0099630: 113c04f0                 sethi   %hi(_kernel_pmap), %o0
F0099634: d0022100                 ld      [%o0+%lo(_kernel_pmap)], %o0
F0099638: 98102003                 mov     3, %o4
F009963C: d4062100                 ld      [%i0+0x100], %o2
F0099640: 4000123e                 call    _pmap_enter_dev
F0099644: 9a102000                 mov     0, %o5
F0099648: 7fff3a8a                 call    _kalloc
F009964C: 90102200                 mov     0x200, %o0! void *
F0099650: 2b3c04f6                 sethi   %hi(_iopbmap), %l5
F0099654: d0256300                 st      %o0, [%l5+%lo(_iopbmap)]
F0099658: 7fffee00                 call    _bzero
F009965C: 92102200                 mov     0x200, %o1! size_t
F0099660: 7fff3a84                 call    _kalloc
F0099664: 901027f0                 mov     0x7F0, %o0! void *
F0099668: 253c04f6                 sethi   %hi(_sbusmap), %l2
F009966C: d024a320                 st      %o0, [%l2+%lo(_sbusmap)]
F0099670: 7fffedfa                 call    _bzero
F0099674: 921027f0                 mov     0x7F0, %o1! size_t
F0099678: 2100000c                 sethi   0x3000, %l0
F009967C: 7fff3a7d                 call    _kalloc
F0099680: 90100010                 mov     %l0, %o0! void *
F0099684: 293c04f6                 sethi   %hi(_bigsbusmap), %l4
F0099688: d02522f0                 st      %o0, [%l4+%lo(_bigsbusmap)]
F009968C: 7fffedf3                 call    _bzero
F0099690: 92100010                 mov     %l0, %o1! size_t
F0099694: 21000004                 sethi   0x1000, %l0
F0099698: 7fff3a76                 call    _kalloc
F009969C: 90100010                 mov     %l0, %o0! void *
F00996A0: 273c04f6                 sethi   %hi(_mbutlmap), %l3
F00996A4: d024e310                 st      %o0, [%l3+%lo(_mbutlmap)]
F00996A8: 7fffedec                 call    _bzero
F00996AC: 92100010                 mov     %l0, %o1
F00996B0: 13000008                 sethi   0x2000, %o1
F00996B4: 94100011                 mov     %l1, %o2
F00996B8: 173c045b9612e398         set     aIopbSpace, %o3! "IOPB space"
F00996C0: d0056300                 ld      [%l5+0x300], %o0
F00996C4: 40002dc8                 call    _rminit
F00996C8: 98102040                 mov     0x40, %o4 ! '@'
F00996CC: 921020fe                 mov     0xFE, %o1
F00996D0: 94102002                 mov     2, %o2
F00996D4: 173c045b9612e3a8         set     aSbusMapSpace, %o3! "sbus map space"
F00996DC: d004a320                 ld      [%l2+0x320], %o0
F00996E0: 40002dc1                 call    _rminit
F00996E4: 98102054                 mov     0x54, %o4 ! 'T'
F00996E8: 92102600                 mov     0x600, %o1
F00996EC: 150003fc                 sethi   0xFF000, %o2
F00996F0: 173c045b9612e3b8         set     aBigsbusMapSpac, %o3! "bigsbus map space"
F00996F8: d00522f0                 ld      [%l4+0x2F0], %o0
F00996FC: 40002dba                 call    _rminit
F0099700: 98102200                 mov     0x200, %o4
F0099704: 92102200                 mov     0x200, %o1
F0099708: 150003fd9412a200         set     0xFF600, %o2
F0099710: 173c045b9612e3d0         set     aMbutlMapSpace, %o3! "mbutl map space"
F0099718: d004e310                 ld      [%l3+0x310], %o0
F009971C: 40002db2                 call    _rminit
F0099720: 981020aa                 mov     0xAA, %o4
F0099724: 153c04f6                 sethi   %hi(_dvmamap), %o2
F0099728: d204a320                 ld      [%l2+0x320], %o1
F009972C: 113c04f6                 sethi   %hi(_phys_iopte), %o0
F0099730: d0022318                 ld      [%o0+%lo(_phys_iopte)], %o0
F0099734: d222a2f8                 st      %o1, [%o2+%lo(_dvmamap)]
F0099738: 9132200e                 srl     %o0, 14, %o0
F009973C: 7ffff64f                 call    _iommu_set_base
F0099740: 912a200a                 sll     %o0, 10, %o0
F0099744: 7ffff64a                 call    _iommu_set_ctl
F0099748: 90102001                 mov     1, %o0
F009974C: 7ffff64f                 call    _iommu_flush_all
F0099750: 01000000                 nop
F0099754: 92100017                 mov     %l7, %o1
F0099758: d0062100                 ld      [%i0+0x100], %o0
F009975C: 94102001                 mov     1, %o2
F0099760: 9132200c                 srl     %o0, 12, %o0
F0099764: 40000009                 call    _iom_dvma_pteload
F0099768: 90020016                 add     %o0, %l6, %o0
F009976C: 11000004                 sethi   0x1000, %o0
F0099770: ac05a001                 inc     %l6
F0099774: 80a5a001                 cmp     %l6, 1
F0099778: 08bffff7                 bleu    loc_F0099754
F009977C: ae05c008                 add     %l7, %o0, %l7
F0099780: 81c7e008                 ret
F0099784: 81e80000                 restore
