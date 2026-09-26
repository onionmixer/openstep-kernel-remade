/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0018c4b4 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 _intr_unregister_irq(uint param_1)

{
  int iVar1;
  undefined4 uVar2;
  ushort uVar3;
  ushort *puVar4;
  int local_8;
  
  if (((param_1 < 0x10) && (param_1 != 2)) &&
     (iVar1 = param_1 * 0xc, *(int *)(&DAT_001e7628 + iVar1) != 0)) {
    *(undefined4 *)(&DAT_001e7624 + iVar1) = 0;
    *(undefined4 *)(&DAT_001e7628 + iVar1) = 0;
    *(undefined4 *)(&DAT_001e762c + iVar1) = 0;
    local_8 = 0;
    puVar4 = &DAT_001e76e4;
    do {
      *puVar4 = *puVar4 | (ushort)(1 << ((byte)param_1 & 0x1f));
      local_8 = local_8 + 1;
      puVar4 = puVar4 + 1;
    } while (local_8 < 8);
    uVar3 = (&DAT_001e76e4)[DAT_001e7718] | DAT_001e771e;
    if (DAT_001e771c != uVar3) {
      out(0x21,(char)uVar3);
      LOCK();
      UNLOCK();
      out(0xa1,(char)(uVar3 >> 8));
      LOCK();
      _DAT_001e7618 = _DAT_001e7618 + 2;
      UNLOCK();
      DAT_001e771c = uVar3;
    }
    _intr_change_mode(param_1,0);
    uVar2 = 1;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}

