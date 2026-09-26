
byte _in_delmulti(undefined4 *param_1)

{
  undefined4 *puVar1;
  uint uVar2;
  int *piVar3;
  char cVar4;
  char cVar5;
  char cVar6;
  char cVar7;
  byte bVar8;
  undefined auStack_24 [16];
  undefined2 uStack_14;
  undefined4 uStack_10;
  
  uVar2 = param_1[3];
  param_1[3] = uVar2 - 1;
  cVar7 = 1 < uVar2;
  cVar6 = SBORROW4(1,uVar2);
  cVar4 = (int)(1 - uVar2) < 0;
  cVar5 = '\0';
  bVar8 = cVar7;
  if (uVar2 == 1) {
    _igmp_leavegroup(param_1);
    piVar3 = (int *)(param_1[2] + 0x44);
    puVar1 = (undefined4 *)*piVar3;
    while (param_1 != puVar1) {
      piVar3 = (int *)(*piVar3 + 0x14);
      puVar1 = (undefined4 *)*piVar3;
    }
    cVar7 = param_1 < puVar1;
    *piVar3 = *(int *)(*piVar3 + 0x14);
    uStack_14 = 2;
    uStack_10 = *param_1;
    _if_ioctl(param_1[1],0x80206932,auStack_24);
    uVar2 = (uint)param_1 & 0xffffff80;
    cVar4 = (int)uVar2 < 0;
    cVar5 = uVar2 == 0;
    cVar6 = '\0';
    bVar8 = 0;
    _m_free(uVar2);
  }
  return cVar7 << 4 | cVar4 << 3 | cVar5 << 2 | cVar6 << 1 | bVar8;
}

