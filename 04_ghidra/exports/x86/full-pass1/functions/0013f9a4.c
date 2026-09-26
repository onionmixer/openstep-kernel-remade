/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0013f9a4 */

/* WARNING: Removing unreachable block (ram,0x0013fb6c) */
/* WARNING: Removing unreachable block (ram,0x0013fb94) */
/* WARNING: Removing unreachable block (ram,0x0013fb74) */
/* WARNING: Removing unreachable block (ram,0x0013fb80) */
/* WARNING: Removing unreachable block (ram,0x0013fb7b) */
/* WARNING: Removing unreachable block (ram,0x0013fb83) */
/* WARNING: Removing unreachable block (ram,0x0013fa58) */
/* WARNING: Removing unreachable block (ram,0x0013fa80) */
/* WARNING: Removing unreachable block (ram,0x0013fa60) */
/* WARNING: Removing unreachable block (ram,0x0013fa6c) */
/* WARNING: Removing unreachable block (ram,0x0013fa67) */
/* WARNING: Removing unreachable block (ram,0x0013fa6f) */

void FUN_0013f9a4(int param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  int *piVar7;
  int *piVar8;
  int iVar9;
  int *local_1c;
  int *local_18;
  
  iVar1 = *(int *)(param_2 + 0x3c);
  uVar5 = _splbio();
  piVar8 = (int *)(param_1 + 0x24);
  do {
    do {
    } while (*piVar8 != 0);
    LOCK();
    iVar6 = *piVar8;
    *piVar8 = 1;
    UNLOCK();
  } while (iVar6 == 1);
  piVar8 = (int *)(param_1 + 0x10);
  local_1c = *(int **)(param_1 + 0x10);
  if (piVar8 == local_1c) {
    if (*(int *)(param_1 + 0x18) == 0) {
      piVar7 = (int *)0x0;
    }
    else {
      *(int *)(param_1 + 0x18) = *(int *)(param_1 + 0x18) + -1;
      piVar7 = (int *)_kalloc(0x18);
      piVar7[3] = 0;
      piVar7[1] = 0;
      *piVar7 = 0;
      piVar7[2] = 0;
    }
    piVar7[1] = param_2;
    *piVar7 = param_2;
    *(undefined4 *)(param_2 + 0xc) = 0;
    piVar2 = *(int **)(param_1 + 0x10);
    if (piVar8 == piVar2) {
      *(int **)(param_1 + 0x14) = piVar7;
    }
    else {
      piVar2[5] = (int)piVar7;
    }
    piVar7[4] = (int)piVar2;
    piVar7[5] = param_1 + 0x10;
    *(int **)(param_1 + 0x10) = piVar7;
    piVar7[3] = iVar1;
    piVar7[2] = *(int *)(param_1 + 0x1c);
    LOCK();
    *(undefined4 *)(param_1 + 0x24) = 0;
    UNLOCK();
    goto LAB_00140157;
  }
  if ((((*(byte *)(param_1 + 0xc) & 8) != 0) &&
      (local_1c[2] = *(int *)(*local_1c + 0x38), local_1c[3] < iVar1)) &&
     (0 < *(int *)(param_1 + 0x18))) {
    iVar6 = *local_1c;
    if (local_1c[1] == iVar6) {
      local_1c[3] = iVar1;
    }
    else {
      *local_1c = *(int *)(iVar6 + 0xc);
      if (*(int *)(param_1 + 0x18) == 0) {
        local_1c = (int *)0x0;
      }
      else {
        *(int *)(param_1 + 0x18) = *(int *)(param_1 + 0x18) + -1;
        local_1c = (int *)_kalloc(0x18);
        local_1c[3] = 0;
        local_1c[1] = 0;
        *local_1c = 0;
        local_1c[2] = 0;
      }
      local_1c[1] = iVar6;
      *local_1c = iVar6;
      *(undefined4 *)(iVar6 + 0xc) = 0;
      piVar7 = *(int **)(param_1 + 0x10);
      if (piVar8 == piVar7) {
        *(int **)(param_1 + 0x14) = local_1c;
      }
      else {
        piVar7[5] = (int)local_1c;
      }
      local_1c[4] = (int)piVar7;
      local_1c[5] = param_1 + 0x10;
      *(int **)(param_1 + 0x10) = local_1c;
      local_1c[3] = iVar1;
      local_1c[2] = *(int *)(iVar6 + 0x38);
    }
  }
  for (; (local_1c != (int *)(param_1 + 0x10) && (iVar1 < local_1c[3]));
      local_1c = (int *)local_1c[4]) {
  }
  if (local_1c == (int *)(param_1 + 0x10)) {
    if (*(int *)(param_1 + 0x18) == 0) {
      piVar8 = *(int **)(param_1 + 0x14);
      if (piVar8[2] < *(int *)(param_2 + 0x38)) {
        iVar1 = *(int *)(*piVar8 + 0x38);
        if ((iVar1 <= *(int *)(param_2 + 0x38)) && (piVar8[2] <= iVar1)) goto LAB_0013fc30;
        *(int *)(param_2 + 0xc) = *piVar8;
LAB_0013fcbc:
        *piVar8 = param_2;
      }
      else {
LAB_0013fc30:
        iVar1 = *(int *)(param_2 + 0x38);
        iVar6 = *piVar8;
        iVar3 = *(int *)(iVar6 + 0x38);
        if (iVar1 <= iVar3) {
          if (piVar8[2] <= iVar3) {
            if (*(int *)(iVar6 + 0xc) != 0) {
              do {
                iVar3 = *(int *)(iVar6 + 0xc);
                iVar9 = iVar6;
                if (*(int *)(iVar3 + 0x38) < *(int *)(iVar6 + 0x38)) break;
                iVar9 = iVar3;
                iVar6 = iVar3;
              } while (*(int *)(iVar3 + 0xc) != 0);
              goto LAB_0013fca5;
            }
            goto LAB_0013fcab;
          }
          iVar9 = iVar6;
          if (iVar3 <= iVar1) {
LAB_0013fca5:
            do {
              iVar6 = iVar9;
              if (*(int *)(iVar6 + 0xc) == 0) break;
              iVar9 = *(int *)(iVar6 + 0xc);
            } while (*(int *)(*(int *)(iVar6 + 0xc) + 0x38) <= iVar1);
            goto LAB_0013fcab;
          }
LAB_0013fcb1:
          *(int *)(param_2 + 0xc) = *piVar8;
          goto LAB_0013fcbc;
        }
        iVar3 = *(int *)(iVar6 + 0xc);
        while (iVar3 != 0) {
          iVar9 = *(int *)(iVar6 + 0xc);
          if ((*(int *)(iVar9 + 0x38) < *(int *)(iVar6 + 0x38)) || (iVar1 < *(int *)(iVar9 + 0x38)))
          break;
          iVar6 = iVar9;
          iVar3 = *(int *)(iVar9 + 0xc);
        }
LAB_0013fcab:
        if (iVar6 == 0) goto LAB_0013fcb1;
        *(undefined4 *)(param_2 + 0xc) = *(undefined4 *)(iVar6 + 0xc);
        *(int *)(iVar6 + 0xc) = param_2;
        if (piVar8[1] == iVar6) {
          piVar8[1] = param_2;
        }
      }
      LOCK();
      *(undefined4 *)(param_1 + 0x24) = 0;
      UNLOCK();
      goto LAB_00140157;
    }
LAB_0013fdb4:
    if (local_1c == (int *)(param_1 + 0x10)) {
      local_1c = *(int **)(param_1 + 0x14);
    }
    if (local_1c[3] < iVar1) {
      iVar6 = local_1c[5];
      if (*(int *)(param_1 + 0x18) == 0) {
        local_1c = (int *)0x0;
      }
      else {
        *(int *)(param_1 + 0x18) = *(int *)(param_1 + 0x18) + -1;
        local_1c = (int *)_kalloc(0x18);
        local_1c[3] = 0;
        local_1c[1] = 0;
        *local_1c = 0;
        local_1c[2] = 0;
      }
      local_1c[1] = param_2;
      *local_1c = param_2;
      *(undefined4 *)(param_2 + 0xc) = 0;
      iVar3 = param_1 + 0x10;
      if (iVar6 == iVar3) {
        iVar3 = *(int *)(param_1 + 0x10);
        if (iVar6 == iVar3) {
          *(int **)(param_1 + 0x14) = local_1c;
        }
        else {
          *(int **)(iVar3 + 0x14) = local_1c;
        }
        local_1c[4] = iVar3;
        local_1c[5] = param_1 + 0x10;
        *(int **)(param_1 + 0x10) = local_1c;
      }
      else if (*(int *)(iVar6 + 0x10) == iVar3) {
        iVar6 = *(int *)(param_1 + 0x14);
        if (iVar3 == iVar6) {
          *(int **)(param_1 + 0x10) = local_1c;
        }
        else {
          *(int **)(iVar6 + 0x10) = local_1c;
        }
        local_1c[5] = iVar6;
        local_1c[4] = param_1 + 0x10;
        *(int **)(param_1 + 0x14) = local_1c;
      }
      else {
        local_1c[5] = iVar6;
        local_1c[4] = *(int *)(iVar6 + 0x10);
        *(int **)(iVar6 + 0x10) = local_1c;
        *(int **)(local_1c[4] + 0x14) = local_1c;
      }
      local_1c[3] = iVar1;
      if (param_1 + 0x10 == local_1c[5]) {
        local_1c[2] = *(int *)(param_1 + 0x1c);
      }
      else {
        local_1c[2] = *(int *)(*(int *)(local_1c[5] + 4) + 0x38);
      }
    }
    else {
      if (iVar1 == local_1c[3]) {
        if (local_1c[2] < *(int *)(param_2 + 0x38)) {
          iVar1 = *(int *)(*local_1c + 0x38);
          if ((*(int *)(param_2 + 0x38) < iVar1) || (iVar1 < local_1c[2])) {
            *(int *)(param_2 + 0xc) = *local_1c;
            goto LAB_0013ff78;
          }
        }
        iVar1 = *(int *)(param_2 + 0x38);
        iVar6 = *local_1c;
        iVar3 = *(int *)(iVar6 + 0x38);
        if (iVar3 < iVar1) {
          iVar3 = *(int *)(iVar6 + 0xc);
          while (iVar3 != 0) {
            iVar9 = *(int *)(iVar6 + 0xc);
            if ((*(int *)(iVar9 + 0x38) < *(int *)(iVar6 + 0x38)) ||
               (iVar1 < *(int *)(iVar9 + 0x38))) break;
            iVar6 = iVar9;
            iVar3 = *(int *)(iVar9 + 0xc);
          }
          goto joined_r0x0013fda7;
        }
        if (local_1c[2] <= iVar3) {
          if (*(int *)(iVar6 + 0xc) != 0) {
            do {
              iVar3 = *(int *)(iVar6 + 0xc);
              iVar9 = iVar6;
              if (*(int *)(iVar3 + 0x38) < *(int *)(iVar6 + 0x38)) break;
              iVar9 = iVar3;
              iVar6 = iVar3;
            } while (*(int *)(iVar3 + 0xc) != 0);
            goto LAB_0013ff61;
          }
          goto joined_r0x0013fda7;
        }
        iVar9 = iVar6;
        if (iVar3 <= iVar1) {
LAB_0013ff61:
          do {
            iVar6 = iVar9;
            if (*(int *)(iVar6 + 0xc) == 0) break;
            iVar9 = *(int *)(iVar6 + 0xc);
          } while (*(int *)(*(int *)(iVar6 + 0xc) + 0x38) <= iVar1);
          goto joined_r0x0013fda7;
        }
        goto LAB_0013ff6d;
      }
      if (*(int *)(param_1 + 0x18) == 0) {
        piVar8 = (int *)0x0;
      }
      else {
        *(int *)(param_1 + 0x18) = *(int *)(param_1 + 0x18) + -1;
        piVar8 = (int *)_kalloc(0x18);
        piVar8[3] = 0;
        piVar8[1] = 0;
        *piVar8 = 0;
        piVar8[2] = 0;
      }
      piVar8[1] = param_2;
      *piVar8 = param_2;
      *(undefined4 *)(param_2 + 0xc) = 0;
      piVar7 = (int *)(param_1 + 0x10);
      if (local_1c == piVar7) {
        piVar7 = *(int **)(param_1 + 0x10);
        if (local_1c == piVar7) {
          *(int **)(param_1 + 0x14) = piVar8;
        }
        else {
          piVar7[5] = (int)piVar8;
        }
        piVar8[4] = (int)piVar7;
        piVar8[5] = param_1 + 0x10;
        *(int **)(param_1 + 0x10) = piVar8;
      }
      else if ((int *)local_1c[4] == piVar7) {
        piVar2 = *(int **)(param_1 + 0x14);
        if (piVar7 == piVar2) {
          *(int **)(param_1 + 0x10) = piVar8;
        }
        else {
          piVar2[4] = (int)piVar8;
        }
        piVar8[5] = (int)piVar2;
        piVar8[4] = param_1 + 0x10;
        *(int **)(param_1 + 0x14) = piVar8;
      }
      else {
        piVar8[5] = (int)local_1c;
        piVar8[4] = local_1c[4];
        local_1c[4] = (int)piVar8;
        *(int **)(piVar8[4] + 0x14) = piVar8;
      }
      piVar8[3] = iVar1;
      piVar8[2] = *(int *)(local_1c[1] + 0x38);
    }
  }
  else {
    if (*(int *)(param_1 + 0x18) != 0) goto LAB_0013fdb4;
    if (local_1c[2] < *(int *)(param_2 + 0x38)) {
      iVar1 = *(int *)(*local_1c + 0x38);
      if ((iVar1 <= *(int *)(param_2 + 0x38)) && (local_1c[2] <= iVar1)) goto LAB_0013fd24;
      *(int *)(param_2 + 0xc) = *local_1c;
    }
    else {
LAB_0013fd24:
      iVar1 = *(int *)(param_2 + 0x38);
      iVar6 = *local_1c;
      iVar3 = *(int *)(iVar6 + 0x38);
      if (iVar3 < iVar1) {
        iVar3 = *(int *)(iVar6 + 0xc);
        while (iVar3 != 0) {
          iVar9 = *(int *)(iVar6 + 0xc);
          if ((*(int *)(iVar9 + 0x38) < *(int *)(iVar6 + 0x38)) || (iVar1 < *(int *)(iVar9 + 0x38)))
          break;
          iVar6 = iVar9;
          iVar3 = *(int *)(iVar9 + 0xc);
        }
      }
      else {
        if (iVar3 < local_1c[2]) {
          iVar9 = iVar6;
          if (iVar1 < iVar3) goto LAB_0013ff6d;
        }
        else {
          if (*(int *)(iVar6 + 0xc) == 0) goto joined_r0x0013fda7;
          do {
            iVar3 = *(int *)(iVar6 + 0xc);
            iVar9 = iVar6;
            if (*(int *)(iVar3 + 0x38) < *(int *)(iVar6 + 0x38)) break;
            iVar9 = iVar3;
            iVar6 = iVar3;
          } while (*(int *)(iVar3 + 0xc) != 0);
        }
        do {
          iVar6 = iVar9;
          if (*(int *)(iVar6 + 0xc) == 0) break;
          iVar9 = *(int *)(iVar6 + 0xc);
        } while (*(int *)(*(int *)(iVar6 + 0xc) + 0x38) <= iVar1);
      }
joined_r0x0013fda7:
      if (iVar6 != 0) {
        *(undefined4 *)(param_2 + 0xc) = *(undefined4 *)(iVar6 + 0xc);
        *(int *)(iVar6 + 0xc) = param_2;
        if (local_1c[1] == iVar6) {
          local_1c[1] = param_2;
        }
        goto LAB_00140067;
      }
LAB_0013ff6d:
      *(int *)(param_2 + 0xc) = *local_1c;
    }
LAB_0013ff78:
    *local_1c = param_2;
  }
LAB_00140067:
  if ((local_1c != (int *)(param_1 + 0x10)) &&
     (local_18 = (int *)local_1c[4], (int *)(param_1 + 0x10) != local_18)) {
    do {
      iVar1 = *(int *)(local_1c[1] + 0x38);
      iVar6 = *local_18;
      iVar9 = iVar1 + -1;
      iVar3 = *(int *)(iVar6 + 0x38);
      if (iVar3 < iVar9) {
        iVar3 = *(int *)(iVar6 + 0xc);
        while (iVar3 != 0) {
          iVar4 = *(int *)(iVar6 + 0xc);
          if ((*(int *)(iVar4 + 0x38) < *(int *)(iVar6 + 0x38)) || (iVar9 < *(int *)(iVar4 + 0x38)))
          break;
          iVar6 = iVar4;
          iVar3 = *(int *)(iVar4 + 0xc);
        }
LAB_0014010b:
        if ((iVar6 != 0) && (*(int *)(iVar6 + 0xc) != 0)) {
          *(int *)(local_18[1] + 0xc) = *local_18;
          local_18[1] = iVar6;
          *local_18 = *(int *)(iVar6 + 0xc);
          *(undefined4 *)(iVar6 + 0xc) = 0;
        }
      }
      else {
        if (local_18[2] <= iVar3) {
          if (*(int *)(iVar6 + 0xc) != 0) {
            do {
              iVar3 = *(int *)(iVar6 + 0xc);
              iVar4 = iVar6;
              if (*(int *)(iVar3 + 0x38) < *(int *)(iVar6 + 0x38)) break;
              iVar4 = iVar3;
              iVar6 = iVar3;
            } while (*(int *)(iVar3 + 0xc) != 0);
            goto LAB_00140105;
          }
          goto LAB_0014010b;
        }
        iVar4 = iVar6;
        if (iVar3 <= iVar9) {
LAB_00140105:
          do {
            iVar6 = iVar4;
            if (*(int *)(iVar6 + 0xc) == 0) break;
            iVar4 = *(int *)(iVar6 + 0xc);
          } while (*(int *)(*(int *)(iVar6 + 0xc) + 0x38) <= iVar9);
          goto LAB_0014010b;
        }
      }
      local_1c = local_18;
      local_18[2] = iVar1;
      local_18 = (int *)local_18[4];
    } while ((int *)(param_1 + 0x10) != local_18);
  }
  LOCK();
  *(undefined4 *)(param_1 + 0x24) = 0;
  UNLOCK();
LAB_00140157:
  _splx(uVar5);
  return;
}

