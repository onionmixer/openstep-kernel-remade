/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0014dbd4 */

int _ipc_right_dnrequest(int param_1,undefined4 param_2,int param_3,int param_4,undefined4 *param_5)

{
  int *piVar1;
  uint uVar2;
  undefined4 *puVar3;
  int iVar4;
  undefined4 uVar5;
  uint uVar6;
  uint local_c;
  uint *local_8;
  
  piVar1 = (int *)(param_1 + 8);
  do {
    do {
      do {
      } while (*piVar1 != 0);
      LOCK();
      iVar4 = *piVar1;
      *piVar1 = 1;
      UNLOCK();
    } while (iVar4 == 1);
    if (*(int *)(param_1 + 0xc) == 0) {
      LOCK();
      *(undefined4 *)(param_1 + 8) = 0;
      UNLOCK();
      return 0x10;
    }
    local_8 = (uint *)_ipc_entry_lookup(param_1,param_2);
    if (local_8 == (uint *)0x0) {
LAB_0014dd2c:
      LOCK();
      *(undefined4 *)(param_1 + 8) = 0;
      UNLOCK();
      return 0xf;
    }
    uVar6 = *local_8;
    if ((uVar6 & 0x70000) == 0) {
LAB_0014dd3d:
      if ((((uVar6 & 0x100000) == 0) || (param_3 == 0)) || (param_4 == 0)) {
        LOCK();
        *(undefined4 *)(param_1 + 8) = 0;
        UNLOCK();
        if ((uVar6 & 0x170000) != 0) {
          return 4;
        }
        return 0x11;
      }
      uVar2 = (uVar6 & 0xffff) + 1;
      if ((uVar2 <= (uVar6 & 0xffff)) || (0xffff < uVar2)) {
        LOCK();
        *(undefined4 *)(param_1 + 8) = 0;
        UNLOCK();
        return 0x13;
      }
      *local_8 = uVar6 + 1;
      LOCK();
      *(undefined4 *)(param_1 + 8) = 0;
      UNLOCK();
      _ipc_notify_dead_name(param_4,param_2);
      uVar5 = 0;
LAB_0014dda8:
      *param_5 = uVar5;
      return 0;
    }
    puVar3 = (undefined4 *)local_8[1];
    iVar4 = _ipc_right_check(param_1,puVar3,param_2,local_8);
    if (iVar4 != 0) {
      if ((uVar6 & 0x400000) != 0) goto LAB_0014dd2c;
      uVar6 = *local_8;
      goto LAB_0014dd3d;
    }
    if (param_4 == 0) {
      if (((uVar6 & 0x400000) == 0) && (local_8[2] != 0)) {
        uVar5 = _ipc_right_dncancel(param_1,puVar3,param_2,local_8);
      }
      else {
        uVar5 = 0;
      }
      LOCK();
      *puVar3 = 0;
      UNLOCK();
LAB_0014dd19:
      LOCK();
      *(undefined4 *)(param_1 + 8) = 0;
      UNLOCK();
      goto LAB_0014dda8;
    }
    if (local_8[2] == 0) {
      uVar5 = 0;
    }
    else {
      uVar5 = _ipc_right_dncancel(param_1,puVar3,param_2,local_8);
    }
    iVar4 = _ipc_port_dnrequest(puVar3,param_2,param_4,&local_c);
    if (iVar4 == 0) {
      LOCK();
      *puVar3 = 0;
      UNLOCK();
      local_8[2] = local_c;
      *local_8 = uVar6 & 0xffbfffff;
      goto LAB_0014dd19;
    }
    LOCK();
    *(undefined4 *)(param_1 + 8) = 0;
    UNLOCK();
    iVar4 = _ipc_port_dngrow(puVar3);
    if (iVar4 != 0) {
      return iVar4;
    }
  } while( true );
}

