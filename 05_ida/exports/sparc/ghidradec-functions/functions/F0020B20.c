
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
