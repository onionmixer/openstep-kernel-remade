
undefined4 sub_40618D0(int param_1,uint param_2,uint param_3)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  undefined4 uVar5;
  int iVar6;
  
  uVar5 = 0;
  _lock_read(param_1);
  iVar6 = *(int *)(param_1 + 0xc);
  do {
    if (param_1 + 8 == iVar6) {
      _lock_done(param_1);
      return uVar5;
    }
    if ((*(byte *)(iVar6 + 0x18) & 0xa0) == 0) {
      uVar1 = *(uint *)(iVar6 + 8);
      if ((uVar1 <= param_3) && (uVar2 = *(uint *)(iVar6 + 0xc), param_2 < uVar2)) {
        if (param_2 < uVar1) {
          param_2 = uVar1;
        }
        uVar4 = param_3;
        if (uVar2 <= param_3) {
          uVar4 = uVar2;
        }
        iVar3 = (param_2 + *(int *)(iVar6 + 0x14)) - uVar1;
        iVar3 = sub_4061A64(*(undefined4 *)(iVar6 + 0x10),iVar3,(iVar3 + uVar4) - param_2);
        if (iVar3 != 0) goto loc_406195C;
      }
    }
    else {
      iVar3 = sub_40618D0(*(undefined4 *)(iVar6 + 0x10),param_2,param_3);
      if (iVar3 == 5) {
loc_406195C:
        uVar5 = 5;
      }
    }
    iVar6 = *(int *)(iVar6 + 4);
  } while( true );
}
