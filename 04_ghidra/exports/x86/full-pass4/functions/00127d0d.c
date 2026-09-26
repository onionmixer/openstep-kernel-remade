/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00127d0d */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Synthetic analysis entry; not a reconstructed ABI function. Role=noreturn_fallthrough_fragment.
   Context recorded in gap-actions.json. */

undefined4 __analysis_fragment_00127d0d(void)

{
  byte bVar1;
  int iVar2;
  int unaff_EBX;
  int iVar3;
  uint *puVar4;
  uint uVar5;
  int unaff_EBP;
  undefined4 *puVar6;
  int *piVar7;
  
  piVar7 = *(int **)(unaff_EBP + 0xc);
  *(undefined2 *)(*piVar7 + 10) = 0xe;
  _DAT_001e917c = _DAT_001e917c + -1;
  _DAT_001e9198 = _DAT_001e9198 + 1;
  _mfree = *(undefined4 *)*piVar7;
  *(undefined4 *)*piVar7 = 0;
  *(undefined4 *)(*piVar7 + 4) = 0xc;
  _splx();
  iVar3 = **(int **)(unaff_EBP + 0xc);
  if (iVar3 == 0) {
    return 0x37;
  }
  puVar6 = (undefined4 *)(iVar3 + *(int *)(iVar3 + 4));
  *puVar6 = 0;
  *(undefined1 *)(puVar6 + 1) = 1;
  *(undefined1 *)((int)puVar6 + 5) = 1;
  *(undefined2 *)((int)puVar6 + 6) = 0;
  piVar7 = (int *)(**(int **)(unaff_EBP + 0xc) + *(int *)(**(int **)(unaff_EBP + 0xc) + 4));
  switch(*(undefined4 *)(unaff_EBP + 8)) {
  case 3:
    if ((unaff_EBX != 0) && (*(short *)(unaff_EBX + 8) == 4)) {
      iVar3 = *(int *)(*(int *)(unaff_EBX + 4) + unaff_EBX);
      iVar2 = _in_ifaddr;
      if (iVar3 == 0) {
        *piVar7 = 0;
        goto LAB_00128093;
      }
      for (; (iVar2 != 0 && (*(int *)(iVar2 + 4) != iVar3)); iVar2 = *(int *)(iVar2 + 0x40)) {
      }
      *(undefined4 *)(unaff_EBP + -0x2c) = 0;
      if (iVar2 != 0) {
        *(undefined4 *)(unaff_EBP + -0x2c) = *(undefined4 *)(iVar2 + 0x20);
      }
      if (*(int *)(unaff_EBP + -0x2c) != 0) {
        *piVar7 = *(int *)(unaff_EBP + -0x2c);
        goto LAB_00128093;
      }
LAB_00128059:
      *(undefined4 *)(unaff_EBP + -0x18) = 0x31;
      goto LAB_00128093;
    }
    break;
  case 4:
    if ((unaff_EBX != 0) && (*(short *)(unaff_EBX + 8) == 1)) {
      *(undefined1 *)(piVar7 + 1) = *(undefined1 *)(*(int *)(unaff_EBX + 4) + unaff_EBX);
      goto LAB_00128093;
    }
    break;
  case 5:
    if (((unaff_EBX != 0) && (*(short *)(unaff_EBX + 8) == 1)) &&
       (bVar1 = *(byte *)(*(int *)(unaff_EBX + 4) + unaff_EBX), bVar1 < 2)) {
      *(byte *)((int)piVar7 + 5) = bVar1;
      goto LAB_00128093;
    }
    break;
  case 6:
    if (((unaff_EBX != 0) && (*(short *)(unaff_EBX + 8) == 8)) &&
       (puVar4 = (uint *)(unaff_EBX + *(int *)(unaff_EBX + 4)),
       *(uint **)(unaff_EBP + -0x28) = puVar4, (*puVar4 & 0xf0) == 0xe0)) {
      iVar3 = (*(undefined4 **)(unaff_EBP + -0x28))[1];
      iVar2 = _in_ifaddr;
      if (iVar3 == 0) {
        *(undefined4 *)(unaff_EBP + -0x14) = 0;
        *(undefined2 *)(unaff_EBP + -0x10) = 2;
        *(undefined4 *)(unaff_EBP + -0xc) = **(undefined4 **)(unaff_EBP + -0x28);
        _rtalloc();
        if (*(int *)(unaff_EBP + -0x14) == 0) goto LAB_00128059;
        *(undefined4 *)(unaff_EBP + -0x2c) = *(undefined4 *)(*(int *)(unaff_EBP + -0x14) + 0x2c);
        _rtfree();
      }
      else {
        for (; (iVar2 != 0 && (*(int *)(iVar2 + 4) != iVar3)); iVar2 = *(int *)(iVar2 + 0x40)) {
        }
        *(undefined4 *)(unaff_EBP + -0x2c) = 0;
        if (iVar2 != 0) {
          *(undefined4 *)(unaff_EBP + -0x2c) = *(undefined4 *)(iVar2 + 0x20);
        }
      }
      if (*(int *)(unaff_EBP + -0x2c) != 0) {
        iVar3 = 0;
        if (*(ushort *)((int)piVar7 + 6) != 0) {
          *(uint *)(unaff_EBP + -0x1c) = (uint)*(ushort *)((int)piVar7 + 6);
          do {
            if ((((int *)piVar7[iVar3 + 2])[1] == *(int *)(unaff_EBP + -0x2c)) &&
               (*(int *)piVar7[iVar3 + 2] == **(int **)(unaff_EBP + -0x28))) break;
            iVar3 = iVar3 + 1;
          } while (iVar3 < *(int *)(unaff_EBP + -0x1c));
          if (iVar3 < (int)(uint)*(ushort *)((int)piVar7 + 6)) {
            *(undefined4 *)(unaff_EBP + -0x18) = 0x30;
            goto LAB_00128093;
          }
        }
        if (iVar3 == 0x14) {
          *(undefined4 *)(unaff_EBP + -0x18) = 0x3b;
        }
        else {
          iVar2 = _in_addmulti(**(undefined4 **)(unaff_EBP + -0x28));
          piVar7[iVar3 + 2] = iVar2;
          if (iVar2 == 0) {
            *(undefined4 *)(unaff_EBP + -0x18) = 0x37;
          }
          else {
            *(short *)((int)piVar7 + 6) = *(short *)((int)piVar7 + 6) + 1;
          }
        }
        goto LAB_00128093;
      }
      goto LAB_00128059;
    }
    break;
  case 7:
    if (((unaff_EBX != 0) && (*(short *)(unaff_EBX + 8) == 8)) &&
       (puVar4 = (uint *)(unaff_EBX + *(int *)(unaff_EBX + 4)),
       *(uint **)(unaff_EBP + -0x28) = puVar4, (*puVar4 & 0xf0) == 0xe0)) {
      iVar3 = *(int *)(*(int *)(unaff_EBP + -0x28) + 4);
      iVar2 = _in_ifaddr;
      if (iVar3 == 0) {
        *(undefined4 *)(unaff_EBP + -0x2c) = 0;
      }
      else {
        for (; (iVar2 != 0 && (*(int *)(iVar2 + 4) != iVar3)); iVar2 = *(int *)(iVar2 + 0x40)) {
        }
        *(undefined4 *)(unaff_EBP + -0x2c) = 0;
        if (iVar2 != 0) {
          *(undefined4 *)(unaff_EBP + -0x2c) = *(undefined4 *)(iVar2 + 0x20);
        }
        if (*(int *)(unaff_EBP + -0x2c) == 0) goto LAB_00128059;
      }
      uVar5 = 0;
      if (*(ushort *)((int)piVar7 + 6) != 0) {
        *(uint *)(unaff_EBP + -0x20) = (uint)*(ushort *)((int)piVar7 + 6);
        do {
          if (((*(int *)(unaff_EBP + -0x2c) == 0) ||
              (*(int *)(piVar7[uVar5 + 2] + 4) == *(int *)(unaff_EBP + -0x2c))) &&
             (*(int *)piVar7[uVar5 + 2] == **(int **)(unaff_EBP + -0x28))) break;
          uVar5 = uVar5 + 1;
        } while ((int)uVar5 < *(int *)(unaff_EBP + -0x20));
      }
      if (uVar5 != *(ushort *)((int)piVar7 + 6)) {
        _in_delmulti();
        while ((int)(uVar5 + 1) < (int)(uint)*(ushort *)((int)piVar7 + 6)) {
          piVar7[uVar5 + 2] = piVar7[uVar5 + 3];
          uVar5 = uVar5 + 1;
        }
        *(short *)((int)piVar7 + 6) = *(short *)((int)piVar7 + 6) + -1;
        goto LAB_00128093;
      }
      goto LAB_00128059;
    }
    break;
  default:
    *(undefined4 *)(unaff_EBP + -0x18) = 0x2d;
    goto LAB_00128093;
  }
  *(undefined4 *)(unaff_EBP + -0x18) = 0x16;
LAB_00128093:
  if ((*piVar7 == 0) && (piVar7[1] == 0x101)) {
    _m_free();
    **(undefined4 **)(unaff_EBP + 0xc) = 0;
  }
  return *(undefined4 *)(unaff_EBP + -0x18);
}

