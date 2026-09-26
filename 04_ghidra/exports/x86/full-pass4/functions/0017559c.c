/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0017559c */

/* Synthetic analysis entry; not a reconstructed ABI function. Role=noreturn_fallthrough_fragment.
   Context recorded in gap-actions.json. */

undefined4 __analysis_fragment_0017559c(void)

{
  uint uVar1;
  undefined4 *puVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  int *piVar7;
  undefined4 *puVar8;
  undefined4 *unaff_EBX;
  int unaff_EBP;
  
  iVar6 = *(int *)(unaff_EBP + -0x18);
  do {
    *(undefined4 *)(unaff_EBP + -0x1c) = *(undefined4 *)(unaff_EBP + -0x14);
    *(undefined4 **)(unaff_EBP + -0x20) = unaff_EBX;
    puVar2 = unaff_EBX;
    puVar8 = *(undefined4 **)(unaff_EBP + -0x1c);
    for (iVar5 = 0xb; iVar5 != 0; iVar5 = iVar5 + -1) {
      *puVar8 = *puVar2;
      puVar2 = puVar2 + 1;
      puVar8 = puVar8 + 1;
    }
    iVar5 = *(int *)(unaff_EBP + 0x10);
    unaff_EBX[3] = iVar5;
    piVar7 = *(int **)(unaff_EBP + -0x1c);
    piVar7[2] = iVar5;
    piVar7[5] = piVar7[5] + (*(int *)(unaff_EBP + 0x10) - unaff_EBX[2]);
    *(int *)(iVar6 + 0x10) = *(int *)(iVar6 + 0x10) + 1;
    *piVar7 = (int)unaff_EBX;
    piVar7[1] = unaff_EBX[1];
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
          iVar5 = *piVar7;
          *piVar7 = 1;
          UNLOCK();
        } while (iVar5 == 1);
        *(int *)(iVar6 + 0x30) = *(int *)(iVar6 + 0x30) + 1;
        LOCK();
        *(undefined4 *)(iVar6 + 0x34) = 0;
        UNLOCK();
      }
    }
    do {
      uVar3 = unaff_EBX[7];
      if (*(int *)(unaff_EBP + 0x18) == 0) {
        unaff_EBX[7] = *(undefined4 *)(unaff_EBP + 0x14);
      }
      else {
        uVar1 = *(uint *)(unaff_EBP + 0x14);
        unaff_EBX[8] = uVar1;
        unaff_EBX[7] = uVar1 & uVar3;
      }
      if (unaff_EBX[7] != uVar3) {
        if ((*(byte *)(unaff_EBX + 6) & 1) == 0) {
          _pmap_protect(*(undefined4 *)(*(int *)(unaff_EBP + 8) + 0x24),unaff_EBX[2],unaff_EBX[3]);
        }
        else {
          _lock_write();
          *(int *)(unaff_EBX[4] + 0x4c) = *(int *)(unaff_EBX[4] + 0x4c) + 1;
          iVar6 = unaff_EBX[4];
          *(int *)(unaff_EBP + -0x20) = iVar6;
          uVar3 = unaff_EBX[5];
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
          puVar2 = (undefined4 *)(iVar6 + 0xc);
          if (puVar8 == puVar2) {
            puVar8 = *(undefined4 **)(iVar6 + 0x10);
          }
          if (uVar3 < (uint)puVar8[2]) {
            puVar2 = (undefined4 *)puVar8[1];
            puVar8 = *(undefined4 **)(*(int *)(unaff_EBP + -0x20) + 0x10);
LAB_001756ff:
            if (puVar8 != puVar2) {
              if ((uint)puVar8[3] <= uVar3) goto LAB_001756fc;
              if ((uint)puVar8[2] <= uVar3) {
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
          if (puVar8 == puVar2) {
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
            if ((uint)puVar8[3] <= uVar3) goto LAB_001756ff;
            *(undefined4 **)(unaff_EBP + -8) = puVar8;
          }
LAB_00175732:
          *(undefined4 *)(unaff_EBP + -0x1c) = (unaff_EBX[3] - unaff_EBX[2]) + unaff_EBX[5];
          while ((*(int *)(unaff_EBP + -8) != unaff_EBX[4] + 0xc &&
                 (*(uint *)(*(int *)(unaff_EBP + -8) + 8) < *(uint *)(unaff_EBP + -0x1c)))) {
            *(int *)(unaff_EBP + -0x20) = *(int *)(unaff_EBP + -8);
            uVar3 = *(uint *)(*(int *)(unaff_EBP + -8) + 0xc);
            if (uVar3 < *(uint *)(unaff_EBP + -0x1c)) {
              uVar3 = *(uint *)(unaff_EBP + -0x1c);
            }
            uVar1 = unaff_EBX[5];
            uVar4 = *(uint *)(*(int *)(unaff_EBP + -0x20) + 8);
            if (uVar4 < uVar1) {
              uVar4 = uVar1;
            }
            _pmap_protect(*(undefined4 *)(*(int *)(unaff_EBP + 8) + 0x24),
                          (uVar4 - uVar1) + unaff_EBX[2],(uVar3 - uVar1) + unaff_EBX[2]);
            *(undefined4 *)(unaff_EBP + -8) = *(undefined4 *)(*(int *)(unaff_EBP + -8) + 4);
          }
          _lock_done();
        }
      }
      unaff_EBX = (undefined4 *)unaff_EBX[1];
      if ((unaff_EBX == (undefined4 *)(*(int *)(unaff_EBP + 8) + 0xc)) ||
         (*(uint *)(unaff_EBP + 0x10) <= (uint)unaff_EBX[2])) {
        _lock_done();
        return 0;
      }
    } while ((uint)unaff_EBX[3] <= *(uint *)(unaff_EBP + 0x10));
    *(int *)(unaff_EBP + -0x18) = *(int *)(unaff_EBP + 8) + 0xc;
    iVar5 = _zalloc();
    *(int *)(unaff_EBP + -0x14) = iVar5;
    iVar6 = *(int *)(unaff_EBP + -0x18);
    if (iVar5 == 0) {
      *(int *)(unaff_EBP + -0x18) = iVar6;
                    /* WARNING: Subroutine does not return */
      _panic(s_vm_map_entry_create_001e0ab0);
    }
  } while( true );
LAB_001756fc:
  puVar8 = (undefined4 *)puVar8[1];
  goto LAB_001756ff;
}

