
/* WARNING: Removing unreachable block (ram,0xf0050054) */
/* WARNING: Removing unreachable block (ram,0xf00500a0) */
/* WARNING: Removing unreachable block (ram,0xf0050070) */
/* WARNING: Removing unreachable block (ram,0xf0050028) */
/* WARNING: Removing unreachable block (ram,0xf004ff60) */
/* WARNING: Removing unreachable block (ram,0xf004ffbc) */
/* WARNING: Removing unreachable block (ram,0xf0050068) */
/* WARNING: Removing unreachable block (ram,0xf0050098) */
/* WARNING: Removing unreachable block (ram,0xf005004c) */
/* WARNING: Removing unreachable block (ram,0xf00500c8) */
/* WARNING: Removing unreachable block (ram,0xf004ff20) */

undefined8 _syncip(int param_1,undefined4 param_2)

{
  word wVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  undefined4 unaff_l0;
  int iVar5;
  uint *puVar6;
  undefined4 unaff_l1;
  int iVar7;
  uint *puVar8;
  undefined4 unaff_l3;
  uint *puVar9;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
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
  iVar7 = *(int *)(param_1 + 0x50);
  iVar2 = *(int *)(param_1 + 0x70) + -1 + *(int *)(iVar7 + 0x30);
  .udiv();
  if (iVar2 < _nbuf / 2) {
    iVar5 = 0;
    if (0 < iVar2) {
      do {
        iVar3 = param_1;
        _bmap(param_1,iVar5,1);
        if ((iVar5 < 0xc) &&
           (*(uint *)(param_1 + 0x70) <
            (uint)(iVar5 + 1 << ((byte)*(undefined4 *)(iVar7 + 0x50) & 0x1f)))) {
          uVar4 = ((*(uint *)(param_1 + 0x70) & ~*(uint *)(iVar7 + 0x48)) + *(int *)(iVar7 + 0x34))
                  - 1 & *(uint *)(iVar7 + 0x4c);
        }
        else {
          uVar4 = *(uint *)(iVar7 + 0x30);
        }
        _blkflush(*(undefined4 *)(param_1 + 0x40),
                  iVar3 << ((byte)*(undefined4 *)(iVar7 + 100) & 0x1f),uVar4);
        iVar5 = iVar5 + 1;
      } while (iVar5 < iVar2);
      wVar1 = *(word *)(param_1 + 0x44);
      goto loc_F00500C0;
    }
  }
  else {
    puVar9 = _buf + _nbuf * 0x11;
    if (_buf < puVar9) {
      puVar8 = _buf + 4;
      puVar6 = _buf;
      do {
        if (puVar8[0xc] == *(uint *)(param_1 + 0x40)) {
          uVar4 = *puVar6;
          if ((uVar4 & 0x200) == 0) {
            puVar6 = puVar6 + 0x11;
          }
          else {
            _spltty();
            if ((*puVar6 & 8) == 0) {
              _splx(uVar4);
              _spltty();
              *(uint *)(*puVar8 + 0xc) = puVar8[-1];
              *(uint *)(puVar8[-1] + 0x10) = *puVar8;
              *puVar6 = *puVar6 | 8;
              _splx();
              _bwrite(puVar6);
            }
            else {
              *puVar6 = *puVar6 | 0x40;
              _sleep(puVar6,0x15);
              _splx(uVar4);
              puVar8 = puVar8 + -0x11;
              puVar6 = puVar6 + -0x11;
            }
            puVar6 = puVar6 + 0x11;
          }
        }
        else {
          puVar6 = puVar6 + 0x11;
        }
        puVar8 = puVar8 + 0x11;
      } while (puVar6 < puVar9);
    }
  }
  wVar1 = *(word *)(param_1 + 0x44);
loc_F00500C0:
  *(word *)(param_1 + 0x44) = wVar1 | 0x40;
  _iupdat(param_1,1);
  return CONCAT44(param_2,param_1);
}
