
/* WARNING: Removing unreachable block (ram,0xf002e3fc) */
/* WARNING: Removing unreachable block (ram,0xf002e47c) */
/* WARNING: Removing unreachable block (ram,0xf002e4c8) */
/* WARNING: Removing unreachable block (ram,0xf002e384) */
/* WARNING: Removing unreachable block (ram,0xf002e454) */
/* WARNING: Removing unreachable block (ram,0xf002e464) */
/* WARNING: Removing unreachable block (ram,0xf002e3ec) */
/* WARNING: Removing unreachable block (ram,0xf002e2f8) */
/* WARNING: Removing unreachable block (ram,0xf002e290) */
/* WARNING: Removing unreachable block (ram,0xf002e2d0) */
/* WARNING: Removing unreachable block (ram,0xf002e318) */
/* WARNING: Removing unreachable block (ram,0xf002e3ac) */
/* WARNING: Removing unreachable block (ram,0xf002e274) */
/* WARNING: Removing unreachable block (ram,0xf002e4e8) */
/* WARNING: Removing unreachable block (ram,0xf002e48c) */

undefined8 _revarpinput(int param_1,undefined4 *param_2)

{
  word wVar3;
  int iVar1;
  int iVar2;
  undefined4 unaff_l0;
  undefined4 *puVar4;
  int iVar5;
  undefined4 unaff_l1;
  undefined *puVar6;
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
  bool bVar7;
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
  param_2[1] = param_2[1] + 4;
  wVar3 = *(sword *)(param_2 + 2) - 4;
  *(word *)(param_2 + 2) = wVar3;
  iVar1 = (uint)wVar3 * 0x10000;
  if (wVar3 == 0) {
    _spltty();
    if (*(sword *)((int)param_2 + 10) == 0) {
      _panic(&aMfree_6);
    }
    (&word_F0134B0C)[*(sword *)((int)param_2 + 10)] =
         (&word_F0134B0C)[*(sword *)((int)param_2 + 10)] + -1;
    word_F0134B0C = word_F0134B0C + 1;
    *(undefined2 *)((int)param_2 + 10) = 0;
    if (0x7f < (uint)param_2[1]) {
      _mclput(param_2);
    }
    param_2[1] = 0;
    param_2[0x1f] = 0;
    puVar4 = (undefined4 *)*param_2;
    *param_2 = _mfree;
    _mfree = param_2;
    _splx(iVar1);
    if (_m_want != 0) {
      _m_want = 0;
      _wakeup(&_mfree);
    }
    wVar3 = *(word *)(puVar4 + 2);
  }
  else {
    wVar3 = *(word *)(param_2 + 2);
    puVar4 = param_2;
  }
  iVar1 = puVar4[1];
  if ((((0x1b < wVar3) && ((*(word *)(param_1 + 0xc) & 0x80) == 0)) &&
      (*(sword *)((int)puVar4 + iVar1 + 2) == 0x800)) &&
     ((_revarp != 0 && (*(sword *)((int)puVar4 + iVar1 + 6) == 3)))) {
    puVar6 = _arptab;
    iVar5 = -0xfeca98c;
    do {
      if (((*(byte *)(iVar5 + 7) & 4) != 0) &&
         (iVar2 = iVar5, _bcmp(iVar5,(int)puVar4 + iVar1 + 0x12,6), iVar2 == 0)) break;
      puVar6 = puVar6 + 0x14;
      iVar5 = iVar5 + 0x14;
    } while (puVar6 < (undefined *)0xf01363cc);
    if (puVar6 < (undefined *)0xf01363cc) {
      _bcopy((int)puVar4 + iVar1 + 8,(undefined *)((int)register0x00000038 + -0x1e),6);
      _bcopy(puVar6,(int)puVar4 + iVar1 + 0x18,4);
      iVar5 = *(int *)(param_1 + 0x18);
      bVar7 = iVar5 == 0;
      if (!bVar7) {
        iVar2 = *(int *)(iVar5 + 0x20);
        while (iVar2 != param_1) {
          iVar5 = *(int *)(iVar5 + 0x24);
          if (iVar5 == 0) {
            bVar7 = true;
            goto loc_F002E438;
          }
          iVar2 = *(int *)(iVar5 + 0x20);
        }
        _bcopy(iVar5 + 4,(int)puVar4 + iVar1 + 0xe,4);
        bVar7 = iVar5 == 0;
      }
loc_F002E438:
      if (!bVar7) {
        _bcopy(param_1 + 0x60,(int)puVar4 + iVar1 + 8,6);
        _bcopy(param_1 + 0x60,(undefined *)((int)register0x00000038 + -0x18),6);
        *(undefined2 *)((int)register0x00000038 + -0x12) = 0x8035;
        *(undefined2 *)((int)puVar4 + iVar1 + 6) = 4;
        *(undefined2 *)((int)register0x00000038 + -0x20) = 0;
        if (_revarpdebug != 0) {
          _printf(aRevarpReplyToX,*(undefined4 *)((int)puVar4 + iVar1 + 0x18),
                  *(undefined4 *)((int)puVar4 + iVar1 + 0xe));
        }
        (**(code **)(param_1 + 0x34))(param_1,puVar4,(undefined *)((int)register0x00000038 + -0x20))
        ;
        goto locret_F002E4F0;
      }
      if (_revarpdebug != 0) {
        _printf(aRevarpCanTFind);
      }
    }
  }
  _m_freem(puVar4);
locret_F002E4F0:
  return CONCAT44(puVar4,param_1);
}
