
/* WARNING: Removing unreachable block (ram,0xf00b8a7c) */
/* WARNING: Removing unreachable block (ram,0xf00b8a50) */
/* WARNING: Removing unreachable block (ram,0xf00b8a28) */
/* WARNING: Removing unreachable block (ram,0xf00b89e0) */
/* WARNING: Removing unreachable block (ram,0xf00b8a14) */
/* WARNING: Removing unreachable block (ram,0xf00b89cc) */
/* WARNING: Removing unreachable block (ram,0xf00b89f8) */
/* WARNING: Removing unreachable block (ram,0xf00b8a3c) */
/* WARNING: Removing unreachable block (ram,0xf00b8a6c) */
/* WARNING: Removing unreachable block (ram,0xf00b8a90) */
/* WARNING: Removing unreachable block (ram,0xf00b899c) */

undefined8 _scsi_std_pktalloc(undefined4 *param_1,int param_2,int param_3,int param_4)

{
  undefined4 uVar1;
  undefined *puVar2;
  undefined4 unaff_l0;
  int iVar3;
  undefined4 unaff_l1;
  int iVar4;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 *puVar5;
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
  iVar4 = 0;
  iVar3 = 0;
  uVar1 = _scsi_spl;
  _splr(_scsi_spl);
  puVar2 = DAT_f0131400;
  puVar5 = dword_F013179C;
  do {
    while (puVar5 == (undefined4 *)0x0) {
      if (param_4 != 1) {
        if (param_4 != 0) {
          sub_F00B8E1C(&dword_F01317A0,param_4);
        }
        goto loc_F00B8A7C;
      }
      _servicing_interrupt();
      if ((undefined4 *)puVar2 != (undefined4 *)0x0) {
        _panic(aScsiStdPktallo);
      }
      puVar2 = (undefined *)&dword_F013179C;
      dword_F011F4A4 = dword_F011F4A4 + 1;
      _sleep(&dword_F013179C,0x14);
      puVar5 = dword_F013179C;
    }
    if (param_2 < 0xd) {
loc_F00B8A48:
      if (param_3 < 4) {
        dword_F013179C = (undefined4 *)*puVar5;
        goto loc_F00B8A7C;
      }
      iVar4 = param_3;
      _kalloc();
      if (iVar4 != 0) {
        _bzero(iVar4,param_3);
        dword_F013179C = (undefined4 *)*puVar5;
loc_F00B8A7C:
        _splx(uVar1);
        if (puVar5 != (undefined4 *)0x0) {
          _bzero(puVar5,0x70);
          if (iVar3 == 0) {
            puVar5[8] = puVar5 + 0x19;
          }
          else {
            puVar5[8] = iVar3;
            *(word *)(puVar5 + 0x17) = *(word *)(puVar5 + 0x17) | 0x40;
          }
          if (iVar4 == 0) {
            puVar5[7] = puVar5 + 0x18;
          }
          else {
            puVar5[7] = iVar4;
            *(word *)(puVar5 + 0x17) = *(word *)(puVar5 + 0x17) | 0x80;
          }
          *(char *)((int)puVar5 + 99) = (char)param_2;
          *(char *)((int)puVar5 + 0x5f) = (char)param_3;
          puVar5[1] = *param_1;
          puVar5[2] = param_1[1];
        }
        return CONCAT44(param_2,puVar5);
      }
    }
    else {
      iVar3 = param_2;
      _kalloc();
      if (iVar3 != 0) {
        _bzero(iVar3,param_2);
        goto loc_F00B8A48;
      }
    }
    puVar2 = (undefined *)0x0;
    puVar5 = (undefined4 *)0x0;
  } while( true );
}

