
/* WARNING: Removing unreachable block (ram,0xf0092174) */
/* WARNING: Removing unreachable block (ram,0xf0092150) */
/* WARNING: Removing unreachable block (ram,0xf009211c) */
/* WARNING: Removing unreachable block (ram,0xf0092164) */
/* WARNING: Removing unreachable block (ram,0xf00921bc) */
/* WARNING: Removing unreachable block (ram,0xf00920f8) */

undefined8 _sdopen(uint param_1,undefined *param_2)

{
  int iVar1;
  undefined8 *puVar2;
  int iVar3;
  undefined (*pauVar4) [20];
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar5;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  undefined auStackX_0 [92];
  
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
  iVar1 = (int)(sword)param_1;
  sub_F0092E34();
  if (iVar1 != 0) {
    iVar3 = iVar1;
    _objc_msgSend(iVar1,paIsdiskready,((uint)param_2 & 4) == 0);
    param_2 = unk_F0131000;
    if (iVar3 == 0) {
      if (dword_F0131248 == 0) {
        puVar2 = &unk_F01124B0;
        _IOGetObjectForDeviceName(&unk_F01124B0,(undefined *)((int)register0x00000038 + -0xc));
        if (puVar2 != (undefined8 *)0x0) {
          _IOPanic(aSdopenCanTFind);
        }
        iVar3 = *(int *)((int)register0x00000038 + -0xc);
        _objc_msgSend(iVar3,paMaxtransfer);
        dword_F0131248 = iVar3;
      }
      if ((param_1 & 7) != 7) {
        pauVar4 = (undefined (*) [20])paSetrawdeviceop;
        if ((param_1 & 0xffff) >> 8 == dword_F0131240) {
          pauVar4 = paSetblockdevice;
        }
        _objc_msgSend(iVar1,pauVar4,1);
      }
      uVar5 = 0;
      goto locret_F00921C8;
    }
  }
  uVar5 = 6;
locret_F00921C8:
  return CONCAT44(param_2,uVar5);
}

