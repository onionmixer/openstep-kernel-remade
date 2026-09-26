/* GHIDRADEC_FUNCTION index=900 start=0xf00439f8 */

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
/* GHIDRADEC_FUNCTION index=901 start=0xf0043e08 */

/* WARNING: Removing unreachable block (ram,0xf0043e34) */
/* WARNING: Removing unreachable block (ram,0xf0043e10) */

undefined8 _xdr_opaque_auth(int param_1,int param_2)

{
  int iVar1;
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
  iVar1 = param_1;
  _xdr_enum(param_1,param_2);
  if (iVar1 == 0) {
    param_1 = 0;
  }
  else {
    _xdr_bytes(param_1,param_2 + 4,param_2 + 8,400);
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=902 start=0xf0043e48 */

/* WARNING: Removing unreachable block (ram,0xf0043e54) */

undefined8 _xdr_des_block(undefined4 param_1,undefined4 param_2)

{
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
  _xdr_opaque(param_1,param_2,8);
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=903 start=0xf0043e64 */

/* WARNING: Removing unreachable block (ram,0xf0043ecc) */
/* WARNING: Removing unreachable block (ram,0xf0043e80) */
/* WARNING: Removing unreachable block (ram,0xf0043ee8) */
/* WARNING: Removing unreachable block (ram,0xf0043e6c) */

undefined8 _xdr_accepted_reply(int param_1,int param_2)

{
  int iVar1;
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
  iVar1 = param_1;
  _xdr_opaque_auth(param_1,param_2);
  if (iVar1 != 0) {
    iVar1 = param_1;
    _xdr_enum(param_1,param_2 + 0xc);
    if (iVar1 == 0) {
      param_1 = 0;
      goto locret_F0043EF4;
    }
    if (*(int *)(param_2 + 0xc) == 0) {
      (**(code **)(param_2 + 0x14))(param_1,*(undefined4 *)(param_2 + 0x10));
      goto locret_F0043EF4;
    }
    if (*(int *)(param_2 + 0xc) != 2) {
      param_1 = 1;
      goto locret_F0043EF4;
    }
    iVar1 = param_1;
    _xdr_u_long(param_1,param_2 + 0x10);
    if (iVar1 != 0) {
      _xdr_u_long(param_1,param_2 + 0x14);
      goto locret_F0043EF4;
    }
  }
  param_1 = 0;
locret_F0043EF4:
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=904 start=0xf0043efc */

/* WARNING: Removing unreachable block (ram,0xf0043f50) */
/* WARNING: Removing unreachable block (ram,0xf0043f3c) */
/* WARNING: Removing unreachable block (ram,0xf0043f60) */
/* WARNING: Removing unreachable block (ram,0xf0043f04) */

undefined8 _xdr_rejected_reply(int param_1,int *param_2)

{
  int iVar1;
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
  iVar1 = param_1;
  _xdr_enum(param_1,param_2);
  if (iVar1 == 0) {
    param_1 = 0;
  }
  else if (*param_2 == 0) {
    iVar1 = param_1;
    _xdr_u_long(param_1,param_2 + 1);
    if (iVar1 == 0) {
      param_1 = 0;
    }
    else {
      _xdr_u_long(param_1,param_2 + 2);
    }
  }
  else if (*param_2 == 1) {
    _xdr_enum(param_1,param_2 + 1);
  }
  else {
    param_1 = 0;
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=905 start=0xf0043f7c */

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
/* GHIDRADEC_FUNCTION index=906 start=0xf00442cc */

/* WARNING: Removing unreachable block (ram,0xf004432c) */
/* WARNING: Removing unreachable block (ram,0xf0044304) */
/* WARNING: Removing unreachable block (ram,0xf0044318) */
/* WARNING: Removing unreachable block (ram,0xf0044340) */
/* WARNING: Removing unreachable block (ram,0xf00442f0) */

undefined8 _xdr_callhdr(int *param_1,int param_2)

{
  int *piVar1;
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
  *(undefined4 *)(param_2 + 4) = 0;
  *(undefined4 *)(param_2 + 8) = 2;
  if (*param_1 == 0) {
    piVar1 = param_1;
    _xdr_u_long(param_1,param_2);
    if ((((piVar1 == (int *)0x0) ||
         (piVar1 = param_1, _xdr_enum(param_1,param_2 + 4), piVar1 == (int *)0x0)) ||
        (piVar1 = param_1, _xdr_u_long(param_1,param_2 + 8), piVar1 == (int *)0x0)) ||
       (piVar1 = param_1, _xdr_u_long(param_1,param_2 + 0xc), piVar1 == (int *)0x0)) {
      param_1 = (int *)0x0;
    }
    else {
      _xdr_u_long(param_1,param_2 + 0x10);
    }
  }
  else {
    param_1 = (int *)0x0;
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=907 start=0xf0044440 */

/* WARNING: Removing unreachable block (ram,0xf004448c) */
/* WARNING: Removing unreachable block (ram,0xf004447c) */

undefined8 __seterr_reply(int param_1,uint *param_2)

{
  uint uVar1;
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
  if (*(int *)(param_1 + 8) == 0) {
    if (*(int *)(param_1 + 0x18) == 0) {
      *param_2 = 0;
      goto locret_F00444FC;
    }
    sub_F004435C(*(int *)(param_1 + 0x18),param_2);
    uVar1 = *param_2;
  }
  else if (*(int *)(param_1 + 8) == 1) {
    sub_F00443F4(*(undefined4 *)(param_1 + 0xc),param_2);
    uVar1 = *param_2;
  }
  else {
    *param_2 = 0x10;
    param_2[1] = *(uint *)(param_1 + 8);
    uVar1 = *param_2;
  }
  if (uVar1 == 7) {
    param_2[1] = *(uint *)(param_1 + 0x10);
  }
  else {
    if (uVar1 < 8) {
      if (uVar1 != 6) goto locret_F00444FC;
      param_2[1] = *(uint *)(param_1 + 0x10);
      uVar1 = *(uint *)(param_1 + 0x14);
    }
    else {
      if (uVar1 != 9) goto locret_F00444FC;
      param_2[1] = *(uint *)(param_1 + 0x1c);
      uVar1 = *(uint *)(param_1 + 0x20);
    }
    param_2[2] = uVar1;
  }
locret_F00444FC:
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=908 start=0xf0044504 */

/* WARNING: Removing unreachable block (ram,0xf004462c) */
/* WARNING: Removing unreachable block (ram,0xf00445b8) */
/* WARNING: Removing unreachable block (ram,0xf0044594) */

undefined8 _ku_recvfrom(int param_1,undefined4 *param_2)

{
  int *piVar1;
  sword sVar2;
  int iVar3;
  int *piVar4;
  int *piVar5;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  int iVar6;
  int iVar7;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  sword *psVar8;
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
  piVar4 = *(int **)(param_1 + 0x30);
  iVar6 = 0;
  psVar8 = (sword *)(param_1 + 0x24);
  if (piVar4 == (int *)0x0) {
    piVar4 = (int *)0x0;
  }
  else {
    iVar3 = piVar4[1];
    iVar7 = piVar4[0x1f];
    *param_2 = *(undefined4 *)((int)piVar4 + iVar3);
    param_2[1] = *(undefined4 *)((int)piVar4 + iVar3 + 4);
    param_2[2] = *(undefined4 *)((int)piVar4 + iVar3 + 8);
    param_2[3] = *(undefined4 *)((int)piVar4 + iVar3 + 0xc);
    sVar2 = *(sword *)((int)piVar4 + 10);
    while (sVar2 != 1) {
      sVar2 = *(sword *)(param_1 + 0x28);
      *psVar8 = *psVar8 - *(sword *)(piVar4 + 2);
      *(sword *)(param_1 + 0x28) = sVar2 + -0x80;
      if (0x7c < (uint)piVar4[1]) {
        *(sword *)(param_1 + 0x28) = sVar2 + -0x480;
      }
      _m_free();
      if (piVar4 == (int *)0x0) break;
      sVar2 = *(sword *)((int)piVar4 + 10);
    }
    piVar5 = piVar4;
    if (piVar4 == (int *)0x0) {
      _printf(aKuRecvfromNoBo);
      *(int *)(param_1 + 0x30) = iVar7;
      piVar4 = (int *)0x0;
    }
    else {
      do {
        sVar2 = *(sword *)(param_1 + 0x28);
        *psVar8 = *psVar8 - *(sword *)(piVar5 + 2);
        *(sword *)(param_1 + 0x28) = sVar2 + -0x80;
        if (0x7c < (uint)piVar5[1]) {
          *(sword *)(param_1 + 0x28) = sVar2 + -0x480;
        }
        piVar1 = piVar5 + 2;
        piVar5 = (int *)*piVar5;
        iVar6 = iVar6 + *(sword *)piVar1;
      } while (piVar5 != (int *)0x0);
      *(int *)(param_1 + 0x30) = iVar7;
      if (0x2260 < iVar6) {
        _printf(aKuRecvfromLenD,iVar6);
      }
    }
  }
  return CONCAT44(param_2,piVar4);
}
/* GHIDRADEC_FUNCTION index=909 start=0xf0044640 */

/* WARNING: Removing unreachable block (ram,0xf00446f4) */
/* WARNING: Removing unreachable block (ram,0xf00446e0) */
/* WARNING: Removing unreachable block (ram,0xf004472c) */
/* WARNING: Removing unreachable block (ram,0xf004471c) */
/* WARNING: Removing unreachable block (ram,0xf00446bc) */
/* WARNING: Removing unreachable block (ram,0xf00446a8) */
/* WARNING: Removing unreachable block (ram,0xf0044714) */
/* WARNING: Removing unreachable block (ram,0xf0044724) */
/* WARNING: Removing unreachable block (ram,0xf00446d4) */
/* WARNING: Removing unreachable block (ram,0xf00446ec) */
/* WARNING: Removing unreachable block (ram,0xf0044670) */
/* WARNING: Removing unreachable block (ram,0xf004465c) */

undefined8 _ku_sendto_mbuf(int param_1,undefined4 param_2,undefined4 *param_3)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  int iVar3;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int iVar4;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 uVar5;
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
  iVar1 = 1;
  iVar3 = *(int *)(param_1 + 8);
  _Sendtries = _Sendtries + 1;
  _m_get(1,8);
  if (iVar1 == 0) {
    _m_freem(param_2);
    iVar4 = 0x37;
  }
  else {
    iVar4 = *(int *)(iVar1 + 4);
    *(undefined2 *)(iVar1 + 8) = 0x10;
    *(undefined4 *)(iVar1 + iVar4) = *param_3;
    iVar4 = iVar1 + iVar4;
    *(undefined4 *)(iVar4 + 4) = param_3[1];
    *(undefined4 *)(iVar4 + 8) = param_3[2];
    uVar2 = param_3[3];
    *(undefined4 *)(iVar4 + 0xc) = uVar2;
    _splnet();
    uVar5 = *(undefined4 *)(iVar3 + 0x14);
    iVar4 = iVar3;
    _in_pcbconnect(iVar3,iVar1);
    if (iVar4 == 0) {
      iVar4 = iVar3;
      _udp_output(iVar3,param_2);
      _in_pcbdisconnect(iVar3);
      *(undefined4 *)(iVar3 + 0x14) = uVar5;
      _splx(uVar2);
      _m_free(iVar1);
      _Sendok = _Sendok + 1;
    }
    else {
      _printf(aPcbsetaddrFail,iVar4);
      _splx(uVar2);
      _m_freem(param_2);
      _m_free(iVar1);
    }
  }
  return CONCAT44(param_2,iVar4);
}
/* GHIDRADEC_FUNCTION index=910 start=0xf004473c */

undefined8 _xprt_register(undefined4 param_1,undefined4 param_2)

{
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
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=911 start=0xf0044748 */

/* WARNING: Removing unreachable block (ram,0xf004477c) */
/* WARNING: Removing unreachable block (ram,0xf0044754) */

undefined8 _svc_register(undefined4 param_1,int param_2,undefined4 param_3,int param_4)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar3;
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
  iVar1 = param_2;
  sub_F0044808(param_2,param_3,(undefined *)((int)register0x00000038 + -0xc));
  if (iVar1 == 0) {
    puVar2 = (undefined4 *)0x10;
    _kalloc();
    puVar2[1] = param_2;
    puVar2[2] = param_3;
    puVar2[3] = param_4;
    *puVar2 = dword_F012F558;
    dword_F012F558 = puVar2;
  }
  else {
    uVar3 = 0;
    if (*(int *)(iVar1 + 0xc) != param_4) goto locret_F00447A8;
  }
  uVar3 = 1;
locret_F00447A8:
  return CONCAT44(param_2,uVar3);
}
/* GHIDRADEC_FUNCTION index=912 start=0xf00447b0 */

/* WARNING: Removing unreachable block (ram,0xf00447f8) */
/* WARNING: Removing unreachable block (ram,0xf00447bc) */

undefined8 _svc_unregister(undefined4 *param_1,undefined4 param_2)

{
  undefined4 *puVar1;
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
  puVar1 = param_1;
  sub_F0044808(param_1,param_2,(undefined *)((int)register0x00000038 + -0xc));
  if (puVar1 != (undefined4 *)0x0) {
    if (*(undefined4 **)((int)register0x00000038 + -0xc) == (undefined4 *)0x0) {
      dword_F012F558 = *puVar1;
    }
    else {
      **(undefined4 **)((int)register0x00000038 + -0xc) = *puVar1;
    }
    *puVar1 = 0;
    _kfree(puVar1,0x10);
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=913 start=0xf0044864 */

undefined8 _svc_sendreply(int param_1,undefined4 param_2,undefined4 param_3)

{
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
  *(undefined4 *)((int)register0x00000038 + -0x34) = 1;
  *(undefined4 *)((int)register0x00000038 + -0x30) = 0;
  *(undefined4 *)((int)register0x00000038 + -0x2c) = *(undefined4 *)(param_1 + 0x20);
  *(undefined4 *)((int)register0x00000038 + -0x28) = *(undefined4 *)(param_1 + 0x24);
  *(undefined4 *)((int)register0x00000038 + -0x24) = *(undefined4 *)(param_1 + 0x28);
  *(undefined4 *)((int)register0x00000038 + -0x20) = 0;
  *(undefined4 *)((int)register0x00000038 + -0x1c) = param_3;
  *(undefined4 *)((int)register0x00000038 + -0x18) = param_2;
  (**(code **)(*(int *)(param_1 + 8) + 0xc))(param_1,(undefined *)((int)register0x00000038 + -0x38))
  ;
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=914 start=0xf00448b4 */

undefined8 _svcerr_noproc(int param_1,undefined4 param_2)

{
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
  *(undefined4 *)((int)register0x00000038 + -0x34) = 1;
  *(undefined4 *)((int)register0x00000038 + -0x30) = 0;
  *(undefined4 *)((int)register0x00000038 + -0x2c) = *(undefined4 *)(param_1 + 0x20);
  *(undefined4 *)((int)register0x00000038 + -0x28) = *(undefined4 *)(param_1 + 0x24);
  *(undefined4 *)((int)register0x00000038 + -0x24) = *(undefined4 *)(param_1 + 0x28);
  *(undefined4 *)((int)register0x00000038 + -0x20) = 3;
  (**(code **)(*(int *)(param_1 + 8) + 0xc))(param_1,(undefined *)((int)register0x00000038 + -0x38))
  ;
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=915 start=0xf0044900 */

undefined8 _svcerr_decode(int param_1,undefined4 param_2)

{
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
  *(undefined4 *)((int)register0x00000038 + -0x34) = 1;
  *(undefined4 *)((int)register0x00000038 + -0x30) = 0;
  *(undefined4 *)((int)register0x00000038 + -0x2c) = *(undefined4 *)(param_1 + 0x20);
  *(undefined4 *)((int)register0x00000038 + -0x28) = *(undefined4 *)(param_1 + 0x24);
  *(undefined4 *)((int)register0x00000038 + -0x24) = *(undefined4 *)(param_1 + 0x28);
  *(undefined4 *)((int)register0x00000038 + -0x20) = 4;
  (**(code **)(*(int *)(param_1 + 8) + 0xc))(param_1,(undefined *)((int)register0x00000038 + -0x38))
  ;
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=916 start=0xf004494c */

undefined8 _svcerr_auth(int param_1,undefined4 param_2)

{
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
  *(undefined4 *)((int)register0x00000038 + -0x34) = 1;
  *(undefined4 *)((int)register0x00000038 + -0x30) = 1;
  *(undefined4 *)((int)register0x00000038 + -0x2c) = 1;
  *(undefined4 *)((int)register0x00000038 + -0x28) = param_2;
  (**(code **)(*(int *)(param_1 + 8) + 0xc))(param_1,(undefined *)((int)register0x00000038 + -0x38))
  ;
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=917 start=0xf0044980 */

/* WARNING: Removing unreachable block (ram,0xf0044988) */

undefined8 _svcerr_weakauth(undefined4 param_1,undefined4 param_2)

{
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
  _svcerr_auth(param_1,5);
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=918 start=0xf0044998 */

undefined8 _svcerr_noprog(int param_1,undefined4 param_2)

{
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
  *(undefined4 *)((int)register0x00000038 + -0x34) = 1;
  *(undefined4 *)((int)register0x00000038 + -0x30) = 0;
  *(undefined4 *)((int)register0x00000038 + -0x2c) = *(undefined4 *)(param_1 + 0x20);
  *(undefined4 *)((int)register0x00000038 + -0x28) = *(undefined4 *)(param_1 + 0x24);
  *(undefined4 *)((int)register0x00000038 + -0x24) = *(undefined4 *)(param_1 + 0x28);
  *(undefined4 *)((int)register0x00000038 + -0x20) = 1;
  (**(code **)(*(int *)(param_1 + 8) + 0xc))(param_1,(undefined *)((int)register0x00000038 + -0x38))
  ;
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=919 start=0xf00449e0 */

undefined8 _svcerr_progvers(int param_1,undefined4 param_2,undefined4 param_3)

{
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
  *(undefined4 *)((int)register0x00000038 + -0x34) = 1;
  *(undefined4 *)((int)register0x00000038 + -0x30) = 0;
  *(undefined4 *)((int)register0x00000038 + -0x2c) = *(undefined4 *)(param_1 + 0x20);
  *(undefined4 *)((int)register0x00000038 + -0x28) = *(undefined4 *)(param_1 + 0x24);
  *(undefined4 *)((int)register0x00000038 + -0x24) = *(undefined4 *)(param_1 + 0x28);
  *(undefined4 *)((int)register0x00000038 + -0x20) = 2;
  *(undefined4 *)((int)register0x00000038 + -0x1c) = param_2;
  *(undefined4 *)((int)register0x00000038 + -0x18) = param_3;
  (**(code **)(*(int *)(param_1 + 8) + 0xc))(param_1,(undefined *)((int)register0x00000038 + -0x38))
  ;
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=920 start=0xf0044a34 */

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
/* GHIDRADEC_FUNCTION index=921 start=0xf0044c00 */

/* WARNING: Removing unreachable block (ram,0xf0044c40) */
/* WARNING: Removing unreachable block (ram,0xf0044c24) */
/* WARNING: Removing unreachable block (ram,0xf0044c48) */
/* WARNING: Removing unreachable block (ram,0xf0044c08) */

void _svc_run(int *param_1)

{
  sword sVar1;
  int *piVar2;
  int iVar3;
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
  
  piVar2 = param_1;
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
    piVar2 = param_1;
  }
  do {
    _splnet();
    iVar3 = *piVar2;
    sVar1 = *(sword *)(iVar3 + 0x24);
    while (sVar1 == 0) {
      _sbwait(iVar3 + 0x24);
      iVar3 = *piVar2;
      sVar1 = *(sword *)(iVar3 + 0x24);
    }
    _splx(param_1);
    _svc_getreq(piVar2);
    param_1 = (int *)((int)_Rpccnt._0_4_ + 1);
    _Rpccnt._0_4_ = param_1;
  } while( true );
}
/* GHIDRADEC_FUNCTION index=922 start=0xf0044c68 */

//Decompiler native message:  Marshaling error: Attribute metatype is not present
//Decompiling function: __authenticate @ 0xf0044c68
/* GHIDRADEC_FUNCTION index=923 start=0xf0044cd8 */

sqword __svcauth_null(undefined4 param_1,uint param_2)

{
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
  return (qword)param_2 << 0x20;
}
/* GHIDRADEC_FUNCTION index=924 start=0xf0044ce4 */

/* WARNING: Removing unreachable block (ram,0xf0044d5c) */
/* WARNING: Removing unreachable block (ram,0xf0044e10) */
/* WARNING: Removing unreachable block (ram,0xf0044e30) */
/* WARNING: Removing unreachable block (ram,0xf0044dfc) */
/* WARNING: Removing unreachable block (ram,0xf0044d10) */

undefined8 __svcauth_unix(int param_1,int param_2)

{
  undefined4 *puVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  undefined4 unaff_l0;
  undefined4 *puVar5;
  undefined4 unaff_l1;
  undefined4 *puVar6;
  int iVar7;
  undefined4 unaff_l3;
  uint uVar8;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar9;
  undefined4 unaff_i1;
  undefined4 *puVar10;
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
  puVar6 = (undefined4 *)((int)register0x00000038 + -0x20);
  puVar5 = *(undefined4 **)(param_1 + 0x18);
  puVar5[1] = puVar5 + 6;
  puVar5[5] = puVar5 + 0x46;
  uVar8 = *(uint *)(param_2 + 0x20);
  _xdrmem_create(puVar6,*(undefined4 *)(param_2 + 0x1c),uVar8,1);
  puVar10 = puVar6;
  (**(code **)(*(int *)((int)register0x00000038 + -0x1c) + 0x18))(puVar6,uVar8);
  if (puVar10 == (undefined4 *)0x0) {
    puVar1 = puVar6;
    _xdr_authunix_parms(puVar6,puVar5);
    puVar10 = (undefined4 *)0x0;
    if (puVar1 == (undefined4 *)0x0) {
      *(undefined4 *)((int)register0x00000038 + -0x20) = 2;
      _xdr_authunix_parms(puVar6,puVar5);
      uVar9 = 1;
      goto loc_F0044E54;
    }
    iVar7 = *(int *)(param_1 + 0x1c);
loc_F0044E44:
    *(undefined4 *)(iVar7 + 0x20) = 0;
    uVar9 = 0;
    *(undefined4 *)(*(int *)(param_1 + 0x1c) + 0x28) = 0;
  }
  else {
    *puVar5 = *puVar10;
    iVar7 = puVar10[1];
    puVar10 = puVar10 + 2;
    if (iVar7 < 0x100) {
      _bcopy(puVar10,puVar5[1],iVar7);
      uVar2 = iVar7 + 3;
      *(undefined *)(puVar5[1] + iVar7) = 0;
      if ((int)uVar2 < 0) {
        uVar2 = iVar7 + 6;
      }
      puVar10 = (undefined4 *)((int)puVar10 + (uVar2 & 0xfffffffc));
      puVar5[2] = *puVar10;
      puVar5[3] = puVar10[1];
      iVar7 = puVar10[2];
      puVar10 = puVar10 + 3;
      if (iVar7 < 0x11) {
        iVar4 = 0;
        puVar5[4] = iVar7;
        if (0 < iVar7) {
          do {
            iVar3 = iVar4 * 4;
            iVar4 = iVar4 + 1;
            *(undefined4 *)(puVar5[5] + iVar3) = *puVar10;
            puVar10 = puVar10 + 1;
          } while (iVar4 < iVar7);
        }
        if ((iVar7 + 5) * 4 + (uVar2 & 0xfffffffc) <= uVar8) {
          iVar7 = *(int *)(param_1 + 0x1c);
          goto loc_F0044E44;
        }
        _printf(aBadAuthLenGidD,iVar7,uVar8,uVar8);
      }
    }
    uVar9 = 1;
  }
loc_F0044E54:
  (**(code **)(*(int *)((int)register0x00000038 + -0x1c) + 0x1c))
            ((undefined *)((int)register0x00000038 + -0x20));
  return CONCAT44(puVar10,uVar9);
}
/* GHIDRADEC_FUNCTION index=925 start=0xf0044e6c */

undefined8 __svcauth_short(undefined4 param_1,undefined4 param_2)

{
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
  return CONCAT44(param_2,2);
}
/* GHIDRADEC_FUNCTION index=926 start=0xf0044e78 */

/* WARNING: Removing unreachable block (ram,0xf0044ea4) */
/* WARNING: Removing unreachable block (ram,0xf0044e8c) */
/* WARNING: Removing unreachable block (ram,0xf0044e98) */
/* WARNING: Removing unreachable block (ram,0xf0044ed0) */
/* WARNING: Removing unreachable block (ram,0xf0044e7c) */

undefined8 _svckudp_create(undefined4 param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  int iVar3;
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
  puVar1 = (undefined4 *)0x34;
  _kalloc();
  uVar2 = 0x2260;
  _kalloc();
  puVar1[0xb] = uVar2;
  iVar3 = 0x1cc;
  _kalloc();
  _bzero();
  puVar1[3] = 0;
  puVar1[0xc] = iVar3;
  puVar1[9] = iVar3 + 0x3c;
  puVar1[2] = _svckudp_op;
  *(sword *)(puVar1 + 1) = (sword)param_2;
  *puVar1 = param_1;
  _xprt_register(puVar1);
  return CONCAT44(param_2,puVar1);
}
/* GHIDRADEC_FUNCTION index=927 start=0xf0044ee0 */

/* WARNING: Removing unreachable block (ram,0xf0044f14) */
/* WARNING: Removing unreachable block (ram,0xf0044f04) */
/* WARNING: Removing unreachable block (ram,0xf0044f20) */
/* WARNING: Removing unreachable block (ram,0xf0044ef8) */

undefined8 _svckudp_destroy(int param_1,undefined4 param_2)

{
  undefined4 unaff_l0;
  int iVar1;
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
  iVar1 = *(int *)(param_1 + 0x30);
  if (*(int *)(iVar1 + 8) != 0) {
    _m_freem();
  }
  _kfree(iVar1,0x1cc);
  _kfree(*(undefined4 *)(param_1 + 0x2c),0x2260);
  _kfree(param_1,0x34);
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=928 start=0xf0044f30 */

/* WARNING: Removing unreachable block (ram,0xf0044fbc) */
/* WARNING: Removing unreachable block (ram,0xf0044f64) */
/* WARNING: Removing unreachable block (ram,0xf0044f58) */
/* WARNING: Removing unreachable block (ram,0xf0044fb0) */
/* WARNING: Removing unreachable block (ram,0xf0044fec) */
/* WARNING: Removing unreachable block (ram,0xf0044f48) */

undefined8 _svckudp_recv(int *param_1,undefined4 *param_2)

{
  int iVar1;
  int iVar2;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  int iVar3;
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
  iVar3 = param_1[0xc];
  iVar1 = _rsstat + 1;
  _rsstat = iVar1;
  _splnet();
  iVar2 = *param_1;
  _ku_recvfrom(iVar2,param_1 + 4);
  _splx(iVar1);
  iVar1 = iVar3 + 0xc;
  if (iVar2 == 0) {
    uVar4 = 0;
    DAT_f013ad18._0_4_ = DAT_f013ad18._0_4_ + 1;
  }
  else {
    if (*(word *)(iVar2 + 8) < 0x10) {
      DAT_f013ad18._4_4_ = DAT_f013ad18._4_4_ + 1;
    }
    else {
      _xdrmbuf_init(iVar1,iVar2,1);
      _xdr_callmsg(iVar1,param_2);
      uVar4 = 1;
      if (iVar1 != 0) {
        *(undefined4 *)(iVar3 + 4) = *param_2;
        *(int *)(iVar3 + 8) = iVar2;
        goto locret_F0045010;
      }
      DAT_f013ad18._8_4_ = DAT_f013ad18._8_4_ + 1;
    }
    _m_freem(iVar2);
    *(undefined4 *)(iVar3 + 8) = 0;
    uVar4 = 0;
    DAT_f013ad14._0_4_ = DAT_f013ad14._0_4_ + 1;
  }
locret_F0045010:
  return CONCAT44(param_2,uVar4);
}
/* GHIDRADEC_FUNCTION index=929 start=0xf0045048 */

/* WARNING: Removing unreachable block (ram,0xf004514c) */
/* WARNING: Removing unreachable block (ram,0xf00450f4) */
/* WARNING: Removing unreachable block (ram,0xf00450d0) */
/* WARNING: Removing unreachable block (ram,0xf004509c) */
/* WARNING: Removing unreachable block (ram,0xf0045078) */
/* WARNING: Removing unreachable block (ram,0xf00450bc) */
/* WARNING: Removing unreachable block (ram,0xf00450e0) */
/* WARNING: Removing unreachable block (ram,0xf0045130) */
/* WARNING: Removing unreachable block (ram,0xf0045154) */
/* WARNING: Removing unreachable block (ram,0xf004504c) */

undefined8 _svckudp_send(int *param_1,uint *param_2)

{
  int *piVar1;
  code *pcVar2;
  uint *puVar3;
  uint *puVar4;
  int iVar5;
  undefined4 *puVar6;
  uint uVar7;
  undefined4 unaff_l0;
  uint *puVar8;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 uVar9;
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
  puVar8 = (uint *)param_1[0xc];
  piVar1 = param_1;
  _spltty();
  uVar9 = 0;
  puVar4 = puVar8 + 9;
  uVar7 = *puVar8;
  if ((uVar7 & 1) != 0) {
    do {
      *puVar8 = uVar7 | 2;
      _sleep(puVar8,0x17);
      uVar7 = *puVar8;
    } while ((uVar7 & 1) != 0);
    uVar7 = *puVar8;
  }
  *puVar8 = uVar7 | 1;
  _splx(piVar1);
  pcVar2 = sub_F0045018;
  _mclgetx(sub_F0045018,puVar8,param_1[0xb],0x2260,1);
  if (pcVar2 == (code *)0x0) {
    sub_F0045018(puVar8);
    goto locret_F0045178;
  }
  _xdrmbuf_init(puVar8 + 9,pcVar2,0);
  *param_2 = puVar8[1];
  puVar3 = puVar4;
  _xdr_replymsg();
  if (puVar3 == (uint *)0x0) {
    _printf(DAT_f010de68);
    _m_freem(pcVar2);
loc_F004515C:
    puVar6 = (undefined4 *)puVar8[0xb];
  }
  else {
    (**(code **)(puVar8[10] + 0x10))();
    if (*(int *)pcVar2 == 0) {
      *(sword *)(pcVar2 + 8) = (sword)puVar4;
    }
    iVar5 = *param_1;
    _ku_sendto_mbuf(iVar5,pcVar2,param_1 + 4);
    if (iVar5 == 0) {
      uVar9 = 1;
      goto loc_F004515C;
    }
    puVar6 = (undefined4 *)puVar8[0xb];
  }
  if (puVar6 != (undefined4 *)0x0) {
    (*(code *)*puVar6)();
  }
locret_F0045178:
  return CONCAT44(param_2,uVar9);
}
/* GHIDRADEC_FUNCTION index=930 start=0xf0045180 */

undefined8 _svckudp_stat(undefined4 param_1,undefined4 param_2)

{
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
  return CONCAT44(param_2,2);
}
/* GHIDRADEC_FUNCTION index=931 start=0xf004518c */

undefined8 _svckudp_getargs(int param_1,code *param_2,undefined4 param_3)

{
  int iVar1;
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
  iVar1 = *(int *)(param_1 + 0x30) + 0xc;
  (*param_2)(iVar1,param_3);
  return CONCAT44(param_2,iVar1);
}
/* GHIDRADEC_FUNCTION index=932 start=0xf00451a8 */

/* WARNING: Removing unreachable block (ram,0xf00451c0) */

undefined8 _svckudp_freeargs(int param_1,code *param_2,int param_3)

{
  undefined4 unaff_l0;
  int iVar1;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int iVar2;
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
  iVar2 = *(int *)(param_1 + 0x30);
  iVar1 = iVar2 + 0xc;
  if (*(int *)(iVar2 + 8) != 0) {
    _m_freem();
  }
  *(undefined4 *)(iVar2 + 8) = 0;
  if (param_3 == 0) {
    iVar1 = 1;
  }
  else {
    *(undefined4 *)(iVar2 + 0xc) = 2;
    (*param_2)(iVar1,param_3);
  }
  return CONCAT44(param_2,iVar1);
}
/* GHIDRADEC_FUNCTION index=933 start=0xf00451fc */

/* WARNING: Removing unreachable block (ram,0xf0045214) */
/* WARNING: Removing unreachable block (ram,0xf0045260) */

undefined8 _svckudp_dupsave(uint *param_1,undefined4 param_2)

{
  uint *puVar1;
  uint uVar2;
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
  if (_ndupreqs < 400) {
    puVar1 = (uint *)0x28;
    _kalloc();
    if (_drmru == (uint *)0x0) {
      puVar1[8] = (uint)puVar1;
    }
    else {
      puVar1[8] = *(uint *)((int)_drmru + 0x20);
      *(uint **)((int)_drmru + 0x20) = puVar1;
    }
    _ndupreqs = _ndupreqs + 1;
  }
  else {
    puVar1 = *(uint **)((int)_drmru + 0x20);
    sub_F00453CC(puVar1);
  }
  *puVar1 = *(uint *)(*(int *)(param_1[7] + 0x30) + 4);
  puVar1[7] = *param_1;
  puVar1[6] = param_1[1];
  puVar1[5] = param_1[2];
  uVar2 = param_1[7];
  puVar1[1] = *(uint *)(uVar2 + 0x10);
  puVar1[2] = *(uint *)(uVar2 + 0x14);
  puVar1[3] = *(uint *)(uVar2 + 0x18);
  puVar1[4] = *(uint *)(uVar2 + 0x1c);
  _drmru = puVar1;
  puVar1[9] = *(uint *)(_drhashtbl + (*puVar1 & 0x1f) * 4);
  *(uint **)(_drhashtbl + (*puVar1 & 0x1f) * 4) = puVar1;
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=934 start=0xf00452f0 */

/* WARNING: Removing unreachable block (ram,0xf0045388) */

undefined8 _svckudp_dup(uint *param_1,undefined4 param_2)

{
  uint uVar1;
  uint *puVar2;
  undefined4 unaff_l0;
  uint *puVar3;
  undefined4 unaff_l1;
  uint uVar4;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar5;
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
  uVar4 = *(uint *)(*(int *)(param_1[7] + 0x30) + 4);
  _dupchecks = _dupchecks + 1;
  puVar3 = *(uint **)(_drhashtbl + (uVar4 & 0x1f) * 4);
  if (puVar3 != (uint *)0x0) {
    uVar1 = *puVar3;
    while( true ) {
      if (uVar1 == uVar4) {
        if (puVar3[7] == *param_1) {
          if (puVar3[6] == param_1[1]) {
            if (puVar3[5] == param_1[2]) {
              puVar2 = puVar3 + 1;
              _bcmp(puVar2,param_1[7] + 0x10,0x10);
              if (puVar2 == (uint *)0x0) {
                uVar5 = 1;
                _dupreqs._0_4_ = _dupreqs._0_4_ + 1;
                goto locret_F00453C4;
              }
              puVar3 = (uint *)puVar3[9];
            }
            else {
              puVar3 = (uint *)puVar3[9];
            }
          }
          else {
            puVar3 = (uint *)puVar3[9];
          }
        }
        else {
          puVar3 = (uint *)puVar3[9];
        }
      }
      else {
        puVar3 = (uint *)puVar3[9];
      }
      if (puVar3 == (uint *)0x0) break;
      uVar1 = *puVar3;
    }
  }
  uVar5 = 0;
locret_F00453C4:
  return CONCAT44(param_2,uVar5);
}
/* GHIDRADEC_FUNCTION index=935 start=0xf0045448 */

undefined8 _xdr_void(undefined4 param_1,undefined4 param_2)

{
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
  return CONCAT44(param_2,1);
}
/* GHIDRADEC_FUNCTION index=936 start=0xf0045454 */

/* WARNING: Removing unreachable block (ram,0xf004545c) */

undefined8 _xdr_int(undefined4 param_1,undefined4 param_2)

{
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
  _xdr_long(param_1,param_2);
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=937 start=0xf004546c */

/* WARNING: Removing unreachable block (ram,0xf0045474) */

undefined8 _xdr_u_int(undefined4 param_1,undefined4 param_2)

{
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
  _xdr_u_long(param_1,param_2);
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=938 start=0xf0045484 */

/* WARNING: Removing unreachable block (ram,0xf00454d0) */

undefined8 _xdr_long(int *param_1,undefined4 param_2)

{
  int iVar1;
  code *pcVar2;
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
  iVar1 = *param_1;
  if (iVar1 == 0) {
    pcVar2 = *(code **)(param_1[1] + 4);
  }
  else {
    if (iVar1 != 1) {
      if (iVar1 == 2) {
        param_1 = (int *)0x1;
      }
      else {
        _printf(aXdrLongFailed);
        param_1 = (int *)0x0;
      }
      goto locret_F00454E4;
    }
    pcVar2 = *(code **)param_1[1];
  }
  (*pcVar2)(param_1,param_2);
locret_F00454E4:
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=939 start=0xf00454ec */

/* WARNING: Removing unreachable block (ram,0xf0045538) */

undefined8 _xdr_u_long(int *param_1,undefined4 param_2)

{
  int iVar1;
  code *pcVar2;
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
  iVar1 = *param_1;
  if (iVar1 == 1) {
    pcVar2 = *(code **)param_1[1];
  }
  else {
    if (iVar1 != 0) {
      if (iVar1 == 2) {
        param_1 = (int *)0x1;
      }
      else {
        _printf(aXdrULongFailed);
        param_1 = (int *)0x0;
      }
      goto locret_F004554C;
    }
    pcVar2 = *(code **)(param_1[1] + 4);
  }
  (*pcVar2)(param_1,param_2);
locret_F004554C:
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=940 start=0xf0045554 */

undefined8 _xdr_short(uint *param_1,sword *param_2)

{
  uint uVar1;
  code *pcVar2;
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
  uVar1 = *param_1;
  if (uVar1 == 1) {
    (**(code **)param_1[1])(param_1,(undefined *)((int)register0x00000038 + -0xc));
    if (param_1 == (uint *)0x0) {
      param_1 = (uint *)0x0;
    }
    else {
      param_1 = (uint *)0x1;
      *param_2 = (sword)*(undefined4 *)((int)register0x00000038 + -0xc);
    }
  }
  else if (uVar1 < 2) {
    pcVar2 = *(code **)(param_1[1] + 4);
    *(int *)((int)register0x00000038 + -0xc) = (int)*param_2;
    (*pcVar2)(param_1,(undefined *)((int)register0x00000038 + -0xc));
  }
  else {
    param_1 = (uint *)0x1;
    if (uVar1 != 2) {
      param_1 = (uint *)0x0;
    }
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=941 start=0xf00455d4 */

/* WARNING: Removing unreachable block (ram,0xf0045658) */

undefined8 _xdr_u_short(uint *param_1,word *param_2)

{
  undefined *puVar1;
  uint uVar2;
  code *pcVar3;
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
  uVar2 = *param_1;
  if (uVar2 == 1) {
    (**(code **)param_1[1])(param_1,(undefined *)((int)register0x00000038 + -0xc));
    if (param_1 != (uint *)0x0) {
      param_1 = (uint *)0x1;
      *param_2 = (word)*(undefined4 *)((int)register0x00000038 + -0xc);
      goto locret_F0045660;
    }
    puVar1 = aXdrUShortDecod;
  }
  else {
    if (uVar2 < 2) {
      pcVar3 = *(code **)(param_1[1] + 4);
      *(uint *)((int)register0x00000038 + -0xc) = (uint)*param_2;
      (*pcVar3)(param_1,(undefined *)((int)register0x00000038 + -0xc));
      goto locret_F0045660;
    }
    param_1 = (uint *)0x1;
    if (uVar2 == 2) goto locret_F0045660;
    puVar1 = aXdrUShortBadOp;
  }
  param_1 = (uint *)0x0;
  _printf(puVar1);
locret_F0045660:
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=942 start=0xf0045668 */

/* WARNING: Removing unreachable block (ram,0xf0045678) */

undefined8 _xdr_char(int param_1,char *param_2)

{
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
  *(int *)((int)register0x00000038 + -0xc) = (int)*param_2;
  _xdr_int(param_1,(undefined *)((int)register0x00000038 + -0xc));
  if (param_1 != 0) {
    *param_2 = (char)*(undefined4 *)((int)register0x00000038 + -0xc);
  }
  return CONCAT44(param_2,(uint)(param_1 != 0));
}
/* GHIDRADEC_FUNCTION index=943 start=0xf00456a4 */

/* WARNING: Removing unreachable block (ram,0xf0045738) */

undefined8 _xdr_bool(uint *param_1,uint *param_2)

{
  undefined *puVar1;
  uint uVar2;
  code *pcVar3;
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
  uVar2 = *param_1;
  if (uVar2 == 1) {
    (**(code **)param_1[1])(param_1,(undefined *)((int)register0x00000038 + -0xc));
    if (param_1 != (uint *)0x0) {
      param_1 = (uint *)0x1;
      *param_2 = (uint)(*(int *)((int)register0x00000038 + -0xc) != 0);
      goto locret_F0045740;
    }
    puVar1 = aXdrBoolDecodeF;
  }
  else {
    if (uVar2 < 2) {
      pcVar3 = *(code **)(param_1[1] + 4);
      *(uint *)((int)register0x00000038 + -0xc) = (uint)(*param_2 != 0);
      (*pcVar3)(param_1,(undefined *)((int)register0x00000038 + -0xc));
      goto locret_F0045740;
    }
    param_1 = (uint *)0x1;
    if (uVar2 == 2) goto locret_F0045740;
    puVar1 = aXdrBoolBadOpFa;
  }
  param_1 = (uint *)0x0;
  _printf(puVar1);
locret_F0045740:
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=944 start=0xf0045748 */

/* WARNING: Removing unreachable block (ram,0xf0045750) */

undefined8 _xdr_enum(undefined4 param_1,undefined4 param_2)

{
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
  _xdr_long(param_1,param_2);
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=945 start=0xf0045760 */

/* WARNING: Removing unreachable block (ram,0xf0045840) */

undefined8 _xdr_opaque(int *param_1,undefined4 param_2,uint param_3)

{
  int iVar1;
  undefined *puVar2;
  int *piVar3;
  code *pcVar4;
  undefined4 unaff_l0;
  int iVar5;
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
  if (param_3 != 0) {
    iVar5 = 0;
    if ((param_3 & 3) != 0) {
      iVar5 = 4 - (param_3 & 3);
    }
    iVar1 = *param_1;
    if (iVar1 == 1) {
      piVar3 = param_1;
      (**(code **)(param_1[1] + 8))(param_1,param_2,param_3);
      if (piVar3 == (int *)0x0) {
        puVar2 = aXdrOpaqueDecod;
        goto loc_F0045840;
      }
      if (iVar5 != 0) {
        pcVar4 = *(code **)(param_1[1] + 8);
        puVar2 = unk_F012F55C;
loc_F0045824:
        (*pcVar4)(param_1,puVar2,iVar5);
        goto locret_F0045850;
      }
    }
    else if (iVar1 == 0) {
      piVar3 = param_1;
      (**(code **)(param_1[1] + 0xc))(param_1,param_2,param_3);
      if (piVar3 == (int *)0x0) {
        puVar2 = aXdrOpaqueEncod;
loc_F0045840:
        param_1 = (int *)0x0;
        _printf(puVar2);
        goto locret_F0045850;
      }
      if (iVar5 != 0) {
        pcVar4 = *(code **)(param_1[1] + 0xc);
        puVar2 = (undefined *)&unk_F010DE90;
        goto loc_F0045824;
      }
    }
    else if (iVar1 != 2) {
      puVar2 = aXdrOpaqueBadOp;
      goto loc_F0045840;
    }
  }
  param_1 = (int *)0x1;
locret_F0045850:
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=946 start=0xf0045858 */

/* WARNING: Removing unreachable block (ram,0xf00458e4) */
/* WARNING: Removing unreachable block (ram,0xf0045914) */
/* WARNING: Removing unreachable block (ram,0xf0045928) */
/* WARNING: Removing unreachable block (ram,0xf00458fc) */
/* WARNING: Removing unreachable block (ram,0xf0045864) */

undefined8 _xdr_bytes(uint *param_1,uint *param_2,uint *param_3,uint param_4)

{
  uint *puVar1;
  uint uVar2;
  undefined *puVar3;
  undefined4 unaff_l0;
  uint uVar4;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  uint uVar5;
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
  uVar4 = *param_2;
  puVar1 = param_1;
  _xdr_u_int(param_1,param_3);
  if (puVar1 == (uint *)0x0) {
    puVar3 = aXdrBytesSizeFa;
loc_F0045928:
    param_1 = (uint *)0x0;
    _printf(puVar3);
    goto locret_F0045930;
  }
  uVar5 = *param_3;
  uVar2 = *param_1;
  if (param_4 < uVar5) {
    if (uVar2 != 2) {
      puVar3 = aXdrBytesBadSiz;
      goto loc_F0045928;
    }
    uVar2 = *param_1;
  }
  if (uVar2 == 1) {
    if (uVar5 == 0) {
loc_F00458D4:
      param_1 = (uint *)0x1;
      goto locret_F0045930;
    }
    if (uVar4 == 0) {
      uVar4 = uVar5;
      _kalloc();
      *param_2 = uVar4;
    }
  }
  else if (1 < uVar2) {
    if (uVar2 != 2) {
      puVar3 = aXdrBytesBadOpF;
      goto loc_F0045928;
    }
    if (uVar4 != 0) {
      _kfree(uVar4,uVar5);
      *param_2 = 0;
    }
    goto loc_F00458D4;
  }
  _xdr_opaque(param_1,uVar4,uVar5);
locret_F0045930:
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=947 start=0xf0045938 */

/* WARNING: Removing unreachable block (ram,0xf0045948) */

undefined8 _xdr_netobj(undefined4 param_1,int param_2)

{
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
  _xdr_bytes(param_1,param_2 + 4,param_2,0x400);
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=948 start=0xf0045958 */

/* WARNING: Removing unreachable block (ram,0xf0045978) */
/* WARNING: Removing unreachable block (ram,0xf0045960) */

undefined8 _xdr_union(int param_1,int *param_2,undefined4 param_3,int *param_4,code *param_5)

{
  int iVar1;
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
  iVar1 = param_1;
  _xdr_enum(param_1,param_2);
  if (iVar1 == 0) {
    _printf(aXdrEnumDscmpFa);
    param_1 = 0;
  }
  else if (param_4[1] == 0) {
loc_F00459B8:
    if (param_5 == (code *)0x0) {
      param_1 = 0;
    }
    else {
      (*param_5)(param_1,param_3,0xffffffff);
    }
  }
  else {
    iVar1 = *param_4;
    while (iVar1 != *param_2) {
      if (param_4[3] == 0) goto loc_F00459B8;
      iVar1 = param_4[2];
      param_4 = param_4 + 2;
    }
    (*(code *)param_4[1])(param_1,param_3,0xffffffff);
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=949 start=0xf00459fc */

/* WARNING: Removing unreachable block (ram,0xf0045ac8) */
/* WARNING: Removing unreachable block (ram,0xf0045aa8) */
/* WARNING: Removing unreachable block (ram,0xf0045a40) */
/* WARNING: Removing unreachable block (ram,0xf0045ad8) */
/* WARNING: Removing unreachable block (ram,0xf0045af0) */
/* WARNING: Removing unreachable block (ram,0xf0045a30) */

undefined8 _xdr_string(uint *param_1,int *param_2,uint param_3)

{
  uint *puVar1;
  int iVar2;
  undefined *puVar3;
  int iVar4;
  uint uVar5;
  undefined4 unaff_l0;
  int iVar6;
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
  iVar6 = *param_2;
  if (*param_1 == 0) {
loc_F0045A30:
    iVar4 = iVar6;
    _strlen();
    *(int *)((int)register0x00000038 + -0xc) = iVar4;
  }
  else if (*param_1 == 2) {
    if (iVar6 == 0) {
      param_1 = (uint *)0x1;
      goto locret_F0045AF8;
    }
    goto loc_F0045A30;
  }
  puVar1 = param_1;
  _xdr_u_int(param_1,(undefined *)((int)register0x00000038 + -0xc));
  if (puVar1 == (uint *)0x0) {
    puVar3 = aXdrStringSizeF;
  }
  else {
    if (*(uint *)((int)register0x00000038 + -0xc) <= param_3) {
      uVar5 = *param_1;
      iVar4 = *(uint *)((int)register0x00000038 + -0xc) + 1;
      if (uVar5 == 1) {
        iVar2 = *(int *)((int)register0x00000038 + -0xc);
        if (iVar6 == 0) {
          _kalloc();
          *param_2 = iVar4;
          iVar2 = *(int *)((int)register0x00000038 + -0xc);
          iVar6 = iVar4;
        }
        *(undefined *)(iVar6 + iVar2) = 0;
      }
      else if (1 < uVar5) {
        if (uVar5 == 2) {
          _kfree(iVar6);
          *param_2 = 0;
          param_1 = (uint *)0x1;
          goto locret_F0045AF8;
        }
        puVar3 = aXdrStringBadOp;
        goto loc_F0045AF0;
      }
      _xdr_opaque(param_1,iVar6,*(undefined4 *)((int)register0x00000038 + -0xc));
      goto locret_F0045AF8;
    }
    puVar3 = aXdrStringBadSi;
  }
loc_F0045AF0:
  param_1 = (uint *)0x0;
  _printf(puVar3);
locret_F0045AF8:
  return CONCAT44(param_2,param_1);
}

