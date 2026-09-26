/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0018c288 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 _intr_initialize(void)

{
  int iVar1;
  int iVar2;
  undefined2 *puVar3;
  undefined4 uVar4;
  
  out(0x20,0x11);
  LOCK();
  UNLOCK();
  out(0x21,0x40);
  LOCK();
  UNLOCK();
  out(0x21,4);
  LOCK();
  UNLOCK();
  out(0x21,1);
  LOCK();
  UNLOCK();
  out(0x20,0x4b);
  LOCK();
  UNLOCK();
  out(0xa0,0x11);
  LOCK();
  UNLOCK();
  out(0xa1,0x48);
  LOCK();
  UNLOCK();
  out(0xa1,2);
  LOCK();
  UNLOCK();
  out(0xa1,1);
  LOCK();
  UNLOCK();
  uVar4 = 0xa0;
  out(0xa0,0x4b);
  LOCK();
  _DAT_001e7618 = _DAT_001e7618 + 10;
  UNLOCK();
  puVar3 = &DAT_001e76e4;
  iVar1 = 1;
  do {
    iVar2 = iVar1;
    *puVar3 = 0xfffb;
    puVar3 = puVar3 + 1;
    iVar1 = iVar2 + 1;
  } while (iVar2 < 8);
  DAT_001e771e = 0;
  if (DAT_001e7718 != 7) {
    if (DAT_001e771c != DAT_001e76f2) {
      DAT_001e771c = DAT_001e76f2;
      out(0x21,(char)DAT_001e76f2);
      LOCK();
      UNLOCK();
      iVar2 = CONCAT22((short)((uint)puVar3 >> 0x10),DAT_001e76f2 >> 8);
      uVar4 = 0xa1;
      out(0xa1,(char)(DAT_001e76f2 >> 8));
      LOCK();
      _DAT_001e7618 = _DAT_001e7618 + 2;
      UNLOCK();
    }
    DAT_001e7718 = 7;
  }
  DAT_001e7714 = 7;
  return CONCAT44(uVar4,iVar2);
}

