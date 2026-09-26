
/* WARNING: Removing unreachable block (ram,0xf00b2a34) */
/* WARNING: Removing unreachable block (ram,0xf00b2970) */
/* WARNING: Removing unreachable block (ram,0xf00b2928) */
/* WARNING: Removing unreachable block (ram,0xf00b28ec) */
/* WARNING: Removing unreachable block (ram,0xf00b28e0) */
/* WARNING: Removing unreachable block (ram,0xf00b291c) */
/* WARNING: Removing unreachable block (ram,0xf00b2934) */
/* WARNING: Removing unreachable block (ram,0xf00b29d8) */
/* WARNING: Removing unreachable block (ram,0xf00b2a6c) */
/* WARNING: Removing unreachable block (ram,0xf00b28c8) */
/* WARNING: Removing unreachable block (ram,0xf00b2ab4) */

int * _getmemlist(void)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  int *piVar6;
  undefined4 unaff_l0;
  uint uVar7;
  int *piVar8;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 unaff_i1;
  int iVar9;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool bVar10;
  bool bVar11;
  bool bVar12;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  
  if (!in_DECOMPILE_MODE) {
    *(undefined4 *)(in_CWP * 0x40 + 0x8000) = unaff_i0;
    *(undefined4 *)((in_CWP * 0x10 + 1) * 4 + 0x8000) = unaff_i1;
    *(undefined4 *)((in_CWP * 0x10 + 2) * 4 + 0x8000) = unaff_i2;
    *(undefined4 *)((in_CWP * 0x10 + 3) * 4 + 0x8000) = unaff_i3;
    *(undefined4 *)((in_CWP * 0x10 + 4) * 4 + 0x8000) = unaff_i4;
    *(undefined4 *)((in_CWP * 0x10 + 5) * 4 + 0x8000) = unaff_i5;
    *(undefined4 *)((in_CWP * 0x10 + 6) * 4 + 0x8000) = unaff_fp;
    *(undefined4 *)((in_CWP * 0x10 + 7) * 4 + 0x8000) = unaff_i7;
    *(undefined4 *)((in_CWP * 0x10 + 8) * 4 + 0x8000) = unaff_l0;
    *(undefined4 *)((in_CWP * 0x10 + 9) * 4 + 0x8000) = unaff_l1;
    *(undefined4 *)((in_CWP * 0x10 + 10) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xb) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xc) * 4 + 0x8000) = unaff_l4;
    *(undefined4 *)((in_CWP * 0x10 + 0xd) * 4 + 0x8000) = unaff_l5;
    *(undefined4 *)((in_CWP * 0x10 + 0xe) * 4 + 0x8000) = unaff_l6;
    *(undefined4 *)((in_CWP * 0x10 + 0xf) * 4 + 0x8000) = unaff_l7;
  }
  if (dword_F011DD24 == (int *)0x0) {
    dword_F011DD24 = (int *)_prom_alloc();
    dword_F0131798 = 0x1000;
  }
  _prom_nextnode(0);
  iVar3 = _searchpromtree();
  if (iVar3 != 0) {
    if (dword_F011DD20 != 0) {
      _printf(aFoundSSAtNodeX);
    }
    uVar4 = _getproplen(iVar3);
    iVar5 = udiv();
    if (iVar5 != 0) {
      uVar7 = iVar5 * 0x18;
      if (dword_F0131798 < uVar7) {
        _panic(aMemlistsTooBig);
      }
      for (; piVar1 = dword_F011DD24, 0 < (int)uVar7; uVar7 = uVar7 - 1) {
        uRam00000000 = 0;
      }
      dword_F0131798 = dword_F0131798 + iVar5 * -0x18;
      dword_F011DD24 = dword_F011DD24 + iVar5 * 6;
      if (dword_F0131798 < uVar4) {
        _panic(aMemlistsTooBig_0);
      }
      piVar8 = dword_F011DD24;
      if (0 < (int)uVar4) {
        *(undefined *)dword_F011DD24 = 0;
      }
      iVar9 = 0;
      dword_F0131798 = dword_F0131798 - uVar4;
      dword_F011DD24 = (int *)((int)dword_F011DD24 + uVar4);
      _prom_getprop(iVar3);
      if (0 < iVar5) {
        do {
          if (dword_F011DD20 != 0) {
            _printf(aChunkDAddrXBus);
          }
          if (*piVar8 == 0) {
            iVar3 = 0;
            bVar12 = false;
            bVar11 = iVar9 == 0;
            bVar10 = iVar9 < 0;
            if (0 < iVar9) {
              piVar6 = piVar1;
              do {
                if (*piVar6 != 0) break;
                bVar12 = SBORROW4(iVar9,iVar3);
                bVar11 = iVar9 == iVar3;
                bVar10 = iVar9 - iVar3 < 0;
                if ((uint)piVar8[1] < (uint)piVar6[1]) goto loc_F00B2AE0;
                iVar3 = iVar3 + 1;
                piVar6 = piVar6 + 6;
              } while (iVar3 < iVar9);
              bVar12 = SBORROW4(iVar9,iVar3);
              bVar11 = iVar9 == iVar3;
              bVar10 = iVar9 - iVar3 < 0;
            }
loc_F00B2AE0:
            if (!bVar11 && bVar10 == bVar12) {
              piVar6 = piVar1 + iVar9 * 6;
              iVar2 = iVar9;
              do {
                iVar2 = iVar2 + -1;
                *(undefined8 *)piVar6 = *(undefined8 *)(piVar6 + -6);
                *(undefined8 *)(piVar6 + 2) = *(undefined8 *)(piVar6 + -4);
                *(undefined8 *)(piVar6 + 4) = *(undefined8 *)(piVar6 + -2);
                piVar6 = piVar6 + -6;
              } while (iVar3 < iVar2);
            }
            *(qword *)(piVar1 + iVar3 * 6) = (qword)(uint)piVar8[1];
            *(qword *)(piVar1 + iVar3 * 6 + 2) = (qword)(uint)piVar8[2];
          }
          iVar9 = iVar9 + 1;
          piVar8 = piVar8 + 3;
        } while (iVar9 < iVar5);
      }
      iVar3 = 1;
      piVar8 = piVar1;
      if (iVar5 < 2) {
        return piVar1;
      }
      do {
        piVar6 = piVar8 + 6;
        if (*piVar6 == 0) {
          if (piVar8[7] != 0) {
            piVar8[4] = (int)piVar6;
          }
        }
        else {
          piVar8[4] = (int)piVar6;
        }
        iVar3 = iVar3 + 1;
        piVar8 = piVar6;
      } while (iVar3 < iVar5);
      return piVar1;
    }
  }
  return (int *)0x0;
}

