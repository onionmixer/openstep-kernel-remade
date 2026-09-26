/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0014027c */

void _disksort_enter_tail(int param_1,int param_2)

{
  int iVar1;
  code *pcVar2;
  
  if (DAT_001f50ec == 0) {
    if ((*(byte *)(param_1 + 0xc) & 1) != 0) {
      iVar1 = (*DAT_001f50dc)(param_1);
      if (iVar1 == 0) {
        *(byte *)(param_1 + 0xc) = *(byte *)(param_1 + 0xc) & 0xfe;
        pcVar2 = DAT_001f50e8;
        goto LAB_001402cf;
      }
      goto LAB_001402d4;
    }
LAB_001402e8:
    *(undefined4 *)(param_2 + 0x3c) = 0;
    FUN_0013f9a4(param_1,param_2);
  }
  else {
    if ((*(byte *)(param_1 + 0xc) & 1) == 0) {
      if (*(int *)(param_1 + 0x10) == param_1 + 0x10) {
        *(byte *)(param_1 + 0xc) = *(byte *)(param_1 + 0xc) | 1;
        pcVar2 = DAT_001f50e4;
LAB_001402cf:
        (*pcVar2)(param_1);
      }
LAB_001402d4:
      if ((*(byte *)(param_1 + 0xc) & 1) == 0) goto LAB_001402e8;
    }
    (*_ds_call)(param_1,param_2);
  }
  return;
}

