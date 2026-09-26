/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0018d610 */

void FUN_0018d610(int *param_1)

{
  int iVar1;
  void *pvVar2;
  size_t sVar3;
  undefined *puVar4;
  undefined4 *puVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  int *piVar9;
  undefined4 *puVar10;
  int *piVar11;
  undefined4 *puVar12;
  
  iVar1 = param_1[0x10];
  do {
    do {
    } while (*param_1 != 0);
    LOCK();
    iVar6 = *param_1;
    *param_1 = 1;
    UNLOCK();
  } while (iVar6 == 1);
  piVar9 = (int *)0x0;
  for (piVar11 = (int *)param_1[7]; param_1 + 7 != piVar11; piVar11 = (int *)piVar11[4]) {
    _thread_reference(piVar11);
    LOCK();
    *param_1 = 0;
    UNLOCK();
    if (piVar9 != (int *)0x0) {
      _thread_deallocate(piVar9);
    }
    pvVar2 = *(void **)(iVar1 + 8);
    sVar3 = *(size_t *)(iVar1 + 0xc);
    piVar9 = (int *)piVar11[10];
    uVar7 = sVar3 + 0x69;
    if ((uint)piVar9[1] < uVar7) {
      puVar5 = (undefined4 *)_kalloc(uVar7);
      puVar10 = (undefined4 *)*piVar9;
      puVar12 = puVar5;
      for (iVar6 = 0x1a; iVar6 != 0; iVar6 = iVar6 + -1) {
        *puVar12 = *puVar10;
        puVar10 = puVar10 + 1;
        puVar12 = puVar12 + 1;
      }
      if ((*(byte *)(piVar9 + 0x3c) & 4) == 0) {
        piVar9[2] = (int)puVar5;
        piVar9[3] = uVar7;
        *piVar9 = (int)puVar5;
        piVar9[1] = uVar7;
        *(byte *)(piVar9 + 0x3c) = *(byte *)(piVar9 + 0x3c) | 4;
      }
      else {
        iVar6 = piVar9[2];
        iVar8 = piVar9[3];
        piVar9[2] = (int)puVar5;
        piVar9[3] = uVar7;
        *piVar9 = (int)puVar5;
        piVar9[1] = uVar7;
        *(byte *)(piVar9 + 0x3c) = *(byte *)(piVar9 + 0x3c) | 4;
        _kfree(iVar6,iVar8);
      }
      puVar4 = _gdt;
      if (_active_threads == piVar11) {
        iVar6 = *(int *)piVar11[10] + -0x40000000;
        iVar8 = ((int *)piVar11[10])[1] + -1;
        *(short *)(_gdt + 0x1a) = (short)iVar6;
        puVar4[0x1c] = (char)((uint)iVar6 >> 0x10);
        puVar4[0x1f] = (char)((uint)iVar6 >> 0x18);
        puVar4[0x1d] = 0x89;
        puVar4[0x1e] = puVar4[0x1e] & 0x7f;
        *(short *)(puVar4 + 0x18) = (short)iVar8;
        puVar4[0x1e] = puVar4[0x1e] & 0xf0 | (byte)((uint)iVar8 >> 0x10) & 0xf;
        TaskRegister(0x18);
      }
    }
    _memcpy((void *)(*piVar9 + (uint)*(ushort *)(*piVar9 + 0x66)),pvVar2,sVar3);
    do {
      do {
      } while (*param_1 != 0);
      LOCK();
      iVar6 = *param_1;
      *param_1 = 1;
      UNLOCK();
    } while (iVar6 == 1);
    piVar9 = piVar11;
  }
  LOCK();
  *param_1 = 0;
  UNLOCK();
  if (piVar9 != (int *)0x0) {
    _thread_deallocate(piVar9);
  }
  return;
}

