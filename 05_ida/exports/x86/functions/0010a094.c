/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x10a094. */
thread_act_t psig()
{
  int v0; // ebx
  volatile __int32 *v1; // edx
  volatile __int32 *v2; // esi
  int v3; // edx
  thread_act_t result; // eax
  int v5; // esi
  int v6; // edi
  int v7; // ecx
  int v8; // edx
  long double v9; // [esp-8h] [ebp-1Ch]
  int v10; // [esp+Ch] [ebp-8h]
  int v11; // [esp+10h] [ebp-4h]

  v0 = *(_DWORD *)active_u; /*0x10a0a2*/
  if ( master_cpu ) /*0x10a0ab*/
    panic(aPsigNotOnMaste); /*0x10a0b2*/
  v1 = (volatile __int32 *)(v0 + 112); /*0x10a0ba*/
  do /*0x10a0d2*/
  {
    while ( *v1 ) /*0x10a0c0*/
      ; /*0x10a0c2*/
  }
  while ( _InterlockedExchange(v1, 1) == 1 ); /*0x10a0d2*/
  while ( *(_DWORD *)(v0 + 116) || *(_DWORD *)(v0 + 120) ) /*0x10a136*/
  {
    v2 = (volatile __int32 *)(v0 + 112); /*0x10a0d8*/
    _InterlockedExchange((volatile __int32 *)(v0 + 112), 0); /*0x10a0dd*/
    v3 = *(_DWORD *)(v0 + 120); /*0x10a0e0*/
    if ( v3 ) /*0x10a0e5*/
    {
      result = active_threads; /*0x10a0e7*/
      if ( active_threads == v3 ) /*0x10a0ee*/
        return result; /*0x10a0ee*/
      thread_hold(active_threads); /*0x10a0f5*/
    }
    thread_block(); /*0x10a0fd*/
    result = active_threads; /*0x10a102*/
    if ( (*(_BYTE *)(active_threads + 380) & 3) != 0 ) /*0x10a10e*/
      return result; /*0x10a10e*/
    do /*0x10a12a*/
    {
      while ( *v2 ) /*0x10a118*/
        ; /*0x10a11a*/
    }
    while ( _InterlockedExchange(v2, 1) == 1 ); /*0x10a12a*/
  }
  v5 = *(char *)(v0 + 23); /*0x10a138*/
  v6 = 1 << (v5 - 1); /*0x10a144*/
  if ( !*(_BYTE *)(v0 + 23) || (v6 & 0x1EF8) != 0 && v5 != *(char *)(dword_1E875C + 120) ) /*0x10a161*/
    return _InterlockedExchange((volatile __int32 *)(v0 + 112), 0); /*0x10a2bc*/
  if ( *(char *)(dword_1E875C + 112) < 0 ) /*0x10a170*/
    rpcont(); /*0x10a172*/
  v7 = *(_DWORD *)(active_u + 4 * v5 + 48); /*0x10a17c*/
  v10 = v7; /*0x10a180*/
  if ( !v7 ) /*0x10a185*/
  {
    *(_BYTE *)(active_u + 580) |= 0x10u; /*0x10a250*/
    switch ( v5 ) /*0x10a263*/
    {
      case 3: /*0x10a263*/
      case 4: /*0x10a263*/
      case 5: /*0x10a263*/
      case 6: /*0x10a263*/
      case 7: /*0x10a263*/
      case 8: /*0x10a263*/
      case 10: /*0x10a263*/
      case 11: /*0x10a263*/
      case 12: /*0x10a263*/
        *(_DWORD *)(dword_1E875C + 4) = v5; /*0x10a2cd*/
        *(_DWORD *)(v0 + 120) = active_threads; /*0x10a2d6*/
        _InterlockedExchange((volatile __int32 *)(v0 + 112), 0); /*0x10a2db*/
        task_hold(*(_DWORD *)(active_threads + 12)); /*0x10a2e7*/
        task_dowait(*(_DWORD *)(active_threads + 12), 0); /*0x10a2f7*/
        if ( core() ) /*0x10a2ff*/
          v5 += 128; /*0x10a308*/
        goto LABEL_39; /*0x10a30e*/
      case 17: /*0x10a263*/
      case 18: /*0x10a263*/
      case 21: /*0x10a263*/
      case 22: /*0x10a263*/
        return _InterlockedExchange((volatile __int32 *)(v0 + 112), 0);
      default:
        *(_DWORD *)(v0 + 120) = active_threads; /*0x10a316*/
        _InterlockedExchange((volatile __int32 *)(v0 + 112), 0); /*0x10a31b*/
        task_hold(*(_DWORD *)(active_threads + 12)); /*0x10a327*/
        task_dowait(*(_DWORD *)(active_threads + 12), 0); /*0x10a337*/
LABEL_39:
        exit(v5); /*0x10a33f*/
    }
  }
  if ( v7 == 1 || (v6 & *(_DWORD *)(v0 + 28)) != 0 ) /*0x10a193*/
  {
    DWORD1(v9) = aPsigProcessing; /*0x10a195*/
    LODWORD(v9) = 4; /*0x10a19a*/
    log(v9); /*0x10a19c*/
  }
  *(_BYTE *)(dword_1E875C + 104) = 0; /*0x10a1a9*/
  splhigh(); /*0x10a1ad*/
  if ( (*(_BYTE *)(v0 + 42) & 0x10) != 0 ) /*0x10a1b6*/
  {
    if ( (unsigned int)(v5 - 4) > 1 ) /*0x10a1be*/
    {
      *(_DWORD *)(active_u + 4 * v5 + 48) = 0; /*0x10a1c5*/
      *(_DWORD *)(v0 + 36) &= ~v6; /*0x10a1d1*/
    }
    v6 = 0; /*0x10a1d4*/
  }
  v8 = *(_DWORD *)(v0 + 40); /*0x10a1d6*/
  if ( (v8 & 0x200) != 0 ) /*0x10a1dc*/
  {
    v11 = *(_DWORD *)(active_u + 324); /*0x10a1e9*/
    BYTE1(v8) &= ~2u; /*0x10a1ec*/
    *(_DWORD *)(v0 + 40) = v8; /*0x10a1ef*/
  }
  else
  {
    v11 = *(_DWORD *)(v0 + 28); /*0x10a1f7*/
  }
  *(_DWORD *)(v0 + 28) |= v6 | *(_DWORD *)(active_u + 4 * v5 + 180); /*0x10a208*/
  *(_BYTE *)(v0 + 23) = 0; /*0x10a20b*/
  if ( ((7928 >> (v5 - 1)) & 1) != 0 ) /*0x10a21b*/
    *(_BYTE *)(dword_1E875C + 120) = 0; /*0x10a222*/
  _InterlockedExchange((volatile __int32 *)(v0 + 112), 0); /*0x10a228*/
  spl0(); /*0x10a22b*/
  ++*(_DWORD *)(active_u + 428); /*0x10a235*/
  return sendsig(v10, v5, v11); /*0x10a34b*/
}
