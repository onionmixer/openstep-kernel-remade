/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001401f8 */

void _disksort_enter_head(int param_1,int param_2)

{
  int iVar1;
  code *pcVar2;
  
  if (DAT_001f50ec == 0) {
    if ((*(byte *)(param_1 + 0xc) & 1) != 0) {
      iVar1 = (*DAT_001f50dc)(param_1);
      if (iVar1 == 0) {
        *(byte *)(param_1 + 0xc) = *(byte *)(param_1 + 0xc) & 0xfe;
        pcVar2 = DAT_001f50e8;
        goto LAB_0014024b;
      }
      goto LAB_00140250;
    }
LAB_00140264:
    *(undefined4 *)(param_2 + 0x3c) = 0x1f;
    FUN_0013f9a4(param_1,param_2);
  }
  else {
    if ((*(byte *)(param_1 + 0xc) & 1) == 0) {
      if (*(int *)(param_1 + 0x10) == param_1 + 0x10) {
        *(byte *)(param_1 + 0xc) = *(byte *)(param_1 + 0xc) | 1;
        pcVar2 = DAT_001f50e4;
LAB_0014024b:
        (*pcVar2)(param_1);
      }
LAB_00140250:
      if ((*(byte *)(param_1 + 0xc) & 1) == 0) goto LAB_00140264;
    }
    (*DAT_001f50d4)(param_1,param_2);
  }
  return;
}

