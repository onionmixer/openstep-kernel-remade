
/* WARNING: Removing unreachable block (ram,0xf001dc54) */
/* WARNING: Removing unreachable block (ram,0xf001dc4c) */
/* WARNING: Removing unreachable block (ram,0xf001dbd4) */
/* WARNING: Removing unreachable block (ram,0xf001dbfc) */
/* WARNING: Removing unreachable block (ram,0xf001dbb8) */
/* WARNING: Removing unreachable block (ram,0xf001db80) */

undefined8 _m_more(int param_1,int param_2)

{
  int iVar1;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 *puVar2;
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
  do {
    iVar1 = param_1;
    _m_expand();
    if (iVar1 != 0) {
      _spltty();
      puVar2 = _mfree;
      if (_mfree == (undefined4 *)0x0) {
        _panic(&aMMore);
      }
      else {
        if (*(sword *)((int)_mfree + 10) != 0) {
          _panic(&aMget_1);
        }
        *(sword *)((int)puVar2 + 10) = (sword)param_2;
        word_F0134B0C = word_F0134B0C + -1;
        (&word_F0134B0C)[param_2] = (&word_F0134B0C)[param_2] + 1;
        _mfree = (undefined4 *)*puVar2;
        puVar2[1] = 0xc;
        *puVar2 = 0;
      }
      _splx(iVar1);
locret_F001DC5C:
      return CONCAT44(param_2,puVar2);
    }
    if (param_1 != 1) {
      puVar2 = (undefined4 *)0x0;
      DAT_f0134b00._0_4_ = DAT_f0134b00._0_4_ + 1;
      goto locret_F001DC5C;
    }
    DAT_f0134b00._4_4_ = DAT_f0134b00._4_4_ + 1;
    _m_want = _m_want + 1;
    _sleep(&_mfree,0x18);
  } while( true );
}
