
/* WARNING: Removing unreachable block (ram,0xf00b5428) */
/* WARNING: Removing unreachable block (ram,0xf00b54f0) */

undefined8 _esp_handle_msg_out_done(int param_1,undefined4 param_2)

{
  char cVar1;
  word wVar2;
  byte bVar3;
  undefined uVar4;
  int iVar5;
  byte bVar6;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  int iVar7;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar8;
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
  iVar5 = *(int *)(param_1 + 0x9c);
  cVar1 = *(char *)(param_1 + 0x4c);
  iVar7 = *(int *)(*(sword *)(param_1 + 0xb2) * 4 + param_1 + 0xb8);
  wVar2 = *(word *)(iVar7 + 8);
  if (*(char *)(param_1 + 0x44) == ' ') {
    if ((cVar1 == '\f') || (cVar1 == '\x06')) {
      _esp_chip_disconnect(param_1);
      if (cVar1 == '\f') {
        *(undefined *)(param_1 + (uint)wVar2 + 0x5e) = 0;
        *(byte *)(param_1 + 0x78) = *(byte *)(param_1 + 0x78) & ~(byte)(1 << ((byte)wVar2 & 0x1f));
        wVar2 = *(word *)(iVar7 + 0x5c);
      }
      else {
        wVar2 = *(word *)(iVar7 + 0x5c);
      }
      *(undefined *)(iVar7 + 0x28) = 0;
      if ((wVar2 & 0x100) != 0) {
        *(undefined *)(iVar7 + 0x6b) = 1;
      }
      uVar8 = 3;
      goto locret_F00B556C;
    }
    *(char *)(param_1 + 0x52) = cVar1;
loc_F00B5554:
    *(undefined *)(param_1 + 0x53) = 0;
    *(undefined *)(param_1 + 0x42) = *(undefined *)(param_1 + 0x41);
    uVar4 = 0x1a;
  }
  else {
    bVar6 = *(byte *)(param_1 + 0x43) & 7;
    *(undefined *)(iVar5 + 0xc) = 0;
    if ((*(byte *)(iVar5 + 0x1c) & 0x1f) == 0) {
loc_F00B54B8:
      bVar3 = *(byte *)(param_1 + 0x44);
    }
    else {
      if ((bVar6 != 1) || (*(char *)(param_1 + (uint)wVar2 + 0x5e) == '\0')) {
        *(undefined *)(iVar5 + 0xc) = 1;
        goto loc_F00B54B8;
      }
      bVar3 = *(byte *)(param_1 + 0x44);
    }
    if ((bVar3 & 0x10) == 0) {
      bVar3 = *(byte *)(param_1 + 0x53);
loc_F00B551C:
      if (bVar3 == 5) {
        if (cVar1 == '\x01') {
          if (*(char *)(param_1 + 0x4e) == '\x01') {
            *(char *)(param_1 + 0x46) = *(char *)(param_1 + 0x46) + '\x01';
            *(undefined *)(param_1 + 0x52) = 1;
          }
          else {
            *(undefined *)(param_1 + 0x52) = 1;
          }
        }
        else {
          *(char *)(param_1 + 0x52) = cVar1;
        }
      }
      else {
        *(char *)(param_1 + 0x52) = cVar1;
      }
      goto loc_F00B5554;
    }
    bVar3 = *(byte *)(param_1 + 0x53);
    if (bVar6 != 6) goto loc_F00B551C;
    if (1 < bVar3) {
      *(undefined *)(iVar5 + 0xc) = 0x1a;
    }
    _esplog(param_1,3,aScsiBusMessage);
    *(byte *)(iVar7 + 0x2a) = *(byte *)(iVar7 + 0x2a) | 4;
    *(undefined *)(param_1 + 0x42) = *(undefined *)(param_1 + 0x41);
    uVar4 = 3;
  }
  uVar8 = 2;
  *(undefined *)(param_1 + 0x41) = uVar4;
locret_F00B556C:
  return CONCAT44(param_2,uVar8);
}

