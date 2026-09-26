
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int _spl4(void)

{
  undefined4 *puVar1;
  int iVar2;
  ushort uVar3;
  int *piVar4;
  
  iVar2 = DAT_001e7714;
  if (4 < DAT_001e7714) {
    for (piVar4 = (int *)(&DAT_001e76f4 + DAT_001e7714 * 4); &DAT_001e7704 < piVar4;
        piVar4 = piVar4 + -1) {
      puVar1 = (undefined4 *)*piVar4;
      if (puVar1 != (undefined4 *)0x0) {
        *piVar4 = 0;
        DAT_001e7714 = puVar1[2];
        (*(code *)puVar1[1])(*puVar1,0,4);
      }
    }
    if (4 < DAT_001e7718) {
      uVar3 = DAT_001e76ec | DAT_001e771e;
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
      DAT_001e7718 = 4;
    }
  }
  DAT_001e7714 = 4;
  return iVar2;
}

