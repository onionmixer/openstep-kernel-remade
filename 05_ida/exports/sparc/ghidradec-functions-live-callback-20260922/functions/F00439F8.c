
/* WARNING: Removing unreachable block (ram,0xf0043d04) */
/* WARNING: Removing unreachable block (ram,0xf0043c78) */
/* WARNING: Removing unreachable block (ram,0xf0043c18) */
/* WARNING: Removing unreachable block (ram,0xf0043be0) */
/* WARNING: Removing unreachable block (ram,0xf0043dd8) */
/* WARNING: Removing unreachable block (ram,0xf0043db0) */
/* WARNING: Removing unreachable block (ram,0xf0043d74) */
/* WARNING: Removing unreachable block (ram,0xf0043d38) */
/* WARNING: Removing unreachable block (ram,0xf0043d4c) */
/* WARNING: Removing unreachable block (ram,0xf0043d9c) */
/* WARNING: Removing unreachable block (ram,0xf0043dc4) */
/* WARNING: Removing unreachable block (ram,0xf0043dec) */
/* WARNING: Removing unreachable block (ram,0xf0043c38) */
/* WARNING: Removing unreachable block (ram,0xf0043c64) */
/* WARNING: Removing unreachable block (ram,0xf0043ccc) */
/* WARNING: Removing unreachable block (ram,0xf0043d28) */
/* WARNING: Removing unreachable block (ram,0xf0043ae4) */

undefined8 _xdr_callmsg(int *param_1,int *param_2)

