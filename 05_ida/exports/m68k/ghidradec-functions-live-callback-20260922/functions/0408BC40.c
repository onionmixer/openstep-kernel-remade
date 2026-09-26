
void _zsselect(word param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = (sword)(param_1 & 0x1f) * 0x86;
  (**(code **)(DAT_40ae4d4 + (char)unk_40B51BC[iVar1 + 0x45] * 0x30))(unk_40B51BC + iVar1,param_2);
  return;
}

