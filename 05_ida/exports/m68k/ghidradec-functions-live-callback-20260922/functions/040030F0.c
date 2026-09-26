
void _acct(void)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined uVar6;
  uint uVar7;
  undefined4 **ppuVar8;
  undefined4 *puStack_78;
  int iStack_4c;
  int iStack_48;
  undefined4 auStack_44 [2];
  int iStack_3c;
  int iStack_34;
  
  if (_savacctp != 0) {
    puStack_78 = auStack_44;
    (**(code **)(*(int *)(*(int *)(_savacctp + 0x24) + 4) + 0xc))(*(int *)(_savacctp + 0x24));
    if ((iStack_3c * _acctresume) / 100 < iStack_34) {
      _acctp = _savacctp;
      _savacctp = 0;
      puStack_78 = (undefined4 *)aAccountingResu;
      _printf();
    }
  }
  iVar5 = _acctp;
  if (_acctp != 0) {
    *(sword *)(_acctp + 6) = *(sword *)(_acctp + 6) + 1;
    puStack_78 = auStack_44;
    (**(code **)(*(int *)(*(int *)(iVar5 + 0x24) + 4) + 0xc))(*(int *)(iVar5 + 0x24));
    if ((iStack_3c * _acctsuspend) / 100 < iStack_34) {
      uVar7 = 0;
      do {
        _acctbuf[uVar7] = *(undefined *)(_active_u + 8 + uVar7);
        iVar4 = _active_u;
        uVar7 = uVar7 + 1;
      } while (uVar7 < 10);
      puVar2 = (undefined4 *)(_active_u + 0x166);
      puStack_78 = *(undefined4 **)(_active_u + 0x16a);
      DAT_40b603a._0_2_ = _compress(*puVar2);
      DAT_40b603a._2_2_ = _compress(*(undefined4 *)(iVar4 + 0x16e),*(undefined4 *)(iVar4 + 0x172));
      _microtime(&iStack_4c);
      _timevalsub(&iStack_4c,_active_u + 0x232);
      DAT_40b603a._4_2_ = _compress(iStack_4c,iStack_48);
      DAT_40b603a._6_4_ = *(undefined4 *)(_active_u + 0x232);
      DAT_40b603a._10_2_ = *(undefined2 *)(*(int *)(_active_u + 0x1a) + 6);
      DAT_40b603a._12_2_ = *(undefined2 *)(*(int *)(_active_u + 0x1a) + 8);
      iStack_4c = *(int *)(iVar4 + 0x16e);
      iStack_48 = *(int *)(iVar4 + 0x172);
      puStack_78 = puVar2;
      _timevaladd(&iStack_4c);
      iVar3 = iStack_48 / _tick + _hz * iStack_4c;
      if (iVar3 == 0) {
        DAT_40b603a._14_2_ = 0;
      }
      else {
        DAT_40b603a._14_2_ =
             (undefined2)
             ((*(int *)(iVar4 + 0x182) + *(int *)(iVar4 + 0x17e) + *(int *)(iVar4 + 0x17a)) / iVar3)
        ;
      }
      puStack_78 = (undefined4 *)0x0;
      DAT_40b603a._16_2_ = _compress(*(int *)(iVar4 + 0x196) + *(int *)(iVar4 + 0x192));
      if (*(int *)(_active_u + 0x15e) == 0) {
        DAT_40b603a._18_2_ = 0xffff;
      }
      else {
        DAT_40b603a._18_2_ = *(undefined2 *)(_active_u + 0x162);
      }
      DAT_40b603a[0x14] = *(undefined *)(_active_u + 0x23b);
      uVar1 = *(undefined4 *)(_active_u + 0x1a);
      *(undefined4 *)(_active_u + 0x1a) = _acctcred;
      puStack_78 = (undefined4 *)0x0;
      uVar6 = _vn_rdwr(1,iVar5,_acctbuf,0x20,0,1,3);
      *(undefined *)(dword_40B57D4 + 100) = uVar6;
      *(undefined4 *)(_active_u + 0x1a) = uVar1;
      ppuVar8 = (undefined4 **)&stack0xffffff8c;
    }
    else {
      _savacctp = _acctp;
      _acctp = 0;
      ppuVar8 = &puStack_78;
      puStack_78 = (undefined4 *)aAccountingSusp;
      _printf();
    }
    *(int *)((int)ppuVar8 + -4) = iVar5;
    *(undefined4 *)((int)ppuVar8 + -8) = 0x4003360;
    _vn_rele();
  }
  return;
}

