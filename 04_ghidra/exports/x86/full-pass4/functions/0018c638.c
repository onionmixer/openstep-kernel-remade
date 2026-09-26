/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0018c638 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 __regparm2 _intr_disable_irq(undefined4 param_1,undefined4 param_2,uint param_3)

{
  undefined4 uVar1;
  int iVar2;
  ushort uVar3;
  
  if ((param_3 < 0x10) && (param_3 != 2)) {
    iVar2 = 1 << ((byte)param_3 & 0x1f);
    DAT_001e771e = (ushort)iVar2 | DAT_001e771e;
    param_2 = CONCAT22((short)((uint)iVar2 >> 0x10),DAT_001e771e);
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
    uVar1 = 1;
  }
  else {
    uVar1 = 0;
  }
  return CONCAT44(param_2,uVar1);
}

