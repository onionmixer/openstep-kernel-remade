F009C708: 9de3bf98                 save    %sp, -0x68, %sp
F009C70C: 90102028                 mov     0x28, %o0 ! '('
F009C710: 921023e8                 mov     0x3E8, %o1
F009C714: 932a6004                 sll     %o1, 4, %o1
F009C718: 94102000                 mov     0, %o2
F009C71C: 96102000                 mov     0, %o3
F009C720: 193c045e                 sethi   %hi(aPmap), %o4! "pmap"
F009C724: 7fff6e05                 call    _zinit
F009C728: 98132370                 bset    %lo(aPmap), %o4! "pmap"
F009C72C: 133c04f7                 sethi   %hi(_pmap_zone), %o1
F009C730: d0226378                 st      %o0, [%o1+%lo(_pmap_zone)]
F009C734: 9010200c                 mov     0xC, %o0
F009C738: 13000075921260c0         set     0x1D4C0, %o1
F009C740: 94102000                 mov     0, %o2
F009C744: 96102000                 mov     0, %o3
F009C748: 193c045e                 sethi   %hi(aPvEntry), %o4! "pv_entry"
F009C74C: 7fff6dfb                 call    _zinit
F009C750: 98132378                 bset    %lo(aPvEntry), %o4! "pv_entry"
F009C754: 133c04f7                 sethi   %hi(_pv_entry_zone), %o1
F009C758: d0226388                 st      %o0, [%o1+%lo(_pv_entry_zone)]
F009C75C: 90102020                 mov     0x20, %o0 ! ' '
F009C760: 92102fa0                 mov     0xFA0, %o1
F009C764: 932a6004                 sll     %o1, 4, %o1
F009C768: 94102000                 mov     0, %o2
F009C76C: 96102000                 mov     0, %o3
F009C770: 193c045e                 sethi   %hi(aPoolZone), %o4! "pool_zone"
F009C774: 7fff6df1                 call    _zinit
F009C778: 98132388                 bset    %lo(aPoolZone), %o4! "pool_zone"
F009C77C: 133c04f7                 sethi   %hi(_pool_zone), %o1
F009C780: d0226380                 st      %o0, [%o1+%lo(_pool_zone)]
F009C784: 9010200c                 mov     0xC, %o0
F009C788: 921025dc                 mov     0x5DC, %o1
F009C78C: 932a6004                 sll     %o1, 4, %o1
F009C790: 94102000                 mov     0, %o2
F009C794: 96102000                 mov     0, %o3
F009C798: 193c045e                 sethi   %hi(aGarbageZone), %o4! "garbage_zone"
F009C79C: 7fff6de7                 call    _zinit
F009C7A0: 98132398                 bset    %lo(aGarbageZone), %o4! "garbage_zone"
F009C7A4: 133c04f7                 sethi   %hi(_garbage_zone), %o1
F009C7A8: d0226220                 st      %o0, [%o1+%lo(_garbage_zone)]
F009C7AC: 133c0463                 sethi   %hi(_pmap_initialized), %o1
F009C7B0: 90102001                 mov     1, %o0
F009C7B4: d0226190                 st      %o0, [%o1+%lo(_pmap_initialized)]
F009C7B8: 81c7e008                 ret
F009C7BC: 81e80000                 restore
