
undefined8 _forceclose(int param_1)

{
  sword sVar1;
  int iVar2;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 unaff_i1;
  undefined4 *puVar3;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  
  if (!in_DECOMPILE_MODE) {
    *(undefined4 *)(in_CWP * 0x40 + 0x8000) = unaff_i0;
    *(undefined4 *)((in_CWP * 0x10 + 1) * 4 + 0x8000) = unaff_i1;
    *(undefined4 *)((in_CWP * 0x10 + 2) * 4 + 0x8000) = unaff_i2;
    *(undefined4 *)((in_CWP * 0x10 + 3) * 4 + 0x8000) = unaff_i3;
    *(undefined4 *)((in_CWP * 0x10 + 4) * 4 + 0x8000) = unaff_i4;
    *(undefined4 *)((in_CWP * 0x10 + 5) * 4 + 0x8000) = unaff_i5;
    *(undefined4 *)((in_CWP * 0x10 + 6) * 4 + 0x8000) = unaff_fp;
    *(undefined4 *)((in_CWP * 0x10 + 7) * 4 + 0x8000) = unaff_i7;
    *(undefined4 *)((in_CWP * 0x10 + 8) * 4 + 0x8000) = unaff_l0;
    *(undefined4 *)((in_CWP * 0x10 + 9) * 4 + 0x8000) = unaff_l1;
    *(undefined4 *)((in_CWP * 0x10 + 10) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xb) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xc) * 4 + 0x8000) = unaff_l4;
    *(undefined4 *)((in_CWP * 0x10 + 0xd) * 4 + 0x8000) = unaff_l5;
    *(undefined4 *)((in_CWP * 0x10 + 0xe) * 4 + 0x8000) = unaff_l6;
    *(undefined4 *)((in_CWP * 0x10 + 0xf) * 4 + 0x8000) = unaff_l7;
  }
  puVar3 = _file_list;
  if ((undefined4 **)_file_list != &_file_list) {
    param_1 = (int)(sword)param_1;
    sVar1 = *(sword *)((int)_file_list + 0xe);
    while( true ) {
      if (sVar1 == 0) {
        puVar3 = (undefined4 *)*puVar3;
      }
      else if (*(sword *)(puVar3 + 3) == 1) {
        iVar2 = puVar3[6];
        if (iVar2 == 0) {
          puVar3 = (undefined4 *)*puVar3;
        }
        else if ((*(int *)(iVar2 + 0x28) == 4) || (*(int *)(iVar2 + 0x28) == 9)) {
          if (*(sword *)(iVar2 + 0x2c) == param_1) {
            puVar3[2] = puVar3[2] & 0xfffffffc;
            puVar3 = (undefined4 *)*puVar3;
          }
          else {
            puVar3 = (undefined4 *)*puVar3;
          }
        }
        else {
          puVar3 = (undefined4 *)*puVar3;
        }
      }
      else {
        puVar3 = (undefined4 *)*puVar3;
      }
      if ((undefined4 **)puVar3 == &_file_list) break;
      sVar1 = *(sword *)((int)puVar3 + 0xe);
    }
  }
  return CONCAT44(puVar3,param_1);
}
