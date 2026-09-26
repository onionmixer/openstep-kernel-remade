/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001a8df8 */

int FUN_001a8df8(int param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  int local_c;
  undefined *local_8;
  
  puVar1 = *(undefined4 **)(param_1 + 4);
  local_c = param_1;
  local_8 = PTR_s_Object_001fa1f8;
  _objc_msgSendSuper(&local_c,PTR_s_init_001f924c);
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)_kalloc(0xc);
    uVar2 = _simple_lock_alloc();
    *puVar1 = uVar2;
    uVar2 = _lock_alloc();
    puVar1[1] = uVar2;
    *(undefined4 **)(param_1 + 4) = puVar1;
  }
  *(undefined4 *)*puVar1 = 0;
  _lock_init(puVar1[1],1);
  puVar1[2] = param_3;
  return param_1;
}

