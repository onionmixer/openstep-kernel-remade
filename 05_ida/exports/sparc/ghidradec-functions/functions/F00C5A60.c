
/* WARNING: Removing unreachable block (ram,0xf00c5b08) */
/* WARNING: Removing unreachable block (ram,0xf00c5be4) */
/* WARNING: Removing unreachable block (ram,0xf00c5bac) */
/* WARNING: Removing unreachable block (ram,0xf00c5b84) */
/* WARNING: Removing unreachable block (ram,0xf00c5b30) */
/* WARNING: Removing unreachable block (ram,0xf00c5ab8) */
/* WARNING: Removing unreachable block (ram,0xf00c5a88) */
/* WARNING: Removing unreachable block (ram,0xf00c5c0c) */
/* WARNING: Removing unreachable block (ram,0xf00c5ad8) */
/* WARNING: Removing unreachable block (ram,0xf00c5b78) */
/* WARNING: Removing unreachable block (ram,0xf00c5b9c) */
/* WARNING: Removing unreachable block (ram,0xf00c5bc4) */
/* WARNING: Removing unreachable block (ram,0xf00c5bf4) */
/* WARNING: Removing unreachable block (ram,0xf00c5b18) */
/* WARNING: Removing unreachable block (ram,0xf00c5a7c) */

undefined8 +[IODevice connectToIndirectDevices:](undefined4 param_1,undefined4 param_2,uint param_3)

{
  int iVar1;
  int *piVar2;
  undefined4 uVar3;
  undefined (*pauVar4) [12];
  uint uVar5;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  int iVar6;
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
  iVar6 = 0;
  _objc_msgSend(dword_F013304C,paLock);
loc_F00C5A84:
  do {
    while( true ) {
      iVar1 = iVar6;
      sub_F00C482C(iVar6,(undefined *)((int)register0x00000038 + -0x14));
      if (iVar1 == -0x2c0) {
        _objc_msgSend(dword_F013304C,paUnlock);
        return CONCAT44(param_2,param_1);
      }
      if ((-0x2c0 < iVar1) || (iVar1 != -0x2d7)) break;
loc_F00C5BFC:
      iVar6 = iVar6 + 1;
    }
    iVar1 = **(int **)((int)register0x00000038 + -0x14);
    _objc_msgSend(iVar1,paDevicestyle);
    if (iVar1 == 1) {
      piVar2 = (int *)**(int **)((int)register0x00000038 + -0x14);
      _objc_msgSend(piVar2,paRequiredprotoc);
      if ((piVar2 != (int *)0x0) && (*piVar2 != 0)) {
        do {
          uVar5 = param_3;
          _objc_msgSend(param_3,paConformsto,*piVar2);
          piVar2 = piVar2 + 1;
          if ((uVar5 & 0xff) == 0) goto loc_F00C5BFC;
        } while (*piVar2 != 0);
        pauVar4 = *(undefined (**) [12])(*(int *)((int)register0x00000038 + -0x14) + 0x10);
        if (pauVar4 == (undefined (*) [12])0x0) {
          pauVar4 = paIodevicedescri;
          _objc_msgSend(paIodevicedescri,paAlloc);
          _objc_msgSend();
        }
        _objc_msgSend(pauVar4,paSetdirectdevic,param_3);
        _objc_msgSend(dword_F013304C,paUnlock);
        uVar5 = **(uint **)((int)register0x00000038 + -0x14);
        _objc_msgSend(uVar5,paProbe,pauVar4);
        if ((uVar5 & 0xff) == 0) {
          _objc_msgSend(pauVar4,paFree);
        }
        _objc_msgSend(dword_F013304C,paLock);
        goto loc_F00C5BFC;
      }
      uVar3 = **(undefined4 **)((int)register0x00000038 + -0x14);
      _objc_msgSend(uVar3,paName);
      _IOLog(aLoadedClassSRe,uVar3);
      iVar6 = iVar6 + 1;
      goto loc_F00C5A84;
    }
    iVar6 = iVar6 + 1;
  } while( true );
}
