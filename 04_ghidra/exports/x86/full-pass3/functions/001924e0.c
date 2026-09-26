/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001924e0 */

void FUN_001924e0(undefined2 *param_1)

{
  undefined2 *puVar1;
  int iVar2;
  undefined2 *puVar3;
  
  iVar2 = *(int *)(*(int *)(_active_threads + 0x28) + 0x70);
  if (iVar2 == 0) {
    puVar3 = (undefined2 *)_thread_user_state(_active_threads);
  }
  else {
    puVar3 = (undefined2 *)(iVar2 + 0x84);
  }
  puVar1 = param_1 + 0x22;
  *(undefined4 *)(puVar3 + 0x1a) = *(undefined4 *)(param_1 + 0x1a);
  if (puVar3 + 6 < puVar1) {
    *(undefined4 *)(puVar3 + 0x16) = *(undefined4 *)(param_1 + 0x16);
    *(undefined4 *)(puVar3 + 0x14) = *(undefined4 *)(param_1 + 0x14);
    *(undefined4 *)(puVar3 + 0x12) = *(undefined4 *)(param_1 + 0x12);
    *(undefined4 *)(puVar3 + 0x10) = *(undefined4 *)(param_1 + 0x10);
    *(undefined4 *)(puVar3 + 0xc) = *(undefined4 *)(param_1 + 0xc);
    *(undefined4 *)(puVar3 + 10) = *(undefined4 *)(param_1 + 10);
    *(undefined4 *)(puVar3 + 8) = *(undefined4 *)(param_1 + 8);
    puVar3[6] = param_1[6];
    puVar3[4] = param_1[4];
    puVar3[2] = param_1[2];
  }
  else if (puVar3 + 4 < puVar1) {
    puVar3[4] = param_1[4];
    puVar3[2] = param_1[2];
  }
  else if (puVar3 + 2 < puVar1) {
    puVar3[2] = param_1[2];
  }
  else if (puVar1 <= puVar3) {
    return;
  }
  *puVar3 = *param_1;
  return;
}

