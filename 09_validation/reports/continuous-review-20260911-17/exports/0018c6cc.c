
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 __regparm2 _intr_change_ipl(undefined4 param_1,ushort *param_2,uint param_3,uint param_4)

{
  ushort *puVar1;
  undefined4 uVar2;
  ushort uVar3;
  int iVar4;
  ushort *local_8;
  
  if ((((param_3 < 0x10) && (param_3 != 2)) && (param_4 < 8)) &&
     (*(int *)(&DAT_001e7628 + param_3 * 0xc) != 0)) {
    *(uint *)(&DAT_001e762c + param_3 * 0xc) = param_4;
    iVar4 = 0;
    local_8 = &DAT_001e76e4;
    uVar3 = (ushort)(1 << ((byte)param_3 & 0x1f));
    puVar1 = local_8;
    do {
      local_8 = puVar1;
      if (iVar4 < (int)param_4) {
        *local_8 = *local_8 & ~uVar3;
      }
      else {
        *local_8 = *local_8 | uVar3;
      }
      iVar4 = iVar4 + 1;
      puVar1 = local_8 + 1;
    } while (iVar4 < 8);
    uVar3 = (&DAT_001e76e4)[DAT_001e7718] | DAT_001e771e;
    if (DAT_001e771c != uVar3) {
      out(0x21,(char)uVar3);
      LOCK();
      UNLOCK();
      local_8 = (ushort *)0xa1;
      out(0xa1,(char)(uVar3 >> 8));
      LOCK();
      _DAT_001e7618 = _DAT_001e7618 + 2;
      UNLOCK();
      DAT_001e771c = uVar3;
    }
    uVar2 = 1;
    param_2 = local_8;
  }
  else {
    uVar2 = 0;
  }
  return CONCAT44(param_2,uVar2);
}

