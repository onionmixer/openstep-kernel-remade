/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00182484 */

undefined4
_kern_IOGetDriverConfig(int param_1,undefined4 param_2,uint param_3,void *param_4,int *param_5)

{
  char cVar1;
  undefined4 uVar2;
  char *pcVar3;
  uint uVar4;
  char *pcVar5;
  
  if (param_1 == 0) {
    uVar2 = 0xfffffd3f;
  }
  else {
    if (0xfff < param_3) {
      param_3 = 0xfff;
    }
    pcVar3 = (char *)_findBootConfigString(param_2);
    if (pcVar3 == (char *)0x0) {
      uVar2 = 0xfffffd40;
    }
    else {
      uVar4 = 0xffffffff;
      pcVar5 = pcVar3;
      do {
        if (uVar4 == 0) break;
        uVar4 = uVar4 - 1;
        cVar1 = *pcVar5;
        pcVar5 = pcVar5 + 1;
      } while (cVar1 != '\0');
      if (~uVar4 - 1 < param_3) {
        param_3 = ~uVar4 - 1;
      }
      _bcopy(pcVar3,param_4,param_3);
      *(undefined1 *)(param_3 + (int)param_4) = 0;
      *param_5 = param_3 + 1;
      uVar2 = 0;
    }
  }
  return uVar2;
}

