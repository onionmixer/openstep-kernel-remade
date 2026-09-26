/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00155858 */

kern_return_t
_mach_port_move_member(ipc_space_t task,mach_port_name_t member,mach_port_name_t after)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 uVar3;
  kern_return_t kVar4;
  int local_8;
  
  if (task == 0) {
    return 0x10;
  }
  iVar2 = _ipc_right_lookup_write(task,member,&local_8);
  if (iVar2 != 0) {
    return iVar2;
  }
  if ((*(byte *)(local_8 + 2) & 2) == 0) {
LAB_001558c6:
    LOCK();
    *(undefined4 *)(task + 8) = 0;
    UNLOCK();
    kVar4 = 0x11;
  }
  else {
    uVar1 = *(undefined4 *)(local_8 + 4);
    if (after == 0) {
      uVar3 = 0;
    }
    else {
      local_8 = _ipc_entry_lookup(task,after);
      if (local_8 == 0) {
        LOCK();
        *(undefined4 *)(task + 8) = 0;
        UNLOCK();
        return 0xf;
      }
      if ((*(byte *)(local_8 + 2) & 8) == 0) goto LAB_001558c6;
      uVar3 = *(undefined4 *)(local_8 + 4);
    }
    kVar4 = _ipc_pset_move(task,uVar1,uVar3);
  }
  return kVar4;
}

