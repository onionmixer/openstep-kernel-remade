
/* WARNING: Removing unreachable block (ram,0xf004406c) */
/* WARNING: Removing unreachable block (ram,0xf00441f0) */
/* WARNING: Removing unreachable block (ram,0xf00441e4) */
/* WARNING: Removing unreachable block (ram,0xf0044150) */
/* WARNING: Removing unreachable block (ram,0xf00440f0) */
/* WARNING: Removing unreachable block (ram,0xf0044278) */
/* WARNING: Removing unreachable block (ram,0xf0044264) */
/* WARNING: Removing unreachable block (ram,0xf00442b0) */
/* WARNING: Removing unreachable block (ram,0xf004413c) */
/* WARNING: Removing unreachable block (ram,0xf004418c) */
/* WARNING: Removing unreachable block (ram,0xf00441c4) */
/* WARNING: Removing unreachable block (ram,0xf004423c) */
/* WARNING: Removing unreachable block (ram,0xf0044254) */
/* WARNING: Removing unreachable block (ram,0xf0044020) */

undefined8 _xdr_replymsg(int *param_1,int *param_2)

{
  int iVar1;
  uint uVar2;
  code *pcVar3;
  undefined4 unaff_l0;
  int *piVar4;
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
  iVar1 = *param_1;
  if (iVar1 == 0) {
    if (param_2[2] != 0) {
      iVar1 = *param_1;
      goto loc_F004408C;
    }
    if (param_2[1] != 1) {
      iVar1 = *param_1;
      goto loc_F004408C;
    }
    piVar4 = param_1;
    (**(code **)(param_1[1] + 0x18))(param_1,param_2[5] + 0x18);
    if (piVar4 == (int *)0x0) {
      iVar1 = *param_1;
      goto loc_F004408C;
    }
    *piVar4 = *param_2;
    piVar4[1] = param_2[1];
    piVar4[2] = param_2[2];
    piVar4[3] = param_2[3];
    piVar4[4] = param_2[5];
    piVar4 = piVar4 + 5;
    if (param_2[5] != 0) {
      _bcopy(param_2[4],piVar4);
      piVar4 = (int *)((int)piVar4 + (param_2[5] + 3U & 0xfffffffc));
    }
    *piVar4 = param_2[6];
    if (param_2[6] != 0) {
      if (param_2[6] != 2) {
        param_1 = (int *)0x1;
        goto locret_F00442C4;
      }
      piVar4 = param_1;
      _xdr_u_long(param_1,param_2 + 7);
      if (piVar4 == (int *)0x0) goto loc_F00442C0;
loc_f0044250:
      _xdr_u_long(param_1,param_2 + 8);
      goto locret_F00442C4;
    }
    iVar1 = param_2[7];
    pcVar3 = (code *)param_2[8];
loc_F004422C:
    (*pcVar3)(param_1,iVar1);
  }
  else {
loc_F004408C:
    if ((iVar1 == 1) &&
       (piVar4 = param_1, (**(code **)(param_1[1] + 0x18))(param_1,0xc), piVar4 != (int *)0x0)) {
      *param_2 = *piVar4;
      iVar1 = piVar4[1];
      param_2[1] = iVar1;
      if (iVar1 == 1) {
        iVar1 = piVar4[2];
        param_2[2] = iVar1;
        if (iVar1 != 0) {
          if (iVar1 == 1) {
            _xdr_rejected_reply(param_1,param_2 + 3);
          }
          else {
            param_1 = (int *)0x0;
          }
          goto locret_F00442C4;
        }
        piVar4 = param_1;
        (**(code **)(param_1[1] + 0x18))(param_1,8);
        if (piVar4 == (int *)0x0) {
          piVar4 = param_1;
          _xdr_enum(param_1,param_2 + 3);
          if (piVar4 == (int *)0x0) goto loc_F00442C0;
          piVar4 = param_1;
          _xdr_u_int(param_1,param_2 + 5);
          if (piVar4 == (int *)0x0) {
            param_1 = (int *)0x0;
            goto locret_F00442C4;
          }
        }
        else {
          param_2[3] = *piVar4;
          param_2[5] = piVar4[1];
        }
        uVar2 = param_2[5];
        if (uVar2 != 0) {
          if (400 < uVar2) {
            param_1 = (int *)0x0;
            goto locret_F00442C4;
          }
          if (param_2[4] == 0) {
            _kalloc();
            param_2[4] = uVar2;
            uVar2 = param_2[5];
          }
          piVar4 = param_1;
          (**(code **)(param_1[1] + 0x18))(param_1,uVar2 + 3 & 0xfffffffc);
          if (piVar4 == (int *)0x0) {
            piVar4 = param_1;
            _xdr_opaque(param_1,param_2[4],param_2[5]);
            if (piVar4 == (int *)0x0) {
              param_1 = (int *)0x0;
              goto locret_F00442C4;
            }
          }
          else {
            _bcopy(piVar4,param_2[4],param_2[5]);
          }
        }
        piVar4 = param_1;
        _xdr_enum(param_1,param_2 + 6);
        if (piVar4 == (int *)0x0) {
          param_1 = (int *)0x0;
          goto locret_F00442C4;
        }
        if (param_2[6] == 0) {
          iVar1 = param_2[7];
          pcVar3 = (code *)param_2[8];
          goto loc_F004422C;
        }
        if (param_2[6] != 2) {
          param_1 = (int *)0x1;
          goto locret_F00442C4;
        }
        piVar4 = param_1;
        _xdr_u_long(param_1,param_2 + 7);
        if (piVar4 != (int *)0x0) goto loc_f0044250;
      }
    }
    else {
      piVar4 = param_1;
      _xdr_u_long(param_1,param_2);
      if (piVar4 != (int *)0x0) {
        piVar4 = param_1;
        _xdr_enum(param_1,param_2 + 1);
        if (piVar4 == (int *)0x0) {
          param_1 = (int *)0x0;
        }
        else if (param_2[1] == 1) {
          _xdr_union(param_1,param_2 + 2,param_2 + 3,unk_F010DDB0,0);
        }
        else {
          param_1 = (int *)0x0;
        }
        goto locret_F00442C4;
      }
    }
loc_F00442C0:
    param_1 = (int *)0x0;
  }
locret_F00442C4:
  return CONCAT44(param_2,param_1);
}
