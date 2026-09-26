/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0018b2ac */

ushort _in_cksum(undefined4 *param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  ushort uVar3;
  uint uVar4;
  uint *puVar5;
  bool bVar6;
  bool bVar7;
  uint *local_10;
  uint local_c;
  uint local_8;
  
  local_8 = 0;
  do {
    do {
      uVar3 = *(ushort *)(param_1 + 2);
      if ((int)param_2 <= (int)(short)uVar3) {
        puVar5 = (uint *)((int)param_1 + param_1[1]);
        goto LAB_0018b48d;
      }
      local_c = (uint)(short)uVar3;
      puVar5 = (uint *)((int)param_1 + param_1[1]);
      if ((local_c & 1) == 0) {
        bVar6 = false;
        if ((local_c & 2) != 0) {
          uVar2 = (uint)*(ushort *)((int)puVar5 + (local_c - 2));
          bVar6 = CARRY4(local_8,uVar2);
          local_8 = local_8 + uVar2;
        }
      }
      else {
        bVar7 = false;
        if ((uVar3 & 2) != 0) {
          uVar2 = (uint)*(ushort *)((int)puVar5 + (local_c - 3));
          bVar7 = CARRY4(local_8,uVar2);
          local_8 = local_8 + uVar2;
        }
        uVar4 = (uint)*(byte *)((int)puVar5 + (local_c - 1));
        uVar2 = local_8 + uVar4;
        bVar6 = CARRY4(local_8,uVar4) || CARRY4(uVar2,(uint)bVar7);
        local_8 = uVar2 + bVar7;
      }
      local_8 = local_8 + bVar6;
      uVar2 = local_c >> 3;
      if ((local_c >> 2 & 1) != 0) {
        local_8 = local_8 + *puVar5 + (uint)CARRY4(local_8,*puVar5);
        puVar5 = puVar5 + 1;
      }
      if (uVar2 != 0) {
        uVar4 = *puVar5;
        uVar1 = puVar5[1];
        while (uVar2 = uVar2 - 1, uVar2 != 0) {
          bVar7 = CARRY4(local_8,uVar4);
          local_8 = local_8 + uVar4;
          uVar4 = puVar5[2];
          bVar6 = CARRY4(local_8,uVar1);
          local_8 = local_8 + uVar1;
          uVar1 = puVar5[3];
          local_8 = local_8 + bVar7 + (uint)(bVar6 || CARRY4(local_8,(uint)bVar7));
          puVar5 = puVar5 + 2;
        }
        uVar2 = local_8 + uVar4 + uVar1;
        local_8 = uVar2 + CARRY4(local_8,uVar4) +
                  (uint)(CARRY4(local_8 + uVar4,uVar1) || CARRY4(uVar2,(uint)CARRY4(local_8,uVar4)))
        ;
      }
      uVar3 = (ushort)(local_8 >> 0x10);
      local_8 = (uint)(ushort)((ushort)local_8 + uVar3) + (uint)CARRY2((ushort)local_8,uVar3) &
                0xffff;
      param_1 = (undefined4 *)*param_1;
      param_2 = param_2 - local_c;
    } while ((local_c & 1) == 0);
    for (; (int)*(short *)(param_1 + 2) < (int)param_2; param_1 = (undefined4 *)*param_1) {
      local_10 = (uint *)((int)param_1 + param_1[1]);
      if ((local_c & 1) == 0) {
        local_c = (uint)*(short *)(param_1 + 2);
      }
      else {
        local_c = (int)*(short *)(param_1 + 2) - 1;
        param_2 = param_2 - 1;
        local_8 = local_8 + (uint)(byte)*local_10 * 0x100;
        local_10 = (uint *)((int)local_10 + 1);
      }
      if ((local_c & 1) == 0) {
        bVar6 = false;
        if ((local_c & 2) != 0) {
          uVar2 = (uint)*(ushort *)((int)local_10 + (local_c - 2));
          bVar6 = CARRY4(local_8,uVar2);
          local_8 = local_8 + uVar2;
        }
      }
      else {
        bVar7 = false;
        if ((local_c & 2) != 0) {
          uVar2 = (uint)*(ushort *)((int)local_10 + (local_c - 3));
          bVar7 = CARRY4(local_8,uVar2);
          local_8 = local_8 + uVar2;
        }
        uVar4 = (uint)*(byte *)((int)local_10 + (local_c - 1));
        uVar2 = local_8 + uVar4;
        bVar6 = CARRY4(local_8,uVar4) || CARRY4(uVar2,(uint)bVar7);
        local_8 = uVar2 + bVar7;
      }
      local_8 = local_8 + bVar6;
      uVar2 = local_c >> 3;
      if ((local_c >> 2 & 1) != 0) {
        local_8 = local_8 + *local_10 + (uint)CARRY4(local_8,*local_10);
        local_10 = local_10 + 1;
      }
      if (uVar2 != 0) {
        uVar4 = *local_10;
        uVar1 = local_10[1];
        while (uVar2 = uVar2 - 1, uVar2 != 0) {
          bVar7 = CARRY4(local_8,uVar4);
          local_8 = local_8 + uVar4;
          uVar4 = local_10[2];
          bVar6 = CARRY4(local_8,uVar1);
          local_8 = local_8 + uVar1;
          uVar1 = local_10[3];
          local_8 = local_8 + bVar7 + (uint)(bVar6 || CARRY4(local_8,(uint)bVar7));
          local_10 = local_10 + 2;
        }
        uVar2 = local_8 + uVar4 + uVar1;
        local_8 = uVar2 + CARRY4(local_8,uVar4) +
                  (uint)(CARRY4(local_8 + uVar4,uVar1) || CARRY4(uVar2,(uint)CARRY4(local_8,uVar4)))
        ;
      }
      uVar3 = (ushort)(local_8 >> 0x10);
      local_8 = (uint)(ushort)((ushort)local_8 + uVar3) + (uint)CARRY2((ushort)local_8,uVar3) &
                0xffff;
      param_2 = param_2 - local_c;
    }
  } while ((local_c & 1) == 0);
  local_8 = local_8 + (uint)*(byte *)((int)param_1 + param_1[1]) * 0x100;
  puVar5 = (uint *)((byte *)((int)param_1 + param_1[1]) + 1);
  param_2 = param_2 - 1;
LAB_0018b48d:
  if ((param_2 & 1) == 0) {
    bVar6 = false;
    if ((param_2 & 2) != 0) {
      uVar2 = (uint)*(ushort *)((int)puVar5 + (param_2 - 2));
      bVar6 = CARRY4(local_8,uVar2);
      local_8 = local_8 + uVar2;
    }
  }
  else {
    bVar7 = false;
    if ((param_2 & 2) != 0) {
      uVar2 = (uint)*(ushort *)((int)puVar5 + (param_2 - 3));
      bVar7 = CARRY4(local_8,uVar2);
      local_8 = local_8 + uVar2;
    }
    uVar4 = (uint)*(byte *)((int)puVar5 + (param_2 - 1));
    uVar2 = local_8 + uVar4;
    bVar6 = CARRY4(local_8,uVar4) || CARRY4(uVar2,(uint)bVar7);
    local_8 = uVar2 + bVar7;
  }
  local_8 = local_8 + bVar6;
  uVar2 = param_2 >> 3;
  if ((param_2 >> 2 & 1) != 0) {
    local_8 = local_8 + *puVar5 + (uint)CARRY4(local_8,*puVar5);
    puVar5 = puVar5 + 1;
  }
  if (uVar2 != 0) {
    uVar4 = *puVar5;
    uVar1 = puVar5[1];
    while (uVar2 = uVar2 - 1, uVar2 != 0) {
      bVar7 = CARRY4(local_8,uVar4);
      local_8 = local_8 + uVar4;
      uVar4 = puVar5[2];
      bVar6 = CARRY4(local_8,uVar1);
      local_8 = local_8 + uVar1;
      uVar1 = puVar5[3];
      local_8 = local_8 + bVar7 + (uint)(bVar6 || CARRY4(local_8,(uint)bVar7));
      puVar5 = puVar5 + 2;
    }
    uVar2 = local_8 + uVar4 + uVar1;
    local_8 = uVar2 + CARRY4(local_8,uVar4) +
              (uint)(CARRY4(local_8 + uVar4,uVar1) || CARRY4(uVar2,(uint)CARRY4(local_8,uVar4)));
  }
  uVar3 = (ushort)(local_8 >> 0x10);
  return ~((ushort)local_8 + uVar3 + (ushort)CARRY2((ushort)local_8,uVar3));
}

