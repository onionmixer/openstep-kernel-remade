/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00109248 */

void _setsigvec(int param_1,int *param_2)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  int *piVar5;
  uint uVar6;
  
  uVar6 = 1 << ((char)param_1 - 1U & 0x1f);
  iVar3 = *_active_u;
  _splhigh();
  piVar1 = (int *)(iVar3 + 0x70);
  do {
    do {
    } while (*piVar1 != 0);
    LOCK();
    iVar2 = *piVar1;
    *piVar1 = 1;
    UNLOCK();
  } while (iVar2 == 1);
  _active_u[param_1 + 0xc] = *param_2;
  if ((*(byte *)(*_active_u + 0x16) & 2) == 0) {
    uVar4 = param_2[1] & 0xfffafeff;
  }
  else {
    uVar4 = param_2[1] & 0xfffefeff;
  }
  _active_u[param_1 + 0x2d] = uVar4;
  if ((*(byte *)(param_2 + 2) & 2) == 0) {
    _active_u[0x50] = _active_u[0x50] & ~uVar6;
  }
  else {
    _active_u[0x50] = _active_u[0x50] | uVar6;
  }
  if ((*(byte *)(param_2 + 2) & 1) == 0) {
    _active_u[0x4f] = _active_u[0x4f] & ~uVar6;
  }
  else {
    _active_u[0x4f] = _active_u[0x4f] | uVar6;
  }
  if ((*param_2 == 1) ||
     ((((*(byte *)(iVar3 + 0x16) & 2) != 0 && (*param_2 == 0)) && (param_1 == 0x14)))) {
    *(uint *)(iVar3 + 0x18) = *(uint *)(iVar3 + 0x18) & ~uVar6;
    if ((uVar6 & 0x1ef8) != 0) {
      piVar5 = *(int **)(iVar3 + 0x68);
      piVar1 = piVar5 + 7;
      do {
        do {
        } while (*piVar5 != 0);
        LOCK();
        iVar2 = *piVar5;
        *piVar5 = 1;
        UNLOCK();
      } while (iVar2 == 1);
      piVar5 = (int *)*piVar1;
      if (piVar1 != piVar5) {
        do {
          *(uint *)(piVar5[0x21] + 0x7c) = *(uint *)(piVar5[0x21] + 0x7c) & ~uVar6;
          piVar5 = (int *)piVar5[4];
        } while (piVar1 != piVar5);
      }
      LOCK();
      **(undefined4 **)(iVar3 + 0x68) = 0;
      UNLOCK();
    }
    *(uint *)(iVar3 + 0x20) = *(uint *)(iVar3 + 0x20) | uVar6;
    *(uint *)(iVar3 + 0x24) = *(uint *)(iVar3 + 0x24) & ~uVar6;
  }
  else {
    *(uint *)(iVar3 + 0x20) = *(uint *)(iVar3 + 0x20) & ~uVar6;
    if (*param_2 == 0) {
      if ((*(byte *)(iVar3 + 0x16) & 2) != 0) {
        _active_u[param_1 + 0xc] = 0;
      }
      *(uint *)(iVar3 + 0x24) = *(uint *)(iVar3 + 0x24) & ~uVar6;
    }
    else {
      *(uint *)(iVar3 + 0x24) = *(uint *)(iVar3 + 0x24) | uVar6;
    }
  }
  LOCK();
  *(undefined4 *)(iVar3 + 0x70) = 0;
  UNLOCK();
  _spl0();
  return;
}

