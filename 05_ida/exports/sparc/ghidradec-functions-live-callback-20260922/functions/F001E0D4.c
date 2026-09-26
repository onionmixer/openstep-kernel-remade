
/* WARNING: Removing unreachable block (ram,0xf001e27c) */
/* WARNING: Removing unreachable block (ram,0xf001e204) */
/* WARNING: Removing unreachable block (ram,0xf001e140) */
/* WARNING: Removing unreachable block (ram,0xf001e198) */
/* WARNING: Removing unreachable block (ram,0xf001e1a4) */
/* WARNING: Removing unreachable block (ram,0xf001e244) */
/* WARNING: Removing unreachable block (ram,0xf001e284) */
/* WARNING: Removing unreachable block (ram,0xf001e118) */

undefined8 _m_pullup(undefined4 *param_1,int param_2)

{
  sword sVar1;
  word wVar2;
  uint uVar3;
  int iVar4;
  undefined4 unaff_l0;
  int iVar5;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 *puVar6;
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
  uVar3 = param_1[1] + param_2;
  if ((uVar3 < 0x7d) && ((undefined4 *)*param_1 != (undefined4 *)0x0)) {
    param_2 = param_2 - *(sword *)(param_1 + 2);
    puVar6 = param_1;
    param_1 = (undefined4 *)*param_1;
loc_F001E1BC:
    iVar4 = puVar6[1];
    sVar1 = *(sword *)(puVar6 + 2);
    while( true ) {
      iVar5 = (0x7c - iVar4) - (int)sVar1;
      if (param_2 + 0x20 < iVar5) {
        iVar5 = param_2 + 0x20;
      }
      if (*(sword *)(param_1 + 2) < iVar5) {
        iVar5 = (int)*(sword *)(param_1 + 2);
      }
      _bcopy((int)param_1 + param_1[1],(int)puVar6 + (int)sVar1 + puVar6[1],iVar5);
      *(sword *)(puVar6 + 2) = *(sword *)(puVar6 + 2) + (sword)iVar5;
      wVar2 = *(word *)(param_1 + 2);
      *(sword *)(param_1 + 2) = (sword)((uint)wVar2 - iVar5);
      param_2 = param_2 - iVar5;
      if (((uint)wVar2 - iVar5 & 0xffff) == 0) {
        _m_free();
      }
      else {
        param_1[1] = param_1[1] + iVar5;
      }
      if ((param_2 < 1) || (param_1 == (undefined4 *)0x0)) break;
      sVar1 = *(sword *)(puVar6 + 2);
    }
    if (param_2 < 1) {
      *puVar6 = param_1;
      goto locret_F001E290;
    }
    _m_free(puVar6);
  }
  else if (param_2 < 0x71) {
    _spltty();
    puVar6 = _mfree;
    if (_mfree == (undefined4 *)0x0) {
      puVar6 = (undefined4 *)0x0;
      _m_more(0,(int)*(sword *)((int)param_1 + 10));
    }
    else {
      if (*(sword *)((int)_mfree + 10) != 0) {
        _panic(&aMget_3);
      }
      *(undefined2 *)((int)puVar6 + 10) = *(undefined2 *)((int)param_1 + 10);
      word_F0134B0C = word_F0134B0C + -1;
      (&word_F0134B0C)[*(sword *)((int)param_1 + 10)] =
           (&word_F0134B0C)[*(sword *)((int)param_1 + 10)] + 1;
      _mfree = (undefined4 *)*puVar6;
      puVar6[1] = 0xc;
      *puVar6 = 0;
    }
    _splx(uVar3);
    if (puVar6 != (undefined4 *)0x0) {
      *(undefined2 *)(puVar6 + 2) = 0;
      goto loc_F001E1BC;
    }
  }
  _m_freem(param_1);
  puVar6 = (undefined4 *)0x0;
locret_F001E290:
  return CONCAT44(param_2,puVar6);
}

