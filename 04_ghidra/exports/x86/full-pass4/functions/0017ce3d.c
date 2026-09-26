/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0017ce3d */

/* Synthetic analysis entry; not a reconstructed ABI function. Role=noreturn_fallthrough_fragment.
   Context recorded in gap-actions.json. */

undefined4 __analysis_fragment_0017ce3d(void)

{
  byte *pbVar1;
  byte bVar2;
  uint uVar3;
  int *piVar4;
  undefined4 uVar5;
  int iVar6;
  int unaff_EBX;
  uint uVar7;
  int unaff_EBP;
  int iVar8;
  int unaff_EDI;
  
  if (unaff_EBX < *(int *)(*(int *)(unaff_EBP + -0x14) + 0x24)) {
    *(int *)(*(int *)(unaff_EBP + -0x14) + 0x24) = unaff_EBX;
  }
  iVar6 = unaff_EBX;
  if (unaff_EBX < 0) {
    iVar6 = unaff_EBX + 7;
  }
  *(undefined4 *)(unaff_EBP + -0x18) = *(undefined4 *)(*(int *)(unaff_EBP + -0x14) + 0x10);
  bVar2 = (char)unaff_EBX + (char)(iVar6 >> 3) * -8 & 0x1f;
  pbVar1 = (byte *)((iVar6 >> 3) + *(int *)(unaff_EBP + -0x18));
  *pbVar1 = *pbVar1 & ((byte)(-2 << bVar2) | (byte)(0xfffffffe >> 0x20 - bVar2));
  piVar4 = (int *)(*(int *)(unaff_EBP + -0x14) + 0x18);
  *piVar4 = *piVar4 + 1;
  _lock_done();
  uVar3 = *(int *)(unaff_EBP + -4) + 1;
  uVar7 = *(uint *)(unaff_EDI + 0x10);
  if (uVar7 < uVar3) {
    *(uint *)(unaff_EBP + -0xc) = uVar3;
    if (uVar3 * 4 < 0x41) {
      piVar4 = (int *)_kalloc_noblock();
      if (piVar4 == (int *)0x0) {
        return 5;
      }
      *(undefined4 *)(unaff_EBP + -0x10) = 0;
      if (*(int *)(unaff_EBP + -0x10) < *(int *)(unaff_EDI + 0x10)) {
        do {
          iVar6 = *(int *)(unaff_EBP + -0x10);
          piVar4[iVar6] = *(int *)(*(int *)(unaff_EDI + 8) + iVar6 * 4);
          *(int *)(unaff_EBP + -0x10) = iVar6 + 1;
        } while (iVar6 + 1 < *(int *)(unaff_EDI + 0x10));
      }
      for (iVar6 = *(int *)(unaff_EDI + 0x10); *(int *)(unaff_EBP + -0x10) = iVar6,
          iVar6 < *(int *)(unaff_EBP + -0xc); iVar6 = iVar6 + 1) {
        iVar6 = *(int *)(unaff_EBP + -0x10);
        *(undefined1 *)(piVar4 + iVar6) = 0;
      }
      if (0 < *(int *)(unaff_EDI + 0x10)) {
        uVar5 = *(undefined4 *)(unaff_EDI + 8);
        goto LAB_0017d09d;
      }
LAB_0017d0a5:
      *(int **)(unaff_EDI + 8) = piVar4;
    }
    else {
      if (uVar7 == 0) {
        *(uint *)(unaff_EBP + -0x14) = (*(uint *)(unaff_EBP + -4) >> 4) * 4 + 4;
        piVar4 = (int *)_kalloc_noblock();
        if (piVar4 == (int *)0x0) {
          return 5;
        }
        _bzero(piVar4,*(size_t *)(unaff_EBP + -0x14));
        goto LAB_0017d0a5;
      }
      if (uVar7 * 4 < 0x41) {
        *(uint *)(unaff_EBP + -0x14) = (*(uint *)(unaff_EBP + -4) >> 4) * 4 + 4;
        piVar4 = (int *)_kalloc_noblock();
        if (piVar4 == (int *)0x0) {
          return 5;
        }
        _bzero(piVar4,*(size_t *)(unaff_EBP + -0x14));
        iVar6 = _kalloc_noblock(0x40);
        *piVar4 = iVar6;
        if (iVar6 == 0) {
          _kfree(piVar4);
          return 5;
        }
        *(undefined4 *)(unaff_EBP + -0x10) = 0;
        if (*(int *)(unaff_EBP + -0x10) < *(int *)(unaff_EDI + 0x10)) {
          do {
            iVar6 = *(int *)(unaff_EBP + -0x10);
            *(undefined4 *)(*piVar4 + iVar6 * 4) =
                 *(undefined4 *)(*(int *)(unaff_EDI + 8) + iVar6 * 4);
            *(int *)(unaff_EBP + -0x10) = iVar6 + 1;
          } while (iVar6 + 1 < *(int *)(unaff_EDI + 0x10));
        }
        uVar7 = *(uint *)(unaff_EDI + 0x10);
        *(uint *)(unaff_EBP + -0x10) = uVar7;
        while (uVar7 < 0x10) {
          iVar6 = *(int *)(unaff_EBP + -0x10);
          *(undefined1 *)(*piVar4 + iVar6 * 4) = 0;
          uVar7 = iVar6 + 1;
          *(uint *)(unaff_EBP + -0x10) = uVar7;
        }
        uVar5 = *(undefined4 *)(unaff_EDI + 8);
LAB_0017d09d:
        _kfree(uVar5);
        goto LAB_0017d0a5;
      }
      *(uint *)(unaff_EBP + -0x14) = (*(uint *)(unaff_EBP + -4) >> 4) * 4 + 4;
      if (*(int *)(unaff_EBP + -0x14) != (uVar7 - 1 >> 4) * 4 + 4) {
        piVar4 = (int *)_kalloc_noblock();
        if (piVar4 == (int *)0x0) {
          return 5;
        }
        _bzero(piVar4,*(size_t *)(unaff_EBP + -0x14));
        iVar6 = *(int *)(unaff_EDI + 0x10);
        *(undefined4 *)(unaff_EBP + -0x10) = 0;
        if (iVar6 - 1U >> 4 != 0xffffffff) {
          do {
            iVar6 = *(int *)(unaff_EBP + -0x10);
            piVar4[iVar6] = *(int *)(*(int *)(unaff_EDI + 8) + iVar6 * 4);
            *(uint *)(unaff_EBP + -0x10) = iVar6 + 1U;
          } while (iVar6 + 1U < (*(int *)(unaff_EDI + 0x10) - 1U >> 4) + 1);
        }
        uVar5 = *(undefined4 *)(unaff_EDI + 8);
        goto LAB_0017d09d;
      }
    }
    *(undefined4 *)(unaff_EDI + 0x10) = *(undefined4 *)(unaff_EBP + -0xc);
  }
  if ((uint)(*(int *)(unaff_EDI + 0x10) * 4) < 0x41) {
    iVar6 = _vnode_pager_findpage(*(undefined4 *)(unaff_EDI + 4));
    if (iVar6 != 5) {
      iVar6 = *(int *)(unaff_EDI + 8);
      uVar5 = **(undefined4 **)(unaff_EBP + 0x14);
      iVar8 = *(int *)(unaff_EBP + -4);
      goto LAB_0017d157;
    }
  }
  else {
    uVar7 = *(uint *)(unaff_EBP + -4) >> 4;
    *(uint *)(unaff_EBP + -0x14) = *(uint *)(unaff_EBP + -4) & 0xf;
    if (*(int *)(*(int *)(unaff_EDI + 8) + uVar7 * 4) == 0) {
      uVar5 = _kalloc_noblock();
      *(undefined4 *)(*(int *)(unaff_EDI + 8) + uVar7 * 4) = uVar5;
      if (*(int *)(*(int *)(unaff_EDI + 8) + uVar7 * 4) == 0) {
        return 5;
      }
      *(undefined4 *)(unaff_EBP + -0x10) = 0;
      do {
        iVar6 = *(int *)(unaff_EBP + -0x10);
        *(undefined1 *)(*(int *)(*(int *)(unaff_EDI + 8) + uVar7 * 4) + iVar6 * 4) = 0;
        uVar3 = iVar6 + 1;
        *(uint *)(unaff_EBP + -0x10) = uVar3;
      } while (uVar3 < 0x10);
    }
    iVar6 = _vnode_pager_findpage(*(undefined4 *)(unaff_EDI + 4));
    if (iVar6 != 5) {
      iVar6 = *(int *)(*(int *)(unaff_EDI + 8) + uVar7 * 4);
      uVar5 = **(undefined4 **)(unaff_EBP + 0x14);
      iVar8 = *(int *)(unaff_EBP + -0x14);
LAB_0017d157:
      *(undefined4 *)(iVar6 + iVar8 * 4) = uVar5;
      return 0;
    }
  }
  return 5;
}

