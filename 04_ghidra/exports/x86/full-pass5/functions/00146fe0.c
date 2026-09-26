/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00146fe0 */

void _ipc_kmsg_destroy(int *param_1)

{
  int *piVar1;
  int iVar2;
  undefined4 *puVar3;
  int *piVar4;
  int *piVar5;
  int *piVar6;
  
  piVar1 = (int *)(_active_threads + 0xa4);
  iVar2 = *(int *)(_active_threads + 0xa4);
  if (iVar2 == 0) {
    *(int **)(_active_threads + 0xa4) = param_1;
    *param_1 = (int)param_1;
    param_1[1] = (int)param_1;
    while (piVar6 = (int *)*piVar1, piVar6 != (int *)0x0) {
      _ipc_kmsg_clean(piVar6);
      piVar4 = (int *)*piVar6;
      piVar5 = (int *)piVar6[1];
      if (piVar4 == piVar6) {
        *piVar1 = 0;
      }
      else {
        if ((int *)*piVar1 == piVar6) {
          *piVar1 = (int)piVar4;
        }
        piVar4[1] = (int)piVar5;
        *piVar5 = (int)piVar4;
      }
      if (piVar6[2] < 1) {
        _ipc_kmsg_free(piVar6);
      }
      else {
        _kfree(piVar6,piVar6[2]);
      }
    }
  }
  else {
    puVar3 = *(undefined4 **)(iVar2 + 4);
    *param_1 = iVar2;
    param_1[1] = (int)puVar3;
    *(int **)(iVar2 + 4) = param_1;
    *puVar3 = param_1;
  }
  return;
}

