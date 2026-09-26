/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0015d8f8 */

undefined4
_netipc_listen(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined2 param_4,
              undefined2 param_5,byte param_6,int param_7)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  uint uVar5;
  
  if (*(short *)(*(int *)(_active_u + 0x1c) + 2) == 0) {
    if (param_7 == 0) {
      uVar3 = 4;
    }
    else {
      puVar4 = (undefined4 *)_zalloc(_listener_zone);
      puVar4[1] = param_2;
      *(undefined2 *)(puVar4 + 3) = param_4;
      puVar4[2] = param_3;
      *(undefined2 *)((int)puVar4 + 0xe) = param_5;
      puVar4[4] = param_7;
      _ipc_object_reference(param_7);
      uVar5 = param_6 & 0xf;
      piVar1 = &_listeners + uVar5 * 2;
      uVar3 = _splnet();
      do {
        do {
        } while (*piVar1 != 0);
        LOCK();
        iVar2 = *piVar1;
        *piVar1 = 1;
        UNLOCK();
      } while (iVar2 == 1);
      *puVar4 = (&DAT_001f6404)[uVar5 * 2];
      (&DAT_001f6404)[uVar5 * 2] = puVar4;
      LOCK();
      *piVar1 = 0;
      UNLOCK();
      _splx(uVar3);
      _ipc_kobject_set(param_7,0,0x11);
      uVar3 = 0;
    }
  }
  else {
    uVar3 = 8;
  }
  return uVar3;
}

