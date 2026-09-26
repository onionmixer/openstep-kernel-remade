/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0016848c */

thread_act_t _kernel_thread(task_t param_1,undefined4 param_2,undefined4 param_3)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  thread_act_t tVar4;
  undefined4 uVar5;
  uint uVar6;
  thread_act_t local_8;
  
  _thread_create(param_1,&local_8);
  _thread_deallocate(local_8);
  *(undefined4 *)(local_8 + 0x34) = param_2;
  *(undefined4 *)(local_8 + 0xc4) = param_3;
  _thread_doswapin(local_8);
  tVar4 = local_8;
  *(undefined4 *)(local_8 + 0x54) = 0x1f;
  *(undefined4 *)(local_8 + 0x50) = 0x18;
  *(undefined4 *)(local_8 + 0x58) = 0x18;
  if (local_8 != 0) {
    uVar5 = _splsched();
    piVar1 = (int *)(tVar4 + 0x20);
    do {
      do {
      } while (*piVar1 != 0);
      LOCK();
      iVar2 = *piVar1;
      *piVar1 = 1;
      UNLOCK();
    } while (iVar2 == 1);
    iVar2 = *(int *)(tVar4 + 0x8c);
    if (((0 < iVar2) && (*(int *)(tVar4 + 0x8c) = iVar2 + -1, iVar2 == 1)) &&
       (iVar2 = *(int *)(tVar4 + 0x40), *(int *)(tVar4 + 0x40) = iVar2 + -1, iVar2 == 1)) {
      uVar3 = *(uint *)(tVar4 + 0x4c);
      uVar6 = uVar3 & 0xffffffed;
      *(uint *)(tVar4 + 0x4c) = uVar6;
      if ((uVar3 & 5) == 0) {
        *(uint *)(tVar4 + 0x4c) = uVar6 | 4;
        _thread_setrun(tVar4,1);
      }
    }
    LOCK();
    *(undefined4 *)(tVar4 + 0x20) = 0;
    UNLOCK();
    _splx(uVar5);
  }
  return local_8;
}

