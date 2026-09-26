/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1662d8. */
kern_return_t __cdecl task_threads(
        task_inspect_t target_task,
        thread_act_array_t *act_list,
        mach_msg_type_number_t *act_listCnt)
{
  task_inspect_t v3; // edx
  mach_msg_type_number_t v5; // ebx
  thread_act_t i; // esi
  thread_act_t *v7; // eax
  thread_act_t *v8; // ebx
  mach_msg_type_number_t j; // ebx
  mach_msg_type_number_t v10; // ebx
  int *v11; // esi
  unsigned int v12; // [esp+Ch] [ebp-18h]
  task_inspect_t v13; // [esp+10h] [ebp-14h]
  task_inspect_t v14; // [esp+10h] [ebp-14h]
  task_inspect_t v15; // [esp+10h] [ebp-14h]
  thread_act_t *v16; // [esp+14h] [ebp-10h]
  size_t v17; // [esp+18h] [ebp-Ch]
  thread_act_t *v18; // [esp+1Ch] [ebp-8h]
  mach_msg_type_number_t v19; // [esp+20h] [ebp-4h]

  v3 = target_task; /*0x1662e1*/
  if ( !target_task ) /*0x1662e6*/
    return 4; /*0x1662ed*/
  v12 = 0; /*0x1662f4*/
  v16 = nullptr; /*0x1662fb*/
  while ( 1 ) /*0x166316*/
  {
    do /*0x166316*/
    {
      while ( *(_DWORD *)v3 ) /*0x166304*/
        ; /*0x166306*/
    }
    while ( _InterlockedExchange((volatile __int32 *)v3, 1) == 1 ); /*0x166316*/
    if ( !*(_DWORD *)(v3 + 8) ) /*0x16631c*/
    {
      _InterlockedExchange((volatile __int32 *)v3, 0); /*0x166436*/
      return 5; /*0x16643d*/
    }
    v19 = *(_DWORD *)(v3 + 36); /*0x166325*/
    v17 = 4 * v19; /*0x16632f*/
    if ( 4 * v19 <= v12 ) /*0x166337*/
      break; /*0x166337*/
    _InterlockedExchange((volatile __int32 *)v3, 0); /*0x16633b*/
    if ( v12 ) /*0x16633f*/
    {
      v13 = v3; /*0x166346*/
      kfree((int)v16, v12); /*0x166349*/
      v3 = v13; /*0x166351*/
    }
    v12 = 4 * v19; /*0x166357*/
    v14 = v3; /*0x16635b*/
    v16 = (thread_act_t *)kalloc(v17); /*0x166363*/
    v3 = v14; /*0x166369*/
    if ( !v16 ) /*0x16636e*/
      return 6; /*0x166375*/
  }
  v18 = v16; /*0x16637f*/
  v5 = 0; /*0x166382*/
  for ( i = *(_DWORD *)(v3 + 28); v19 > v5; v3 = v15 ) /*0x16638a*/
  {
    v15 = v3; /*0x16638d*/
    thread_reference(i); /*0x166390*/
    v16[v5++] = i; /*0x166398*/
    i = *(_DWORD *)(i + 16); /*0x16639f*/
  }
  _InterlockedExchange((volatile __int32 *)v3, 0); /*0x1663ac*/
  if ( !v19 ) /*0x1663b2*/
  {
    *act_list = nullptr; /*0x1663b7*/
    *act_listCnt = 0; /*0x1663c0*/
    if ( v12 ) /*0x1663ca*/
      kfree((int)v16, v12); /*0x1663d8*/
    return 0; /*0x1663dd*/
  }
  if ( v17 >= v12 ) /*0x1663ea*/
  {
LABEL_24:
    *act_list = v18; /*0x16645e*/
    *act_listCnt = v19; /*0x16646c*/
    v10 = 0; /*0x16646e*/
    v11 = (int *)v18; /*0x166474*/
    do /*0x16648c*/
    {
      *v11 = convert_thread_to_port(*v11); /*0x166480*/
      ++v11; /*0x166485*/
      ++v10; /*0x166488*/
    }
    while ( v19 > v10 ); /*0x16648c*/
    return 0; /*0x16648e*/
  }
  v7 = (thread_act_t *)kalloc(v17); /*0x1663f0*/
  v8 = v7; /*0x1663f5*/
  if ( v7 ) /*0x1663fc*/
  {
    bcopy(v16, v7, v17); /*0x166449*/
    kfree((int)v16, v12); /*0x166453*/
    v18 = v8; /*0x166458*/
    goto LABEL_24; /*0x166458*/
  }
  for ( j = 0; j < v19; ++j ) /*0x1663fe*/
    thread_deallocate(v16[j]); /*0x16640f*/
  kfree((int)v16, v12); /*0x166425*/
  return 6; /*0x166493*/
}
