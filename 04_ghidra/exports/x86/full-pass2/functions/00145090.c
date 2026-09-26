/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00145090 */

undefined4 FUN_00145090(int param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  
  iVar1 = *(int *)(param_1 + 0x30);
  iVar2 = *param_2;
  if (((param_2[1] == 1) && (0x3ff < *(uint *)(iVar2 + 4))) && ((param_2[2] & 0x3ffU) == 0)) {
    uVar4 = *(uint *)(iVar2 + 4) & 0xfffffc00;
    param_2[5] = param_2[5] - (*(int *)(iVar2 + 4) - uVar4);
    *(uint *)(iVar2 + 4) = uVar4;
    uVar3 = FUN_00143e24(iVar1,param_2,0,0);
    if ((*(ushort *)(iVar1 + 0x44) & 0x46) != 0) {
      *(ushort *)(iVar1 + 0x44) = *(ushort *)(iVar1 + 0x44) | 8;
      _microtime(&_iuniqtime);
      if ((*(byte *)(iVar1 + 0x44) & 4) != 0) {
        *(undefined4 *)(iVar1 + 0x74) = _iuniqtime;
      }
      if ((*(byte *)(iVar1 + 0x44) & 2) != 0) {
        *(undefined4 *)(iVar1 + 0x7c) = _iuniqtime;
      }
      if ((*(byte *)(iVar1 + 0x44) & 0x40) != 0) {
        *(undefined4 *)(iVar1 + 0x4c) = 0;
        *(undefined4 *)(iVar1 + 0x84) = _iuniqtime;
      }
      *(byte *)(iVar1 + 0x44) = *(byte *)(iVar1 + 0x44) & 0xb9;
    }
  }
  else {
    uVar3 = 0x16;
  }
  return uVar3;
}

