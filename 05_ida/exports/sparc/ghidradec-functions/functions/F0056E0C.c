
/* WARNING: Removing unreachable block (ram,0xf0056f78) */
/* WARNING: Removing unreachable block (ram,0xf0056fac) */
/* WARNING: Removing unreachable block (ram,0xf0056f14) */
/* WARNING: Removing unreachable block (ram,0xf0056ebc) */
/* WARNING: Removing unreachable block (ram,0xf0056ed0) */
/* WARNING: Removing unreachable block (ram,0xf0056fc4) */
/* WARNING: Removing unreachable block (ram,0xf0056f84) */
/* WARNING: Removing unreachable block (ram,0xf0056e70) */

undefined8 _ipc_kmsg_copyout_body(uint *param_1,uint *param_2,uint param_3,int param_4)

{
  bool bVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint *puVar7;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  uint uVar8;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  uint uVar9;
  undefined4 unaff_l6;
  uint uVar10;
  undefined4 unaff_l7;
  uint uVar11;
  undefined4 unaff_i0;
  uint *puVar12;
  undefined4 unaff_i1;
  uint *puVar13;
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
  uVar11 = 0;
  puVar13 = param_2;
loc_F0056E1C:
  do {
    if (param_2 <= param_1) {
      return CONCAT44(puVar13,uVar11);
    }
    uVar2 = *param_1;
    uVar5 = uVar2 >> 2 & 1;
    uVar9 = uVar2 >> 3 & 1;
    if (uVar5 == 0) {
      uVar10 = (uint)*(byte *)param_1;
      uVar6 = uVar2 >> 0x10 & 0xff;
      uVar2 = uVar2 >> 4 & 0xfff;
      puVar12 = param_1 + 1;
    }
    else {
      uVar10 = (uint)*(word *)(param_1 + 1);
      uVar6 = (uint)*(word *)((int)param_1 + 6);
      uVar2 = param_1[2];
      puVar12 = param_1 + 3;
    }
    uVar8 = uVar2;
    .umul(uVar2,uVar6);
    bVar1 = 5 < uVar10 - 0x10;
    uVar6 = uVar8 + 7 >> 3;
    puVar13 = param_1;
    if (!bVar1) {
      puVar7 = puVar12;
      if (uVar9 != 0) {
loc_F0056EF0:
        uVar8 = 0;
        if (uVar2 != 0) {
          do {
            uVar8 = uVar8 + 1;
            uVar4 = param_3;
            _ipc_kmsg_copyout_object(param_3,*puVar7,uVar10,puVar7);
            uVar11 = uVar11 | uVar4;
            puVar7 = puVar7 + 1;
          } while (uVar8 < uVar2);
        }
        goto loc_F0056F30;
      }
      if ((uVar6 == 0) ||
         (iVar3 = param_4,
         _vm_allocate(param_4,(undefined *)((int)register0x00000038 + -0xc),uVar6,1), iVar3 == 0)) {
        puVar7 = (uint *)*puVar12;
        goto loc_F0056EF0;
      }
      _ipc_kmsg_clean_body(param_1,puVar12);
loc_F0056FD8:
      *(undefined4 *)((int)register0x00000038 + -0xc) = 0;
      if (uVar5 == 0) {
        *(byte *)((int)param_1 + 1) = 0;
      }
      else {
        ((byte *)((int)param_1 + 6))[0] = 0;
        ((byte *)((int)param_1 + 6))[1] = 0;
      }
      if (iVar3 == 6) {
        uVar11 = uVar11 | 0x400;
      }
      else {
        uVar11 = uVar11 | 0x1000;
      }
      goto loc_F0057004;
    }
loc_F0056F30:
    if (uVar9 == 0) {
      uVar2 = *puVar12;
      if (uVar6 == 0) {
        *(undefined4 *)((int)register0x00000038 + -0xc) = 0;
loc_F0057004:
        uVar5 = *param_1;
      }
      else {
        if (bVar1) {
          iVar3 = _ipc_soft_map;
          _vm_move(_ipc_soft_map,uVar2,param_4,uVar6,0,(undefined *)((int)register0x00000038 + -0xc)
                  );
          _vm_deallocate(_ipc_soft_map,uVar2,uVar6);
          if (iVar3 != 0) goto loc_F0056FD8;
          goto loc_F0057004;
        }
        _copyoutmap(param_4,uVar2,*(undefined4 *)((int)register0x00000038 + -0xc),uVar6);
        _kfree(uVar2,uVar6);
        uVar5 = *param_1;
      }
      uVar2 = *(uint *)((int)register0x00000038 + -0xc);
      *param_1 = uVar5 | 2;
      *puVar12 = uVar2;
      param_1 = puVar12 + 1;
      goto loc_F0056E1C;
    }
    *param_1 = *param_1 & 0xfffffffd;
    param_1 = (uint *)((int)puVar12 + (uVar6 + 3 & 0xfffffffc));
  } while( true );
}
