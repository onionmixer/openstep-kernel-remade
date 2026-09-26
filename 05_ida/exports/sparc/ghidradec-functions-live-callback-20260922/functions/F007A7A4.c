
/* WARNING: Removing unreachable block (ram,0xf007a820) */

undefined8 _kern_serv_port_serv(int *param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 unaff_l0;
  int iVar2;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int iVar3;
  undefined4 unaff_i1;
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
  iVar3 = *param_1;
  if (*(int *)(iVar3 + 0x4ac) == param_2) {
    *(undefined4 *)(iVar3 + 0x4ac) = 0;
  }
  iVar2 = 0;
  iVar1 = iVar3;
  do {
    if (*(int *)(iVar1 + 0x18c) == param_2) {
      *(undefined4 *)(iVar1 + 0x18c) = 0;
    }
    iVar2 = iVar2 + 1;
    iVar1 = iVar1 + 0x10;
  } while (iVar2 < 0x32);
  iVar2 = 0;
  iVar1 = iVar3;
  do {
    if (*(int *)(iVar1 + 0x18c) == 0) break;
    iVar2 = iVar2 + 1;
    iVar1 = iVar1 + 0x10;
  } while (iVar2 < 0x32);
  iVar1 = 6;
  if (iVar2 != 0x32) {
    iVar1 = *(int *)(iVar3 + 8);
    _port_set_add_EXTERNAL(iVar1,*(undefined4 *)(iVar3 + 0x20),param_2);
    if (iVar1 == 0) {
      iVar3 = iVar3 + iVar2 * 0x10;
      *(int *)(iVar3 + 0x18c) = param_2;
      *(undefined4 *)(iVar3 + 400) = param_3;
      *(undefined4 *)(iVar3 + 0x194) = param_4;
      *(undefined4 *)(iVar3 + 0x198) = 1;
      iVar1 = 0;
    }
  }
  return CONCAT44(param_2,iVar1);
}

