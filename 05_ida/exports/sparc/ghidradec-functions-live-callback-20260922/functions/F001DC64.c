
/* WARNING: Removing unreachable block (ram,0xf001dd1c) */
/* WARNING: Removing unreachable block (ram,0xf001dce0) */
/* WARNING: Removing unreachable block (ram,0xf001dc90) */
/* WARNING: Removing unreachable block (ram,0xf001dca8) */
/* WARNING: Removing unreachable block (ram,0xf001dd00) */
/* WARNING: Removing unreachable block (ram,0xf001dd34) */
/* WARNING: Removing unreachable block (ram,0xf001dc74) */

sqword _m_freem(undefined4 *param_1,uint param_2)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 unaff_l0;
  undefined4 *puVar4;
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
  if (param_1 != (undefined4 *)0x0) {
    puVar1 = param_1;
    _spltty();
    puVar2 = puVar1;
    do {
      _spltty();
      iVar3 = (int)*(sword *)((int)param_1 + 10);
      if (iVar3 == 0) {
        _panic(&aMfree_9);
        iVar3 = (int)*(sword *)((int)param_1 + 10);
      }
      (&word_F0134B0C)[iVar3] = (&word_F0134B0C)[iVar3] + -1;
      word_F0134B0C = word_F0134B0C + 1;
      *(undefined2 *)((int)param_1 + 10) = 0;
      if (0x7f < (uint)param_1[1]) {
        _mclput(param_1);
      }
      param_1[1] = 0;
      puVar4 = (undefined4 *)*param_1;
      param_1[0x1f] = 0;
      *param_1 = _mfree;
      _mfree = param_1;
      _splx(puVar2);
      puVar2 = (undefined4 *)0x0;
      if (_m_want != 0) {
        _m_want = 0;
        puVar2 = &_mfree;
        _wakeup();
      }
      param_1 = puVar4;
    } while (puVar4 != (undefined4 *)0x0);
    _splx(puVar1);
  }
  return (qword)param_2 << 0x20;
}

