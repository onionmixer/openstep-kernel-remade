/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001aa2ac */

void FUN_001aa2ac(int param_1)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  int *piVar4;
  int *piVar5;
  int local_c;
  undefined *local_8;
  
  _objc_msgSend(param_1,PTR_s_clearTimeout_001f9b50);
  if (*(int *)(param_1 + 300) != 0) {
    _objc_msgSend(*(int *)(param_1 + 300),PTR_s_send__001f9b4c,4);
    _objc_msgSend(*(undefined4 *)(param_1 + 300),PTR_s_free_001f921c);
  }
  if (*(int *)(param_1 + 0x14c) != 0) {
    _objc_msgSend(*(int *)(param_1 + 0x14c),PTR_s_free_001f921c);
  }
  if (*(int *)(param_1 + 0x138) != 0) {
    _objc_msgSend(*(int *)(param_1 + 0x138),PTR_s_lock_001f9220);
    piVar1 = (int *)(param_1 + 0x144);
    piVar2 = *(int **)(param_1 + 0x144);
    while (piVar2 != piVar1) {
      iVar3 = *(int *)(param_1 + 0x144);
      piVar2 = *(int **)(iVar3 + 8);
      piVar4 = *(int **)(iVar3 + 0xc);
      piVar5 = piVar1;
      if (piVar1 != piVar2) {
        piVar5 = piVar2 + 2;
      }
      piVar5[1] = (int)piVar4;
      piVar5 = piVar1;
      if (piVar1 != piVar4) {
        piVar5 = piVar4 + 2;
      }
      *piVar5 = (int)piVar2;
      _IOFree(iVar3,0x14);
      piVar2 = *(int **)(param_1 + 0x144);
    }
    _objc_msgSend(*(undefined4 *)(param_1 + 0x138),PTR_s_unlock_001f9474);
    _objc_msgSend(*(undefined4 *)(param_1 + 0x138),PTR_s_free_001f921c);
  }
  local_c = param_1;
  local_8 = PTR_s_IODirectDevice_001fa2c0;
  _objc_msgSendSuper(&local_c,PTR_s_free_001f921c);
  return;
}

