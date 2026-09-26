
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint _intr_handler(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  byte bVar5;
  ushort uVar6;
  uint uVar7;
  int iVar8;
  undefined1 local_10;
  
  iVar4 = DAT_001e7718;
  iVar3 = DAT_001e7714;
  iVar8 = *(int *)(param_1 + 0x30) + -0x40;
  iVar1 = iVar8 * 0xc;
  __intr_cnt = __intr_cnt + 1;
  if (((iVar8 == 7) && (bVar5 = in(0x20), -1 < (char)bVar5)) ||
     ((iVar8 == 0xf && (bVar5 = in(0xa0), -1 < (char)bVar5)))) {
    uVar7 = (uint)bVar5;
    _DAT_001f7a18 = _DAT_001f7a18 + 1;
    DAT_001e7714 = iVar3;
    DAT_001e7718 = iVar4;
  }
  else {
    iVar2 = *(int *)(&DAT_001e762c + iVar1);
    if ((iVar2 != DAT_001e7718) &&
       (uVar6 = (&DAT_001e76e4)[iVar2] | DAT_001e771e, DAT_001e7718 = iVar2, DAT_001e771c != uVar6))
    {
      local_10 = (undefined1)uVar6;
      out(0x21,local_10);
      LOCK();
      UNLOCK();
      out(0xa1,(char)(uVar6 >> 8));
      LOCK();
      _DAT_001e7618 = _DAT_001e7618 + 2;
      UNLOCK();
      DAT_001e771c = uVar6;
    }
    out(0x20,0x20);
    LOCK();
    UNLOCK();
    out(0xa0,0x20);
    LOCK();
    _DAT_001e7618 = _DAT_001e7618 + 2;
    UNLOCK();
    if (*(int *)(&DAT_001e7628 + iVar1) == 0) {
      uVar7 = _printf(s_intr__dropped_IRQ__d_001e2248,iVar8);
    }
    else if (DAT_001e7714 < *(int *)(&DAT_001e762c + iVar1)) {
      DAT_001e7714 = *(int *)(&DAT_001e762c + iVar1);
      uVar7 = (**(code **)(&DAT_001e7628 + iVar1))
                        (*(undefined4 *)(&DAT_001e7624 + iVar1),param_1,iVar3);
      DAT_001e7714 = iVar3;
      if ((DAT_001e7718 != iVar4) &&
         (uVar6 = (&DAT_001e76e4)[iVar4] | DAT_001e771e, DAT_001e7718 = iVar4, DAT_001e771c != uVar6
         )) {
        out(0x21,(char)uVar6);
        LOCK();
        UNLOCK();
        uVar7 = (uint)(uVar6 >> 8);
        out(0xa1,(char)(uVar6 >> 8));
        LOCK();
        _DAT_001e7618 = _DAT_001e7618 + 2;
        UNLOCK();
        DAT_001e771c = uVar6;
      }
    }
    else {
      _DAT_001f7a14 = _DAT_001f7a14 + 1;
      uVar7 = *(uint *)(&DAT_001e762c + iVar1);
      *(undefined **)(&DAT_001e76f4 + uVar7 * 4) = &DAT_001e7624 + iVar1;
    }
  }
  return uVar7;
}

