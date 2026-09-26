
/* WARNING: Removing unreachable block (ram,0xf00c5a14) */
/* WARNING: Removing unreachable block (ram,0xf00c5998) */
/* WARNING: Removing unreachable block (ram,0xf00c5918) */
/* WARNING: Removing unreachable block (ram,0xf00c5a34) */
/* WARNING: Removing unreachable block (ram,0xf00c58a4) */
/* WARNING: Removing unreachable block (ram,0xf00c59ec) */
/* WARNING: Removing unreachable block (ram,0xf00c58d4) */
/* WARNING: Removing unreachable block (ram,0xf00c5960) */
/* WARNING: Removing unreachable block (ram,0xf00c59ac) */
/* WARNING: Removing unreachable block (ram,0xf00c5a20) */
/* WARNING: Removing unreachable block (ram,0xf00c5880) */

qword +[IODevice addLoadedClass:description:]
                (undefined4 param_1,undefined4 param_2,int *param_3,undefined4 param_4)

{
  undefined7 *puVar1;
  int *piVar2;
  int iVar3;
  uint uVar4;
  int *piVar5;
  undefined4 unaff_l0;
  undefined *puVar6;
  undefined4 unaff_l1;
  int iVar7;
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
  bool bVar8;
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
  bVar8 = false;
  piVar2 = param_3;
  sub_F00C47A0(param_3,(undefined *)((int)register0x00000038 + -0x14));
  if (piVar2 == (int *)0x0) {
    *(undefined4 *)(*(int *)((int)register0x00000038 + -0x14) + 0x10) = param_4;
  }
  piVar2 = param_3;
  _objc_msgSend(param_3,paDevicestyle);
  puVar1 = paProbe;
  if (piVar2 == (int *)0x1) {
    piVar2 = param_3;
    _objc_msgSend(param_3,paRequiredprotoc);
    if ((piVar2 != (int *)0x0) && (iVar7 = 0, *piVar2 != 0)) {
      do {
        iVar3 = iVar7;
        sub_F00C4664(iVar7,(undefined *)((int)register0x00000038 + -0x18));
        if ((iVar3 != -0x2c0) && ((-0x2c0 < iVar3 && (iVar3 == 0)))) {
          if (*piVar2 == 0) {
loc_F00C5990:
            _objc_msgSend(param_4,paSetdirectdevic,*(undefined4 *)((int)register0x00000038 + -0x18))
            ;
            piVar5 = param_3;
            _objc_msgSend(param_3,paProbe,param_4);
            if (((uint)piVar5 & 0xff) != 0) {
              bVar8 = true;
            }
          }
          else {
            uVar4 = *(uint *)((int)register0x00000038 + -0x18);
            piVar5 = piVar2;
            while (_objc_msgSend(uVar4,paConformsto,*piVar5), (uVar4 & 0xff) != 0) {
              piVar5 = piVar5 + 1;
              if (*piVar5 == 0) goto loc_F00C5990;
              uVar4 = *(uint *)((int)register0x00000038 + -0x18);
            }
          }
        }
        iVar7 = iVar7 + 1;
      } while (iVar3 != -0x2c0);
      goto loc_F00C5A50;
    }
    puVar6 = aLoadedClassSRe;
  }
  else {
    if (((int *)0x1 < piVar2) && (piVar2 != (int *)0x2)) {
      bVar8 = false;
      goto loc_F00C5A50;
    }
    piVar2 = param_3;
    _objc_msgSend(param_3,paRespondsto,paProbe);
    if (((uint)piVar2 & 0xff) != 0) {
      _objc_msgSend(param_3,puVar1,param_4);
      bVar8 = ((uint)param_3 & 0xff) != 0;
      goto loc_F00C5A50;
    }
    puVar6 = aAddloadedclass;
  }
  _objc_msgSend(param_3,paName);
  _IOLog(puVar6,param_3);
  bVar8 = false;
loc_F00C5A50:
  return CONCAT44(param_2,bVar8 - 1) & 0xfffffffffffffd40;
}
