
/* WARNING: Removing unreachable block (ram,0xf00b8fb0) */
/* WARNING: Removing unreachable block (ram,0xf00b8f54) */

undefined8 _scsi_poll(int param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 unaff_l0;
  int iVar3;
  undefined4 unaff_l1;
  int iVar4;
  uint uVar5;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 uVar6;
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
  
  iVar1 = dword_F011F4E8;
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
  iVar4 = -1;
  uVar5 = *(uint *)(param_1 + 0x14);
  iVar3 = 0;
  uVar6 = *(undefined4 *)(param_1 + 0x10);
  *(uint *)(param_1 + 0x14) = uVar5 | 1;
  *(code **)(param_1 + 0x10) = _scsi_pollintr;
  if (0 < iVar1) {
    param_2 = 0xffff0000;
    do {
      iVar1 = param_1;
      _pkt_transport();
      if (iVar1 != 1) {
        *(uint *)(param_1 + 0x14) = uVar5;
        goto loc_F00B8FCC;
      }
      if ((*(uint *)(param_1 + 0x28) & 0xffff0000) == 0x1000000) {
        uVar2 = 10000;
      }
      else {
        if (*(char *)(param_1 + 0x28) != '\0') {
          *(uint *)(param_1 + 0x14) = uVar5;
          goto loc_F00B8FCC;
        }
        uVar2 = 1000000;
        if ((**(byte **)(param_1 + 0x1c) & 0x3e) != 8) {
          iVar4 = 0;
          break;
        }
      }
      iVar3 = iVar3 + 1;
      _us_spin(uVar2);
    } while (iVar3 < dword_F011F4E8);
  }
  *(uint *)(param_1 + 0x14) = uVar5;
loc_F00B8FCC:
  *(undefined4 *)(param_1 + 0x10) = uVar6;
  if ((dword_F011F4E8 <= iVar3) && (iVar4 == 0)) {
    iVar4 = iVar3;
  }
  return CONCAT44(param_2,iVar4);
}

