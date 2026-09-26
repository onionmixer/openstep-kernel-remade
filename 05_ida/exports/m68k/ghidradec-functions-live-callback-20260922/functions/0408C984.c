
undefined4 sub_408C984(int param_1)

{
  undefined2 uVar1;
  undefined2 extraout_D0u;
  int iVar2;
  int iVar3;
  char cVar4;
  
  iVar2 = param_1 * 0x164;
  cVar4 = ((uint)((char)unk_40B51BC[param_1 * 0x86 + 0x45] * 3) >> 0x1c & 1) != 0;
  iVar3 = (**(code **)(DAT_40ae4d0 + (char)unk_40B51BC[param_1 * 0x86 + 0x45] * 0x30))
                    (unk_40B51BC + param_1 * 0x86,*(uint *)(DAT_40b5420 + iVar2) & 0x10);
  if (iVar3 == 0) {
    iVar3 = sub_408CF32(param_1,0,0);
  }
  uVar1 = (undefined2)((uint)iVar3 >> 0x10);
  if ((DAT_40b5420[iVar2 + 3] & 0x10) != 0) {
    _wakeup(DAT_40b52d0 + iVar2);
    uVar1 = extraout_D0u;
  }
  *(undefined4 *)(DAT_40b5420 + iVar2 + 0xc) = 0;
  return CONCAT22(uVar1,(word)(byte)(cVar4 << 4 | 4));
}

