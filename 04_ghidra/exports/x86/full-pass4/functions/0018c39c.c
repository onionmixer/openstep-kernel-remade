/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0018c39c */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 __regparm2
_intr_register_irq(undefined4 param_1,undefined *param_2,uint param_3,undefined4 param_4,
                  undefined4 param_5,uint param_6)

{
  int iVar1;
  undefined4 uVar2;
  ushort *puVar3;
  ushort uVar4;
  ushort *local_c;
  ushort local_8;
  
  if (((param_3 < 0x10) && (param_3 != 2)) && (param_6 < 8)) {
    iVar1 = param_3 * 0xc;
    param_2 = &DAT_001e7624;
    if (*(int *)(&DAT_001e7628 + iVar1) == 0) {
      *(undefined4 *)(&DAT_001e7624 + iVar1) = param_5;
      puVar3 = (ushort *)&DAT_001e7624;
      *(undefined4 *)(&DAT_001e7628 + iVar1) = param_4;
      *(uint *)(&DAT_001e762c + iVar1) = param_6;
      iVar1 = 0;
      local_c = &DAT_001e76e4;
      local_8 = (ushort)(1 << ((byte)param_3 & 0x1f));
      do {
        if (iVar1 < (int)param_6) {
          *local_c = *local_c & ~local_8;
        }
        else {
          *local_c = *local_c | local_8;
          puVar3 = local_c;
        }
        iVar1 = iVar1 + 1;
        local_c = local_c + 1;
      } while (iVar1 < 8);
      DAT_001e771e = local_8 | DAT_001e771e;
      param_2 = (undefined *)CONCAT22((short)((uint)puVar3 >> 0x10),DAT_001e771e);
      uVar4 = DAT_001e771e | (&DAT_001e76e4)[DAT_001e7718];
      if (DAT_001e771c != uVar4) {
        out(0x21,(char)uVar4);
        LOCK();
        UNLOCK();
        param_2 = (undefined *)0xa1;
        out(0xa1,(char)(uVar4 >> 8));
        LOCK();
        _DAT_001e7618 = _DAT_001e7618 + 2;
        UNLOCK();
        DAT_001e771c = uVar4;
      }
      uVar2 = 1;
      goto LAB_0018c4aa;
    }
  }
  uVar2 = 0;
LAB_0018c4aa:
  return CONCAT44(param_2,uVar2);
}

