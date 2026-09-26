
/* WARNING: Removing unreachable block (ram,0xf002f5ec) */
/* WARNING: Removing unreachable block (ram,0xf002f524) */
/* WARNING: Removing unreachable block (ram,0xf002f4fc) */
/* WARNING: Removing unreachable block (ram,0xf002f4b4) */
/* WARNING: Removing unreachable block (ram,0xf002f570) */
/* WARNING: Removing unreachable block (ram,0xf002f57c) */
/* WARNING: Removing unreachable block (ram,0xf002f5f4) */
/* WARNING: Removing unreachable block (ram,0xf002f4a8) */

undefined8 _inet_queue(undefined4 param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  undefined *puVar2;
  uint uVar3;
  undefined4 *puVar4;
  undefined4 unaff_l0;
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
  bool bVar5;
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
  _netisr = _netisr | 4;
  _wakeup(_soft_net_wakeup);
  puVar2 = DAT_f0136400;
  _spltty();
  if (DAT_f0136488 < dword_F013648C) {
    uVar3 = param_2[1] - 0x10;
    if (uVar3 < 0x6d) {
      param_2[1] = param_2[1] + -4;
      *(sword *)(param_2 + 2) = *(sword *)(param_2 + 2) + 4;
      puVar4 = param_2;
loc_F002F5A0:
      bVar5 = puVar4 == (undefined4 *)0x0;
    }
    else {
      _spltty();
      puVar4 = _mfree;
      if (_mfree == (undefined4 *)0x0) {
        puVar4 = (undefined4 *)0x0;
        _m_more(0,2);
      }
      else {
        if (*(sword *)((int)_mfree + 10) != 0) {
          _panic(&aMget_7);
        }
        *(undefined2 *)((int)puVar4 + 10) = 2;
        word_F0134B0C = word_F0134B0C + -1;
        DAT_f0134b10._0_2_ = DAT_f0134b10._0_2_ + 1;
        _mfree = (undefined4 *)*puVar4;
        puVar4[1] = 0xc;
        *puVar4 = 0;
      }
      _splx(uVar3);
      bVar5 = puVar4 == (undefined4 *)0x0;
      if (!bVar5) {
        puVar4[1] = 0xc;
        *(undefined2 *)(puVar4 + 2) = 4;
        *puVar4 = param_2;
        goto loc_F002F5A0;
      }
    }
    if (!bVar5) {
      *(undefined4 *)((int)puVar4 + puVar4[1]) = param_1;
      puVar4[0x1f] = 0;
      puVar1 = puVar4;
      if (DAT_f0136484._0_4_ != (undefined4 *)0x0) {
        DAT_f0136484._0_4_[0x1f] = puVar4;
        puVar1 = _ipintrq;
      }
      _ipintrq = puVar1;
      DAT_f0136488 = DAT_f0136488 + 1;
      DAT_f0136484._0_4_ = puVar4;
      goto loc_F002F5F4;
    }
  }
  DAT_f0136490._0_4_ = DAT_f0136490._0_4_ + 1;
  _m_freem(param_2);
loc_F002F5F4:
  _splx(puVar2);
  return CONCAT44(param_2,param_1);
}
