/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0017544f */

/* Synthetic analysis entry; not a reconstructed ABI function. Role=noreturn_fallthrough_fragment.
   Context recorded in gap-actions.json. */

undefined4 __analysis_fragment_0017544f(void)

{
  uint uVar1;
  int iVar2;
  undefined4 *puVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  int *piVar7;
  undefined4 *puVar8;
  int *unaff_EBX;
  undefined4 *puVar9;
  int unaff_EBP;
  int *piVar10;
  int *piVar11;
  
  *(undefined4 *)(unaff_EBP + -0x1c) = *(undefined4 *)(unaff_EBP + -0x10);
  piVar7 = *(int **)(unaff_EBP + -0x1c);
  piVar10 = unaff_EBX;
  piVar11 = piVar7;
  for (iVar6 = 0xb; iVar6 != 0; iVar6 = iVar6 + -1) {
    *piVar11 = *piVar10;
    piVar10 = piVar10 + 1;
    piVar11 = piVar11 + 1;
  }
  iVar6 = *(int *)(unaff_EBP + 0xc);
  piVar7[3] = iVar6;
  unaff_EBX[5] = unaff_EBX[5] + (*(int *)(unaff_EBP + 0xc) - unaff_EBX[2]);
  unaff_EBX[2] = iVar6;
  piVar7 = (int *)(*(int *)(unaff_EBP + -0xc) + 0x10);
  *piVar7 = *piVar7 + 1;
  piVar7 = *(int **)(unaff_EBP + -0x1c);
  *piVar7 = *unaff_EBX;
  piVar7[1] = *(int *)(*unaff_EBX + 4);
  iVar6 = *piVar7;
  *(int **)piVar7[1] = piVar7;
  *(int **)(iVar6 + 4) = piVar7;
  if ((*(byte *)(unaff_EBX + 6) & 5) == 0) {
    _vm_object_reference();
  }
  else {
    iVar6 = piVar7[4];
    if (iVar6 != 0) {
      piVar7 = (int *)(iVar6 + 0x34);
      do {
        do {
        } while (*piVar7 != 0);
        LOCK();
        iVar2 = *piVar7;
        *piVar7 = 1;
        UNLOCK();
      } while (iVar2 == 1);
      *(int *)(iVar6 + 0x30) = *(int *)(iVar6 + 0x30) + 1;
      LOCK();
      *(undefined4 *)(iVar6 + 0x34) = 0;
      UNLOCK();
    }
  }
  for (iVar6 = *(int *)(unaff_EBP + -4);
      (iVar6 != *(int *)(unaff_EBP + 8) + 0xc &&
      (*(uint *)(iVar6 + 8) < *(uint *)(unaff_EBP + 0x10))); iVar6 = *(int *)(iVar6 + 4)) {
    if ((*(byte *)(iVar6 + 0x18) & 4) != 0) {
      _lock_done();
      return 4;
    }
    if (*(uint *)(unaff_EBP + 0x14) != (*(uint *)(unaff_EBP + 0x14) & *(uint *)(iVar6 + 0x20))) {
      _lock_done();
      return 2;
    }
  }
  puVar9 = *(undefined4 **)(unaff_EBP + -4);
  do {
    if ((puVar9 == (undefined4 *)(*(int *)(unaff_EBP + 8) + 0xc)) ||
       (*(uint *)(unaff_EBP + 0x10) <= (uint)puVar9[2])) {
      _lock_done();
      return 0;
    }
    if (*(uint *)(unaff_EBP + 0x10) < (uint)puVar9[3]) {
      *(int *)(unaff_EBP + -0x18) = *(int *)(unaff_EBP + 8) + 0xc;
      iVar2 = _zalloc();
      *(int *)(unaff_EBP + -0x14) = iVar2;
      iVar6 = *(int *)(unaff_EBP + -0x18);
      if (iVar2 == 0) {
        *(int *)(unaff_EBP + -0x18) = iVar6;
                    /* WARNING: Subroutine does not return */
        _panic(s_vm_map_entry_create_001e0ab0);
      }
      *(undefined4 *)(unaff_EBP + -0x1c) = *(undefined4 *)(unaff_EBP + -0x14);
      *(undefined4 **)(unaff_EBP + -0x20) = puVar9;
      puVar3 = puVar9;
      puVar8 = *(undefined4 **)(unaff_EBP + -0x1c);
      for (iVar2 = 0xb; iVar2 != 0; iVar2 = iVar2 + -1) {
        *puVar8 = *puVar3;
        puVar3 = puVar3 + 1;
        puVar8 = puVar8 + 1;
      }
      iVar2 = *(int *)(unaff_EBP + 0x10);
      puVar9[3] = iVar2;
      piVar10 = *(int **)(unaff_EBP + -0x1c);
      piVar10[2] = iVar2;
      piVar10[5] = piVar10[5] + (*(int *)(unaff_EBP + 0x10) - puVar9[2]);
      piVar7 = (int *)(iVar6 + 0x10);
      *piVar7 = *piVar7 + 1;
      *piVar10 = (int)puVar9;
      piVar10[1] = puVar9[1];
      iVar6 = *piVar10;
      *(int **)piVar10[1] = piVar10;
      *(int **)(iVar6 + 4) = piVar10;
      if ((*(byte *)(puVar9 + 6) & 5) == 0) {
        _vm_object_reference();
      }
      else {
        iVar6 = piVar10[4];
        if (iVar6 != 0) {
          piVar7 = (int *)(iVar6 + 0x34);
          do {
            do {
            } while (*piVar7 != 0);
            LOCK();
            iVar2 = *piVar7;
            *piVar7 = 1;
            UNLOCK();
          } while (iVar2 == 1);
          *(int *)(iVar6 + 0x30) = *(int *)(iVar6 + 0x30) + 1;
          LOCK();
          *(undefined4 *)(iVar6 + 0x34) = 0;
          UNLOCK();
        }
      }
    }
    uVar4 = puVar9[7];
    if (*(int *)(unaff_EBP + 0x18) == 0) {
      puVar9[7] = *(undefined4 *)(unaff_EBP + 0x14);
    }
    else {
      uVar1 = *(uint *)(unaff_EBP + 0x14);
      puVar9[8] = uVar1;
      puVar9[7] = uVar1 & uVar4;
    }
    if (puVar9[7] != uVar4) {
      if ((*(byte *)(puVar9 + 6) & 1) == 0) {
        _pmap_protect(*(undefined4 *)(*(int *)(unaff_EBP + 8) + 0x24),puVar9[2],puVar9[3]);
      }
      else {
        _lock_write();
        *(int *)(puVar9[4] + 0x4c) = *(int *)(puVar9[4] + 0x4c) + 1;
        iVar6 = puVar9[4];
        *(int *)(unaff_EBP + -0x20) = iVar6;
        uVar4 = puVar9[5];
        piVar7 = (int *)(iVar6 + 0x3c);
        do {
          do {
          } while (*piVar7 != 0);
          LOCK();
          iVar6 = *piVar7;
          *piVar7 = 1;
          UNLOCK();
        } while (iVar6 == 1);
        iVar6 = *(int *)(unaff_EBP + -0x20);
        puVar8 = *(undefined4 **)(iVar6 + 0x38);
        LOCK();
        *(undefined4 *)(iVar6 + 0x3c) = 0;
        UNLOCK();
        puVar3 = (undefined4 *)(iVar6 + 0xc);
        if (puVar8 == puVar3) {
          puVar8 = *(undefined4 **)(iVar6 + 0x10);
        }
        if (uVar4 < (uint)puVar8[2]) {
          puVar3 = (undefined4 *)puVar8[1];
          puVar8 = *(undefined4 **)(*(int *)(unaff_EBP + -0x20) + 0x10);
LAB_001756ff:
          if (puVar8 != puVar3) {
            if ((uint)puVar8[3] <= uVar4) break;
            if ((uint)puVar8[2] <= uVar4) {
              *(undefined4 **)(unaff_EBP + -8) = puVar8;
              piVar7 = (int *)(*(int *)(unaff_EBP + -0x20) + 0x3c);
              do {
                do {
                } while (*piVar7 != 0);
                LOCK();
                iVar6 = *piVar7;
                *piVar7 = 1;
                UNLOCK();
              } while (iVar6 == 1);
              iVar6 = *(int *)(unaff_EBP + -0x20);
              *(undefined4 **)(iVar6 + 0x38) = puVar8;
              LOCK();
              *(undefined4 *)(iVar6 + 0x3c) = 0;
              UNLOCK();
              goto LAB_00175732;
            }
          }
          goto LAB_00175703;
        }
        if (puVar8 == puVar3) {
LAB_00175703:
          *(undefined4 *)(unaff_EBP + -8) = *puVar8;
          piVar7 = (int *)(*(int *)(unaff_EBP + -0x20) + 0x3c);
          do {
            do {
            } while (*piVar7 != 0);
            LOCK();
            iVar6 = *piVar7;
            *piVar7 = 1;
            UNLOCK();
          } while (iVar6 == 1);
          iVar6 = *(int *)(unaff_EBP + -0x20);
          *(undefined4 *)(iVar6 + 0x38) = *(undefined4 *)(unaff_EBP + -8);
          LOCK();
          *(undefined4 *)(iVar6 + 0x3c) = 0;
          UNLOCK();
        }
        else {
          if ((uint)puVar8[3] <= uVar4) goto LAB_001756ff;
          *(undefined4 **)(unaff_EBP + -8) = puVar8;
        }
LAB_00175732:
        *(undefined4 *)(unaff_EBP + -0x1c) = (puVar9[3] - puVar9[2]) + puVar9[5];
        while ((*(int *)(unaff_EBP + -8) != puVar9[4] + 0xc &&
               (*(uint *)(*(int *)(unaff_EBP + -8) + 8) < *(uint *)(unaff_EBP + -0x1c)))) {
          *(int *)(unaff_EBP + -0x20) = *(int *)(unaff_EBP + -8);
          uVar4 = *(uint *)(*(int *)(unaff_EBP + -8) + 0xc);
          if (uVar4 < *(uint *)(unaff_EBP + -0x1c)) {
            uVar4 = *(uint *)(unaff_EBP + -0x1c);
          }
          uVar1 = puVar9[5];
          uVar5 = *(uint *)(*(int *)(unaff_EBP + -0x20) + 8);
          if (uVar5 < uVar1) {
            uVar5 = uVar1;
          }
          _pmap_protect(*(undefined4 *)(*(int *)(unaff_EBP + 8) + 0x24),(uVar5 - uVar1) + puVar9[2],
                        (uVar4 - uVar1) + puVar9[2]);
          *(undefined4 *)(unaff_EBP + -8) = *(undefined4 *)(*(int *)(unaff_EBP + -8) + 4);
        }
        _lock_done();
      }
    }
    puVar9 = (undefined4 *)puVar9[1];
  } while( true );
  puVar8 = (undefined4 *)puVar8[1];
  goto LAB_001756ff;
}

