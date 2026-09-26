/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0010c9a8 */

void FUN_0010c9a8(uint param_1,uint param_2,undefined4 param_3,undefined4 param_4,int param_5,
                 int param_6)

{
  uint uVar1;
  char *pcVar2;
  undefined4 uVar3;
  char local_10 [12];
  
  if ((param_2 == 10) && ((int)param_1 < 0)) {
    FUN_0010cbac(0x2d,param_3,param_4);
    param_1 = -param_1;
  }
  pcVar2 = local_10;
  do {
    uVar1 = param_1 / param_2;
    *pcVar2 = s_0123456789abcdef_001dac23[param_1 % param_2];
    pcVar2 = pcVar2 + 1;
    param_1 = uVar1;
  } while (uVar1 != 0);
  if (param_6 != 0) {
    for (param_6 = param_6 - ((int)pcVar2 - (int)local_10); 0 < param_6; param_6 = param_6 + -1) {
      if (param_5 == 0) {
        uVar3 = 0x20;
      }
      else {
        uVar3 = 0x30;
      }
      FUN_0010cbac(uVar3,param_3,param_4);
    }
  }
  do {
    pcVar2 = pcVar2 + -1;
    FUN_0010cbac((int)*pcVar2,param_3,param_4);
  } while (local_10 < pcVar2);
  return;
}

