/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001baa6c */

void FUN_001baa6c(int param_1)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  int *piVar4;
  int *piVar5;
  int local_c;
  undefined *local_8;
  
  if (*(int *)(param_1 + 0xa0) != 0) {
    _IOFree(*(int *)(param_1 + 0xa0),0x40);
  }
  if (*(int *)(param_1 + 0x9c) != 0) {
    _IOFree(*(int *)(param_1 + 0x9c),0x40);
  }
  piVar1 = (int *)(param_1 + 0x8c);
  piVar2 = *(int **)(param_1 + 0x8c);
  while (piVar2 != piVar1) {
    iVar3 = *(int *)(param_1 + 0x8c);
    piVar2 = *(int **)(iVar3 + 0x14);
    piVar4 = *(int **)(iVar3 + 0x18);
    piVar5 = piVar1;
    if (piVar1 != piVar2) {
      piVar5 = piVar2 + 5;
    }
    piVar5[1] = (int)piVar4;
    piVar5 = piVar1;
    if (piVar1 != piVar4) {
      piVar5 = piVar4 + 5;
    }
    *piVar5 = (int)piVar2;
    _IOFree(iVar3,0x1c);
    piVar2 = *(int **)(param_1 + 0x8c);
  }
  if (*(int *)(param_1 + 0x70) != 0) {
    _IOFree(*(int *)(param_1 + 0x70),_page_size * 8);
  }
  if (*(int *)(param_1 + 0x74) != 0) {
    _IOFree(*(int *)(param_1 + 0x74),_page_size * 4);
  }
  local_c = param_1;
  local_8 = PTR_s_AudioStream_001fa518;
  _objc_msgSendSuper(&local_c,PTR_s_free_001f921c);
  return;
}

