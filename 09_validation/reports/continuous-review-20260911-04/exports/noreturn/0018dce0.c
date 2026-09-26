
void _thread_bootstrap_return(void)

{
  int *piVar1;
  size_t sVar2;
  void *pvVar3;
  int *piVar4;
  undefined4 uVar5;
  undefined *puVar6;
  int iVar7;
  undefined4 *puVar8;
  int iVar9;
  uint uVar10;
  int iVar11;
  int iVar12;
  undefined4 *puVar13;
  undefined4 *puVar14;
  
  iVar7 = _active_threads;
  piVar1 = *(int **)(*(int *)(_active_threads + 0xc) + 0x40);
  iVar12 = *(int *)(_active_threads + 0x28);
  _lock_read(piVar1 + 4);
  sVar2 = piVar1[3];
  if (sVar2 != 0) {
    pvVar3 = (void *)piVar1[2];
    piVar4 = *(int **)(iVar7 + 0x28);
    uVar10 = sVar2 + 0x69;
    if ((uint)piVar4[1] < uVar10) {
      puVar8 = (undefined4 *)_kalloc(uVar10);
      puVar13 = (undefined4 *)*piVar4;
      puVar14 = puVar8;
      for (iVar9 = 0x1a; iVar9 != 0; iVar9 = iVar9 + -1) {
        *puVar14 = *puVar13;
        puVar13 = puVar13 + 1;
        puVar14 = puVar14 + 1;
      }
      if ((*(byte *)(piVar4 + 0x3c) & 4) == 0) {
        piVar4[2] = (int)puVar8;
        piVar4[3] = uVar10;
        *piVar4 = (int)puVar8;
        piVar4[1] = uVar10;
        *(byte *)(piVar4 + 0x3c) = *(byte *)(piVar4 + 0x3c) | 4;
      }
      else {
        iVar9 = piVar4[2];
        iVar11 = piVar4[3];
        piVar4[2] = (int)puVar8;
        piVar4[3] = uVar10;
        *piVar4 = (int)puVar8;
        piVar4[1] = uVar10;
        *(byte *)(piVar4 + 0x3c) = *(byte *)(piVar4 + 0x3c) | 4;
        _kfree(iVar9,iVar11);
      }
      puVar6 = _gdt;
      if (_active_threads == iVar7) {
        iVar9 = **(int **)(iVar7 + 0x28) + -0x40000000;
        iVar11 = (*(int **)(iVar7 + 0x28))[1] + -1;
        *(short *)(_gdt + 0x1a) = (short)iVar9;
        puVar6[0x1c] = (char)((uint)iVar9 >> 0x10);
        puVar6[0x1f] = (char)((uint)iVar9 >> 0x18);
        puVar6[0x1d] = 0x89;
        puVar6[0x1e] = puVar6[0x1e] & 0x7f;
        *(short *)(puVar6 + 0x18) = (short)iVar11;
        puVar6[0x1e] = puVar6[0x1e] & 0xf0 | (byte)((uint)iVar11 >> 0x10) & 0xf;
        TaskRegister(0x18);
      }
    }
    _memcpy((void *)(*piVar4 + (uint)*(ushort *)(*piVar4 + 0x66)),pvVar3,sVar2);
  }
  if (*(int *)(iVar12 + 0x74) != *piVar1) {
    iVar12 = piVar1[1];
    *(int *)(*(int *)(iVar7 + 0x28) + 0x74) = *piVar1;
    *(int *)(*(int *)(iVar7 + 0x28) + 0x78) = iVar12;
    puVar6 = _gdt;
    if (_active_threads == iVar7) {
      uVar5 = *(undefined4 *)(*(int *)(iVar7 + 0x28) + 0x74);
      iVar12 = *(int *)(*(int *)(iVar7 + 0x28) + 0x78) + -1;
      *(short *)(_gdt + 0x22) = (short)uVar5;
      puVar6[0x24] = (char)((uint)uVar5 >> 0x10);
      puVar6[0x27] = (char)((uint)uVar5 >> 0x18);
      puVar6[0x25] = puVar6[0x25] & 0xe0 | 0x82;
      puVar6[0x26] = puVar6[0x26] & 0x7f;
      *(short *)(puVar6 + 0x20) = (short)iVar12;
      puVar6[0x26] = puVar6[0x26] & 0xf0 | (byte)((uint)iVar12 >> 0x10) & 0xf;
      LocalDescriptorTableRegister(0x20);
    }
  }
  _lock_done(piVar1 + 4);
                    /* WARNING: Subroutine does not return */
  _thread_exception_return();
}