{
  int iVar1;
  int *piVar2;
  uint uVar3;
  int *piVar4;
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
  bool bVar5;
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
    if (400 < (uint)param_2[8]) {
      param_1 = (int *)0x0;
      goto locret_F0043E00;
    }
    if ((uint)param_2[0xb] < 0x191) {
      piVar4 = param_1;
      (**(code **)(param_1[1] + 0x18))
                (param_1,(param_2[8] + 3U & 0xfffffffc) + (param_2[0xb] + 3U & 0xfffffffc) + 0x28);
      if (piVar4 == (int *)0x0) {
        iVar1 = *param_1;
        goto loc_F0043B30;
      }
      *piVar4 = *param_2;
      piVar4[1] = param_2[1];
      if (param_2[1] == 0) {
        piVar4[2] = param_2[2];
        if (param_2[2] == 2) {
          piVar4[3] = param_2[3];
          piVar4[4] = param_2[4];
          piVar4[5] = param_2[5];
          piVar4[6] = param_2[6];
          piVar4[7] = param_2[8];
          piVar4 = piVar4 + 8;
          if (param_2[8] != 0) {
            _bcopy(param_2[7],piVar4);
            piVar4 = (int *)((int)piVar4 + (param_2[8] + 3U & 0xfffffffc));
          }
          *piVar4 = param_2[9];
          piVar4[1] = param_2[0xb];
          iVar1 = param_2[0xb];
          piVar4 = piVar4 + 2;
          if (iVar1 != 0) {
            piVar2 = (int *)param_2[10];
            goto loc_F0043D28;
          }
          goto loc_F0043D30;
        }
      }
    }
  }
  else {
loc_F0043B30:
    if ((iVar1 == 1) &&
       (piVar4 = param_1, (**(code **)(param_1[1] + 0x18))(param_1,0x20), piVar4 != (int *)0x0)) {
      *param_2 = *piVar4;
      iVar1 = piVar4[1];
      param_2[1] = iVar1;
      if (iVar1 == 0) {
        iVar1 = piVar4[2];
        param_2[2] = iVar1;
        if (iVar1 == 2) {
          param_2[3] = piVar4[3];
          param_2[4] = piVar4[4];
          param_2[5] = piVar4[5];
          param_2[6] = piVar4[6];
          uVar3 = piVar4[7];
          param_2[8] = uVar3;
          if (uVar3 == 0) {
loc_F0043C40:
            iVar1 = param_1[1];
          }
          else {
            if (400 < uVar3) {
              param_1 = (int *)0x0;
              goto locret_F0043E00;
            }
            if (param_2[7] == 0) {
              _kalloc();
              param_2[7] = uVar3;
              iVar1 = param_2[8];
            }
            else {
              iVar1 = param_2[8];
            }
            piVar4 = param_1;
            (**(code **)(param_1[1] + 0x18))(param_1,iVar1 + 3U & 0xfffffffc);
            if (piVar4 != (int *)0x0) {
              _bcopy(piVar4,param_2[7],param_2[8]);
              goto loc_F0043C40;
            }
            piVar4 = param_1;
            _xdr_opaque(param_1,param_2[7],param_2[8]);
            if (piVar4 == (int *)0x0) {
              param_1 = (int *)0x0;
              goto locret_F0043E00;
            }
            iVar1 = param_1[1];
          }
          piVar4 = param_1;
          (**(code **)(iVar1 + 0x18))(param_1,8);
          if (piVar4 == (int *)0x0) {
            piVar4 = param_1;
            _xdr_enum(param_1,param_2 + 9);
            if (piVar4 == (int *)0x0) goto loc_F0043DFC;
            piVar4 = param_1;
            _xdr_u_int(param_1,param_2 + 0xb);
            if (piVar4 == (int *)0x0) {
              param_1 = (int *)0x0;
              goto locret_F0043E00;
            }
            uVar3 = param_2[0xb];
          }
          else {
            param_2[9] = *piVar4;
            param_2[0xb] = piVar4[1];
            uVar3 = param_2[0xb];
          }
          if (uVar3 != 0) {
            if (400 < uVar3) {
              param_1 = (int *)0x0;
              goto locret_F0043E00;
            }
            if (param_2[10] == 0) {
              _kalloc();
              param_2[10] = uVar3;
              iVar1 = param_2[0xb];
            }
            else {
              iVar1 = param_2[0xb];
            }
            piVar2 = param_1;
            (**(code **)(param_1[1] + 0x18))(param_1,iVar1 + 3U & 0xfffffffc);
            piVar4 = (int *)param_2[10];
            if (piVar2 == (int *)0x0) {
              _xdr_opaque(param_1,piVar4,param_2[0xb]);
              bVar5 = param_1 == (int *)0x0;
              param_1 = (int *)0x1;
              if (bVar5) {
                param_1 = (int *)0x0;
              }
              goto locret_F0043E00;
            }
            iVar1 = param_2[0xb];
loc_F0043D28:
            _bcopy(piVar2,piVar4,iVar1);
          }
loc_F0043D30:
          param_1 = (int *)0x1;
          goto locret_F0043E00;
        }
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
          goto locret_F0043E00;
        }
        if (param_2[1] != 0) {
          param_1 = (int *)0x0;
          goto locret_F0043E00;
        }
        piVar4 = param_1;
        _xdr_u_long(param_1,param_2 + 2);
        if (piVar4 == (int *)0x0) {
          param_1 = (int *)0x0;
          goto locret_F0043E00;
        }
        if (param_2[2] != 2) {
          param_1 = (int *)0x0;
          goto locret_F0043E00;
        }
        piVar4 = param_1;
        _xdr_u_long(param_1,param_2 + 3);
        if ((((piVar4 != (int *)0x0) &&
             (piVar4 = param_1, _xdr_u_long(param_1,param_2 + 4), piVar4 != (int *)0x0)) &&
            (piVar4 = param_1, _xdr_u_long(param_1,param_2 + 5), piVar4 != (int *)0x0)) &&
           (piVar4 = param_1, _xdr_opaque_auth(param_1,param_2 + 6), piVar4 != (int *)0x0)) {
          _xdr_opaque_auth(param_1,param_2 + 9);
          goto locret_F0043E00;
        }
      }
    }
  }
loc_F0043DFC:
  param_1 = (int *)0x0;
locret_F0043E00:
  return CONCAT44(param_2,param_1);
}

