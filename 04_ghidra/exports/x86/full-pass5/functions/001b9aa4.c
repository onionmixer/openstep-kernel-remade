/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001b9aa4 */

int FUN_001b9aa4(int param_1,undefined4 param_2,int param_3,int param_4,uint param_5,int *param_6)

{
  ushort uVar1;
  int iVar2;
  uint uVar3;
  ushort *puVar4;
  uint local_c;
  ushort *local_8;
  
  puVar4 = *(ushort **)(param_3 + 0xc);
  local_c = *(int *)(param_3 + 8) - (int)puVar4;
  if ((param_5 != 0) && (local_c != 0)) {
    iVar2 = *param_6;
    if (param_5 < local_c + iVar2) {
      local_c = param_5 - iVar2;
    }
    local_8 = (ushort *)(iVar2 + *(int *)(param_4 + 4));
    iVar2 = *(int *)(param_1 + 0x68);
    if (iVar2 == 0) {
      uVar3 = 0;
      if (local_c >> 1 != 0) {
        do {
          uVar1 = *local_8;
          local_8 = local_8 + 1;
          *puVar4 = uVar1 >> 8 | uVar1 << 8;
          puVar4 = puVar4 + 1;
          uVar3 = uVar3 + 1;
        } while (uVar3 < local_c >> 1);
      }
    }
    else if (iVar2 == 3) {
      uVar3 = 0;
      if (local_c != 0) {
        do {
          *(byte *)puVar4 = (byte)*local_8 ^ 0x80 | (byte)*local_8 & 0x7f;
          puVar4 = (ushort *)((int)puVar4 + 1);
          local_8 = (ushort *)((int)local_8 + 1);
          uVar3 = uVar3 + 1;
        } while (uVar3 < local_c);
      }
    }
    else if (iVar2 == 1) {
      _bcopy(local_8,puVar4,local_c);
    }
    *param_6 = *param_6 + local_c;
    *(int *)(param_3 + 0xc) = *(int *)(param_3 + 0xc) + local_c;
    *(int *)(param_1 + 0x20) = *(int *)(param_1 + 0x20) + local_c;
  }
  if ((*(int *)(param_3 + 0x24) == param_4) || (*(int *)(param_3 + 0x30) != 0)) {
    _objc_msgSend(param_1,PTR_s_sendRecordedDataForRegion__001f9708,param_3);
  }
  return param_1;
}

