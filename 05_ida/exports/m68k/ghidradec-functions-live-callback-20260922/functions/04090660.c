
undefined4 _in_bootp_closeconsole(int param_1)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  undefined4 uVar12;
  undefined4 uVar13;
  undefined4 uVar14;
  undefined4 uVar15;
  undefined4 uVar16;
  
  (**(code **)(*(int *)(param_1 + 0x1c) + 0xc))(param_1,0x20006b02,0,0x20000000,0);
  puVar1 = _file_list;
  while( true ) {
    if ((undefined4 **)puVar1 == &_file_list) {
      uVar3 = *(undefined4 *)(dword_40B57D4 + 0x28);
      uVar4 = *(undefined4 *)(dword_40B57D4 + 0x2c);
      uVar5 = *(undefined4 *)(dword_40B57D4 + 0x30);
      uVar6 = *(undefined4 *)(dword_40B57D4 + 0x34);
      uVar7 = *(undefined4 *)(dword_40B57D4 + 0x38);
      uVar8 = *(undefined4 *)(dword_40B57D4 + 0x3c);
      uVar9 = *(undefined4 *)(dword_40B57D4 + 0x40);
      uVar10 = *(undefined4 *)(dword_40B57D4 + 0x44);
      uVar11 = *(undefined4 *)(dword_40B57D4 + 0x48);
      uVar12 = *(undefined4 *)(dword_40B57D4 + 0x4c);
      uVar13 = *(undefined4 *)(dword_40B57D4 + 0x50);
      uVar14 = *(undefined4 *)(dword_40B57D4 + 0x54);
      uVar15 = *(undefined4 *)(dword_40B57D4 + 0x58);
      uVar16 = _vn_close(param_1,0);
      iVar2 = dword_40B57D4;
      *(undefined4 *)(dword_40B57D4 + 0x28) = uVar3;
      *(undefined4 *)(iVar2 + 0x2c) = uVar4;
      *(undefined4 *)(iVar2 + 0x30) = uVar5;
      *(undefined4 *)(iVar2 + 0x34) = uVar6;
      *(undefined4 *)(iVar2 + 0x38) = uVar7;
      *(undefined4 *)(iVar2 + 0x3c) = uVar8;
      *(undefined4 *)(iVar2 + 0x40) = uVar9;
      *(undefined4 *)(iVar2 + 0x44) = uVar10;
      *(undefined4 *)(iVar2 + 0x48) = uVar11;
      *(undefined4 *)(iVar2 + 0x4c) = uVar12;
      *(undefined4 *)(iVar2 + 0x50) = uVar13;
      *(undefined4 *)(iVar2 + 0x54) = uVar14;
      *(undefined4 *)(iVar2 + 0x58) = uVar15;
      _vn_rele(param_1);
      return uVar16;
    }
    if ((((*(sword *)(puVar1 + 3) == 1) && (*(sword *)((int)puVar1 + 0xe) != 0)) &&
        (iVar2 = *(int *)((int)puVar1 + 0x16), iVar2 != 0)) &&
       ((*(sword *)(param_1 + 0x2c) == *(sword *)(iVar2 + 0x2c) &&
        (*(int *)(param_1 + 0x28) == *(int *)(iVar2 + 0x28))))) break;
    puVar1 = (undefined4 *)*puVar1;
  }
  _vn_rele(param_1);
  return 0;
}

