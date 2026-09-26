/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001c80f8 */

int FUN_001c80f8(int param_1,undefined4 param_2,undefined4 *param_3,int param_4)

{
  undefined1 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  if (*(int *)(param_1 + 0x228) != 0) {
    _IOFree(*(int *)(param_1 + 0x228),*(int *)(param_1 + 0x234) * 3);
  }
  *(int *)(param_1 + 0x234) = param_4;
  iVar4 = _IOMalloc(param_4 * 3);
  *(int *)(param_1 + 0x228) = iVar4;
  *(int *)(param_1 + 0x22c) = iVar4 + param_4;
  *(int *)(param_1 + 0x230) = iVar4 + param_4 + param_4;
  iVar4 = _objc_msgSend(param_1,PTR_s_displayInfo_001f9610);
  if (*(uint *)(iVar4 + 0x18) < 2) {
    iVar4 = 0;
    if (0 < param_4) {
      do {
        iVar2 = *(int *)(param_1 + 0x228);
        iVar3 = *(int *)(param_1 + 0x22c);
        uVar1 = *(undefined1 *)(param_3 + iVar4);
        *(undefined1 *)(iVar4 + *(int *)(param_1 + 0x230)) = uVar1;
        *(undefined1 *)(iVar4 + iVar3) = uVar1;
        *(undefined1 *)(iVar4 + iVar2) = uVar1;
        iVar4 = iVar4 + 1;
      } while (iVar4 < param_4);
    }
  }
  else if (*(uint *)(iVar4 + 0x18) < 5) {
    iVar4 = 0;
    if (0 < param_4) {
      do {
        *(undefined1 *)(iVar4 + *(int *)(param_1 + 0x228)) = *(undefined1 *)((int)param_3 + 3);
        *(undefined1 *)(iVar4 + *(int *)(param_1 + 0x22c)) = *(undefined1 *)((int)param_3 + 2);
        *(char *)(iVar4 + *(int *)(param_1 + 0x230)) = (char)((uint)*param_3 >> 8);
        param_3 = param_3 + 1;
        iVar4 = iVar4 + 1;
      } while (iVar4 < param_4);
    }
  }
  else {
    _IOFree(*(undefined4 *)(param_1 + 0x228),param_4 * 3);
    *(undefined4 *)(param_1 + 0x228) = 0;
  }
  _objc_msgSend(param_1,PTR_s_setGammaTable_001f9588);
  return param_1;
}

