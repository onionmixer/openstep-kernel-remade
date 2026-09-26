/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1566b0. */
int ast_check()
{
  thread_act_t v0; // esi
  int v1; // eax
  int v2; // edx
  int v3; // ecx
  int v4; // eax
  int v5; // eax
  int v6; // ecx
  int v7; // edx
  int v8; // ecx
  volatile __int32 *v9; // edx
  int v10; // eax
  _DWORD *v11; // edx
  int v12; // eax
  int v14; // [esp+Ch] [ebp-10h]
  int v15; // [esp+10h] [ebp-Ch]
  int v16; // [esp+14h] [ebp-8h]

  v0 = active_threads; /*0x1566bb*/
  v16 = splsched(); /*0x1566c6*/
  v1 = *(_DWORD *)(processor_ptr + 276); /*0x1566d2*/
  if ( v1 == 1 ) /*0x1566db*/
  {
    v2 = *(_DWORD *)active_u; /*0x156701*/
    if ( *(_DWORD *)active_u ) /*0x156701*/
    {
      if ( *(_BYTE *)(v2 + 23) /*0x15672f*/
        || v0
        && (v3 = *(_DWORD *)(*(_DWORD *)(v0 + 132) + 124) | *(_DWORD *)(v2 + 24)) != 0
        && ((*(_BYTE *)(v2 + 40) & 0x10) != 0 || (v3 & ~(*(_DWORD *)(v2 + 28) | *(_DWORD *)(v2 + 32))) != 0) )
      {
        v4 = need_ast; /*0x156731*/
        LOBYTE(v4) = need_ast | 0x20; /*0x156738*/
        need_ast = v4; /*0x15673a*/
      }
    }
    need_ast |= *(_DWORD *)(v0 + 380); /*0x156755*/
    if ( need_ast ) /*0x15676c*/
      return splx(v16); /*0x15676c*/
    if ( (*(_BYTE *)(v0 + 76) & 2) == 0 && *(int *)(processor_ptr + 264) <= 0 ) /*0x156786*/
    {
      v5 = *(_DWORD *)(processor_ptr + 300); /*0x15678f*/
      if ( (*(_BYTE *)(v5 + 360) & 2) != 0 ) /*0x15679c*/
      {
        v14 = *(_DWORD *)(v5 + 264); /*0x1567a4*/
        v6 = *(_DWORD *)(v5 + 260); /*0x1567a7*/
        v15 = *(_DWORD *)(processor_ptr + 292); /*0x1567b6*/
        v7 = *(_DWORD *)(v0 + 88); /*0x1567b9*/
        if ( *(_DWORD *)(v0 + 96) == 1 ) /*0x1567c2*/
        {
          if ( !v15 && v14 > 0 && v6 >= v7 ) /*0x1567f6*/
            goto LABEL_42; /*0x1567f6*/
        }
        else if ( v14 && v6 >= v7 && (v6 > v7 || !v15) ) /*0x1567df*/
        {
          goto LABEL_42; /*0x1567df*/
        }
        if ( *(_DWORD *)(v0 + 96) == 2 ) /*0x156800*/
          *(_DWORD *)(processor_ptr + 292) = 1; /*0x156809*/
        return splx(v16); /*0x156813*/
      }
      v8 = *(_DWORD *)(processor_ptr + 300); /*0x156818*/
      if ( *(_DWORD *)(processor_ptr + 292) || *(int *)(v5 + 264) <= 0 ) /*0x156831*/
        return splx(v16); /*0x156831*/
      if ( *(_DWORD *)(v8 + 8 * *(_DWORD *)(v5 + 260)) == v8 + 8 * *(_DWORD *)(v5 + 260) ) /*0x156842*/
      {
        v9 = (volatile __int32 *)(v8 + 256); /*0x156844*/
        do /*0x15685e*/
        {
          while ( *v9 ) /*0x15684c*/
            ; /*0x15684e*/
        }
        while ( _InterlockedExchange(v9, 1) == 1 ); /*0x15685e*/
        v10 = *(_DWORD *)(v8 + 260); /*0x156860*/
        v11 = (_DWORD *)(v8 + 8 * v10); /*0x156866*/
        if ( *(int *)(v8 + 264) > 0 ) /*0x156870*/
        {
          for ( ; v10 >= 0; --v10 ) /*0x156874*/
          {
            if ( (_DWORD *)*v11 != v11 ) /*0x15687a*/
              break; /*0x15687a*/
            v11 -= 2; /*0x15687c*/
          }
          *(_DWORD *)(v8 + 260) = v10; /*0x156882*/
        }
        _InterlockedExchange((volatile __int32 *)(v8 + 256), 0); /*0x15688a*/
      }
      if ( *(_DWORD *)(v8 + 260) < *(_DWORD *)(v0 + 88) ) /*0x156899*/
        return splx(v16); /*0x156899*/
    }
LABEL_42:
    v12 = need_ast; /*0x15689c*/
    LOBYTE(v12) = need_ast | 4; /*0x1568a3*/
    need_ast = v12; /*0x1568a5*/
    return splx(v16); /*0x1568b3*/
  }
  if ( v1 > 1 ) /*0x1566dd*/
  {
    if ( v1 > 3 ) /*0x1566ef*/
      goto LABEL_43; /*0x1566ef*/
  }
  else if ( v1 ) /*0x1566e1*/
  {
LABEL_43:
    panic(aAstCheckBadPro); /*0x1568b8*/
  }
  return splx(v16); /*0x1568d1*/
}
