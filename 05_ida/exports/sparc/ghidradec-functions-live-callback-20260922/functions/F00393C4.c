
/* WARNING: Removing unreachable block (ram,0xf00395c0) */
/* WARNING: Removing unreachable block (ram,0xf003952c) */
/* WARNING: Removing unreachable block (ram,0xf0039484) */
/* WARNING: Removing unreachable block (ram,0xf003945c) */
/* WARNING: Removing unreachable block (ram,0xf00393f0) */
/* WARNING: Removing unreachable block (ram,0xf003943c) */
/* WARNING: Removing unreachable block (ram,0xf0039448) */
/* WARNING: Removing unreachable block (ram,0xf00394d0) */
/* WARNING: Removing unreachable block (ram,0xf00394dc) */
/* WARNING: Removing unreachable block (ram,0xf00395b8) */
/* WARNING: Removing unreachable block (ram,0xf00394f0) */
/* WARNING: Removing unreachable block (ram,0xf00393c8) */

undefined8 _igmp_sendreport(undefined4 *param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
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
  puVar1 = param_1;
  _spltty();
  puVar2 = _mfree;
  if (_mfree == (undefined4 *)0x0) {
    puVar2 = (undefined4 *)0x0;
    _m_more(0,2);
  }
  else {
    if (*(sword *)((int)_mfree + 10) != 0) {
      _panic(&aMget_13);
    }
    *(undefined2 *)((int)puVar2 + 10) = 2;
    word_F0134B0C = word_F0134B0C + -1;
    DAT_f0134b10._0_2_ = DAT_f0134b10._0_2_ + 1;
    _mfree = (undefined4 *)*puVar2;
    puVar2[1] = 0xc;
    *puVar2 = 0;
  }
  _splx(puVar1);
  if (puVar2 != (undefined4 *)0x0) {
    _spltty();
    puVar3 = _mfree;
    if (_mfree == (undefined4 *)0x0) {
      puVar3 = (undefined4 *)0x0;
      _m_more(0,0xe);
    }
    else {
      if (*(sword *)((int)_mfree + 10) != 0) {
        _panic(&aMget_14);
      }
      *(undefined2 *)((int)puVar3 + 10) = 0xe;
      word_F0134B0C = word_F0134B0C + -1;
      DAT_f0134b10._24_2_ = DAT_f0134b10._24_2_ + 1;
      _mfree = (undefined4 *)*puVar3;
      puVar3[1] = 0xc;
      *puVar3 = 0;
    }
    _splx(puVar1);
    if (puVar3 == (undefined4 *)0x0) {
      _m_free(puVar2);
    }
    else {
      puVar2[1] = 0x74;
      *(undefined2 *)(puVar2 + 2) = 8;
      iVar5 = puVar2[1];
      *(undefined *)((int)puVar2 + iVar5) = 0x12;
      *(undefined *)((int)puVar2 + iVar5 + 1) = 0;
      *(undefined4 *)((int)puVar2 + iVar5 + 4) = *param_1;
      *(undefined2 *)((int)puVar2 + iVar5 + 2) = 0;
      puVar1 = puVar2;
      _in_cksum(puVar2,8);
      *(sword *)((int)puVar2 + iVar5 + 2) = (sword)puVar1;
      puVar2[1] = puVar2[1] + -0x14;
      *(sword *)(puVar2 + 2) = *(sword *)(puVar2 + 2) + 0x14;
      iVar4 = puVar2[1];
      *(undefined *)((int)puVar2 + iVar4 + 1) = 0;
      *(undefined2 *)((int)puVar2 + iVar4 + 2) = 0x1c;
      *(undefined2 *)((int)puVar2 + iVar4 + 6) = 0;
      *(undefined *)((int)puVar2 + iVar4 + 9) = 2;
      *(undefined4 *)((int)puVar2 + iVar4 + 0xc) = 0;
      *(undefined4 *)((int)puVar2 + iVar4 + 0x10) = *(undefined4 *)((int)puVar2 + iVar5 + 4);
      iVar4 = puVar3[1];
      *(undefined4 *)((int)puVar3 + iVar4) = param_1[1];
      *(undefined *)((int)puVar3 + iVar4 + 4) = 1;
      *(bool *)((int)puVar3 + iVar4 + 5) = _ip_mrouter != 0;
      _ip_output(puVar2,0,0,2,puVar3);
      _m_free(puVar3);
      DAT_f013a8c0._0_4_ = DAT_f013a8c0._0_4_ + 1;
    }
  }
  return CONCAT44(param_2,param_1);
}

