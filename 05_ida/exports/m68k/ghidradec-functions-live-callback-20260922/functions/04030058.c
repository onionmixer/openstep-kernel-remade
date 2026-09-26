
undefined4 _xdr_opaque(int *param_1,undefined4 param_2,uint param_3)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  undefined *puVar4;
  
  if (param_3 != 0) {
    iVar3 = 0;
    if ((param_3 & 3) != 0) {
      iVar3 = 4 - (param_3 & 3);
    }
    iVar1 = *param_1;
    if (iVar1 == 1) {
      iVar1 = (**(code **)(param_1[1] + 8))(param_1,param_2,param_3);
      if (iVar1 == 0) {
        puVar4 = aXdrOpaqueDecod;
        goto loc_4030108;
      }
      if (iVar3 != 0) {
        uVar2 = (**(code **)(param_1[1] + 8))(param_1,unk_40B359A,iVar3);
        return uVar2;
      }
    }
    else if (iVar1 == 0) {
      iVar1 = (**(code **)(param_1[1] + 0xc))(param_1,param_2,param_3);
      if (iVar1 == 0) {
        puVar4 = aXdrOpaqueEncod;
loc_4030108:
        _printf(puVar4);
        return 0;
      }
      if (iVar3 != 0) {
        uVar2 = (**(code **)(param_1[1] + 0xc))(param_1,&unk_40AF06A,iVar3);
        return uVar2;
      }
    }
    else if (iVar1 != 2) {
      puVar4 = aXdrOpaqueBadOp;
      goto loc_4030108;
    }
  }
  return 1;
}

