/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00154b28 */

int _mach_port_names_helper
              (int param_1,uint *param_2,undefined4 param_3,int param_4,int param_5,int *param_6)

{
  int iVar1;
  int *piVar2;
  bool bVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  
  uVar4 = *param_2;
  uVar6 = param_2[2];
  if ((uVar4 & 0x50000) != 0) {
    piVar2 = (int *)param_2[1];
    do {
      do {
      } while (*piVar2 != 0);
      LOCK();
      iVar1 = *piVar2;
      *piVar2 = 1;
      UNLOCK();
    } while (iVar1 == 1);
    bVar3 = false;
    if ((-1 < piVar2[2]) && (piVar2[3] - param_1 < 0)) {
      bVar3 = true;
    }
    LOCK();
    iVar1 = *piVar2;
    *piVar2 = 0;
    UNLOCK();
    if (bVar3) {
      if ((uVar4 & 0x400000) != 0) {
        return iVar1;
      }
      uVar4 = uVar4 & 0xffc0ffff | 0x100000;
      if (uVar6 != 0) {
        uVar4 = uVar4 + 1;
      }
      uVar6 = 0;
    }
  }
  uVar5 = uVar4 & 0x1f0000;
  if ((uVar4 & 0x400000) == 0) {
    if (uVar6 != 0) {
      uVar5 = uVar5 | 0x80000000;
    }
  }
  else {
    uVar5 = uVar5 | 0x20000000;
  }
  if ((uVar4 & 0x200000) != 0) {
    uVar5 = uVar5 | 0x40000000;
  }
  iVar1 = *param_6;
  *(undefined4 *)(param_4 + iVar1 * 4) = param_3;
  *(uint *)(param_5 + iVar1 * 4) = uVar5;
  *param_6 = iVar1 + 1;
  return iVar1 + 1;
}

