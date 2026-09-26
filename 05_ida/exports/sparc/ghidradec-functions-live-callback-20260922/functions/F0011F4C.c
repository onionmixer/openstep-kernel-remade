
/* WARNING: Removing unreachable block (ram,0xf0011fd4) */
/* WARNING: Removing unreachable block (ram,0xf00122c4) */
/* WARNING: Removing unreachable block (ram,0xf0012288) */
/* WARNING: Removing unreachable block (ram,0xf0012270) */
/* WARNING: Removing unreachable block (ram,0xf001219c) */
/* WARNING: Removing unreachable block (ram,0xf00120d0) */
/* WARNING: Removing unreachable block (ram,0xf0011f8c) */
/* WARNING: Removing unreachable block (ram,0xf0012090) */
/* WARNING: Removing unreachable block (ram,0xf00120e4) */
/* WARNING: Removing unreachable block (ram,0xf00121bc) */
/* WARNING: Removing unreachable block (ram,0xf0012280) */
/* WARNING: Removing unreachable block (ram,0xf00122b4) */
/* WARNING: Removing unreachable block (ram,0xf0011fcc) */
/* WARNING: Removing unreachable block (ram,0xf0012004) */
/* WARNING: Removing unreachable block (ram,0xf0011f70) */

undefined8 _psig(undefined4 param_1,undefined4 param_2)

{
  char cVar1;
  int *piVar2;
  int iVar3;
  uint uVar4;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  int iVar5;
  undefined4 unaff_l3;
  uint uVar6;
  undefined4 unaff_l4;
  int iVar7;
  undefined4 unaff_l5;
  int iVar8;
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
  iVar5 = *_active_u;
  if (_master_cpu != 0) {
    _panic(aPsigNotOnMaste);
  }
  do {
    do {
    } while (*(int *)(iVar5 + 0x70) != 0);
    piVar2 = (int *)(iVar5 + 0x70);
    _simple_lock_try();
  } while (piVar2 == (int *)0x0);
  iVar3 = *(int *)(iVar5 + 0x74);
  do {
    if (iVar3 == 0) {
      if (*(int *)(iVar5 + 0x78) == 0) {
        cVar1 = *(char *)(iVar5 + 0x17);
        iVar3 = (int)cVar1;
        uVar6 = 1 << (cVar1 - 1U & 0x1f);
        if ((iVar3 == 0) || (((uVar6 & 0x1ef8) != 0 && (iVar3 != *(char *)(dword_F0133DDC + 0x48))))
           ) {
loc_F0012248:
          *(undefined4 *)(iVar5 + 0x70) = 0;
        }
        else {
          if (((int)*(char *)(dword_F0133DDC + 0x40) & 0x80U) != 0) {
            _rpcont();
          }
          iVar7 = _active_u[iVar3 + 0xc];
          if (iVar7 == 0) {
            *(word *)(_active_u + 0x90) = *(word *)(_active_u + 0x90) | 0x10;
            switch(iVar3) {
            case :
            case :
            case :
            case :
            case :
            case :
            case :
            case :
            case :
              *(int *)(dword_F0133DDC + 4) = iVar3;
              *(int *)(iVar5 + 0x78) = _active_threads;
              *(undefined4 *)(iVar5 + 0x70) = 0;
              _task_hold(*(undefined4 *)(_active_threads + 0xc));
              iVar5 = *(int *)(_active_threads + 0xc);
              _task_dowait(iVar5,0);
              _core();
              if (iVar5 != 0) {
                iVar3 = iVar3 + 0x80;
              }
              break;
            :
              *(int *)(iVar5 + 0x78) = _active_threads;
              *(undefined4 *)(iVar5 + 0x70) = 0;
              _task_hold(*(undefined4 *)(_active_threads + 0xc));
              _task_dowait(*(undefined4 *)(_active_threads + 0xc),0);
              break;
            case :
            case :
            case :
            case :
              goto loc_F0012248;
            }
                    /* WARNING: Subroutine does not return */
            _exit(iVar3);
          }
          if ((iVar7 == 1) || ((*(uint *)(iVar5 + 0x1c) & uVar6) != 0)) {
            _log(4,aPsigProcessing);
          }
          *(undefined *)(dword_F0133DDC + 0x38) = 0;
          _splusclock();
          uVar4 = *(uint *)(iVar5 + 0x28);
          if ((uVar4 & 0x100000) != 0) {
            if (1 < iVar3 - 4U) {
              _active_u[iVar3 + 0xc] = 0;
              *(uint *)(iVar5 + 0x24) = *(uint *)(iVar5 + 0x24) & ~uVar6;
            }
            uVar6 = 0;
            uVar4 = *(uint *)(iVar5 + 0x28);
          }
          if ((uVar4 & 0x200) == 0) {
            iVar8 = *(int *)(iVar5 + 0x1c);
          }
          else {
            iVar8 = _active_u[0x50];
            *(uint *)(iVar5 + 0x28) = uVar4 & 0xfffffdff;
          }
          *(uint *)(iVar5 + 0x1c) = *(uint *)(iVar5 + 0x1c) | _active_u[iVar3 + 0x2d] | uVar6;
          *(undefined *)(iVar5 + 0x17) = 0;
          if ((0x1ef8 >> (cVar1 - 1U & 0x1f) & 1U) != 0) {
            *(undefined *)(dword_F0133DDC + 0x48) = 0;
          }
          *(undefined4 *)(iVar5 + 0x70) = 0;
          _spl0();
          _active_u[0x6a] = _active_u[0x6a] + 1;
          _sendsig(iVar7,iVar3,iVar8);
        }
locret_F00122D4:
        return CONCAT44(param_2,param_1);
      }
      iVar3 = *(int *)(iVar5 + 0x78);
    }
    else {
      iVar3 = *(int *)(iVar5 + 0x78);
    }
    *(undefined4 *)(iVar5 + 0x70) = 0;
    if (iVar3 != 0) {
      if (_active_threads == iVar3) goto locret_F00122D4;
      _thread_hold();
    }
    _thread_block();
    if ((*(uint *)(_active_threads + 0x18c) & 3) != 0) goto locret_F00122D4;
    do {
      do {
      } while (*(int *)(iVar5 + 0x70) != 0);
      piVar2 = (int *)(iVar5 + 0x70);
      _simple_lock_try();
    } while (piVar2 == (int *)0x0);
    iVar3 = *(int *)(iVar5 + 0x74);
  } while( true );
}

