
/* WARNING: Removing unreachable block (ram,0xf00a73f4) */
/* WARNING: Removing unreachable block (ram,0xf00a73d4) */
/* WARNING: Removing unreachable block (ram,0xf00a7424) */
/* WARNING: Removing unreachable block (ram,0xf00a7390) */

undefined8 sub_F00A7380(undefined4 param_1,undefined4 param_2)

{
  bool bVar1;
  undefined (*pauVar2) [9];
  undefined (*pauVar3) [12];
  undefined *puVar4;
  uint uVar5;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  int iVar6;
  undefined4 unaff_l3;
  undefined *puVar7;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar8;
  undefined (*pauVar9) [9];
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
  pauVar2 = paScsidisk_0;
  _objc_msgSend(paScsidisk_0,paRequiredprotoc);
  uVar8 = 1;
  if ((pauVar2 != (undefined (*) [9])0x0) && (iVar6 = 0, *(int *)*pauVar2 != 0)) {
    puVar7 = (undefined *)((int)register0x00000038 + -0x58);
    do {
      while( true ) {
        pauVar3 = paIodevice_0;
        _objc_msgSend(paIodevice_0,paLookupbyobject_0,iVar6,
                      (undefined *)((int)register0x00000038 + -0xa8),puVar7);
        if ((pauVar3 != (undefined (*) [12])0x0) &&
           (uVar8 = 0, pauVar3 != (undefined (*) [12])0xfffffd29)) goto locret_F00A7468;
        puVar4 = puVar7;
        _IOGetObjectForDeviceName(puVar7,(undefined *)((int)register0x00000038 + -0xac));
        if (puVar4 == (undefined *)0x0) break;
        iVar6 = iVar6 + 1;
      }
      bVar1 = true;
      if (*(int *)*pauVar2 != 0) {
        uVar5 = *(uint *)((int)register0x00000038 + -0xac);
        pauVar9 = pauVar2;
        do {
          _objc_msgSend(uVar5,paConformsto,*(undefined4 *)*pauVar9);
          pauVar9 = (undefined (*) [9])(*pauVar9 + 4);
          if ((uVar5 & 0xff) == 0) {
            bVar1 = false;
            break;
          }
          uVar5 = *(uint *)((int)register0x00000038 + -0xac);
        } while (*(int *)*pauVar9 != 0);
      }
      iVar6 = iVar6 + 1;
    } while (!bVar1);
    uVar8 = 1;
  }
locret_F00A7468:
  return CONCAT44(param_2,uVar8);
}

