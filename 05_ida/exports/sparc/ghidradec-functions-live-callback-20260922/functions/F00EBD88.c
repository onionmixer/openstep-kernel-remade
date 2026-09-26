
/* WARNING: Removing unreachable block (ram,0xf00ebdd4) */

undefined8 +[Object conformsTo:](int *param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  uint uVar2;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  int *piVar3;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar4;
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
  if (param_1 != (int *)0x0) {
    iVar1 = *param_1;
    do {
      if (*(int *)(iVar1 + 0xc) < 3) {
        param_1 = (int *)param_1[1];
      }
      else {
        piVar3 = (int *)param_1[9];
        if (piVar3 == (int *)0x0) {
          param_1 = (int *)param_1[1];
        }
        else {
          iVar1 = 0;
          while( true ) {
            while (iVar1 < piVar3[1]) {
              uVar2 = piVar3[iVar1 + 2];
              _objc_msgSend(uVar2,paConformsto,param_3);
              iVar1 = iVar1 + 1;
              if ((uVar2 & 0xff) != 0) {
                uVar4 = 1;
                goto locret_F00EBE3C;
              }
            }
            if (*(int *)(*param_1 + 0xc) < 5) {
              param_1 = (int *)param_1[1];
              goto loc_F00EBE2C;
            }
            piVar3 = (int *)*piVar3;
            if (piVar3 == (int *)0x0) break;
            iVar1 = 0;
          }
          param_1 = (int *)param_1[1];
        }
      }
loc_F00EBE2C:
      if (param_1 == (int *)0x0) goto loc_f00ebe38;
      iVar1 = *param_1;
    } while( true );
  }
  uVar4 = 0;
locret_F00EBE3C:
  return CONCAT44(param_2,uVar4);
loc_f00ebe38:
  uVar4 = 0;
  goto locret_F00EBE3C;
}

