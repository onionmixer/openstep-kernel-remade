/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00144be0 */

undefined4 FUN_00144be0(int param_1,int param_2,undefined4 param_3)

{
  byte *pbVar1;
  ushort uVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  int local_8;
  
  iVar3 = (**(code **)(*(int *)(param_1 + 0x1c) + 0x70))(param_1,&local_8);
  if (iVar3 == 0) {
    param_1 = local_8;
  }
  iVar3 = *(int *)(param_1 + 0x30);
  if ((*(byte *)(*_active_u + 0x16) & 2) == 0) {
    if (((*(ushort *)(iVar3 + 100) & 0xf000) == 0x4000) && (iVar4 = _suser(), iVar4 == 0)) {
      return 1;
    }
  }
  else if ((*(ushort *)(iVar3 + 100) & 0xf000) == 0x4000) {
    return 1;
  }
  uVar5 = _direnter(*(undefined4 *)(param_2 + 0x30),param_3,1,0,iVar3,0,0);
  if ((*(ushort *)(iVar3 + 0x44) & 0x46) != 0) {
    *(ushort *)(iVar3 + 0x44) = *(ushort *)(iVar3 + 0x44) | 8;
    _microtime(&_iuniqtime);
    if ((*(byte *)(iVar3 + 0x44) & 4) != 0) {
      *(undefined4 *)(iVar3 + 0x74) = _iuniqtime;
    }
    if ((*(byte *)(iVar3 + 0x44) & 2) != 0) {
      *(undefined4 *)(iVar3 + 0x7c) = _iuniqtime;
    }
    if ((*(byte *)(iVar3 + 0x44) & 0x40) != 0) {
      *(undefined4 *)(iVar3 + 0x4c) = 0;
      *(undefined4 *)(iVar3 + 0x84) = _iuniqtime;
    }
    *(byte *)(iVar3 + 0x44) = *(byte *)(iVar3 + 0x44) & 0xb9;
  }
  uVar2 = *(ushort *)(*(int *)(param_2 + 0x30) + 0x44);
  if ((uVar2 & 0x46) != 0) {
    *(ushort *)(*(int *)(param_2 + 0x30) + 0x44) = uVar2 | 8;
    _microtime(&_iuniqtime);
    if ((*(byte *)(*(int *)(param_2 + 0x30) + 0x44) & 4) != 0) {
      *(undefined4 *)(*(int *)(param_2 + 0x30) + 0x74) = _iuniqtime;
    }
    if ((*(byte *)(*(int *)(param_2 + 0x30) + 0x44) & 2) != 0) {
      *(undefined4 *)(*(int *)(param_2 + 0x30) + 0x7c) = _iuniqtime;
    }
    if ((*(byte *)(*(int *)(param_2 + 0x30) + 0x44) & 0x40) != 0) {
      *(undefined4 *)(*(int *)(param_2 + 0x30) + 0x4c) = 0;
      *(undefined4 *)(*(int *)(param_2 + 0x30) + 0x84) = _iuniqtime;
    }
    pbVar1 = (byte *)(*(int *)(param_2 + 0x30) + 0x44);
    *pbVar1 = *pbVar1 & 0xb9;
  }
  return uVar5;
}

