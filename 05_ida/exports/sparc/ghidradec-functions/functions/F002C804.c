
/* WARNING: Removing unreachable block (ram,0xf002c9a4) */
/* WARNING: Removing unreachable block (ram,0xf002c990) */
/* WARNING: Removing unreachable block (ram,0xf002c94c) */
/* WARNING: Removing unreachable block (ram,0xf002c938) */
/* WARNING: Removing unreachable block (ram,0xf002c8f0) */
/* WARNING: Removing unreachable block (ram,0xf002c84c) */
/* WARNING: Removing unreachable block (ram,0xf002c8c8) */
/* WARNING: Removing unreachable block (ram,0xf002c918) */
/* WARNING: Removing unreachable block (ram,0xf002c95c) */
/* WARNING: Removing unreachable block (ram,0xf002c9c4) */
/* WARNING: Removing unreachable block (ram,0xf002c9b0) */
/* WARNING: Removing unreachable block (ram,0xf002c9b8) */
/* WARNING: Removing unreachable block (ram,0xf002c808) */

undefined8 _rawintr(int *param_1,undefined4 param_2)

{
  int *piVar1;
  sword sVar2;
  word wVar3;
  int *piVar4;
  undefined4 *puVar5;
  int iVar6;
  int *piVar7;
  undefined4 unaff_l0;
  int iVar8;
  undefined4 unaff_l1;
  undefined4 *puVar9;
  int iVar10;
  undefined4 unaff_l3;
  sword *psVar11;
  undefined4 unaff_l4;
  int iVar12;
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
  
  piVar4 = param_1;
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
    piVar4 = param_1;
  }
  while( true ) {
    _spltty();
    piVar7 = _rawintrq;
    if (_rawintrq != (int *)0x0) {
      if ((int *)_rawintrq[0x1f] == (int *)0x0) {
        DAT_f0134164 = 0;
      }
      piVar1 = _rawintrq + 0x1f;
      _rawintrq = (int *)_rawintrq[0x1f];
      *piVar1 = 0;
      dword_F0134168 = dword_F0134168 + -1;
    }
    _splx(param_1);
    iVar12 = 0;
    if (piVar7 == (int *)0x0) {
      return CONCAT44(param_2,piVar4);
    }
    psVar11 = (sword *)((int)piVar7 + piVar7[1]);
    if ((undefined4 **)_rawcb != &_rawcb) break;
loc_F002C978:
    iVar8 = iVar12 + 0x24;
    if (iVar12 == 0) {
      _m_freem();
      param_1 = piVar7;
    }
    else {
      iVar6 = iVar8;
      _sbappendaddr(iVar8,psVar11 + 10,*piVar7,0);
      if (iVar6 == 0) {
        _m_freem(*piVar7);
      }
      else {
        _sowakeup(iVar12,iVar8);
      }
      _m_free();
      param_1 = piVar7;
    }
  }
  sVar2 = *(sword *)(_rawcb + 0xb);
  puVar9 = _rawcb;
  do {
    if (sVar2 == *psVar11) {
      if (*(sword *)((int)puVar9 + 0x2e) == 0) {
        wVar3 = *(word *)(puVar9 + 0x13);
      }
      else {
        if (*(sword *)((int)puVar9 + 0x2e) != psVar11[1]) {
          puVar9 = (undefined4 *)*puVar9;
          goto loc_F002C96C;
        }
        wVar3 = *(word *)(puVar9 + 0x13);
      }
      puVar5 = puVar9 + 7;
      if (((wVar3 & 1) == 0) || (_bcmp(puVar5,psVar11 + 2,0x10), puVar5 == (undefined4 *)0x0)) {
        puVar5 = puVar9 + 3;
        if (((*(word *)(puVar9 + 0x13) & 2) == 0) ||
           (_bcmp(puVar5,psVar11 + 10,0x10), puVar5 == (undefined4 *)0x0)) {
          if (iVar12 == 0) {
loc_F002C964:
            iVar12 = puVar9[2];
          }
          else {
            iVar8 = *piVar7;
            _m_copy(iVar8,0,1000000000);
            if (iVar8 == 0) goto loc_F002C964;
            iVar10 = iVar12 + 0x24;
            iVar6 = iVar10;
            _sbappendaddr(iVar10,psVar11 + 10,iVar8,0);
            if (iVar6 != 0) {
              _sowakeup(iVar12,iVar10);
              goto loc_F002C964;
            }
            _m_freem(iVar8);
            iVar12 = puVar9[2];
          }
          puVar9 = (undefined4 *)*puVar9;
        }
        else {
          puVar9 = (undefined4 *)*puVar9;
        }
      }
      else {
        puVar9 = (undefined4 *)*puVar9;
      }
    }
    else {
      puVar9 = (undefined4 *)*puVar9;
    }
loc_F002C96C:
    if ((undefined4 **)puVar9 == &_rawcb) goto loc_F002C978;
    sVar2 = *(sword *)(puVar9 + 0xb);
  } while( true );
}
