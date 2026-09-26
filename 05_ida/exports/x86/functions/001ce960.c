/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1ce960. */
id objc_msgSend(id a1, SEL a2, ...)
{
  id result; // eax
  int *v3; // eax
  _DWORD *v4; // edi
  int v5; // esi
  SEL i; // edx
  int v7; // edx
  int v8; // eax
  id (*Cache)(void); // eax
  __int32 v10; // ecx
  int *v11; // eax
  _DWORD *v12; // edi
  int v13; // esi
  SEL j; // edx
  int v15; // edx
  int v16; // eax
  id (*v17)(void); // eax
  id (*v18)(void); // eax

  result = a1; /*0x1ce960*/
  if ( (_objc_multithread_mask & (unsigned int)a1) != 0 ) /*0x1ce96c*/
  {
    v3 = *(int **)(*(_DWORD *)a1 + 32); /*0x1ce976*/
    v4 = v3 + 2; /*0x1ce97a*/
    v5 = *v3; /*0x1ce97d*/
    for ( i = a2; ; i = (SEL)(v7 + 1) ) /*0x1ce980*/
    {
      v7 = v5 & (unsigned int)i; /*0x1ce982*/
      v8 = v4[v7]; /*0x1ce984*/
      if ( !v8 ) /*0x1ce989*/
        break; /*0x1ce989*/
      if ( a2 == *(SEL *)v8 ) /*0x1ce98e*/
        return (*(id (**)(void))(v8 + 8))(); /*0x1ce995*/
    }
    Cache = (id (*)(void))_class_lookupMethodAndLoadCache(*(_DWORD *)a1, (int)a2); /*0x1ce9bb*/
    return Cache(); /*0x1ce9c3*/
  }
  else if ( a1 ) /*0x1ce9d8*/
  {
    v10 = 1; /*0x1ce9e0*/
    do /*0x1ce9f0*/
      v10 = _InterlockedExchange(&messageLock, v10); /*0x1ce9eb*/
    while ( v10 ); /*0x1ce9f0*/
    v11 = *(int **)(*(_DWORD *)a1 + 32); /*0x1ce9fe*/
    v12 = v11 + 2; /*0x1cea02*/
    v13 = *v11; /*0x1cea05*/
    for ( j = a2; ; j = (SEL)(v15 + 1) ) /*0x1cea08*/
    {
      v15 = v13 & (unsigned int)j; /*0x1cea0a*/
      v16 = v12[v15]; /*0x1cea0c*/
      if ( !v16 ) /*0x1cea11*/
        break; /*0x1cea11*/
      if ( a2 == *(SEL *)v16 ) /*0x1cea16*/
      {
        v17 = *(id (**)(void))(v16 + 8); /*0x1cea18*/
        messageLock = 0; /*0x1cea1d*/
        return v17(); /*0x1cea27*/
      }
    }
    v18 = (id (*)(void))_class_lookupMethodAndLoadCache(*(_DWORD *)a1, (int)a2); /*0x1cea4b*/
    messageLock = 0; /*0x1cea53*/
    return v18(); /*0x1cea5d*/
  }
  return result; /*0x1ce9da*/
}
