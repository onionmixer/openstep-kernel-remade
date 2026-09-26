
undefined4 _copyoutmsg(undefined4 *param_1,int param_2,uint param_3)

{
  int iVar1;
  undefined4 *puVar2;
  uint uVar3;
  undefined1 *puVar4;
  int in_FS_OFFSET;
  int local_10;
  uint local_c;
  uint local_8;
  
  local_10 = param_2;
  local_8 = param_3;
  *(code **)(_active_threads + 0x74) = __analysis_fragment_0018a018;
  if ((int)param_3 < 0x10) {
    if ((param_3 & 1) != 0) {
      *(undefined1 *)(in_FS_OFFSET + param_2) = *(undefined1 *)param_1;
      param_2 = param_2 + 1;
      param_1 = (undefined4 *)((int)param_1 + 1);
    }
    if ((param_3 & 2) != 0) {
      *(undefined2 *)(in_FS_OFFSET + param_2) = *(undefined2 *)param_1;
      param_2 = param_2 + 2;
      param_1 = (undefined4 *)((int)param_1 + 2);
    }
    iVar1 = (int)param_3 >> 2;
    while (iVar1 = iVar1 + -1, iVar1 != -1) {
      *(undefined4 *)(in_FS_OFFSET + param_2) = *param_1;
      param_2 = param_2 + 4;
      param_1 = param_1 + 1;
    }
    return 0;
  }
  if (((uint)param_1 & 3) != 0) {
    uVar3 = 4 - ((uint)param_1 & 3);
    local_c = param_2;
    puVar2 = param_1;
    if ((uVar3 & 1) != 0) {
      *(undefined1 *)(in_FS_OFFSET + param_2) = *(undefined1 *)param_1;
      local_c = param_2 + 1;
      puVar2 = (undefined4 *)((int)param_1 + 1);
    }
    if ((uVar3 & 2) != 0) {
      *(undefined2 *)(in_FS_OFFSET + local_c) = *(undefined2 *)puVar2;
      local_c = local_c + 2;
      puVar2 = (undefined4 *)((int)puVar2 + 2);
    }
    iVar1 = (int)uVar3 >> 2;
    while (iVar1 = iVar1 + -1, iVar1 != -1) {
      *(undefined4 *)(in_FS_OFFSET + local_c) = *puVar2;
      local_c = local_c + 4;
      puVar2 = puVar2 + 1;
    }
    local_8 = param_3 - uVar3;
    local_10 = param_2 + uVar3;
    param_1 = (undefined4 *)((int)param_1 + uVar3);
  }
  local_c = local_8;
  uVar3 = local_8 & 0xc;
  puVar2 = (undefined4 *)((uVar3 - 0x10) + (int)param_1);
  iVar1 = (uVar3 - 0x10) + local_10;
  if (uVar3 == 4) goto LAB_00189fb5;
  if (uVar3 < 5) {
    if (uVar3 == 0) {
      while (local_c = local_c - 0x10, -1 < (int)local_c) {
        puVar2 = puVar2 + 4;
        iVar1 = iVar1 + 0x10;
        *(undefined4 *)(in_FS_OFFSET + iVar1) = *puVar2;
LAB_00189fa7:
        *(undefined4 *)(in_FS_OFFSET + iVar1 + 4) = puVar2[1];
LAB_00189fae:
        *(undefined4 *)(in_FS_OFFSET + iVar1 + 8) = puVar2[2];
LAB_00189fb5:
        *(undefined4 *)(in_FS_OFFSET + iVar1 + 0xc) = puVar2[3];
      }
    }
  }
  else {
    if (uVar3 == 8) goto LAB_00189fae;
    if (uVar3 == 0xc) goto LAB_00189fa7;
  }
  uVar3 = local_8 & 3;
  if (uVar3 == 0) goto LAB_0018a005;
  puVar4 = (undefined1 *)((int)param_1 + (local_8 & 0xfffffffc));
  local_10 = local_10 + (local_8 & 0xfffffffc);
  if (uVar3 == 2) {
LAB_00189ff3:
    *(undefined1 *)(in_FS_OFFSET + local_10 + 1) = puVar4[1];
  }
  else {
    if (2 < uVar3) {
      if (uVar3 != 3) goto LAB_0018a005;
      *(undefined1 *)(in_FS_OFFSET + local_10 + 2) = puVar4[2];
      goto LAB_00189ff3;
    }
    if (uVar3 != 1) goto LAB_0018a005;
  }
  *(undefined1 *)(in_FS_OFFSET + local_10) = *puVar4;
LAB_0018a005:
  *(undefined4 *)(_active_threads + 0x74) = 0;
  return 0;
}

