
/* WARNING: Removing unreachable block (ram,0xf00b4ba8) */
/* WARNING: Removing unreachable block (ram,0xf00b4bb8) */
/* WARNING: Removing unreachable block (ram,0xf00b4af0) */

undefined8 _esp_finish(int param_1,undefined4 param_2)

{
  int *piVar1;
  char cVar2;
  byte bVar3;
  word wVar4;
  undefined uVar5;
  int iVar6;
  undefined4 unaff_l0;
  int iVar7;
  undefined4 unaff_l1;
  int iVar8;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
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
  iVar7 = *(int *)(*(sword *)(param_1 + 0xb2) * 4 + param_1 + 0xb8);
  if (-1 < (char)*(byte *)(iVar7 + 0x2b)) {
    _dk_busy = _dk_busy & ~(1 << (*(byte *)(iVar7 + 0x2b) & 0x1f));
  }
  wVar4 = *(word *)(param_1 + 0xb2);
  *(word *)(param_1 + 0xb0) = wVar4;
  *(undefined2 *)(param_1 + 0xb2) = 0xffff;
  *(int *)(param_1 + 0x84) = *(int *)(param_1 + 0x84) + -1;
  cVar2 = *(char *)(param_1 + 0x54);
  bVar3 = *(byte *)(iVar7 + 0x29);
  if ((bVar3 & 0x10) != 0) {
    if ((**(byte **)(iVar7 + 0x1c) & 2) == 0) {
      bVar3 = *(byte *)(iVar7 + 0x29);
    }
    else {
      if (*(char *)(param_1 + (uint)*(word *)(iVar7 + 8) + 0x5e) != '\0') {
        *(byte *)(param_1 + 0x78) =
             *(byte *)(param_1 + 0x78) & ~(byte)(1 << ((byte)*(word *)(iVar7 + 8) & 0x1f));
      }
      bVar3 = *(byte *)(iVar7 + 0x29);
    }
  }
  if ((bVar3 & 8) == 0) {
    uVar5 = *(undefined *)(param_1 + 0x41);
  }
  else {
    if ((*(int *)(iVar7 + 0x50) != 0) && (*(int *)(*(int *)(iVar7 + 0x50) + 4) != 0)) {
      _panic(aEspFinishMoreT);
    }
    iVar8 = iVar7 + 0x48;
    iVar6 = 0;
    if (iVar7 != -0x48) {
      do {
        piVar1 = (int *)(iVar8 + 4);
        iVar8 = *(int *)(iVar8 + 8);
        iVar6 = iVar6 + *piVar1;
      } while (iVar8 != 0);
    }
    *(int *)(iVar7 + 0x24) = *(int *)(iVar7 + 0x40) - iVar6;
    uVar5 = *(undefined *)(param_1 + 0x41);
  }
  *(undefined *)(param_1 + 0x42) = uVar5;
  *(undefined *)(param_1 + 0x41) = 0;
  iVar8 = ((int)((uint)wVar4 << 0x10) >> 0xe) + param_1;
  *(undefined4 *)(iVar8 + 0xb8) = 0;
  if ((*(uint *)(iVar7 + 0x14) & 1) == 0) {
    if ((byte)(cVar2 - 10U) < 2) {
      *(undefined *)(param_1 + 0x41) = 0x1e;
      (**(code **)(iVar7 + 0x10))(iVar7);
      *(undefined *)(param_1 + 0x41) = 0;
      if (*(int *)(iVar8 + 0xb8) == 0) {
        _esplog(param_1,3,aLinkedCommandN);
        param_1 = 8;
      }
      else {
        *(word *)(param_1 + 0xb2) = wVar4;
        _esp_link_start(param_1);
      }
    }
    else {
      (**(code **)(iVar7 + 0x10))(iVar7);
      param_1 = 5;
    }
  }
  else {
    *(int *)(param_1 + 0x80) = *(int *)(param_1 + 0x80) + -1;
    (**(code **)(iVar7 + 0x10))(iVar7);
    param_1 = -1;
  }
  return CONCAT44(param_2,param_1);
}

