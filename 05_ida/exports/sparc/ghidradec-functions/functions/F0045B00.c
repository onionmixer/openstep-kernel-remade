
/* WARNING: Removing unreachable block (ram,0xf0045bb8) */
/* WARNING: Removing unreachable block (ram,0xf0045b60) */
/* WARNING: Removing unreachable block (ram,0xf0045b50) */
/* WARNING: Removing unreachable block (ram,0xf0045ba8) */
/* WARNING: Removing unreachable block (ram,0xf0045c10) */
/* WARNING: Removing unreachable block (ram,0xf0045b10) */

undefined8
_xdr_array(int *param_1,uint *param_2,uint *param_3,uint param_4,int param_5,code *param_6)

{
  int *piVar1;
  undefined *puVar2;
  uint uVar3;
  int iVar4;
  undefined4 unaff_l0;
  uint uVar5;
  undefined4 unaff_l1;
  int *piVar6;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  uint uVar7;
  undefined4 unaff_i3;
  uint uVar8;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool bVar9;
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
  uVar5 = *param_2;
  piVar6 = (int *)0x1;
  piVar1 = param_1;
  _xdr_u_int(param_1,param_3);
  if (piVar1 == (int *)0x0) {
    puVar2 = aXdrArraySizeFa;
  }
  else {
    uVar7 = *param_3;
    if ((uVar7 <= param_4) || (*param_1 == 2)) {
      uVar3 = uVar7;
      .umul(uVar7,param_5);
      if (uVar5 == 0) {
        if (*param_1 == 1) {
          if (uVar7 == 0) {
            piVar6 = (int *)0x1;
            goto locret_F0045C20;
          }
          uVar5 = uVar3;
          _kalloc();
          *param_2 = uVar5;
          _bzero();
        }
        else if (*param_1 == 2) {
          piVar6 = (int *)0x1;
          goto locret_F0045C20;
        }
      }
      uVar8 = 0;
      if (uVar7 == 0) {
        iVar4 = *param_1;
      }
      else {
        do {
          bVar9 = piVar6 == (int *)0x0;
          piVar6 = (int *)0x0;
          if (bVar9) break;
          piVar6 = param_1;
          (*param_6)(param_1,uVar5,0xffffffff);
          uVar8 = uVar8 + 1;
          uVar5 = uVar5 + param_5;
        } while (uVar8 < uVar7);
        iVar4 = *param_1;
      }
      if (iVar4 == 2) {
        _kfree(*param_2,uVar3);
        *param_2 = 0;
      }
      goto locret_F0045C20;
    }
    puVar2 = aXdrArrayBadSiz;
  }
  piVar6 = (int *)0x0;
  _printf(puVar2);
locret_F0045C20:
  return CONCAT44(param_2,piVar6);
}
