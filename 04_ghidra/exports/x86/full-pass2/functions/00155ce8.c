/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00155ce8 */

kern_return_t
_port_names(ipc_space_t param_1,mach_port_name_array_t *param_2,mach_msg_type_number_t *param_3,
           mach_port_type_array_t *param_4,mach_msg_type_number_t *param_5)

{
  uint uVar1;
  kern_return_t kVar2;
  int iVar3;
  uint uVar4;
  uint size;
  uint *puVar5;
  uint uVar6;
  uint local_1c;
  mach_port_type_array_t local_c;
  uint *local_8;
  
  kVar2 = _mach_port_names(param_1,param_2,param_3,param_4,param_5);
  if (kVar2 == 0) {
    uVar1 = *param_5;
    local_c = *param_4;
    size = _page_mask + uVar1 * 4 & ~_page_mask;
    iVar3 = _vm_move(_ipc_soft_map,local_c,_ipc_kernel_map,size,0,&local_8);
    if (iVar3 == 0) {
      _vm_deallocate(_ipc_soft_map,(vm_address_t)local_c,size);
      uVar6 = 0;
      puVar5 = local_8;
      if (uVar1 != 0) {
        do {
          uVar4 = *puVar5 & 0x1f0000;
          if (uVar4 == 0x30000) {
LAB_00155e24:
            local_1c = 7;
          }
          else {
            if (uVar4 < 0x30001) {
              if (uVar4 != 0x10000) {
                if (uVar4 != 0x20000) goto LAB_00155e3c;
                goto LAB_00155e24;
              }
            }
            else {
              if (uVar4 == 0x80000) {
                local_1c = 9;
                goto LAB_00155e49;
              }
              if (uVar4 < 0x80001) {
                if (uVar4 != 0x40000) {
LAB_00155e3c:
                    /* WARNING: Subroutine does not return */
                  _panic(s_convert_port_type__strange_port_t_001deafd);
                }
              }
              else if (uVar4 != 0x100000) goto LAB_00155e3c;
            }
            local_1c = 1;
          }
LAB_00155e49:
          *puVar5 = local_1c;
          uVar6 = uVar6 + 1;
          puVar5 = puVar5 + 1;
        } while (uVar6 < uVar1);
      }
      kVar2 = _vm_move(_ipc_kernel_map,local_8,_ipc_soft_map,size,1,&local_c);
      *param_4 = local_c;
    }
    else {
      _kmem_free(_ipc_soft_map,*param_4,*param_5 * 4 + _page_mask & ~_page_mask);
      _kmem_free(_ipc_soft_map,*param_2,*param_3 * 4 + _page_mask & ~_page_mask);
      kVar2 = 6;
    }
  }
  else if (kVar2 != 6) {
    kVar2 = 4;
  }
  return kVar2;
}

