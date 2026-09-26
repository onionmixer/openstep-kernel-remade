/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00116650 */

void _sbappendrecord(short *param_1,undefined4 *param_2)

{
  short sVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  
  if (param_2 != (undefined4 *)0x0) {
    iVar4 = *(int *)(param_1 + 6);
    if (iVar4 != 0) {
      iVar2 = *(int *)(iVar4 + 0x7c);
      while (iVar2 != 0) {
        iVar4 = *(int *)(iVar4 + 0x7c);
        iVar2 = *(int *)(iVar4 + 0x7c);
      }
    }
    *param_1 = *param_1 + *(short *)(param_2 + 2);
    sVar1 = param_1[2];
    param_1[2] = sVar1 + 0x80;
    if (0x7c < (uint)param_2[1]) {
      param_1[2] = sVar1 + 0x480;
    }
    if (iVar4 == 0) {
      *(undefined4 **)(param_1 + 6) = param_2;
    }
    else {
      *(undefined4 **)(iVar4 + 0x7c) = param_2;
    }
    uVar3 = *param_2;
    *param_2 = 0;
    _sbcompress(param_1,uVar3,param_2);
  }
  return;
}

