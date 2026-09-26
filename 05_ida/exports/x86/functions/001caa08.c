/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1caa08. */
unsigned int *__cdecl sub_1CAA08(int a1, int a2)
{
  thread_act_t v2; // edx
  unsigned int *result; // eax
  unsigned int *v4; // edi
  unsigned int i; // ebx
  unsigned int *v6; // esi
  unsigned int v7; // ebx
  unsigned int *v8; // [esp+Ch] [ebp-4h] BYREF

  v2 = current_thread_EXTERNAL(); /*0x1caa16*/
  result = (unsigned int *)&unk_1E551C; /*0x1caa18*/
  if ( &unk_1E551C ) /*0x1caa1f*/
  {
    while ( result[4] != v2 ) /*0x1caa27*/
    {
      result = (unsigned int *)result[5]; /*0x1caa30*/
      if ( !result ) /*0x1caa35*/
        goto LABEL_5; /*0x1caa35*/
    }
    v4 = result; /*0x1caa29*/
  }
  else
  {
LABEL_5:
    result = sub_1CA960(v2); /*0x1caa37*/
    v4 = result; /*0x1caa3d*/
  }
  for ( i = *v4; a1 != i; i = (unsigned int)result ) /*0x1caa42*/
  {
    if ( !i ) /*0x1caa4b*/
      return result; /*0x1caa4b*/
    if ( (i & 1) != 0 ) /*0x1caa54*/
    {
      result = *(unsigned int **)(v4[1] + 12 * ((int)(i - 1) / 2)); /*0x1caa68*/
    }
    else
    {
      if ( i <= (unsigned int)&v8 ) /*0x1caa75*/
      {
        _NXLogError("Exception handlers were not properly removed."); /*0x1caa85*/
        abort(); /*0x1caa8a*/
      }
      result = *(unsigned int **)(i + 72); /*0x1caa77*/
    }
  }
  if ( i ) /*0x1caa92*/
  {
    if ( !a2 ) /*0x1caa9c*/
      result = (unsigned int *)_NXLogError("Exception handlers were not properly removed."); /*0x1caaa3*/
    v6 = v4; /*0x1caaab*/
    while ( 1 ) /*0x1caab0*/
    {
      v7 = *v6; /*0x1caab0*/
      if ( (*v6 & 1) == 0 ) /*0x1caab5*/
      {
        if ( a2 ) /*0x1cab30*/
          v6 = (unsigned int *)(v7 + 72); /*0x1cab32*/
        else
          *v6 = *(_DWORD *)(v7 + 72); /*0x1cab3b*/
        goto LABEL_30; /*0x1cab35*/
      }
      result = (unsigned int *)(v4[1] + 12 * ((int)(v7 - 1) / 2)); /*0x1caac9*/
      v8 = result; /*0x1caacc*/
      if ( !a2 ) /*0x1caad3*/
        break; /*0x1caad3*/
      if ( a1 == v7 ) /*0x1caad8*/
        goto LABEL_26; /*0x1caad8*/
      v6 = v8; /*0x1caada*/
LABEL_30:
      if ( a1 == v7 ) /*0x1cab40*/
        return result; /*0x1cab40*/
    }
    if ( a1 != v7 ) /*0x1caae3*/
      ((void (__cdecl *)(unsigned int, int, _DWORD, _DWORD))v8[1])(v8[2], 1, 0, 0); /*0x1caaf5*/
    v4[3] = (-1431655765 * (int)((int)v8 - v4[1])) >> 2; /*0x1cab1e*/
    result = v8; /*0x1cab21*/
LABEL_26:
    result = (unsigned int *)*result; /*0x1cab24*/
    *v6 = (unsigned int)result; /*0x1cab26*/
    goto LABEL_30; /*0x1cab28*/
  }
  return result; /*0x1cab49*/
}
