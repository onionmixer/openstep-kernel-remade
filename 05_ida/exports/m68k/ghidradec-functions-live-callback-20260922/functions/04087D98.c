
undefined4 sub_4087D98(int param_1,int param_2)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  uint uVar4;
  undefined4 uVar5;
  int *piVar6;
  
  uVar5 = 0;
  if ((*(uint *)(param_2 + 0xc) < *(uint *)(param_2 + 0x20)) &&
     (*(uint *)(param_2 + 0xc) < *(uint *)(param_2 + 8))) {
    piVar2 = (int *)(param_1 + 0x14);
    while (piVar1 = (int *)*piVar2, piVar1 != piVar2) {
      uVar5 = 1;
      piVar6 = (int *)piVar1[0xb];
      if (piVar6 == piVar2) {
        *(int **)(param_1 + 0x18) = piVar2;
      }
      else {
        piVar6[0xc] = (int)piVar2;
      }
      *(int **)(param_1 + 0x14) = piVar6;
      uVar4 = (~_page_mask & *(int *)(param_2 + 0xc) + 1 + _page_mask) - *(int *)(param_2 + 0xc);
      if (*(uint *)(param_2 + 0x14) < uVar4) {
        uVar4 = *(uint *)(param_2 + 0x14);
      }
      if (*(uint *)(param_2 + 8) < uVar4 + *(int *)(param_2 + 0xc)) {
        uVar4 = *(uint *)(param_2 + 8) - *(int *)(param_2 + 0xc);
      }
      *piVar1 = *(undefined4 *)(param_2 + 0xc);
      piVar1[1] = uVar4;
      piVar1[0xd] = 0;
      piVar1[2] = param_2;
      *(uint *)(param_2 + 0xc) = uVar4 + *(int *)(param_2 + 0xc);
      iVar3 = _pmap_resident_extract(*(undefined4 *)(dword_40C6EBC + 0x20),*piVar1);
      piVar1[4] = iVar3;
      if (iVar3 == 0) {
        *(byte *)(param_2 + 0x2d) = *(byte *)(param_2 + 0x2d) | 0x20;
        *(byte *)(param_1 + 0x24) = *(byte *)(param_1 + 0x24) & 0xdf;
        *(uint *)(param_2 + 0xc) = *(int *)(param_2 + 0xc) - uVar4;
        piVar6 = *(int **)(param_1 + 0x18);
        if (piVar6 == piVar2) {
          *piVar2 = (int)piVar1;
          goto loc_4087ED0;
        }
loc_4087ECC:
        piVar6[0xb] = (int)piVar1;
loc_4087ED0:
        piVar1[0xc] = (int)piVar6;
        piVar1[0xb] = param_1 + 0x14;
        *(int **)(param_1 + 0x18) = piVar1;
        *(byte *)(param_1 + 0x24) = *(byte *)(param_1 + 0x24) | 4;
        return 0;
      }
      piVar1[5] = piVar1[1] + iVar3;
      iVar3 = (**(code **)(param_1 + 0x3a))
                        (piVar1,(*(byte *)(param_2 + 0x2d) & 0x7f) >> 6,
                         (*(word *)(param_2 + 0x2c) & 0x1ff) >> 7);
      if (iVar3 == 0) {
        *(uint *)(param_2 + 0xc) = *(int *)(param_2 + 0xc) - uVar4;
        piVar6 = *(int **)(param_1 + 0x18);
        if (piVar6 == piVar2) {
          *piVar6 = (int)piVar1;
          goto loc_4087ED0;
        }
        goto loc_4087ECC;
      }
      if (*(uint *)(param_2 + 0x20) <= *(uint *)(param_2 + 0xc)) {
        return 1;
      }
      if (*(uint *)(param_2 + 8) <= *(uint *)(param_2 + 0xc)) {
        return 1;
      }
    }
  }
  return uVar5;
}

