/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00184ac8 */

undefined4
_IOGetDDMEntry(uint param_1,uint param_2,char *param_3,undefined4 *param_4,undefined4 *param_5)

{
  char cVar1;
  undefined4 uVar2;
  uint uVar3;
  undefined4 *puVar4;
  char *pcVar5;
  char local_130 [300];
  
  if (param_1 < DAT_001f74cc) {
    puVar4 = (undefined4 *)(DAT_001f74c8 + param_1 * -0x24);
    if (puVar4 < DAT_001f74c4) {
      puVar4 = puVar4 + _uxprGlobal * 9;
    }
    _sprintf(local_130,(char *)*puVar4,puVar4[1],puVar4[2],puVar4[3],puVar4[4],puVar4[5]);
    uVar3 = 0xffffffff;
    pcVar5 = local_130;
    do {
      if (uVar3 == 0) break;
      uVar3 = uVar3 - 1;
      cVar1 = *pcVar5;
      pcVar5 = pcVar5 + 1;
    } while (cVar1 != '\0');
    if (param_2 < ~uVar3 - 1) {
      local_130[param_2 - 1] = '\0';
    }
    _strcpy(param_3,local_130);
    *param_4 = puVar4[6];
    param_4[1] = puVar4[7];
    *param_5 = puVar4[8];
    uVar2 = 0;
  }
  else {
    uVar2 = 0xffffffff;
  }
  return uVar2;
}

