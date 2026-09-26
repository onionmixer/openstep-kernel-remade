
/* WARNING: Removing unreachable block (ram,0xf00b5cb8) */
/* WARNING: Removing unreachable block (ram,0xf00b5d08) */
/* WARNING: Removing unreachable block (ram,0xf00b5d88) */
/* WARNING: Removing unreachable block (ram,0xf00b5ce0) */

undefined8 _esp_handle_c_cmplt(int param_1,undefined4 param_2)

{
  char cVar1;
  byte bVar2;
  undefined uVar3;
  char *pcVar4;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  char cVar5;
  char cVar6;
  undefined4 unaff_l3;
  int iVar7;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  int iVar8;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  char cVar9;
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
  cVar1 = *(char *)(param_1 + 0x44);
  iVar8 = *(int *)(param_1 + 0x9c);
  iVar7 = *(int *)(*(sword *)(param_1 + 0xb2) * 4 + param_1 + 0xb8);
  if (cVar1 == ' ') {
    *(undefined *)(param_1 + 0x42) = *(undefined *)(param_1 + 0x41);
    *(undefined *)(param_1 + 0x41) = 0x1a;
    param_1 = 2;
  }
  else {
    bVar2 = *(byte *)(param_1 + 0x43);
    if ((bVar2 & 0x20) != 0) {
      *(byte *)(iVar7 + 0x2a) = *(byte *)(iVar7 + 0x2a) | 4;
    }
    cVar6 = '\0';
    cVar9 = -1;
    if (cVar1 == '\x10') {
      cVar5 = *(char *)(iVar8 + 8);
      if ((bVar2 & 0x20) != 0) {
        cVar5 = '\x02';
        _esplog(param_1,3,aScsiBusStatusP);
        cVar6 = '\x05';
      }
    }
    else {
      cVar5 = *(char *)(iVar8 + 8);
      *(char *)(param_1 + 0x54) = cVar5;
      *(undefined *)(param_1 + 0x54) = *(undefined *)(iVar8 + 8);
      _printf(&unk_F011E768);
      cVar9 = '\0';
      *(undefined *)(param_1 + 0x54) = 0;
      if ((bVar2 & 0x20) != 0) {
        cVar6 = '\t';
        _esplog(param_1,3,_msginperr);
      }
    }
    if (cVar5 != -1) {
      pcVar4 = *(char **)(iVar7 + 0x30);
      *(byte *)(iVar7 + 0x29) = *(byte *)(iVar7 + 0x29) | 0x10;
      *(char **)(iVar7 + 0x30) = pcVar4 + 1;
      *pcVar4 = cVar5;
    }
    if (cVar6 == '\0') {
      if (cVar9 == '\0') {
        uVar3 = *(undefined *)(param_1 + 0x41);
      }
      else {
        if (1 < (byte)(cVar9 - 10U)) {
          *(undefined *)(param_1 + 0x5c) = 1;
          *(undefined *)(param_1 + 0x5d) = 1;
          *(undefined *)(param_1 + 0x42) = *(undefined *)(param_1 + 0x41);
          *(undefined *)(param_1 + 0x41) = 7;
          _esp_handle_msg_in_done();
          goto locret_F00B5DCC;
        }
        uVar3 = *(undefined *)(param_1 + 0x41);
      }
      *(undefined *)(param_1 + 0x42) = uVar3;
      uVar3 = 8;
    }
    else {
      *(char *)(param_1 + 0x4c) = cVar6;
      *(undefined *)(param_1 + 0x53) = 1;
      uVar3 = 0x1a;
      *(undefined *)(param_1 + 0x42) = *(undefined *)(param_1 + 0x41);
    }
    *(undefined *)(param_1 + 0x41) = uVar3;
    if (cVar1 == '\x10') {
      param_1 = 2;
    }
    else {
      *(undefined *)(iVar8 + 0xc) = 0x12;
      param_1 = -1;
    }
  }
locret_F00B5DCC:
  return CONCAT44(param_2,param_1);
}

