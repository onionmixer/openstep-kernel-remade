/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x178458. */
kern_return_t __cdecl vm_region(
        vm_map_t target_task,
        vm_address_t *address,
        vm_size_t *size,
        vm_region_flavor_t flavor,
        vm_region_info_t info,
        mach_msg_type_number_t *infoCnt,
        mach_port_t *object_name)
{
  vm_address_t v8; // ebx
  volatile __int32 *v9; // edx
  _DWORD *v10; // ecx
  vm_map_t v11; // eax
  volatile __int32 *v12; // edx
  volatile __int32 *v13; // edx
  _DWORD *v14; // edx
  vm_address_t v15; // ebx
  char v16; // al
  int v17; // ebx
  volatile __int32 *v18; // edx
  _DWORD *v19; // ecx
  _DWORD *v20; // eax
  volatile __int32 *v21; // edx
  volatile __int32 *v22; // edx
  vm_size_t v23; // eax
  unsigned int v24; // [esp+Ch] [ebp-8h]
  _DWORD *v25; // [esp+10h] [ebp-4h]
  int v26; // [esp+10h] [ebp-4h]
  _DWORD *v27; // [esp+10h] [ebp-4h]
  _DWORD *v28; // [esp+38h] [ebp+24h]
  unsigned int *v29; // [esp+3Ch] [ebp+28h]

  if ( !target_task ) /*0x178465*/
    return 4; /*0x17846c*/
  v8 = *address; /*0x178477*/
  lock_read(target_task); /*0x17847d*/
  v9 = (volatile __int32 *)(target_task + 60); /*0x178488*/
  do /*0x17849e*/
  {
    while ( *v9 ) /*0x17848c*/
      ; /*0x17848e*/
  }
  while ( _InterlockedExchange(v9, 1) == 1 ); /*0x17849e*/
  v10 = *(_DWORD **)(target_task + 56); /*0x1784a3*/
  _InterlockedExchange((volatile __int32 *)(target_task + 60), 0); /*0x1784a8*/
  v11 = target_task + 12; /*0x1784ad*/
  if ( v10 == (_DWORD *)(target_task + 12) ) /*0x1784b2*/
    v10 = *(_DWORD **)(target_task + 16); /*0x1784b4*/
  if ( v10[2] > v8 ) /*0x1784ba*/
  {
    v11 = v10[1]; /*0x1784d0*/
    v10 = *(_DWORD **)(target_task + 16); /*0x1784d6*/
LABEL_20:
    while ( v10 != (_DWORD *)v11 ) /*0x178519*/
    {
      if ( v10[3] > v8 ) /*0x1784df*/
      {
        if ( v10[2] > v8 ) /*0x1784e4*/
          break; /*0x1784e4*/
        v25 = v10; /*0x1784e6*/
        v12 = (volatile __int32 *)(target_task + 60); /*0x1784ec*/
        do /*0x178502*/
        {
          while ( *v12 ) /*0x1784f0*/
            ; /*0x1784f2*/
        }
        while ( _InterlockedExchange(v12, 1) == 1 ); /*0x178502*/
        *(_DWORD *)(target_task + 56) = v10; /*0x178507*/
        _InterlockedExchange((volatile __int32 *)(target_task + 60), 0); /*0x17850c*/
        goto LABEL_26; /*0x17850f*/
      }
      v10 = (_DWORD *)v10[1]; /*0x178514*/
    }
  }
  else if ( v10 != (_DWORD *)v11 ) /*0x1784be*/
  {
    if ( v10[3] <= v8 ) /*0x1784c3*/
      goto LABEL_20; /*0x1784c3*/
    v25 = v10; /*0x1784c5*/
LABEL_26:
    v14 = v25; /*0x17856c*/
    goto LABEL_27; /*0x17856c*/
  }
  v26 = *v10; /*0x17851b*/
  v13 = (volatile __int32 *)(target_task + 60); /*0x178523*/
  do /*0x17853a*/
  {
    while ( *v13 ) /*0x178528*/
      ; /*0x17852a*/
  }
  while ( _InterlockedExchange(v13, 1) == 1 ); /*0x17853a*/
  *(_DWORD *)(target_task + 56) = v26; /*0x178542*/
  _InterlockedExchange((volatile __int32 *)(target_task + 60), 0); /*0x178547*/
  v14 = *(_DWORD **)(v26 + 4); /*0x17854d*/
  if ( v14 == (_DWORD *)(target_task + 12) ) /*0x178558*/
  {
    lock_done(target_task); /*0x17855b*/
    return 3; /*0x178565*/
  }
LABEL_27:
  v15 = v14[2]; /*0x17856f*/
  *(_DWORD *)flavor = v14[7]; /*0x178578*/
  *info = v14[8]; /*0x178580*/
  *infoCnt = v14[9]; /*0x178588*/
  *address = v15; /*0x17858d*/
  *size = v14[3] - v15; /*0x178597*/
  v24 = v14[5]; /*0x17859c*/
  v16 = *((_BYTE *)v14 + 24); /*0x17859f*/
  if ( (v16 & 1) == 0 ) /*0x1785a4*/
  {
    *object_name = 0; /*0x1786b7*/
    if ( (v16 & 4) != 0 ) /*0x1786b2*/
      *v28 = 0; /*0x1786c0*/
    else
      *v28 = vm_object_name(v14[4]); /*0x1786e5*/
    *v29 = v24; /*0x1786cc*/
    goto LABEL_58; /*0x1786ce*/
  }
  v17 = v14[4]; /*0x1785aa*/
  lock_read(v17); /*0x1785ae*/
  v18 = (volatile __int32 *)(v17 + 60); /*0x1785b6*/
  do /*0x1785ce*/
  {
    while ( *v18 ) /*0x1785bc*/
      ; /*0x1785be*/
  }
  while ( _InterlockedExchange(v18, 1) == 1 ); /*0x1785ce*/
  v19 = *(_DWORD **)(v17 + 56); /*0x1785d0*/
  _InterlockedExchange((volatile __int32 *)(v17 + 60), 0); /*0x1785d5*/
  v20 = (_DWORD *)(v17 + 12); /*0x1785d8*/
  if ( v19 == (_DWORD *)(v17 + 12) ) /*0x1785dd*/
    v19 = *(_DWORD **)(v17 + 16); /*0x1785df*/
  if ( v19[2] > v24 ) /*0x1785e8*/
  {
    v20 = (_DWORD *)v19[1]; /*0x1785f8*/
    v19 = *(_DWORD **)(v17 + 16); /*0x1785fb*/
LABEL_45:
    while ( v19 != v20 ) /*0x178635*/
    {
      if ( v19[3] > v24 ) /*0x178606*/
      {
        if ( v19[2] > v24 ) /*0x17860b*/
          goto LABEL_46; /*0x17860b*/
        v27 = v19; /*0x17860d*/
        v21 = (volatile __int32 *)(v17 + 60); /*0x178610*/
        do /*0x178626*/
        {
          while ( *v21 ) /*0x178614*/
            ; /*0x178616*/
        }
        while ( _InterlockedExchange(v21, 1) == 1 ); /*0x178626*/
        *(_DWORD *)(v17 + 56) = v19; /*0x178628*/
        goto LABEL_50; /*0x17862b*/
      }
      v19 = (_DWORD *)v19[1]; /*0x178630*/
    }
    goto LABEL_46; /*0x178635*/
  }
  if ( v19 == v20 ) /*0x1785ec*/
  {
LABEL_46:
    v27 = (_DWORD *)*v19; /*0x178637*/
    v22 = (volatile __int32 *)(v17 + 60); /*0x17863c*/
    do /*0x178652*/
    {
      while ( *v22 ) /*0x178640*/
        ; /*0x178642*/
    }
    while ( _InterlockedExchange(v22, 1) == 1 ); /*0x178652*/
    *(_DWORD *)(v17 + 56) = v27; /*0x178657*/
LABEL_50:
    _InterlockedExchange((volatile __int32 *)(v17 + 60), 0); /*0x17865a*/
    goto LABEL_51; /*0x17865c*/
  }
  if ( v19[3] <= v24 ) /*0x1785f1*/
    goto LABEL_45; /*0x1785f1*/
  v27 = v19; /*0x1785f3*/
LABEL_51:
  v23 = v27[3] - v24; /*0x17865f*/
  if ( *size > v23 ) /*0x17866d*/
    *size = v23; /*0x17866f*/
  *v28 = vm_object_name(v27[4]); /*0x178680*/
  *v29 = v27[5] + v24 - v27[2]; /*0x178691*/
  *object_name = *(_DWORD *)(v17 + 48) != 1; /*0x1786a5*/
  lock_done(v17); /*0x1786a8*/
LABEL_58:
  lock_done(target_task); /*0x1786f2*/
  return 0; /*0x178700*/
}
