/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0018c7b0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 _intr_change_mode(uint param_1,int param_2)

{
  byte bVar1;
  int iVar2;
  undefined4 uVar3;
  ushort uVar4;
  
  iVar2 = _eisa_present();
  if (((iVar2 == 0) || (0xf < param_1)) || (*(int *)(&DAT_001e2208 + param_1 * 4) == 0)) {
    uVar3 = 0;
  }
  else {
    if (param_2 == 0) {
      bVar1 = (byte)param_1 & 0x1f;
      uVar4 = DAT_001e7720 & ((ushort)(-2 << bVar1) | (ushort)(0xfffffffe >> 0x20 - bVar1));
    }
    else {
      uVar4 = DAT_001e7720 | (ushort)(1 << ((byte)param_1 & 0x1f));
    }
    if (DAT_001e7720 != uVar4) {
      out(0x4d0,(char)uVar4);
      LOCK();
      UNLOCK();
      out(0x4d1,(char)(uVar4 >> 8));
      LOCK();
      _DAT_001e7618 = _DAT_001e7618 + 2;
      UNLOCK();
      DAT_001e7720 = uVar4;
    }
    uVar3 = 1;
  }
  return uVar3;
}

