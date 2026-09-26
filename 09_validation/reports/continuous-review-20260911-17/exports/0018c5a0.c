
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 __regparm2 _intr_enable_irq(undefined4 param_1,undefined4 param_2,uint param_3)

{
  byte bVar1;
  undefined4 uVar2;
  ushort uVar3;
  
  if ((param_3 < 0x10) && (param_3 != 2)) {
    bVar1 = (byte)param_3 & 0x1f;
    DAT_001e771e = DAT_001e771e & ((ushort)(-2 << bVar1) | (ushort)(0xfffffffe >> 0x20 - bVar1));
    param_2 = CONCAT22((short)((uint)param_2 >> 0x10),DAT_001e771e);
    uVar3 = DAT_001e771e | (&DAT_001e76e4)[DAT_001e7718];
    if (DAT_001e771c != uVar3) {
      out(0x21,(char)uVar3);
      LOCK();
      UNLOCK();
      param_2 = 0xa1;
      out(0xa1,(char)(uVar3 >> 8));
      LOCK();
      _DAT_001e7618 = _DAT_001e7618 + 2;
      UNLOCK();
      DAT_001e771c = uVar3;
    }
    uVar2 = 1;
  }
  else {
    uVar2 = 0;
  }
  return CONCAT44(param_2,uVar2);
}

