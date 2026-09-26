
/* WARNING: Removing unreachable block (ram,0xf0044b7c) */
/* WARNING: Removing unreachable block (ram,0xf0044ae4) */
/* WARNING: Removing unreachable block (ram,0xf0044ba4) */
/* WARNING: Removing unreachable block (ram,0xf0044af8) */
/* WARNING: Removing unreachable block (ram,0xf0044a70) */

undefined8 _svc_getreq(int param_1,undefined4 param_2)

{
  int *piVar1;
  undefined *puVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  undefined4 *puVar6;
  uint uVar7;
  uint uVar8;
  bool bVar9;
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
  if (_rqcred_head == (int *)0x0) {
    piVar1 = (int *)0x4b0;
    _kalloc();
  }
  else {
    piVar1 = _rqcred_head;
    _rqcred_head = (int *)*_rqcred_head;
  }
  *(int **)((int)register0x00000038 + -0x1c) = piVar1;
  *(int **)((int)register0x00000038 + -0x10) = piVar1 + 100;
  *(int **)((int)register0x00000038 + -0x40) = piVar1 + 200;
  puVar6 = *(undefined4 **)(param_1 + 8);
  do {
    iVar3 = param_1;
    (*(code *)*puVar6)(param_1,(undefined *)((int)register0x00000038 + -0x38));
    if (iVar3 == 0) {
loc_F0044BC4:
      iVar3 = *(int *)(param_1 + 8);
    }
    else {
      *(int *)((int)register0x00000038 + -0x3c) = param_1;
      puVar2 = (undefined *)((int)register0x00000038 + -0x58);
      *(undefined8 *)((int)register0x00000038 + -0x58) =
           *(undefined8 *)((int)register0x00000038 + -0x2c);
      *(undefined4 *)((int)register0x00000038 + -0x48) =
           *(undefined4 *)((int)register0x00000038 + -0x1c);
      *(undefined4 *)((int)register0x00000038 + -0x50) =
           *(undefined4 *)((int)register0x00000038 + -0x24);
      *(undefined4 *)((int)register0x00000038 + -0x4c) =
           *(undefined4 *)((int)register0x00000038 + -0x20);
      *(undefined4 *)((int)register0x00000038 + -0x44) =
           *(undefined4 *)((int)register0x00000038 + -0x18);
      __authenticate(puVar2,(undefined *)((int)register0x00000038 + -0x38));
      bVar9 = false;
      if (puVar2 == (undefined *)0x0) {
        uVar7 = 0xffffffff;
        uVar8 = 0;
        if (dword_F012F558 != (undefined4 *)0x0) {
          iVar3 = dword_F012F558[1];
          puVar6 = dword_F012F558;
          while( true ) {
            if (iVar3 == *(int *)((int)register0x00000038 + -0x58)) {
              uVar4 = puVar6[2];
              if (uVar4 == *(uint *)((int)register0x00000038 + -0x54)) {
                (*(code *)puVar6[3])((undefined *)((int)register0x00000038 + -0x58),param_1);
                iVar3 = *(int *)(param_1 + 8);
                goto loc_F0044BC8;
              }
              bVar9 = true;
              if (uVar4 < uVar7) {
                uVar7 = uVar4;
              }
              if (uVar8 < uVar4) {
                uVar8 = uVar4;
              }
              puVar6 = (undefined4 *)*puVar6;
            }
            else {
              puVar6 = (undefined4 *)*puVar6;
            }
            if (puVar6 == (undefined4 *)0x0) break;
            iVar3 = puVar6[1];
          }
        }
        if (bVar9) {
          _svcerr_progvers(param_1);
          iVar3 = *(int *)(param_1 + 8);
        }
        else {
          _svcerr_noprog(param_1);
          iVar3 = *(int *)(param_1 + 8);
        }
        (**(code **)(iVar3 + 0x10))(param_1,0,0);
        goto loc_F0044BC4;
      }
      _svcerr_auth(param_1,puVar2);
      iVar3 = *(int *)(param_1 + 8);
    }
loc_F0044BC8:
    iVar5 = param_1;
    (**(code **)(iVar3 + 4))();
    if (iVar5 == 0) {
      (**(code **)(*(int *)(param_1 + 8) + 0x14))(param_1);
loc_F0044BEC:
      *piVar1 = (int)_rqcred_head;
      _rqcred_head = piVar1;
      return CONCAT44(param_2,param_1);
    }
    if (iVar5 != 1) goto loc_F0044BEC;
    puVar6 = *(undefined4 **)(param_1 + 8);
  } while( true );
}

