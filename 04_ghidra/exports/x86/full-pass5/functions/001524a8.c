/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001524a8 */

kern_return_t
_mach_port_dnrequest_info(ipc_space_t task,mach_port_name_t name,uint *dnr_total,uint *dnr_used)

{
  int iVar1;
  kern_return_t kVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  undefined4 *local_8;
  
  if (task == 0) {
    kVar2 = 0x10;
  }
  else {
    kVar2 = _ipc_object_translate(task,name,1,&local_8);
    if (kVar2 == 0) {
      iVar1 = local_8[0xb];
      if (iVar1 == 0) {
        uVar5 = 0;
        uVar4 = 0;
      }
      else {
        uVar5 = **(uint **)(iVar1 + 4);
        uVar3 = 1;
        uVar4 = 0;
        if (1 < uVar5) {
          do {
            if (*(int *)(iVar1 + 0xc) != 0) {
              uVar4 = uVar4 + 1;
            }
            uVar3 = uVar3 + 1;
            iVar1 = iVar1 + 8;
          } while (uVar3 < uVar5);
        }
      }
      LOCK();
      *local_8 = 0;
      UNLOCK();
      *dnr_total = uVar5;
      *dnr_used = uVar4;
      kVar2 = 0;
    }
  }
  return kVar2;
}

