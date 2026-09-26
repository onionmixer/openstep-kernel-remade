
void _in_bootp_openconsole(undefined4 param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
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
  int iVar14;
  
  uVar1 = *(undefined4 *)(dword_40B57D4 + 0x28);
  uVar2 = *(undefined4 *)(dword_40B57D4 + 0x2c);
  uVar3 = *(undefined4 *)(dword_40B57D4 + 0x30);
  uVar4 = *(undefined4 *)(dword_40B57D4 + 0x34);
  uVar5 = *(undefined4 *)(dword_40B57D4 + 0x38);
  uVar6 = *(undefined4 *)(dword_40B57D4 + 0x3c);
  uVar7 = *(undefined4 *)(dword_40B57D4 + 0x40);
  uVar8 = *(undefined4 *)(dword_40B57D4 + 0x44);
  uVar9 = *(undefined4 *)(dword_40B57D4 + 0x48);
  uVar10 = *(undefined4 *)(dword_40B57D4 + 0x4c);
  uVar11 = *(undefined4 *)(dword_40B57D4 + 0x50);
  uVar12 = *(undefined4 *)(dword_40B57D4 + 0x54);
  uVar13 = *(undefined4 *)(dword_40B57D4 + 0x58);
  _vn_open(aDevConsole,1,0x20000002,0,param_1);
  iVar14 = dword_40B57D4;
  *(undefined4 *)(dword_40B57D4 + 0x28) = uVar1;
  *(undefined4 *)(iVar14 + 0x2c) = uVar2;
  *(undefined4 *)(iVar14 + 0x30) = uVar3;
  *(undefined4 *)(iVar14 + 0x34) = uVar4;
  *(undefined4 *)(iVar14 + 0x38) = uVar5;
  *(undefined4 *)(iVar14 + 0x3c) = uVar6;
  *(undefined4 *)(iVar14 + 0x40) = uVar7;
  *(undefined4 *)(iVar14 + 0x44) = uVar8;
  *(undefined4 *)(iVar14 + 0x48) = uVar9;
  *(undefined4 *)(iVar14 + 0x4c) = uVar10;
  *(undefined4 *)(iVar14 + 0x50) = uVar11;
  *(undefined4 *)(iVar14 + 0x54) = uVar12;
  *(undefined4 *)(iVar14 + 0x58) = uVar13;
  return;
}
