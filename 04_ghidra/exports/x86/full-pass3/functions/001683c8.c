/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001683c8 */

kern_return_t _thread_abort(thread_act_t target_act)

{
  int *piVar1;
  uint uVar2;
  kern_return_t kVar3;
  int iVar4;
  undefined4 uVar5;
  uint uVar6;
  
  if ((target_act == 0) || (_active_threads == target_act)) {
    kVar3 = 4;
  }
  else {
    iVar4 = _thread_halt(target_act,0);
    if (iVar4 == 0) {
      _mach_msg_abort_rpc(target_act);
      uVar5 = _splsched();
      piVar1 = (int *)(target_act + 0x20);
      do {
        do {
        } while (*piVar1 != 0);
        LOCK();
        iVar4 = *piVar1;
        *piVar1 = 1;
        UNLOCK();
      } while (iVar4 == 1);
      iVar4 = *(int *)(target_act + 0x40);
      *(int *)(target_act + 0x40) = iVar4 + -1;
      if (iVar4 == 1) {
        uVar2 = *(uint *)(target_act + 0x4c);
        uVar6 = uVar2 & 0xffffffed;
        *(uint *)(target_act + 0x4c) = uVar6;
        if ((uVar2 & 5) == 0) {
          *(uint *)(target_act + 0x4c) = uVar6 | 4;
          _thread_setrun(target_act,1);
        }
      }
      LOCK();
      *(undefined4 *)(target_act + 0x20) = 0;
      UNLOCK();
      _splx(uVar5);
      if (*(int *)(target_act + 100) != -1) {
        _thread_depress_abort(target_act);
      }
      kVar3 = 0;
    }
    else {
      kVar3 = 0xe;
    }
  }
  return kVar3;
}

