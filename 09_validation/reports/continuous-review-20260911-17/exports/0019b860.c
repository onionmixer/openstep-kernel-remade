
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_0019b860(int param_1,ushort *param_2)

{
  byte bVar1;
  byte bVar2;
  uint uVar3;
  int iVar4;
  undefined1 *puVar5;
  undefined4 uVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  uint uVar10;
  undefined1 *puVar11;
  uint uVar12;
  uint uVar13;
  byte local_20;
  
  iVar7 = _DAT_001e8654;
  uVar3 = *(uint *)(param_1 + 0x1c);
  uVar13 = (uint)*param_2;
  uVar10 = param_2[2] + uVar13;
  uVar9 = (uint)param_2[2];
  if ((int)uVar10 <= *(int *)(uVar3 + 4)) {
    uVar12 = (uint)param_2[3];
    uVar9 = uVar3;
    if ((int)(param_2[1] + uVar12) <= *(int *)(uVar3 + 8)) {
      local_20 = (byte)*(undefined4 *)(param_2 + 4) & 3;
      iVar4 = *(int *)(uVar3 + 0x10);
      out(0x3ce,0);
      LOCK();
      UNLOCK();
      out(0x3cf,'\x03' - local_20);
      LOCK();
      UNLOCK();
      out(0x3ce,8);
      LOCK();
      _DAT_001e8654 = _DAT_001e8654 + 3;
      UNLOCK();
      bVar1 = (&DAT_001e4685)[uVar13 & 7];
      bVar2 = (&DAT_001e468d)[uVar10 & 7];
      puVar11 = (undefined1 *)
                ((uint)param_2[1] * iVar4 + *(int *)(uVar3 + 0x18) + ((int)uVar13 >> 3));
      iVar8 = ((int)uVar10 >> 3) - ((int)uVar13 >> 3);
      if (iVar8 == 0) {
        out(0x3cf,bVar2 & bVar1);
        LOCK();
        _DAT_001e8654 = iVar7 + 4;
        UNLOCK();
        while (uVar12 = uVar12 - 1, -1 < (int)uVar12) {
          *puVar11 = 0xff;
          puVar11 = puVar11 + iVar4;
        }
      }
      else {
        while (uVar12 = uVar12 - 1, -1 < (int)uVar12) {
          out(0x3cf,bVar1);
          LOCK();
          _DAT_001e8654 = _DAT_001e8654 + 1;
          UNLOCK();
          *puVar11 = 0xff;
          out(0x3cf,0xff);
          LOCK();
          _DAT_001e8654 = _DAT_001e8654 + 1;
          UNLOCK();
          puVar5 = puVar11;
          for (iVar7 = iVar8 + -2; puVar5 = puVar5 + 1, -1 < iVar7; iVar7 = iVar7 + -1) {
            *puVar5 = 0xff;
          }
          out(0x3cf,bVar2);
          LOCK();
          _DAT_001e8654 = _DAT_001e8654 + 1;
          UNLOCK();
          *puVar5 = 0xff;
          puVar11 = puVar11 + iVar4;
        }
      }
      uVar9 = 0x3cf;
      out(0x3cf,0xff);
      LOCK();
      _DAT_001e8654 = _DAT_001e8654 + 1;
      UNLOCK();
      uVar6 = 0;
      goto LAB_0019b9be;
    }
  }
  uVar6 = 0xffffffff;
LAB_0019b9be:
  return CONCAT44(uVar9,uVar6);
}

