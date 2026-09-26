
undefined4 _setsigvec(uint param_1,uint *param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  uint uVar4;
  uint uVar5;
  bool bVar6;
  
  uVar4 = 1 << (param_1 - 1 & 0x3f);
  iVar1 = *_active_u;
  *(uint *)((int)_active_u + param_1 * 4 + 0x2a) = *param_2;
  if ((*(byte *)(*_active_u + 0x16) & 0x40) == 0) {
    uVar5 = param_2[1] & 0xfffafeff;
  }
  else {
    uVar5 = param_2[1] & 0xfffefeff;
  }
  *(uint *)((int)_active_u + param_1 * 4 + 0xae) = uVar5;
  if ((*(byte *)((int)param_2 + 0xb) & 2) == 0) {
    *(uint *)((int)_active_u + 0x136) = ~uVar4 & *(uint *)((int)_active_u + 0x136);
  }
  else {
    *(uint *)((int)_active_u + 0x136) = uVar4 | *(uint *)((int)_active_u + 0x136);
  }
  if ((*(byte *)((int)param_2 + 0xb) & 1) == 0) {
    *(uint *)((int)_active_u + 0x132) = ~uVar4 & *(uint *)((int)_active_u + 0x132);
  }
  else {
    *(uint *)((int)_active_u + 0x132) = uVar4 | *(uint *)((int)_active_u + 0x132);
  }
  uVar5 = *param_2;
  bVar6 = 1 < uVar5;
  if ((uVar5 == 1) ||
     ((((*(byte *)(iVar1 + 0x16) & 0x40) != 0 && (uVar5 == 0)) &&
      (bVar6 = 0x14 < param_1, param_1 == 0x14)))) {
    *(uint *)(iVar1 + 0x18) = ~uVar4 & *(uint *)(iVar1 + 0x18);
    if ((uVar4 & 0x1ef8) != 0) {
      puVar3 = (undefined4 *)(*(int *)(iVar1 + 0x66) + 0x18);
      for (puVar2 = (undefined4 *)*puVar3; bVar6 = puVar2 < puVar3, puVar2 != puVar3;
          puVar2 = (undefined4 *)puVar2[4]) {
        *(uint *)(puVar2[0x20] + 0x72) = ~uVar4 & *(uint *)(puVar2[0x20] + 0x72);
      }
    }
    *(uint *)(iVar1 + 0x20) = uVar4 | *(uint *)(iVar1 + 0x20);
  }
  else {
    *(uint *)(iVar1 + 0x20) = ~uVar4 & *(uint *)(iVar1 + 0x20);
    if (*param_2 != 0) {
      uVar5 = uVar4 | *(uint *)(iVar1 + 0x24);
      *(uint *)(iVar1 + 0x24) = uVar5;
      goto loc_4008B58;
    }
    if ((*(byte *)(iVar1 + 0x16) & 0x40) != 0) {
      *(undefined4 *)((int)_active_u + param_1 * 4 + 0x2a) = 0;
    }
  }
  uVar5 = ~uVar4 & *(uint *)(iVar1 + 0x24);
  *(uint *)(iVar1 + 0x24) = uVar5;
loc_4008B58:
  return CONCAT22(~(word)(uVar4 >> 0x10),
                  (word)(byte)(bVar6 << 4 | ((int)uVar5 < 0) << 3 | (uVar5 == 0) << 2));
}

