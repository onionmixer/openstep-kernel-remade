
int sub_4088A60(undefined8 param_1,int param_2)

{
  undefined4 uVar1;
  int *piVar2;
  undefined *puVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  undefined4 uStack_c;
  undefined *puStack_8;
  
  piVar2 = (int *)param_1;
  iVar4 = (param_1._3_4_ >> 0x1b) * 0x166;
  iVar7 = 0;
  if (1 < param_1._3_4_ >> 0x1b) {
    return 6;
  }
  if (piVar2[1] != 1) {
    return 0x16;
  }
  if (*(int *)(*piVar2 + 4) == 0) {
    return 0;
  }
  iVar5 = _kmem_alloc_wired(_kernel_map,&puStack_8,0x52);
  if (iVar5 != 0) {
    return 0xc;
  }
  iVar5 = _kmem_alloc_wired(_kernel_map,&uStack_c,*(undefined4 *)(*piVar2 + 4));
  puVar3 = puStack_8;
  if (iVar5 != 0) {
    _kmem_free(_kernel_map,puStack_8,0x52);
    return 0xc;
  }
  _bzero(puStack_8,0x52);
  *(uint *)(puVar3 + 1) =
       *(uint *)(puVar3 + 1) & 0x1fffffff |
       (uint)*(byte *)(*(int *)(_st_std + iVar4) + 0x1d) << 0x1d;
  if ((_st_std[iVar4 + 0x67] & 4) == 0) {
    uVar1 = *(undefined4 *)(*piVar2 + 4);
    *(undefined4 *)(puStack_8 + 0x14) = uVar1;
    *(sword *)(puVar3 + 2) = (sword)((uint)uVar1 >> 8);
    puVar3[4] = (char)uVar1;
    if (param_2 == 0) {
      puVar3[1] = (byte)(((uint)(byte)puVar3[1] << 0x1e) >> 0x1e) | 2 | puVar3[1] & 0xfc;
    }
  }
  else {
    uVar6 = (*(uint *)(_st_std + iVar4 + 0x70) + *(int *)(*piVar2 + 4) + -1) /
            *(uint *)(_st_std + iVar4 + 0x70);
    *(sword *)(puVar3 + 2) = (sword)(uVar6 >> 8);
    puVar3[4] = (char)uVar6;
    *(uint *)(puVar3 + 1) = *(uint *)(puVar3 + 1) & 0xfcffffff | 0x1000000;
    *(undefined4 *)(puStack_8 + 0x14) = *(undefined4 *)(*piVar2 + 4);
  }
  if (*(uint3 *)(puVar3 + 2) < 0x1000000) {
    *(undefined4 *)(puStack_8 + 0x10) = uStack_c;
    *(undefined4 *)(puStack_8 + 0x18) = 0x78;
    *(undefined4 *)(puStack_8 + 0x3c) = 0;
    if (param_2 == 0) {
      *puVar3 = 8;
      *(undefined4 *)(puStack_8 + 0xc) = 0;
    }
    else {
      *puVar3 = 10;
      *(undefined4 *)(puStack_8 + 0xc) = 1;
    }
    if ((param_2 != 1) ||
       (iVar7 = _copyinmsg(*(undefined4 *)*piVar2,uStack_c,((undefined4 *)*piVar2)[1]), iVar7 == 0))
    {
      iVar4 = sub_40895AC(_st_std + iVar4,puStack_8,0);
      if (iVar4 == 0) {
        if ((*(int *)(puStack_8 + 0x3c) != 0) && (param_2 == 0)) {
          iVar7 = _copyoutmsg(uStack_c,*(undefined4 *)*piVar2,*(int *)(puStack_8 + 0x3c));
        }
        if (*(int *)(puStack_8 + 0x1c) == 0) goto loc_4088C56;
      }
      iVar7 = 5;
    }
  }
  else {
    iVar7 = 0x16;
  }
loc_4088C56:
  *(int *)((int)piVar2 + 0x12) = *(int *)(*piVar2 + 4) - *(int *)(puStack_8 + 0x3c);
  _kmem_free(_kernel_map,puStack_8,0x52);
  _kmem_free(_kernel_map,uStack_c,*(undefined4 *)(*piVar2 + 4));
  *(char *)(dword_40B57D4 + 100) = (char)iVar7;
  return iVar7;
}
