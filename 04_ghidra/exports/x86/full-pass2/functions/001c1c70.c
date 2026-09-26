/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001c1c70 */

undefined4 FUN_001c1c70(int param_1,undefined4 param_2,char *param_3,char *param_4,char *param_5)

{
  char *pcVar1;
  undefined4 uVar2;
  
  pcVar1 = *(char **)(param_1 + 0x24);
  if (*pcVar1 == '\0') {
    uVar2 = 0xfffffd40;
  }
  else {
    if (param_3 != (char *)0x0) {
      *param_3 = pcVar1[1];
    }
    if (param_4 != (char *)0x0) {
      *param_4 = pcVar1[2];
    }
    if (param_5 != (char *)0x0) {
      *param_5 = pcVar1[3];
    }
    uVar2 = 0;
  }
  return uVar2;
}

