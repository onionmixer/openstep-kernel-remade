/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0017c2c4 */

void _fake_u(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int *piVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  iVar1 = *(int *)(*(int *)(param_2 + 0xc) + 0x38);
  iVar3 = *(int *)(param_2 + 0x84);
  _bcopy((void *)(iVar1 + 8),(void *)(param_1 + 8),0x11);
  _bcopy((void *)(iVar3 + 4),(void *)(param_1 + 0x1c),0x20);
  *(undefined4 *)(param_1 + 0x84) = *(undefined4 *)(iVar1 + 0x1c);
  _bcopy((void *)(iVar1 + 0x30),(void *)(param_1 + 0xa0),0x84);
  *(undefined4 *)(param_1 + 0x1b8) = *(undefined4 *)(iVar3 + 0x74);
  *(undefined4 *)(param_1 + 0x6d0) = *(undefined4 *)(iVar1 + 0x168);
  *(undefined2 *)(param_1 + 0x6d4) = *(undefined2 *)(iVar1 + 0x16c);
  puVar5 = (undefined4 *)(iVar1 + 0x170);
  puVar6 = (undefined4 *)(param_1 + 0x6d8);
  for (iVar3 = 0x12; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar6 = *puVar5;
    puVar5 = puVar5 + 1;
    puVar6 = puVar6 + 1;
  }
  uVar2 = _splsched();
  piVar4 = (int *)(param_2 + 0x20);
  do {
    do {
    } while (*piVar4 != 0);
    LOCK();
    iVar3 = *piVar4;
    *piVar4 = 1;
    UNLOCK();
  } while (iVar3 == 1);
  _thread_read_times(param_2,&local_c,&local_14);
  LOCK();
  *(undefined4 *)(param_2 + 0x20) = 0;
  UNLOCK();
  _splx(uVar2);
  *(undefined4 *)(param_1 + 0x6e0) = local_14;
  *(undefined4 *)(param_1 + 0x6e4) = local_10;
  *(undefined4 *)(param_1 + 0x6d8) = local_c;
  *(undefined4 *)(param_1 + 0x6dc) = local_8;
  puVar5 = (undefined4 *)(iVar1 + 0x1b8);
  puVar6 = (undefined4 *)(param_1 + 0x720);
  for (iVar3 = 0x12; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar6 = *puVar5;
    puVar5 = puVar5 + 1;
    puVar6 = puVar6 + 1;
  }
  return;
}

