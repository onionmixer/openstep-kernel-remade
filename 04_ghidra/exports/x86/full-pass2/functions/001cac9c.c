/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001cac9c */

void __NXAddHandler(int param_1)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = _current_thread_EXTERNAL();
  piVar2 = &DAT_001e551c;
  do {
    if (piVar2[4] == iVar1) goto LAB_001cacc6;
    piVar2 = (int *)piVar2[5];
  } while (piVar2 != (int *)0x0);
  piVar2 = (int *)FUN_001ca960(iVar1);
LAB_001cacc6:
  *(int *)(param_1 + 0x48) = *piVar2;
  *piVar2 = param_1;
  *(undefined4 *)(param_1 + 0x4c) = 0;
  return;
}

