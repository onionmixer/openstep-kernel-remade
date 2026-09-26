
/* WARNING: Removing unreachable block (ram,0xf00f0310) */
/* WARNING: Removing unreachable block (ram,0xf00f034c) */
/* WARNING: Removing unreachable block (ram,0xf00f0288) */
/* WARNING: Removing unreachable block (ram,0xf00f0308) */
/* WARNING: Removing unreachable block (ram,0xf00f0334) */
/* WARNING: Removing unreachable block (ram,0xf00f0280) */

undefined8 __class_lookupMethodAndLoadCache(int *param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  undefined4 unaff_l0;
  int *piVar3;
  undefined4 unaff_l1;
  int *piVar4;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  code *pcVar5;
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
  if (param_1 != (int *)unk_F00FA360) {
    if (((param_1[4] & 2U) != 0) && ((param_1[4] & 4U) == 0)) {
      _objc_getClass(param_1[2]);
      sub_F00EFA04();
    }
    pcVar5 = __objc_msgForward;
    piVar2 = (int *)param_1[7];
    piVar4 = param_1;
    do {
      piVar3 = (int *)0x0;
      if (piVar2 != (int *)0x0) {
        iVar1 = piVar2[1];
        while( true ) {
          piVar3 = piVar2 + 2;
          while (iVar1 = iVar1 + -1, -1 < iVar1) {
            if (param_2 == *piVar3) goto loc_F00F02EC;
            piVar3 = piVar3 + 3;
          }
          piVar2 = (int *)*piVar2;
          if (piVar2 == (int *)0x0) break;
          iVar1 = piVar2[1];
        }
        piVar3 = (int *)0x0;
      }
loc_F00F02EC:
      if (piVar3 != (int *)0x0) {
        sub_F00F00E4(param_1,piVar3);
        pcVar5 = (code *)piVar3[2];
        goto locret_F00F0358;
      }
      piVar4 = (int *)piVar4[1];
      if (piVar4 == (int *)0x0) goto loc_f00f0308;
      piVar2 = (int *)piVar4[7];
    } while( true );
  }
  pcVar5 = sub_F00EF9D8;
locret_F00F0358:
  return CONCAT44(param_2,pcVar5);
loc_f00f0308:
  piVar4 = param_1;
  _NXDefaultMallocZone();
  piVar2 = piVar4;
  _NXDefaultMallocZone();
  (*(code *)piVar4[1])();
  *piVar2 = param_2;
  piVar2[1] = (int)&asc_F00FA528;
  piVar2[2] = (int)__objc_msgForward;
  sub_F00F00E4(param_1);
  goto locret_F00F0358;
}
