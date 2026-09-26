/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0011efd4 */

undefined4 * _ifunit(char *param_1)

{
  char cVar1;
  undefined4 *puVar2;
  int iVar3;
  char *pcVar4;
  
  for (pcVar4 = param_1; pcVar4 < param_1 + 0x10; pcVar4 = pcVar4 + 1) {
    if (*pcVar4 == '\0') goto LAB_0011f00a;
    if ((byte)(*pcVar4 - 0x30U) < 10) break;
  }
  cVar1 = *pcVar4;
  if ((cVar1 == '\0') || (pcVar4 == param_1 + 0x10)) {
LAB_0011f00a:
    puVar2 = (undefined4 *)0x0;
  }
  else {
    for (puVar2 = _ifnet;
        (puVar2 != (undefined4 *)0x0 &&
        (((iVar3 = _bcmp((void *)*puVar2,param_1,(int)pcVar4 - (int)param_1), iVar3 != 0 ||
          (puVar2[5] != 0x1000)) || (cVar1 + -0x30 != (int)*(short *)(puVar2 + 2)))));
        puVar2 = (undefined4 *)puVar2[0x17]) {
    }
  }
  return puVar2;
}

