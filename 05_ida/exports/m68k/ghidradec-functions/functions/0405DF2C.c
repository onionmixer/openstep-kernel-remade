
undefined4 _vm_map_insert(int param_1,int param_2,int param_3,uint param_4,uint param_5)

{
  int iVar1;
  int *piVar2;
  int iStack_8;
  
  if (((param_4 < *(uint *)(param_1 + 0x10)) || (*(uint *)(param_1 + 0x14) < param_5)) ||
     (param_5 <= param_4)) {
    return 1;
  }
  iVar1 = _vm_map_lookup_entry(param_1,param_4,&iStack_8);
  if ((iVar1 == 0) &&
     ((param_1 + 8 == *(int *)(iStack_8 + 4) || (param_5 <= *(uint *)(*(int *)(iStack_8 + 4) + 8))))
     ) {
    if ((param_2 == 0) &&
       (((param_1 + 8 != iStack_8 && (param_4 == *(uint *)(iStack_8 + 0xc))) &&
        (((*(byte *)(iStack_8 + 0x18) & 0xa0) == 0 &&
         ((((*(int *)(iStack_8 + 0x22) == 1 && (*(int *)(iStack_8 + 0x1a) == 3)) &&
           (*(int *)(iStack_8 + 0x1e) == 7)) &&
          ((*(sword *)(iStack_8 + 0x26) == 0 &&
           (iVar1 = _vm_object_coalesce(*(undefined4 *)(iStack_8 + 0x10),0,
                                        *(undefined4 *)(iStack_8 + 0x14),0,
                                        param_4 - *(int *)(iStack_8 + 8),param_5 - param_4),
           iVar1 != 0)))))))))) {
      *(int *)(param_1 + 0x24) = (param_5 - *(int *)(iStack_8 + 0xc)) + *(int *)(param_1 + 0x24);
      *(uint *)(iStack_8 + 0xc) = param_5;
    }
    else {
      piVar2 = (int *)__vm_map_entry_create(param_1 + 8);
      piVar2[2] = param_4;
      piVar2[3] = param_5;
      *(byte *)(piVar2 + 6) = *(byte *)(piVar2 + 6) & 0x5f;
      piVar2[4] = param_2;
      piVar2[5] = param_3;
      *(byte *)(piVar2 + 6) = *(byte *)(piVar2 + 6) & 0xed;
      if (*(int *)(param_1 + 0x28) != 0) {
        *(undefined4 *)((int)piVar2 + 0x22) = 1;
        *(undefined4 *)((int)piVar2 + 0x1a) = 3;
        *(undefined4 *)((int)piVar2 + 0x1e) = 7;
        *(undefined2 *)((int)piVar2 + 0x26) = 0;
      }
      *(int *)(param_1 + 0x18) = *(int *)(param_1 + 0x18) + 1;
      *piVar2 = iStack_8;
      piVar2[1] = *(int *)(iStack_8 + 4);
      iVar1 = *piVar2;
      *(int **)piVar2[1] = piVar2;
      *(int **)(iVar1 + 4) = piVar2;
      *(int *)(param_1 + 0x24) = (piVar2[3] - piVar2[2]) + *(int *)(param_1 + 0x24);
      if ((iStack_8 == *(int *)(param_1 + 0x34)) && ((uint)piVar2[2] <= *(uint *)(iStack_8 + 0xc)))
      {
        *(int **)(param_1 + 0x34) = piVar2;
      }
    }
    return 0;
  }
  return 3;
}
