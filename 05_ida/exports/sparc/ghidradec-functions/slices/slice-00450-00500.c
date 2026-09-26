/* GHIDRADEC_FUNCTION index=450 start=0xf0020990 */

/* WARNING: Removing unreachable block (ram,0xf0020a40) */
/* WARNING: Removing unreachable block (ram,0xf0020a14) */

sword * _sbcompress(sword *param_1,undefined4 *param_2,undefined4 *param_3)

{
  sword sVar1;
  undefined4 *puVar2;
  sword sVar3;
  uint uVar4;
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
  do {
    while( true ) {
      puVar2 = param_2;
      if (puVar2 == (undefined4 *)0x0) {
        return param_1;
      }
      if (*(sword *)(puVar2 + 2) != 0) break;
loc_F0020A40:
      _m_free();
      param_2 = puVar2;
    }
    if (param_3 == (undefined4 *)0x0) {
      sVar3 = *param_1;
    }
    else {
      uVar4 = param_3[1];
      if (uVar4 < 0x7d) {
        if ((uint)puVar2[1] < 0x7d) {
          if (uVar4 + (int)*(sword *)(param_3 + 2) + (int)*(sword *)(puVar2 + 2) < 0x7d) {
            if (*(sword *)((int)param_3 + 10) == *(sword *)((int)puVar2 + 10)) {
              _bcopy((int)puVar2 + puVar2[1],(int)param_3 + (int)*(sword *)(param_3 + 2) + uVar4);
              *(sword *)(param_3 + 2) = *(sword *)(param_3 + 2) + *(sword *)(puVar2 + 2);
              *param_1 = *param_1 + *(sword *)(puVar2 + 2);
              goto loc_F0020A40;
            }
            sVar3 = *param_1;
          }
          else {
            sVar3 = *param_1;
          }
        }
        else {
          sVar3 = *param_1;
        }
      }
      else {
        sVar3 = *param_1;
      }
    }
    sVar1 = param_1[2];
    *param_1 = sVar3 + *(sword *)(puVar2 + 2);
    param_1[2] = sVar1 + 0x80;
    if (0x7c < (uint)puVar2[1]) {
      param_1[2] = sVar1 + 0x480;
    }
    if (param_3 == (undefined4 *)0x0) {
      *(undefined4 **)(param_1 + 6) = puVar2;
    }
    else {
      *param_3 = puVar2;
    }
    param_2 = (undefined4 *)*puVar2;
    *puVar2 = 0;
    param_3 = puVar2;
  } while( true );
}
/* GHIDRADEC_FUNCTION index=451 start=0xf0020aa4 */

/* WARNING: Removing unreachable block (ram,0xf0020b10) */
/* WARNING: Removing unreachable block (ram,0xf0020ac8) */
/* WARNING: Removing unreachable block (ram,0xf0020ab8) */

undefined8 _sbflush(sword *param_1,undefined4 param_2)

