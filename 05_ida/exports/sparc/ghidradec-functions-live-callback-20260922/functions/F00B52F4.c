
/* WARNING: Removing unreachable block (ram,0xf00b5340) */

undefined8 _esp_handle_msg_out(int param_1,undefined4 param_2)

{
  undefined uVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int iVar5;
  undefined4 uVar6;
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
  iVar4 = *(int *)(param_1 + 0x9c);
  iVar5 = *(int *)(*(sword *)(param_1 + 0xb2) * 4 + param_1 + 0xb8);
  if (((*(byte *)(param_1 + 0x43) & 7) == 6) || (*(char *)(param_1 + 0x42) != '\x04')) {
    *(undefined *)(iVar4 + 0xc) = 1;
    cVar2 = *(char *)(param_1 + 0x53);
    if (cVar2 == '\0') {
      *(undefined *)(param_1 + 0x4c) = 8;
      *(undefined *)(param_1 + 0x53) = 1;
      cVar2 = *(char *)(param_1 + 0x53);
    }
    iVar3 = 0;
    iVar5 = param_1;
    if (cVar2 != '\0') {
      do {
        *(undefined *)(iVar4 + 8) = *(undefined *)(iVar5 + 0x4c);
        iVar3 = iVar3 + 1;
        iVar5 = param_1 + iVar3;
      } while (iVar3 < (int)(uint)*(byte *)(param_1 + 0x53));
    }
    *(undefined *)(iVar4 + 0xc) = 0x10;
    uVar6 = 0xffffffff;
    *(undefined *)(param_1 + 0x42) = *(undefined *)(param_1 + 0x41);
    uVar1 = 4;
  }
  else {
    _esplog(param_1,4,aTargetDRefused,*(undefined2 *)(iVar5 + 8));
    *(undefined *)(iVar5 + 0x28) = 0xb;
    uVar6 = 2;
    *(undefined *)(param_1 + 0x42) = *(undefined *)(param_1 + 0x41);
    uVar1 = 0x1a;
  }
  *(undefined *)(param_1 + 0x41) = uVar1;
  return CONCAT44(param_2,uVar6);
}

