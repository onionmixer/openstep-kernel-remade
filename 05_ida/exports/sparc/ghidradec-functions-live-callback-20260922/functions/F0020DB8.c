
/* WARNING: Removing unreachable block (ram,0xf0020e84) */
/* WARNING: Removing unreachable block (ram,0xf0020e2c) */
/* WARNING: Removing unreachable block (ram,0xf0020e64) */
/* WARNING: Removing unreachable block (ram,0xf0020ea0) */
/* WARNING: Removing unreachable block (ram,0xf0020e10) */

undefined8 _sbdroprecord(sword *param_1,undefined4 param_2)

{
  sword sVar1;
  word wVar2;
  int iVar3;
  int iVar4;
  undefined4 unaff_l0;
  undefined4 *puVar5;
  undefined4 unaff_l1;
  undefined4 *puVar6;
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
  puVar5 = *(undefined4 **)(param_1 + 6);
  if (puVar5 != (undefined4 *)0x0) {
    *(undefined4 *)(param_1 + 6) = puVar5[0x1f];
    sVar1 = *param_1;
    while( true ) {
      wVar2 = param_1[2];
      *param_1 = sVar1 - *(sword *)(puVar5 + 2);
      param_1[2] = wVar2 - 0x80;
      iVar3 = wVar2 - 0x480;
      if (0x7c < (uint)puVar5[1]) {
        param_1[2] = (sword)iVar3;
      }
      _spltty();
      iVar4 = (int)*(sword *)((int)puVar5 + 10);
      if (iVar4 == 0) {
        _panic(&aMfree_5);
        iVar4 = (int)*(sword *)((int)puVar5 + 10);
      }
      (&word_F0134B0C)[iVar4] = (&word_F0134B0C)[iVar4] + -1;
      word_F0134B0C = word_F0134B0C + 1;
      *(undefined2 *)((int)puVar5 + 10) = 0;
      if (0x7f < (uint)puVar5[1]) {
        _mclput(puVar5);
      }
      puVar5[1] = 0;
      puVar6 = (undefined4 *)*puVar5;
      puVar5[0x1f] = 0;
      *puVar5 = _mfree;
      _mfree = puVar5;
      _splx(iVar3);
      if (_m_want != 0) {
        _m_want = 0;
        _wakeup(&_mfree);
      }
      if (puVar6 == (undefined4 *)0x0) break;
      sVar1 = *param_1;
      puVar5 = puVar6;
    }
  }
  return CONCAT44(param_2,param_1);
}

