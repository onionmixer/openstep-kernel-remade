/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001d00e8 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Restarted to delay deadcode elimination for space: ram */

byte * __sel_registerName(byte *param_1)

{
  undefined4 uVar1;
  undefined *puVar2;
  int iVar3;
  uint uVar4;
  undefined4 *puVar5;
  byte *pbVar6;
  uint local_10;
  
  if (param_1 == (byte *)0x0) {
    return (byte *)0x0;
  }
  uVar4 = 0;
  for (pbVar6 = param_1; puVar2 = PTR_DAT_001e5640, *pbVar6 != 0; pbVar6 = pbVar6 + 4) {
    uVar4 = uVar4 ^ *pbVar6;
    if (pbVar6[1] == 0) break;
    uVar4 = uVar4 ^ (uint)pbVar6[1] << 8;
    if (pbVar6[2] == 0) break;
    uVar4 = uVar4 ^ (uint)pbVar6[2] << 0x10;
    if (pbVar6[3] == 0) break;
    uVar4 = uVar4 ^ (uint)pbVar6[3] << 0x18;
  }
  while( true ) {
    if (puVar2 == (undefined *)0x0) {
                    /* WARNING: Subroutine does not return */
      _abort();
    }
    if ((*(byte **)(puVar2 + 0xc) <= param_1) && (param_1 < *(byte **)(puVar2 + 0x10))) break;
    local_10 = uVar4 % *(uint *)(puVar2 + 4);
    for (puVar5 = *(undefined4 **)(*(int *)(puVar2 + 0x14) + local_10 * 4);
        puVar5 != (undefined4 *)0x0; puVar5 = (undefined4 *)*puVar5) {
      if ((*(byte *)puVar5[1] == *param_1) &&
         (iVar3 = _strcmp((char *)param_1,(char *)puVar5[1]), iVar3 == 0)) {
        return (byte *)puVar5[1];
      }
    }
    if (puVar2 == &DAT_001e5624) {
      _DAT_001e562c = _DAT_001e562c + 1;
      if ((undefined4 *)PTR_DAT_001e5638 == &DAT_001d6750) {
        DAT_001e5628 = 0x335;
        PTR_DAT_001e5638 = (undefined *)FUN_001cffec(0xcd4);
        _memset(PTR_DAT_001e5638,0,DAT_001e5628 * 4);
        local_10 = uVar4 % DAT_001e5628;
      }
      uVar1 = *(undefined4 *)(PTR_DAT_001e5638 + local_10 * 4);
      if ((DAT_001e5648 == 0) || (0x27 < DAT_001e564c)) {
        DAT_001e5648 = FUN_001cffec(0x140);
        DAT_001e564c = 0;
      }
      puVar5 = (undefined4 *)(DAT_001e564c * 8 + DAT_001e5648);
      DAT_001e564c = DAT_001e564c + 1;
      *puVar5 = uVar1;
      puVar5[1] = param_1;
      *(undefined4 **)(PTR_DAT_001e5638 + local_10 * 4) = puVar5;
      return param_1;
    }
    puVar2 = *(undefined **)(puVar2 + 0x18);
  }
  return param_1;
}

