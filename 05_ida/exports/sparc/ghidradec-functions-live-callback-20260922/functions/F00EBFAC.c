
/* WARNING: Removing unreachable block (ram,0xf00ebff8) */

undefined8 +[Object descriptionForInstanceMethod:](int *param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  int iVar2;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  int *piVar3;
  int *piVar4;
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
  if (param_1 != (int *)0x0) {
    iVar1 = *param_1;
    piVar4 = param_1;
    do {
      if (*(int *)(iVar1 + 0xc) < 3) {
        piVar4 = (int *)piVar4[1];
      }
      else {
        piVar3 = (int *)piVar4[9];
        if (piVar3 == (int *)0x0) {
          piVar4 = (int *)piVar4[1];
        }
        else {
          iVar1 = 0;
          while( true ) {
            while (iVar1 < piVar3[1]) {
              puVar5 = (undefined4 *)piVar3[iVar1 + 2];
              _objc_msgSend(puVar5,paDescriptionfor,param_3);
              iVar1 = iVar1 + 1;
              if (puVar5 != (undefined4 *)0x0) goto locret_F00EC0E8;
            }
            if (*(int *)(*piVar4 + 0xc) < 5) {
              piVar4 = (int *)piVar4[1];
              goto loc_F00EC04C;
            }
            piVar3 = (int *)*piVar3;
            if (piVar3 == (int *)0x0) break;
            iVar1 = 0;
          }
          piVar4 = (int *)piVar4[1];
        }
      }
loc_F00EC04C:
      if (piVar4 == (int *)0x0) goto loc_f00ec058;
      iVar1 = *piVar4;
    } while( true );
  }
  puVar5 = (undefined4 *)0x0;
locret_F00EC0E8:
  return CONCAT44(param_2,puVar5);
loc_f00ec058:
  puVar5 = (undefined4 *)0x0;
  if (param_1 != (int *)0x0) {
    puVar5 = (undefined4 *)param_1[7];
    while( true ) {
      if (puVar5 == (undefined4 *)0x0) {
        param_1 = (int *)param_1[1];
      }
      else {
        do {
          iVar1 = 0;
          if ((int)puVar5[1] < 1) {
            puVar5 = (undefined4 *)*puVar5;
          }
          else {
            iVar2 = 0;
            do {
              iVar2 = iVar2 + iVar1;
              iVar1 = iVar1 + 1;
              if (puVar5[iVar2 + 2] == param_3) {
                puVar5 = puVar5 + iVar2 + 2;
                goto locret_F00EC0E8;
              }
              iVar2 = iVar1 * 2;
            } while (iVar1 < (int)puVar5[1]);
            puVar5 = (undefined4 *)*puVar5;
          }
        } while (puVar5 != (undefined4 *)0x0);
        param_1 = (int *)param_1[1];
      }
      if (param_1 == (int *)0x0) break;
      puVar5 = (undefined4 *)param_1[7];
    }
    puVar5 = (undefined4 *)0x0;
  }
  goto locret_F00EC0E8;
}

