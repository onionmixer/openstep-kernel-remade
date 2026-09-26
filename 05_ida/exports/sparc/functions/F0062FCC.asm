F0062FCC: 9de3bf90                 save    %sp, -0x70, %sp
F0062FD0: 90100018                 mov     %i0, %o0! task
F0062FD4: 92100019                 mov     %i1, %o1! names
F0062FD8: 9410001a                 mov     %i2, %o2! namesCnt
F0062FDC: 9610001b                 mov     %i3, %o3! types
F0062FE0: 7ffffbc9                 call    _mach_port_names
F0062FE4: 9810001c                 mov     %i4, %o4
F0062FE8: b0920000                 orcc    %o0, %g0, %i0
F0062FEC: 12800043                 bne     loc_F00630F8
F0062FF0: 80a62006                 cmp     %i0, 6
F0062FF4: 273c04ef                 sethi   %hi(_ipc_soft_map), %l3
F0062FF8: d004e320                 ld      [%l3+%lo(_ipc_soft_map)], %o0
F0062FFC: 98102000                 mov     0, %o4
F0063000: e2070000                 ld      [%i4], %l1
F0063004: 9a07bff4                 add     %fp, var_C, %o5
F0063008: d206c000                 ld      [%i3], %o1
F006300C: 153c04ef                 sethi   %hi(_ipc_kernel_map), %o2
F0063010: d402a2f8                 ld      [%o2+%lo(_ipc_kernel_map)], %o2
F0063014: 253c04d0                 sethi   %hi(_page_mask), %l2
F0063018: c404a0d8                 ld      [%l2+%lo(_page_mask)], %g2
F006301C: d227bff0                 st      %o1, [%fp+address]
F0063020: 972c6002                 sll     %l1, 2, %o3
F0063024: 9602c002                 add     %o3, %g2, %o3
F0063028: a02ac002                 andn    %o3, %g2, %l0
F006302C: 40008c93                 call    _vm_move
F0063030: 96100010                 mov     %l0, %o3
F0063034: b0920000                 orcc    %o0, %g0, %i0
F0063038: 02800013                 be      loc_F0063084
F006303C: d604a0d8                 ld      [%l2+%lo(_page_mask)], %o3
F0063040: d004e320                 ld      [%l3+0x320], %o0
F0063044: d206c000                 ld      [%i3], %o1
F0063048: d4070000                 ld      [%i4], %o2
F006304C: 952aa002                 sll     %o2, 2, %o2
F0063050: 9402800b                 add     %o2, %o3, %o2
F0063054: 4000820c                 call    _kmem_free
F0063058: 942a800b                 bclr    %o3, %o2
F006305C: d004e320                 ld      [%l3+0x320], %o0
F0063060: d2064000                 ld      [%i1], %o1
F0063064: d4068000                 ld      [%i2], %o2
F0063068: d604a0d8                 ld      [%l2+0xD8], %o3
F006306C: 952aa002                 sll     %o2, 2, %o2
F0063070: 9402800b                 add     %o2, %o3, %o2
F0063074: 40008204                 call    _kmem_free
F0063078: 942a800b                 bclr    %o3, %o2
F006307C: 10800021                 ba      locret_F0063100
F0063080: b0102006                 mov     6, %i0
F0063084: d004e320                 ld      [%l3+0x320], %o0! target_task
F0063088: 94100010                 mov     %l0, %o2! size
F006308C: d207bff0                 ld      [%fp+address], %o1! address
F0063090: 40009e04                 call    _vm_deallocate
F0063094: b2102000                 mov     0, %i1
F0063098: 80a60011                 cmp     %i0, %l1
F006309C: 1a80000a                 bcc     loc_F00630C4
F00630A0: d007bff4                 ld      [%fp+var_C], %o0
F00630A4: b0100008                 mov     %o0, %i0
F00630A8: d0060000                 ld      [%i0], %o0
F00630AC: 7fffffa2                 call    _convert_port_type
F00630B0: b2066001                 inc     %i1
F00630B4: d0260000                 st      %o0, [%i0]
F00630B8: 80a64011                 cmp     %i1, %l1
F00630BC: 0abffffb                 bcs     loc_F00630A8
F00630C0: b0062004                 inc     4, %i0
F00630C4: 96100010                 mov     %l0, %o3
F00630C8: 113c04ef                 sethi   %hi(_ipc_kernel_map), %o0
F00630CC: d00222f8                 ld      [%o0+%lo(_ipc_kernel_map)], %o0
F00630D0: 98102001                 mov     1, %o4
F00630D4: d207bff4                 ld      [%fp+var_C], %o1
F00630D8: 153c04ef                 sethi   %hi(_ipc_soft_map), %o2
F00630DC: d402a320                 ld      [%o2+%lo(_ipc_soft_map)], %o2
F00630E0: 40008c66                 call    _vm_move
F00630E4: 9a07bff0                 add     %fp, address, %o5
F00630E8: d207bff0                 ld      [%fp+address], %o1
F00630EC: b0100008                 mov     %o0, %i0
F00630F0: 10800004                 ba      locret_F0063100
F00630F4: d226c000                 st      %o1, [%i3]
F00630F8: 32800002                 bne,a   locret_F0063100
F00630FC: b0102004                 mov     4, %i0
F0063100: 81c7e008                 ret
F0063104: 81e80000                 restore
