/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00159000 */

void _thread_go(int param_1)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  undefined4 uVar4;
  
  uVar4 = _splsched();
  piVar1 = (int *)(param_1 + 0x20);
  do {
    do {
    } while (*piVar1 != 0);
    LOCK();
    iVar2 = *piVar1;
    *piVar1 = 1;
    UNLOCK();
  } while (iVar2 == 1);
  if (*(int *)(param_1 + 0x144) != 0) {
    _reset_timeout(param_1 + 0x118);
  }
  uVar3 = *(uint *)(param_1 + 0x4c);
  switch(uVar3 & 0xf) {
  case 1:
  case 9:
  case 0xb:
    *(uint *)(param_1 + 0x4c) = uVar3 & 0xfffffffe | 4;
    *(undefined4 *)(param_1 + 0x44) = 0;
    _thread_setrun(param_1,1);
    break;
  case 3:
  case 5:
  case 7:
  case 0xd:
  case 0xf:
    *(uint *)(param_1 + 0x4c) = uVar3 & 0xfffffffe;
    *(undefined4 *)(param_1 + 0x44) = 0;
  }
  LOCK();
  *(undefined4 *)(param_1 + 0x20) = 0;
  UNLOCK();
  _splx(uVar4);
  return;
}

