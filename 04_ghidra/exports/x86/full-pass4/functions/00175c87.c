/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00175c87 */

/* Synthetic analysis entry; not a reconstructed ABI function. Role=noreturn_fallthrough_fragment.
   Context recorded in gap-actions.json. */

undefined4 __analysis_fragment_00175c87(void)

{
  short sVar1;
  int *piVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  int *unaff_EBX;
  undefined4 *puVar6;
  int unaff_EBP;
  int *piVar7;
  undefined4 *puVar8;
  int *piVar9;
  undefined4 *puVar10;
  
  *(undefined4 *)(unaff_EBP + -0x20) = *(undefined4 *)(unaff_EBP + -0x10);
  piVar2 = *(int **)(unaff_EBP + -0x20);
  piVar7 = unaff_EBX;
  piVar9 = piVar2;
  for (iVar5 = 0xb; iVar5 != 0; iVar5 = iVar5 + -1) {
    *piVar9 = *piVar7;
    piVar7 = piVar7 + 1;
    piVar9 = piVar9 + 1;
  }
  iVar5 = *(int *)(unaff_EBP + 0xc);
  piVar2[3] = iVar5;
  unaff_EBX[5] = unaff_EBX[5] + (*(int *)(unaff_EBP + 0xc) - unaff_EBX[2]);
  unaff_EBX[2] = iVar5;
  piVar2 = (int *)(*(int *)(unaff_EBP + -0xc) + 0x10);
  *piVar2 = *piVar2 + 1;
  piVar2 = *(int **)(unaff_EBP + -0x20);
  *piVar2 = *unaff_EBX;
  piVar2[1] = *(int *)(*unaff_EBX + 4);
  iVar5 = *piVar2;
  *(int **)piVar2[1] = piVar2;
  *(int **)(iVar5 + 4) = piVar2;
  if ((*(byte *)(unaff_EBX + 6) & 5) == 0) {
    _vm_object_reference();
  }
  else {
    iVar5 = piVar2[4];
    if (iVar5 != 0) {
      piVar2 = (int *)(iVar5 + 0x34);
      do {
        do {
        } while (*piVar2 != 0);
        LOCK();
        iVar3 = *piVar2;
        *piVar2 = 1;
        UNLOCK();
      } while (iVar3 == 1);
      *(int *)(iVar5 + 0x30) = *(int *)(iVar5 + 0x30) + 1;
      LOCK();
      *(undefined4 *)(iVar5 + 0x34) = 0;
      UNLOCK();
    }
  }
  *(int **)(unaff_EBP + -4) = unaff_EBX;
  if (*(int *)(unaff_EBP + 0x14) == 0) {
    for (puVar6 = *(undefined4 **)(unaff_EBP + -4);
        (puVar6 != (undefined4 *)(*(int *)(unaff_EBP + 8) + 0xc) &&
        ((uint)puVar6[2] < *(uint *)(unaff_EBP + 0x10))); puVar6 = (undefined4 *)puVar6[1]) {
      if (*(uint *)(unaff_EBP + 0x10) < (uint)puVar6[3]) {
        *(int *)(unaff_EBP + -0x1c) = *(int *)(unaff_EBP + 8) + 0xc;
        iVar3 = _zalloc();
        *(int *)(unaff_EBP + -0x18) = iVar3;
        iVar5 = *(int *)(unaff_EBP + -0x1c);
        if (iVar3 == 0) {
          *(int *)(unaff_EBP + -0x1c) = iVar5;
                    /* WARNING: Subroutine does not return */
          _panic(s_vm_map_entry_create_001e0ab0);
        }
        *(undefined4 *)(unaff_EBP + -0x20) = *(undefined4 *)(unaff_EBP + -0x18);
        *(undefined4 **)(unaff_EBP + -0x24) = puVar6;
        puVar8 = puVar6;
        puVar10 = *(undefined4 **)(unaff_EBP + -0x20);
        for (iVar3 = 0xb; iVar3 != 0; iVar3 = iVar3 + -1) {
          *puVar10 = *puVar8;
          puVar8 = puVar8 + 1;
          puVar10 = puVar10 + 1;
        }
        iVar3 = *(int *)(unaff_EBP + 0x10);
        puVar6[3] = iVar3;
        piVar7 = *(int **)(unaff_EBP + -0x20);
        piVar7[2] = iVar3;
        piVar7[5] = piVar7[5] + (*(int *)(unaff_EBP + 0x10) - puVar6[2]);
        piVar2 = (int *)(iVar5 + 0x10);
        *piVar2 = *piVar2 + 1;
        *piVar7 = (int)puVar6;
        piVar7[1] = puVar6[1];
        iVar5 = *piVar7;
        *(int **)piVar7[1] = piVar7;
        *(int **)(iVar5 + 4) = piVar7;
        if ((*(byte *)(puVar6 + 6) & 5) == 0) {
          _vm_object_reference();
        }
        else {
          iVar5 = piVar7[4];
          if (iVar5 != 0) {
            piVar2 = (int *)(iVar5 + 0x34);
            do {
              do {
              } while (*piVar2 != 0);
              LOCK();
              iVar3 = *piVar2;
              *piVar2 = 1;
              UNLOCK();
            } while (iVar3 == 1);
            *(int *)(iVar5 + 0x30) = *(int *)(iVar5 + 0x30) + 1;
            LOCK();
            *(undefined4 *)(iVar5 + 0x34) = 0;
            UNLOCK();
          }
        }
      }
      sVar1 = *(short *)(puVar6 + 10);
      *(short *)(puVar6 + 10) = sVar1 + 1;
      if ((sVar1 == 0) && ((*(byte *)(puVar6 + 6) & 1) == 0)) {
        if (((*(byte *)(puVar6 + 6) & 0x40) == 0) || ((*(byte *)(puVar6 + 7) & 2) == 0)) {
          if (puVar6[4] == 0) {
            uVar4 = _vm_object_allocate();
            puVar6[4] = uVar4;
            puVar6[5] = 0;
          }
        }
        else {
          _vm_object_shadow(puVar6 + 4,puVar6 + 5);
          *(byte *)(puVar6 + 6) = *(byte *)(puVar6 + 6) & 0xbf;
        }
      }
    }
    if (_kernel_map == *(int *)(unaff_EBP + 8)) {
      *(undefined4 *)(unaff_EBP + -8) = 0;
      _lock_done();
    }
    else {
      uVar4 = *(undefined4 *)(unaff_EBP + 8);
      _lock_set_recursive();
      _lock_write_to_read(uVar4);
    }
    iVar5 = *(int *)(unaff_EBP + -4);
    iVar3 = *(int *)(unaff_EBP + 8) + 0xc;
    if (iVar5 != iVar3) {
      *(int *)(unaff_EBP + -0x24) = iVar3;
      do {
        if (*(uint *)(unaff_EBP + 0x10) <= *(uint *)(iVar5 + 8)) break;
        if (*(short *)(iVar5 + 0x28) == 1) {
          _vm_fault_wire(*(undefined4 *)(unaff_EBP + 8));
        }
        iVar5 = *(int *)(iVar5 + 4);
      } while (*(int *)(unaff_EBP + -0x24) != iVar5);
    }
    if (*(int *)(unaff_EBP + -8) == 0) {
      return 0;
    }
    _lock_clear_recursive();
  }
  else {
    for (; (unaff_EBX != (int *)(*(int *)(unaff_EBP + 8) + 0xc) &&
           ((uint)unaff_EBX[2] < *(uint *)(unaff_EBP + 0x10))); unaff_EBX = (int *)unaff_EBX[1]) {
      if ((short)unaff_EBX[10] == 0) {
        _lock_done();
        return 4;
      }
    }
    for (puVar6 = *(undefined4 **)(unaff_EBP + -4);
        (puVar6 != (undefined4 *)(*(int *)(unaff_EBP + 8) + 0xc) &&
        ((uint)puVar6[2] < *(uint *)(unaff_EBP + 0x10))); puVar6 = (undefined4 *)puVar6[1]) {
      if (*(uint *)(unaff_EBP + 0x10) < (uint)puVar6[3]) {
        *(int *)(unaff_EBP + -0x1c) = *(int *)(unaff_EBP + 8) + 0xc;
        iVar3 = _zalloc();
        *(int *)(unaff_EBP + -0x14) = iVar3;
        iVar5 = *(int *)(unaff_EBP + -0x1c);
        if (iVar3 == 0) {
          *(int *)(unaff_EBP + -0x1c) = iVar5;
                    /* WARNING: Subroutine does not return */
          _panic(s_vm_map_entry_create_001e0ab0);
        }
        *(undefined4 *)(unaff_EBP + -0x20) = *(undefined4 *)(unaff_EBP + -0x14);
        *(undefined4 **)(unaff_EBP + -0x24) = puVar6;
        puVar8 = puVar6;
        puVar10 = *(undefined4 **)(unaff_EBP + -0x20);
        for (iVar3 = 0xb; iVar3 != 0; iVar3 = iVar3 + -1) {
          *puVar10 = *puVar8;
          puVar8 = puVar8 + 1;
          puVar10 = puVar10 + 1;
        }
        iVar3 = *(int *)(unaff_EBP + 0x10);
        puVar6[3] = iVar3;
        piVar7 = *(int **)(unaff_EBP + -0x20);
        piVar7[2] = iVar3;
        piVar7[5] = piVar7[5] + (*(int *)(unaff_EBP + 0x10) - puVar6[2]);
        piVar2 = (int *)(iVar5 + 0x10);
        *piVar2 = *piVar2 + 1;
        *piVar7 = (int)puVar6;
        piVar7[1] = puVar6[1];
        iVar5 = *piVar7;
        *(int **)piVar7[1] = piVar7;
        *(int **)(iVar5 + 4) = piVar7;
        if ((*(byte *)(puVar6 + 6) & 5) == 0) {
          _vm_object_reference();
        }
        else {
          iVar5 = piVar7[4];
          if (iVar5 != 0) {
            piVar2 = (int *)(iVar5 + 0x34);
            do {
              do {
              } while (*piVar2 != 0);
              LOCK();
              iVar3 = *piVar2;
              *piVar2 = 1;
              UNLOCK();
            } while (iVar3 == 1);
            *(int *)(iVar5 + 0x30) = *(int *)(iVar5 + 0x30) + 1;
            LOCK();
            *(undefined4 *)(iVar5 + 0x34) = 0;
            UNLOCK();
          }
        }
      }
      sVar1 = *(short *)(puVar6 + 10);
      *(short *)(puVar6 + 10) = sVar1 + -1;
      if (sVar1 == 1) {
        _vm_fault_unwire(*(undefined4 *)(unaff_EBP + 8));
      }
    }
  }
  if (*(int *)(unaff_EBP + -8) != 0) {
    _lock_done();
  }
  return 0;
}

