
undefined4 sub_408935A(undefined8 param_1)

{
  undefined2 *puVar1;
  undefined *puVar2;
  int iVar3;
  undefined4 uVar4;
  undefined *puStack_8;
  
  puVar1 = (undefined2 *)param_1;
  iVar3 = _kmem_alloc_wired(_kernel_map,&puStack_8,0x52);
  puVar2 = puStack_8;
  if (iVar3 != 0) {
    return 0xc;
  }
  _bzero(puStack_8,0x52);
  *(uint *)(puVar2 + 1) =
       *(uint *)(puVar2 + 1) & 0x1fffffff |
       (uint)*(byte *)(*(int *)(_st_std + (sword)((word)((qword)param_1 >> 0x18) >> 0xb) * 0x166) +
                      0x1d) << 0x1d;
  *(undefined4 *)(puStack_8 + 0x18) = 0x78;
  switch(*puVar1) {
  case :
    *puVar2 = 0x10;
    break;
  case :
    *puVar2 = 0x11;
    puVar2[1] = puVar2[1] & 0xfd | 1;
    *(int *)(puStack_8 + 0x18) = *(int *)(puVar1 + 1) * 600;
    break;
  case :
    *puVar2 = 0x11;
    puVar2[1] = puVar2[1] & 0xfd | 1;
    *(int *)(puStack_8 + 0x18) = *(int *)(puVar1 + 1) * 600;
    goto loc_40894A0;
  case :
    *puVar2 = 0x11;
    puVar2[1] = puVar2[1] & 0xfc;
    *(undefined4 *)(puStack_8 + 0x18) = 0x3c;
    break;
  case :
    *puVar2 = 0x11;
    puVar2[1] = puVar2[1] & 0xfc;
    *(undefined4 *)(puStack_8 + 0x18) = 0x3c;
loc_40894A0:
    iVar3 = -*(int *)(puVar1 + 1);
    goto loc_40894A6;
  case :
    *puVar2 = 1;
    goto loc_40894BE;
  case :
    *puVar2 = 0x1b;
loc_40894BE:
    *(undefined4 *)(puStack_8 + 0x18) = 300;
    goto loc_40894D2;
  :
    uVar4 = 0x16;
    goto loc_40894F0;
  }
  iVar3 = *(int *)(puVar1 + 1);
loc_40894A6:
  *(sword *)(puVar2 + 2) = (sword)((uint)iVar3 >> 8);
  puVar2[4] = (char)iVar3;
loc_40894D2:
  *(undefined4 *)(puStack_8 + 0x10) = 0;
  *(undefined4 *)(puStack_8 + 0x3c) = 0;
  uVar4 = sub_40895AC(_st_std + (sword)((word)((qword)param_1 >> 0x18) >> 0xb) * 0x166,puStack_8,0);
loc_40894F0:
  _kmem_free(_kernel_map,puStack_8,0x52);
  return uVar4;
}
