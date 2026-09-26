
/* WARNING: Removing unreachable block (ram,0xf00c5404) */
/* WARNING: Removing unreachable block (ram,0xf00c53ac) */
/* WARNING: Removing unreachable block (ram,0xf00c53cc) */
/* WARNING: Removing unreachable block (ram,0xf00c53ec) */
/* WARNING: Removing unreachable block (ram,0xf00c53b8) */
/* WARNING: Removing unreachable block (ram,0xf00c542c) */
/* WARNING: Removing unreachable block (ram,0xf00c5390) */

undefined8
-[IODevice getCharValues:forParameter:count:]
          (uint param_1,undefined4 param_2,int param_3,int param_4,uint *param_5)

{
  int iVar1;
  undefined4 unaff_l0;
  uint uVar2;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar3;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  uint uVar4;
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
  uVar2 = *param_5;
  if (uVar2 == 0) {
    uVar2 = 0x200;
  }
  iVar1 = param_4;
  _strcmp(param_4,aIoclassname);
  if (iVar1 == 0) {
    _objc_msgSend(param_1,paClass);
    _objc_msgSend();
  }
  else {
    iVar1 = param_4;
    _strcmp(param_4,aIodevicename);
    if (iVar1 == 0) {
      param_1 = param_1 + 8;
    }
    else {
      _strcmp(param_4,aIodevicekind);
      if (param_4 != 0) {
        uVar3 = 0xfffffd39;
        goto locret_F00C543C;
      }
      param_1 = param_1 + 0xa8;
    }
  }
  uVar4 = param_1;
  _strlen();
  if (uVar2 <= uVar4) {
    uVar4 = uVar2 - 1;
  }
  *param_5 = uVar4 + 1;
  _strncpy(param_3,param_1,uVar4);
  *(undefined *)(param_3 + uVar4) = 0;
  uVar3 = 0;
locret_F00C543C:
  return CONCAT44(param_2,uVar3);
}

