
/* WARNING: Removing unreachable block (ram,0xf00d2400) */
/* WARNING: Removing unreachable block (ram,0xf00d23c0) */
/* WARNING: Removing unreachable block (ram,0xf00d239c) */
/* WARNING: Removing unreachable block (ram,0xf00d23d8) */
/* WARNING: Removing unreachable block (ram,0xf00d2418) */
/* WARNING: Removing unreachable block (ram,0xf00d2388) */

undefined8
-[EventDriver evFrameBufferDevicePort:unitName:unitClass:unitPort:]
          (int param_1,undefined4 param_2,int param_3,int param_4,uint param_5,undefined4 *param_6)

{
  undefined6 *puVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  undefined4 uVar5;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int iVar6;
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
  *param_6 = 0;
  if (*(char *)(param_1 + 0x1d0) == '\0') {
    iVar6 = -0x2c2;
  }
  else {
    iVar6 = -0x2c2;
    if (param_3 == *(int *)(param_1 + 0x114)) {
      _IOGetObjectForDeviceName(param_4,(undefined *)((int)register0x00000038 + -0x14));
      if (param_4 != 0) {
        _objc_getClass();
        puVar1 = paProbe_0;
        *(uint *)((int)register0x00000038 + -0x14) = param_5;
        iVar6 = param_4;
        if (param_5 == 0) goto locret_F00D2430;
        _objc_msgSend();
        iVar3 = *(int *)((int)register0x00000038 + -0x14);
        if ((param_5 & 0xff) == 0) goto locret_F00D2430;
        _objc_msgSend(iVar3,puVar1);
        *(int *)((int)register0x00000038 + -0x14) = iVar3;
        if (iVar3 == 0) goto locret_F00D2430;
      }
      uVar2 = paDeviceport_0;
      uVar4 = *(uint *)((int)register0x00000038 + -0x14);
      _objc_msgSend(uVar4,paRespondsto,paDeviceport_0);
      uVar5 = *(undefined4 *)((int)register0x00000038 + -0x14);
      if ((uVar4 & 0xff) == 0) {
        iVar6 = -0x2c1;
      }
      else {
        _objc_msgSend(uVar5,uVar2);
        *param_6 = uVar5;
        iVar6 = 0;
      }
    }
  }
locret_F00D2430:
  return CONCAT44(param_2,iVar6);
}
