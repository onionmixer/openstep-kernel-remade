
/* WARNING: Removing unreachable block (ram,0xf00f24a0) */

undefined8 __nameForHeader(int param_1,undefined4 param_2)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
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
  if (param_1 == 0) {
    iVar1 = *_NXArgv;
  }
  else {
    iVar1 = *(int *)(param_1 + 0xc);
    if (iVar1 == 3) {
      sub_F00F2420();
      piVar2 = (int *)(iVar1 + 0x1c);
      piVar3 = (int *)((int)piVar2 + *(int *)(iVar1 + 0x14));
      if (piVar2 < piVar3) {
        iVar1 = *piVar2;
        while( true ) {
          if (iVar1 == 6) {
            if (piVar2[4] == param_1) {
              iVar1 = (int)piVar2 + piVar2[2];
              goto locret_F00F2508;
            }
            iVar1 = piVar2[1];
          }
          else {
            iVar1 = piVar2[1];
          }
          piVar2 = (int *)((int)piVar2 + iVar1);
          if (piVar3 <= piVar2) break;
          iVar1 = *piVar2;
        }
        iVar1 = 0;
      }
      else {
        iVar1 = 0;
      }
    }
    else {
      iVar1 = *_NXArgv;
    }
  }
locret_F00F2508:
  return CONCAT44(param_2,iVar1);
}

