/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x161b90. */
int __cdecl processor_set_things(int a1, int **a2, unsigned int *a3, int a4)
{
  volatile __int32 *v5; // ebx
  unsigned int v6; // edi
  unsigned int v7; // ebx
  int j; // esi
  unsigned int v9; // ebx
  int i; // esi
  int *v11; // eax
  int *v12; // ebx
  unsigned int m; // ebx
  unsigned int k; // ebx
  unsigned int v15; // ebx
  int *v16; // esi
  unsigned int v17; // ebx
  int *v18; // esi
  int *v19; // [esp+14h] [ebp-Ch]
  size_t v20; // [esp+18h] [ebp-8h]
  unsigned int v21; // [esp+1Ch] [ebp-4h]

  if ( !a1 ) /*0x161b9d*/
    return 4; /*0x161ba4*/
  v21 = 0; /*0x161bac*/
  v19 = nullptr; /*0x161bb3*/
  v5 = (volatile __int32 *)(a1 + 344); /*0x161bbd*/
  while ( 1 )
  {
    do /*0x161bd6*/
    {
      while ( *v5 ) /*0x161bc4*/
        ; /*0x161bc6*/
    }
    while ( _InterlockedExchange(v5, 1) == 1 ); /*0x161bd6*/
    if ( !*(_DWORD *)(a1 + 340) ) /*0x161be2*/
    {
      _InterlockedExchange((volatile __int32 *)(a1 + 344), 0); /*0x161de5*/
      return 5; /*0x161df0*/
    }
    v6 = a4 ? *(_DWORD *)(a1 + 320) : *(_DWORD *)(a1 + 308);
    v20 = 4 * v6; /*0x161c08*/
    if ( 4 * v6 <= v21 ) /*0x161c10*/
      break; /*0x161c10*/
    _InterlockedExchange((volatile __int32 *)(a1 + 344), 0); /*0x161c17*/
    if ( v21 ) /*0x161c1f*/
      kfree((int)v19, v21); /*0x161c26*/
    v21 = 4 * v6; /*0x161c31*/
    v19 = (int *)kalloc(v20); /*0x161c3a*/
    if ( !v19 ) /*0x161c42*/
      return 6; /*0x161c49*/
  }
  if ( a4 ) /*0x161c54*/
  {
    if ( a4 == 1 ) /*0x161c5a*/
    {
      v9 = 0; /*0x161c9a*/
      for ( i = *(_DWORD *)(a1 + 312); v9 < v6; i = *(_DWORD *)(i + 24) ) /*0x161ca7*/
      {
        thread_reference(i); /*0x161cad*/
        v19[v9++] = i; /*0x161cb5*/
      }
    }
  }
  else
  {
    v7 = 0; /*0x161c66*/
    for ( j = *(_DWORD *)(a1 + 300); v7 < v6; j = *(_DWORD *)(j + 16) ) /*0x161c73*/
    {
      task_reference(j); /*0x161c79*/
      v19[v7++] = j; /*0x161c81*/
    }
  }
  _InterlockedExchange((volatile __int32 *)(a1 + 344), 0); /*0x161cc8*/
  if ( !v6 ) /*0x161cd0*/
  {
    *a2 = nullptr; /*0x161cd5*/
    *a3 = 0; /*0x161cde*/
    if ( v21 ) /*0x161ce8*/
      kfree((int)v19, v21); /*0x161cf6*/
    return 0; /*0x161e15*/
  }
  if ( v20 >= v21 ) /*0x161d06*/
  {
LABEL_38:
    *a2 = v19; /*0x161da1*/
    *a3 = v6; /*0x161dac*/
    if ( a4 ) /*0x161db2*/
    {
      if ( a4 == 1 ) /*0x161db8*/
      {
        v17 = 0; /*0x161df4*/
        v18 = v19; /*0x161dfa*/
        do /*0x161e13*/
        {
          *v18 = convert_thread_to_port(*v18); /*0x161e08*/
          ++v18; /*0x161e0d*/
          ++v17; /*0x161e10*/
        }
        while ( v17 < v6 ); /*0x161e13*/
      }
    }
    else
    {
      v15 = 0; /*0x161dbc*/
      v16 = v19; /*0x161dc2*/
      do /*0x161ddb*/
      {
        *v16 = convert_task_to_port(*v16); /*0x161dd0*/
        ++v16; /*0x161dd5*/
        ++v15; /*0x161dd8*/
      }
      while ( v15 < v6 ); /*0x161ddb*/
    }
    return 0; /*0x161e13*/
  }
  v11 = (int *)kalloc(v20); /*0x161d10*/
  v12 = v11; /*0x161d15*/
  if ( v11 ) /*0x161d1c*/
  {
    bcopy(v19, v11, v20); /*0x161d89*/
    kfree((int)v19, v21); /*0x161d96*/
    v19 = v12; /*0x161d9b*/
    goto LABEL_38; /*0x161d9b*/
  }
  if ( a4 ) /*0x161d22*/
  {
    if ( a4 == 1 ) /*0x161d28*/
    {
      for ( k = 0; k < v6; ++k ) /*0x161d4f*/
        thread_deallocate(v19[k]); /*0x161d5c*/
    }
  }
  else
  {
    for ( m = 0; m < v6; ++m ) /*0x161d2f*/
      task_deallocate(v19[m]); /*0x161d3c*/
  }
  kfree((int)v19, v21); /*0x161d71*/
  return 6; /*0x161e1a*/
}
