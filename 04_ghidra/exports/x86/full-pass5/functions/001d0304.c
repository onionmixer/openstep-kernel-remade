/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001d0304 */

byte * _sel_getUid(byte *param_1)

{
  undefined4 *puVar1;
  undefined *puVar2;
  int iVar3;
  uint uVar4;
  byte *pbVar5;
  
  if (param_1 != (byte *)0x0) {
    uVar4 = 0;
    for (pbVar5 = param_1; puVar2 = PTR_DAT_001e5640, *pbVar5 != 0; pbVar5 = pbVar5 + 4) {
      uVar4 = uVar4 ^ *pbVar5;
      if (pbVar5[1] == 0) break;
      uVar4 = uVar4 ^ (uint)pbVar5[1] << 8;
      if (pbVar5[2] == 0) break;
      uVar4 = uVar4 ^ (uint)pbVar5[2] << 0x10;
      if (pbVar5[3] == 0) break;
      uVar4 = uVar4 ^ (uint)pbVar5[3] << 0x18;
    }
    for (; puVar2 != (undefined *)0x0; puVar2 = *(undefined **)(puVar2 + 0x18)) {
      if ((*(byte **)(puVar2 + 0xc) <= param_1) && (param_1 < *(byte **)(puVar2 + 0x10))) {
        return param_1;
      }
      for (puVar1 = *(undefined4 **)(*(int *)(puVar2 + 0x14) + (uVar4 % *(uint *)(puVar2 + 4)) * 4);
          puVar1 != (undefined4 *)0x0; puVar1 = (undefined4 *)*puVar1) {
        if ((*(byte *)puVar1[1] == *param_1) &&
           (iVar3 = _strcmp((char *)param_1,(char *)puVar1[1]), iVar3 == 0)) {
          return (byte *)puVar1[1];
        }
      }
    }
  }
  return (byte *)0x0;
}

