
/* WARNING: Removing unreachable block (ram,0xf00ebeb0) */

undefined8 -[Object descriptionForMethod:](int *param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  int iVar2;
  undefined (*pauVar3) [30];
  int iVar4;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  int *piVar5;
  int *piVar6;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 *puVar7;
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
  piVar6 = (int *)*param_1;
  if (piVar6 != (int *)0x0) {
    iVar1 = *piVar6;
    do {
      if (*(int *)(iVar1 + 0xc) < 3) {
        piVar6 = (int *)piVar6[1];
      }
      else {
        piVar5 = (int *)piVar6[9];
        if (piVar5 == (int *)0x0) {
          piVar6 = (int *)piVar6[1];
        }
        else {
          iVar1 = 0;
          while( true ) {
            while (iVar1 < piVar5[1]) {
              puVar7 = (undefined4 *)piVar5[iVar1 + 2];
              pauVar3 = paDescriptionfor;
              if ((piVar6[4] & 2U) != 0) {
                pauVar3 = (undefined (*) [30])paDescriptionfor_1;
              }
              _objc_msgSend(puVar7,pauVar3,param_3);
              iVar1 = iVar1 + 1;
              if (puVar7 != (undefined4 *)0x0) goto locret_F00EBFA4;
            }
            if (*(int *)(*piVar6 + 0xc) < 5) {
              piVar6 = (int *)piVar6[1];
              goto loc_F00EBF04;
            }
            piVar5 = (int *)*piVar5;
            if (piVar5 == (int *)0x0) break;
            iVar1 = 0;
          }
          piVar6 = (int *)piVar6[1];
        }
      }
loc_F00EBF04:
      if (piVar6 == (int *)0x0) goto loc_f00ebf10;
      iVar1 = *piVar6;
    } while( true );
  }
  puVar7 = (undefined4 *)0x0;
locret_F00EBFA4:
  return CONCAT44(param_2,puVar7);
loc_f00ebf10:
  iVar1 = *param_1;
  puVar7 = (undefined4 *)0x0;
  if (iVar1 != 0) {
    puVar7 = *(undefined4 **)(iVar1 + 0x1c);
    while( true ) {
      if (puVar7 == (undefined4 *)0x0) {
        iVar1 = *(int *)(iVar1 + 4);
      }
      else {
        do {
          iVar4 = 0;
          if ((int)puVar7[1] < 1) {
            puVar7 = (undefined4 *)*puVar7;
          }
          else {
            iVar2 = 0;
            do {
              iVar2 = iVar2 + iVar4;
              iVar4 = iVar4 + 1;
              if (puVar7[iVar2 + 2] == param_3) {
                puVar7 = puVar7 + iVar2 + 2;
                goto locret_F00EBFA4;
              }
              iVar2 = iVar4 * 2;
            } while (iVar4 < (int)puVar7[1]);
            puVar7 = (undefined4 *)*puVar7;
          }
        } while (puVar7 != (undefined4 *)0x0);
        iVar1 = *(int *)(iVar1 + 4);
      }
      if (iVar1 == 0) break;
      puVar7 = *(undefined4 **)(iVar1 + 0x1c);
    }
    puVar7 = (undefined4 *)0x0;
  }
  goto locret_F00EBFA4;
}

