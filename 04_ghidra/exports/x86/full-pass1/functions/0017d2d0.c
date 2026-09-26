/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0017d2d0 */

undefined4 _vnode_pagein(int param_1,undefined4 *param_2)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  bool bVar4;
  int iVar5;
  int *piVar6;
  uint local_8;
  
  bVar4 = false;
  iVar1 = *(int *)(*(int *)(param_1 + 0x14) + 0x28);
  do {
  } while (_vstruct_lock != 0);
  LOCK();
  UNLOCK();
  *(short *)(iVar1 + 0xe) = *(short *)(iVar1 + 0xe) + 1;
  LOCK();
  _vstruct_lock = 0;
  UNLOCK();
  piVar6 = *(int **)(iVar1 + 0x14);
  iVar5 = *(int *)(param_1 + 0x18) + *(int *)(*(int *)(param_1 + 0x14) + 0x2c);
  if ((*(byte *)(iVar1 + 0xc) & 1) != 0) {
    iVar2 = FUN_0017cd58(iVar1,iVar5,1,&local_8);
    bVar4 = false;
    if (iVar2 == 5) {
      bVar4 = true;
    }
    else {
      iVar5 = (local_8 >> 8) << ((byte)_page_shift & 0x1f);
      piVar6 = *(int **)(*(int *)(&DAT_001e7294 + (local_8 & 0xff) * 4) + 8);
    }
  }
  uVar3 = 1;
  if ((!bVar4) &&
     (uVar3 = (**(code **)(piVar6[7] + 0x74))(piVar6,param_1,iVar5), param_2 != (undefined4 *)0x0))
  {
    *param_2 = *(undefined4 *)(*piVar6 + 0x34);
  }
  do {
  } while (_vstruct_lock != 0);
  LOCK();
  UNLOCK();
  *(short *)(iVar1 + 0xe) = *(short *)(iVar1 + 0xe) + -1;
  LOCK();
  _vstruct_lock = 0;
  UNLOCK();
  return uVar3;
}

