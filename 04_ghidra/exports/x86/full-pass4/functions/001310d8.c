/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001310d8 */

void FUN_001310d8(int param_1,char *param_2)

{
  uint uVar1;
  uint uVar2;
  char *pcVar3;
  char *pcVar4;
  char *pcVar5;
  char local_10 [12];
  
  pcVar3 = local_10;
  uVar2 = (uint)*(byte *)(param_1 + 7);
  do {
    uVar1 = uVar2 / 10;
    *pcVar3 = s_0123456789_001dca0f[uVar2 % 10];
    pcVar3 = pcVar3 + 1;
    uVar2 = uVar1;
  } while ((short)uVar1 != 0);
  do {
    pcVar4 = param_2;
    pcVar3 = pcVar3 + -1;
    *pcVar4 = *pcVar3;
    param_2 = pcVar4 + 1;
  } while (local_10 < pcVar3);
  pcVar4[1] = '.';
  pcVar3 = local_10;
  uVar2 = (uint)*(byte *)(param_1 + 6);
  do {
    uVar1 = uVar2 / 10;
    *pcVar3 = s_0123456789_001dca0f[uVar2 % 10];
    pcVar3 = pcVar3 + 1;
    uVar2 = uVar1;
  } while ((short)uVar1 != 0);
  pcVar4 = pcVar4 + 2;
  do {
    pcVar5 = pcVar4;
    pcVar3 = pcVar3 + -1;
    *pcVar5 = *pcVar3;
    pcVar4 = pcVar5 + 1;
  } while (local_10 < pcVar3);
  pcVar5[1] = '.';
  pcVar3 = local_10;
  uVar2 = (uint)*(byte *)(param_1 + 5);
  do {
    uVar1 = uVar2 / 10;
    *pcVar3 = s_0123456789_001dca0f[uVar2 % 10];
    pcVar3 = pcVar3 + 1;
    uVar2 = uVar1;
  } while ((short)uVar1 != 0);
  pcVar4 = pcVar5 + 2;
  do {
    pcVar5 = pcVar4;
    pcVar3 = pcVar3 + -1;
    *pcVar5 = *pcVar3;
    pcVar4 = pcVar5 + 1;
  } while (local_10 < pcVar3);
  pcVar5[1] = '.';
  pcVar5 = pcVar5 + 2;
  pcVar3 = local_10;
  uVar2 = (uint)*(byte *)(param_1 + 4);
  do {
    uVar1 = uVar2 / 10;
    *pcVar3 = s_0123456789_001dca0f[uVar2 % 10];
    pcVar3 = pcVar3 + 1;
    uVar2 = uVar1;
  } while ((short)uVar1 != 0);
  do {
    pcVar3 = pcVar3 + -1;
    *pcVar5 = *pcVar3;
    pcVar5 = pcVar5 + 1;
  } while (local_10 < pcVar3);
  *pcVar5 = '\0';
  return;
}

