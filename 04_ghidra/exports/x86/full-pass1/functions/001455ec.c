/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001455ec */

void FUN_001455ec(byte *param_1)

{
  ushort uVar1;
  uint uVar2;
  int iVar3;
  bool bVar4;
  undefined2 uVar5;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 *local_20;
  undefined4 local_1c;
  int local_18;
  undefined4 local_14;
  undefined4 local_c;
  undefined4 local_8;
  
  local_18 = (**(code **)(*(int *)(*(int *)(param_1 + 0x40) + 0x1c) + 0x80))
                       (*(int *)(param_1 + 0x40));
  if ((*param_1 & 1) == 0) {
    local_18 = local_18 * *(int *)(param_1 + 0x24);
    iVar3 = *(int *)(*(int *)(param_1 + 0x40) + 0x30);
    local_24 = *(undefined4 *)(param_1 + 0x14);
    local_28 = *(undefined4 *)(param_1 + 0x20);
    local_20 = &local_28;
    local_1c = 1;
    local_14 = 1;
    local_c = local_24;
    if (**(int **)(iVar3 + 0xc) != 0) {
      _vnode_uncache(iVar3 + 0xc);
    }
    uVar2 = *(uint *)(iVar3 + 0x3c);
    if ((*(ushort *)(uVar2 + 100) & 0xf000) == 0x8000) {
      bVar4 = true;
      while ((*(ushort *)(uVar2 + 0x44) & 1) != 0) {
        *(ushort *)(uVar2 + 0x44) = *(ushort *)(uVar2 + 0x44) | 0x10;
        _sleep(uVar2);
      }
      *(byte *)(uVar2 + 0x44) = *(byte *)(uVar2 + 0x44) | 1;
    }
    else {
      bVar4 = false;
    }
    uVar5 = FUN_00143e24(uVar2,&local_20,1,0);
    if ((*(ushort *)(uVar2 + 0x44) & 0x46) != 0) {
      *(ushort *)(uVar2 + 0x44) = *(ushort *)(uVar2 + 0x44) | 8;
      _microtime(&_iuniqtime);
      if ((*(byte *)(uVar2 + 0x44) & 4) != 0) {
        *(undefined4 *)(uVar2 + 0x74) = _iuniqtime;
      }
      if ((*(byte *)(uVar2 + 0x44) & 2) != 0) {
        *(undefined4 *)(uVar2 + 0x7c) = _iuniqtime;
      }
      if ((*(byte *)(uVar2 + 0x44) & 0x40) != 0) {
        *(undefined4 *)(uVar2 + 0x4c) = 0;
        *(undefined4 *)(uVar2 + 0x84) = _iuniqtime;
      }
      *(byte *)(uVar2 + 0x44) = *(byte *)(uVar2 + 0x44) & 0xb9;
    }
  }
  else {
    local_18 = local_18 * *(int *)(param_1 + 0x24);
    local_24 = *(undefined4 *)(param_1 + 0x14);
    local_28 = *(undefined4 *)(param_1 + 0x20);
    local_20 = &local_28;
    local_1c = 1;
    local_14 = 1;
    uVar2 = *(uint *)(*(int *)(*(int *)(param_1 + 0x40) + 0x30) + 0x3c);
    local_c = local_24;
    if ((*(ushort *)(uVar2 + 100) & 0xf000) == 0x8000) {
      bVar4 = true;
      while ((*(ushort *)(uVar2 + 0x44) & 1) != 0) {
        *(ushort *)(uVar2 + 0x44) = *(ushort *)(uVar2 + 0x44) | 0x10;
        _sleep(uVar2);
      }
      *(byte *)(uVar2 + 0x44) = *(byte *)(uVar2 + 0x44) | 1;
    }
    else {
      bVar4 = false;
    }
    uVar5 = FUN_00143e24(uVar2,&local_20,0,0);
    if ((*(ushort *)(uVar2 + 0x44) & 0x46) != 0) {
      *(ushort *)(uVar2 + 0x44) = *(ushort *)(uVar2 + 0x44) | 8;
      _microtime(&_iuniqtime);
      if ((*(byte *)(uVar2 + 0x44) & 4) != 0) {
        *(undefined4 *)(uVar2 + 0x74) = _iuniqtime;
      }
      if ((*(byte *)(uVar2 + 0x44) & 2) != 0) {
        *(undefined4 *)(uVar2 + 0x7c) = _iuniqtime;
      }
      if ((*(byte *)(uVar2 + 0x44) & 0x40) != 0) {
        *(undefined4 *)(uVar2 + 0x4c) = 0;
        *(undefined4 *)(uVar2 + 0x84) = _iuniqtime;
      }
      *(byte *)(uVar2 + 0x44) = *(byte *)(uVar2 + 0x44) & 0xb9;
    }
  }
  if (bVar4) {
    uVar1 = *(ushort *)(uVar2 + 0x44);
    *(ushort *)(uVar2 + 0x44) = uVar1 & 0xfffe;
    if ((uVar1 & 0x10) != 0) {
      *(ushort *)(uVar2 + 0x44) = uVar1 & 0xffee;
      _wakeup(uVar2);
    }
  }
  local_8 = local_c;
  *(undefined2 *)(param_1 + 0x1c) = uVar5;
  *(undefined4 *)(param_1 + 0x28) = local_c;
  if (*(short *)(param_1 + 0x1c) != 0) {
    *param_1 = *param_1 | 4;
  }
  _biodone(param_1);
  return;
}

