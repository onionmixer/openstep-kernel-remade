
/* WARNING: Removing unreachable block (ram,0xf0071438) */
/* WARNING: Removing unreachable block (ram,0xf00716f4) */
/* WARNING: Removing unreachable block (ram,0xf00716cc) */
/* WARNING: Removing unreachable block (ram,0xf007163c) */
/* WARNING: Removing unreachable block (ram,0xf00715d4) */
/* WARNING: Removing unreachable block (ram,0xf00715f4) */
/* WARNING: Removing unreachable block (ram,0xf00714e0) */
/* WARNING: Removing unreachable block (ram,0xf0071668) */
/* WARNING: Removing unreachable block (ram,0xf00714d4) */
/* WARNING: Removing unreachable block (ram,0xf00714fc) */
/* WARNING: Removing unreachable block (ram,0xf007161c) */
/* WARNING: Removing unreachable block (ram,0xf0071634) */
/* WARNING: Removing unreachable block (ram,0xf007167c) */
/* WARNING: Removing unreachable block (ram,0xf00716ec) */
/* WARNING: Removing unreachable block (ram,0xf007140c) */
/* WARNING: Removing unreachable block (ram,0xf0071440) */
/* WARNING: Removing unreachable block (ram,0xf007145c) */

undefined8 _thread_invoke(int param_1,int param_2,int param_3)

{
  int *piVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
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
  if (param_1 == param_3) {
    do {
      do {
      } while (*(int *)(param_1 + 0x20) != 0);
      piVar1 = (int *)(param_1 + 0x20);
      _simple_lock_try();
    } while (piVar1 == (int *)0x0);
    *(undefined4 *)(param_3 + 0x20) = 0;
    *(uint *)(param_3 + 0x4c) = *(uint *)(param_3 + 0x4c) & 0xfffffff7;
    if (param_2 != 0) {
      uVar5 = 1;
      _spl0();
      _call_continuation(param_2);
      goto locret_F0071700;
    }
  }
  else {
    do {
      do {
      } while (*(int *)(param_3 + 0x20) != 0);
      piVar1 = (int *)(param_3 + 0x20);
      _simple_lock_try();
    } while (piVar1 == (int *)0x0);
    if (*(int *)(param_1 + 0x30) == _active_stacks) {
      uVar2 = *(uint *)(param_3 + 0x4c);
loc_F0071650:
      if ((uVar2 & 0x100) == 0) {
        uVar2 = *(uint *)(param_3 + 0x4c);
      }
      else {
        if (((uVar2 & 0x200) != 0) ||
           (iVar3 = param_3, _stack_alloc_try(param_3,_thread_continue), iVar3 == 0)) {
loc_F007167C:
          _thread_swapin(param_3);
          *(undefined4 *)(param_3 + 0x20) = 0;
          uVar5 = 0;
          _c_thread_invoke_misses = _c_thread_invoke_misses + 1;
          goto locret_F0071700;
        }
        uVar2 = *(uint *)(param_3 + 0x4c);
      }
    }
    else {
      uVar2 = *(uint *)(param_3 + 0x4c);
      if (param_2 == 0) goto loc_F0071650;
      uVar4 = uVar2 & 0x300;
      if (uVar4 == 0x100) {
        *(uint *)(param_3 + 0x4c) = uVar2 & 0xfffffef7;
        *(undefined4 *)(param_3 + 0x20) = 0;
        _need_ast = _need_ast & 0xfffffffc | *(uint *)(param_3 + 0x18c);
        _switch_unix_context(param_3);
        _stack_handoff(param_1,param_3);
        do {
          do {
          } while (*(int *)(param_1 + 0x20) != 0);
          piVar1 = (int *)(param_1 + 0x20);
          _simple_lock_try();
        } while (piVar1 == (int *)0x0);
        iVar3 = *(int *)(param_1 + 0x4c);
        *(int *)(param_1 + 0x34) = param_2;
        if (iVar3 == 0xc) {
loc_F00715E8:
          *(uint *)(param_1 + 0x4c) = *(uint *)(param_1 + 0x4c) | 0x100;
          _thread_setrun(param_1,0);
loc_F0071624:
          *(undefined4 *)(param_1 + 0x20) = 0;
        }
        else {
          if (0xc < iVar3) {
            if (iVar3 != 0xf) {
              if (iVar3 < 0x10) {
                if (iVar3 == 0xd) goto loc_F0071600;
                if (iVar3 == 0xe) goto loc_F00715E8;
              }
              else {
                if (iVar3 == 0x16) {
                  uVar2 = *(uint *)(param_1 + 0x4c);
                  goto loc_F00715AC;
                }
                if (iVar3 == 0x84) {
                  *(undefined4 *)(param_1 + 0x4c) = 0x184;
                  goto loc_F0071624;
                }
              }
              goto loc_F007161C;
            }
loc_F0071600:
            uVar2 = *(uint *)(param_1 + 0x4c);
loc_F0071604:
            *(uint *)(param_1 + 0x4c) = uVar2 & 0xfffffffb | 0x100;
            goto loc_F0071624;
          }
          if (iVar3 == 5) {
            uVar2 = *(uint *)(param_1 + 0x4c);
            goto loc_F0071604;
          }
          if (iVar3 < 6) {
            if (iVar3 == 4) goto loc_F00715E8;
loc_F007161C:
            _panic(aThreadInvoke);
            goto loc_F0071624;
          }
          if (7 < iVar3) goto loc_F007161C;
          uVar2 = *(uint *)(param_1 + 0x4c);
loc_F00715AC:
          *(uint *)(param_1 + 0x4c) = uVar2 & 0xfffffffb | 0x100;
          if (*(int *)(param_1 + 0x48) == 0) goto loc_F0071624;
          *(undefined4 *)(param_1 + 0x48) = 0;
          *(undefined4 *)(param_1 + 0x20) = 0;
          _thread_wakeup_prim(param_1 + 0x48,0,0);
        }
        _c_thread_invoke_hits = _c_thread_invoke_hits + 1;
        _spl0();
        _call_continuation(*(undefined4 *)(param_3 + 0x34));
        uVar5 = 1;
        goto locret_F0071700;
      }
      if ((0x100 < uVar4) && (uVar4 == 0x200)) goto loc_F007167C;
    }
    *(undefined4 *)(param_3 + 0x20) = 0;
    *(uint *)(param_3 + 0x4c) = uVar2 & 0xfffffef7;
    _need_ast = _need_ast & 0xfffffffc | *(uint *)(param_3 + 0x18c);
    _switch_unix_context(param_3);
    _c_thread_invoke_csw = _c_thread_invoke_csw + 1;
    _switch_context(param_1,param_2,param_3);
    _thread_dispatch();
  }
  uVar5 = 1;
locret_F0071700:
  return CONCAT44(param_2,uVar5);
}
