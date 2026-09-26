/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001427b4 */

void FUN_001427b4(void *param_1,int param_2)

{
  int *piVar1;
  void *pvVar2;
  
  if (*(int *)((int)param_1 + 4) == *(int *)(param_2 + 4)) {
    *(int *)((int)param_1 + 4) = *(int *)(param_2 + 8) + 1;
    *(void **)(param_2 + 0x14) = param_1;
  }
  else {
    if (*(int *)((int)param_1 + 8) == *(int *)(param_2 + 8)) {
      *(int *)((int)param_1 + 8) = *(int *)(param_2 + 4) + -1;
      *(undefined4 *)(param_2 + 0x14) = *(undefined4 *)((int)param_1 + 0x14);
    }
    else {
      pvVar2 = (void *)_kalloc(0x1c);
      _bcopy(param_1,pvVar2,0x1c);
      piVar1 = (int *)(*(int *)((int)pvVar2 + 0x10) + 8);
      *piVar1 = *piVar1 + 1;
      *(int *)((int)pvVar2 + 4) = *(int *)(param_2 + 8) + 1;
      *(undefined4 *)((int)pvVar2 + 0x18) = 0;
      *(int *)((int)param_1 + 8) = *(int *)(param_2 + 4) + -1;
      *(undefined4 *)((int)pvVar2 + 0x14) = *(undefined4 *)((int)param_1 + 0x14);
      *(void **)(param_2 + 0x14) = pvVar2;
    }
    *(int *)((int)param_1 + 0x14) = param_2;
  }
  return;
}

