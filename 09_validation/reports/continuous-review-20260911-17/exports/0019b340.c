
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 __regparm2 FUN_0019b340(undefined4 param_1,uint param_2,int param_3,ushort *param_4)

{
  byte bVar1;
  ushort uVar2;
  int *piVar3;
  undefined4 uVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  int local_28;
  int local_20;
  int local_1c;
  int local_14;
  byte *local_10;
  uint local_8;
  
  piVar3 = *(int **)(param_3 + 0x1c);
  if (((*piVar3 == 2) && (param_2 = (uint)param_4[2], (int)param_2 <= piVar3[1])) &&
     ((int)(uint)param_4[3] <= piVar3[2])) {
    *(byte *)param_4 = (byte)*param_4 & 0xfc;
    uVar2 = param_4[2];
    param_4[2] = uVar2 & 0xfffc;
    param_2 = 0;
    if ((uint)(uVar2 >> 2) * (uint)param_4[3] != 0) {
      out(0x3ce,1);
      LOCK();
      UNLOCK();
      out(0x3cf,0);
      LOCK();
      _DAT_001e8654 = _DAT_001e8654 + 2;
      UNLOCK();
      local_10 = *(byte **)(param_4 + 4);
      uVar6 = (*param_4 & 0xc) >> 2;
      iVar5 = (uint)*param_4 + (uint)param_4[1] * *(int *)(*(int *)(param_3 + 0x1c) + 4) +
              uVar6 * -4;
      if (iVar5 < 0) {
        iVar5 = iVar5 + 7;
      }
      local_14 = *(int *)(*(int *)(param_3 + 0x1c) + 0x18) + (iVar5 >> 3);
      local_1c = 0;
      if (param_4[3] != 0) {
        do {
          iVar5 = 0x1e;
          local_8 = 0;
          local_20 = local_14;
          iVar7 = 0;
          if (param_4[2] != 0) {
LAB_0019b44c:
            do {
              if ((iVar7 == 0) && (local_28 = 0, uVar6 != 0)) {
                do {
                  local_8 = local_8 << 8 | 0xaa;
                  iVar5 = iVar5 + -8;
                  local_28 = local_28 + 1;
                } while (local_28 < (int)uVar6);
              }
              bVar1 = *local_10;
              local_10 = local_10 + 1;
              local_28 = 0;
              do {
                local_8 = local_8 | ((int)(uint)bVar1 >> (6U - (char)local_28 & 0x1f) & 3U) <<
                                    (0x1eU - (char)iVar5 & 0x1f);
                iVar5 = iVar5 + -2;
                local_28 = local_28 + 2;
              } while (local_28 < 8);
              iVar7 = iVar7 + 4;
              if (-1 < iVar5) {
                if (iVar7 < (int)(uint)param_4[2]) goto LAB_0019b44c;
                do {
                  local_8 = local_8 | 2 << (0x1eU - (char)iVar5 & 0x1f);
                  iVar5 = iVar5 + -2;
                } while (-1 < iVar5);
              }
              FUN_0019b0a8(&local_8,local_20);
              iVar5 = 0x1e;
              local_8 = 0;
              local_20 = local_20 + 2;
            } while (iVar7 < (int)(uint)param_4[2]);
          }
          local_14 = local_14 + 0x50;
          local_1c = local_1c + 1;
        } while (local_1c < (int)(uint)param_4[3]);
      }
      out(0x3ce,1);
      LOCK();
      UNLOCK();
      param_2 = 0x3cf;
      out(0x3cf,0xf);
      LOCK();
      _DAT_001e8654 = _DAT_001e8654 + 2;
      UNLOCK();
      uVar4 = 0;
      goto LAB_0019b542;
    }
  }
  uVar4 = 0xffffffff;
LAB_0019b542:
  return CONCAT44(param_2,uVar4);
}

