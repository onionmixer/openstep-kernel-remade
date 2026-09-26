
undefined4 _netipc_ignore(undefined4 param_1,int param_2)

{
  int *piVar1;
  undefined4 uVar2;
  undefined *puVar3;
  int *piVar4;
  int *piVar5;
  
  uVar2 = 5;
  if (param_2 == 0) {
    uVar2 = 4;
  }
  else {
    puVar3 = _listeners;
    do {
      piVar1 = *(int **)puVar3;
      piVar4 = *(int **)puVar3;
      while (piVar5 = piVar1, piVar5 != (int *)0x0) {
        if (param_2 == piVar5[4]) {
          uVar2 = 0;
          if (piVar5 == *(int **)puVar3) {
            *(int *)puVar3 = *piVar5;
            _zfree(_listener_zone,piVar5);
            piVar4 = *(int **)puVar3;
            if (piVar4 == (int *)0x0) break;
          }
          else {
            *piVar4 = *piVar5;
            _zfree(_listener_zone,piVar5);
          }
          _ipc_object_release(param_2);
          piVar5 = piVar4;
        }
        piVar4 = piVar5;
        piVar1 = (int *)*piVar5;
      }
      puVar3 = (undefined *)((int)puVar3 + 4);
    } while (puVar3 < &_mach_net_kmsg_zone);
  }
  return uVar2;
}