{
  sword sVar1;
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
  if ((param_1[10] & 1U) == 0) goto loc_F0020AD0;
  _panic(&aSbflush);
  sVar1 = param_1[2];
  while (sVar1 != 0) {
    _sbdrop(param_1,*param_1);
loc_F0020AD0:
    sVar1 = param_1[2];
  }
  if (((*param_1 != 0) || (param_1[2] != 0)) || (*(int *)(param_1 + 6) != 0)) {
    _panic(aSbflush2);
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=452 start=0xf0020b20 */

/* WARNING: Removing unreachable block (ram,0xf0020d30) */
/* WARNING: Removing unreachable block (ram,0xf0020cd8) */
/* WARNING: Removing unreachable block (ram,0xf0020c4c) */
/* WARNING: Removing unreachable block (ram,0xf0020c10) */
/* WARNING: Removing unreachable block (ram,0xf0020bbc) */
/* WARNING: Removing unreachable block (ram,0xf0020bd8) */
/* WARNING: Removing unreachable block (ram,0xf0020c30) */
/* WARNING: Removing unreachable block (ram,0xf0020cbc) */
/* WARNING: Removing unreachable block (ram,0xf0020d10) */
/* WARNING: Removing unreachable block (ram,0xf0020d4c) */
/* WARNING: Removing unreachable block (ram,0xf0020b6c) */

undefined8 _sbdrop(sword *param_1,undefined *param_2)

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
  undefined4 *puVar7;
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
  bool bVar8;
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
  puVar7 = (undefined4 *)0x0;
  if (puVar5 != (undefined4 *)0x0) {
    puVar7 = (undefined4 *)puVar5[0x1f];
  }
  bVar8 = puVar5 == (undefined4 *)0x0;
  if (0 < (int)param_2) {
    do {
      if (bVar8) {
        if (puVar7 == (undefined4 *)0x0) {
          _panic(&aSbdrop);
        }
        puVar6 = (undefined4 *)puVar7[0x1f];
        puVar5 = puVar7;
      }
      else {
        sVar1 = *(sword *)(puVar5 + 2);
        if ((int)param_2 < (int)sVar1) {
          *(sword *)(puVar5 + 2) = sVar1 - (sword)param_2;
          puVar5[1] = param_2 + puVar5[1];
          *param_1 = *param_1 - (sword)param_2;
          break;
        }
        param_2 = param_2 + -(int)sVar1;
        wVar2 = param_1[2];
        *param_1 = *param_1 - sVar1;
        param_1[2] = wVar2 - 0x80;
        iVar3 = wVar2 - 0x480;
        if (0x7c < (uint)puVar5[1]) {
          param_1[2] = (sword)iVar3;
        }
        _spltty();
        iVar4 = (int)*(sword *)((int)puVar5 + 10);
        if (iVar4 == 0) {
          _panic(&aMfree_3);
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
        puVar5 = puVar6;
        puVar6 = puVar7;
        if (_m_want != 0) {
          _m_want = 0;
          _wakeup(&_mfree);
        }
      }
      bVar8 = puVar5 == (undefined4 *)0x0;
      puVar7 = puVar6;
    } while (0 < (int)param_2);
    bVar8 = puVar5 == (undefined4 *)0x0;
  }
  if ((!bVar8) && (sVar1 = *(sword *)(puVar5 + 2), *(sword *)(puVar5 + 2) == 0)) {
    param_2 = DAT_f0134c00;
    puVar6 = puVar5;
    do {
      wVar2 = param_1[2];
      *param_1 = *param_1 - sVar1;
      param_1[2] = wVar2 - 0x80;
      iVar3 = wVar2 - 0x480;
      if (0x7c < (uint)puVar6[1]) {
        param_1[2] = (sword)iVar3;
      }
      _spltty();
      iVar4 = (int)*(sword *)((int)puVar6 + 10);
      if (iVar4 == 0) {
        _panic(&aMfree_4);
        iVar4 = (int)*(sword *)((int)puVar6 + 10);
      }
      (&word_F0134B0C)[iVar4] = (&word_F0134B0C)[iVar4] + -1;
      word_F0134B0C = word_F0134B0C + 1;
      *(undefined2 *)((int)puVar6 + 10) = 0;
      if (0x7f < (uint)puVar6[1]) {
        _mclput(puVar6);
      }
      puVar6[1] = 0;
      puVar5 = (undefined4 *)*puVar6;
      puVar6[0x1f] = 0;
      *puVar6 = _mfree;
      _mfree = puVar6;
      _splx(iVar3);
      if (_m_want != 0) {
        _m_want = 0;
        _wakeup(&_mfree);
      }
      if (puVar5 == (undefined4 *)0x0) {
        *(undefined4 **)(param_1 + 6) = puVar7;
        goto locret_F0020DB0;
      }
      sVar1 = *(sword *)(puVar5 + 2);
      puVar6 = puVar5;
    } while (*(sword *)(puVar5 + 2) == 0);
  }
  if (puVar5 == (undefined4 *)0x0) {
    *(undefined4 **)(param_1 + 6) = puVar7;
  }
  else {
    *(undefined4 **)(param_1 + 6) = puVar5;
    puVar5[0x1f] = puVar7;
  }
locret_F0020DB0:
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=453 start=0xf0020db8 */

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
/* GHIDRADEC_FUNCTION index=454 start=0xf0020ec0 */

/* WARNING: Removing unreachable block (ram,0xf0020f08) */
/* WARNING: Removing unreachable block (ram,0xf0020ecc) */

undefined8 _socket(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 *puVar3;
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
  puVar3 = *(undefined4 **)(dword_F0133DDC + 0x24);
  iVar1 = dword_F0133DDC;
  _falloc();
  if (iVar1 != 0) {
    *(undefined4 *)(iVar1 + 8) = 3;
    *(undefined2 *)(iVar1 + 0xc) = 2;
    *(undefined **)(iVar1 + 0x14) = _socketops;
    uVar2 = *puVar3;
    _socreate(uVar2,(undefined *)((int)register0x00000038 + -0xc),puVar3[1],puVar3[2]);
    *(char *)(dword_F0133DDC + 0x38) = (char)uVar2;
    if (*(char *)(dword_F0133DDC + 0x38) == '\0') {
      *(undefined4 *)(iVar1 + 0x18) = *(undefined4 *)((int)register0x00000038 + -0xc);
      *(int *)(*(int *)(_active_u + 0x14c) + *(int *)(dword_F0133DDC + 0x30) * 4) = iVar1;
    }
    else {
      *(undefined4 *)(*(int *)(_active_u + 0x14c) + *(int *)(dword_F0133DDC + 0x30) * 4) = 0;
      *(undefined2 *)(iVar1 + 0xe) = 0;
    }
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=455 start=0xf0020f6c */

/* WARNING: Removing unreachable block (ram,0xf0020fc0) */
/* WARNING: Removing unreachable block (ram,0xf0020f98) */
/* WARNING: Removing unreachable block (ram,0xf0020fd0) */
/* WARNING: Removing unreachable block (ram,0xf0020f7c) */

undefined8 _bind(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined *puVar2;
  undefined4 uVar3;
  undefined4 unaff_l0;
  int *piVar4;
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
  piVar4 = *(int **)(dword_F0133DDC + 0x24);
  iVar1 = *piVar4;
  _getsock();
  puVar2 = (undefined *)((int)register0x00000038 + -0xc);
  if (iVar1 != 0) {
    _sockargs(puVar2,piVar4[1],piVar4[2],8);
    *(char *)(dword_F0133DDC + 0x38) = (char)puVar2;
    if (*(char *)(dword_F0133DDC + 0x38) == '\0') {
      uVar3 = *(undefined4 *)(iVar1 + 0x18);
      _sobind(uVar3,*(undefined4 *)((int)register0x00000038 + -0xc));
      *(char *)(dword_F0133DDC + 0x38) = (char)uVar3;
      _m_freem(*(undefined4 *)((int)register0x00000038 + -0xc));
    }
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=456 start=0xf0020fe0 */

/* WARNING: Removing unreachable block (ram,0xf0021008) */
/* WARNING: Removing unreachable block (ram,0xf0020ff0) */

undefined8 _listen(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 unaff_l0;
  int *piVar3;
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
  piVar3 = *(int **)(dword_F0133DDC + 0x24);
  iVar1 = *piVar3;
  _getsock();
  if (iVar1 != 0) {
    uVar2 = *(undefined4 *)(iVar1 + 0x18);
    _solisten(uVar2,piVar3[1]);
    *(char *)(dword_F0133DDC + 0x38) = (char)uVar2;
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=457 start=0xf0021020 */

/* WARNING: Removing unreachable block (ram,0xf0021264) */
/* WARNING: Removing unreachable block (ram,0xf002124c) */
/* WARNING: Removing unreachable block (ram,0xf0021208) */
/* WARNING: Removing unreachable block (ram,0xf00211a4) */
/* WARNING: Removing unreachable block (ram,0xf0021118) */
/* WARNING: Removing unreachable block (ram,0xf002108c) */
/* WARNING: Removing unreachable block (ram,0xf002106c) */
/* WARNING: Removing unreachable block (ram,0xf00210a0) */
/* WARNING: Removing unreachable block (ram,0xf0021164) */
/* WARNING: Removing unreachable block (ram,0xf00211bc) */
/* WARNING: Removing unreachable block (ram,0xf0021218) */
/* WARNING: Removing unreachable block (ram,0xf002125c) */
/* WARNING: Removing unreachable block (ram,0xf0021270) */
/* WARNING: Removing unreachable block (ram,0xf0021044) */

undefined8 _accept(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  sword sVar3;
  undefined *puVar2;
  undefined4 unaff_l0;
  int iVar4;
  undefined4 unaff_l1;
  int *piVar5;
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
  bool bVar6;
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
  piVar5 = *(int **)(dword_F0133DDC + 0x24);
  if (piVar5[1] != 0) {
    iVar1 = piVar5[2];
    _copyin(iVar1,(undefined *)((int)register0x00000038 + -0xc),4);
    *(char *)(dword_F0133DDC + 0x38) = (char)iVar1;
    if (*(char *)(dword_F0133DDC + 0x38) != '\0') goto locret_F0021278;
    iVar1 = piVar5[1];
    _useracc(iVar1,*(undefined4 *)((int)register0x00000038 + -0xc),0);
    if (iVar1 == 0) {
      *(undefined *)(dword_F0133DDC + 0x38) = 0xe;
      goto locret_F0021278;
    }
  }
  iVar1 = *piVar5;
  _getsock();
  if (iVar1 != 0) {
    _splnet();
    iVar1 = *(int *)(iVar1 + 0x18);
    if ((*(word *)(iVar1 + 2) & 2) == 0) {
      *(undefined *)(dword_F0133DDC + 0x38) = 0x16;
    }
    else {
      sVar3 = *(sword *)(iVar1 + 0x20);
      if ((*(word *)(iVar1 + 6) & 0x100) == 0) goto loc_F0021124;
      bVar6 = sVar3 == 0;
      if (bVar6) {
        *(undefined *)(dword_F0133DDC + 0x38) = 0x23;
      }
      else {
        while (bVar6) {
          if (*(sword *)(iVar1 + 0x56) != 0) {
loc_F0021140:
            sVar3 = *(sword *)(iVar1 + 0x56);
            goto loc_F0021144;
          }
          if ((*(word *)(iVar1 + 6) & 0x20) != 0) {
            *(undefined2 *)(iVar1 + 0x56) = 0x35;
            goto loc_F0021140;
          }
          _sleep(iVar1 + 0x54,0x1a);
          sVar3 = *(sword *)(iVar1 + 0x20);
loc_F0021124:
          bVar6 = sVar3 == 0;
        }
        sVar3 = *(sword *)(iVar1 + 0x56);
loc_F0021144:
        puVar2 = DAT_f0133c00;
        if (sVar3 == 0) {
          _falloc();
          if (puVar2 == (undefined *)0x0) {
            *(undefined4 *)(*(int *)(_active_u + 0x14c) + *(int *)(dword_F0133DDC + 0x30) * 4) = 0;
          }
          else {
            iVar4 = *(int *)(iVar1 + 0x1c);
            iVar1 = iVar4;
            _soqremque(iVar4,1);
            if (iVar1 == 0) {
              _panic(&aAccept);
            }
            *(undefined2 *)(puVar2 + 0xc) = 2;
            *(undefined4 *)(puVar2 + 8) = 3;
            *(undefined **)(puVar2 + 0x14) = _socketops;
            *(int *)(puVar2 + 0x18) = iVar4;
            iVar1 = 1;
            *(undefined **)(*(int *)(_active_u + 0x14c) + *(int *)(dword_F0133DDC + 0x30) * 4) =
                 puVar2;
            _m_get(1,8);
            _soaccept(iVar4,iVar1);
            if (piVar5[1] != 0) {
              if ((int)*(sword *)(iVar1 + 8) < *(int *)((int)register0x00000038 + -0xc)) {
                *(int *)((int)register0x00000038 + -0xc) = (int)*(sword *)(iVar1 + 8);
              }
              _copyout(iVar1 + *(int *)(iVar1 + 4),piVar5[1],
                       *(undefined4 *)((int)register0x00000038 + -0xc));
              _copyout((undefined *)((int)register0x00000038 + -0xc),piVar5[2],4);
            }
            _m_freem(iVar1);
          }
        }
        else {
          *(char *)(dword_F0133DDC + 0x38) = (char)sVar3;
          *(undefined2 *)(iVar1 + 0x56) = 0;
        }
      }
    }
    _splx();
  }
locret_F0021278:
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=458 start=0xf0021280 */

/* WARNING: Removing unreachable block (ram,0xf00213c8) */
/* WARNING: Removing unreachable block (ram,0xf0021354) */
/* WARNING: Removing unreachable block (ram,0xf00212fc) */
/* WARNING: Removing unreachable block (ram,0xf00212d8) */
/* WARNING: Removing unreachable block (ram,0xf0021344) */
/* WARNING: Removing unreachable block (ram,0xf0021384) */
/* WARNING: Removing unreachable block (ram,0xf00213e4) */
/* WARNING: Removing unreachable block (ram,0xf0021290) */

undefined8 _connect(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined *puVar2;
  undefined4 uVar3;
  uint uVar4;
  undefined4 unaff_l0;
  int *piVar5;
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
  piVar5 = *(int **)(dword_F0133DDC + 0x24);
  iVar1 = *piVar5;
  _getsock();
  if (iVar1 == 0) goto locret_F00213EC;
  iVar1 = *(int *)(iVar1 + 0x18);
  *(int *)((int)register0x00000038 + -0x14) = iVar1;
  if ((*(uint *)(iVar1 + 4) & 0x104) == 0x104) {
    *(undefined *)(dword_F0133DDC + 0x38) = 0x25;
    goto locret_F00213EC;
  }
  puVar2 = (undefined *)((int)register0x00000038 + -0xc);
  _sockargs(puVar2,piVar5[1],piVar5[2],8);
  *(char *)(dword_F0133DDC + 0x38) = (char)puVar2;
  if (*(char *)(dword_F0133DDC + 0x38) != '\0') goto locret_F00213EC;
  uVar3 = *(undefined4 *)((int)register0x00000038 + -0x14);
  _soconnect(uVar3,*(undefined4 *)((int)register0x00000038 + -0xc));
  *(char *)(dword_F0133DDC + 0x38) = (char)uVar3;
  iVar1 = *(int *)((int)register0x00000038 + -0x14);
  if (*(char *)(dword_F0133DDC + 0x38) == '\0') {
    uVar4 = *(uint *)(iVar1 + 4) & 0x104;
    if (uVar4 != 0x104) {
      _splnet();
      *(uint *)((int)register0x00000038 + -0x10) = uVar4;
      iVar1 = dword_F0133DDC + 0x28;
      _setjmp();
      if (iVar1 == 0) {
        while (iVar1 = *(int *)((int)register0x00000038 + -0x14), (*(word *)(iVar1 + 6) & 4) != 0) {
          if (*(sword *)(iVar1 + 0x56) != 0) {
            iVar1 = *(int *)((int)register0x00000038 + -0x14);
            break;
          }
          _sleep(iVar1 + 0x54,0x1a);
        }
        *(char *)(dword_F0133DDC + 0x38) = (char)*(undefined2 *)(iVar1 + 0x56);
        *(undefined2 *)(iVar1 + 0x56) = 0;
      }
      else if (*(char *)(dword_F0133DDC + 0x38) == '\0') {
        *(undefined *)(dword_F0133DDC + 0x38) = 4;
      }
      _splx(*(undefined4 *)((int)register0x00000038 + -0x10));
      iVar1 = *(int *)((int)register0x00000038 + -0x14);
      goto loc_F00213D4;
    }
    *(undefined *)(dword_F0133DDC + 0x38) = 0x24;
    uVar3 = *(undefined4 *)((int)register0x00000038 + -0xc);
  }
  else {
loc_F00213D4:
    uVar3 = *(undefined4 *)((int)register0x00000038 + -0xc);
    *(word *)(iVar1 + 6) = *(word *)(iVar1 + 6) & 0xfffb;
  }
  _m_freem(uVar3);
locret_F00213EC:
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=459 start=0xf00213f4 */

/* WARNING: Removing unreachable block (ram,0xf00215dc) */
/* WARNING: Removing unreachable block (ram,0xf0021568) */
/* WARNING: Removing unreachable block (ram,0xf00214e4) */
/* WARNING: Removing unreachable block (ram,0xf002146c) */
/* WARNING: Removing unreachable block (ram,0xf002143c) */
/* WARNING: Removing unreachable block (ram,0xf0021490) */
/* WARNING: Removing unreachable block (ram,0xf0021530) */
/* WARNING: Removing unreachable block (ram,0xf002159c) */
/* WARNING: Removing unreachable block (ram,0xf00215e4) */
/* WARNING: Removing unreachable block (ram,0xf002140c) */

undefined8 _socketpair(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  undefined uVar4;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 *puVar5;
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
  puVar5 = *(undefined4 **)(dword_F0133DDC + 0x24);
  iVar1 = puVar5[3];
  _useracc(iVar1,8,0);
  if (iVar1 == 0) {
    *(undefined *)(dword_F0133DDC + 0x38) = 0xe;
    goto locret_F00215EC;
  }
  uVar2 = *puVar5;
  _socreate(uVar2,(undefined *)((int)register0x00000038 + -0x14),puVar5[1],puVar5[2]);
  *(char *)(dword_F0133DDC + 0x38) = (char)uVar2;
  if (*(char *)(dword_F0133DDC + 0x38) != '\0') goto locret_F00215EC;
  uVar2 = *puVar5;
  _socreate(uVar2,(undefined *)((int)register0x00000038 + -0x18),puVar5[1],puVar5[2]);
  *(char *)(dword_F0133DDC + 0x38) = (char)uVar2;
  iVar1 = (int)*(char *)(dword_F0133DDC + 0x38);
  if (iVar1 == 0) {
    _falloc();
    if (iVar1 != 0) {
      *(undefined4 *)((int)register0x00000038 + -0x10) = *(undefined4 *)(dword_F0133DDC + 0x30);
      *(undefined4 *)(iVar1 + 8) = 3;
      *(undefined2 *)(iVar1 + 0xc) = 2;
      uVar2 = *(undefined4 *)((int)register0x00000038 + -0x14);
      *(undefined **)(iVar1 + 0x14) = _socketops;
      *(undefined4 *)(iVar1 + 0x18) = uVar2;
      iVar3 = *(int *)(dword_F0133DDC + 0x30) * 4;
      *(int *)(*(int *)(_active_u + 0x14c) + iVar3) = iVar1;
      _falloc();
      if (iVar3 == 0) {
        *(undefined2 *)(iVar1 + 0xe) = 0;
      }
      else {
        *(undefined4 *)(iVar3 + 8) = 3;
        *(undefined2 *)(iVar3 + 0xc) = 2;
        uVar2 = *(undefined4 *)((int)register0x00000038 + -0x18);
        *(undefined **)(iVar3 + 0x14) = _socketops;
        *(undefined4 *)(iVar3 + 0x18) = uVar2;
        *(int *)(*(int *)(_active_u + 0x14c) + *(int *)(dword_F0133DDC + 0x30) * 4) = iVar3;
        uVar4 = (undefined)*(undefined4 *)((int)register0x00000038 + -0x14);
        *(undefined4 *)((int)register0x00000038 + -0xc) = *(undefined4 *)(dword_F0133DDC + 0x30);
        _soconnect2();
        *(undefined *)(dword_F0133DDC + 0x38) = uVar4;
        if (*(char *)(dword_F0133DDC + 0x38) == '\0') {
          if (puVar5[1] == 2) {
            uVar2 = *(undefined4 *)((int)register0x00000038 + -0x18);
            _soconnect2(uVar2,*(undefined4 *)((int)register0x00000038 + -0x14));
            *(char *)(dword_F0133DDC + 0x38) = (char)uVar2;
            if (*(char *)(dword_F0133DDC + 0x38) != '\0') {
              *(undefined2 *)(iVar3 + 0xe) = 0;
              goto loc_F00215A8;
            }
          }
          *(undefined4 *)(dword_F0133DDC + 0x30) = 0;
          _copyout((undefined *)((int)register0x00000038 + -0x10),puVar5[3],8);
          goto locret_F00215EC;
        }
        *(undefined2 *)(iVar3 + 0xe) = 0;
loc_F00215A8:
        *(undefined4 *)(*(int *)(_active_u + 0x14c) + *(int *)((int)register0x00000038 + -0xc) * 4)
             = 0;
        *(undefined2 *)(iVar1 + 0xe) = 0;
      }
      *(undefined4 *)(*(int *)(_active_u + 0x14c) + *(int *)((int)register0x00000038 + -0x10) * 4) =
           0;
    }
    _soclose(*(undefined4 *)((int)register0x00000038 + -0x18));
  }
  _soclose(*(undefined4 *)((int)register0x00000038 + -0x14));
locret_F00215EC:
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=460 start=0xf00215f4 */

/* WARNING: Removing unreachable block (ram,0xf0021644) */

undefined8 _sendto(undefined4 param_1,undefined4 param_2)

{
  undefined4 *puVar1;
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
  puVar1 = *(undefined4 **)(dword_F0133DDC + 0x24);
  *(undefined4 *)((int)register0x00000038 + -0x20) = puVar1[4];
  *(undefined4 *)((int)register0x00000038 + -0x1c) = puVar1[5];
  *(undefined **)((int)register0x00000038 + -0x18) = (undefined *)((int)register0x00000038 + -0x28);
  *(undefined4 *)((int)register0x00000038 + -0x14) = 1;
  *(undefined4 *)((int)register0x00000038 + -0x28) = puVar1[1];
  *(undefined4 *)((int)register0x00000038 + -0x24) = puVar1[2];
  *(undefined4 *)((int)register0x00000038 + -0x10) = 0;
  *(undefined4 *)((int)register0x00000038 + -0xc) = 0;
  _sendit(*puVar1,(undefined *)((int)register0x00000038 + -0x20),puVar1[3]);
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=461 start=0xf0021654 */

/* WARNING: Removing unreachable block (ram,0xf002169c) */

undefined8 _send(undefined4 param_1,undefined4 param_2)

{
  undefined4 *puVar1;
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
  puVar1 = *(undefined4 **)(dword_F0133DDC + 0x24);
  *(undefined4 *)((int)register0x00000038 + -0x20) = 0;
  *(undefined4 *)((int)register0x00000038 + -0x1c) = 0;
  *(undefined **)((int)register0x00000038 + -0x18) = (undefined *)((int)register0x00000038 + -0x28);
  *(undefined4 *)((int)register0x00000038 + -0x14) = 1;
  *(undefined4 *)((int)register0x00000038 + -0x28) = puVar1[1];
  *(undefined4 *)((int)register0x00000038 + -0x24) = puVar1[2];
  *(undefined4 *)((int)register0x00000038 + -0x10) = 0;
  *(undefined4 *)((int)register0x00000038 + -0xc) = 0;
  _sendit(*puVar1,(undefined *)((int)register0x00000038 + -0x20),puVar1[3]);
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=462 start=0xf00216ac */

/* WARNING: Removing unreachable block (ram,0xf002170c) */
/* WARNING: Removing unreachable block (ram,0xf002173c) */
/* WARNING: Removing unreachable block (ram,0xf00216c8) */

undefined8 _sendmsg(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  undefined4 unaff_l0;
  undefined4 *puVar2;
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
  puVar2 = *(undefined4 **)(dword_F0133DDC + 0x24);
  uVar1 = puVar2[1];
  _copyin(uVar1,(undefined *)((int)register0x00000038 + -0x20),0x18);
  *(char *)(dword_F0133DDC + 0x38) = (char)uVar1;
  if (*(char *)(dword_F0133DDC + 0x38) == '\0') {
    if (*(uint *)((int)register0x00000038 + -0x14) < 0x10) {
      uVar1 = *(undefined4 *)((int)register0x00000038 + -0x18);
      _copyin(uVar1,(undefined *)((int)register0x00000038 + -0xa0),
              *(uint *)((int)register0x00000038 + -0x14) << 3);
      *(char *)(dword_F0133DDC + 0x38) = (char)uVar1;
      if (*(char *)(dword_F0133DDC + 0x38) == '\0') {
        *(undefined **)((int)register0x00000038 + -0x18) =
             (undefined *)((int)register0x00000038 + -0xa0);
        _sendit(*puVar2,(undefined *)((int)register0x00000038 + -0x20),puVar2[2]);
      }
    }
    else {
      *(undefined *)(dword_F0133DDC + 0x38) = 0x28;
    }
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=463 start=0xf002174c */

/* WARNING: Removing unreachable block (ram,0xf00218e4) */
/* WARNING: Removing unreachable block (ram,0xf0021848) */
/* WARNING: Removing unreachable block (ram,0xf00217b4) */
/* WARNING: Removing unreachable block (ram,0xf0021800) */
/* WARNING: Removing unreachable block (ram,0xf00218b4) */
/* WARNING: Removing unreachable block (ram,0xf00218fc) */
/* WARNING: Removing unreachable block (ram,0xf0021750) */

undefined8 _sendit(int *param_1,int *param_2,undefined4 param_3)

{
  int *piVar1;
  int iVar2;
  undefined *puVar3;
  int iVar4;
  undefined4 unaff_l0;
  int *piVar5;
  undefined4 unaff_l1;
  int iVar6;
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
  piVar1 = param_1;
  _getsock();
  iVar6 = 0;
  if (piVar1 == (int *)0x0) goto locret_F0021904;
  *(int *)((int)register0x00000038 + -0x20) = param_2[2];
  *(int *)((int)register0x00000038 + -0x1c) = param_2[3];
  *(undefined4 *)((int)register0x00000038 + -0x14) = 0;
  *(undefined4 *)((int)register0x00000038 + -0x18) = 0;
  *(undefined4 *)((int)register0x00000038 + -0xc) = 0;
  *(undefined2 *)((int)register0x00000038 + -0x10) = 0;
  param_1 = (int *)param_2[2];
  if (0 < param_2[3]) {
    piVar5 = param_1 + 1;
    do {
      iVar4 = *piVar5;
      if (iVar4 < 0) {
        *(undefined *)(dword_F0133DDC + 0x38) = 0x16;
        goto locret_F0021904;
      }
      if (iVar4 != 0) {
        iVar2 = *param_1;
        _useracc(iVar2,iVar4,1);
        if (iVar2 == 0) {
          *(undefined *)(dword_F0133DDC + 0x38) = 0xe;
          goto locret_F0021904;
        }
        *(int *)((int)register0x00000038 + -0xc) =
             *(int *)((int)register0x00000038 + -0xc) + *piVar5;
      }
      iVar6 = iVar6 + 1;
      piVar5 = piVar5 + 2;
      param_1 = param_1 + 2;
    } while (iVar6 < param_2[3]);
  }
  puVar3 = (undefined *)((int)register0x00000038 + -0x24);
  if (*param_2 == 0) {
    *(undefined4 *)((int)register0x00000038 + -0x24) = 0;
    iVar6 = param_2[4];
  }
  else {
    _sockargs(puVar3,*param_2,param_2[1],8);
    *(char *)(dword_F0133DDC + 0x38) = (char)puVar3;
    if (*(char *)(dword_F0133DDC + 0x38) != '\0') goto locret_F0021904;
    iVar6 = param_2[4];
  }
  puVar3 = (undefined *)((int)register0x00000038 + -0x28);
  if (iVar6 == 0) {
    *(undefined4 *)((int)register0x00000038 + -0x28) = 0;
    iVar6 = piVar1[6];
loc_F00218A4:
    iVar4 = *(int *)((int)register0x00000038 + -0xc);
    _sosend(iVar6,*(undefined4 *)((int)register0x00000038 + -0x24),
            (undefined *)((int)register0x00000038 + -0x20),param_3,
            *(undefined4 *)((int)register0x00000038 + -0x28));
    *(char *)(dword_F0133DDC + 0x38) = (char)iVar6;
    iVar6 = *(int *)((int)register0x00000038 + -0x28);
    *(int *)(dword_F0133DDC + 0x30) = iVar4 - *(int *)((int)register0x00000038 + -0xc);
    if (iVar6 != 0) {
      _m_freem();
    }
    iVar6 = *(int *)((int)register0x00000038 + -0x24);
  }
  else {
    _sockargs(puVar3,iVar6,param_2[5],0xc);
    *(char *)(dword_F0133DDC + 0x38) = (char)puVar3;
    iVar6 = *(int *)((int)register0x00000038 + -0x24);
    if (*(char *)(dword_F0133DDC + 0x38) == '\0') {
      iVar6 = piVar1[6];
      goto loc_F00218A4;
    }
  }
  if (iVar6 != 0) {
    _m_freem();
  }
locret_F0021904:
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=464 start=0xf002190c */

/* WARNING: Removing unreachable block (ram,0xf002199c) */
/* WARNING: Removing unreachable block (ram,0xf002192c) */

undefined8 _recvfrom(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 unaff_l0;
  undefined4 *puVar2;
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
  puVar2 = *(undefined4 **)(dword_F0133DDC + 0x24);
  iVar1 = puVar2[5];
  if (iVar1 == 0) {
    *(undefined4 *)((int)register0x00000038 + -0x1c) = 0;
  }
  else {
    _copyin(iVar1,(undefined *)((int)register0x00000038 + -0x2c),4);
    *(char *)(dword_F0133DDC + 0x38) = (char)iVar1;
  }
  if (*(char *)(dword_F0133DDC + 0x38) == '\0') {
    *(qword *)((int)register0x00000038 + -0x20) =
         CONCAT44(puVar2[4],*(undefined4 *)((int)register0x00000038 + -0x2c));
    *(undefined **)((int)register0x00000038 + -0x18) =
         (undefined *)((int)register0x00000038 + -0x28);
    *(undefined4 *)((int)register0x00000038 + -0x14) = 1;
    *(undefined4 *)((int)register0x00000038 + -0x28) = puVar2[1];
    *(undefined4 *)((int)register0x00000038 + -0x24) = puVar2[2];
    *(undefined4 *)((int)register0x00000038 + -0x10) = 0;
    *(undefined4 *)((int)register0x00000038 + -0xc) = 0;
    _recvit(*puVar2,(undefined *)((int)register0x00000038 + -0x20),puVar2[3],puVar2[5],0);
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=465 start=0xf00219ac */

/* WARNING: Removing unreachable block (ram,0xf00219fc) */

undefined8 _recv(undefined4 param_1,undefined4 param_2)

{
  undefined4 *puVar1;
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
  puVar1 = *(undefined4 **)(dword_F0133DDC + 0x24);
  *(undefined4 *)((int)register0x00000038 + -0x20) = 0;
  *(undefined4 *)((int)register0x00000038 + -0x1c) = 0;
  *(undefined **)((int)register0x00000038 + -0x18) = (undefined *)((int)register0x00000038 + -0x28);
  *(undefined4 *)((int)register0x00000038 + -0x14) = 1;
  *(undefined4 *)((int)register0x00000038 + -0x28) = puVar1[1];
  *(undefined4 *)((int)register0x00000038 + -0x24) = puVar1[2];
  *(undefined4 *)((int)register0x00000038 + -0x10) = 0;
  *(undefined4 *)((int)register0x00000038 + -0xc) = 0;
  _recvit(*puVar1,(undefined *)((int)register0x00000038 + -0x20),puVar1[3],0,0);
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=466 start=0xf0021a0c */

/* WARNING: Removing unreachable block (ram,0xf0021a9c) */
/* WARNING: Removing unreachable block (ram,0xf0021a68) */
/* WARNING: Removing unreachable block (ram,0xf0021ad4) */
/* WARNING: Removing unreachable block (ram,0xf0021a24) */

undefined8 _recvmsg(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 unaff_l0;
  undefined4 *puVar3;
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
  puVar3 = *(undefined4 **)(dword_F0133DDC + 0x24);
  uVar1 = puVar3[1];
  _copyin(uVar1,(undefined *)((int)register0x00000038 + -0x20),0x18);
  *(char *)(dword_F0133DDC + 0x38) = (char)uVar1;
  if (*(char *)(dword_F0133DDC + 0x38) == '\0') {
    if (*(uint *)((int)register0x00000038 + -0x14) < 0x10) {
      uVar1 = *(undefined4 *)((int)register0x00000038 + -0x18);
      _copyin(uVar1,(undefined *)((int)register0x00000038 + -0xa0),
              *(uint *)((int)register0x00000038 + -0x14) << 3);
      *(char *)(dword_F0133DDC + 0x38) = (char)uVar1;
      iVar2 = *(int *)((int)register0x00000038 + -0x10);
      if (*(char *)(dword_F0133DDC + 0x38) == '\0') {
        *(undefined **)((int)register0x00000038 + -0x18) =
             (undefined *)((int)register0x00000038 + -0xa0);
        if (iVar2 == 0) {
          uVar1 = *puVar3;
        }
        else {
          _useracc(iVar2,*(undefined4 *)((int)register0x00000038 + -0xc),0);
          if (iVar2 == 0) {
            *(undefined *)(dword_F0133DDC + 0x38) = 0xe;
            goto locret_F0021ADC;
          }
          uVar1 = *puVar3;
        }
        _recvit(uVar1,(undefined *)((int)register0x00000038 + -0x20),puVar3[2],puVar3[1] + 4,
                puVar3[1] + 0x14);
      }
    }
    else {
      *(undefined *)(dword_F0133DDC + 0x38) = 0x28;
    }
  }
locret_F0021ADC:
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=467 start=0xf0021ae4 */

/* WARNING: Removing unreachable block (ram,0xf0021cc4) */
/* WARNING: Removing unreachable block (ram,0xf0021c9c) */
/* WARNING: Removing unreachable block (ram,0xf0021c10) */
/* WARNING: Removing unreachable block (ram,0xf0021b48) */
/* WARNING: Removing unreachable block (ram,0xf0021b98) */
/* WARNING: Removing unreachable block (ram,0xf0021c20) */
/* WARNING: Removing unreachable block (ram,0xf0021cac) */
/* WARNING: Removing unreachable block (ram,0xf0021cdc) */
/* WARNING: Removing unreachable block (ram,0xf0021ae8) */

undefined8
_recvit(int *param_1,int *param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  undefined4 unaff_l0;
  int *piVar4;
  undefined4 unaff_l1;
  int iVar5;
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
  piVar1 = param_1;
  _getsock();
  iVar5 = 0;
  if (piVar1 != (int *)0x0) {
    *(int *)((int)register0x00000038 + -0x20) = param_2[2];
    *(int *)((int)register0x00000038 + -0x1c) = param_2[3];
    *(undefined4 *)((int)register0x00000038 + -0x14) = 0;
    *(undefined4 *)((int)register0x00000038 + -0x18) = 0;
    *(undefined4 *)((int)register0x00000038 + -0xc) = 0;
    piVar4 = (int *)param_2[2];
    if (0 < param_2[3]) {
      param_1 = piVar4 + 1;
      do {
        iVar3 = *param_1;
        if (iVar3 < 0) {
          *(undefined *)(dword_F0133DDC + 0x38) = 0x16;
          goto locret_F0021CE4;
        }
        if (iVar3 != 0) {
          iVar2 = *piVar4;
          _useracc(iVar2,iVar3,0);
          if (iVar2 == 0) {
            *(undefined *)(dword_F0133DDC + 0x38) = 0xe;
            goto locret_F0021CE4;
          }
          *(int *)((int)register0x00000038 + -0xc) =
               *(int *)((int)register0x00000038 + -0xc) + *param_1;
        }
        iVar5 = iVar5 + 1;
        param_1 = param_1 + 2;
        piVar4 = piVar4 + 2;
      } while (iVar5 < param_2[3]);
    }
    iVar5 = piVar1[6];
    *(undefined4 *)((int)register0x00000038 + -0x2c) =
         *(undefined4 *)((int)register0x00000038 + -0xc);
    _soreceive(iVar5,(undefined *)((int)register0x00000038 + -0x24),
               (undefined *)((int)register0x00000038 + -0x20),param_3,
               (undefined *)((int)register0x00000038 + -0x28));
    *(char *)(dword_F0133DDC + 0x38) = (char)iVar5;
    *(int *)(dword_F0133DDC + 0x30) =
         *(int *)((int)register0x00000038 + -0x2c) - *(int *)((int)register0x00000038 + -0xc);
    if (*param_2 == 0) {
      iVar5 = param_2[4];
    }
    else {
      iVar5 = param_2[1];
      *(int *)((int)register0x00000038 + -0x2c) = iVar5;
      if ((iVar5 < 1) || (iVar3 = *(int *)((int)register0x00000038 + -0x24), iVar3 == 0)) {
        *(undefined4 *)((int)register0x00000038 + -0x2c) = 0;
      }
      else {
        if (*(sword *)(iVar3 + 8) < iVar5) {
          *(int *)((int)register0x00000038 + -0x2c) = (int)*(sword *)(iVar3 + 8);
        }
        _copyout(iVar3 + *(int *)(iVar3 + 4),*param_2,
                 *(undefined4 *)((int)register0x00000038 + -0x2c));
      }
      _copyout((undefined *)((int)register0x00000038 + -0x2c),param_4,4);
      iVar5 = param_2[4];
    }
    iVar3 = *(int *)((int)register0x00000038 + -0x28);
    if (iVar5 != 0) {
      iVar5 = param_2[5];
      *(int *)((int)register0x00000038 + -0x2c) = iVar5;
      if ((iVar5 < 1) || (iVar3 = *(int *)((int)register0x00000038 + -0x28), iVar3 == 0)) {
        *(undefined4 *)((int)register0x00000038 + -0x2c) = 0;
      }
      else {
        if (*(sword *)(iVar3 + 8) < iVar5) {
          *(int *)((int)register0x00000038 + -0x2c) = (int)*(sword *)(iVar3 + 8);
        }
        _copyout(iVar3 + *(int *)(iVar3 + 4),param_2[4],
                 *(undefined4 *)((int)register0x00000038 + -0x2c));
      }
      _copyout((undefined *)((int)register0x00000038 + -0x2c),param_5,4);
      iVar3 = *(int *)((int)register0x00000038 + -0x28);
    }
    if (iVar3 == 0) {
      iVar5 = *(int *)((int)register0x00000038 + -0x24);
    }
    else {
      _m_freem();
      iVar5 = *(int *)((int)register0x00000038 + -0x24);
    }
    if (iVar5 != 0) {
      _m_freem();
    }
  }
locret_F0021CE4:
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=468 start=0xf0021cec */

/* WARNING: Removing unreachable block (ram,0xf0021d14) */
/* WARNING: Removing unreachable block (ram,0xf0021cfc) */

undefined8 _shutdown(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 unaff_l0;
  int *piVar3;
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
  piVar3 = *(int **)(dword_F0133DDC + 0x24);
  iVar1 = *piVar3;
  _getsock();
  if (iVar1 != 0) {
    uVar2 = *(undefined4 *)(iVar1 + 0x18);
    _soshutdown(uVar2,piVar3[1]);
    *(char *)(dword_F0133DDC + 0x38) = (char)uVar2;
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=469 start=0xf0021d2c */

/* WARNING: Removing unreachable block (ram,0xf0021dc8) */
/* WARNING: Removing unreachable block (ram,0xf0021d7c) */
/* WARNING: Removing unreachable block (ram,0xf0021da4) */
/* WARNING: Removing unreachable block (ram,0xf0021de4) */
/* WARNING: Removing unreachable block (ram,0xf0021d40) */

undefined8 _setsockopt(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined uVar5;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 unaff_l0;
  int *piVar6;
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
  piVar6 = *(int **)(dword_F0133DDC + 0x24);
  iVar1 = *piVar6;
  _getsock();
  if (iVar1 == 0) goto locret_F0021DF8;
  if (piVar6[4] < 0x71) {
    iVar2 = 1;
    iVar3 = 0;
    if (piVar6[3] != 0) {
      _m_get(1,10);
      if (iVar2 == 0) {
        uVar5 = 0x37;
        goto loc_F0021DF4;
      }
      iVar3 = piVar6[3];
      _copyin(iVar3,iVar2 + *(int *)(iVar2 + 4),piVar6[4]);
      *(char *)(dword_F0133DDC + 0x38) = (char)iVar3;
      if (*(char *)(dword_F0133DDC + 0x38) != '\0') {
        _m_free(iVar2);
        goto locret_F0021DF8;
      }
      *(sword *)(iVar2 + 8) = (sword)piVar6[4];
      iVar3 = iVar2;
    }
    uVar4 = *(undefined4 *)(iVar1 + 0x18);
    _sosetopt(uVar4,piVar6[1],piVar6[2],iVar3);
    uVar5 = (undefined)uVar4;
  }
  else {
    uVar5 = 0x16;
  }
loc_F0021DF4:
  *(undefined *)(dword_F0133DDC + 0x38) = uVar5;
locret_F0021DF8:
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=470 start=0xf0021e00 */

/* WARNING: Removing unreachable block (ram,0xf0021f10) */
/* WARNING: Removing unreachable block (ram,0xf0021e78) */
/* WARNING: Removing unreachable block (ram,0xf0021e3c) */
/* WARNING: Removing unreachable block (ram,0xf0021ee4) */
/* WARNING: Removing unreachable block (ram,0xf0021f30) */
/* WARNING: Removing unreachable block (ram,0xf0021e14) */

undefined8 _getsockopt(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined *puVar4;
  undefined4 unaff_l0;
  int *piVar5;
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
  piVar5 = *(int **)(dword_F0133DDC + 0x24);
  iVar1 = *piVar5;
  *(undefined4 *)((int)register0x00000038 + -0x10) = 0;
  _getsock();
  if (iVar1 == 0) goto locret_F0021F38;
  if (piVar5[3] == 0) {
    *(undefined4 *)((int)register0x00000038 + -0xc) = 0;
    uVar3 = *(undefined4 *)(iVar1 + 0x18);
  }
  else {
    iVar2 = piVar5[4];
    _copyin(iVar2,(undefined *)((int)register0x00000038 + -0xc),4);
    *(char *)(dword_F0133DDC + 0x38) = (char)iVar2;
    if (*(char *)(dword_F0133DDC + 0x38) != '\0') goto locret_F0021F38;
    uVar3 = *(undefined4 *)(iVar1 + 0x18);
  }
  _sogetopt(uVar3,piVar5[1],piVar5[2],(undefined *)((int)register0x00000038 + -0x10));
  *(char *)(dword_F0133DDC + 0x38) = (char)uVar3;
  iVar1 = *(int *)((int)register0x00000038 + -0x10);
  if (*(char *)(dword_F0133DDC + 0x38) == '\0') {
    if ((piVar5[3] == 0) ||
       (iVar2 = *(int *)((int)register0x00000038 + -0x10),
       *(int *)((int)register0x00000038 + -0xc) == 0)) {
loc_F0021F20:
      iVar1 = *(int *)((int)register0x00000038 + -0x10);
    }
    else {
      iVar1 = *(int *)((int)register0x00000038 + -0x10);
      if (iVar2 != 0) {
        if ((int)*(sword *)(iVar2 + 8) < *(int *)((int)register0x00000038 + -0xc)) {
          *(int *)((int)register0x00000038 + -0xc) = (int)*(sword *)(iVar2 + 8);
        }
        iVar2 = iVar2 + *(int *)(iVar2 + 4);
        _copyout(iVar2,piVar5[3],*(undefined4 *)((int)register0x00000038 + -0xc));
        *(char *)(dword_F0133DDC + 0x38) = (char)iVar2;
        iVar1 = *(int *)((int)register0x00000038 + -0x10);
        if (*(char *)(dword_F0133DDC + 0x38) == '\0') {
          puVar4 = (undefined *)((int)register0x00000038 + -0xc);
          _copyout(puVar4,piVar5[4],4);
          *(char *)(dword_F0133DDC + 0x38) = (char)puVar4;
          goto loc_F0021F20;
        }
      }
    }
  }
  if (iVar1 != 0) {
    _m_free();
  }
locret_F0021F38:
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=471 start=0xf0021f40 */

/* WARNING: Removing unreachable block (ram,0xf0022108) */
/* WARNING: Removing unreachable block (ram,0xf002201c) */
/* WARNING: Removing unreachable block (ram,0xf0021f84) */
/* WARNING: Removing unreachable block (ram,0xf0021fa8) */
/* WARNING: Removing unreachable block (ram,0xf0022094) */
/* WARNING: Removing unreachable block (ram,0xf0022110) */
/* WARNING: Removing unreachable block (ram,0xf0021f50) */

undefined8 _pipe(undefined4 param_1,undefined4 param_2)

{
  undefined uVar5;
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  int iVar6;
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
  uVar5 = 1;
  _socreate(1,(undefined *)((int)register0x00000038 + -0xc),1,0);
  *(undefined *)(dword_F0133DDC + 0x38) = uVar5;
  if (*(char *)(dword_F0133DDC + 0x38) == '\0') {
    uVar5 = 1;
    _socreate(1,(undefined *)((int)register0x00000038 + -0x10),1,0);
    *(undefined *)(dword_F0133DDC + 0x38) = uVar5;
    iVar1 = (int)*(char *)(dword_F0133DDC + 0x38);
    if (iVar1 == 0) {
      _falloc();
      if (iVar1 != 0) {
        iVar6 = *(int *)(dword_F0133DDC + 0x30);
        *(undefined4 *)(iVar1 + 8) = 1;
        if ((*(uint *)(*_active_u + 0x14) & 0x4000) != 0) {
          *(undefined4 *)(iVar1 + 8) = 0x2001;
        }
        *(undefined2 *)(iVar1 + 0xc) = 2;
        uVar2 = *(undefined4 *)((int)register0x00000038 + -0xc);
        *(undefined **)(iVar1 + 0x14) = _socketops;
        *(undefined4 *)(iVar1 + 0x18) = uVar2;
        iVar3 = *(int *)(dword_F0133DDC + 0x30) * 4;
        *(int *)(_active_u[0x53] + iVar3) = iVar1;
        _falloc();
        if (iVar3 == 0) {
          *(undefined2 *)(iVar1 + 0xe) = 0;
        }
        else {
          *(undefined4 *)(iVar3 + 8) = 2;
          if ((*(uint *)(*_active_u + 0x14) & 0x4000) != 0) {
            *(undefined4 *)(iVar3 + 8) = 0x2002;
          }
          *(undefined2 *)(iVar3 + 0xc) = 2;
          uVar4 = *(uint *)((int)register0x00000038 + -0x10);
          *(undefined **)(iVar3 + 0x14) = _socketops;
          *(uint *)(iVar3 + 0x18) = uVar4;
          *(int *)(_active_u[0x53] + *(int *)(dword_F0133DDC + 0x30) * 4) = iVar3;
          *(undefined4 *)(dword_F0133DDC + 0x34) = *(undefined4 *)(dword_F0133DDC + 0x30);
          uVar2 = *(undefined4 *)((int)register0x00000038 + -0xc);
          *(int *)(dword_F0133DDC + 0x30) = iVar6;
          _unp_connect2(uVar4,uVar2);
          *(char *)(dword_F0133DDC + 0x38) = (char)uVar4;
          if ((uVar4 & 0xff) == 0) {
            iVar1 = *(int *)((int)register0x00000038 + -0xc);
            *(word *)(*(int *)((int)register0x00000038 + -0x10) + 6) =
                 *(word *)(*(int *)((int)register0x00000038 + -0x10) + 6) | 0x20;
            *(word *)(iVar1 + 6) = *(word *)(iVar1 + 6) | 0x10;
            goto locret_F0022118;
          }
          *(undefined2 *)(iVar3 + 0xe) = 0;
          *(undefined4 *)(_active_u[0x53] + *(int *)(dword_F0133DDC + 0x34) * 4) = 0;
          *(undefined2 *)(iVar1 + 0xe) = 0;
        }
        *(undefined4 *)(_active_u[0x53] + iVar6 * 4) = 0;
      }
      _soclose(*(undefined4 *)((int)register0x00000038 + -0x10));
    }
    _soclose(*(undefined4 *)((int)register0x00000038 + -0xc));
  }
locret_F0022118:
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=472 start=0xf0022120 */

/* WARNING: Removing unreachable block (ram,0xf0022214) */
/* WARNING: Removing unreachable block (ram,0xf0022174) */
/* WARNING: Removing unreachable block (ram,0xf002214c) */
/* WARNING: Removing unreachable block (ram,0xf00221ec) */
/* WARNING: Removing unreachable block (ram,0xf0022224) */
/* WARNING: Removing unreachable block (ram,0xf0022130) */

undefined8 _getsockname(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  int *piVar3;
  undefined4 unaff_l4;
  undefined *puVar4;
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
  piVar3 = *(int **)(dword_F0133DDC + 0x24);
  iVar1 = *piVar3;
  _getsock();
  puVar4 = (undefined *)((int)register0x00000038 + -0xc);
  if (iVar1 != 0) {
    iVar2 = piVar3[2];
    _copyin(iVar2,puVar4,4);
    *(char *)(dword_F0133DDC + 0x38) = (char)iVar2;
    iVar2 = 1;
    if (*(char *)(dword_F0133DDC + 0x38) == '\0') {
      iVar1 = *(int *)(iVar1 + 0x18);
      _m_getclr(1,8);
      if (iVar2 == 0) {
        *(undefined *)(dword_F0133DDC + 0x38) = 0x37;
      }
      else {
        (**(code **)(*(int *)(iVar1 + 0xc) + 0x1c))(iVar1,0xf,0,iVar2,0);
        *(char *)(dword_F0133DDC + 0x38) = (char)iVar1;
        if (*(char *)(dword_F0133DDC + 0x38) == '\0') {
          if ((int)*(sword *)(iVar2 + 8) < *(int *)((int)register0x00000038 + -0xc)) {
            *(int *)((int)register0x00000038 + -0xc) = (int)*(sword *)(iVar2 + 8);
          }
          iVar1 = iVar2 + *(int *)(iVar2 + 4);
          _copyout(iVar1,piVar3[1],*(undefined4 *)((int)register0x00000038 + -0xc));
          *(char *)(dword_F0133DDC + 0x38) = (char)iVar1;
          if (*(char *)(dword_F0133DDC + 0x38) == '\0') {
            _copyout(puVar4,piVar3[2],4);
            *(char *)(dword_F0133DDC + 0x38) = (char)puVar4;
          }
        }
        _m_freem(iVar2);
      }
    }
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=473 start=0xf0022234 */

/* WARNING: Removing unreachable block (ram,0xf0022348) */
/* WARNING: Removing unreachable block (ram,0xf00222a8) */
/* WARNING: Removing unreachable block (ram,0xf002227c) */
/* WARNING: Removing unreachable block (ram,0xf0022320) */
/* WARNING: Removing unreachable block (ram,0xf0022358) */
/* WARNING: Removing unreachable block (ram,0xf0022244) */

undefined8 _getpeername(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  int *piVar3;
  undefined4 unaff_l3;
  int iVar4;
  undefined4 unaff_l4;
  undefined *puVar5;
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
  piVar3 = *(int **)(dword_F0133DDC + 0x24);
  iVar1 = *piVar3;
  _getsock();
  if (iVar1 != 0) {
    iVar4 = *(int *)(iVar1 + 0x18);
    iVar1 = 1;
    if ((*(word *)(iVar4 + 6) & 2) == 0) {
      *(undefined *)(dword_F0133DDC + 0x38) = 0x39;
    }
    else {
      _m_getclr(1,8);
      puVar5 = (undefined *)((int)register0x00000038 + -0xc);
      if (iVar1 == 0) {
        *(undefined *)(dword_F0133DDC + 0x38) = 0x37;
      }
      else {
        iVar2 = piVar3[2];
        _copyin(iVar2,puVar5,4);
        *(char *)(dword_F0133DDC + 0x38) = (char)iVar2;
        if (*(char *)(dword_F0133DDC + 0x38) == '\0') {
          (**(code **)(*(int *)(iVar4 + 0xc) + 0x1c))(iVar4,0x10,0,iVar1,0);
          *(char *)(dword_F0133DDC + 0x38) = (char)iVar4;
          if (*(char *)(dword_F0133DDC + 0x38) == '\0') {
            if ((int)*(sword *)(iVar1 + 8) < *(int *)((int)register0x00000038 + -0xc)) {
              *(int *)((int)register0x00000038 + -0xc) = (int)*(sword *)(iVar1 + 8);
            }
            iVar4 = iVar1 + *(int *)(iVar1 + 4);
            _copyout(iVar4,piVar3[1],*(undefined4 *)((int)register0x00000038 + -0xc));
            *(char *)(dword_F0133DDC + 0x38) = (char)iVar4;
            if (*(char *)(dword_F0133DDC + 0x38) == '\0') {
              _copyout(puVar5,piVar3[2],4);
              *(char *)(dword_F0133DDC + 0x38) = (char)puVar5;
            }
          }
          _m_freem(iVar1);
        }
      }
    }
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=474 start=0xf0022368 */

/* WARNING: Removing unreachable block (ram,0xf00223ac) */
/* WARNING: Removing unreachable block (ram,0xf00223c0) */
/* WARNING: Removing unreachable block (ram,0xf0022384) */

undefined8 _sockargs(int *param_1,int param_2,int param_3,undefined4 param_4)

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
  if (param_3 < 0x71) {
    iVar1 = 1;
    _m_get(1,param_4);
    if (iVar1 == 0) {
      iVar2 = 0x37;
    }
    else {
      *(sword *)(iVar1 + 8) = (sword)param_3;
      iVar2 = param_2;
      _copyin(param_2,iVar1 + *(int *)(iVar1 + 4),param_3);
      if (iVar2 == 0) {
        *param_1 = iVar1;
      }
      else {
        _m_free(iVar1);
      }
    }
  }
  else {
    iVar2 = 0x16;
  }
  return CONCAT44(param_2,iVar2);
}
/* GHIDRADEC_FUNCTION index=475 start=0xf00223d0 */

/* WARNING: Removing unreachable block (ram,0xf00223d4) */

undefined8 _getsock(int param_1,undefined4 param_2)

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
  _getf();
  if (param_1 == 0) {
    param_1 = 0;
  }
  else if (*(sword *)(param_1 + 0xc) != 2) {
    param_1 = 0;
    *(undefined *)(dword_F0133DDC + 0x38) = 0x26;
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=476 start=0xf0022414 */

/* WARNING: Removing unreachable block (ram,0xf00224f0) */
/* WARNING: Removing unreachable block (ram,0xf0022514) */
/* WARNING: Removing unreachable block (ram,0xf00229b4) */
/* WARNING: Removing unreachable block (ram,0xf00225e8) */
/* WARNING: Removing unreachable block (ram,0xf00229cc) */
/* WARNING: Removing unreachable block (ram,0xf0022614) */
/* WARNING: Removing unreachable block (ram,0xf00227fc) */
/* WARNING: Removing unreachable block (ram,0xf00227dc) */
/* WARNING: Removing unreachable block (ram,0xf0022770) */
/* WARNING: Removing unreachable block (ram,0xf0022698) */
/* WARNING: Removing unreachable block (ram,0xf0022948) */
/* WARNING: Removing unreachable block (ram,0xf002288c) */
/* WARNING: Removing unreachable block (ram,0xf00226e0) */
/* WARNING: Removing unreachable block (ram,0xf0022784) */
/* WARNING: Removing unreachable block (ram,0xf0022810) */
/* WARNING: Removing unreachable block (ram,0xf0022870) */
/* WARNING: Removing unreachable block (ram,0xf0022674) */
/* WARNING: Removing unreachable block (ram,0xf00225e0) */
/* WARNING: Removing unreachable block (ram,0xf00227a4) */
/* WARNING: Removing unreachable block (ram,0xf0022540) */
/* WARNING: Removing unreachable block (ram,0xf0022500) */
/* WARNING: Removing unreachable block (ram,0xf00229e0) */
/* WARNING: Removing unreachable block (ram,0xf0022554) */

undefined8 _uipc_usrreq(sword *param_1,int param_2,undefined2 *param_3,int param_4,sword *param_5)

{
  word wVar1;
  int *piVar2;
  int iVar3;
  undefined *puVar4;
  sword sVar5;
  int iVar6;
  undefined2 *puVar7;
  undefined4 unaff_l0;
  sword *psVar8;
  undefined4 unaff_l1;
  sword *psVar9;
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
  bool bVar10;
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
  psVar9 = (sword *)0x0;
  psVar8 = *(sword **)(param_1 + 4);
  if (param_2 == 0xb) {
loc_F0022428:
    psVar9 = (sword *)0x2d;
    goto locret_F00229EC;
  }
  if (((param_2 != 9) && (param_5 != (sword *)0x0)) && (param_5[4] != 0)) {
loc_F0022454:
    psVar9 = (sword *)0x2d;
    goto loc_F00229D4;
  }
  if ((psVar8 == (sword *)0x0) && (param_2 != 0)) {
    psVar9 = (sword *)0x16;
    goto loc_F00229D4;
  }
  switch(param_2) {
  case :
    psVar9 = (sword *)0x38;
    if (psVar8 == (sword *)0x0) {
      _unp_attach(param_1);
      psVar9 = param_1;
    }
  case :
  case :
loc_F00229D4:
    bVar10 = param_3 == (undefined2 *)0x0;
    break;
  case :
    _unp_detach(psVar8);
    bVar10 = param_3 == (undefined2 *)0x0;
    break;
  case :
    _unp_bind(psVar8,param_4);
    psVar9 = psVar8;
    goto loc_F00229D4;
  case :
    bVar10 = param_3 == (undefined2 *)0x0;
    if (*(int *)(psVar8 + 2) == 0) {
      psVar9 = (sword *)0x16;
    }
    break;
  case :
    _unp_connect(param_1,param_4);
    psVar9 = param_1;
    goto loc_F00229D4;
  case :
    if ((*(int *)(psVar8 + 6) == 0) || (iVar3 = *(int *)(*(int *)(psVar8 + 6) + 0x18), iVar3 == 0))
    {
      *(undefined2 *)(param_4 + 8) = 0x10;
      iVar3 = *(int *)(param_4 + 4);
      *(undefined2 *)(param_4 + iVar3) = _sun_noname;
      param_4 = param_4 + iVar3;
      *(undefined2 *)(param_4 + 2) = DAT_f010bcf2._0_2_;
      *(undefined2 *)(param_4 + 4) = DAT_f010bcf2._2_2_;
      *(undefined2 *)(param_4 + 6) = DAT_f010bcf2._4_2_;
      *(undefined2 *)(param_4 + 8) = DAT_f010bcf2._6_2_;
      *(undefined2 *)(param_4 + 10) = DAT_f010bcf2._8_2_;
      *(undefined2 *)(param_4 + 0xc) = DAT_f010bcf2._10_2_;
      *(undefined2 *)(param_4 + 0xe) = DAT_f010bcf2._12_2_;
      goto loc_F00229D4;
    }
    sVar5 = *(sword *)(iVar3 + 8);
loc_F0022994:
    *(sword *)(param_4 + 8) = sVar5;
    _bcopy(*(int *)(*(int *)(psVar8 + 6) + 0x18) +
           *(int *)(*(int *)(*(int *)(psVar8 + 6) + 0x18) + 4),param_4 + *(int *)(param_4 + 4),
           (int)sVar5);
    bVar10 = param_3 == (undefined2 *)0x0;
    break;
  case :
loc_F00227A4:
    _unp_disconnect(psVar8);
    bVar10 = param_3 == (undefined2 *)0x0;
    break;
  case :
    _socantsendmore(param_1);
    _unp_usrclosed(psVar8);
    bVar10 = param_3 == (undefined2 *)0x0;
    break;
  case :
    if (*param_1 != 1) {
      if (*param_1 != 2) {
        puVar4 = (undefined *)&aUipc2;
        goto loc_F00229CC;
      }
      _panic(&aUipc1);
    }
    bVar10 = param_3 == (undefined2 *)0x0;
    if (*(int **)(psVar8 + 6) != (int *)0x0) {
      param_2 = **(int **)(psVar8 + 6);
      *(sword *)(param_2 + 0x42) =
           *(sword *)(param_2 + 0x42) + ((sword)*(undefined4 *)(psVar8 + 0x10) - param_1[0x14]);
      *(uint *)(psVar8 + 0x10) = (uint)(word)param_1[0x14];
      *(sword *)(param_2 + 0x3e) =
           *(sword *)(param_2 + 0x3e) + ((sword)*(undefined4 *)(psVar8 + 0xe) - param_1[0x12]);
      *(uint *)(psVar8 + 0xe) = (uint)(word)param_1[0x12];
      _sowakeup(param_2,param_2 + 0x3c);
      bVar10 = param_3 == (undefined2 *)0x0;
    }
    break;
  case :
    if (param_5 == (sword *)0x0) {
      sVar5 = *param_1;
    }
    else {
      psVar9 = param_5;
      _unp_internalize();
      bVar10 = param_3 == (undefined2 *)0x0;
      if (psVar9 != (sword *)0x0) break;
      sVar5 = *param_1;
    }
    if (sVar5 == 1) {
      if ((param_1[3] & 0x10U) == 0) {
        if (*(int *)(psVar8 + 6) == 0) {
          _panic(&aUipc3);
          piVar2 = *(int **)(psVar8 + 6);
        }
        else {
          piVar2 = *(int **)(psVar8 + 6);
        }
        param_2 = *piVar2;
        if (param_5 == (sword *)0x0) {
          _sbappend(param_2 + 0x24,param_3);
          iVar3 = *(int *)(psVar8 + 6);
        }
        else {
          _sbappendrights(param_2 + 0x24,param_3,param_5);
          iVar3 = *(int *)(psVar8 + 6);
        }
        param_1[0x21] =
             param_1[0x21] - (*(sword *)(param_2 + 0x28) - (sword)*(undefined4 *)(iVar3 + 0x20));
        *(uint *)(*(int *)(psVar8 + 6) + 0x20) = (uint)*(word *)(param_2 + 0x28);
        param_3 = (undefined2 *)0x0;
        param_1[0x1f] =
             param_1[0x1f] -
             (*(sword *)(param_2 + 0x24) - (sword)*(undefined4 *)(*(int *)(psVar8 + 6) + 0x1c));
        *(uint *)(*(int *)(psVar8 + 6) + 0x1c) = (uint)*(word *)(param_2 + 0x24);
        _sowakeup(param_2,param_2 + 0x24);
        bVar10 = true;
        break;
      }
      psVar9 = (sword *)0x20;
    }
    else {
      if (sVar5 != 2) {
        puVar4 = (undefined *)&aUipc4;
        goto loc_F00229CC;
      }
      if (param_4 == 0) {
        if (*(int *)(psVar8 + 6) != 0) {
          piVar2 = *(int **)(psVar8 + 6);
          goto loc_F0022710;
        }
        psVar9 = (sword *)0x39;
      }
      else {
        psVar9 = (sword *)0x38;
        if (*(int *)(psVar8 + 6) == 0) {
          _unp_connect(param_1,param_4);
          bVar10 = param_3 == (undefined2 *)0x0;
          psVar9 = param_1;
          if (param_1 != (sword *)0x0) break;
          piVar2 = *(int **)(psVar8 + 6);
loc_F0022710:
          iVar3 = *(int *)(psVar8 + 0xc);
          param_2 = *piVar2;
          if (iVar3 == 0) {
            puVar7 = &_sun_noname;
          }
          else {
            puVar7 = (undefined2 *)(iVar3 + *(int *)(iVar3 + 4));
          }
          iVar3 = (uint)*(word *)(param_2 + 0x26) - (uint)*(word *)(param_2 + 0x24);
          iVar6 = (uint)*(word *)(param_2 + 0x2a) - (uint)*(word *)(param_2 + 0x28);
          if (iVar6 < iVar3) {
            iVar3 = iVar6;
          }
          iVar6 = param_2 + 0x24;
          if ((iVar3 < 1) ||
             (iVar3 = iVar6, _sbappendaddr(iVar6,puVar7,param_3,param_5), iVar3 == 0)) {
            psVar9 = (sword *)0x37;
          }
          else {
            _sowakeup(param_2,iVar6);
            param_3 = (undefined2 *)0x0;
          }
          bVar10 = param_3 == (undefined2 *)0x0;
          if (param_4 != 0) goto loc_F00227A4;
          break;
        }
      }
    }
    goto loc_F00229D4;
  case :
    _unp_drop(psVar8,0x35);
    bVar10 = param_3 == (undefined2 *)0x0;
    break;
  :
    puVar4 = aPiusrreq;
loc_F00229CC:
    _panic(puVar4);
    goto loc_F00229D4;
  case :
    wVar1 = param_1[0x1f];
    *(uint *)(param_3 + 0x18) = (uint)wVar1;
    if ((*param_1 == 1) && (*(int **)(psVar8 + 6) != (int *)0x0)) {
      param_2 = **(int **)(psVar8 + 6);
      *(uint *)(param_3 + 0x18) = (uint)wVar1 + (uint)*(word *)(param_2 + 0x24);
    }
    *param_3 = 0xffff;
    iVar3 = *(int *)(psVar8 + 4);
    if (iVar3 == 0) {
      iVar3 = _unp_vno + 1;
      *(int *)(psVar8 + 4) = _unp_vno;
      _unp_vno = iVar3;
      iVar3 = *(int *)(psVar8 + 4);
    }
    *(int *)(param_3 + 2) = iVar3;
    param_3[4] = 0x11b6;
    param_3[5] = 1;
    param_3[6] = *(undefined2 *)(*(int *)(_active_u + 0x1c) + 2);
    param_3[7] = *(undefined2 *)(*(int *)(_active_u + 0x1c) + 4);
    *(uint *)(param_3 + 10) = (uint)(word)param_1[0x12];
    _getthetime((undefined *)((int)register0x00000038 + -0x10));
    *(undefined4 *)(param_3 + 0xc) = *(undefined4 *)((int)register0x00000038 + -0x10);
    *(undefined4 *)(param_3 + 0x10) = *(undefined4 *)((int)register0x00000038 + -0x10);
    psVar9 = (sword *)0x0;
    *(undefined4 *)(param_3 + 0x14) = *(undefined4 *)((int)register0x00000038 + -0x10);
    goto locret_F00229EC;
  case :
    goto loc_F0022428;
  case :
    goto loc_F0022454;
  case :
    bVar10 = param_3 == (undefined2 *)0x0;
    if (*(int *)(psVar8 + 6) != 0) {
      iVar3 = *(int *)(*(int *)(psVar8 + 6) + 0x18);
      bVar10 = param_3 == (undefined2 *)0x0;
      if (iVar3 != 0) {
        sVar5 = *(sword *)(iVar3 + 8);
        goto loc_F0022994;
      }
    }
    break;
  case :
    _unp_connect2(param_1,param_4);
    psVar9 = param_1;
    goto loc_F00229D4;
  }
  if (!bVar10) {
    _m_freem(param_3);
  }
locret_F00229EC:
  return CONCAT44(param_2,psVar9);
}
/* GHIDRADEC_FUNCTION index=477 start=0xf00229f4 */

/* WARNING: Removing unreachable block (ram,0xf0022a64) */
/* WARNING: Removing unreachable block (ram,0xf0022a3c) */
/* WARNING: Removing unreachable block (ram,0xf0022a70) */
/* WARNING: Removing unreachable block (ram,0xf0022a50) */

undefined8 _unp_attach(sword *param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  sword *psVar4;
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
  uVar2 = _unpst_sendspace;
  uVar3 = _unpst_recvspace;
  if ((*param_1 == 1) || (uVar2 = _unpdg_sendspace, uVar3 = _unpdg_recvspace, *param_1 == 2)) {
    psVar4 = param_1;
    _soreserve(param_1,uVar2,uVar3);
  }
  else {
    psVar4 = (sword *)0x0;
    _panic(aUnpAttackBadSo);
  }
  if (psVar4 == (sword *)0x0) {
    puVar1 = (undefined4 *)0x24;
    _kalloc();
    _bzero();
    *(undefined4 **)(param_1 + 4) = puVar1;
    *puVar1 = param_1;
    psVar4 = (sword *)0x0;
  }
  return CONCAT44(param_2,psVar4);
}
/* GHIDRADEC_FUNCTION index=478 start=0xf0022a8c */

/* WARNING: Removing unreachable block (ram,0xf0022b04) */
/* WARNING: Removing unreachable block (ram,0xf0022ae8) */
/* WARNING: Removing unreachable block (ram,0xf0022ac0) */
/* WARNING: Removing unreachable block (ram,0xf0022ad0) */
/* WARNING: Removing unreachable block (ram,0xf0022af8) */
/* WARNING: Removing unreachable block (ram,0xf0022b20) */
/* WARNING: Removing unreachable block (ram,0xf0022aa4) */

undefined8 _unp_detach(int *param_1,undefined4 param_2)

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
  if (param_1[1] == 0) {
    iVar1 = param_1[3];
  }
  else {
    *(undefined4 *)(param_1[1] + 0x20) = 0;
    _vn_rele(param_1[1]);
    param_1[1] = 0;
    iVar1 = param_1[3];
  }
  if (iVar1 == 0) {
    iVar1 = param_1[4];
  }
  else {
    _unp_disconnect(param_1);
    iVar1 = param_1[4];
  }
  while (iVar1 != 0) {
    _unp_drop(param_1[4],0x36);
    iVar1 = param_1[4];
  }
  _soisdisconnected(*param_1);
  *(undefined4 *)(*param_1 + 8) = 0;
  _m_freem(param_1[6]);
  _kfree(param_1,0x24);
  if (_unp_rights != 0) {
    _unp_gc();
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=479 start=0xf0022b30 */

/* WARNING: Removing unreachable block (ram,0xf0022b90) */
/* WARNING: Removing unreachable block (ram,0xf0022bd0) */
/* WARNING: Removing unreachable block (ram,0xf0022b64) */

undefined8 _unp_bind(undefined4 *param_1,int param_2)

{
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  int iVar1;
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
  iVar1 = param_2 + *(int *)(param_2 + 4);
  if ((param_1[1] == 0) && (*(sword *)(param_2 + 8) != 0x70)) {
    *(undefined *)(iVar1 + *(sword *)(param_2 + 8)) = 0;
    _vattr_null((undefined *)((int)register0x00000038 + -0x48));
    *(undefined4 *)((int)register0x00000038 + -0x48) = 6;
    *(undefined2 *)((int)register0x00000038 + -0x44) = 0x1ff;
    iVar1 = iVar1 + 2;
    _vn_create(iVar1,1,(undefined *)((int)register0x00000038 + -0x48),1,0,
               (undefined *)((int)register0x00000038 + -0x4c));
    if (iVar1 == 0) {
      iVar1 = *(int *)((int)register0x00000038 + -0x4c);
      *(undefined4 *)(iVar1 + 0x20) = *param_1;
      param_1[1] = iVar1;
      iVar1 = param_2;
      _m_copy(param_2,0,1000000000);
      param_1[6] = iVar1;
      iVar1 = 0;
    }
    else if (iVar1 == 0x11) {
      iVar1 = 0x30;
    }
  }
  else {
    iVar1 = 0x16;
  }
  return CONCAT44(param_2,iVar1);
}
/* GHIDRADEC_FUNCTION index=480 start=0xf0022be8 */

/* WARNING: Removing unreachable block (ram,0xf0022cb0) */
/* WARNING: Removing unreachable block (ram,0xf0022c94) */
/* WARNING: Removing unreachable block (ram,0xf0022cbc) */
/* WARNING: Removing unreachable block (ram,0xf0022c28) */

undefined8 _unp_connect(sword *param_1,int param_2)

{
  int iVar1;
  sword *psVar2;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  sword *psVar3;
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
  iVar1 = param_2 + *(int *)(param_2 + 4);
  if (*(sword *)(param_2 + 8) + -0xc + *(int *)(param_2 + 4) == 0x70) {
    psVar3 = (sword *)0x28;
    goto locret_F0022CC4;
  }
  *(undefined *)(iVar1 + *(sword *)(param_2 + 8)) = 0;
  psVar3 = (sword *)(iVar1 + 2);
  _lookupname(psVar3,1,1,0,(undefined *)((int)register0x00000038 + -0xc));
  if (psVar3 != (sword *)0x0) goto locret_F0022CC4;
  psVar3 = (sword *)0x26;
  if (*(int *)(*(int *)((int)register0x00000038 + -0xc) + 0x28) == 6) {
    psVar2 = *(sword **)(*(int *)((int)register0x00000038 + -0xc) + 0x20);
    psVar3 = (sword *)0x3d;
    if ((psVar2 != (sword *)0x0) && (psVar3 = (sword *)0x29, *param_1 == *psVar2)) {
      if ((*(word *)(*(int *)(param_1 + 6) + 10) & 4) == 0) {
loc_F0022CB0:
        _unp_connect2(param_1,psVar2);
        psVar3 = param_1;
      }
      else {
        psVar3 = (sword *)0x3d;
        if ((psVar2[1] & 2U) != 0) {
          _sonewconn();
          if (psVar2 != (sword *)0x0) goto loc_F0022CB0;
          psVar3 = (sword *)0x3d;
        }
      }
    }
  }
  _vn_rele(*(undefined4 *)((int)register0x00000038 + -0xc));
locret_F0022CC4:
  return CONCAT44(param_2,psVar3);
}
/* GHIDRADEC_FUNCTION index=481 start=0xf0022ccc */

/* WARNING: Removing unreachable block (ram,0xf0022d44) */
/* WARNING: Removing unreachable block (ram,0xf0022d34) */
/* WARNING: Removing unreachable block (ram,0xf0022d18) */
/* WARNING: Removing unreachable block (ram,0xf0022d2c) */

undefined8 _unp_connect2(sword *param_1,sword *param_2)

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
  iVar2 = *(int *)(param_1 + 4);
  if (*param_2 == *param_1) {
    iVar1 = *(int *)(param_2 + 4);
    *(int *)(iVar2 + 0xc) = iVar1;
    if (*param_1 == 1) {
      *(int *)(iVar1 + 0xc) = iVar2;
      _soisconnected(param_2);
      _soisconnected(param_1);
      uVar3 = 0;
    }
    else if (*param_1 == 2) {
      *(undefined4 *)(iVar2 + 0x14) = *(undefined4 *)(iVar1 + 0x10);
      *(int *)(iVar1 + 0x10) = iVar2;
      _soisconnected(param_1);
      uVar3 = 0;
    }
    else {
      _panic(aUnpConnect2);
      uVar3 = 0;
    }
  }
  else {
    uVar3 = 0x29;
  }
  return CONCAT44(param_2,uVar3);
}
/* GHIDRADEC_FUNCTION index=482 start=0xf0022d58 */

/* WARNING: Removing unreachable block (ram,0xf0022e00) */
/* WARNING: Removing unreachable block (ram,0xf0022db8) */
/* WARNING: Removing unreachable block (ram,0xf0022df4) */

undefined8 _unp_disconnect(int *param_1,undefined4 param_2)

{
  int *piVar1;
  undefined4 unaff_l0;
  undefined4 *puVar2;
  int *piVar3;
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
  puVar2 = (undefined4 *)param_1[3];
  if (puVar2 != (undefined4 *)0x0) {
    param_1[3] = 0;
    if (*(sword *)*param_1 == 1) {
      _soisdisconnected();
      puVar2[3] = 0;
      _soisdisconnected(*puVar2);
    }
    else if (*(sword *)*param_1 == 2) {
      piVar1 = (int *)puVar2[4];
      if ((int *)puVar2[4] == param_1) {
        puVar2[4] = param_1[5];
      }
      else {
        do {
          piVar3 = piVar1;
          if (piVar3 == (int *)0x0) {
            _panic(aUnpDisconnect);
            piVar1 = piRam00000014;
          }
          else {
            piVar1 = (int *)piVar3[5];
          }
        } while (piVar1 != param_1);
        piVar3[5] = param_1[5];
      }
      param_1[5] = 0;
      *(word *)(*param_1 + 6) = *(word *)(*param_1 + 6) & 0xfffd;
    }
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=483 start=0xf0022e10 */

undefined8 _unp_usrclosed(undefined4 param_1,undefined4 param_2)

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
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=484 start=0xf0022e1c */

/* WARNING: Removing unreachable block (ram,0xf0022e50) */
/* WARNING: Removing unreachable block (ram,0xf0022e44) */
/* WARNING: Removing unreachable block (ram,0xf0022e58) */
/* WARNING: Removing unreachable block (ram,0xf0022e28) */

undefined8 _unp_drop(int *param_1,undefined4 param_2)

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
  *(sword *)(iVar1 + 0x56) = (sword)param_2;
  _unp_disconnect(param_1);
  if (*(int *)(iVar1 + 0x10) != 0) {
    *(undefined4 *)(iVar1 + 8) = 0;
    _m_freem(param_1[6]);
    _kfree(param_1,0x24);
    _sofree(iVar1);
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=485 start=0xf0022e68 */

/* WARNING: Removing unreachable block (ram,0xf0022ee8) */
/* WARNING: Removing unreachable block (ram,0xf0022ed4) */
/* WARNING: Removing unreachable block (ram,0xf0022e9c) */
/* WARNING: Removing unreachable block (ram,0xf0022e78) */

undefined8 _unp_externalize(int param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  undefined4 unaff_l0;
  int iVar3;
  undefined4 unaff_l1;
  uint uVar4;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int *piVar5;
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
  iVar1 = *(int *)(param_1 + 4);
  piVar5 = (int *)(param_1 + iVar1);
  uVar4 = (uint)(int)*(sword *)(param_1 + 8) >> 2;
  _ufavail();
  iVar3 = 0;
  if (iVar1 < (int)uVar4) {
    if (uVar4 == 0) {
      uVar6 = 0x28;
    }
    else {
      do {
        iVar3 = iVar3 + 1;
        _unp_discard(*piVar5);
        *piVar5 = 0;
        piVar5 = piVar5 + 1;
      } while (iVar3 < (int)uVar4);
      uVar6 = 0x28;
    }
  }
  else if (uVar4 == 0) {
    uVar6 = 0;
  }
  else {
    do {
      iVar1 = 0;
      _ufalloc();
      if (iVar1 < 0) {
        _panic(aUnpExternalize);
        iVar2 = *piVar5;
      }
      else {
        iVar2 = *piVar5;
      }
      iVar3 = iVar3 + 1;
      _unp_rights = _unp_rights + -1;
      *(int *)(*(int *)(_active_u + 0x14c) + iVar1 * 4) = iVar2;
      *(sword *)(iVar2 + 0x10) = *(sword *)(iVar2 + 0x10) + -1;
      *piVar5 = iVar1;
      piVar5 = piVar5 + 1;
    } while (iVar3 < (int)uVar4);
    uVar6 = 0;
  }
  return CONCAT44(param_2,uVar6);
}
/* GHIDRADEC_FUNCTION index=486 start=0xf0022f3c */

/* WARNING: Removing unreachable block (ram,0xf0022fa4) */
/* WARNING: Removing unreachable block (ram,0xf0022f60) */

undefined8 _unp_internalize(int param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 unaff_l0;
  int *piVar2;
  undefined4 unaff_l1;
  int iVar3;
  uint uVar4;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar5;
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
  iVar3 = 0;
  uVar4 = (uint)(int)*(sword *)(param_1 + 8) >> 2;
  piVar2 = (int *)(param_1 + *(int *)(param_1 + 4));
  if (uVar4 == 0) {
loc_F0022F8C:
    iVar3 = 0;
    piVar2 = (int *)(param_1 + *(int *)(param_1 + 4));
    if (uVar4 != 0) {
      do {
        iVar1 = *piVar2;
        iVar3 = iVar3 + 1;
        _getf();
        *piVar2 = iVar1;
        piVar2 = piVar2 + 1;
        *(sword *)(iVar1 + 0xe) = *(sword *)(iVar1 + 0xe) + 1;
        *(sword *)(iVar1 + 0x10) = *(sword *)(iVar1 + 0x10) + 1;
        _unp_rights = _unp_rights + 1;
      } while (iVar3 < (int)uVar4);
    }
    uVar5 = 0;
  }
  else {
    iVar1 = *piVar2;
    while( true ) {
      piVar2 = piVar2 + 1;
      _getf();
      iVar3 = iVar3 + 1;
      if (iVar1 == 0) break;
      if ((int)uVar4 <= iVar3) goto loc_F0022F8C;
      iVar1 = *piVar2;
    }
    uVar5 = 9;
  }
  return CONCAT44(param_2,uVar5);
}
/* GHIDRADEC_FUNCTION index=487 start=0xf0022fec */

/* WARNING: Removing unreachable block (ram,0xf0023130) */
/* WARNING: Removing unreachable block (ram,0xf00231a8) */
/* WARNING: Removing unreachable block (ram,0xf002311c) */

undefined8 _unp_gc(undefined4 param_1,undefined4 param_2)

{
  sword sVar1;
  uint uVar2;
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
  if (_unp_gcing == 0) {
    _unp_gcing = 1;
loc_F002300C:
    _unp_defer = 0;
    if ((undefined4 **)_file_list != &_file_list) {
      uVar2 = _file_list[2];
      puVar4 = _file_list;
      while( true ) {
        puVar4[2] = uVar2 & 0xffffffcf;
        puVar4 = (undefined4 *)*puVar4;
        if ((undefined4 **)puVar4 == &_file_list) break;
        uVar2 = puVar4[2];
      }
    }
    do {
      if ((undefined4 **)_file_list != &_file_list) {
        sVar1 = *(sword *)((int)_file_list + 0xe);
        puVar4 = _file_list;
        do {
          if (sVar1 == 0) {
            puVar4 = (undefined4 *)*puVar4;
          }
          else {
            uVar2 = puVar4[2];
            if ((uVar2 & 0x20) == 0) {
              if ((uVar2 & 0x10) == 0) {
                if (sVar1 != *(sword *)(puVar4 + 4)) {
                  puVar4[2] = uVar2 | 0x10;
                  goto loc_F00230C8;
                }
                puVar4 = (undefined4 *)*puVar4;
              }
              else {
                puVar4 = (undefined4 *)*puVar4;
              }
            }
            else {
              puVar4[2] = uVar2 & 0xffffffdf;
              _unp_defer = _unp_defer + -1;
loc_F00230C8:
              if (*(sword *)(puVar4 + 3) == 2) {
                iVar3 = puVar4[6];
                if (iVar3 == 0) {
                  puVar4 = (undefined4 *)*puVar4;
                }
                else if (*(undefined **)(*(int *)(iVar3 + 0xc) + 4) == _unixdomain) {
                  if ((*(word *)(*(int *)(iVar3 + 0xc) + 10) & 0x10) == 0) {
                    puVar4 = (undefined4 *)*puVar4;
                  }
                  else {
                    if ((*(word *)(iVar3 + 0x38) & 1) != 0) {
                      _sbwait(iVar3 + 0x24);
                      goto loc_F002300C;
                    }
                    _unp_scan(*(undefined4 *)(iVar3 + 0x30),_unp_mark);
                    puVar4 = (undefined4 *)*puVar4;
                  }
                }
                else {
                  puVar4 = (undefined4 *)*puVar4;
                }
              }
              else {
                puVar4 = (undefined4 *)*puVar4;
              }
            }
          }
          if ((undefined4 **)puVar4 == &_file_list) break;
          sVar1 = *(sword *)((int)puVar4 + 0xe);
        } while( true );
      }
    } while (_unp_defer != 0);
    if ((undefined4 **)_file_list != &_file_list) {
      sVar1 = *(sword *)((int)_file_list + 0xe);
      puVar4 = _file_list;
      while( true ) {
        if (sVar1 == *(sword *)(puVar4 + 4)) {
          if ((puVar4[2] & 0x10) == 0) {
            while (sVar1 != 0) {
              _unp_discard(puVar4);
              sVar1 = *(sword *)(puVar4 + 4);
            }
            puVar4 = (undefined4 *)*_file_list;
          }
          else {
            puVar4 = (undefined4 *)*puVar4;
          }
        }
        else {
          puVar4 = (undefined4 *)*puVar4;
        }
        if ((undefined4 **)puVar4 == &_file_list) break;
        sVar1 = *(sword *)((int)puVar4 + 0xe);
      }
    }
    _unp_gcing = 0;
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=488 start=0xf00231e4 */

/* WARNING: Removing unreachable block (ram,0xf00231f4) */

undefined8 _unp_dispose(int param_1,undefined4 param_2)

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
  if (param_1 != 0) {
    _unp_scan(param_1,_unp_discard);
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=489 start=0xf0023204 */

sqword _unp_scan(undefined4 *param_1,code *param_2)

{
  sword sVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  undefined4 unaff_l0;
  int iVar4;
  undefined4 unaff_l1;
  uint uVar5;
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
  do {
    while( true ) {
      if (param_1 == (undefined4 *)0x0) {
        return ZEXT48(param_2) << 0x20;
      }
      if (param_1 != (undefined4 *)0x0) break;
loc_F0023288:
      param_1 = (undefined4 *)param_1[0x1f];
    }
    sVar1 = *(sword *)((int)param_1 + 10);
    puVar3 = param_1;
loc_F0023224:
    if (sVar1 != 0xc) {
      puVar3 = (undefined4 *)*puVar3;
loc_F002327C:
      if (puVar3 == (undefined4 *)0x0) goto loc_F0023288;
      sVar1 = *(sword *)((int)puVar3 + 10);
      goto loc_F0023224;
    }
    if ((int)*(sword *)(puVar3 + 2) == 0) {
      puVar3 = (undefined4 *)*puVar3;
      goto loc_F002327C;
    }
    iVar4 = 0;
    uVar5 = (uint)(int)*(sword *)(puVar3 + 2) >> 2;
    puVar3 = (undefined4 *)((int)puVar3 + puVar3[1]);
    if (uVar5 == 0) goto loc_F0023288;
    uVar2 = *puVar3;
    while( true ) {
      iVar4 = iVar4 + 1;
      puVar3 = puVar3 + 1;
      (*param_2)(uVar2);
      if ((int)uVar5 <= iVar4) break;
      uVar2 = *puVar3;
    }
    param_1 = (undefined4 *)param_1[0x1f];
  } while( true );
}
/* GHIDRADEC_FUNCTION index=490 start=0xf00232a0 */

undefined8 _unp_mark(uint param_1)

{
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  uint uVar1;
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
  uVar1 = param_1;
  if ((*(uint *)(param_1 + 8) & 0x10) == 0) {
    _unp_defer = _unp_defer + 1;
    uVar1 = *(uint *)(param_1 + 8) | 0x30;
    *(uint *)(param_1 + 8) = uVar1;
  }
  return CONCAT44(param_1,uVar1);
}
/* GHIDRADEC_FUNCTION index=491 start=0xf00232d8 */

/* WARNING: Removing unreachable block (ram,0xf00232f8) */

undefined8 _unp_discard(int param_1,undefined4 param_2)

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
  *(sword *)(param_1 + 0x10) = *(sword *)(param_1 + 0x10) + -1;
  _unp_rights = _unp_rights + -1;
  _closef();
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=492 start=0xf0023308 */

/* WARNING: Removing unreachable block (ram,0xf00239e0) */
/* WARNING: Removing unreachable block (ram,0xf00239f0) */
/* WARNING: Removing unreachable block (ram,0xf0023988) */
/* WARNING: Removing unreachable block (ram,0xf002374c) */
/* WARNING: Removing unreachable block (ram,0xf002373c) */
/* WARNING: Removing unreachable block (ram,0xf0023710) */
/* WARNING: Removing unreachable block (ram,0xf00236e4) */
/* WARNING: Removing unreachable block (ram,0xf00238f0) */
/* WARNING: Removing unreachable block (ram,0xf0023810) */
/* WARNING: Removing unreachable block (ram,0xf0023864) */
/* WARNING: Removing unreachable block (ram,0xf00237a0) */
/* WARNING: Removing unreachable block (ram,0xf00235d0) */
/* WARNING: Removing unreachable block (ram,0xf00235bc) */
/* WARNING: Removing unreachable block (ram,0xf0023520) */
/* WARNING: Removing unreachable block (ram,0xf002341c) */
/* WARNING: Removing unreachable block (ram,0xf00233c8) */
/* WARNING: Removing unreachable block (ram,0xf00234e4) */
/* WARNING: Removing unreachable block (ram,0xf00234b4) */
/* WARNING: Removing unreachable block (ram,0xf002337c) */
/* WARNING: Removing unreachable block (ram,0xf002339c) */
/* WARNING: Removing unreachable block (ram,0xf00233e4) */
/* WARNING: Removing unreachable block (ram,0xf0023488) */
/* WARNING: Removing unreachable block (ram,0xf0023578) */
/* WARNING: Removing unreachable block (ram,0xf00235c4) */
/* WARNING: Removing unreachable block (ram,0xf0023774) */
/* WARNING: Removing unreachable block (ram,0xf0023828) */
/* WARNING: Removing unreachable block (ram,0xf00237f0) */
/* WARNING: Removing unreachable block (ram,0xf00238ac) */
/* WARNING: Removing unreachable block (ram,0xf00236b0) */
/* WARNING: Removing unreachable block (ram,0xf0023708) */
/* WARNING: Removing unreachable block (ram,0xf0023728) */
/* WARNING: Removing unreachable block (ram,0xf0023744) */
/* WARNING: Removing unreachable block (ram,0xf0023980) */
/* WARNING: Removing unreachable block (ram,0xf00239a8) */
/* WARNING: Removing unreachable block (ram,0xf00239fc) */
/* WARNING: Removing unreachable block (ram,0xf0023a08) */
/* WARNING: Removing unreachable block (ram,0xf0023340) */

undefined8 _smount(undefined4 param_1,undefined4 param_2)

{
  sword sVar1;
  word wVar2;
  bool bVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 *puVar6;
  uint uVar7;
  int iVar8;
  undefined *puVar9;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 *puVar10;
  uint *puVar11;
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
  bool bVar12;
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
  puVar11 = *(uint **)(dword_F0133DDC + 0x24);
  *(undefined4 *)((int)register0x00000038 + -0x1c) = 0;
  puVar9 = (undefined *)0x0;
  uVar7 = puVar11[1];
  if ((puVar11[2] & 0x10) == 0) {
    puVar9 = (undefined *)((int)register0x00000038 + -0x1c);
  }
  _lookupname(uVar7,0,1,puVar9,(undefined *)((int)register0x00000038 + -0x20));
  *(char *)(dword_F0133DDC + 0x38) = (char)uVar7;
  if (*(char *)(dword_F0133DDC + 0x38) != '\0') goto locret_F0023A10;
  if (*(int *)((int)register0x00000038 + -0x20) == 0) {
    if ((puVar11[2] & 0x10) != 0) {
      if (*(int *)((int)register0x00000038 + -0x1c) != 0) {
        _vn_rele();
      }
      *(undefined *)(dword_F0133DDC + 0x38) = 2;
      goto locret_F0023A10;
    }
    iVar8 = *(int *)((int)register0x00000038 + -0x1c);
    if ((*(uint *)(*(int *)(iVar8 + 0x24) + 0xc) & 0x20) != 0) goto loc_F00234E4;
    puVar11[2] = puVar11[2] | 0x8000;
    *(int *)((int)register0x00000038 + -0x20) = iVar8;
    *(undefined4 *)((int)register0x00000038 + -0x1c) = 0;
    uVar7 = puVar11[2];
  }
  else {
    iVar8 = *(int *)((int)register0x00000038 + -0x20);
    if (*(int *)((int)register0x00000038 + -0x1c) != 0) {
      _vn_rele();
      iVar8 = *(int *)((int)register0x00000038 + -0x20);
    }
    if ((*(uint *)(*(int *)(iVar8 + 0x24) + 0xc) & 0x20) != 0) {
loc_F00234E4:
      _vn_rele(iVar8);
      *(undefined *)(dword_F0133DDC + 0x38) = 0x16;
      goto locret_F0023A10;
    }
    _dnlc_purge();
    iVar8 = *(int *)((int)register0x00000038 + -0x20);
    if (*(sword *)(iVar8 + 6) != 1) {
      if ((puVar11[2] & 0x10) != 0) {
        iVar4 = *(int *)(iVar8 + 0x28);
        goto loc_F00233D8;
      }
      _vn_rele(iVar8);
loc_F002342C:
      *(undefined *)(dword_F0133DDC + 0x38) = 0x10;
      goto locret_F0023A10;
    }
    iVar4 = *(int *)(iVar8 + 0x28);
loc_F00233D8:
    if (iVar4 != 2) {
      _vn_rele(iVar8);
      *(undefined *)(dword_F0133DDC + 0x38) = 0x14;
      goto locret_F0023A10;
    }
    if ((*(word *)(iVar8 + 4) & 1) == 0) {
      iVar8 = *(int *)((int)register0x00000038 + -0x20);
    }
    else {
      if ((puVar11[2] & 0x10) == 0) {
        _vn_rele(iVar8);
        goto loc_F002342C;
      }
      iVar8 = *(int *)((int)register0x00000038 + -0x20);
    }
    if (((*(word *)(iVar8 + 4) & 1) == 0) || (uVar7 = puVar11[2], (uVar7 & 0x10) == 0)) {
      (**(code **)(*(int *)(iVar8 + 0x1c) + 0x1c))(iVar8,0x80,*(undefined4 *)(_active_u + 0x1c));
      if (iVar8 != 0) {
        _vn_rele(*(undefined4 *)((int)register0x00000038 + -0x20));
        *(char *)(dword_F0133DDC + 0x38) = (char)iVar8;
        goto locret_F0023A10;
      }
      uVar7 = puVar11[2];
    }
  }
  if ((uVar7 & 0x14) == 0) {
    if ((*puVar11 < 5) &&
       (puVar9 = _vfssw + *(int *)(unk_F010BDA8 + *puVar11 * 4) * 8,
       *(int *)(_vfssw + *(int *)(unk_F010BDA8 + *puVar11 * 4) * 8 + 4) != 0)) {
      uVar7 = puVar11[2];
      goto loc_F0023630;
    }
    *(undefined *)(dword_F0133DDC + 0x38) = 0x13;
    goto loc_F0023A04;
  }
  uVar7 = *puVar11;
  _pn_get(uVar7,0,(undefined *)((int)register0x00000038 + -0x18));
  *(char *)(dword_F0133DDC + 0x38) = (char)uVar7;
  uVar5 = *(undefined4 *)((int)register0x00000038 + -0x20);
  if (*(char *)(dword_F0133DDC + 0x38) == '\0') {
    puVar9 = _vfssw;
    iVar8 = _vfssw._0_4_;
    if (_vfssw < _vfsNVFS) {
      do {
        if (iVar8 != 0) {
          iVar8 = *(int *)((int)register0x00000038 + -0x14);
          _strcmp();
          if (iVar8 == 0) break;
        }
        puVar9 = (undefined *)((int)puVar9 + 8);
        if (_vfsNVFS <= puVar9) break;
        iVar8 = *(int *)puVar9;
      } while( true );
    }
    if ((undefined5 *)puVar9 == _vfsNVFS) {
      *(undefined *)(dword_F0133DDC + 0x38) = 0x13;
      _vn_rele(*(undefined4 *)((int)register0x00000038 + -0x20));
      _pn_free((undefined *)((int)register0x00000038 + -0x18));
      goto locret_F0023A10;
    }
    _pn_free((undefined *)((int)register0x00000038 + -0x18));
    uVar7 = puVar11[2];
loc_F0023630:
    bVar3 = false;
    if ((uVar7 & 0x10) == 0) {
      uVar7 = puVar11[1];
      _pn_get(uVar7,0,(undefined *)((int)register0x00000038 + -0x18));
      *(char *)(dword_F0133DDC + 0x38) = (char)uVar7;
      uVar7 = 0;
      if (*(char *)(dword_F0133DDC + 0x38) != '\0') goto loc_F0023A04;
      puVar10 = (undefined4 *)0x12c;
      _kalloc();
      *puVar10 = 0;
      puVar10[1] = *(int *)((int)puVar9 + 4);
      puVar10[3] = 0;
      puVar10[7] = 0;
      puVar10[0x4a] = 0;
      puVar10[0x48] = 0;
      *(undefined2 *)(puVar10 + 0x49) = *(undefined2 *)(*(int *)(_active_u + 0x1c) + 2);
      iVar8 = *(int *)((int)register0x00000038 + -0x14);
      if ((puVar11[2] & 0x8000) == 0) {
        _strncpy(puVar10 + 8,*(undefined4 *)((int)register0x00000038 + -0x14),0xff);
        iVar8 = *(int *)((int)register0x00000038 + -0x20);
        if (*(undefined **)(iVar8 + 0x1c) == _ufs_vnodeops) {
          iVar4 = *(int *)(iVar8 + 0x30);
          while ((*(word *)(iVar4 + 0x44) & 1) != 0) {
            *(word *)(*(int *)(iVar8 + 0x30) + 0x44) =
                 *(word *)(*(int *)(iVar8 + 0x30) + 0x44) | 0x10;
            _sleep(*(undefined4 *)(iVar8 + 0x30),10);
            iVar8 = *(int *)((int)register0x00000038 + -0x20);
            iVar4 = *(int *)(iVar8 + 0x30);
          }
          bVar3 = true;
          *(word *)(*(int *)(*(int *)((int)register0x00000038 + -0x20) + 0x30) + 0x44) =
               *(word *)(*(int *)(*(int *)((int)register0x00000038 + -0x20) + 0x30) + 0x44) | 1;
        }
      }
      else {
        while (iVar4 = iVar8, _index(iVar8,0x2f), iVar4 != 0) {
          iVar8 = iVar4 + 1;
        }
        _strncpy(puVar10 + 8,iVar8,0xff);
      }
      puVar6 = puVar10 + 8;
      if (puVar10 == (undefined4 *)0xffffffe0) {
loc_F00238CC:
        sVar1 = *(sword *)(puVar10 + 0x49);
      }
      else {
        _strncmp(puVar6,aNetAppleshare,0xf);
        if (puVar6 == (undefined4 *)0x0) {
          puVar10[3] = puVar10[3] | 0x100;
          goto loc_F00238CC;
        }
        sVar1 = *(sword *)(puVar10 + 0x49);
      }
      uVar5 = *(undefined4 *)((int)register0x00000038 + -0x20);
      if (sVar1 != 0) {
        puVar11[2] = puVar11[2] | 2;
        uVar5 = *(undefined4 *)((int)register0x00000038 + -0x20);
      }
      _vfs_add(uVar5,puVar10,puVar11[2]);
      *(char *)(dword_F0133DDC + 0x38) = (char)uVar5;
loc_F0023904:
      if (*(char *)(dword_F0133DDC + 0x38) == '\0') {
        puVar6 = puVar10;
        (**(code **)puVar10[1])(puVar10,*(undefined4 *)((int)register0x00000038 + -0x14),puVar11[3])
        ;
        *(char *)(dword_F0133DDC + 0x38) = (char)puVar6;
      }
      iVar8 = *(int *)((int)register0x00000038 + -0x20);
      if (bVar3) {
        *(word *)(*(int *)(iVar8 + 0x30) + 0x44) = *(word *)(*(int *)(iVar8 + 0x30) + 0x44) & 0xfffe
        ;
        wVar2 = *(word *)(*(int *)(iVar8 + 0x30) + 0x44);
        if ((wVar2 & 0x10) != 0) {
          *(word *)(*(int *)(iVar8 + 0x30) + 0x44) = wVar2 & 0xffef;
          _wakeup(*(undefined4 *)(iVar8 + 0x30));
        }
      }
      _pn_free((undefined *)((int)register0x00000038 + -0x18));
      if (*(char *)(dword_F0133DDC + 0x38) == '\0') {
        _vfs_unlock(puVar10);
        uVar5 = *(undefined4 *)((int)register0x00000038 + -0x20);
        if ((puVar11[2] & 0x10) == 0) goto locret_F0023A10;
        puVar10[3] = puVar10[3] & 0xffffffbf;
      }
      else {
        if ((puVar11[2] & 0x10) == 0) {
          _vfs_remove(puVar10);
          _kfree(puVar10,300);
          goto loc_F0023A04;
        }
        puVar10[3] = uVar7;
        _vfs_unlock(puVar10);
        uVar5 = *(undefined4 *)((int)register0x00000038 + -0x20);
      }
    }
    else {
      bVar12 = _rootvfs == (undefined4 *)0x0;
      puVar10 = _rootvfs;
      if (!bVar12) {
        iVar8 = *(int *)((int)register0x00000038 + -0x20);
        do {
          if (*(undefined4 **)(iVar8 + 0x24) == puVar10) {
            if ((*(word *)(iVar8 + 4) & 1) == 0) {
              puVar10 = (undefined4 *)*puVar10;
            }
            else {
              bVar12 = puVar10 == (undefined4 *)0x0;
              if (*(int *)(iVar8 + 0xc) == 0) goto loc_F0023698;
              puVar10 = (undefined4 *)*puVar10;
            }
          }
          else {
            puVar10 = (undefined4 *)*puVar10;
          }
        } while (puVar10 != (undefined4 *)0x0);
        bVar12 = true;
      }
loc_F0023698:
      if (!bVar12) {
        puVar6 = puVar10;
        _vfs_lock();
        *(char *)(dword_F0133DDC + 0x38) = (char)puVar6;
        uVar5 = *(undefined4 *)((int)register0x00000038 + -0x20);
        if (*(char *)(dword_F0133DDC + 0x38) != '\0') goto loc_F0023A08;
        uVar7 = puVar11[1];
        _pn_get(uVar7,0,(undefined *)((int)register0x00000038 + -0x18));
        *(char *)(dword_F0133DDC + 0x38) = (char)uVar7;
        if (*(char *)(dword_F0133DDC + 0x38) != '\0') {
          _vn_rele(*(undefined4 *)((int)register0x00000038 + -0x20));
          _vfs_unlock(puVar10);
          goto locret_F0023A10;
        }
        if ((puVar11[2] & 1) != 0) {
          _printf(aMountCanTRemou);
          *(undefined *)(dword_F0133DDC + 0x38) = 0x16;
          _vfs_unlock(puVar10);
          _vn_rele(*(undefined4 *)((int)register0x00000038 + -0x20));
          _pn_free((undefined *)((int)register0x00000038 + -0x18));
          goto locret_F0023A10;
        }
        uVar7 = puVar10[3];
        puVar10[3] = uVar7 & 0xfffffffe | 0x40;
        goto loc_F0023904;
      }
      *(undefined *)(dword_F0133DDC + 0x38) = 2;
loc_F0023A04:
      uVar5 = *(undefined4 *)((int)register0x00000038 + -0x20);
    }
  }
loc_F0023A08:
  _vn_rele(uVar5);
locret_F0023A10:
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=493 start=0xf0023a18 */

/* WARNING: Removing unreachable block (ram,0xf0023a1c) */

undefined8 _sync(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 unaff_l0;
  undefined *puVar2;
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
  _mfs_sync();
  puVar2 = _vfssw;
  iVar1 = DAT_f010bfdc._0_4_;
  if (_vfssw < _vfsNVFS) {
    while( true ) {
      if (iVar1 != 0) {
        (**(code **)(iVar1 + 0x10))(0);
      }
      if (_vfsNVFS <= puVar2 + 8) break;
      iVar1 = *(int *)(puVar2 + 0xc);
      puVar2 = puVar2 + 8;
    }
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=494 start=0xf0023a78 */

/* WARNING: Removing unreachable block (ram,0xf0023ac0) */
/* WARNING: Removing unreachable block (ram,0xf0023ac8) */
/* WARNING: Removing unreachable block (ram,0xf0023a98) */

undefined8 _statfs(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 *puVar2;
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
  puVar2 = *(undefined4 **)(dword_F0133DDC + 0x24);
  uVar1 = *puVar2;
  _lookupname(uVar1,0,1,0,(undefined *)((int)register0x00000038 + -0xc));
  *(char *)(dword_F0133DDC + 0x38) = (char)uVar1;
  if (*(char *)(dword_F0133DDC + 0x38) == '\0') {
    _cstatfs(*(undefined4 *)(*(int *)((int)register0x00000038 + -0xc) + 0x24),puVar2[1]);
    _vn_rele(*(undefined4 *)((int)register0x00000038 + -0xc));
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=495 start=0xf0023ad8 */

/* WARNING: Removing unreachable block (ram,0xf0023b18) */
/* WARNING: Removing unreachable block (ram,0xf0023aec) */

undefined8 _fstatfs(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 *puVar2;
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
  puVar2 = *(undefined4 **)(dword_F0133DDC + 0x24);
  uVar1 = *puVar2;
  _getvnodefp(uVar1,(undefined *)((int)register0x00000038 + -0xc));
  *(char *)(dword_F0133DDC + 0x38) = (char)uVar1;
  if (*(char *)(dword_F0133DDC + 0x38) == '\0') {
    _cstatfs(*(undefined4 *)(*(int *)(*(int *)((int)register0x00000038 + -0xc) + 0x18) + 0x24),
             puVar2[1]);
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=496 start=0xf0023b28 */

/* WARNING: Removing unreachable block (ram,0xf0023b74) */
/* WARNING: Removing unreachable block (ram,0xf0023b34) */

undefined8 _cstatfs(int param_1,undefined4 param_2)

{
  undefined4 unaff_l0;
  undefined *puVar1;
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
  puVar1 = (undefined *)((int)register0x00000038 + -0x48);
  _bzero(puVar1,0x40);
  (**(code **)(*(int *)(param_1 + 4) + 0xc))(param_1,puVar1);
  *(char *)(dword_F0133DDC + 0x38) = (char)param_1;
  if (*(char *)(dword_F0133DDC + 0x38) == '\0') {
    _copyout(puVar1,param_2,0x40);
    *(char *)(dword_F0133DDC + 0x38) = (char)puVar1;
  }
  return CONCAT44(param_2,DAT_f0133c00);
}
/* GHIDRADEC_FUNCTION index=497 start=0xf0023b8c */

/* WARNING: Removing unreachable block (ram,0xf0023c40) */
/* WARNING: Removing unreachable block (ram,0xf0023c1c) */
/* WARNING: Removing unreachable block (ram,0xf0023bec) */
/* WARNING: Removing unreachable block (ram,0xf0023bf8) */
/* WARNING: Removing unreachable block (ram,0xf0023c38) */
/* WARNING: Removing unreachable block (ram,0xf0023c48) */
/* WARNING: Removing unreachable block (ram,0xf0023bac) */

undefined8 _unmount(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  undefined uVar2;
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
  uVar1 = **(undefined4 **)(dword_F0133DDC + 0x24);
  _lookupname(uVar1,0,1,0,(undefined *)((int)register0x00000038 + -0xc));
  *(char *)(dword_F0133DDC + 0x38) = (char)uVar1;
  if (*(char *)(dword_F0133DDC + 0x38) == '\0') {
    iVar3 = *(int *)((int)register0x00000038 + -0xc);
    if ((*(word *)(iVar3 + 4) & 1) == 0) {
      *(undefined *)(dword_F0133DDC + 0x38) = 0x16;
      _vn_rele(*(undefined4 *)((int)register0x00000038 + -0xc));
    }
    else {
      iVar4 = *(int *)(iVar3 + 0x24);
      _vn_rele(iVar3);
      iVar3 = (int)*(sword *)(iVar4 + 0x124);
      if ((*(sword *)(*(int *)(_active_u + 0x1c) + 2) == iVar3) || (_suser(), iVar3 != 0)) {
        _mfs_cache_clear();
        _vm_object_cache_clear();
        _dounmount();
        uVar2 = (undefined)iVar4;
      }
      else {
        uVar2 = 1;
      }
      *(undefined *)(dword_F0133DDC + 0x38) = uVar2;
    }
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=498 start=0xf0023c64 */

/* WARNING: Removing unreachable block (ram,0xf0023cdc) */
/* WARNING: Removing unreachable block (ram,0xf0023cc8) */
/* WARNING: Removing unreachable block (ram,0xf0023c80) */
/* WARNING: Removing unreachable block (ram,0xf0023cd0) */
/* WARNING: Removing unreachable block (ram,0xf0023cb4) */
/* WARNING: Removing unreachable block (ram,0xf0023c6c) */

undefined8 _dounmount(int param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  int iVar2;
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
  iVar2 = *(int *)(param_1 + 8);
  iVar1 = param_1;
  _vfs_lock();
  if (iVar1 == 0) {
    _dnlc_purge();
    (**(code **)(*(int *)(param_1 + 4) + 0x10))(param_1);
    iVar1 = param_1;
    (**(code **)(*(int *)(param_1 + 4) + 4))();
    if (iVar1 == 0) {
      if (iVar2 != 0) {
        _vn_rele(iVar2);
        _vfs_remove(param_1);
      }
      _kfree(param_1,300);
    }
    else {
      _vfs_unlock(param_1);
    }
  }
  return CONCAT44(param_2,iVar1);
}
/* GHIDRADEC_FUNCTION index=499 start=0xf0023cec */

/* WARNING: Removing unreachable block (ram,0xf0023d18) */

undefined8 _vfssw_lookup(int param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined *puVar3;
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
  puVar3 = _vfssw;
  uVar2 = _vfssw._0_4_;
  if (_vfssw < _vfsNVFS) {
    while (iVar1 = param_1, _strcmp(param_1,uVar2), iVar1 != 0) {
      puVar3 = (undefined *)((int)puVar3 + 8);
      if (_vfsNVFS <= puVar3) {
        puVar3 = (undefined *)0x0;
        break;
      }
      uVar2 = *(undefined4 *)puVar3;
    }
  }
  else {
    puVar3 = (undefined *)0x0;
  }
  return CONCAT44(param_2,puVar3);
}

