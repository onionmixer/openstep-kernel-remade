
/* WARNING: Removing unreachable block (ram,0xf00d76b8) */
/* WARNING: Removing unreachable block (ram,0xf00d76a4) */
/* WARNING: Removing unreachable block (ram,0xf00d76b0) */
/* WARNING: Removing unreachable block (ram,0xf00d76d0) */
/* WARNING: Removing unreachable block (ram,0xf00d768c) */

undefined8 +[IOAudio _inputChannelForSndPort:](undefined4 param_1,undefined4 param_2,uint param_3)

{
  uint uVar1;
  undefined4 unaff_l0;
  uint uVar2;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  uint uVar3;
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
  uVar2 = 0;
  do {
    while( true ) {
      uVar3 = dword_F012EF0C;
      _objc_msgSend(dword_F012EF0C,paCount_0);
      if (uVar3 <= uVar2) {
        uVar3 = 0;
        goto locret_F00D76F0;
      }
      uVar3 = dword_F012EF0C;
      _objc_msgSend(dword_F012EF0C,paObjectat,uVar2);
      uVar1 = uVar3;
      _objc_msgSend();
      _objc_msgSend();
      if (uVar3 == uVar1) break;
      uVar2 = uVar2 + 1;
    }
    uVar1 = uVar3;
    _objc_msgSend(uVar3,paUsersndport);
    uVar2 = uVar2 + 1;
  } while (uVar1 != param_3);
locret_F00D76F0:
  return CONCAT44(param_2,uVar3);
}

