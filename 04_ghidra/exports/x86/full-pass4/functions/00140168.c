/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00140168 */

void _disksort_enter(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  code *pcVar3;
  
  iVar1 = _active_threads;
  if (DAT_001f50ec == 0) {
    if ((*(byte *)(param_1 + 0xc) & 1) != 0) {
      iVar2 = (*DAT_001f50dc)(param_1);
      if (iVar2 == 0) {
        *(byte *)(param_1 + 0xc) = *(byte *)(param_1 + 0xc) & 0xfe;
        pcVar3 = DAT_001f50e8;
        goto LAB_001401c3;
      }
      goto LAB_001401c8;
    }
LAB_001401dc:
    if (iVar1 != 0) {
      *(undefined4 *)(param_2 + 0x3c) = *(undefined4 *)(iVar1 + 0x50);
    }
    FUN_0013f9a4(param_1,param_2);
  }
  else {
    if ((*(byte *)(param_1 + 0xc) & 1) == 0) {
      if (*(int *)(param_1 + 0x10) == param_1 + 0x10) {
        *(byte *)(param_1 + 0xc) = *(byte *)(param_1 + 0xc) | 1;
        pcVar3 = DAT_001f50e4;
LAB_001401c3:
        (*pcVar3)(param_1);
      }
LAB_001401c8:
      if ((*(byte *)(param_1 + 0xc) & 1) == 0) goto LAB_001401dc;
    }
    (*_ds_call)(param_1,param_2);
  }
  return;
}

