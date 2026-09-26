
/* WARNING: Removing unreachable block (ram,0xf0040b2c) */
/* WARNING: Removing unreachable block (ram,0xf0040aec) */
/* WARNING: Removing unreachable block (ram,0xf0040a4c) */
/* WARNING: Removing unreachable block (ram,0xf0040a98) */
/* WARNING: Removing unreachable block (ram,0xf0040b5c) */
/* WARNING: Removing unreachable block (ram,0xf0040a2c) */

undefined8 _async_daemon(undefined4 param_1,undefined4 param_2)

{
  uint *puVar1;
  int iVar2;
  uint uVar3;
  uint *puVar4;
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
  *(undefined4 *)(_active_threads + 0x78) = 1;
  _stack_privilege(_active_threads);
  dword_F012F528 = dword_F012F528 + 1;
  iVar2 = dword_F0133DDC + 0x28;
  _setjmp();
  if (iVar2 == 0) {
    do {
      dword_F012F524 = dword_F012F524 + 1;
      while (_async_bufhead == (uint *)0x0) {
        _sleep(&_async_bufhead,0x1a);
      }
      dword_F012F524 = dword_F012F524 + -1;
      puVar4 = _async_bufhead;
      _async_bufhead = (uint *)_async_bufhead[3];
      sub_F0040B74(puVar4);
    } while( true );
  }
  iVar2 = dword_F012F528 + -1;
  if (dword_F012F528 == 0) {
    if (_async_bufhead != (uint *)0x0) {
      uVar3 = *_async_bufhead;
      while( true ) {
        *_async_bufhead = uVar3 | 4;
        _async_bufhead = (uint *)_async_bufhead[3];
        _biodone();
        if (_async_bufhead == (uint *)0x0) break;
        uVar3 = *_async_bufhead;
      }
    }
  }
  else {
    dword_F012F524 = dword_F012F524 + -1;
    dword_F012F528 = iVar2;
    if ((iVar2 == 0) && (_async_bufhead != (uint *)0x0)) {
      puVar4 = (uint *)_async_bufhead[3];
      while (puVar1 = _async_bufhead, _async_bufhead = puVar4, sub_F0040B74(puVar1),
            _async_bufhead != (uint *)0x0) {
        puVar4 = (uint *)_async_bufhead[3];
      }
    }
  }
  return CONCAT44(param_2,param_1);
}
