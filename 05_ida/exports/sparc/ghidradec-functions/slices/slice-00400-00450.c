/* GHIDRADEC_FUNCTION index=400 start=0xf001d9f8 */

/* WARNING: Removing unreachable block (ram,0xf001da84) */
/* WARNING: Removing unreachable block (ram,0xf001da78) */
/* WARNING: Removing unreachable block (ram,0xf001da28) */
/* WARNING: Removing unreachable block (ram,0xf001da9c) */
/* WARNING: Removing unreachable block (ram,0xf001d9fc) */

undefined8 _m_getclr(undefined4 *param_1,int param_2)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
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
  puVar2 = param_1;
  _spltty();
  puVar1 = _mfree;
  if (_mfree == (undefined4 *)0x0) {
    _m_more(param_1,param_2);
  }
  else {
    if (*(sword *)((int)_mfree + 10) != 0) {
      _panic(&aMget_0);
    }
    *(sword *)((int)puVar1 + 10) = (sword)param_2;
    word_F0134B0C = word_F0134B0C + -1;
    (&word_F0134B0C)[param_2] = (&word_F0134B0C)[param_2] + 1;
    _mfree = (undefined4 *)*puVar1;
    puVar1[1] = 0xc;
    *puVar1 = 0;
    param_1 = puVar1;
  }
  _splx(puVar2);
  if (param_1 == (undefined4 *)0x0) {
    param_1 = (undefined4 *)0x0;
  }
  else {
    _bzero((int)param_1 + param_1[1],0x70);
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=401 start=0xf001dab4 */

/* WARNING: Removing unreachable block (ram,0xf001db3c) */
/* WARNING: Removing unreachable block (ram,0xf001dad4) */
/* WARNING: Removing unreachable block (ram,0xf001db14) */
/* WARNING: Removing unreachable block (ram,0xf001db5c) */
/* WARNING: Removing unreachable block (ram,0xf001dab8) */

undefined8 _m_free(undefined4 *param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  undefined4 unaff_l0;
  undefined4 uVar2;
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
  if (*(sword *)((int)param_1 + 10) == 0) {
    _panic(&aMfree);
  }
  (&word_F0134B0C)[*(sword *)((int)param_1 + 10)] =
       (&word_F0134B0C)[*(sword *)((int)param_1 + 10)] + -1;
  word_F0134B0C = word_F0134B0C + 1;
  *(undefined2 *)((int)param_1 + 10) = 0;
  if (0x7f < (uint)param_1[1]) {
    _mclput(param_1);
  }
  param_1[1] = 0;
  param_1[0x1f] = 0;
  uVar2 = *param_1;
  *param_1 = _mfree;
  _mfree = param_1;
  _splx(puVar1);
  if (_m_want != 0) {
    _m_want = 0;
    _wakeup(&_mfree);
  }
  return CONCAT44(param_2,uVar2);
}
/* GHIDRADEC_FUNCTION index=402 start=0xf001db6c */

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
/* GHIDRADEC_FUNCTION index=403 start=0xf001dc64 */

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
/* GHIDRADEC_FUNCTION index=404 start=0xf001dd44 */

/* WARNING: Removing unreachable block (ram,0xf001df00) */
/* WARNING: Removing unreachable block (ram,0xf001de80) */
/* WARNING: Removing unreachable block (ram,0xf001de74) */
/* WARNING: Removing unreachable block (ram,0xf001ddf0) */
/* WARNING: Removing unreachable block (ram,0xf001dd8c) */
/* WARNING: Removing unreachable block (ram,0xf001de00) */
/* WARNING: Removing unreachable block (ram,0xf001de28) */
/* WARNING: Removing unreachable block (ram,0xf001df34) */
/* WARNING: Removing unreachable block (ram,0xf001ded4) */
/* WARNING: Removing unreachable block (ram,0xf001dd68) */

undefined8 _m_copy(int *param_1,int param_2,int param_3)

{
  sword sVar1;
  undefined *puVar2;
  undefined4 *puVar3;
  int iVar4;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 *puVar5;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar6;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  undefined auStackX_0 [92];
  
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
  if (param_3 == 0) {
loc_F001DF3C:
    uVar6 = 0;
  }
  else {
    if ((param_2 < 0) || (param_3 < 0)) {
      _panic(&aMCopy);
    }
    for (; 0 < param_2; param_2 = param_2 - sVar1) {
      if (param_1 == (int *)0x0) {
        _panic(&aMCopy_1);
        sVar1 = sRam00000008;
      }
      else {
        sVar1 = *(sword *)(param_1 + 2);
      }
      if (param_2 < sVar1) break;
      param_1 = (int *)*param_1;
    }
    *(undefined4 *)((int)register0x00000038 + -0xc) = 0;
    if (0 < param_3) {
      puVar2 = DAT_f0134800;
      puVar5 = (undefined4 *)((int)register0x00000038 + -0xc);
      do {
        if (param_1 == (int *)0x0) {
          if (param_3 != 1000000000) {
            _panic(&aMCopy_0);
            uVar6 = *(undefined4 *)((int)register0x00000038 + -0xc);
            goto locret_F001DF40;
          }
          break;
        }
        _spltty();
        puVar3 = _mfree;
        if (_mfree == (undefined4 *)0x0) {
          puVar3 = (undefined4 *)0x0;
          _m_more(0,(int)*(sword *)((int)param_1 + 10));
        }
        else {
          if (*(sword *)((int)_mfree + 10) != 0) {
            _panic(&aMget_2);
          }
          *(undefined2 *)((int)puVar3 + 10) = *(undefined2 *)((int)param_1 + 10);
          word_F0134B0C = word_F0134B0C + -1;
          (&word_F0134B0C)[*(sword *)((int)param_1 + 10)] =
               (&word_F0134B0C)[*(sword *)((int)param_1 + 10)] + 1;
          _mfree = (undefined4 *)*puVar3;
          puVar3[1] = 0xc;
          *puVar3 = 0;
        }
        _splx(puVar2);
        *puVar5 = puVar3;
        if (puVar3 == (undefined4 *)0x0) {
          _m_freem(*(undefined4 *)((int)register0x00000038 + -0xc));
          goto loc_F001DF3C;
        }
        iVar4 = param_3;
        if (*(sword *)(param_1 + 2) - param_2 < param_3) {
          iVar4 = *(sword *)(param_1 + 2) - param_2;
        }
        *(sword *)(puVar3 + 2) = (sword)iVar4;
        if (((uint)param_1[1] < 0x7d) || ((sword)iVar4 < 0x71)) {
          puVar2 = (undefined *)((int)param_1 + param_2 + param_1[1]);
          _bcopy(puVar2,(int)puVar3 + puVar3[1],(int)*(sword *)(puVar3 + 2));
        }
        else {
          _mcldup(param_1,puVar3,param_2);
          puVar2 = (undefined *)(puVar3[1] + param_2);
          puVar3[1] = puVar2;
        }
        param_2 = 0;
        if (param_3 != 1000000000) {
          puVar2 = (undefined *)(int)*(sword *)(puVar3 + 2);
          param_3 = param_3 - (int)puVar2;
        }
        param_1 = (int *)*param_1;
        puVar5 = puVar3;
      } while (0 < param_3);
    }
    uVar6 = *(undefined4 *)((int)register0x00000038 + -0xc);
  }
locret_F001DF40:
  return CONCAT44(param_2,uVar6);
}
/* GHIDRADEC_FUNCTION index=405 start=0xf001df48 */

/* WARNING: Removing unreachable block (ram,0xf001dfc4) */
/* WARNING: Removing unreachable block (ram,0xf001dfac) */

undefined8 _m_cat(int *param_1,int param_2)

{
  int iVar1;
  uint uVar2;
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
  iVar1 = *param_1;
  while (iVar1 != 0) {
    param_1 = (int *)*param_1;
    iVar1 = *param_1;
  }
  if (param_2 != 0) {
    uVar2 = param_1[1];
    while (uVar2 < 0x7c) {
      if (0x7c < uVar2 + (int)*(sword *)(param_1 + 2) + (int)*(sword *)(param_2 + 8)) {
        *param_1 = param_2;
        goto locret_F001DFD8;
      }
      _bcopy(param_2 + *(int *)(param_2 + 4),(int)param_1 + (int)*(sword *)(param_1 + 2) + uVar2);
      *(sword *)(param_1 + 2) = *(sword *)(param_1 + 2) + *(sword *)(param_2 + 8);
      _m_free();
      if (param_2 == 0) goto locret_F001DFD8;
      uVar2 = param_1[1];
    }
    *param_1 = param_2;
  }
locret_F001DFD8:
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=406 start=0xf001dfe0 */

undefined8 _m_adj(int *param_1,int param_2)

{
  sword sVar1;
  int iVar2;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 unaff_i1;
  int iVar3;
  undefined4 unaff_i2;
  int *piVar4;
  int *piVar5;
  undefined4 unaff_i3;
  int iVar6;
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
  iVar3 = param_2;
  if (param_1 != (int *)0x0) {
    piVar4 = param_1;
    if (param_2 < 0) {
      iVar3 = -param_2;
      iVar6 = (int)*(sword *)(param_1 + 2);
      iVar2 = *param_1;
      while (iVar2 != 0) {
        piVar4 = (int *)*piVar4;
        iVar6 = iVar6 + *(sword *)(piVar4 + 2);
        iVar2 = *piVar4;
      }
      if (*(sword *)(piVar4 + 2) < iVar3) {
        iVar6 = iVar6 + param_2;
        piVar5 = param_1;
        piVar4 = param_1;
        if (param_1 != (int *)0x0) {
          while (piVar4 = piVar5 + 2, *(sword *)piVar4 < iVar6) {
            piVar5 = (int *)*piVar5;
            iVar6 = iVar6 - *(sword *)piVar4;
            piVar4 = piRam00000000;
            if (piVar5 == (int *)0x0) goto loc_F001E0C0;
          }
          *(sword *)(piVar5 + 2) = (sword)iVar6;
          piVar4 = piVar5;
        }
        while( true ) {
          piVar4 = (int *)*piVar4;
loc_F001E0C0:
          if (piVar4 == (int *)0x0) break;
          *(undefined2 *)(piVar4 + 2) = 0;
        }
      }
      else {
        *(sword *)(piVar4 + 2) = *(sword *)(piVar4 + 2) - (sword)iVar3;
      }
    }
    else {
      do {
        if (iVar3 < 1) break;
        sVar1 = *(sword *)(piVar4 + 2);
        if (iVar3 < sVar1) {
          *(sword *)(piVar4 + 2) = sVar1 - (sword)iVar3;
          piVar4[1] = piVar4[1] + iVar3;
          break;
        }
        *(undefined2 *)(piVar4 + 2) = 0;
        piVar4 = (int *)*piVar4;
        iVar3 = iVar3 - sVar1;
      } while (piVar4 != (int *)0x0);
    }
  }
  return CONCAT44(iVar3,param_1);
}
/* GHIDRADEC_FUNCTION index=407 start=0xf001e0d4 */

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
/* GHIDRADEC_FUNCTION index=408 start=0xf001e298 */

/* WARNING: Removing unreachable block (ram,0xf001e2bc) */
/* WARNING: Removing unreachable block (ram,0xf001e328) */
/* WARNING: Removing unreachable block (ram,0xf001e29c) */

undefined8 _mclget(int param_1,undefined4 param_2)

{
  int *piVar1;
  int iVar2;
  int iVar3;
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
  iVar2 = param_1;
  _spltty();
  if (_mclfree == (int *)0x0) {
    _m_clalloc(1,1,0);
  }
  piVar1 = _mclfree;
  if (_mclfree != (int *)0x0) {
    iVar3 = (int)_mclfree - _mbutl >> 10;
    _mclrefcnt[iVar3] = _mclrefcnt[iVar3] + '\x01';
    DAT_f0134afc._0_4_ = DAT_f0134afc._0_4_ + -1;
    _mclfree = (int *)*_mclfree;
    *(undefined2 *)(param_1 + 8) = 0x400;
    *(int *)(param_1 + 4) = (int)piVar1 - param_1;
    *(undefined2 *)(param_1 + 0xc) = 1;
  }
  _splx(iVar2);
  return CONCAT44(param_2,(uint)(piVar1 != (int *)0x0));
}
/* GHIDRADEC_FUNCTION index=409 start=0xf001e340 */

/* WARNING: Removing unreachable block (ram,0xf001e370) */
/* WARNING: Removing unreachable block (ram,0xf001e3bc) */
/* WARNING: Removing unreachable block (ram,0xf001e3c8) */
/* WARNING: Removing unreachable block (ram,0xf001e344) */

undefined8
_mclgetx(undefined4 param_1,undefined4 param_2,int param_3,undefined2 param_4,undefined4 *param_5)

{
  undefined4 *puVar1;
  undefined4 uVar2;
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
  uVar2 = param_1;
  _spltty();
  puVar1 = _mfree;
  if (_mfree == (undefined4 *)0x0) {
    _m_more(param_5,1);
  }
  else {
    if (*(sword *)((int)_mfree + 10) != 0) {
      _panic(&aMget_4);
    }
    *(undefined2 *)((int)puVar1 + 10) = 1;
    word_F0134B0C = word_F0134B0C + -1;
    DAT_f0134b0e._0_2_ = DAT_f0134b0e._0_2_ + 1;
    _mfree = (undefined4 *)*puVar1;
    puVar1[1] = 0xc;
    *puVar1 = 0;
    param_5 = puVar1;
  }
  _splx(uVar2);
  if (param_5 == (undefined4 *)0x0) {
    param_5 = (undefined4 *)0x0;
  }
  else {
    param_5[1] = param_3 - (int)param_5;
    *(undefined2 *)(param_5 + 2) = param_4;
    *(undefined2 *)(param_5 + 3) = 2;
    param_5[4] = param_1;
    param_5[5] = param_2;
    param_5[6] = 0;
  }
  return CONCAT44(param_2,param_5);
}
/* GHIDRADEC_FUNCTION index=410 start=0xf001e408 */

/* WARNING: Removing unreachable block (ram,0xf001e49c) */

undefined8 _mclput(undefined4 *param_1,undefined4 param_2)

{
  char cVar1;
  int iVar2;
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
  if (*(sword *)(param_1 + 3) == 1) {
    param_1 = (undefined4 *)((int)param_1 + param_1[1] & 0xfffffc00);
    iVar2 = (int)param_1 - _mbutl >> 10;
    cVar1 = _mclrefcnt[iVar2];
    _mclrefcnt[iVar2] = cVar1 + -1;
    if (cVar1 == '\x01') {
      *param_1 = _mclfree;
      DAT_f0134afc._0_4_ = DAT_f0134afc._0_4_ + 1;
      _mclfree = param_1;
    }
  }
  else if (*(sword *)(param_1 + 3) == 2) {
    (*(code *)param_1[4])(param_1[5]);
  }
  else {
    _panic(&aMclput);
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=411 start=0xf001e4c4 */

/* WARNING: Removing unreachable block (ram,0xf001e528) */
/* WARNING: Removing unreachable block (ram,0xf001e550) */
/* WARNING: Removing unreachable block (ram,0xf001e588) */

undefined8 _mcldup(int param_1,int param_2,int param_3)

{
  int *piVar1;
  int iVar2;
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
  if (*(sword *)(param_1 + 0xc) == 1) {
    iVar2 = param_1 + *(int *)(param_1 + 4);
    *(int *)(param_2 + 4) = iVar2 - param_2;
    *(undefined2 *)(param_2 + 0xc) = 1;
    iVar2 = iVar2 - _mbutl >> 10;
    _mclrefcnt[iVar2] = _mclrefcnt[iVar2] + '\x01';
  }
  else if (*(sword *)(param_1 + 0xc) == 2) {
    piVar1 = (int *)(*(sword *)(param_2 + 8) + 4);
    _kalloc();
    *piVar1 = *(sword *)(param_2 + 8) + 4;
    _bcopy(param_1 + *(int *)(param_1 + 4) + param_3,piVar1 + 1,(int)*(sword *)(param_2 + 8));
    *(int *)(param_2 + 4) = (int)piVar1 + (-param_3 - (param_2 + -4));
    *(undefined2 *)(param_2 + 0xc) = 2;
    *(code **)(param_2 + 0x10) = sub_F001E4AC;
    *(int **)(param_2 + 0x14) = piVar1;
    *(undefined4 *)(param_2 + 0x18) = 0;
  }
  else {
    _panic(&aMcldup);
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=412 start=0xf001e598 */

undefined8 _piconnect(int param_1,int param_2)

{
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
  *(undefined4 *)(*(int *)(param_1 + 8) + 0xc) = *(undefined4 *)(param_2 + 8);
  *(undefined4 *)(*(int *)(param_2 + 8) + 0xc) = *(undefined4 *)(param_1 + 8);
  *(undefined2 *)(param_1 + 0x3e) = 0x1000;
  *(undefined2 *)(param_1 + 0x42) = 0x2000;
  *(word *)(param_1 + 6) = *(word *)(param_1 + 6) | 0x22;
  *(undefined2 *)(param_2 + 0x26) = 0;
  *(undefined2 *)(param_2 + 0x2a) = 0;
  *(word *)(param_2 + 6) = *(word *)(param_2 + 6) | 0x12;
  return CONCAT44(param_2,1);
}
/* GHIDRADEC_FUNCTION index=413 start=0xf001e5ec */

/* WARNING: Removing unreachable block (ram,0xf001e644) */
/* WARNING: Removing unreachable block (ram,0xf001e600) */
/* WARNING: Removing unreachable block (ram,0xf001e6c8) */
/* WARNING: Removing unreachable block (ram,0xf001e610) */

undefined8 _socreate(sword *param_1,int *param_2,int param_3,int param_4)

{
  int iVar1;
  int iVar2;
  undefined4 unaff_l0;
  int iVar3;
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
  if (param_4 == 0) {
    _pffindtype(param_1,param_3);
  }
  else {
    _pffindproto(param_1,param_4,param_3);
  }
  if (param_1 == (sword *)0x0) {
    iVar1 = 0x2b;
  }
  else {
    iVar1 = 1;
    if (*param_1 == param_3) {
      _m_getclr(1,3);
      iVar2 = *(int *)(iVar1 + 4);
      iVar3 = iVar1 + iVar2;
      *(undefined2 *)(iVar3 + 2) = 0x20;
      *(undefined2 *)(iVar3 + 6) = 0;
      *(sword *)(iVar1 + iVar2) = (sword)param_3;
      if (*(sword *)(*(int *)(_active_u + 0x1c) + 2) == 0) {
        *(undefined2 *)(iVar3 + 6) = 0x80;
        *(sword **)(iVar3 + 0xc) = param_1;
      }
      else {
        *(sword **)(iVar3 + 0xc) = param_1;
      }
      iVar1 = iVar3;
      (**(code **)(param_1 + 0xe))(iVar3,0,0,param_4,0);
      if (iVar1 == 0) {
        *param_2 = iVar3;
        iVar1 = 0;
      }
      else {
        *(word *)(iVar3 + 6) = *(word *)(iVar3 + 6) | 1;
        _sofree();
      }
    }
    else {
      iVar1 = 0x29;
    }
  }
  return CONCAT44(param_2,iVar1);
}
/* GHIDRADEC_FUNCTION index=414 start=0xf001e6d8 */

/* WARNING: Removing unreachable block (ram,0xf001e70c) */
/* WARNING: Removing unreachable block (ram,0xf001e6dc) */

undefined8 _sobind(int param_1,undefined4 param_2)

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
  iVar1 = param_1;
  _splnet();
  (**(code **)(*(int *)(param_1 + 0xc) + 0x1c))(param_1,2,0,param_2,0);
  _splx(iVar1);
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=415 start=0xf001e71c */

/* WARNING: Removing unreachable block (ram,0xf001e758) */
/* WARNING: Removing unreachable block (ram,0xf001e7a0) */
/* WARNING: Removing unreachable block (ram,0xf001e720) */

undefined8 _solisten(int param_1,int param_2)

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
  int iVar2;
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
  iVar1 = param_1;
  _splnet();
  iVar2 = param_1;
  (**(code **)(*(int *)(param_1 + 0xc) + 0x1c))(param_1,3,0,0,0);
  if (iVar2 == 0) {
    if (*(int *)(param_1 + 0x1c) == 0) {
      *(int *)(param_1 + 0x1c) = param_1;
      *(int *)(param_1 + 0x14) = param_1;
      *(word *)(param_1 + 2) = *(word *)(param_1 + 2) | 2;
    }
    if (param_2 < 0) {
      param_2 = 0;
    }
    if (0x80 < param_2) {
      param_2 = 0x80;
    }
    *(sword *)(param_1 + 0x22) = (sword)param_2;
    _splx(iVar1);
    iVar2 = 0;
  }
  else {
    _splx(iVar1);
  }
  return CONCAT44(param_2,iVar2);
}
/* GHIDRADEC_FUNCTION index=416 start=0xf001e7b4 */

/* WARNING: Removing unreachable block (ram,0xf001e82c) */
/* WARNING: Removing unreachable block (ram,0xf001e818) */
/* WARNING: Removing unreachable block (ram,0xf001e800) */
/* WARNING: Removing unreachable block (ram,0xf001e824) */
/* WARNING: Removing unreachable block (ram,0xf001e834) */
/* WARNING: Removing unreachable block (ram,0xf001e7e8) */

undefined8 _sofree(uint param_1,undefined4 param_2)

{
  uint uVar1;
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
  if ((*(int *)(param_1 + 8) == 0) && ((*(word *)(param_1 + 6) & 1) != 0)) {
    if (*(int *)(param_1 + 0x10) != 0) {
      uVar1 = param_1;
      _soqremque(param_1,0);
      if (uVar1 == 0) {
        uVar1 = param_1;
        _soqremque(param_1,1);
        if (uVar1 == 0) {
          _panic(aSofreeDq);
          *(undefined4 *)(param_1 + 0x10) = 0;
        }
        else {
          *(undefined4 *)(param_1 + 0x10) = 0;
        }
      }
      else {
        *(undefined4 *)(param_1 + 0x10) = 0;
      }
    }
    _sbrelease(param_1 + 0x3c);
    _sorflush(param_1);
    _m_free(param_1 & 0xffffff80);
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=417 start=0xf001e844 */

/* WARNING: Removing unreachable block (ram,0xf001e97c) */
/* WARNING: Removing unreachable block (ram,0xf001e904) */
/* WARNING: Removing unreachable block (ram,0xf001e888) */
/* WARNING: Removing unreachable block (ram,0xf001e868) */
/* WARNING: Removing unreachable block (ram,0xf001e8c4) */
/* WARNING: Removing unreachable block (ram,0xf001e968) */
/* WARNING: Removing unreachable block (ram,0xf001e984) */
/* WARNING: Removing unreachable block (ram,0xf001e848) */

undefined8 _soclose(int param_1,undefined4 param_2)

{
  word wVar1;
  int iVar2;
  int iVar3;
  undefined4 unaff_l0;
  int iVar4;
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
  iVar4 = 0;
  iVar2 = param_1;
  _splnet();
  if ((*(word *)(param_1 + 2) & 2) != 0) {
    iVar3 = *(int *)(param_1 + 0x14);
    while (iVar3 != param_1) {
      _soabort(*(undefined4 *)(param_1 + 0x14));
      iVar3 = *(int *)(param_1 + 0x14);
    }
    iVar3 = *(int *)(param_1 + 0x1c);
    while (iVar3 != param_1) {
      _soabort(*(undefined4 *)(param_1 + 0x1c));
      iVar3 = *(int *)(param_1 + 0x1c);
    }
  }
  wVar1 = *(word *)(param_1 + 6);
  if (*(int *)(param_1 + 8) == 0) goto loc_F001E958;
  if ((wVar1 & 2) == 0) {
loc_F001E91C:
    iVar3 = *(int *)(param_1 + 8);
  }
  else if ((wVar1 & 8) == 0) {
    iVar4 = param_1;
    _sodisconnect();
    if (iVar4 == 0) {
      wVar1 = *(word *)(param_1 + 2);
      goto loc_F001E8DC;
    }
    iVar3 = *(int *)(param_1 + 8);
  }
  else {
    wVar1 = *(word *)(param_1 + 2);
loc_F001E8DC:
    if ((wVar1 & 0x80) == 0) {
      iVar3 = *(int *)(param_1 + 8);
    }
    else {
      if ((*(uint *)(param_1 + 4) & 0x108) != 0x108) {
        wVar1 = *(word *)(param_1 + 6);
        while ((wVar1 & 2) != 0) {
          _sleep(param_1 + 0x54,0x1a);
          wVar1 = *(word *)(param_1 + 6);
        }
        goto loc_F001E91C;
      }
      iVar3 = *(int *)(param_1 + 8);
    }
  }
  if ((iVar3 != 0) &&
     (iVar3 = param_1, (**(code **)(*(int *)(param_1 + 0xc) + 0x1c))(param_1,1,0,0,0), iVar4 == 0))
  {
    iVar4 = iVar3;
  }
  wVar1 = *(word *)(param_1 + 6);
loc_F001E958:
  if ((wVar1 & 1) == 0) {
    wVar1 = *(word *)(param_1 + 6);
  }
  else {
    _panic(aSocloseNofdref);
    wVar1 = *(word *)(param_1 + 6);
  }
  *(word *)(param_1 + 6) = wVar1 | 1;
  _sofree();
  _splx(iVar2);
  return CONCAT44(param_2,iVar4);
}
/* GHIDRADEC_FUNCTION index=418 start=0xf001e994 */

undefined8 _soabort(int param_1,undefined4 param_2)

{
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
  (**(code **)(*(int *)(param_1 + 0xc) + 0x1c))(param_1,10,0,0,0);
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=419 start=0xf001e9c0 */

/* WARNING: Removing unreachable block (ram,0xf001e9e0) */
/* WARNING: Removing unreachable block (ram,0xf001ea18) */
/* WARNING: Removing unreachable block (ram,0xf001e9c4) */

undefined8 _soaccept(int param_1,undefined4 param_2)

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
  iVar1 = param_1;
  _splnet();
  if ((*(word *)(param_1 + 6) & 1) == 0) {
    _panic(aSoacceptNofdre);
  }
  *(word *)(param_1 + 6) = *(word *)(param_1 + 6) & 0xfffe;
  (**(code **)(*(int *)(param_1 + 0xc) + 0x1c))(param_1,5,0,param_2,0);
  _splx(iVar1);
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=420 start=0xf001ea28 */

/* WARNING: Removing unreachable block (ram,0xf001ea70) */
/* WARNING: Removing unreachable block (ram,0xf001eab0) */
/* WARNING: Removing unreachable block (ram,0xf001ea44) */

undefined8 _soconnect(int param_1,undefined4 param_2)

{
  uint uVar1;
  int iVar2;
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
  uVar1 = (uint)*(word *)(param_1 + 2);
  if ((*(word *)(param_1 + 2) & 2) != 0) {
    param_1 = 0x2d;
    goto locret_F001EAB8;
  }
  _splnet();
  if ((*(word *)(param_1 + 6) & 6) == 0) {
loc_F001EA90:
    (**(code **)(*(int *)(param_1 + 0xc) + 0x1c))(param_1,4,0,param_2,0);
  }
  else if ((*(word *)(*(int *)(param_1 + 0xc) + 10) & 4) == 0) {
    iVar2 = param_1;
    _sodisconnect();
    if (iVar2 == 0) goto loc_F001EA90;
    param_1 = 0x38;
  }
  else {
    param_1 = 0x38;
  }
  _splx(uVar1);
locret_F001EAB8:
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=421 start=0xf001eac0 */

/* WARNING: Removing unreachable block (ram,0xf001eaf4) */
/* WARNING: Removing unreachable block (ram,0xf001eac4) */

undefined8 _soconnect2(int param_1,undefined4 param_2)

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
  iVar1 = param_1;
  _splnet();
  (**(code **)(*(int *)(param_1 + 0xc) + 0x1c))(param_1,0x11,0,param_2,0);
  _splx(iVar1);
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=422 start=0xf001eb04 */

/* WARNING: Removing unreachable block (ram,0xf001eb5c) */
/* WARNING: Removing unreachable block (ram,0xf001eb08) */

undefined8 _sodisconnect(int param_1,undefined4 param_2)

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
  iVar1 = param_1;
  _splnet();
  if ((*(word *)(param_1 + 6) & 2) == 0) {
    param_1 = 0x39;
  }
  else if ((*(word *)(param_1 + 6) & 8) == 0) {
    (**(code **)(*(int *)(param_1 + 0xc) + 0x1c))(param_1,6,0,0,0);
  }
  else {
    param_1 = 0x25;
  }
  _splx(iVar1);
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=423 start=0xf001eb6c */

/* WARNING: Removing unreachable block (ram,0xf001f090) */
/* WARNING: Removing unreachable block (ram,0xf001f018) */
/* WARNING: Removing unreachable block (ram,0xf001ef8c) */
/* WARNING: Removing unreachable block (ram,0xf001ee9c) */
/* WARNING: Removing unreachable block (ram,0xf001ee5c) */
/* WARNING: Removing unreachable block (ram,0xf001ee50) */
/* WARNING: Removing unreachable block (ram,0xf001edb8) */
/* WARNING: Removing unreachable block (ram,0xf001eda0) */
/* WARNING: Removing unreachable block (ram,0xf001ed6c) */
/* WARNING: Removing unreachable block (ram,0xf001ec54) */
/* WARNING: Removing unreachable block (ram,0xf001ed98) */
/* WARNING: Removing unreachable block (ram,0xf001eda8) */
/* WARNING: Removing unreachable block (ram,0xf001eddc) */
/* WARNING: Removing unreachable block (ram,0xf001ee08) */
/* WARNING: Removing unreachable block (ram,0xf001ee7c) */
/* WARNING: Removing unreachable block (ram,0xf001eee0) */
/* WARNING: Removing unreachable block (ram,0xf001efdc) */
/* WARNING: Removing unreachable block (ram,0xf001f078) */
/* WARNING: Removing unreachable block (ram,0xf001f0b0) */
/* WARNING: Removing unreachable block (ram,0xf001ec28) */

undefined8 _sosend(uint param_1,uint param_2,int param_3,uint param_4,int param_5)

{
  bool bVar1;
  int *piVar2;
  undefined *puVar3;
  uint uVar4;
  word wVar6;
  undefined4 *puVar5;
  undefined4 uVar7;
  int iVar8;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  int iVar9;
  int iVar10;
  undefined4 unaff_l3;
  uint uVar11;
  undefined4 unaff_l4;
  undefined4 *puVar12;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 unaff_i1;
  uint uVar13;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  undefined auStackX_0 [92];
  
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
  *(undefined4 *)((int)register0x00000038 + -0xc) = 0;
  iVar9 = 0;
  uVar11 = 0;
  bVar1 = true;
  if (((*(word *)(*(int *)(param_1 + 0xc) + 10) & 1) != 0) &&
     ((int)(uint)*(word *)(param_1 + 0x3e) < *(int *)(param_3 + 0x14))) {
    uVar11 = 0x28;
    uVar13 = param_2;
locret_F001F0BC:
    return CONCAT44(uVar13,uVar11);
  }
  uVar13 = 0;
  if (((param_4 & 4) != 0) && ((*(word *)(param_1 + 2) & 0x10) == 0)) {
    uVar13 = *(word *)(*(int *)(param_1 + 0xc) + 10) & 1;
  }
  _active_u[0x68] = _active_u[0x68] + 1;
  if (param_5 != 0) {
    iVar9 = (int)*(sword *)(param_5 + 8);
  }
  do {
    wVar6 = *(word *)(param_1 + 0x50);
loc_F001EC34:
    if ((wVar6 & 1) == 0) {
      *(word *)(param_1 + 0x50) = *(word *)(param_1 + 0x50) | 1;
      puVar3 = DAT_f0134800;
      do {
        _splnet();
        wVar6 = *(word *)(param_1 + 6);
        if ((wVar6 & 0x10) != 0) {
          uVar4 = 0x20;
          goto loc_F001ED6C;
        }
        uVar4 = (uint)*(word *)(param_1 + 0x56);
        if (uVar4 != 0) {
          *(undefined2 *)(param_1 + 0x56) = 0;
          goto loc_F001ED6C;
        }
        if ((wVar6 & 2) == 0) {
          if ((*(word *)(*(int *)(param_1 + 0xc) + 10) & 4) != 0) {
            uVar4 = 0x39;
            goto loc_F001ED6C;
          }
          if (param_2 == 0) {
            uVar4 = 0x27;
            goto loc_F001ED6C;
          }
        }
        iVar10 = 0x400;
        if ((param_4 & 1) == 0) {
          iVar10 = (uint)*(word *)(param_1 + 0x3e) - (uint)*(word *)(param_1 + 0x3c);
          iVar8 = (uint)*(word *)(param_1 + 0x42) - (uint)*(word *)(param_1 + 0x40);
          if (iVar8 < iVar10) {
            iVar10 = iVar8;
          }
          if (iVar10 <= iVar9) {
            wVar6 = *(word *)(param_1 + 6);
            goto loc_F001ED28;
          }
          iVar8 = *(int *)(param_3 + 0x14);
          if ((*(word *)(*(int *)(param_1 + 0xc) + 10) & 1) != 0) {
            if (iVar10 < iVar8 + iVar9) {
              wVar6 = *(word *)(param_1 + 6);
              goto loc_F001ED28;
            }
            iVar8 = *(int *)(param_3 + 0x14);
          }
          if ((((0x3ff < iVar8) && (iVar10 < 0x400)) && (0x3ff < *(word *)(param_1 + 0x3c))) &&
             ((wVar6 & 0x100) == 0)) goto loc_f001ed24;
        }
        _splx(puVar3);
        iVar10 = iVar10 - iVar9;
        if (0 < iVar10) {
          puVar3 = DAT_f0134800;
          puVar12 = (undefined4 *)((int)register0x00000038 + -0xc);
          do {
            _spltty();
            puVar5 = _mfree;
            if (_mfree == (undefined4 *)0x0) {
              puVar5 = (undefined4 *)0x1;
              _m_more(1,1);
            }
            else {
              if (*(sword *)((int)_mfree + 10) != 0) {
                _panic(&aMget_5);
              }
              *(undefined2 *)((int)puVar5 + 10) = 1;
              word_F0134B0C = word_F0134B0C + -1;
              DAT_f0134b0e._0_2_ = DAT_f0134b0e._0_2_ + 1;
              _mfree = (undefined4 *)*puVar5;
              puVar5[1] = 0xc;
              *puVar5 = 0;
            }
            _splx(puVar3);
            iVar9 = *(int *)(param_3 + 0x14);
            if ((iVar9 < 0x200) || (iVar10 < 0x400)) {
loc_F001EF40:
              iVar8 = iVar10;
              if (iVar9 < 0x71) {
                if (iVar9 < iVar10) {
                  iVar9 = *(int *)(param_3 + 0x14);
loc_F001EF68:
                  iVar8 = 0x70;
                  if (iVar9 < 0x71) {
                    iVar8 = iVar9;
                  }
                }
              }
              else if (0x70 < iVar10) {
                iVar9 = *(int *)(param_3 + 0x14);
                goto loc_F001EF68;
              }
              iVar10 = iVar10 - iVar8;
            }
            else {
              _spltty();
              if (_mclfree == (int *)0x0) {
                _m_clalloc(1,1,0);
              }
              piVar2 = _mclfree;
              if (_mclfree != (int *)0x0) {
                iVar8 = (int)_mclfree - _mbutl >> 10;
                _mclrefcnt[iVar8] = _mclrefcnt[iVar8] + '\x01';
                DAT_f0134afc._0_4_ = DAT_f0134afc._0_4_ + -1;
                _mclfree = (int *)*_mclfree;
              }
              _splx(iVar9);
              if (piVar2 == (int *)0x0) {
                *(undefined2 *)(puVar5 + 2) = 0x70;
              }
              else {
                puVar5[1] = (int)piVar2 - (int)puVar5;
                *(undefined2 *)(puVar5 + 2) = 0x400;
                *(undefined2 *)(puVar5 + 3) = 1;
              }
              iVar9 = *(int *)(param_3 + 0x14);
              if (*(sword *)(puVar5 + 2) != 0x400) goto loc_F001EF40;
              iVar8 = 0x400;
              if (iVar9 < 0x401) {
                iVar8 = iVar9;
              }
              iVar10 = iVar10 + -0x400;
            }
            uVar11 = (int)puVar5 + puVar5[1];
            _uiomove(uVar11,iVar8,1,param_3);
            *(sword *)(puVar5 + 2) = (sword)iVar8;
            *puVar12 = puVar5;
            if (uVar11 != 0) goto loc_F001F05C;
            puVar3 = *(undefined **)(param_3 + 0x14);
          } while ((0 < (int)puVar3) && (puVar12 = puVar5, 0 < iVar10));
        }
        if (uVar13 != 0) {
          puVar3 = (undefined *)(*(word *)(param_1 + 2) | 0x10);
          *(sword *)(param_1 + 2) = (sword)puVar3;
        }
        _splnet();
        uVar7 = 9;
        if ((param_4 & 1) != 0) {
          uVar7 = 0xe;
        }
        uVar11 = param_1;
        (**(code **)(*(int *)(param_1 + 0xc) + 0x1c))
                  (param_1,uVar7,*(undefined4 *)((int)register0x00000038 + -0xc),param_2,param_5);
        _splx(puVar3);
        param_5 = 0;
        if (uVar13 != 0) {
          *(word *)(param_1 + 2) = *(word *)(param_1 + 2) & 0xffef;
        }
        iVar9 = 0;
        *(undefined4 *)((int)register0x00000038 + -0xc) = 0;
        bVar1 = false;
        if ((uVar11 != 0) || (puVar3 = *(undefined **)(param_3 + 0x14), puVar3 == (undefined *)0x0))
        {
loc_F001F05C:
          wVar6 = *(word *)(param_1 + 0x50);
          goto loc_F001F060;
        }
      } while( true );
    }
    *(word *)(param_1 + 0x50) = wVar6 | 2;
    _sleep(param_1 + 0x50,0x1a);
  } while( true );
loc_f001ed24:
  wVar6 = *(word *)(param_1 + 6);
loc_F001ED28:
  if ((wVar6 & 0x100) != 0) {
    uVar4 = uVar11;
    if (((bVar1) && (uVar4 = 0x23, (*(uint *)(*_active_u + 0x14) & 0x4000) != 0)) &&
       ((*(word *)(param_3 + 0x10) & 0x2000) != 0)) {
      uVar4 = 0xb;
    }
loc_F001ED6C:
    _splx(puVar3);
    wVar6 = *(word *)(param_1 + 0x50);
    uVar11 = uVar4;
loc_F001F060:
    *(word *)(param_1 + 0x50) = wVar6 & 0xfffe;
    if ((wVar6 & 2) != 0) {
      *(word *)(param_1 + 0x50) = wVar6 & 0xfffc;
      _wakeup(param_1 + 0x50);
    }
    if (*(int *)((int)register0x00000038 + -0xc) != 0) {
      _m_freem();
    }
    if (uVar11 == 0x20) {
      _exception_from_kernel(5,0x10001,0);
    }
    goto locret_F001F0BC;
  }
  wVar6 = *(word *)(param_1 + 0x50);
  *(word *)(param_1 + 0x50) = wVar6 & 0xfffe;
  if ((wVar6 & 2) != 0) {
    *(word *)(param_1 + 0x50) = wVar6 & 0xfffc;
    _wakeup(param_1 + 0x50);
  }
  _sbwait(param_1 + 0x3c);
  _splx(puVar3);
  wVar6 = *(word *)(param_1 + 0x50);
  goto loc_F001EC34;
}
/* GHIDRADEC_FUNCTION index=424 start=0xf001f0c4 */

/* WARNING: Removing unreachable block (ram,0xf001f158) */
/* WARNING: Removing unreachable block (ram,0xf001f0f4) */
/* WARNING: Removing unreachable block (ram,0xf001f2a4) */
/* WARNING: Removing unreachable block (ram,0xf001f914) */
/* WARNING: Removing unreachable block (ram,0xf001f868) */
/* WARNING: Removing unreachable block (ram,0xf001f764) */
/* WARNING: Removing unreachable block (ram,0xf001f700) */
/* WARNING: Removing unreachable block (ram,0xf001f684) */
/* WARNING: Removing unreachable block (ram,0xf001f660) */
/* WARNING: Removing unreachable block (ram,0xf001f5b4) */
/* WARNING: Removing unreachable block (ram,0xf001f568) */
/* WARNING: Removing unreachable block (ram,0xf001f50c) */
/* WARNING: Removing unreachable block (ram,0xf001f440) */
/* WARNING: Removing unreachable block (ram,0xf001f3f4) */
/* WARNING: Removing unreachable block (ram,0xf001f398) */
/* WARNING: Removing unreachable block (ram,0xf001f310) */
/* WARNING: Removing unreachable block (ram,0xf001f2e4) */
/* WARNING: Removing unreachable block (ram,0xf001f330) */
/* WARNING: Removing unreachable block (ram,0xf001f3b4) */
/* WARNING: Removing unreachable block (ram,0xf001f420) */
/* WARNING: Removing unreachable block (ram,0xf001f488) */
/* WARNING: Removing unreachable block (ram,0xf001f528) */
/* WARNING: Removing unreachable block (ram,0xf001f594) */
/* WARNING: Removing unreachable block (ram,0xf001f4a8) */
/* WARNING: Removing unreachable block (ram,0xf001f618) */
/* WARNING: Removing unreachable block (ram,0xf001f67c) */
/* WARNING: Removing unreachable block (ram,0xf001f6e4) */
/* WARNING: Removing unreachable block (ram,0xf001f740) */
/* WARNING: Removing unreachable block (ram,0xf001f784) */
/* WARNING: Removing unreachable block (ram,0xf001f90c) */
/* WARNING: Removing unreachable block (ram,0xf001f29c) */
/* WARNING: Removing unreachable block (ram,0xf001f2ac) */
/* WARNING: Removing unreachable block (ram,0xf001f14c) */
/* WARNING: Removing unreachable block (ram,0xf001f190) */
/* WARNING: Removing unreachable block (ram,0xf001f1a4) */
/* WARNING: Removing unreachable block (ram,0xf001f1c4) */

undefined8 _soreceive(uint param_1,undefined4 *param_2,int param_3,uint param_4,uint *param_5)

{
  sword sVar1;
  int iVar2;
  uint uVar3;
  undefined4 *puVar4;
  int iVar5;
  word wVar6;
  code *pcVar7;
  undefined4 unaff_l0;
  undefined4 *puVar8;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  uint uVar9;
  undefined4 unaff_l4;
  int iVar10;
  undefined4 unaff_l5;
  undefined4 uVar11;
  undefined4 unaff_l6;
  int iVar12;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool bVar13;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  undefined auStackX_0 [92];
  
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
  uVar9 = 0;
  iVar12 = *(int *)(param_1 + 0xc);
  if (param_5 != (uint *)0x0) {
    *param_5 = 0;
  }
  if (param_2 != (undefined4 *)0x0) {
    *param_2 = 0;
  }
  iVar2 = 1;
  if ((param_4 & 1) == 0) {
    do {
      wVar6 = *(word *)(param_1 + 0x38);
      while ((wVar6 & 1) == 0) {
        uVar3 = *(word *)(param_1 + 0x38) | 1;
        *(sword *)(param_1 + 0x38) = (sword)uVar3;
        _splnet();
        sVar1 = *(sword *)(param_1 + 0x24);
        *(uint *)((int)register0x00000038 + -0xc) = uVar3;
        if (sVar1 != 0) {
          _active_u[0x69] = _active_u[0x69] + 1;
          puVar8 = *(undefined4 **)(param_1 + 0x30);
          if (puVar8 == (undefined4 *)0x0) {
            _panic(aReceive1);
            wVar6 = *(word *)(iVar12 + 10);
          }
          else {
            wVar6 = *(word *)(iVar12 + 10);
          }
          uVar11 = puVar8[0x1f];
          if ((wVar6 & 2) == 0) {
loc_F001F458:
            bVar13 = puVar8 == (undefined4 *)0x0;
          }
          else {
            if (*(sword *)((int)puVar8 + 10) != 8) {
              _panic(aReceive1a);
            }
            if ((param_4 & 2) != 0) {
              if (param_2 != (undefined4 *)0x0) {
                puVar4 = puVar8;
                _m_copy(puVar8,0,(int)*(sword *)(puVar8 + 2));
                *param_2 = puVar4;
              }
              puVar8 = (undefined4 *)*puVar8;
              goto loc_F001F458;
            }
            wVar6 = *(word *)(param_1 + 0x28);
            *(sword *)(param_1 + 0x24) = *(sword *)(param_1 + 0x24) - *(sword *)(puVar8 + 2);
            *(word *)(param_1 + 0x28) = wVar6 - 0x80;
            iVar2 = wVar6 - 0x480;
            if (0x7c < (uint)puVar8[1]) {
              *(sword *)(param_1 + 0x28) = (sword)iVar2;
            }
            if (param_2 == (undefined4 *)0x0) {
              _spltty();
              if (*(sword *)((int)puVar8 + 10) == 0) {
                _panic(&aMfree_0);
              }
              (&word_F0134B0C)[*(sword *)((int)puVar8 + 10)] =
                   (&word_F0134B0C)[*(sword *)((int)puVar8 + 10)] + -1;
              word_F0134B0C = word_F0134B0C + 1;
              *(undefined2 *)((int)puVar8 + 10) = 0;
              if (0x7f < (uint)puVar8[1]) {
                _mclput(puVar8);
              }
              *(undefined4 *)(param_1 + 0x30) = *puVar8;
              *puVar8 = _mfree;
              puVar8[1] = 0;
              puVar8[0x1f] = 0;
              _mfree = puVar8;
              _splx(iVar2);
              if (_m_want == 0) {
                puVar8 = *(undefined4 **)(param_1 + 0x30);
              }
              else {
                _m_want = 0;
                _wakeup(&_mfree);
                puVar8 = *(undefined4 **)(param_1 + 0x30);
              }
            }
            else {
              *param_2 = puVar8;
              puVar8 = (undefined4 *)*puVar8;
              *(undefined4 *)*param_2 = 0;
              *(undefined4 **)(param_1 + 0x30) = puVar8;
            }
            if (puVar8 == (undefined4 *)0x0) goto loc_F001F458;
            puVar8[0x1f] = uVar11;
            bVar13 = false;
          }
          if ((!bVar13) &&
             (bVar13 = puVar8 == (undefined4 *)0x0, *(sword *)((int)puVar8 + 10) == 0xc)) {
            if ((*(word *)(iVar12 + 10) & 0x10) == 0) {
              _panic(aReceive2);
            }
            if ((param_4 & 2) == 0) {
              wVar6 = *(word *)(param_1 + 0x28);
              *(sword *)(param_1 + 0x24) = *(sword *)(param_1 + 0x24) - *(sword *)(puVar8 + 2);
              *(word *)(param_1 + 0x28) = wVar6 - 0x80;
              iVar2 = wVar6 - 0x480;
              if (0x7c < (uint)puVar8[1]) {
                *(sword *)(param_1 + 0x28) = (sword)iVar2;
              }
              if (param_5 == (uint *)0x0) {
                _spltty();
                if (*(sword *)((int)puVar8 + 10) == 0) {
                  _panic(&aMfree_1);
                }
                (&word_F0134B0C)[*(sword *)((int)puVar8 + 10)] =
                     (&word_F0134B0C)[*(sword *)((int)puVar8 + 10)] + -1;
                word_F0134B0C = word_F0134B0C + 1;
                *(undefined2 *)((int)puVar8 + 10) = 0;
                if (0x7f < (uint)puVar8[1]) {
                  _mclput(puVar8);
                }
                *(undefined4 *)(param_1 + 0x30) = *puVar8;
                *puVar8 = _mfree;
                puVar8[1] = 0;
                puVar8[0x1f] = 0;
                _mfree = puVar8;
                _splx(iVar2);
                if (_m_want != 0) {
                  _m_want = 0;
                  _wakeup(&_mfree);
                  goto loc_F001F5BC;
                }
                puVar8 = *(undefined4 **)(param_1 + 0x30);
              }
              else {
                *param_5 = (uint)puVar8;
                *(undefined4 *)(param_1 + 0x30) = *puVar8;
                *puVar8 = 0;
loc_F001F5BC:
                puVar8 = *(undefined4 **)(param_1 + 0x30);
              }
              if (puVar8 != (undefined4 *)0x0) {
                puVar8[0x1f] = uVar11;
              }
            }
            else {
              if (param_5 != (uint *)0x0) {
                puVar4 = puVar8;
                _m_copy(puVar8,0,(int)*(sword *)(puVar8 + 2));
                *param_5 = (uint)puVar4;
              }
              puVar8 = (undefined4 *)*puVar8;
            }
            bVar13 = puVar8 == (undefined4 *)0x0;
          }
          iVar2 = 0;
          iVar10 = 0;
          if ((bVar13) || (*(int *)(param_3 + 0x14) < 1)) goto loc_F001F840;
          sVar1 = *(sword *)((int)puVar8 + 10);
          goto loc_F001F600;
        }
        uVar3 = (uint)*(word *)(param_1 + 0x56);
        if (uVar3 != 0) {
          *(undefined2 *)(param_1 + 0x56) = 0;
          goto loc_F001F8F0;
        }
        if ((*(word *)(param_1 + 6) & 0x20) != 0) {
          wVar6 = *(word *)(param_1 + 0x38);
          goto loc_F001F8F4;
        }
        if ((*(word *)(param_1 + 6) & 2) == 0) {
          if ((*(word *)(*(int *)(param_1 + 0xc) + 10) & 4) != 0) {
            uVar3 = 0x39;
            goto loc_F001F8F0;
          }
          iVar2 = *(int *)(param_3 + 0x14);
        }
        else {
          iVar2 = *(int *)(param_3 + 0x14);
        }
        if (iVar2 == 0) {
          wVar6 = *(word *)(param_1 + 0x38);
          goto loc_F001F8F4;
        }
        if ((*(word *)(param_1 + 6) & 0x100) != 0) {
          uVar3 = 0x23;
          if ((*(uint *)(*_active_u + 0x14) & 0x4000) == 0) goto loc_F001F8F0;
          if ((*(word *)(param_3 + 0x10) & 0x2000) != 0) {
            uVar3 = 0xb;
            goto loc_F001F8F0;
          }
          wVar6 = *(word *)(param_1 + 0x38);
          uVar9 = uVar3;
          goto loc_F001F8F4;
        }
        wVar6 = *(word *)(param_1 + 0x38);
        *(word *)(param_1 + 0x38) = wVar6 & 0xfffe;
        if ((wVar6 & 2) != 0) {
          *(word *)(param_1 + 0x38) = wVar6 & 0xfffc;
          _wakeup(param_1 + 0x38);
        }
        _sbwait(param_1 + 0x24);
        _splx(*(undefined4 *)((int)register0x00000038 + -0xc));
        wVar6 = *(word *)(param_1 + 0x38);
      }
      *(word *)(param_1 + 0x38) = wVar6 | 2;
      _sleep(param_1 + 0x38,0x1a);
    } while( true );
  }
  _m_get(1,1);
  (**(code **)(iVar12 + 0x1c))(param_1,0xd,iVar2,param_4 & 2,0);
  if (param_1 == 0) {
    param_2 = *(undefined4 **)(param_3 + 0x14);
    while( true ) {
      if ((int)*(sword *)(iVar2 + 8) < (int)param_2) {
        param_2 = (undefined4 *)(int)*(sword *)(iVar2 + 8);
      }
      param_1 = iVar2 + *(int *)(iVar2 + 4);
      _uiomove(param_1,param_2,0,param_3);
      _m_free();
      if (((*(int *)(param_3 + 0x14) == 0) || (param_1 != 0)) || (iVar2 == 0)) break;
      param_2 = *(undefined4 **)(param_3 + 0x14);
    }
  }
  uVar9 = param_1;
  if (iVar2 != 0) {
    _m_freem(iVar2);
  }
  goto locret_F001F91C;
loc_F001F600:
  if (1 < (word)(sVar1 - 1U)) {
    _panic(aReceive3);
  }
  param_2 = *(undefined4 **)(param_3 + 0x14);
  *(word *)(param_1 + 6) = *(word *)(param_1 + 6) & 0xffbf;
  if ((*(word *)(param_1 + 0x58) != 0) &&
     (puVar4 = (undefined4 *)((uint)*(word *)(param_1 + 0x58) - iVar10), (int)puVar4 < (int)param_2)
     ) {
    param_2 = puVar4;
  }
  if (*(sword *)(puVar8 + 2) - iVar2 < (int)param_2) {
    param_2 = (undefined4 *)(*(sword *)(puVar8 + 2) - iVar2);
  }
  _splx(*(undefined4 *)((int)register0x00000038 + -0xc));
  uVar9 = (int)puVar8 + iVar2 + puVar8[1];
  _uiomove(uVar9,param_2,0,param_3);
  uVar3 = uVar9;
  _splnet();
  sVar1 = *(sword *)(puVar8 + 2);
  *(uint *)((int)register0x00000038 + -0xc) = uVar3;
  bVar13 = (param_4 & 2) != 0;
  if (param_2 == (undefined4 *)(sVar1 - iVar2)) {
    if (bVar13) {
      puVar8 = (undefined4 *)*puVar8;
      iVar2 = 0;
      goto loc_F001F7D4;
    }
    uVar11 = puVar8[0x1f];
    wVar6 = *(word *)(param_1 + 0x28);
    *(sword *)(param_1 + 0x24) = *(sword *)(param_1 + 0x24) - sVar1;
    *(word *)(param_1 + 0x28) = wVar6 - 0x80;
    iVar5 = wVar6 - 0x480;
    if (0x7c < (uint)puVar8[1]) {
      *(sword *)(param_1 + 0x28) = (sword)iVar5;
    }
    _spltty();
    if (*(sword *)((int)puVar8 + 10) == 0) {
      _panic(&aMfree_2);
    }
    (&word_F0134B0C)[*(sword *)((int)puVar8 + 10)] =
         (&word_F0134B0C)[*(sword *)((int)puVar8 + 10)] + -1;
    word_F0134B0C = word_F0134B0C + 1;
    *(undefined2 *)((int)puVar8 + 10) = 0;
    if (0x7f < (uint)puVar8[1]) {
      _mclput(puVar8);
    }
    *(undefined4 *)(param_1 + 0x30) = *puVar8;
    *puVar8 = _mfree;
    puVar8[1] = 0;
    puVar8[0x1f] = 0;
    _mfree = puVar8;
    _splx(iVar5);
    if (_m_want == 0) {
      puVar8 = *(undefined4 **)(param_1 + 0x30);
    }
    else {
      _m_want = 0;
      _wakeup(&_mfree);
      puVar8 = *(undefined4 **)(param_1 + 0x30);
    }
    if (puVar8 != (undefined4 *)0x0) {
      puVar8[0x1f] = uVar11;
      goto loc_F001F7D4;
    }
    wVar6 = *(word *)(param_1 + 0x58);
  }
  else {
    if (bVar13) {
      iVar2 = iVar2 + (int)param_2;
    }
    else {
      puVar8[1] = puVar8[1] + (int)param_2;
      *(sword *)(puVar8 + 2) = *(sword *)(puVar8 + 2) - (sword)param_2;
      *(sword *)(param_1 + 0x24) = *(sword *)(param_1 + 0x24) - (sword)param_2;
    }
loc_F001F7D4:
    wVar6 = *(word *)(param_1 + 0x58);
  }
  if (wVar6 == 0) {
loc_F001F81C:
    if (((puVar8 == (undefined4 *)0x0) || (*(int *)(param_3 + 0x14) < 1)) || (uVar9 != 0))
    goto loc_F001F840;
    sVar1 = *(sword *)((int)puVar8 + 10);
    goto loc_F001F600;
  }
  if ((param_4 & 2) != 0) {
    iVar10 = iVar10 + (int)param_2;
    goto loc_F001F81C;
  }
  uVar3 = (uint)wVar6 - (int)param_2;
  *(sword *)(param_1 + 0x58) = (sword)uVar3;
  if ((uVar3 & 0xffff) != 0) goto loc_F001F81C;
  *(word *)(param_1 + 6) = *(word *)(param_1 + 6) | 0x40;
loc_F001F840:
  if ((param_4 & 2) == 0) {
    if (puVar8 == (undefined4 *)0x0) {
      *(undefined4 *)(param_1 + 0x30) = uVar11;
loc_F001F870:
      wVar6 = *(word *)(iVar12 + 10);
    }
    else {
      if ((*(word *)(iVar12 + 10) & 1) != 0) {
        _sbdroprecord(param_1 + 0x24);
        goto loc_F001F870;
      }
      wVar6 = *(word *)(iVar12 + 10);
    }
    if (((wVar6 & 8) != 0) && (*(int *)(param_1 + 8) != 0)) {
      (**(code **)(iVar12 + 0x1c))(param_1,8,0,0,0);
    }
    if (uVar9 == 0) {
      if (param_5 == (uint *)0x0) {
        wVar6 = *(word *)(param_1 + 0x38);
      }
      else {
        uVar3 = *param_5;
        if (uVar3 == 0) {
          wVar6 = *(word *)(param_1 + 0x38);
        }
        else {
          pcVar7 = *(code **)(*(int *)(iVar12 + 4) + 0xc);
          if (pcVar7 == (code *)0x0) {
            wVar6 = *(word *)(param_1 + 0x38);
          }
          else {
            (*pcVar7)(uVar3);
loc_F001F8F0:
            wVar6 = *(word *)(param_1 + 0x38);
            uVar9 = uVar3;
          }
        }
      }
    }
    else {
      wVar6 = *(word *)(param_1 + 0x38);
    }
  }
  else {
    wVar6 = *(word *)(param_1 + 0x38);
  }
loc_F001F8F4:
  *(word *)(param_1 + 0x38) = wVar6 & 0xfffe;
  if ((wVar6 & 2) != 0) {
    *(word *)(param_1 + 0x38) = wVar6 & 0xfffc;
    _wakeup(param_1 + 0x38);
  }
  _splx(*(undefined4 *)((int)register0x00000038 + -0xc));
locret_F001F91C:
  return CONCAT44(param_2,uVar9);
}
/* GHIDRADEC_FUNCTION index=425 start=0xf001f924 */

/* WARNING: Removing unreachable block (ram,0xf001f938) */

undefined8 _soshutdown(int param_1,int param_2)

{
  undefined4 unaff_l0;
  int iVar1;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 unaff_i1;
  uint uVar2;
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
  uVar2 = param_2 + 1;
  iVar1 = *(int *)(param_1 + 0xc);
  if ((uVar2 & 1) != 0) {
    _sorflush(param_1);
  }
  if ((uVar2 & 2) == 0) {
    param_1 = 0;
  }
  else {
    (**(code **)(iVar1 + 0x1c))(param_1,7,0,0,0);
  }
  return CONCAT44(uVar2,param_1);
}
/* GHIDRADEC_FUNCTION index=426 start=0xf001f978 */

/* WARNING: Removing unreachable block (ram,0xf001fa34) */
/* WARNING: Removing unreachable block (ram,0xf001f9f0) */
/* WARNING: Removing unreachable block (ram,0xf001f9c0) */
/* WARNING: Removing unreachable block (ram,0xf001f9cc) */
/* WARNING: Removing unreachable block (ram,0xf001fa2c) */
/* WARNING: Removing unreachable block (ram,0xf001fa68) */
/* WARNING: Removing unreachable block (ram,0xf001f9a0) */

undefined8 _sorflush(int param_1,undefined4 param_2)

{
  word wVar1;
  uint uVar2;
  code *pcVar3;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  int iVar4;
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
  undefined auStackX_0 [92];
  
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
  iVar4 = *(int *)(param_1 + 0xc);
  wVar1 = *(word *)(param_1 + 0x38);
  while ((wVar1 & 1) != 0) {
    *(word *)(param_1 + 0x38) = *(word *)(param_1 + 0x38) | 2;
    _sleep(param_1 + 0x38,0x1a);
    wVar1 = *(word *)(param_1 + 0x38);
  }
  uVar2 = *(word *)(param_1 + 0x38) | 1;
  *(sword *)(param_1 + 0x38) = (sword)uVar2;
  _spltty();
  _socantrcvmore(param_1);
  wVar1 = *(word *)(param_1 + 0x38);
  *(word *)(param_1 + 0x38) = wVar1 & 0xfffe;
  if ((wVar1 & 2) != 0) {
    *(word *)(param_1 + 0x38) = wVar1 & 0xfffc;
    _wakeup(param_1 + 0x38);
  }
  *(undefined4 *)((int)register0x00000038 + -0x20) = *(undefined4 *)(param_1 + 0x24);
  *(undefined4 *)((int)register0x00000038 + -0x1c) = *(undefined4 *)(param_1 + 0x28);
  *(undefined4 *)((int)register0x00000038 + -0x18) = *(undefined4 *)(param_1 + 0x2c);
  *(undefined4 *)((int)register0x00000038 + -0x14) = *(undefined4 *)(param_1 + 0x30);
  *(undefined4 *)((int)register0x00000038 + -0x10) = *(undefined4 *)(param_1 + 0x34);
  *(undefined4 *)((int)register0x00000038 + -0xc) = *(undefined4 *)(param_1 + 0x38);
  _bzero((undefined4 *)(param_1 + 0x24),0x18);
  _splx(uVar2);
  if (((*(word *)(iVar4 + 10) & 0x10) != 0) &&
     (pcVar3 = *(code **)(*(int *)(iVar4 + 4) + 0x10), pcVar3 != (code *)0x0)) {
    (*pcVar3)(*(undefined4 *)((int)register0x00000038 + -0x14));
  }
  _sbrelease((undefined *)((int)register0x00000038 + -0x20));
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=427 start=0xf001fa78 */

/* WARNING: Removing unreachable block (ram,0xf001fcd4) */
/* WARNING: Removing unreachable block (ram,0xf001fc68) */

undefined8 _sosetopt(int param_1,int param_2,int param_3,int param_4)

{
  code *pcVar1;
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
  undefined4 uVar2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  undefined auStackX_0 [92];
  
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
  *(int *)((int)register0x00000038 + 0x50) = param_4;
  uVar2 = 0;
  if (param_2 != 0xffff) {
    if (*(int *)(param_1 + 0xc) == 0) {
      uVar2 = 0x2a;
    }
    else {
      pcVar1 = *(code **)(*(int *)(param_1 + 0xc) + 0x18);
      uVar2 = 1;
      if (pcVar1 != (code *)0x0) {
        (*pcVar1)(1,param_1,param_2,param_3,(undefined *)((int)register0x00000038 + 0x50));
        goto locret_F001FCE0;
      }
      uVar2 = 0x2a;
    }
    goto loc_F001FCCC;
  }
  if (param_3 == 0x20) {
loc_F001FBA4:
    if (param_4 == 0) {
      uVar2 = 0x16;
    }
    else if (*(word *)(param_4 + 8) < 4) {
      uVar2 = 0x16;
    }
    else if (*(int *)(param_4 + *(int *)(param_4 + 4)) == 0) {
      *(word *)(param_1 + 2) = *(word *)(param_1 + 2) & ~(word)param_3;
    }
    else {
      *(word *)(param_1 + 2) = *(word *)(param_1 + 2) | (word)param_3;
    }
  }
  else {
    if (0x20 < param_3) {
      if (param_3 != 0x100) {
        if (param_3 < 0x101) {
          if (param_3 == 0x40) goto loc_F001FBA4;
          if (param_3 == 0x80) {
            if (param_4 == 0) {
              uVar2 = 0x16;
            }
            else {
              if (*(sword *)(param_4 + 8) == 8) {
                *(sword *)(param_1 + 4) =
                     (sword)*(undefined4 *)(param_4 + *(int *)(param_4 + 4) + 4);
                goto loc_F001FBA4;
              }
              uVar2 = 0x16;
            }
          }
          else {
            uVar2 = 0x2a;
          }
        }
        else if (param_3 < 0x1007) {
          if (param_3 < 0x1001) {
            uVar2 = 0x2a;
          }
          else if (param_4 == 0) {
            uVar2 = 0x16;
          }
          else if (*(word *)(param_4 + 8) < 4) {
            uVar2 = 0x16;
          }
          else {
            switch(param_3) {
            case :
            case :
              if (param_3 == 0x1001) {
                param_1 = param_1 + 0x3c;
              }
              else {
                param_1 = param_1 + 0x24;
              }
              _sbreserve(param_1,*(undefined4 *)(param_4 + *(int *)(param_4 + 4)));
              if (param_1 == 0) {
                uVar2 = 0x37;
              }
              break;
            case :
              *(sword *)(param_1 + 0x44) = (sword)*(undefined4 *)(param_4 + *(int *)(param_4 + 4));
              break;
            case :
              *(sword *)(param_1 + 0x2c) = (sword)*(undefined4 *)(param_4 + *(int *)(param_4 + 4));
              break;
            case :
              *(sword *)(param_1 + 0x46) = (sword)*(undefined4 *)(param_4 + *(int *)(param_4 + 4));
              break;
            case :
              *(sword *)(param_1 + 0x2e) = (sword)*(undefined4 *)(param_4 + *(int *)(param_4 + 4));
            }
          }
        }
        else {
          uVar2 = 0x2a;
        }
        goto loc_F001FCCC;
      }
      goto loc_F001FBA4;
    }
    if (param_3 == 4) goto loc_F001FBA4;
    if (param_3 < 5) {
      if (param_3 == 1) goto loc_F001FBA4;
      uVar2 = 0x2a;
    }
    else {
      if ((param_3 == 8) || (param_3 == 0x10)) goto loc_F001FBA4;
      uVar2 = 0x2a;
    }
  }
loc_F001FCCC:
  if (param_4 != 0) {
    _m_free(param_4);
  }
locret_F001FCE0:
  return CONCAT44(param_2,uVar2);
}
/* GHIDRADEC_FUNCTION index=428 start=0xf001fce8 */

/* WARNING: Removing unreachable block (ram,0xf001ff04) */
/* WARNING: Removing unreachable block (ram,0xf001fd3c) */

undefined8 _sogetopt(sword *param_1,int param_2,uint param_3,int *param_4)

{
  int iVar1;
  uint uVar2;
  code *pcVar3;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar4;
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
  iVar1 = 1;
  if (param_2 != 0xffff) {
    if (*(int *)(param_1 + 6) == 0) {
      uVar4 = 0x2a;
      goto locret_F001FF1C;
    }
    pcVar3 = *(code **)(*(int *)(param_1 + 6) + 0x18);
    uVar4 = 0;
    if (pcVar3 != (code *)0x0) {
      (*pcVar3)(0,param_1,param_2,param_3,param_4);
      goto locret_F001FF1C;
    }
loc_F001FF0C:
    uVar4 = 0x2a;
    goto locret_F001FF1C;
  }
  _m_get(1,10);
  *(undefined2 *)(iVar1 + 8) = 4;
  if (param_3 == 0x100) {
loc_F001FE84:
    uVar2 = (uint)param_1[1];
loc_F001FE88:
    *(uint *)(iVar1 + *(int *)(iVar1 + 4)) = uVar2 & param_3;
  }
  else {
    if ((int)param_3 < 0x101) {
      if (param_3 == 0x10) {
        uVar2 = (uint)param_1[1];
      }
      else {
        if (0x10 < (int)param_3) {
          if (param_3 == 0x40) goto loc_F001FE84;
          if ((int)param_3 < 0x41) {
            if (param_3 == 0x20) {
              uVar2 = (uint)param_1[1];
              goto loc_F001FE88;
            }
          }
          else if (param_3 == 0x80) {
            *(undefined2 *)(iVar1 + 8) = 8;
            *(uint *)(iVar1 + *(int *)(iVar1 + 4)) = (word)param_1[1] & 0x80;
            *(int *)(iVar1 + *(int *)(iVar1 + 4) + 4) = (int)param_1[2];
            goto loc_F001FF14;
          }
          goto loc_F001FF04;
        }
        if (param_3 != 4) {
          if ((int)param_3 < 5) {
            if (param_3 == 1) {
              uVar2 = (uint)param_1[1];
              goto loc_F001FE88;
            }
          }
          else if (param_3 == 8) {
            uVar2 = (uint)param_1[1];
            goto loc_F001FE88;
          }
loc_F001FF04:
          _m_free(iVar1);
          goto loc_F001FF0C;
        }
        uVar2 = (uint)param_1[1];
      }
      goto loc_F001FE88;
    }
    if (param_3 == 0x1004) {
      *(uint *)(iVar1 + *(int *)(iVar1 + 4)) = (uint)(word)param_1[0x16];
    }
    else if ((int)param_3 < 0x1005) {
      if (param_3 == 0x1002) {
        *(uint *)(iVar1 + *(int *)(iVar1 + 4)) = (uint)(word)param_1[0x13];
      }
      else if ((int)param_3 < 0x1003) {
        if (param_3 != 0x1001) goto loc_F001FF04;
        *(uint *)(iVar1 + *(int *)(iVar1 + 4)) = (uint)(word)param_1[0x1f];
      }
      else {
        *(uint *)(iVar1 + *(int *)(iVar1 + 4)) = (uint)(word)param_1[0x22];
      }
    }
    else if (param_3 == 0x1006) {
      *(int *)(iVar1 + *(int *)(iVar1 + 4)) = (int)param_1[0x17];
    }
    else if ((int)param_3 < 0x1006) {
      *(int *)(iVar1 + *(int *)(iVar1 + 4)) = (int)param_1[0x23];
    }
    else if (param_3 == 0x1007) {
      *(uint *)(iVar1 + *(int *)(iVar1 + 4)) = (uint)(word)param_1[0x2b];
      param_1[0x2b] = 0;
    }
    else {
      if (param_3 != 0x1008) goto loc_F001FF04;
      *(int *)(iVar1 + *(int *)(iVar1 + 4)) = (int)*param_1;
    }
  }
loc_F001FF14:
  *param_4 = iVar1;
  uVar4 = 0;
locret_F001FF1C:
  return CONCAT44(param_2,uVar4);
}
/* GHIDRADEC_FUNCTION index=429 start=0xf001ff24 */

/* WARNING: Removing unreachable block (ram,0xf001ff84) */
/* WARNING: Removing unreachable block (ram,0xf001ff68) */
/* WARNING: Removing unreachable block (ram,0xf001ff3c) */
/* WARNING: Removing unreachable block (ram,0xf001ff8c) */
/* WARNING: Removing unreachable block (ram,0xf001ff54) */

undefined8 _sohasoutofband(int param_1,undefined4 param_2)

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
  iVar1 = (int)*(sword *)(param_1 + 0x5a);
  if (iVar1 < 0) {
    _gsignal(-iVar1,0x10);
    iVar1 = *(int *)(param_1 + 0x34);
  }
  else if (iVar1 < 1) {
    iVar1 = *(int *)(param_1 + 0x34);
  }
  else {
    _pfind();
    if (iVar1 == 0) {
      iVar1 = *(int *)(param_1 + 0x34);
    }
    else {
      _psignal();
      iVar1 = *(int *)(param_1 + 0x34);
    }
  }
  if (iVar1 != 0) {
    _selwakeup(iVar1,*(word *)(param_1 + 0x38) & 0x10);
    _selthreadclear(param_1 + 0x34);
    *(word *)(param_1 + 0x38) = *(word *)(param_1 + 0x38) & 0xffef;
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=430 start=0xf001ffa8 */

/* WARNING: Removing unreachable block (ram,0xf001ffbc) */

undefined8 _soisconnecting(int param_1,undefined4 param_2)

{
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
  *(word *)(param_1 + 6) = *(word *)(param_1 + 6) & 0xfff5 | 4;
  _wakeup(param_1 + 0x54);
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=431 start=0xf001ffcc */

/* WARNING: Removing unreachable block (ram,0xf0020040) */
/* WARNING: Removing unreachable block (ram,0xf002001c) */
/* WARNING: Removing unreachable block (ram,0xf0020008) */
/* WARNING: Removing unreachable block (ram,0xf001fff8) */
/* WARNING: Removing unreachable block (ram,0xf0020014) */
/* WARNING: Removing unreachable block (ram,0xf0020034) */
/* WARNING: Removing unreachable block (ram,0xf002004c) */
/* WARNING: Removing unreachable block (ram,0xf001ffe0) */

undefined8 _soisconnected(int param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 unaff_l0;
  int iVar2;
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
  iVar2 = *(int *)(param_1 + 0x10);
  if (iVar2 != 0) {
    iVar1 = param_1;
    _soqremque(param_1,0);
    if (iVar1 == 0) {
      _panic(aSoisconnected);
    }
    _soqinsque(iVar2,param_1,1);
    _sowakeup(iVar2,iVar2 + 0x24);
    _wakeup(iVar2 + 0x54);
  }
  *(word *)(param_1 + 6) = *(word *)(param_1 + 6) & 0xfff3 | 2;
  _wakeup(param_1 + 0x54);
  _sowakeup(param_1,param_1 + 0x24);
  _sowakeup(param_1,param_1 + 0x3c);
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=432 start=0xf002005c */

/* WARNING: Removing unreachable block (ram,0xf002007c) */
/* WARNING: Removing unreachable block (ram,0xf0020088) */
/* WARNING: Removing unreachable block (ram,0xf0020070) */

undefined8 _soisdisconnecting(int param_1,undefined4 param_2)

{
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
  *(word *)(param_1 + 6) = *(word *)(param_1 + 6) & 0xfffb | 0x38;
  _wakeup(param_1 + 0x54);
  _sowakeup(param_1,param_1 + 0x3c);
  _sowakeup(param_1,param_1 + 0x24);
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=433 start=0xf0020098 */

/* WARNING: Removing unreachable block (ram,0xf00200b8) */
/* WARNING: Removing unreachable block (ram,0xf00200c4) */
/* WARNING: Removing unreachable block (ram,0xf00200ac) */

undefined8 _soisdisconnected(int param_1,undefined4 param_2)

{
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
  *(word *)(param_1 + 6) = *(word *)(param_1 + 6) & 0xfff1 | 0x30;
  _wakeup(param_1 + 0x54);
  _sowakeup(param_1,param_1 + 0x3c);
  _sowakeup(param_1,param_1 + 0x24);
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=434 start=0xf00200d4 */

/* WARNING: Removing unreachable block (ram,0xf00201b4) */
/* WARNING: Removing unreachable block (ram,0xf0020170) */
/* WARNING: Removing unreachable block (ram,0xf00201bc) */
/* WARNING: Removing unreachable block (ram,0xf0020110) */

undefined8 _sonewconn(undefined2 *param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int iVar3;
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
  if (((sword)param_1[0x11] * 3) / 2 < (int)(sword)param_1[0x10] + (int)(sword)param_1[0xc]) {
    iVar3 = 0;
  }
  else {
    iVar1 = 0;
    _m_getclr(0,3);
    if (iVar1 != 0) {
      iVar3 = *(int *)(iVar1 + 4);
      *(undefined2 *)(iVar1 + iVar3) = *param_1;
      iVar3 = iVar1 + iVar3;
      *(word *)(iVar3 + 2) = param_1[1] & 0xfffd;
      *(undefined2 *)(iVar3 + 4) = param_1[2];
      *(word *)(iVar3 + 6) = param_1[3] | 1;
      *(undefined4 *)(iVar3 + 0xc) = *(undefined4 *)(param_1 + 6);
      *(undefined2 *)(iVar3 + 0x54) = param_1[0x2a];
      *(undefined2 *)(iVar3 + 0x5a) = param_1[0x2d];
      _soqinsque(param_1,iVar3,0);
      iVar2 = iVar3;
      (**(code **)(*(int *)(iVar3 + 0xc) + 0x1c))(iVar3,0,0,0,0);
      if (iVar2 == 0) goto locret_F00201C8;
      if (*(int *)(iVar3 + 0x10) != 0) {
        _soqremque(iVar3,0);
      }
      _m_free(iVar1);
    }
    iVar3 = 0;
  }
locret_F00201C8:
  return CONCAT44(param_2,iVar3);
}
/* GHIDRADEC_FUNCTION index=435 start=0xf00201d0 */

undefined8 _soqinsque(int param_1,int param_2,int param_3)

{
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
  int iVar1;
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
  *(int *)(param_2 + 0x10) = param_1;
  if (param_3 == 0) {
    *(sword *)(param_1 + 0x18) = *(sword *)(param_1 + 0x18) + 1;
    iVar1 = param_1;
    if (*(int *)(param_1 + 0x14) != param_1) {
      for (iVar1 = *(int *)(param_1 + 0x14); *(int *)(iVar1 + 0x14) != param_1;
          iVar1 = *(int *)(iVar1 + 0x14)) {
      }
    }
    *(undefined4 *)(param_2 + 0x14) = *(undefined4 *)(iVar1 + 0x14);
    *(int *)(iVar1 + 0x14) = param_2;
  }
  else {
    *(sword *)(param_1 + 0x20) = *(sword *)(param_1 + 0x20) + 1;
    iVar1 = param_1;
    if (*(int *)(param_1 + 0x1c) != param_1) {
      for (iVar1 = *(int *)(param_1 + 0x1c); *(int *)(iVar1 + 0x1c) != param_1;
          iVar1 = *(int *)(iVar1 + 0x1c)) {
      }
    }
    *(undefined4 *)(param_2 + 0x1c) = *(undefined4 *)(iVar1 + 0x1c);
    *(int *)(iVar1 + 0x1c) = param_2;
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=436 start=0xf0020260 */

undefined8 _soqremque(int param_1,int param_2)

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
  undefined4 uVar2;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  int iVar3;
  undefined4 unaff_i3;
  int iVar4;
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
  iVar4 = *(int *)(param_1 + 0x10);
  iVar3 = iVar4;
  while( true ) {
    if (param_2 == 0) {
      iVar1 = *(int *)(iVar3 + 0x14);
    }
    else {
      iVar1 = *(int *)(iVar3 + 0x1c);
    }
    if (iVar1 == param_1) break;
    iVar3 = iVar1;
    if (iVar1 == iVar4) {
      uVar2 = 0;
locret_F00202E4:
      return CONCAT44(param_2,uVar2);
    }
  }
  if (param_2 == 0) {
    *(undefined4 *)(iVar3 + 0x14) = *(undefined4 *)(iVar1 + 0x14);
    *(sword *)(iVar4 + 0x18) = *(sword *)(iVar4 + 0x18) + -1;
  }
  else {
    *(undefined4 *)(iVar3 + 0x1c) = *(undefined4 *)(iVar1 + 0x1c);
    *(sword *)(iVar4 + 0x20) = *(sword *)(iVar4 + 0x20) + -1;
  }
  *(undefined4 *)(iVar1 + 0x1c) = 0;
  *(undefined4 *)(iVar1 + 0x14) = 0;
  *(undefined4 *)(iVar1 + 0x10) = 0;
  uVar2 = 1;
  goto locret_F00202E4;
}
/* GHIDRADEC_FUNCTION index=437 start=0xf00202ec */

/* WARNING: Removing unreachable block (ram,0xf0020300) */

undefined8 _socantsendmore(int param_1,undefined4 param_2)

{
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
  *(word *)(param_1 + 6) = *(word *)(param_1 + 6) | 0x10;
  _sowakeup(param_1,param_1 + 0x3c);
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=438 start=0xf0020310 */

/* WARNING: Removing unreachable block (ram,0xf0020324) */

undefined8 _socantrcvmore(int param_1,undefined4 param_2)

{
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
  *(word *)(param_1 + 6) = *(word *)(param_1 + 6) | 0x20;
  _sowakeup(param_1,param_1 + 0x24);
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=439 start=0xf0020334 */

/* WARNING: Removing unreachable block (ram,0xf0020338) */

undefined8 _sbselqueue(int param_1,undefined4 param_2)

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
  iVar1 = param_1 + 0x10;
  _selthreadcache();
  if (iVar1 != 0) {
    *(word *)(param_1 + 0x14) = *(word *)(param_1 + 0x14) | 0x10;
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=440 start=0xf0020360 */

/* WARNING: Removing unreachable block (ram,0xf0020374) */

undefined8 _sbwait(int param_1,undefined4 param_2)

{
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
  *(word *)(param_1 + 0x14) = *(word *)(param_1 + 0x14) | 4;
  _sleep(param_1,0x1a);
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=441 start=0xf0020384 */

/* WARNING: Removing unreachable block (ram,0xf00203fc) */
/* WARNING: Removing unreachable block (ram,0xf00203b0) */
/* WARNING: Removing unreachable block (ram,0xf00203a8) */
/* WARNING: Removing unreachable block (ram,0xf00203c4) */
/* WARNING: Removing unreachable block (ram,0xf00203f0) */
/* WARNING: Removing unreachable block (ram,0xf0020388) */

undefined8 _sbwakeup(int param_1,undefined4 param_2)

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
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool bVar2;
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
  iVar1 = param_1;
  _spltty();
  if (*(int *)(param_1 + 0x10) != 0) {
    _selwakeup(*(int *)(param_1 + 0x10),*(word *)(param_1 + 0x14) & 0x10);
    _selthreadclear(param_1 + 0x10);
    *(word *)(param_1 + 0x14) = *(word *)(param_1 + 0x14) & 0xffef;
  }
  _splx(iVar1);
  if ((*(word *)(param_1 + 0x14) & 4) != 0) {
    bVar2 = _nfs_wakeup_one_nfsd == 1;
    *(word *)(param_1 + 0x14) = *(word *)(param_1 + 0x14) & 0xfffb;
    if (bVar2) {
      _wakeup_one(param_1);
    }
    else {
      _wakeup(param_1);
    }
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=442 start=0xf002040c */

/* WARNING: Removing unreachable block (ram,0xf0020464) */
/* WARNING: Removing unreachable block (ram,0xf0020450) */
/* WARNING: Removing unreachable block (ram,0xf002043c) */
/* WARNING: Removing unreachable block (ram,0xf0020410) */

undefined8 _sowakeup(int param_1,undefined4 param_2)

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
  _sbwakeup(param_2);
  if ((*(word *)(param_1 + 6) & 0x200) != 0) {
    iVar1 = (int)*(sword *)(param_1 + 0x5a);
    if (iVar1 < 0) {
      _gsignal(-iVar1,0x17);
    }
    else if ((0 < iVar1) && (_pfind(), iVar1 != 0)) {
      _psignal();
    }
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=443 start=0xf0020474 */

/* WARNING: Removing unreachable block (ram,0xf0020498) */
/* WARNING: Removing unreachable block (ram,0xf00204ac) */
/* WARNING: Removing unreachable block (ram,0xf0020480) */

undefined8 _soreserve(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 unaff_l0;
  int iVar2;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar3;
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
  iVar2 = param_1 + 0x3c;
  iVar1 = iVar2;
  _sbreserve(iVar2,param_2);
  if (iVar1 == 0) {
    uVar3 = 0x37;
  }
  else {
    param_1 = param_1 + 0x24;
    _sbreserve(param_1,param_3);
    uVar3 = 0;
    if (param_1 == 0) {
      _sbrelease(iVar2);
      uVar3 = 0x37;
    }
  }
  return CONCAT44(param_2,uVar3);
}
/* GHIDRADEC_FUNCTION index=444 start=0xf00204c0 */

undefined8 _sbreserve(int param_1,uint param_2)

{
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar1;
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
  if (param_2 < 0xcccd) {
    *(sword *)(param_1 + 2) = (sword)param_2;
    param_2 = param_2 * 2;
    if (0xffff < (int)param_2) {
      param_2 = 0xffff;
    }
    *(sword *)(param_1 + 6) = (sword)param_2;
    uVar1 = 1;
  }
  else {
    uVar1 = 0;
  }
  return CONCAT44(param_2,uVar1);
}
/* GHIDRADEC_FUNCTION index=445 start=0xf0020508 */

/* WARNING: Removing unreachable block (ram,0xf0020530) */
/* WARNING: Removing unreachable block (ram,0xf0020518) */
/* WARNING: Removing unreachable block (ram,0xf0020538) */
/* WARNING: Removing unreachable block (ram,0xf002050c) */

undefined8 _sbrelease(int param_1,undefined4 param_2)

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
  iVar1 = param_1;
  _sbflush(param_1);
  *(undefined2 *)(param_1 + 6) = 0;
  *(undefined2 *)(param_1 + 2) = 0;
  _spltty();
  if (*(int *)(param_1 + 0x10) != 0) {
    _selthreadclear(param_1 + 0x10);
  }
  _splx(iVar1);
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=446 start=0xf0020548 */

/* WARNING: Removing unreachable block (ram,0xf0020598) */

undefined8 _sbappend(int param_1,int param_2)

{
  int iVar1;
  int *piVar2;
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
  if (param_2 != 0) {
    piVar2 = *(int **)(param_1 + 0xc);
    if (piVar2 != (int *)0x0) {
      iVar1 = piVar2[0x1f];
      while (iVar1 != 0) {
        piVar2 = (int *)piVar2[0x1f];
        iVar1 = piVar2[0x1f];
      }
      iVar1 = *piVar2;
      while (iVar1 != 0) {
        piVar2 = (int *)*piVar2;
        iVar1 = *piVar2;
      }
    }
    _sbcompress(param_1,param_2);
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=447 start=0xf00205a8 */

/* WARNING: Removing unreachable block (ram,0xf002062c) */

undefined8 _sbappendrecord(sword *param_1,undefined4 *param_2)

{
  sword sVar1;
  sword sVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
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
  if (param_2 != (undefined4 *)0x0) {
    iVar4 = *(int *)(param_1 + 6);
    if (iVar4 == 0) {
      sVar1 = *param_1;
    }
    else {
      iVar3 = *(int *)(iVar4 + 0x7c);
      while (iVar3 != 0) {
        iVar4 = *(int *)(iVar4 + 0x7c);
        iVar3 = *(int *)(iVar4 + 0x7c);
      }
      sVar1 = *param_1;
    }
    sVar2 = param_1[2];
    *param_1 = sVar1 + *(sword *)(param_2 + 2);
    param_1[2] = sVar2 + 0x80;
    if (0x7c < (uint)param_2[1]) {
      param_1[2] = sVar2 + 0x480;
    }
    if (iVar4 == 0) {
      *(undefined4 **)(param_1 + 6) = param_2;
    }
    else {
      *(undefined4 **)(iVar4 + 0x7c) = param_2;
    }
    uVar5 = *param_2;
    *param_2 = 0;
    _sbcompress(param_1,uVar5);
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=448 start=0xf002063c */

/* WARNING: Removing unreachable block (ram,0xf00207ac) */
/* WARNING: Removing unreachable block (ram,0xf0020720) */
/* WARNING: Removing unreachable block (ram,0xf0020714) */
/* WARNING: Removing unreachable block (ram,0xf00206c8) */
/* WARNING: Removing unreachable block (ram,0xf0020798) */
/* WARNING: Removing unreachable block (ram,0xf002086c) */
/* WARNING: Removing unreachable block (ram,0xf00206a0) */

undefined8 _sbappendaddr(word *param_1,undefined2 *param_2,int param_3,int param_4)

{
  word wVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  undefined4 unaff_l0;
  int *piVar5;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar6;
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
  iVar4 = 0x10;
  for (piVar5 = (int *)param_3; piVar5 != (int *)0x0; piVar5 = (int *)*piVar5) {
    iVar4 = iVar4 + *(sword *)(piVar5 + 2);
  }
  if (param_4 != 0) {
    iVar4 = iVar4 + *(sword *)(param_4 + 8);
  }
  uVar2 = (uint)*param_1;
  iVar3 = param_1[1] - uVar2;
  if ((int)((uint)param_1[3] - (uint)param_1[2]) < (int)(param_1[1] - uVar2)) {
    iVar3 = (uint)param_1[3] - (uint)param_1[2];
  }
  if (iVar3 < iVar4) {
    uVar6 = 0;
    goto locret_F0020878;
  }
  _spltty();
  piVar5 = _mfree;
  if (_mfree == (int *)0x0) {
    piVar5 = (int *)0x0;
    _m_more(0,8);
  }
  else {
    if (*(sword *)((int)_mfree + 10) != 0) {
      _panic(&aMget_6);
    }
    *(undefined2 *)((int)piVar5 + 10) = 8;
    word_F0134B0C = word_F0134B0C + -1;
    DAT_f0134b1c._0_2_ = DAT_f0134b1c._0_2_ + 1;
    _mfree = (int *)*piVar5;
    piVar5[1] = 0xc;
    *piVar5 = 0;
  }
  _splx(uVar2);
  if (piVar5 == (int *)0x0) {
loc_F00207B4:
    uVar6 = 0;
  }
  else {
    iVar4 = piVar5[1];
    *(undefined2 *)((int)piVar5 + iVar4) = *param_2;
    *(undefined2 *)((int)piVar5 + iVar4 + 2) = param_2[1];
    *(undefined2 *)((int)piVar5 + iVar4 + 4) = param_2[2];
    *(undefined2 *)((int)piVar5 + iVar4 + 6) = param_2[3];
    *(undefined2 *)((int)piVar5 + iVar4 + 8) = param_2[4];
    *(undefined2 *)((int)piVar5 + iVar4 + 10) = param_2[5];
    *(undefined2 *)((int)piVar5 + iVar4 + 0xc) = param_2[6];
    *(undefined2 *)((int)piVar5 + iVar4 + 0xe) = param_2[7];
    *(undefined2 *)(piVar5 + 2) = 0x10;
    if ((param_4 != 0) && (*(sword *)(param_4 + 8) != 0)) {
      _m_copy(param_4,0);
      *piVar5 = param_4;
      if (param_4 == 0) {
        _m_freem(piVar5);
        goto loc_F00207B4;
      }
      wVar1 = param_1[2];
      *param_1 = *param_1 + *(sword *)(param_4 + 8);
      param_1[2] = wVar1 + 0x80;
      if (0x7c < *(uint *)(*piVar5 + 4)) {
        param_1[2] = wVar1 + 0x480;
      }
    }
    wVar1 = param_1[2];
    *param_1 = *param_1 + *(sword *)(piVar5 + 2);
    param_1[2] = wVar1 + 0x80;
    if (0x7c < (uint)piVar5[1]) {
      param_1[2] = wVar1 + 0x480;
    }
    iVar4 = *(int *)(param_1 + 6);
    if (iVar4 == 0) {
      *(int **)(param_1 + 6) = piVar5;
    }
    else {
      iVar3 = *(int *)(iVar4 + 0x7c);
      while (iVar3 != 0) {
        iVar4 = *(int *)(iVar4 + 0x7c);
        iVar3 = *(int *)(iVar4 + 0x7c);
      }
      *(int **)(iVar4 + 0x7c) = piVar5;
    }
    if ((int *)*piVar5 != (int *)0x0) {
      piVar5 = (int *)*piVar5;
    }
    if (param_3 != 0) {
      _sbcompress(param_1,param_3,piVar5);
    }
    uVar6 = 1;
  }
locret_F0020878:
  return CONCAT44(param_2,uVar6);
}
/* GHIDRADEC_FUNCTION index=449 start=0xf0020880 */

/* WARNING: Removing unreachable block (ram,0xf00208fc) */
/* WARNING: Removing unreachable block (ram,0xf002097c) */
/* WARNING: Removing unreachable block (ram,0xf0020894) */

undefined8 _sbappendrights(word *param_1,int *param_2,int param_3)

{
  int *piVar1;
  sword sVar2;
  word wVar3;
  int iVar4;
  int *piVar5;
  undefined4 unaff_l0;
  int iVar6;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar7;
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
  iVar6 = 0;
  if (param_3 == 0) {
    _panic(aSbappendrights);
  }
  piVar5 = param_2;
  if (param_2 == (int *)0x0) {
    sVar2 = *(sword *)(param_3 + 8);
  }
  else {
    do {
      piVar1 = piVar5 + 2;
      piVar5 = (int *)*piVar5;
      iVar6 = iVar6 + *(sword *)piVar1;
    } while (piVar5 != (int *)0x0);
    sVar2 = *(sword *)(param_3 + 8);
  }
  iVar4 = (uint)param_1[1] - (uint)*param_1;
  if ((int)((uint)param_1[3] - (uint)param_1[2]) < (int)((uint)param_1[1] - (uint)*param_1)) {
    iVar4 = (uint)param_1[3] - (uint)param_1[2];
  }
  if (iVar4 < iVar6 + sVar2) {
    uVar7 = 0;
  }
  else {
    _m_copy(param_3,0,(int)sVar2);
    if (param_3 == 0) {
      uVar7 = 0;
    }
    else {
      wVar3 = param_1[2];
      *param_1 = *param_1 + *(sword *)(param_3 + 8);
      param_1[2] = wVar3 + 0x80;
      if (0x7c < *(uint *)(param_3 + 4)) {
        param_1[2] = wVar3 + 0x480;
      }
      iVar6 = *(int *)(param_1 + 6);
      if (iVar6 == 0) {
        *(int *)(param_1 + 6) = param_3;
      }
      else {
        iVar4 = *(int *)(iVar6 + 0x7c);
        while (iVar4 != 0) {
          iVar6 = *(int *)(iVar6 + 0x7c);
          iVar4 = *(int *)(iVar6 + 0x7c);
        }
        *(int *)(iVar6 + 0x7c) = param_3;
      }
      if (param_2 != (int *)0x0) {
        _sbcompress(param_1,param_2);
      }
      uVar7 = 1;
    }
  }
  return CONCAT44(param_2,uVar7);
}

