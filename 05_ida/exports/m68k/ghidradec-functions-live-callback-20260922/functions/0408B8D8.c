
undefined4 _zsread(word param_1,undefined4 param_2)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  
  uVar2 = param_1 & 0x1f;
  iVar1 = uVar2 * 0x86;
  uVar3 = (**(code **)(DAT_40ae4b4 + (char)unk_40B51BC[iVar1 + 0x45] * 0x30))
                    (unk_40B51BC + iVar1,param_2);
  if (((DAT_40b5423[uVar2 * 0x164] & 1) == 0) && (-1 < (char)unk_40B51BC[iVar1 + 0x3f])) {
    sub_408C552(uVar2);
  }
  return uVar3;
}

